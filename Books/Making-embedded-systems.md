---
title: Making Embedded Systems
author: Elecia White
---

# Ch01: Introduction

An embedded system is a computerized system that is purpose built for its application.
An embedded system can be considered as an object in the context of OOP.

## Embedded system development

### Challenges
* ES usually will need a cross compiler and cross debugger.
* Limited debugging due to limited resources such as registers to save the breakpoints.
* Many ES are designed to be debugged using `printf` or some sort of logging.
* Trade off between resources (ram, rom, clock freq, battery, I/O)
* Software may damage hardware.
* Product development migth change along the way, so based on the constraints you must anticipate what could be a problem in the future.

### Principles to confront the challenges
* Modularity, encapsulation (OOP principles).
* Be effective, efficiency will come later.

# Ch02: Creating a System architecture
I recommend three different diagrams:
* Architecture block diagram, tell us the components we will use
* Hierarchy of control organization chart, tell us the blocks we will code
* Software layering view, tell us how complex the blocks will be

## Block diagram
Design is straightforward at the start because you are considering the physical components of the system, and you can think in an object-oriented fashion to model your software around the physical
components.
Each chip attached to the processor is an object. You can think of the wires that connect the chip to the processor (the communication methods) as another set of objects.
Start your design by drawing these as boxes where a chip is in the center, the communication objects are in the processor and the peripherals are each attached to those.

It is better to have too many boxes at this stage than too few. We can combine them later. 

## Hierarchy of control 
The next type of software architecture diagram looks like an organizational chart. Main is the highest level. We can then fill in the lower-level objects that are used by a higher-level object.
For example, the `main` routine will need a **display** which will need **text**, **fonts** and **images**.

Sometimes, some objects share resources such as memory or communication peripherals, you'll need special care to avoid contention around the resource and make sure it is available when needed.

## Layered view
The last architecture drawing looks for layers and represents objects by their estimated
size.
Start at the bottom of the page and draw boxes for the things that go off the processor (like our
communication boxes). If you anticipate that one is going to be more complicated to implement, make it a little larger. If you aren't sure, make them all the same size.
Next, add the items that use the lowest layer to the diagram. If there are multiple users of a
lower level object, they should all touch the lower level object (this might mean making an object bigger).
Also, each object that uses something below it should touch all of the things it uses, if possible.

# From diagram to architecture
what is going to change? At this stage, everything is experimental so it is a good bet that any piece of the system puzzle is going to change.

## Encapsulate modules
We will focus on the interface rather than what it is under the hood, so it will be easier to mantain over time.

Keep it simple, but flexible. 
* In the hierarchy chart, look for objects that are used only by one other object. Are these both fixed? Or can one change independently of the other?
* In the layered diagram, look for collections of objects that are always used together. Can these be grouped together in a higher level interface to manage the objects? You'd be creating a hardware abstraction layer.
* Which modules have lots of interdependencies? Can they be broken apart and simplified? Or can the dependencies be grouped together? 

## Driver Interface
The idea is to model your driver upon Unix drivers. A embedded system device might look like any of these:

```
spi.open()
spi_open()
spi.ioctl(CHANGE_FREQ, 30, MHZ)
```
## Model-View-Controller (MVC) model
The **model** holds the data, state, and application logic. For an MP3 player, the model consists of database of music and the codec necessary to play it.
Traditionally thought of in contexts where there is a screen, the **view** represents the display handling functions. The **view** is what the user sees of the model. The **controller** is the somewhat nebulous cloud that sits between (or near) the model and view to help them work together. The goal of the controller is to make the view and model independent of each other so that they can each be reused.

Sometimes it is needed to interface your code with your PC in order to debug or isolate a bug. 
Your files and the way you read the data in are the view part of the MVC. The algorithm you are testing is the model, and shouldn't change.
The controller is the part that changes when you put the algorithm on a PC.

# Ch03: Getting the Code Working
## Datasheet section you need when things go wrong

* I/O pins
* pins descriptions
* performance characteristics
* Sample schematics
* Timinng Diagrams

## Testing HW and SW
For most forms of memory, the pattern we've seen here is a good start:
1. Read the original data.
2. Write some changing but formulaic junk.
3. Verify the junk.
4. Re-write original.
5. Verify the original.

Designing good tests is one of those things that can make you software great.

## Command and response
To test some block you will need to use your PC as interface, and it will be done by using a CLI most likely.

### Creating commands
* *Ver*: Outputs the version information
* *Test the flash*: Runs the flash unit test, printing out the number of errors upon completion
* *Blink LED*: Sets an LED to blink at a given frequency
* *Help*: Lists available commands with one-line descriptions
 
## Error Handling Gracefully
Error return codes for an application or system should be standardized over the code base. A single high-level `errorCodes.h` file (or some such) may be created to provide consistent errors in an enumerated format. Some suggested error codes are:
* No error (should always be 0)
* Unknown error (or unrecognized error)
* Bad parameter
* Bad index (pointer outside range or null)
* Uninitialized variable or subsystem
* Catastrophic failure (this may cause a processor reset unless it is in a development mode,x in which case it probably causes a breakpoint or spin loop)
 
