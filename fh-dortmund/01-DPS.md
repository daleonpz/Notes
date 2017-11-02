---
course: Distributed and Parallel Systems
professor: Lukas, Uwe
semester: Winter 2017
---

# Introduction
- **Def**: A distributed system is a collection of independent computers that appears to its users as a single coherent system. In which hardware and software components located at network computers communicate and coordinate their actions using only messages.
- In distributed systems the computer power is distributed.
- The parallel systems are able to do calculations in parallel.
- In parallel computing, all processors may have access to a shared memory to exchange information between processors.
- In distributed computing, each processor has its own private memory (distributed memory). Information is exchanged by passing messages between the processors.

## Types of memory
- **Shared memory**: 
    - From a strictly hardware point of view, describes a computer architecture where all processors have direct (usually bus based) access to common physical memory
    - can be used in parallel systems. In a programming sense, it describes a model where parallel tasks all have the same "picture" of memory and can directly address and access the same logical memory locations regardless of where the physical memory actually exists. 
- **Distributed memory**: 
    - In hardware, refers to network based memory access for physical memory that is not common.
    - As a programming model, tasks can only logically "see" local machine memory 
- **Distributed shared memory**: it is possible to access to other physical memory using an Ethernet bus for example
- Distributed system cannot be in the same hardware

## Characteristics
- Concurrency: is focus on cyberphysical systems. Concurrency is a property of a system representing the fact that multiple activities are executed at the same time. Only executing two different tasks simultaneously yields true parallelism.
- Shared resources (memory, bus)
- No global clock: no time stamp, it is an issue
- Independent failure; some parts may fail due to power consumption
- Heterogeneity: different types of devices working together. Need some type of virtualization
- Openness: Be able to interact with services from other open systems, irrespective of the underlying environment. 
- Scalability: a system is considered scalable if it is capable of increasing its total output under an increased load when resources (typically hardware) are added 

## Distributed System Categories
- Distributed computer system: 
    - Cluster and Grid computer systems for example
    - High-speed network (for security reasons) is not connect to Master node. 
    - High performance computation
- Distributed Information systems:
    - Client-Server applications. Transaction Processing Systems for example
    - Not only one type of network
    - Paradigm: not try to implement high performance computation in this form, information systems are meant to work with databases or to produce information.
    - A computer information system is a system composed of people and computers that processes or interprets information. The term is also sometimes used in more restricted senses to refer to only the software used to run a computerized database or to refer to only a computer system.
- Distributed Pervasive systems:
    - Electronic Health Care Systems for example
    - Store and process information
    - Small nodes, mobile, usually embedded, battery-powered
    - No calculation is done in the device, all are done in an external device
    - computing is made to appear anytime and everywhere. 

## Advantages
- Efficiency: more processing for less effort
- Concurrency: some computation can be done in parallel
- Reliability: "backup device"
- Scalability: easily extended

## Disadvantages
- Complexity:
    - Concurrency is sometimes hard to achieve
    - Reliability needs to be implemented
    - Scalability
- Security
- Manageability: 
    - The key to high availability is redundancy: if you have more than one of everything, you’re not susceptible to any single points of failure
    - Manageability includes both the ability to detect faults (or the absence of faults) and the ability to automatically react to the

# Architecture
- Architecture usually serves some purpose
    - Ensure that the structure will meet present and likely future demands
    - Reliable
    - Manageable: manage resources, logistics
    - Adaptable
    - Cost-Effective
- Architectural elements in developing distributed embedded systems
    - Communication entities: clusters, micro controllers, memory for examples
    - Communication paradigms: MPI
    - Roles and responsibilities: several clients will access the back-end. Roles implies access restrictions
    - Placement: distribute tasks, data. Virtualization
- Should be stable

## Viewpoints
- Different diagrams to capture structure and behavior (UML)
- Different roles have different viewpoints on systems

## Kruchten's 4+1
- Logical view: 
    - End-user functionality
    - relation between classes. 
    - Consider extend software
- Process view:
    - communication between objects. 
    - Help with planning communication overload (threads, tasks and their interdependencies)
- Physical view: 
    - System engineer viewpoint
    - Describes the mapping from software to hardware
    - Structural Information: Processing units, memories, networks, data, communication
- Development view:
    - Software engineer viewpoint 
    - Describes the organization of software
    - Modules and dependencies 
- Use case View:
    - End users and developers view
    - Describes user focused scenarios 

