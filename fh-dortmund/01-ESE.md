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
    - Mechatronics: is the synergistic combination of mechanical, electronic and software engineering
    - Telematics: is the integrate use of telecommunications and informatics

## System characteristics
- Reactive systems: continuously sensing and reacting to the environment
- Real-time systems: The response should be delivered in a specific time. Executing in an specific time again and again
    - Deadline: the latest time until which the response to a stimulus is required.
    - Synchronous/periodic task: Can be used to address required activities with a period p. 
    - Asynchronous/aperiodic task: Can be used to address required activities for stimulus without knowledge about the occurrence.
    - Not only the correct behavior is important, but also its timely provision.
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
        - Hardware timers: more precise and flexible than RTOS ticks
        - Watchdog timers: a one-shot hardware timer that results  in a non-maskable interrupt when not re triggered
        - A/D and D/A converters: special support for converting analogous external signals to digital and vice versa
        - Serial communication controller: often at least used for development and debugging
        - Bus controller: direct support for special bus system 

## Possible HW-platforms 
- General purpose microprocessors: x86
- Highly integrate microprocessors: additional I/O on the chip
- Single chip microcomputer: ROM, RAM
- Single chip micro controller
- DSP
- Mixed-signal processor 
- Bespoken system-on-chip: ASICs, FPGA

## Dependable systems: 
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
- Need for self-adaptive/ self-optimized behavior: highly dynamic environments
- New software design paradigm: future of software-intensive systems - ultra large, networked, distributed and diffuse-control nature
- Model based deployment: vehicle for communication between engineers from different areas.

## Summary
- Definition of software-intensive systems
- Characteristics of software-intensive systems
- Typical application domains (Automotive, transportation, medicine, industrial automation, telecommunications)
- Challenges

# Foundations
- **Model**: a simplified representation of something, may be restricted to certain properties.
- **Specification**: a formal description of a system or component intended as a basis for further development. Required properties that an artifact must ensure
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
- Hybrid Automata: the states  **may** change as soon as the conditions are satisfied.


## System Semantics (Read SLIDES)
- Zeno behavior: described informally as the system making an infinite number of jumps in a finite amount of time

- Time stopping deadlock: when S2 goes to S1 there is a time stopping deadlock.

![Time deadlock](images/ESE_deadlock.jpg)

- Non-deterministic

![Non-deterministic](images/ESE_non_deterministic.jpg)

- Refinement:
    - The operator sigma means actions in this case
    - for any action "a" that belongs to the intersection between the set of action of the refinement and the set of action of the original model, if there is a transtition in the refinement given the action "a"  ( s -(a)> A (s1) ) , then there should be a transition in the original model for given the same action "a" ( t -(a)> B (t1) ). Note that the neither the source state nor the destiny state shouldn't be the same for both models. 
    - What is it important is that the outputs generated by a given action should remain the same. 

![Definition](images/ESE_ref01.png)

- In this example A2 is not a refinement af B1||B2, because it is not possible to "send a" in B1||B2 if x==2, since in that model "send a" it is only possible for x>=5. 

![Example](images/ESE_ref02.png) 

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
- Sequence property: a property _p_ is a sequence property if and only if _p_ belongs to the trajectory described by a specific path
- Safety:
    - non-empty (exists a sequence property)
    - if for all _t_ >= t0 the property _p_ belongs to _S_, then _p+1_ also belongs to _S_
    - this also applies if _k_ goes to infinity
- liveness:
    - exist in some point _t_  a property _p_ that belongs to _S_
    - slides examples: 
        - exists a point in the _Future_ in which _p_ belongs to _S_
        - There is a paths (**G**) that have points in the _Future_ in which _p_ belongs to _S_
        - There is a point in time (**F**) from when _p_ in paths  belongs to _S_

### Stability
- A trajectory _traj1_ is stable iff for any other trajectory _traj2_ the distance between these two is bounded for all time >= 0.
- A trajectory is asymptotically stable if the distance tends to zero overtime
- A model M is asymptotically stable if all its trajectories are asymptotically stables.

### Controlability
- State controllability: is usually taken to mean that it is possible – by admissible inputs - to steer the states from any initial value to any final value within some time window. In other words, that you will able to reach a state within some time window
- Output controllability: means the ability to manipulate the outputs of a system by admissible inputs. 
    - it may be the case in which it won't be possible to manipulate all the outputs of a system with several outputs just by the valid inputs. Thus, this system is not output controllable
