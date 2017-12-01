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
- is defined as the trustworthiness of a computer system such that reliance can justifiably be placed on the services it delivers.  
- We need to trust the system realization
- Two aspects of reliance:
    - system performs according to its service specification
    - system avoids hazards,
- Attributes:
    - reliability: the ability of a system to deliver services as specified
    - availability: the ability of a system to deliver services on request
    - safety: operate without catastrophic failure
    - security: protect itself against accidental or deliberate intrusion
- fault: is a defect within the system (error cause).  It is a condition that causes the software to fail to perform its required function. 
- error: is a derivation of the required operation of the subsystem or system. Refers to difference between Actual Output and Expected output. 
- system failure: fails to perform its required task according to its specification. 
- Fault > Error: a fault is active when it produces an error
- Error > Failure: 
    - an error is latent when it has not been recognized
    - an error is detected by a detection algorithm
- Failure > Fault: 
    - A failure occurs when an error passes through and affects the systems
    - A failure causes a fault

## Faults:
- Nature - critical distinction: 
    - random HW faults
    - logical/ systematic/ design
- Nature - degradation faults
    - the system does not working anymore
- Nature - Design faults
    - The system never worked
    - the design is flawed
- Duration:
    - permanent, transient, intermittent
    - localized, global

## Reliability
- Reliability is the probability of a component, or system, functioning correctly over a given period of time under a given set of operating conditions.  
- Quantitative: in terms of probability in time (my car must be reliable for 4-5 years)

## Availability:
- The availability of a system is the probability that the system will be functioning correctly at any given time.  
- Quantitative: probability of a system in a specific time (my car is available tomorrow at 6pm)

### Availability vs Reliability
- Obviously if a system is unavailable it is not delivering the specified system services
- It is possible to have systems with low reliability that must be available
    - So long as system failures can be repaired quickly and do not damage data, low reliability may not be a problem
    - Availability takes repair time into account

### Reliability achievement
- Fault avoidance: the system minimize human error and the development process is organized so the faults are detected and solved. test-driven development
- Fault detection: detect the faults before deployment
- Fault tolerance: faults in the system does not result in a system crash
- Removing X% of the faults in a system will not necessarily improve the reliability by X%. 
- Program defects may be in rarely executed sections of the code so may never be encountered by users. Removing these does not affect the perceived reliability

## Safety
- Safety is a property of a system that it will not endanger human life or the environment.
- Terminology:
    - Accident: An unplanned event or sequence of events which results in human death or injury, damage to property or to the environment. 
    - Hazard: A condition with the potential for causing or contributing to an accident
    - Damage: A measure of the loss resulting from an accident. Damage can range from many people killed as a result of an accident to minor injury or property damage.
    - Hazard severity: An assessment of the worst possible damage that could result from a particular hazard. Hazard severity can range from catastrophic where many people are killed to minor where only minor damage results.
    - Hazard probability: The probability of the events occurring which create a hazard 
    - Risk: This is a measure of the probability that the system will cause an accident. The risk is assessed by considering the hazard probability, the hazard severity and the probability that a hazard will result in an accident.

### Safety avoidance 
- Hazard avoidance
- Hazard detection and removal: before they result in an accident
- Damage limitation: minimize the damage

## Security
- Prevention of or protection against (a) access to information by unauthorized recipients or (b) intentional but unauthorized destruction or alteration of that information.
- related to prevention or protection of the information
- The security of a system is a system property that reflects the system’s ability to protect itself from accidental or deliberate external attack 
- When an unauthorized access can result in an accident, then safety requires some security
- security is an essential prerequirement for availability, safety and reliability.
- Fundamental security: If a system is a networked system and is insecure then 
statements about its reliability and its safety are unreliable 
- Attributes:
    - Confidentiality: Only authorized individuals have access to data
    - Integrity: Data cannot be altered without the knowledge of those who own it
    - Availability: Data is available when needed
