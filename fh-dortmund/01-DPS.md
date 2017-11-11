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
- **Concurrency**: is focus on cyberphysical systems. Concurrency is a property of a system representing the fact that multiple activities are executed at the same time. Only executing two different tasks simultaneously yields true parallelism.
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

---
# General Challenges and Solutions
## Why parallelism
- Physical limits of frequency scaling already met years ago
- Advantanges:
    - meet efficiency / performance demands / requirements
    - Better resource utilization, innovation and advancement
- Disadvantages: 
    - More complex design
    - Overheads: context switches, resource consumption (local mem, os resources for management)

## Concurrency - Parallelism
- **Process**: program instance
- **Task** is a specific part of a program
- **Thread**: has a virtual address space. runs in a single core
- **Runnable**: interface of a task
-  An application may process one task at at time (sequentially) or work on multiple tasks at the same time (concurrently). Subtasks can be calculated in parallel.

### Concurrency Models:
- Useful [link](http://tutorials.jenkov.com/java-concurrency/concurrency-models.html)
- Delegator:
    - Incoming jobs are assigned to different workers. Each worker completes the full job. 
    - Workers share states, complex and non-deterministic: shared states can be modified by other threads in the system
- Reactive Systems:
    - The system's workers react to events occurring in the system, either received from the outside world or emitted by other workers
    - Event driven system
    - No shared state between workers: they can be implemented without having to think about all the concurrency problems that may arise from concurrent access to shared state.
    - Deterministic
    - Hard to debug
- Functional Parallelism:
    - The basic idea of functional parallelism is that you implement your program using function calls. All parameters passed to the function are copied, so no entity outside the receiving function can manipulate the data.
    - Similar to atomic operation

## Problems
- Parallel and Distributed systems:
    - Race conditions, visibility
    - Deadlocks: program get stuck no more executions
    - livelocks: program get stuck but keep executing instructions
    - spinlock: stuck in a loop, `while(1)` for example
    - priority inversion: high priority task is indirectly preempted by a lower priority
- Coordination solutions for mutual exclusion
    - Semaphores
    - OS services, monitors
    - Mutex algorithms for critical sections
    - Syncronization

## Race conditions
- If result of multiple threads executing a critical section depends on the sequence in which the threads execute the critical section, then the program contains a race condition 
- **Solution**: Synchronized block or atomic operations
- Atomic operation: is the one that  appears to the rest of the system to occur instantaneously. Atomicity is a guarantee of isolation from interrupts, signals, concurrent processes and threads.

## 

## Lampart's Bakery algorithm
- Similar to when you draw a number and wait for your turn.

## Semaphore
- Can be seen as a counter that organized the resources
- With a queue the access to a resource can be schedule (fairness)

## Monitor 
- Semaphore + condition variable
- Multiple threads can be access the monitor, and the monitor manage the resources for the threads

## Coffman condition
- A deadlock situation on a resource can arise if and only if all of the following conditions hold simultaneously in a system

- Mutual exclusion: The resources involved must be unshareable; otherwise, the processes would not be prevented from using the resource when necessary. Only one process can use the resource at any given instant of time.
- Hold and wait or resource holding: A process holding resources can request more resources 
- No preemption: a resource can be released only voluntarily by the process holding it.
- Circular wait: each process must be waiting for a resource which is being held by another process, which in turn is waiting for the first process to release the resource. In general, there is a set of waiting processes, P = {P1, P2, …, PN}, such that P1 is waiting for a resource held by P2, P2 is waiting for a resource held by P3 and so on until PN is waiting for a resource held by P1.
