---
course: Embedded systems Engineering
professor: Prof. Dr. Henkler 
semester: Winter 2017
---

# Introduction
- **Embedded software engineering** is a multidisciplinary approach for developing solutions to complex engineering problems. 
- Embedded systems are often safety-critical applications where correct operation is vital to ensure the safety of the public and environment. 
- Typically have communications with people and other systems
- is the main driver for the industries
- **Embedded systems**: software embedded into a technical system which interacts with the world on a specific hardware. Interaction with the technical system via actors and sensors.
- **software-intensive systems** (balance HW and SW): is any system where software contributes essential influences to the design, construction, deployment, and evolution of the system as a whole.
- **software engineering**: The application of a systematic, disciplined, quantifiable approach to the development, operation, and maintenance of software; that is, the application of engineering to software. 
- System engineering integrates and use software engineering
- **Control engineering**: is the engineering discipline that focuses on the mathematical modeling systems of a diverse nature, analyzing their dynamic behavior, and using control theory to make a controller that will cause the systems to behave in a desired manner.
- Control engineering uses extensively computer software and hardware due to its strong mathematical foundations
- Other relevant disciplines:
    - Mechatronics: is the sinergystic combination of mechanical, electronic and software engineering
    - Telematics: is the integrade use of telecomunications and informatics

## System characteristics
- Reactive systems: continuously sensing and reacting to the environment
- Real-time systems: The response should be delivered in a specific time. Executing in an specific time again and again
    - Deadline: the latest time until which the response to a stimulus is required.
    - Synchronous/periodic task: Can be used to address required activities with a period p. 
    - Asynchronous/aperiodic task: Can be used to address required activities for stimulus without knowledge about the occurrence.
    - Not only the correct behaviour is important, but also its timely provision.
- Hard and soft Real-time systems:
    - The utility describes the time-dependent value of a result.
    - Soft real-time: it's allowed to miss the deadline and reduces the utility, but does not lead to a significant financial loss 
    - Hard real-time: result must be delivered to the systems in a specific time, otherwise it will have terrible consequences.
- Continuous/discrete systems:
    - Continuous/discrete in time
    - Continuous/discrete in space/data 
    - Continuous systems: behavior specified by differential equations
    - Discrete systems: State transitions. Complex high level programs
    - Hybrid systems: Continuous and discrete elements, either independent or interrelated
- Embedded systems:
    - Should be predictable even in the worst case scenario (cache, pipeline)
    - Relevant hardware:     
        - real-time clock: highly accurate ticks
        - Interrupt controller: hardware supports for asynchronous stimulus
        - Hardware timers: more precise and flexble than RTOS ticks
        - Watchdog timers: a one-shot hardware timer that results  in a non-maskable interrupt when not retriggered
        - A/D and D/A converters: special support for converting analogous external signals to digital and vice versa
        - Serial communication controller: often at least used for development and debugging
        - Bus controller: direct support for special bus system 

## Possible HW-platforms 
- General purpose microprocessors: x86
- Highly integrate microprocessors: aditional I/O on the chip
- Single chip microcomputer: ROM, RAM
- Single chip microcontroller
- DSP
- Mixed-signal processor 
- Bespoken system-on-chip: ASICs, FPGA

## Dependable systems: (from here)
- We need to trust the system realization
- Dependability:
    - reliability: the ability of a system to deliver services as specified
    - availability: the ability of a system to deliver services on request
    - safety: operate without catastrophic failure
    - security: protect itself against accidental or deliberate intrusion
- fault: is a defect within the system
- error: implies memory
- system failure: fails to perform its required task

## Faults:
- Nature - critical distinction: 
    - random HW faults
    - logical/ systematic/ design
- Nature - degradation faults
    - the system does not working anymore

## Reliability
- Quantitative: in terms of probability in time (my car must be reliable for 4-5 years)

## Availability:
- Quantitative: probability of a system in a specific time (my car is available tomorrow at 6pm)

## Reliability achievement
- Fault avoidance: test-driven development
- Fault detection: detect the faults before deployment
- Fault tolerance: faults in the system does not result in a system crash

## Safety
- related to harm humans or the environment

## Security
- related to prevention or protection of the information
- security is an essential prerequirement for availability, safety and reliability.
- Fundamental security: you cannot trust anything
- What causes security failure: AAA attributes
    - Architecture: software faults, bad designs
    - Administration: poor use of features
    - Attacks: Active intrusion

----
# Foundations
- Model based specifications
- Specification: a description of required properties that an artifact must ensure
- Relation: a model can fulfill a specification
- A model is also a specification

## Systems model types

