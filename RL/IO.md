The I/O Subsystem is responsible for providing the interface between Applications on the GSP and Remote Terminal (RT) devices such as Star Trackers.
These RT devices are either on a high-speed serial bus (RS-485) or a 1553 bus. 

A RS-485 bus, also referred to as MBUS, has three types of MBUS RTs:
1.	Generic MBUS RT devices. 
- These are Telemetry Encoders, Command Decoders, and CCLs.
2.	IOBIC devices. 
- These are all of the ACE trays.
3.	Router devices. 
- Supported devices that can be accessed through a Router are SIAs, M500s, and SySIIs.

Examples of devices that communicate on the 1553 bus:
1.	Star trackers 
2.	Inter Processor communication (See  Inter-Processor Communication for details).

I/O interfaces with the Bus Adapter over a compact PCI bus. The Bus Adapter provides the gateway to the MBUS and 1553 channels. The baseline architecture supports four MBUS channels and one 1553 channel. Each MBUS channel provides four individual buses, whereas the 1553 channel has two distinct buses. 

![I/O Architecture](IO_arch.png)

