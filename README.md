"# Communication-Protocols-Models" 

**Client – Server model of Communication**

The client-server characteristic describes the relationship of cooperating programs in an application. The server component provides a function or service to one or many clients, which initiate requests for such services. Servers are classified by the services they provide. For example, a web server serves web pages and a file server serves computer files. A shared resource may be any of the server computer's software and electronic components, from programs and data to processors and storage devices. The sharing of resources of a server constitutes a service.

Client/server architecture is also known as a networking computing model or client/server network because all the requests and services are delivered over a network.

Whether a computer is a client, a server, or both, is determined by the nature of the application that requires the service functions. For example, a single computer can run web server and file server software at the same time to serve different data to clients making different kinds of requests. Client software can also communicate with server software within the same computer.[2] Communication between servers, such as to synchronize data, is sometimes called inter-server or server-to-server communication.

**Understand HTTP, HTTPS and WebSockets**

* **HTTP**
	
	* HTTP (Hypertext Transfer Protocol) is perhaps the most popular application protocol used in the Internet (or The WEB).HTTP is an asymmetric request-response client-server protocol as illustrated.  An HTTP client sends a request message to an HTTP server.  The server, in turn, returns a response message.  In other words, HTTP is a pull protocol; the client pulls information from the server (instead of server pushes information down to the client).
	
	* HTTP is a stateless protocol. In other words, the current request does not know what has been done in the previous requests.
	
	* HTTP permits negotiating of data type and representation, so as to allow systems to be built independently of the data being transferred.
	
	* The Hypertext Transfer Protocol (HTTP) is an application-level protocol for distributed, collaborative, hypermedia information systems. It is a generic, stateless, protocol which can be used for many tasks beyond its use for hypertext, such as name servers and distributed object management systems, through extension of its request methods, error codes and headers.

	* Whenever you issue a URL from your browser to get a web resource using HTTP, e.g. http://www.nowhere123.com/index.html, the browser turns the URL into a request message and sends it to the HTTP server. The HTTP server interprets the request message, and returns you an appropriate response message, which is either the resource you requested or an error message. This process is illustrated below:

![Alt Text](https://www.tutorialspoint.com/security_testing/images/http_Protocol.jpg)

* **HTTPS**
	
	* HTTP Secure (HTTPS) is an extension of the Hypertext Transfer Protocol (HTTP) for secure communication over a computer network, and is widely used on the Internet. In HTTPS, the communication protocol is encrypted by Transport Layer Security (TLS), or formerly, its predecessor, Secure Sockets Layer (SSL). The protocol is therefore also often referred to as HTTP over TLS,or HTTP over SSL.
	
	* The principal motivation for HTTPS is authentication of the accessed website and protection of the privacy and integrity of the exchanged data while in transit. It protects against man-in-the-middle attacks. The bidirectional encryption of communications between a client and server protects against eavesdropping and tampering of the communication. In practice, this provides a reasonable assurance that one is communicating without interference by attackers with the website that one intended to communicate with, as opposed to an impostor.

![Alt Text](https://geeksided.com/wp-content/blogs.dir/317/files/2014/07/intermediatediagramhttps.jpg)
	
* **WEB SOCKETS**
	
	* WebSocket is a web technology that provides full-duplex communication channels over a single TCP connection. A full-duplex communication is the communication system that allows simultaneous bidirectional communication. A telephone conversation is a good example of full-duplex communication where in both parties can speak and hear at the same time.
	
	* **Why do we need WebSocket?**
		
		* Current web relies on HTTP for communication which is a request-reply protocol. To achieve desktop like (real-time) experience, programmers use techniques like polling, long polling and streaming.
		
		* All of these methods use HTTP protocol to communicate with the server. Every request sent to server over HTTP contains lot of unnecessary header information describing where this request came from, where it’s heading, the user agent information, etc. This information adds a lot of overhead on bandwidth in real-time scenarios.
		
		* Secondly, this is not a full-duplex communication. Which means client and server cannot send and receive message at the same time. 
		
![Alt Text](https://www.pubnub.com/wp-content/uploads/2014/09/WebSockets-Diagram.png)

* **Pub-Sub Model of Communication*
	
	* The publish/subscribe pattern (pub/sub) is an alternative to the traditional client-server model, where a client communicates directly with an endpoint. However, Pub/Sub decouples a client, who is sending a particular message (called publisher) from another client (or more clients), who is receiving the message (called subscriber). This means that the publisher and subscriber don’t know about the existence of one another. There is a third component, called broker, which is known by both the publisher and subscriber, which filters all incoming messages and distributes them accordingly.
	
	* MQTT is a Client Server publish/subscribe messaging transport protocol. It is light weight, open, simple, and designed so as to be easy to implement. These characteristics make it ideal for use in many situations, including constrained environments such as for communication in Machine to Machine (M2M) and Internet of Things (IoT) contexts where a small code footprint is required and/or network bandwidth is at a premium.

![Alt Text](https://www.hivemq.com/wp-content/uploads/Screen-Shot-2014-10-22-at-12.21.07.png)




