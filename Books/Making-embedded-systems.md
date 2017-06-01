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



