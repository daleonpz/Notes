---
course: Microelectronics 
professor: Prof. Dr. 
semester: Summer 2018
---

# Chapter 01: Introduction
- **Observation 1.1.** Microelectronics is the enabler of information technology.
- An integrated circuit (IC) is an electronic component that incorporates and interconnects a multitude of miniature electronic devices, mostly transistors, on a single piece of semiconductor material, typically silicon.

## size point fo view
- In a world obsessed with records, a foremost question asks “How large is that circuit?”.
    - **Die size** is a poor metric for design complexity because the geometric dimensions of a circuit greatly vary as a function of technology generation, fabrication depth, and design style.
    - **Transistor count** is a much better indication. Still, comparing across logic families is problematic as the number of devices necessary to implement some given function varies.3
    - **Gate equivalents** attempt to capture a design’s hardware complexity independently from its actual circuit style and fabrication technology. One gate equivalent (GE) stands for a two- input nand gate and corresponds to four MOSFETs in static CMOS; a flip-flop takes roughly 7 GEs. Memory circuits are rated according to storage capacity in bits. 

## marketing pov
- general purpose IC: The function of a general-purpose IC is either so simple or so generic that the component is being used in a multitude of applications and typically sold in huge quantities.
- application specific IC
    - glue logic
    - The term system-on- a-chip (SoC) has been coined to reflect the development of the ASICs

## fabrication POV
- full custom IC: layers are patterned according to user specifications.
- semi custom IC: Only a small subset of fabrication layers is unique to each design. there is a master preprocessed layer or template, in which the gates, transistor or whatever will be interconnected depends on user needs using a connection layer. 
- field programmable logic: . No custom photomasks are involved. Field- programmable logic (FPL) devices are best viewed as “soft hardware"

## developer POV
- hand layout: slow, expensive, prone to errors, but it can out performs synthesis based designs
- Cell libraries and schematic entry: cell libraries encapsulates the physical details and allows a faster and easier development using schematics entries. The developer has to connect in a schematic blocks.
    - microcells: flip-flop, logic gates, registers
    - megacells: peripheral, ADC, DAC
    - macrocells: ROM, RAM
- automatic circuit synthesis: synthesis models are established using a text editor and look like software code. a Hardware descriotion language is used (HDL). 
    - logic synthesis: level of truth tables, logic operators
    - register transfer level (RTL) synthesis: state machines, arithmetic operation
    - architecture synthesis: starts with algorithm descriotion such as in c++, and the synthesis is made based on this. the results are not that good compared to RTL o logi synthesis.
- design with virtual components: known as intelectual property modules. some common are USB interfaces, digital filter

## VLSI design flow
- From a behavioral perspective we are only interested in what a circuit or system does, not in how it is actually built. Put differently, the design is viewed as a black box that processes information by producing some output symbols in response to some input symbols
- A structural way of looking at electronic circuits is concerned with connectivity, that is with the building blocks from which a circuit is composed and with how they connect to each other.
- What counts from a physical point of view is how the various hardware components and wires are arranged in the space available on a semiconductor chip or on a printed circuit board. 
 
![Y view](images/micro_Yview.png)

- **Observation 1.2.** Redesigns are so devastating for the business that the entire semiconductor industry has committed itself to “first-time-right” design as a guiding principle. To avoid them, VLSI engineers typically spend much more time verifying a circuit than actually designing it.

## Glossary of logic families
- NMOS vs CMOS: 
    - NMOS: static power ( vcc --[ R ]-- uC ) :> I2xR 
    - COMS: connects the vcc directly to the uC pin ( vcc --- uC )

- ECL vs CMOS: ECL is more expensive and does not have any true advantage to CMOS.

