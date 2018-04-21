---
course: Internet of Things and Edge Computing
professor: Prof. Dr. Rolf Schuster
semester: Summer 2018
---

# Introduction
- **Def**: Internet of things is the network of embedded systems and connectivity which enables these objects to connect and exchange data.
- Mobile computing (embedded systems) and cloud computing are slowly drifting apart
- We need connected compute power and storage close to mobile devices and embedded systems
- **Edge Computing**: Little data centers and computing resources right next to the mobile device or sensor
- **Def**: Edge computing builds something that connects cloud computing and embedded systems that provides storage and computation
- Characteristics:
    - Low latency
    - Edge stations / servers work as "Cache memory"
- Application: big data, virtual reality, drone support services, online gaming

![Course Map](images/iot-course.png)

# Real-Time Embedded systems
## Common Characteristics
- Dependability: 
    - Reliability: probability of a system to work as expected
    - Maintainability: probability of a system to work correctly _d_ time units after an error occurred
    - Availability: probability of a system to work on request at any time
    - Safety: no harm to be cause
    - Security: confidential and authentication  communications 
    - Even perfectly designed systems can fail if the assumptions about the workload and possible errors turn out to be wrong
- Efficiency:  Code size, run-time, weight, cost, energy
    - There is a trade-off between low energy consumption and flexibility (multi-purpose)
- Real-time constrains:
    - A real-time system must response to an stimuli from the controlled object within an interval given by the environment
    - Hard real-time system: if the deadline is not met, it will have catastrophic consequences

## Embedded Systems Hardware
 - Input
    - Embedded systems hardware is frequently used in a loop (hardware in a loop)
    - Sensors: 
        - can be designed for virtually every physical and chemical quantity
        - Measure signals; **signal** is a mapping from time domain to value domain, can be continuous or discrete
        - Discretization of time: Sample and Hold (transistor + capacitor) and A/D converters (Flash ADC - comparator + Encoding)
        - Types: 
            - Basic sensor (chemical/ physical quantity but not electrical)
            - Integrated sensor: basic sensor + signal processing (filtering usually)
            - Intelligent sensor: integrated sensor + preprocessing (fusion, pattern recognition)
- Processing
    - Microcontroller: CPU + Memories + Peripherals, also could have Interrupt system, watchdog, debugging interface, and oscillator
    - Examples of ARM processors (CHECK SLIDES)
    - Trend: multiprocessor system-on-chips (MPSoC)
- Memories
    - Efficiency is a concern (capacity, speed, energy, predictable timing, size, cost, etc)
    - Types:
        - SRAM/ DRAM: Data is lost as soon as power is switched off, for run time data
        - Flash: Typically 10K write cycles, write only block-wise, not always is possible to read, for program code
        - EEPROM: Typically 100K write cycles, access is always indirect, byte-wise access, for configuration
    - Trends: Speed gap between processor and main DRAM decreases, Memory access time is much lower than processor access time. Hierarchical memories using scratch pad memories (SPM) which are small but physically separate memory mapped into the address space. They are mostly suited for storing temporary results. More info [here](https://en.wikipedia.org/wiki/Scratchpad_memory).
- Output:
    - OPAMPs (amplify voltage, impedance)
    - DAC
    - Actuators: influence physical processes based on electrical signals

## Embedded Systems Software
    - Real-time Operating Systems
        - Embedded operating systems: Configurable, devices are handle by tasks, protection is optional, real-time capability
        - Configurability:
            - Avoid overhead of unused functions
            - Conditional compilation 
            - Linker time optimization (removal of unused functions)
            - Dynamic data might be replaced by static data
        - Devices are handle by tasks
            - Effectively no device needs to be supported by all variants of the OS
            - Disk and network handle by tasks instead of integrated drivers
        - Protection is optional
            - Sometimes it's not required
            - However, protection mechanisms may be needed for safety and security reasons
        - Interrupts not restricted to OS
            - Interrupts can be employed by any process
            - More efficient than going through OS services
            - Reduce composability, if there is direct mapping of a SW to an interrupts, it means that another SW cannot use it.
        - Real-time capability: Many embedded systems are real-time systems, hence, the OS should have that capability as well
            - **Def** real-time operating system is an operating system that supports the construction of real-time systems
            - The time behavior of the OS must be **PREDICTABLE**
            - OS should manage the timing and scheduling (aware of task deadlines, precise time services with high resolution)
            - Time synchronization (universal clocks)
            - Synchronization with one master clock or Distributed synchronization (christian's algorithm, Berkeley algorithm)
            - Problems with external synchronization: erroneous values are copied to all stations, many time formats are too restricted
            - The OS must be fast
            - RTOS-Kernels: include resource management (processor, memory, timer), task management and synchronization.
                -  Fast RTOS: are fast but not predictable (QNX, VxWORKS, VCOS)
                - RT extensions to standard OSs: RT-task cannot use standard OS services but if the OS crash the RT-task still working (RT linux, RTAI, FreeRTOS)
                - Research trying to avoid limitations
    - Resource Access Protocols
    - Scheduling in real-time Systems

## Real-Time Embedded Systems and Edge Computing