- Terminology:
    - Exposure: Possible loss or harm in a computing system. 
    - Vulnerability: A weakness in a computer-based system that may be exploited to cause an exposure.
    - Attack: An exploitation of a system vulnerability. Generally, this is from outside the system and is a deliberate attempt to cause some damage.
    - Threats: Circumstances that have potential to cause an exposure. 
    - Control: A protective measure that reduces a system vulnerability. 
- What causes security failure: AAA attributes
    - Architecture: software faults, bad designs
    - Administration: poor use of features
    - Attacks: Active intrusion
- No intrusions, then secure. Better administration minimizes risk. Better architecture limits impact of attacks.
- Security assurance:
    - Vulnerability avoidance: good design to avoid vulnerabilities
    - Attack detection and  elimination: early attack detection and elimination before they result in an exposure
    - Exposure limitation: the consequences of an attack are minimized

## Distributed system:
- A collection of autonomous computers linked by a computer network, and communicate and coordinate their actions only by message passing. 

## Challenges
- Software is a bottleneck: complexity vs productivity
- Complexity of design flows and supply chains: difficulties on specification and system integration
- Need for self-adaptive/ self-optimized behavior: higly dynamic environments
- New sofware design paradigm: future of software-intensive systems - ultra large, networked, distributed and diffuse-control nature
- Model based deployment: vehicle for communication between engineers from different areas.

## Summary
- Definition of software-intensive systems
- Characteristics of software-intensive systems
- Typical application domains (Automative, transportation, medicine, industrial automation, telecomunications)
- Challenges

# Foundations
- **Model**: a simplified representation of something, may be restricted to certain properties.
- **Specification**: a formal description of a system or component intended as a basis for further development. Rrequired properties that an artifact must ensure
- **Model based specifications**: a form of specification, usually software, that is develop based on a mathematical model of a system.
- Relation: 
    - A model can fulfill a specification
    - A model is also a specification
    - All models fulfill the empty specification

## Different kinds of model (Read SLIDES for notation)
- Phase specific models:
    - Requirement model: fulfills informal costumer need? specification for architecture model
    - Architectural model: fulfills requirement model? specification for design model
    - Design model: fulfills architectural model? specification for implementation model
    - Implementation model: fulfills design model?
- $M_r$ is a refinement of M if $M_r \subseteq M$
- $M_a$ is an abstraction of M if $M \subseteq M_a$

## System model types (Read SLIDES)
- Zeno behavior: described informally as the system making an infinite number of jumps in a finite amount of time

- Time stopping deadlock: when S2 goes to S1 there is a time stopping deadlock.

![Time deadlock](images/ESE_deadlock.jpg)

- Non-deterministic

![Non-deterministic](images/ESE_non_deterministic.jpg)

## System model Properties (Read SLIDES)
### Computation Tree logic (CTL)

![CTL operators](images/ESE_CTL_operator.png)

- Note:  W is X
- Example CTL: 
    - M, s |- AGg 
    - M, s |- AFg
    - M, s |- EFg
    - M, s |- EGg

- Safety: avoid that something bad happens 
- Liveness: avoid starvation and deadlocks

### State and sequence properties
- State property: a property _p_ is a state property if and only if _p_ belongs to some state given a specific state variable 
- Sequence property: a property _p_ is a sequence property if and only if _p_ belongs to the trajetory described by a specific path
- Safety:
    - non-empty (exists a sequence propertie)
    - if for all _t_ >= t0 the property _p_ belongs to _S_, then _p+1_ also belongs to _S_
    - this also applies if _k_ goes to infinity
- liveness:
    - exist in some point _t_  a property _p_ that belongs to _S_
    - slides examples: 
        - exists a point in the _Future_ in which _p_ belongs to _S_
        - There is a paths (**G**) that have points in the _Future_ in which _p_ belongs to _S_
        - There is a point in time (**F**) from when _p_ in paths  belongs to _S_

## Summary
- Semantics of automatas
- Zeno behavior and deadlocks
- Non-deterministic and what is refinement in hybrid automatas
- Difference State properties, sequence properties, stability and controllability 
