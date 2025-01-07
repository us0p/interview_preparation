# CAP Theorem - (Consistency, Availability, Partition tolerance)
According to the CAP theorem, any distributed system can only guarantee two
of the three properties at any time. You can't guarantee all three 
properties at once.
In the theorem, partition tolerance is a must. The assumption is that the 
system operates on a distributed data store so the system, by nature, 
operates with network partitions. Network failures will happen, so to offer
any kind of reliable service, partition tolerance is necessary.
Consistency in CAP is different than that of ACID. Consistency in CAP means 
having the most up-to-date information.Also note that availability as 
defined in CAP theorem is different from high availability in software 
architecture.

- Consistency: All clients see the same data at the same time, no matter 
  which node they connect to. For this to happen, whenever data is written 
  to one node, it must be instantly forwarded or replicated to all the 
  other nodes in the system before the write is deemed ‘successful.’
- Availability: Any client making a request for data gets a response, even 
  if one or more nodes are down. Another way to state this — all working 
  nodes in the distributed system return a valid response for any request, 
  without exception.
- Partition tolerance: A partition is a communication break within a 
  distributed system — a lost or temporarily delayed connection between two
  nodes. Partition tolerance means that the cluster must continue to work 
  despite any number of communication breakdowns between nodes in the 
  system.

NoSQL databases are ideal for distributed network applications. Unlike 
their vertically scalable SQL (relational) counterparts, NoSQL databases 
are horizontally scalable and distributed by design—they can rapidly scale 
across a growing network consisting of multiple interconnected nodes.

> The modern CAP goal should be to maximize combinations of consistency and 
availability that make sense for the specific application. Such an approach 
incorporates plans for operation during a partition and for recovery 
afterward.
Eric Brewer - Initial positor of the CAP Theorem.
