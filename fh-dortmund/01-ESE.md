---
course: Embedded systems Engineering
professor: Prof. Dr. Henkler 
semester: Winter 2017
---

# Introduction
- Typically have communications with people and other systems
- is the main driver for the industries
- **Embedded systems**: software embedded into a technical system which interacts with the world on a specific hardware
- **Embedded software engineering** is a multidisciplinary approach for developing Solutions to complex engineering problems.


## System characteristics
- Reactive systems: continuously sensing and reacting to the environment
- Real-time systems: The response should be delivered in a specific time. Executing in an specific time again and again
- Hard and soft Real-time systems: 
    - Soft real-time: it's allowed to miss the deadline 
    - Hard real-time: result must be delivered to the systems in a specific time, otherwise it will have terrible consequences.
- Continuous/discrete systems:
- Embedded systems:
    - Should be predictable even in the worst case scenario (cache, pipeline)
    - need real-time clock

## Possible HW-platforms 

## Dependable systems:
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

