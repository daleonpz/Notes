---
course: Introduction to embedded systems Designs
professor: Prof. Dr. Henkler / Schuster
semester: Winter 2017
---

# Foundations of Object Oriented Modeling and Design

## Software Development:
- Ideal: direct mapping from problem domain to implementation model
- Real:
    - work with model no real things
    - the implementation is not the one expected 

## Model based design:
- Model is interesting because it "tries to catch the problem as good as possible". Before implementation.
- Language should be precise
- Quality assurance: Constructive (object orientation) and Analytical (verification and validation).

## System:
- Small parts that works together, in an organized way, to full fill a specific task.

###  Systems engineering: 
- It is an **interdisciplinary approach** that concerns with all the aspects of the development and evolution of a successful system or product. 
- It considers both the business and technical needs of the **customers**.
- System engineers are involved in specify the overall architecture, and then integrating the different parts to create the finished system. 
- It focuses in analyze system requirements in order to develop a quality product.

### Software engineering: 
- is an engineering discipline that is concerned with all aspects of software production from initial conception to operation and maintenance. 
- It is focused on the quality
- It has well-defined principles
- It is a critical task, complexity is always increasing

## Extra definition:
- Software: Computer programs and associated documentation. Software products may be developed for a particular customer or may be developed for a general market.
- What are the attributes of good software?  Good software should deliver the required functionality and performance to the user and should be maintainable, dependable and usable.

## Model: 
- Abstract and simplified representation of something

## Design:
- It the process of defining things (interfaces, architecture, components)  and results (documentation)
- Create abstract implementation model

## Role of Design:
### Waterfall model:
- In principle at least, you plan and schedule all of the process activities before starting software development.
- Parts of the system that are well understood can be specified and developed using a waterfall-based process
- The Stages:
    - Requirements analysis and definition: established by consultation with system users. defined in detail
    - System and software design: allocates the requirements, system architecture, system abstractions and relationships.
    - Implementation and unit testing: 
    - Integration and system testing: after testing the software is delivered to the customer
    - Operation and maintenance: longest life-cycle phase
- Usually the results of each phase are documents
- Suitable for:
    - Embedded systems where the software has to interface with "inflexible" hardware systems. 
    - Critical systems where there is a need for extensive safety and security analysis of the software specification and design. Safety related problems are usually very expensive.
    - Large software systems that are part of broader engineering systems developed by several partner companies. Furthermore, where several companies are involved, complete specifications may be needed to allow for the independent development of different subsystems.

### V-Model
- Shows the software validation activities that correspond to each stage of the waterfall process model.
- Direct map between conceptual level and testing level
- There are feedback between blocks.
- Its phases:
    - Analysis
    - Coarse design: description of software architecture (decompose into subsystems, identify components, relations and cooperation between components).
    - Detailed Design: Component design (determine interfaces)
    - Implementation

### Spiral Model

!["Spiral Model"](./images/ITESD_spiralmodel.jpg "Spiral Model"){width=50%}

- Take into account iterations
- Typically starts with risk analysis.
- Phases:
    - Negotiation: with stakeholders, users (objectives, constrains, strategies)
    - Evaluation: Make or buy analysis
    - Implementation and testing: components, prototypes 1,2,... and final product
    - Planning: the next stage, review the product


Each loop in the spiral represents a phase of the software process. Thus, the innermost loop might be concerned with system feasibility, the next loop with requirements definition, the next loop with system design, and so on. The spiral model combines change avoidance with change tolerance. It assumes that changes are a result of project risks and includes explicit risk management activities to reduce these risks.

### RUP Model (check slides)

!["RUP Model"](./images/ITESD_RUPmodel.jpg "RUP Model"){width=75%}

- Design is important, spans through almost the whole life-cycle
- It's possible to know the efforts in each phase
- Requirements may change overtime
- Parallel
- Within each iteration, the tasks are categorized into nine disciplines:
    -  Six "engineering disciplines"
        - Business modeling
        - Requirements
        - Analysis and design
        - Implementation
        - Test
        - Deployment
    - Three supporting disciplines
        - Configuration and change management
        - Project management
        - Environment

### Propagate the change:
- Iterative Process:
    - Ensure core functionality first
    - Ensure that required extensions are possible
- Software Architecture and detailed design have to be flexible and extensible

### Life cycle and change
- First law of software evolution: software must be continually adapted or it will become less and less satisfactory
- First law of systems engineering: No matter where you are in the system life cycle, the system will change and the desire of change will persist throughout the entire life cycle.
- Software will change during maintenance

## Software Quality requires design: (READ slides)
- If there is a good design, it will be much simple to update a system.
- What are the attributes of good software?  Good software should deliver the required functionality and performance to the user and should be maintainable, dependable and usable.
- Good design: User view, Administrative/ Deployment view and Internal view

### Design principles:
- Separation of concerns: 
    - Try not to focus on the whole system as a unit
    - Breakdown the system, develop and design each part

- Information hiding:
    - Work with black boxes (interfaces)
    - Maintendable and extensable

- Abstraction: Focus on giving the relevant information to a particular purpose.

- Modularity: no coupling (full independency), functional (strong dependency)

### Object orientation
- An object has states and behaviours
- Classes: abstraction that defines propertios and characteristics of an object, are used as templates for objects.
- Usually we think in an oriented-object way

### Structured Analysis and Design
- Classes are used at all levels.

### OO & Modularity: 5 Principles
- Uniform access: All services offer by a module should be available through a uniform notation, which does not betray whether they are implemented through storage or through computation. 
For example in Ruby:

```ruby
#Setters are like:
 journey_plan.title = "South West Journey_plan"

#Getters are like:
 journey_plan.title
```

- Single choice: The goal is to put things which change for the same reason into the same place.
Structurally, it is a matter of inverting a nested relationship:

```
  Variation 1
  --operation A
  --operation B
  Variation 2
  --operation A
  --operation B
  etc...
```

Versus:

```
  Operation A
  --variation 1
  --variation 2
  Operation B
  --variation 1
  --variation 2
  etc...
```

### Software components
A software component is a unit of composition with contractually-specified interfaces and explicit context dependencies only. A software component can be deployed independently and is subject to composition by third parties. 


# Introduction to UML
- It is a visual language
- Neutral: independent form language programming

Some good [tutorial](https://www.youtube.com/watch?v=UI6lqHOVHic)