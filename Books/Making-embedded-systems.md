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
Good for testing: `0xAA, 0x55`, and for anomalies `0xDEADBEEF`.

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
## External memory
There are two types _volatile_ (lost when system turns off) and _nonvolatile_.
Some questions:
* How large is it? (Don't be fooled by memory sizes given in Mbits instead of Mbytes!)
* How long does it take to access the memory? This depends both on the communication bandwidth and the memory characteristics.
* How much do you need to erase at a time?
* How many times can it be rewritten?

## Buttons and key matrices
There are two ways to implement a key matrix, depending on whether you need it to be cheap (row/column scan) or minimal I/O (Charlieplexing).Both of these methods may cause problems when multiple buttons are pressed simultaneously.

With a row/column scan you can implement an MxN matrix with M+N lines. So if you want to implement a 12 digit number pad, you could do a 3x4 matrix and use 7 lines (far fewer than the 12 lines it would take to do direct I/O). Of course, matrix input does require more complicated software to make it work.  

## So many ways of Communicating
The clock is what controls the communication. It usually comes from the master device, it not only controls the **speed** but also the **existence of the interactions**.

### The OSI model

1. Physical Layer: Provides electrical and physical specification.
How many wires connect your processor to a peripheral? At what voltage? At what speed?
For example: ethernet cable

2. Data Link Layer: Describes how bytes flow over the physical wires.
Do the bytes have parity checking? How many bits are sent and received in each frame?
For example: ethernet 802.xx

3. Network Layer: Gets a variable length of information(packets) from one place to another.
How is each system addressed? How to break up (and re-form) big blocks of data into amounts that can go over the communication pathway?
For example: IP

4. Transport Layer: Moves blocks of data in a reliable manner, even if those blocks are larger than the lower levels can handle.
How do you count on data being received even when there is a glitch in wires? How are errors recovered from?
For example: TCP

5. Session Layer: Manages a connection between local and remote application
How to send this data from here to there?
For example: Sockets

6. Presentation Layer: Provides structure to the data, possibly encryption
How is the data organized when it is sent?
For example: TLS and SSL

7. Application Layer: Takes user interaction with the software and formulates a communication request
What command to send when a button is pressed?
For example: HTTP

For an embedded system, most of your attention will be spent on the data link layer and how to move bytes from one place to another.

### Serial
When encountering a new peripheral bus, the things to understand include:
* How is the clock generated? Is it implicit (all parties agree upon it ahead of time) or explicit? If it is explicit, does the clock generator (usually the bus master) have any other special responsibilities?
* How many hardware lines does it need?
* Synchronous or asynchronous?
* Full or half duplex?
* Is it point-to-point or is there addressing? Is it in the protocol or done via chip select?
* What is the maximum throughput of the system?
* How far can the signals travel?

The real goal here is to figure out how long it will take you to implement a driver using the communication method in question. The easiest driver to write is one you've already got working on another project.  

### Serial Peripheral bus profiles
Timing diagrams are often very important to getting a peripheral working. As you bring up a driver for the first time, expect to spend some time setting an oscope up and trying to recreate those diagrams (in order to debug your driver).

## Putting Peripherals and Communication together 
### Data Handling 
There is a class of problems where the goal is to get data, process it, do something with the results and repeat. In such **data driven systems**, there are no events, just an ever increasing mountain of data for your software to process. Ideally, the system can wade through the data just a tiny bit faster than it is generated. This a type of system that must fail gracefully.

Most systems have some elements of an event driven system and a data driven system.  As you consider your system, try to figure out what aspects belong to each. This will unravel some of the complexity of your software by allowing you to implement them separately.

### Circular buffers
- are FIFO
- A circular buffer needs to keep track of a chunk of memory, its length, where to put the next element that comes in (write or start) and where to get the next element (read or end).
- If you don't constrain the buffer size to a power of two, you need to use modulo arithmetic to wrap the pointers.
- The circular buffer rejects data that would overflow the buffer.  
- Dealing with lengths:  
How much is free and ready to be written? Wrapped subtract of write from free  
How much data can be read? Wrapped subtract of read from write  
How much data is currently checked out for reading? Wrapped subtract of free from read  
Handling the free pointer is straightforward.  
- **Hardware FIFOs**  
You don't always have to implement a circular buffer. Sometimes the hardware will do it for you with a FIFO buffer.  
- **DMA**  
A processor that supports DMA (Direct Memory Access) can pass far more data than one that implements only a FIFO. To use DMA, you give the processor a pointer and a number of bytes to read. When receiving, the processor puts data from the peripheral until it reaches the byte count at which point it interrupts the software.  Similarly, when transmitting, the processor moves data from the buffer to the peripheral, interrupting when the count is complete.  
DMA is a lot like having another thread do the data handling for you.  

## Adding Robustness to the Communication
- Versioning everything then checksum it. 
- Authentication and Encryption

# Ch07: Updating Code
Some issues you should know about before we start include:
- The code storage mechanism and communication method:  
 We'll need something to hold the new code image. What you employ to store it on depends mostly on the communication method, for example: a thumbdrive when updating over USB, an EEPROM for SPI, or a hard drive for a network.
- Code space memory (old code location):  
The code space is some sort of nonvolatile memory (memory that is not erased when the power is lost) that often requires special voodoo to rewrite.
- Scratch space RAM:  
The idea is to write the code to the scratch space and make sure the upload is complete without corruption before actually copying it over to where it counts—the permanent memory of the device.
- Run space RAM:  
This is RAM from which the processor can execute. If you don't have this, it limits your loading options.

## On-board bootloader
Some processors have an internal bootloader that will load code from an external source if the right I/O pins are set. In an ideal world, you'd just set the I/O pin while you connected the new code to the system, generally as the system powers up. The bootloader would automatically load the data into the code space.

## Build you own bootloader
If you have plenty of code space, the next easiest option is to build your own bootloader: a resident program in the code space that could reprogram the rest of the memory. Since most code space is flash memory, you will have to erase sectors of the old runtime code before you can write the new code.
There could be problems such as corrupted code, before and during code replacement. Checksums and a scratch space RAM can prevent flash the microcontroller with corrupted code.
Another solution is to make the bootloader check the code image when power on, so if there is new/ uncorrupted code it will update the code or run the old one, otherwise it could be wait for a extrenal source to upload an uncorrupted code, which is better than put garbage in the processor.

## Modifying the Resident Bootloader
If you really need to, you can modify the bootloader using a two-pass process that resembles a shell game. 
1. load old bootloader and programs new runtime (temp BL: BL2)
2. BL2 erases old BL
3. BL2 programs new BL
4. new BL runs the new runtime

## Brick Loader
The next loader is more complicated and riskier but it solves the problem of running out of code space. The danger comes from the possibility of making the system useless and unable to ever load valid code (aka "turning the system into a brick"). For example, when the power is lost during an update.

To get the new runtime image running using our loader, we'll need to implement five steps:
1. With the runtime code, copy the loader from the new code storage to RAM.
2. Run the loader code.
3. Copy the new code to a scratch area.
4. Erase the old code and program the new code.
5. Reset the processor to run the new code.
 
### Linker Script
Do not write one from zero, usually the linker file (`*.ld`) is also a subproduct of the compilation. The idea is to focus on the addresses of the sections (.bss, .data, .text, .vector) so you can move them from one address to another. 
The key point is to copy the loader to RAM.

### Copy loader to RAM
Some details to take into account:
- You'll need to allocate some RAM memory just for the loader to avoid random behaviors of the program. Make sure the this allocated RAM won't be used by the runtime program.
- The loader also have function calls at certain addresses, so you have to modify these calls as well.
- If the loader is larger than your RAM size, you may not update unnecessary functionalities or you can also use unused buffers (SPI, sensors, circular buffers)  as memory space. Don't forget to disable all the interrupts that use any of this memory before loading your bootloader there.

### Run the loader
To avoid running a corrupted or incomplete loader, you may use a checksum.
Once you get down to actually loading the code, you'll need a function to pointer, the function should be set the address in RAM that holds the loader program.
For example:

```c
int loaderStartAddress = 0x10000; // should come from the linker file
typedef void (*tFunctionPointer)(void);
tFunctionPointer fp = (tFunctionPointer) (*(uint32_t*)(loaderStartAddress));
(*fp)(); // jump to loader, never to return
```

### Copy new code to scratch 
Once the loader code is running, the next step is to get the new runtime code on the system. You could erase and program the new code directly, but if something happens, you could end up with a system whose only program is a RAM-based loader. Once the power is cycled, you end up with a brick.
You may want to use an optional scratch RAM to check the integrity of the image.

### Dangerous Time: Erase and Program
So before erasing the old code, disable all interrupts (really this time, no excuses). Then write the new code. A reset will make the new code run (a good excuse to stop feeding the watchdog).
Chip vendors often supply the erase and write functions, so look around before writing them.

### Reset to New Code
There are additional points of interest when thinking about loaders.
- Where does the loader come from? it could be in same place in your memory or from the same place as the new application code.
- Second, this process assumes that getting the new image is straightforward. You may load the loader first and place the new image code somewhere local. Oonce the loader is ready to copy the new code it will use the new image.
- Finally, loading code is dangerous. Often the loader is the last piece of code written and so one of the least tested parts of the system. As you draw a flow chart for what goes on in your loader, look at the amount of time when the old image is erased and the new image is running. Minimizing the updating process may save your units.

# Ch08: Doing more with less
 