- Observability: a system is observable if it is possible to know the current state just by knowing the output


## Summary
- Semantics of automatas
- Zeno behavior and deadlocks
- Non-deterministic and what is refinement in hybrid automatas
- Difference State properties, sequence properties, stability and controllability 

# The Development life cycle 
## Software Engineering life cycle model
[link](https://www.tatvasoft.com/blog/top-12-software-development-methodologies-and-its-advantages-disadvantages/#anchor1)
- Waterfall model:
    - Sometimes the requirements are not very clear at the beginning
- Prototyping process:
    - Based on the initial requirements
    - iterative process
    - sometimes it's used to see if it will be possible to develop the final product (internal process)
    - no focusing in the verification system
- V development process:
    - quality management
    - problem: no iterations that consider the update of the requirements
- Spiral model
- RUP model
    
IMPORTANT: when we could apply the different models?
- Waterfall: well defined systems. critical safety systems.
- Prototyping: Prototype model should be used when the desired system needs to have a lot of interaction with the end users.  Typically, online systems, web interfaces have a very high amount of interaction with end users, 
- V development: The V-Shaped model should be chosen when ample technical resources are available with needed technical expertise
- Spiral: When costs and risk evaluation is important, New product line, Significant changes are expected  
- RUP: development of  large, complex, engineered systems,

## System engineering life cycle model (check slides)
- Basically waterfall model
- Phases: Definition, development and deployment 
- Deployment phase:
    - We have an idea of the overall system before deploy it into subsystems
    - We distribute the system into subsystems 
- Focus on the complete system

## Embedded engineering life cycle model
- 3V Model:
    - Each V has a design, built and test phase 
    - Model level:
        - covers the definition and simulation of the overall system functionality 
        - Implementation aspects are not considered 
        - simulate in MATLAB for example
    - Prototype: 
        - is characterized by rapid prototyping hardware specific parameters become important 
        - deployment & message scheduling 
        - local design addresses the scheduling of tasks on each node 
        - the system should be able to run into specific hardware correctly. It's important to see how the hardware reacts in the environment
        - Idea of safety requirements 
    - Final product: 
        - complete system (real hardware and real environment)
        - typical problem: limited performance of the target system 
        - the system is stable, safety and reliable

- Multilevel V model:
    - the development of the complete system is decomposed into components 
    - typically start in the prototyping phase
    - the components could be developed by different companies (could be in parallel)\

## Advanced life cycle model and model driven development 
- Model driven architecture (MDA):
    - An approach to IT system specification that separates the specification of system functionality from the specification of the implementation of that functionality on a particular technology platform 
    - Design once and built it on any platform
    - models the perfect system for the problem domain
    - Platform independent model - PIM: all the requirements must be fulfill. UML
    - Platform specific model PSM: take into account things such as delays. checking is a correct refinement of PIM
    - Models permit to detect some problems early 
    - Reduced defect detection costs 
    - Reduced costs for defect removal 
    - Traceability and portability 
    - It is good to have some kind of trace between elements from different models

- Y model:
    - Manual coding: the requirements must be checked
    - Standard automatic: check if the generated code is correct with tests
    - Qualified code generator: model properties should not have conflicts
    - Design verified: guaranties that all the parts of the system works as expected
    - There is the need to specify the requirements in a formal way
- Platform model design
    - it could be the case that the designed model cannot run in any platforms 
    - it is good idea to have platform information to restrict the model design
    - bottom-top approach
    - platform design space: 
        - try to find which is the best platform for the system
        - focusing on the relevant parts

    - **Platform**: a family of architectures satisfying a set of constraints imposed to
allow the reuse of hardware and software components. 
    - **Platform-based design**: meet-in-the-middle approach: In the top-down design flow, designers map an instance of the upper platform to an instance of the lower, and propagate design constraints. 

- Process improvement:
    - System product life cycle:
        - from conceptual to production there is only investment
        - you have to know at which point in time our product will be still required
        - breakeven point: your investment is fulfill (return in investment point)
        - how long it's good idea to keep the development of a product 
- Process management:
    - The quality outcome and timeliness of the system development is highly influenced by the quality of the process used to acquire, develop, and maintain it. 
    - Common Misconceptions 
        - I don’t need process, I have really good people, advanced technology, an experienced manager 
        - Process: interferes with creativity, equals bureaucracy + regimentation, isn’t needed when building prototypes, is only useful on large projects, hinders agility in fast-moving markets, costs too much 
    - define processes in a well define way
- CMMI project
    - how much of the process is supported by a company
    - level 1 - initial: no process model, unpredictable, poorly controlled, it is reactive
    - level 2 - managed: we are able to monitor the end of an activity. it is often reactive
    - level 3 - defined: is organized and proactive. we have activities, and sub activities and we know when the sub activities are finished. We are able to measure
    - level 4 - quantitatively managed: we are able to measure and control sub activities and the whole process
    - level 5 - Optimizing: Focus on continous quantitative improvement. well defined process model. it's observable and verifiable
    - the greater the level, the lower the risk

## Summary 
- We have nearly the same life cycle models in the different disciplines. 
- Advanced life cycle models and model driven approaches try to increase the degree of automation and decrease time to-market. 
- Especially for organizations which develop large-scale software-intensive systems process improvement is crucial. 
- System LC vs Software LC: 
    - Retirement phase in the system
    - In software we focus on the development
- Software LC vs Embedded LC:
    - Embedded: 
        - we consider several phases, real Hardware, check if the control algorithm works
        - Consider also if the system is safe or the possibility of a hardware crash
- Model driven development: 
    - Ideal case no implementation
    - Ideal case there is code generator
    - You trust the automation tool
- Prototype model development: hardware constrains

# Requirements Engineering 
- bad requirements are the main cause of errors in software
- bad requirements are really expensive. 56% of costs of rectifying errors
- **Requirement Engineering** is the science and discipline concerned with analyzing and documenting requirements.
- ** Requirement**: 
    - A condition or capability needed by a user to solve a problem or achieve an objective, and its documented representation
    - A condition or capability that must be met or possessed by a system or system component to satisfy a contract, standard, specification, or other formally imposed documents, and its documents representation
    - Inputs:
        - Existing information systems: Information about the functionality of the systems to be replaced or systems that will interact with the system being specified.
        - Stakeholders needs: what the stakeholders need from the systems to support their work
        - Organizational standards: organizational practices, quality management
        - Regulations
        - Domain information: general information about the application domain
    - Outputs
        - Agreed requirements: a description of the requirements which is understandable by stakeholders and which has been agreed by them

## Requirement elements:
- Requirement elicitation:
    - the process through which the customer and developer discover, review, articulate, and understand the users’ needs and constraints on the software and development activities
    - Requirements elicitation is about discovering what requirements a system should be based upon
    - This doesn’t involve just asking stakeholders what they want. It requires a careful analysis of: The organization, The application domain, Organization processes where the system will be used, to determine the stakeholders need.
    - Elicitation process:
        - Establish objectives (Business goals, system constraints)
        - Understand background (Organizational structure, Application domain, Existing systems)
        - Organize knowledge (Stakeholder identification, Goal prioritization)
        - Collect requirements (Stakeholder requirements, Domain requirements, Organizational requirements)
    - Stakeholders: Anyone with a stake in creating or using a new system
    - Uncovered knowledge: 
        - Application domain knowledge: knowledge about airport systems
        - Context knowledge: knowledge about Denver Airport
        - Problem knowledge: knowledge about Denver’s baggage-handling system
        - Stakeholders needs and work processes to be supported
    - Requirements elicitation techniques: Interviews, questionnaires, examination of documentation (standards, laws), prototyping, contextual design
- Requirement Analysis:
    - the process of analyzing the customers’ and users’ needs to arrive at a definition of the requirements
    - The process of studying user needs to arrive at a definition of system, hardware, or software requirements.
    - The process of studying and refining system, hardware, or software requirements.
    - Analyze the results of elicitation: are the answers consistent?, identify trouble spots, identify boundaries, identify most important requirements
    - possibly iterate over elicitation again
    - The analysis has to establish an agreed set of requirements which are complete, consistent, and unambiguous. Such a set can be used as the basis for systems development.
    - Negotiation: Stakeholders often disagree over requirements. Therefore they need to negotiate to try to reach agreement.
- Requirement specification:
    - he development of a document that clearly and precisely records each of the requirements of the software.
    - Different specification methods have different levels of formality 
- Requirement validation:
    - the process of ensuring that the requirement specification is in compliance with the user needs
    - system requirements, conforms to document standards, and is an adequate basis for the architectural design.
- Requirement management: 
    - the planning and controlling of the requirements elicitation, specification, analysis, and verification activities.

## Requirement for complex systems
- A system of any but the smallest size will be decomposed into a hierarchy of elements (partitioning):
- Allocation: assigning requirements to elements
- Flowdown: requirements which respond to the allocated high level requirements
- Traceability: keep track of the dependencies
- Requirement engineering continues during design
- Design solution: HOW to achieve something
- Requirements: WHAT to achieve

## Requirements specification
- A document that specifies the requirements for a system or component. Typically included are functional requirements, performance requirements, interface requirements, design requirements, and development standards. 
- A Good Requirement Specification should be correct, unambiguous, complete, consistent, ranked for importance and/or stability, verifiable, modifiable, traceable

## SysML
- Relation with uml: activity, class, state machine, sequence, use case, composite structures
- New diagrams: requirements, allocations, parametric constrains

## Requirement diagram
- offers a graphical representation of the requirements
- Basic properties of a requirement: unique identifier, textual description of requirement
- Further properties of a requirement: priority, source, risk, status, verification method 
- Containment: split th requirement into single requirements.  A composite requirement may state that the system shall do A and B, which can be decomposed into the child requirements that the system shall do A, and the system shall do B 
- Refine: consist in adding precision
- Derivation: connect requirements from different levels. Usually involves some choice of architecture. A simple example would be a vehicle acceleration requirement that is analyzed to derive requirements for engine power, so the engine power is DeriveReq of the acceleration
- Satisfy: describes how a design or implementation model concept satisfies one or more requirements. It is not a proof
- Verify:  defines how a test case or other model element verifies a requirement
- Useful [link](https://re-magazine.ireb.org/issues/2015-2-bridging-the-impossible/modeling-requirements-with-sysml/)

# Analysis and design
## Introduction
- Analysis: 
    - what we would like to develop
    - Analysis phase belongs to the problem domain and it specifies a relevant subset of the real world according to the requirements
    - input: textual requirements
    - output: descriptive model
- Break down the system
- Design: 
    - Model the solution in the solution domain (computational model)
    - The process of defining the architecture, components and interfaces, and other characteristics of a system or component
    - Design description: A document that describes the design of a system or component.Typical contents include system or component architecture, control logic, data structures, input/output formats, interfaces descriptions and algorithms
    - Importance: 
        - translate requirements into product
        - stable for small changes
        - easy to test
    - Requirements are not stable
    - Change is important during development 
    - A designed system is more stable
    - Focus on the relevant elements of the real world
    - we must specify the constrains that reflects the real world
    - In the level of design is **how** to implement the elements
- First law of software evolution: the software models some reality, undergoes continual change or it becomes useless overtime.
- First law of system engineering: no matter where you are in the life cycle, the need of change will appear and it persists throughout the whole life cycle.

## Methods
- How to describe complex systems
    - Dynamic model (knowledge about causality)
    - Entity model (knowledge about relationships)
    - Functional model (knowledge about functionality)

## Analysis
- Analysis should model aspects of the real world that are relevant
- The model should only describe the required or the existing structure and behavior of the application
- The analysis model is the base for communication between the main stake holders (analysts, experts in the application domain and end-users of the system)
- Analysis with sysML:
    - block diagram: given structures and interfaces
    - Parametric constraint diagram: dependencies/ constrains between given elements
    - Activity diagram: scenarios describing required activities
    - Sequence diagram: required/ likely interaction scenarios
    - State machine diagram: complete state-depended reactive behavior of given elements

## SysML for analysis (Read SLIDES)
- View: conforms to a particular viewpoint. specify purpose
- Block diagram:
    - Block is a modular unit of system that encapsulates its content. Can be used to create composite structures, or divided in parts (blocks with their own content)
    - Application: model logical or physical systems (software, hardware, human organizations)
    - block definition diagram (bdd): represents block definitions (values, parts, references)
    - internal block diagram (ibd): describes a blocks in terms of parts, ports and connectors
        - Item flow: precise type across blocks
        - composition relationship in a bdd can be represented with an ibd. In the example traction detector and break modulator are part of anti-lock controller, but the sensors are a reference
    - Ports: the motivation is to have modular blocks that can be connected and interact with their context of use
        - Proxy: expose features of the owning block
        - full: expose features of the same block
        - Port flow: continuous interact with the environment
- Parametric constraint block: 
    - can be used to specify network of constrains that represents mathematical expressions
    - can be used to identify critical performance parameters and their relationship to other parameters
    - can be used to support trade off analysis
    - usually constrained properties express quantitative, and parametric models express non-quantities properties
    - time can be modeled as a property that other properties can use
- Activity diagram:
    - Activities specify sequential and concurrent behaviors that are connected by control flows and object flows.
    - Activities can be nested or atomic (actions)
    - can be used to specify causal/functional behavior of a system
    - Object flow: "no buffer" - only one element can be in the buffer, the rest are discarded
- Sequence diagram:
    - can be used to model communications among block structures arranged in time order

## Design 
- Analysis overview:
    - Block diagrams:
        - definition: Block is a definition/type, captures properties and can be used in multiple contexts
        - Use ports with flow properties to model the bus architecture
        - Port types with flow properties can be the CAN bus
- The designer focuses on the solution of the problem (solution domain) which involves many tasks (subsystem decomposition, selection of the hardware, etc)
- The design model should describe the solution but may also include required or existing structure and behavior of the application identified during analysis
- Main stakeholders: designer, implementer
- Analysis vs design:
    - There is no clear boundary between analysis and design
    - Analysis concerns the description of the problem and the user requirements
    - Design concerns the construction of a solution which satisfies the previously recorded requirements
    - transition to design must transform analysis objects into design objects

## Design with SysML
- State Machine diagrams:
    - can be used to model discrete behavior through finite state transition systems in terms of its transitions and states
    - the activities  that are invoked during the transition, entry and exit of the states are specified along  with the associated event and guard conditions
    - Activities that are invoked while being in a state are specified as "do activities", and can be either continuous or discrete
    - A composite state has nested states that can be sequential or concurrent
- Allocation diagram:
    - Enables traceability
    - denote the  organized cross-association (mapping) of elements within the various structures or hierarchies of a user model
    - Describes a design decision that assigns responsibility for meeting a requirement (requirement allocation) or implementing a behavior (functional allocation) to structural elements of the system
    - The allocation relationship can provide an effective means for navigating the model by establishing cross relationships, and ensuring that the various parts of the model are properly integrated
- Activity is used usually for algorithm behaviors

## Analysis and design summary
- There exists different decomposition principles such as functional structuring, data-flow structuring and object-oriented structuring which may occur in combination when analyzing or designing a complex system.
- SysML (UML) provides a rich set of modeling concepts for the analysis and design of software intensive systems.
- While analysis focuses on the requirements and problem domain, the design describes the proposed solution (which might include some elements of the problem 

## Implementation
- Desirable features of real-time systems
    - Timeless: OS has to provide the kernel mechanisms for time management and handling tasks with explicit time constrains
    - Design for peak load
    - Predictability
    - Fault tolerance
    - Maintainability
- Types of constrains - Scheduler
    - Timing constrains: meet your deadlines
    - Precedence constrains: respect pre-requisites
    - Resource constrains: access only available resources 
- Timing constrains:
    - Real-time systems are characterized mostly by timing constrains
    - Typical constrain: deadline
    - worst case execution time: is the maximum length of time that a task could take to execute on a specific hardware platform
    - the real worst case execution time is hard to find, there's a probability that the "worst case" hasn't been taken into account. 
- Hard RTS: missing the deadline can cause catastrophic consequences
    - Soft RTS: missing the deadline decreases the performance of the system
- Precedence Relation: check DPS slides
- Resource constrain:
    - Process view: resource is any SW structure to be used by process (memory data file, set of variables)
    - private resource: dedicated to a particular process
    - shared resource: to be used by more than one process
    - exclusive resource: shared resource where simultaneous access from different processes is not allowed
    - critical section: piece of code that is executed under mutual exclusion constrains
- Scheduling:
    - Precedence's may be given using precedence graph and timing constrains may be associated to each task
    - Scheduling means to assign processors and resources to tasks in order to complete all tasks under the imposed constrains
    - NP-complete: non-deterministic polynomial time
    - In the ideal case we know the worst case execution time and the scheduler works always
    - Classification of scheduling algorithms: 
        - Preemptive: if a low priority task is executing and it's preempted by a higher execution task
        - non-preemptive: a task, once started is executed until completion
        - Static: scheduling decisions are based on fixed parameters (off-line)
        - Dynamic: try to optimize the scheduling algorithm and then decide which task is executing next
        - off-line: is performed on the entire task set before start of system. Calculated schedule is executed by dispatcher
        - on-line: scheduling decisions are taken at run-time every time a task enters or leaves the system
        - optimal: the algorithm minimizes some given cost function, alternatively: it may fail to meet a deadline only if no other algorithm of the same class can meet it
        - heuristic: algorithm that tends to find the optimal schedule but does not guarantee to find it
- Guarantee-based Algorithms:
    - hard real-time systems: highly predictable behavior, systems has to plan actions by looking ahead into the future assuming the worst-case scenario.
    - static real-time systems:
        - all task activation can be pre-calculated off-line
        - entire schedule can be store in a table
        - run-time simple dispatching due to tables takes place
    - off-line: very sophisticated algorithms possible. however, system is inflexible to environmental changes
    - Dynamic real-time system: guarantee must be done on-line each time a new task enters the system
- Real-time scheduling:
    - Aperiodic scheduling: 
        - Earliest deadline first (EDF): Optimal dynamic priority scheduling, a task with a shorter deadline has a higher priority, executes a job with the earliest deadline
   - Periodic scheduling: Rate Monotonic Priority Assignment (RM),  Earliest Deadline First (EDF)
    - Server: Fixed Priority, Dynamic Priority
16
- Support for extra hardware: support is required for Real-time clocks, Interrupts, Hardware timers, Watchdog timer, A/D and D/A converter, Serial communication controller, and  Bus controller
    - Typically supported by special RTOS, drivers or APIs
- Dependable systems: 
    - reliability, availability, safety, security should be addressed (included in the requirements, appropriate architecture/design, validation and verification helps to remove faults)
- Distributed system:
    - Synchronization of independent programs, run-time configuration (heterogeneity, resource sharing, openness, concurrency)
    - block should be loose decoupled (lack of global clock, scalability, failure handling)

## Implementation - Manual coding
- Assembly language: avoid whenever possible (hardware depended, insecure - you can access to every part), possible reasons to use it (speed, hardware testing, interrupt handling)
- Programming language:
    - Essential features which are required to realize the system (really needed)
    - Primary features for correct, reliable and safe programs (needed to produce high-quality software)
    - Secondary features which make a significant contribution to productivity, portability, maintainability, flexibility and efficiency (features useful from an economic perspective)
- Coding patterns:
    - Reactivity: how to implement a state machine (state pattern, state table pattern, state walker pattern, fuzzy state pattern)
    - State pattern:
        - Intent: Allow an object to alter its behavior when its internal state changes
        - Also Known as: Objects for States
        - Applicability:  The object behavior depends on the state,  Operations have large multipart conditionals statements that depend on object state
        - Participants: 
            - Context: defines interface of interest and handles current state
            - State: defines an interface encapsulating the behavior associated with each particular state
            - Concrete State: specific implementation of state 
        - Implementation: switch/if statements for simple cases
        - Pros: Encapsulates state dependent behavior, avoid that each operation distinguish the different states using additional conditional statements, relevant states are better supported 
        - Cons:  Run-time overhead due to additional reference
    - State table pattern:
        - Shortcomings: The State pattern is rather inefficient for a large number of states due too the dynamic creation of states.
        - Solution: Use a state table as a simple mechanism for managing state machines which handle a transition in constant time 
        - Remark: Only implementation alternative for the State Patter
        - Pros: Low constant basic execution costs after it is set up, Direct mapping to tabular state specifications often used for safety-critical systems, Decouple transition and states and permit many transitions to be realized using a single transition object
        - Cons: Relatively high initialization cost, High complexity of the pattern
    - Synchronization: The synchronization between the different tasks is of crucial importance concerning scheduling and reusability (priority inversion, priority ceiling, ect)
        - Priority ceiling: The idea is that if an important task is blocked by an unimportant one, so the unimportant one is elevated and executed quickly to release the lock
            - Pros:  Prevents the unbounded priority inversion problem, Pre-computation of resource priority ceiling possible  
            - Cons: Complexity, Resulting run-time overhead, less demanding alternatives, Basic Priority Inheritance Protocol, Highest Locker Protocol
        - Rendezvous: 
            - Problem: how to synchronize tasks in such a manner that they are still somehow independent reusable
            - solution: it refines the synchronization of two threads as an object itself. The Rendezvous object may contain data to be shared as the threads synchronize, or it may simply provide a means for synchronizing an arbitrary number of threads 
            - Pros: Synchronizer partially decouples related tasks, Synchronizer encapsulated required pre-conditions
            - Cons: The solution with a synchronizer might restrict the parallel processing and hence blocks the performance of the system more than required
    - Memory management and safety:
        - Problem: heap fragmentation, explicit dynamic memory management is notoriously error prone 
        - Solution:
            - Static allocation: avoid heap fragmentation, but it may not scale up well to large problems, not possible to allocate all the block (memory limit), inefficient memory management
            - fixed size allocations: all the objects will have the same memory size. Eliminates fragmentation, but wasteful of memory (there will be unused memory)
            - smart pointer: `<unique_ptr>` in c++. It will avoid raw references, but complex run-time behavior, run-time overhead

## Verification and Validation
- Foundations:
    - Verification: refers to the set of activities that ensure that the software correctly implements a specific function
    - Validation: refers to a different set of activities that ensure that the software  that has been built is traceable to customer requirements
    - static analysis: the process of evaluating a system or component based on its form, structure, content, or documentation. No execution of the program. Modeling (mathematical representation)
    - Dynamic analysis: The process of evaluating a system or component based on its behavior during execution. Execution of system components. Running the software
- Static analysis tecniques:
    - Technical reviews: personal review, walkthroughs, inspections, formal review
    - Static code analysis: 
    - Formal methods: discrete mathematics, logics
    - Model checking: an automated proof method and a precise system analysis tool
    - Input-output pattern
        - Reactive programs: carry out an ongoing interaction with their environment
        - Semantics: transition systems (Kripke structure)
        - Specifications: temporal logic
        - Method: model checking
    - kripke structure:
        - state based
        - with statistics, predicators and transitions
    - the state machine includes temporal logic that must be checked
    - Software model checking: Reality check
    - Why model checking is difficult?
        - Model construction problem:
            - Semantic gap: are the abstractions right?, no direct mapping, the implementation level is more detailed, the requirement must be fulfill also in the implementation
        - Model specification problem: difficult to formalize a requirement in temporal logic, because specification are partial or not clear.
        - States explosion problem
            - the more components there are, the less feasible is checking  all of them
            - the only thing that helps is the compound component checking approach 
        - Output interpretation problem: it's hard to find the exact error or trace the error
    - Input languages for model checking: synchronous languages, finite automata, timed and hybrid automata 
    - Model checking - Summary:
        - Instead of a "complete" specification use only one that consists of relevant properties (e.g., for safety)
        - Usually only restricted notions for formal models:  Finite automata (or similar restricted models)
        - Often restricted notions for formal properties:  Prepositional logic, Temporal logic (Model-Checking)
        - Benefits: Counterexample when a property is not fulfilled
        - Limitations: Not feasible for too large models (state explosion), Not feasible for too complex formal properties

- Dynamic analysis:
    - Testing is a process of executing a program with the intent of finding an error.
    - A good test case is one that has high probabilities of finding an error
    - A succesful test is one that uncovers an as-yet undiscoverd error
    - Test:  An activity in which a system or component is executed under specified conditions, the results are observed or recorded, and an evaluation is made of some aspect of the system or component.
    - Objetives: 
        - Design tests that systematically uncover defects 
        - Help managers make ship or no-ship decisions
        - Minimize risks
        - Find safe scenarios for use
    - Indirect objectives: to compile a record of software defects for use in error prevention 
    - Testing approaches:
        - black box: ignores the internal mechanism of the system or component and focuses on the output in response to some inputs. Also to evaluate the compliance of a system or component with specified functional requirements. Function testing
        - White box: takes into account the internal mechanism of a system or component
    - Black box testing:
        - Function testing: 
            - Test each function / feature / variable in isolation.
            - Usually start with fairly simple function testing
            - Later switch to a different style which often involves the interaction of several functions
            - These tests are highly credible and easy to evaluate but not particular powerful
        - Regresion testing
            - Process: (1) design tests with the intent of regularly reusing them (2)repeat the tests after making changes to the program.
            - A good regression test is designed for reuse.
            - Discussion: at first run usually detect several defects, but it decrease its power in each run. However, automation can make regression testing very cheap
        - Regresion testing strategies
            - Random: The test cases are randomly selected from the existing test suite.
            - Retest-all: Run all the tests in the existing suite.
            - Safe: The test selection algorithm excludes no test from the original test suite that if executed would reveal faults in the modified program.
            - Based on modifications: Place an emphasis on selecting existing test cases to cover modified program components and those that may be affected by the modifications.
            - Dataflow/coverage based: Select tests that exercise data interactions that have been affected by modifications.
    - White box testing:
        - Control flow testing:
            - Statement coverage: The test cases are generated so that all the program statements are executed at least once.
            - Decision coverage (branch coverage): The test cases are generated so that the program decisions take the value true or false.
            - Condition coverage: The test cases are generated so that all the program conditions (predicates) that form the logical expression of the decision take the value true or false.
            - Path coverage: Test cases are generated to execute all/some program paths
        - Data flow testing:
            - based on selecting paths through the program's control flow in order to explore sequences of events related to the status of variables or data objects
    - Comparison between black box and white box
        - Black box:
            - no access to information about the system implementation  
            - Characteristics: good for independence of tester, hard to test individual modules
        - White box:
            - tester can access to information about the system implementation
            - Characteristics: simplifies diagnosis of results, can compromise independence, how much do they need to know?

    - Testing process and activities
        - Beforehand: requirements analysis and design analysis
        - Process and activities
            - 1.Unit test: inputs for integration test
            - 2.Integration test: test design specifications, integrated modules (output)
            - 3.Function test: test system functional requirements, functional system (output)
            - 4.Performance test: test other software requirements, verified-validated software (output)
            - 5.Acceptance test: test costumer requirements specifications, accepted system (output)
            - 6.Installation test: test user environment, system in use (output)
    - Testing software intensive system:
        - Software Intensive Systems include:
            - Large scale heterogenous systems
            - Embedded systems for automotive applications
            - Telecommunications
            - Wireless ad-hoc systems
            - Business aplications with an emphasis on web services
        - Testing embedded systems
            - What is an embedded system?
            - What is the correct behavior? range tolerance in value and time 
            - Development Stages: Simulation, Prototyping, Pre-Production, Productio
        - Simulation:
            - Model test (MT): one way test
            - Model-in-the-loop (MIL): feedback simulation 
            - Rapid prototyping (RP)
        - Prototyping:
            - Software-in-the-loop (SIL)
            - Hardware-in-the-loop (HIL)
            - Read SLIDES 
        - Pre-Production: 
            - System test (ST): test a pre-production unit
            - Goals: validation, Demonstrate that production effort and schedule can be met,  Demonstrate maintainability and meantime-to-repair requirements,  Demonstrate product to potencial customers.
            - Typical tests: real-life testing, random testing, fault injection
        - Production:
            - development and test of the production facilities (often equally important for quality)
            - Often a first article inspection of similar style as the pre-production test is required
            - Production and maintenance tests on production units may required for quality control
        - Comparison of test levels: Check SLIDES (upper yellow -model, below red - production, in between - prototyping

- Summary:
    - Two main approaches to testing (dynamic analysis) are black box testing, which ignores the internal mechanism of the system or component (sometimes named functional testing), or white box testing, which takes into account the internal mechanism of a system or component (sometimes named structural testing).
    - The testing activities during development should include, unit tests, integration tests, and system tests. System tests may be divided into function tests, performance tests, acceptance tests, and installation tests.  
    - Testing embedded systems for automotive application (SIS) includes testing processes like Model-/Software-/Hardware-in-the-loop at different development stages.
    - Besides dynamic analysis (testing), which includes the execution of the software, also are available effective static analysis techniques such as reviews or inspections and formal methods.
    - The complexity and properties (e.g. safety) of software intensive systems require exhaustive verification and validation activities.
    - Due to the lack of one technique (e.g. Model Checking, Testing) an appropriate combination of the verification and validation