- MOS: metal oxide semiconductor
- FET: field effect transistor
- CMOS: Complementary MOS (circuit style or fabrication technology) where pairs of n- and p-channel MOSFETs cooperate in each logic gate; features zero quiescent power dissipation, or almost so; supply voltages have evolved from up to 15 V down to below 1 V.
- TTL: Transistor Transistor Logic, made up of BJTs and passive devices; first logic family to gain widespread acceptance as SSI/MSI parts, has evolved over many generations all of which share a 5 V supply.
- Originally a low-power but slow alternative to TTL, CMOS has become the technology that almost totally dominates VLSI today.
- This is essentially because layout density, operating speed, energy efficiency, and manufacturing costs per function benefit from the geometric down-scaling that comes with every process generation. 
- In addition, the simplicity and comparatively low power dissipation of CMOS circuits have allowed for integration densities not possible on the basis of BJTs.

## Definitions
- Schematic data include information that indicate where and how to draw icons, wires, busses, etc. on a computer screen or on a piece of paper
- Datapath is a generic term for all those subcircuits that
manipulate payload data
-  The controller does so by interpreting various status signals and by piloting datapath operation via control signals in response. A controller is either implemented as a hardwired finite state machine (FSM), as a stored program (program counter plus microcoded instruction sequence), or as a combination of both. 

![Datapath and control](images/micro_data_control.png)

# Chapter 02: Field Programmable Logic
-  pre-manufactured subcircuits get configured into the target circuit via electrically programmable links that can be done — and in many cases also undone — as dictated by so called configuration bits. 

## Configuration technologies
- Static memory :
    - The key element here is an electronic switch — such as a transmission gate, a pass transistor, or a three-state buffer — that gets turned “on” or “off” under control of a configuration bit.
    - Unlimited reprogrammability is obtained from storing the configuration data in static memory (SRAM) cells
    - FPL device must (re-)obtain the entire configuration — the settings of all its programmable links — from outside whenever it is being powered up. The problem is solved in one of three possible ways, namely (a) by reading from a dedicated bit-serial or bit-parallel off-chip ROM, (b) by downloading a bit stream from a host computer, or (c) by long-term battery backup.

- Flash memory: 
    - Flash memories rely on special MOSFETs where a second gate electrode is sandwiched between the transistor’s bulk material underneath and a control gate above
    - Flash FPL devices are non-volatile and immediately live at power up, thereby doing away with the need for any kind of configuration-backup apparatus.  Data retention times vary between 10 and 40 years. Endurance of flash FPL is typically specified with 100 to 1000 configure-erase cycles, which is much less than for flash memory chips.

- Antifuse:
    - programming is permanent.
    - antifuses are only about the size of a contact or via and, therefore, allow for higher densities than reprogrammable links
    - Antifuse-based FPL is also less sensitive to radiation effects, offers superior protection against unauthorized cloning, and does not need to be configured following power-up.

## Organization of HW resources
- SPLD: simple programmable logic devices
- CPLD: Complex programmable logic devices
- PAL: programmable array logic 
image here cpld

- FPGA: field programmable gate array
    - Many configurable logic cells are arranged in a two-dimensional array with bundles of parallel wires in between. 
    - Fine-grained FPGAs: One speaks of a fine-grained architecture when the configurable cells are so simple that they are capable of implementing no more than a few logic gates and/or one bistable.
    - Coarse-grained FPGAs. Here cells are designed to implement combinational functions of four or more variables and are capable of storing two or more bits at a time.

![FPGA types](images/micro_fpga_grained.png)

## Commercial Aspects

![Commercial aspects](images/micro_commercial.png)

## Conclusions
- Field programmable logic is ideal for
    - Prototyping and other
    - Situations where agility is crucial because specifications are subject to change at any time,
    - Products that sell in modest quantities or where time to market is paramount, and for
    - Products that need to be reconfigured from remote.


- (put somewhere): In digital circuit theory, sequential logic is a type of logic circuit whose output depends not only on the present value of its input signals but on the sequence of past inputs, the input history. This is in contrast to combinational logic, whose output is a function of only the present input. That is, sequential logic has state (memory) while combinational logic does not. 
