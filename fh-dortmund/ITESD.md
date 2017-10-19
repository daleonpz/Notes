---
course: Introduction to embedded systems Designs
professor Prof. Dr. Henkler / Schuster:
semester: Winter 2017
---

# Software Development:
- Ideal: direct mapping from problem domain to implementation model
- Real:
    - work with model no real things
    - the implementation is not the one expected 

# Model based design:
- Model is interesting because it "tries to catch the problem as good as possible". Before implementation.
- Language should be precise
- Quality ensurance: Constructive (object orientation) and Analytical (verification and validation).

# System:
- Small parts that works together too fullfill a specific task.

##  System engineering: 
- It is an **interdisciplinary approach** that concerns with all the aspects of the development and evolution of the product. 
- It considers both the bussines and technical needs of the **customers**.
- System engineers are involved in specify the overall architecture, and then integrating the different parts to create the finished system. 
- It focuses in analize system requeriments in order to develop a quality product.

## Software engineering: 
- is an engineering discipline that is concerned with all aspects of software production from initial conception to operation and maintenance. 
- It is focused on the quality
- It has well-defined principles
- It is a critical task, complexity is always increasing

# Extra definition:
- Software: Computer programs and associated documentation. Software products may be developed for a particular customer or may be developed for a general market.
- What are the attributes of good software?  Good software should deliver the required functionality and performance to the user and should be maintainable, dependable and usable.

# Model: 
- Abstract representation of something

# Design:
- Defining things (interfaces, architecture, componenents)  and results (documentation)
- Create abstract implementation model

# Role of Design:
## Waterfall model:
- In principle at least, you plan and schedule all of the proces
activities before starting software development.
- Parts of the system that are well understood can be specified and developed using a waterfall-based process
- The Stages:
    - Requeriments analysis and definition: established by consultation with system users. defined in detail
    - System and software design: allocates the requirements, system architecture, system abstractions and relationships.
    - Implementation and unit testing: 
    - Integration and system testing: after testing the software is delivered to the customer
    - Operation and maintenance: longest life-cycle phase
- Usually the results of each phase are documents
- Suitable for:
    - Embedded systems where the software has to interface with "inflexble" hardware systems. 
    - Critical systems where there is a need for extensive safety and security analysis of the software specification and design. Safety related problems are usually very expensive.
    - Large software systems that are part of broader engineering systems developed by several partner companies. Furthermore, where several companies are involved, complete specifications may be needed to allow for the independent development of different subsystems.

## V-Model
- Shows the software validation activities that corre spond to each stage of the waterfall process model.
- Direct map between conceptual level and testing level
- There are feedback between blocks.

## Spiral Model
- Take into accoun iterations
- Typically starts with risk analysis.
Each loop in the spiral represents a phase of the software process. Thus, the innermost loop might be con-
cerned with system feasibility, the next loop with requirements definition, the next loop with system design, 
and so on. The spiral model combines change avoidance with change tolerance. It assumes that changes are 
a result of project risks and includes explicit risk management activities to reduce these risks.

## RUP Model
- Design is important, spans through almost the whole life-cycle
- It's possible to know the efforts in each phase
- Requeriments may change overtime
- Parallel

# Extra notes:
ware being developed. For example, safety-critical software is usually developed 
using a waterfall process as lots of analysis and documentation is required before 
implementation begins. Software products are now always developed using an incre-
mental process model. Business systems are increasingly being developed by con-
figuring existing systems and integrating these to create a new system with the 
functionality that is required.




