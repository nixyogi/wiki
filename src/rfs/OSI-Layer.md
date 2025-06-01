## OSI Model 

1.  Application - Consists of Application Protocols that form the basis of Web services, like HTTP, FTP, etc..
2.  Presentation - Does Translation (converting Protocols into data bits) --> Compression --> Encryption (SSL/TLS) 
3.  Session - Manages a session (a connection) and does Authorization and Authentication. 
4.  Transport - Controls the reliability of the communication, Does Segmentation, flow control and error control. For eg: TCP/UDP. Data here is divided into segments
5.  Network - Logical Addressing, Routing and Path determination. Segments here are encapuslated into Packets. 
6.  Data Link - Packets here are encapsulated into frames which adds the MAC of sender and receiver. It does framing and Media Access control and Error Detection. 
7.  Physical - Responsible for transmitting the frames to different computers. This is where the frames are converted to signals and sent over a physical medium. 

