1.	Client Server Model 
2.	Network Protocols - TCP, UDP, ARP, DNS, HTTP, IP packet 
3.	Storage 
4.	LAtency and Throughput 
5.	Availability 
6.	Caching 
	1. Reading is simple in cache
	2.	Wiriting 
		-	Write-through cache, where the cache and database is updated in one go
		-   Write back cache, where the chache is updated and then the cache is written back into the database. 

	Cache Hit & Misses 

	Use caching if the data is immutable 
	no need for consistancy 

	Eviction policy 
	1.	LRU - Least recently used, remove the LRU data
	2.	LFU  
	3.	LIFO 
	4.	FIFO 
	5.	Random 
7.	Proxy 
	-	Forward Proxy 
		-	Sits in-between the Client and Server, but is in the client's team and will forward all the requests 
			of the client to the server. 
		-	Hides the identity of the Client. 

	-	Reverse Proxy 
		-	Sits in-between the Client and Server, but is in the servers's team and will forward all the requests 
			of the client to the server. 
		-	Hides the identity of the Server, so the client does not see the actual server and thinks the Reverse proxy as the Server. 
		-	Lot's of use cases like load balancing, ssl termination, caching, DDoS Sheild etc ..

8.	Load Balancers 
	-	Balancing or re-routing the requests to different servers. 
	- 	Hardware load balancers and software load balancers 
	-	Round Robin approach for redirection 
	-	Weighted Round Robin approach 
	-	Load based balancing using health and latency of the requests. 
	-	IP based loading balancing using IP hashed. 
	-	Multiple load balancers for balancing the requests. 
9.	Hashing 
	-   We use the hashes to always sends the request to a particular server via the load balancer. 
	-	This allows use to the server caching, and if it was round robin then the chaching miss might be more. 
	-	MD5, SHA1 hashing functions 
	-	Consistent hashing and Rendezvous hashing strategy to mitigate the issue with new servers being added or removed. 

10.	Relational databases 
	- 	Data stored is stored in tables. 
	-	Rows are records and columns are attributes 
	-	Data is defined in schemas 

	-	ACID transcation 
	-	Database index speeds up a certian query to make it faster. WRite might be slower, but read will be faster. 
11. Non-Relational databases 
	-	One of them is Key Value store 

12. Specialized Storage Paradigms
	- 	Blob store, unstructred store for unstructured data - S3, they sort of behave like key value store. Key value store is optimized for different types of data 
	-	Time Series data base - InfluxDB and prometheus - Large ammounts of data for the timeseries. Monitoring and events, mainly used for IoT data. 
	-	Graph database - Neo4j - Data is stored in a graph model, relationship is important and central. like social media etc... 
	-	Spatial database - Locations storage, spatial database - Quadtree data structure can be made as a grid. 

13. Replication and Sharding in Database 
	-	Replications is used if the main database is gone down. 
	-	For this to work the replication need to be always up-to date, so the update should always be done in async and whenever an update fails in replication database then the main database replcation should also fail. 
	-	horizontal scaling is replicating the data in multiple databases. 
	-	Spliting the existing datbase into chunks and storing it in database called sharding. 
	-	With relational databases we split it into different tables and store it in the different database shards
	-	Sharding can create hotspots, where there is an increased usage of one or 2 database. 
	-	Use hashing to avoid the creation of hotspots.
	-	Depending on what type of data we do a sharding and then replication of the shard. 
	

