---
course: Distributed and Parallel Systems
professor: 
semester: Winter 2017
---

# Introduction
- In distributed systems  the computer power is distributed.
- The parallel systems are able to do calculations in parallel.
- Shared memory con be used as parallel systems. (read more about this)
- Distributed memory: 
- Distributed shared memory: it is possible to access to other physical memory using an Ethernet bus for example
- Distributed system cannot be in the same hardware
- Distributed computer system: 
    - Cluster for example
    - High-speed network (for security reasons) is not connect to Master node. 
    - High performance computation
- Distributed Information systems:
    - Not only one type of network
    - Paradigm: not try to implement high performance computation in this form
- Distributed Pervasive systems:
    - Store and process information
    - No calculation is done in the device, all are done in an external device

## Characteristics
- Shared resources (memory, bus)
- No global clock: no time stamp, it is an issue
- Inde. failure; some parts may fail due to power consumption
- Hetero: different types of devices working together. Need some type of virtualization
- Openness: no need to come closer to steal data (for example due to openness)
- Scalability: easily extended
- Concurrency: is focus on cyberphysical systems

## Advantages
- Efficiency: more processing for less effort
- Concurrency: some computation can be done in parallel
- Reliability: "backup device"

## Architecture
- Should be stable
- Manageable: manage resources, logistics
- Communication entities: clusters, microcontrollers, memory for example
- Communication paradigm: MPI
- Roles and responsabilities: several clients will access the backend. Roles implies access restrictions
- Placement: distribute tasks, data. Virtualization

## 4+1
- Logical view: relation between classes. Consider extend software
- Process view: communication between objects. Help with planning communication overload
- Physical view: HW
- Development view:  