# Ch04: Outputs, Inputs, and Timers
## Outputs
Good for testing: `0xAA, 0x55', and for anomalies `0xDEADBEEF`.

## Inputs
Be careful with the buttons bounce effect.

## Using a timer
Internal clock is not very stable

# Ch05: Task Management 
## Scheduling and OS basics
Some definitions:
* Task: it's something the processor does
* Threads: it's a task plus some overhead such as memory
* Process: it is usually a complete unit of execution unit with its own memory space, usually compiled separately from other processes.

### Avoid Race Conditions
it is when two task, let's say an interruption and no-interruption task, are called at the "same time" and both share the same memory. This leads to some unstability in the code.

One way to prevent this unstability is to do a **mutual exclusion** or **mutex**. This means that only one task at a time can use the memory space.
When dealing with normal task, non interruptions, it can be as simple as setting global variables, but if task are interruptions, the way to go is by using **atomic** action.
An **atomic** action is the one that cannot be interrupted.

## Table Driven State Machine
Instead of using a flow chart to represent the state transitions, we are using a chart to represent the states and the actions.

Go, STOP and timeout are commands, light is the output.

STATES | light | GO | STOP | Timeout |
---|---|---|---|---|
 Red | red | Green | Red | Red |
 Yellow | yellow | Red | Yellow | Red |
 Green | green | Yellow | Yellow | Green |

the code will be something like
```c
struct sStateTableEntry {
  tLight light;       // all states have associated lights
  tState goEvent;     // state to enter when go event occurs
  tState stopEvent;   // ... when stop event occurs
  tState timeoutEvent;// ... when timeout occurs
};
```

An example of the event handler:
```c
// event handler
void HandleEventGo(struct sStateTableEntry *currentState)
{
  LightOff(currentState->light);
  currentState = currentState->go;
  LightOn(currentState->light);
}
```

We need to define the actual table
```c
typedef enum { kRedState = 0, kYellowState = 1, kGreenState = 2 } tState;
struct sStateTableEntry stateTable[] = {
  { kRedLight,    kGreenState,  kRedState,    kRedState},   // Red
  { kYellowLight, kYellowState, kYellowState, kRedState},   // Yellow
  { kGreenLight,  kGreenState,  kYellowState, kGreenState}, // Green
}
```

As conclusion, table driven state machines it an useful resource but it can get very complex.

## Interrupts

1. Interrupt request (IRQ) happens, inside the processor based on a peripheral, the
software, or a fault in the system.
2. The processor saves where it was (the context).
3. The processor looks in the interrupt vector table to find the callback function as-
sociated with the interrupt.
4. The callback function (aka interrupt service routine (ISR) or interrupt handler) runs.

### An IRQ happens:
* dissable all interrupts
* set up the interrupts
* be careful with interrupt latency( saving the context and switching)
* always count on interrupts may happen at the worst time

### Get the ISR from table vector
- You may want unhandled interrupts to simply return to normal execution to avoid infintive loops
- Processor responds to reset button as an interrupt to their code
- All the interrupts have an associated value, and the processor uses this value to get the address to the handle

### Calling the ISR
- Keep ISRs short, because longer ones increase your system latency. Generally avoid
function calls, which may have hidden depths and increase overhead.
- Don't call non-reentrant functions (such as `printf`), because global variables can
be corrupted by interrupts.
- Turn off other interrupts during the ISR to avoid priority inversion problems.

An example
```c
volatile tBoolean gYellowTimeout = FALSE; // global variable set by the interrupt handler
                                 // cleared by normal code when event handled
void TIMER3_IRQHandler(void)
{
  __disable_irq();        // disallow nesting of interrupts
  gYellowTimeout = TRUE;
  __enable_irq();
}

```

Many processors require that you acknowledge (or clear) the interrupt. This is usually
accomplished by reading a status register.

### Restore the context
After your ISR has run to completion, it is time to return to normal execution. Some compilers extend C/C++ to include an `interrupt` keyword (or **__IRQ** or **_interrupt** ) to indicate which functions implement interrupt handlers.
The processor gives these functions get special treatment both when they start (some context is saved before the ISR starts running) and when they return.

## When to use Interrupts 
- The more real-time is the requirement to handle a change on the line, the more an interrupt is appropriate for a solution.
- Interrupts tend to make your code less portable.
- Save interrupts for when you need their special power: when a system is time critical, when an event is expensive to check for and happens very rarely, and when a short background task will let the system run more smoothly.

## Watchdog
The watchdog system waits for the processor to send a signal that things are going well. If such a signal fails to occur in a reasonable (often configurable) amount of time, the watchdog will cause the processor to reset.  The goal is that when the system fails, it fails in a safe manner (failsafe).

Generally you don't want the watchdog active during board bring-up or while using a debugger. Otherwise, the system will reset after a breakpoint. A straightforward way to turn off the watchdog will facilitate debugging. If you have a logging method, be sure to print out a message on boot if the watchdog is on. It is one of those things you don't want to forget to enable as you do production testing. Alternatively, you can toggle an LED when the watchdog is serviced to give your system a heartbeat that is easy to see from the outside, letting the user know that everything is working as expected.
 
# Ch06: Communicating with Peripherals 
