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

# Operation

I/O data can be thought of as data formatted in outbound buffers for use on Remote Terminals and processed data received in the inbound buffers for use on the GSP Applications. 

The outbound data encodes read and write requests to the RT devices, and the inbound data contains responses for those requests. 

I/O requests are scheduled and sent out on a subcycle basis, and can be scheduled up to one major cycle in advance 

At the beginning of each subcycle, I/O sends out the I/O requests scheduled for that subcycle and processes all available I/O responses, which are fed back in First In First Out (FIFO) fashion.  I/O maintains separate I/O buffers for outbound requests for all sixteen subcycles, which are populated when Applications create and schedule requests.

![I/O Data Flow](io_data_flow.png)

# Bus Adapter Interface
Bus Adapter is the gateway between the Rad750 GSP and RT devices. The Bus Adapter is responsible for driving the MBUS Controller and the 1553 hardware. I/O communicates with the Bus Adapter via a PCI memory mapped interface.

Every sub-cycle, I/O initializes a series of descriptors that inform the Bus Adapter about all pending outbound data. I/O signals the Bus Adapter via an interrupt that there is new I/O data ready to be sent out. 

The Bus Adapter then pulls all of this data into its local memory and sends it out on the appropriate bus (MBUS or 1553). As the data is sent out on the buses, and responses are received, the Bus Adapter updates a series of inbound descriptors that let I/O know how much new data is ready to be processed.

Every sub-cycle, I/O will pull all of the available inbound data into its local memory and will process it as it arrives, passing the results back to the Applications.

Applications interact with I/O via a Job interface. A Job consists of one or more Transactions targeted to a specific RT device. A Transaction refers to any atomic interaction with an RT, but can simply be thought of as a read or write operation. 

# Application Interface Overview
An Application can perform the following functions on a Job:
1.	Create and Schedule a Job
2.	De-schedule a Job.
3.	Disable a Job.
4.	Enable a Job.
5.	Enable a Job Once.
6.	Get Status of a Job.





