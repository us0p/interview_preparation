aws service offerings
- compute
- storage
- network security
- blockchain
- machine learning
- artificial intelligence
- robot development plaftorms
- video production
- management systems
- obital satellites

ec2 -> virtual servers

pay for what you need, pay only for what you use.

on-premise servers can't be scaled up or down as needed.
on cloud environments you can scale up or down as the stress on your servers varies.

cloud computing is the on-demand delivery of IT resources over the internet
with pay-as-you-go pricing

Deployment models for cloud computing
When selecting a cloud strategy, a company must consider factors such as:
- required cloud application components
- preferred resource management
- tools
- legacy IT infrastructure requirements.

The three cloud computing deployment models are:
- cloud-based: You can build applications on low-level infrastructure that
  requires your IT staff to manage them. Alternatively, you can build them
  using higher-level services that reduce the management, architecting, and
  scaling requirements of the core infrastructure.
- on-premises: Resources are deployged on premises by using virtualization
  and resource management tools.
- hybrid: You might want to use this approach if you have a legacy 
  application that are better maintained on premises or government 
  regulations require your business to keep certain records on premises.

## Cloud benefits
- Trade upfront expense for variable expense: upfront expenses are 
  resources that you would need to investin before using them. Variable 
  expense means you only pay for computing resources you consume.
- Stop spending money to run and maintain data centers: The aggregated 
  cloud usage from a large number of customers results in lower 
  pay-as-you-go prices.
- Stop guessing cpacity: With cloud computing, you don't have to predict 
  how much infrastructure capacity you will need before deploying an 
  application.
- Benefit from massice economies of scale: by using cloud computing, you 
  can achieve a lower variable cost than you can get on your own.
- Increase speed and agility: cloud provides you with more time to 
  experiment and innovate. When computing in data centers, it may take 
  weeks to obtain new resources that you need. By comparison, cloud 
  computing enables you to access new resources within minutes.
- Go global in minutes: The global footpring of the AWS Cloud enables you 
  to deploy applications to customers around the world quickly, while 
  providing them with low latency.

## EC2
Provides secure, resizable compute capacity in the cloud as Amazon EC2 
instances.  
Every application needs raw computing capacity to provide the functionality
the users need.  
When working with cloud, capacity of these servers are virtual, and the 
service you use to gaind access to those servers with virtual capacity is 
the EC2.  
It runs on top of physical host machines manage by aws using virtualization
technology.  
When you spin up an ec2 instance you aren't necessarily taking an entire 
host for yourself.  
Instead, you're sharing the host with multiple other instances otherwise 
known as virtual machines and a hypervisor running on the host machine is 
responsible for sharing the underline physical resources between the
virtual machines.  
This idea of sharing undeline hardware is called `Multitenancy`.
The hypervisor is responsible for coordinating this `Multitenancy` and it's
manage by aws.  
The hypervisor is responsible for isolating the virtual machines from each
other as they share resources from the host.
EC2 instances aren't aware of other instances on the same host.
When you use EC2 you need only to setup the instance with configurations like:
- OS (windows or linux)
- What will run inside the instance
- Network aspects and also what type of request reaches your server or 
  whether they are public or private accessible.
You can scale the number of instances up or down at will.
You can resize your instance or vertical scale it up.

This form of service is also known as Compute as a service or `CaaS`.

## EC2 instances types
Each instance type is grouped under a instance family that are optmized for
certain types of tasks.
Each type offers a variation of:
- cpu
- memory
- storage
- network capacity
You can mix these resources as you need.

EC2 instance families are:
- General purpose: good balance between compute, memory and networking 
  resources, often used for web servers or code repositories.
  Good choice for application in which the resource needs for compute, 
  memory, and networking are rougly equivalent.
- Compute optimized: ideal for compute intense tasks like gaming servers, 
  high performance computing (HPC), scientific modeling.
  Ideal for high performance web servers, compute-intensive applications 
  servers, and dedicated gaming servers. You can also use compute optimized
  instances for batch processing workloads that require processing many 
  transactions in a single group.
- Memory optimized: memory intensive tasks, designed to deliver fast 
  performance for workloads that process large datasets in memory.
  Some examples are, high-performance database or workloads that involves 
  performing real-time processing of a large amount of unstructured data.
- Accelerated computing: often used for floating point number calculations,
  graphics processing, data pattern maching as they use hardware 
  accelerators.
  It uses hardware accelerators, or coprocessors, to perform some functions
  more efficiently than is possible in software running on CPUs.
- Storage optimized: high performance for locally stored data.
  Designed for workloads that require high, sequential read and write 
  access to large datasets on local storage.
  Some workloads suitable for storage optimized instances include 
  distributed file systems, data warehousing applications, and 
  high-frequency online transaction processing (OLTP) systems.

## EC2 prices
**On-demand pricing:** pay for the duration your instance is running for, 
which can be per hour or per second, depending on the instance type and the
OS that you're running. This kind of pricing is good when you're starting a 
new project and want to experience and thes ideas without long term 
commitment.
Another good use is to determine a base line for your average usage.
Ideal for short-term, irregular workloads that cannot be interrupted.
Sample use cases for On-Demand instances include developing and testing 
applications and running applications that have unpredictable usage 
patterns.
It's not recommended for workloads that last a year or longer because these
workloads can experience cost savings using Reserved Instances.

**Reserved Instances:** billing discount applied to the use of On-Demand 
Instances in your account.
There are two available types of Reserved Instances:
- Standard Reserved Instances: good fit if you know the EC2 isntance type 
  and size you need and in which AWS Region you plan to run them.
- Convertible Reserved Instances: If you need to run your EC2 instances in 
  different Availability Zones or different instance types. You trade in a 
  deeper discount when you require flexibility to run your EC2 instances.
At the end of a Reserved Instance term, you can continue using the Amazon 
EC2 instance withour interruption. However, you are charged On-Demand rates
until you do one of the following:
- Terminate the instance.
- Purchase a new Reserved Instance that matches the instance attributes 
  (instance family and size, Regions, platform, and tenancy).
suited for steady-state workloads or ones with 
predictable usage and offer you up to a 75% discount versus On-Demand 
pricing. You qualify for a discount once you commit to a once or three-year
term.

**Savings Plans:** low prices on ec2 usage, in exchange for a commitment to
a consistent amount of usage measured in dollars per hour for a onr or 
three-year term.
This flexible pricing model can therefore provide savings of up to 72% 
compared to On-Demand rates. 
Any usage beyond the commitment is charged ar regular On-Demand rates.
Good option if you need flexibility in your Amazon EC2 usage over the 
duration of the commitment term.
The savings with EC2 instances Savings Plans are similar to the savings 
provided by Standard Reserverd Instances.
Unlike Reserved instances, however, you don't need to specify up front what
EC2 instance type and size, OS, and tenancy to get a discount.
Further, you don't need to commit to a certain number of EC2 instances over
a term. Additionally, sacings plans don't include EC2 capacity reservation 
option.
This can lower prices on your EC2 usage, regardless of instance family, 
size, OS, tenancy, or AWS region.
This also applies to AWS Fargate and AWS Lambda usage, which are serverless
compute options.
You can use AWS Cost Explores to visualize and mange your AWS costs and 
usage over time.
AWS Cost Explores also provides customized recommendations for Savings 
Plans. These recommendations estimate how much you could save on your 
montly Amazon EC2 costs, based on previuos usage and the hourly commitment
amount in a 1-yer or 3-year Savings Plan.

**Spot Instances:** ideal for workloads with flexible start and end times, 
or that can withstand interruptions.
Spot Istances are unused Amazon EC2 computing capacity and offer you cost 
savings at up to 90% of On-Demands prices.
If you make a Spot request and EC2 capacity is available, your Spot 
Instance launches. However, if the capacity is unavailable, the request is
not successful until capacity becomes available. The unavailable capacity 
might delay the launch of your background processing job.
If capacity is no longer available or demand for Spot Instances increases, 
your instance my be interrupted.

**Dedicated Hosts:** physical hosts dedicated for your use for EC2. These 
are usually for meeting certain compliance requirements and nobody else 
will share tenancy of that host.
You can use your existing per-socket, per-core, or per-VM software licenses
to help maintain license compliance.

## Scaling Amazon EC2
Involves beginning with only the resources you need and designing your 
architecture to automatically resopnd to changing demand by scalling out or
in. As a result, you pay  for only the resources you use.

The service that provides this functionality for EC2 instances is Amazon 
EC2 Auto Scalling.
It add or remove EC2 instances in response to changingg application demand.

You can use two approaches:
- **Dynamic Scaling:** responds to changing demand.
- **Predictive Scaling:** automatically schedules the right number of EC2 
  instances based on predicted demand.

To scale faster, you can use dynamic scalling and predictive scaling 
together.

The `size of your Auto Scaling group` set the minimum number of EC2 
instances that launch immediately after you have created the Auto Scaling 
group. This means that at all times, it's also known as `minimum capacity`.
The `desired capacity` set the number of instances, it can be greater than
the `minimum capacity` but if you do not specify ythe desired number of EC2
instances in an Auto Scaling group, the desired capacity defaults to your 
`minimum capacity`.
The `maximum capacity` sets the maximum number of instances to provide.

## Elastic Load Balancing (ELB)
Automatically distributes incoming application traffic across multiple 
resources, such as Amazon EC2 instances.
It acts as a single point of contact for all incoming gweb traffic to your 
Auto Scaling group.
This means that as you add or remove EC2 instances, these requests route to
the load balancer first.
Them the requests spread across multiple resources that will handle them.
Elast Load Balancing is a regional construct, this means that is runs at 
the Region level rather than on individual EC2 instances, the service is 
automatically highly available with no additional effort on your part.
ELB is automatically scalable. As your traffic grows, ELB is designed to 
handle the additional throughput with no change to the hourly cost.

ELB and EC2 Auto Scaling are separate services that work together to 
provide high performance and availability.

## Amazon Simple Notification Service (SNS)
Is a publish/subscribe service. Using SNS topics, a publisher publishes 
messages to subscribers.
In SNS, subscribers can be web servers, email addresses, Lambda functions, 
or several other options.

## Amazon Simple Queue Service (SQS)
Is a message queuing service. Using SQS, you can send, store, and receive 
messages between software components, without losing messages or requiring
other services to be available. In SQS, an application sends messages into
a queue. A user or service retrieves a messae from the queue, processes it,
and then deletes it from the queue.

## Serverless computing
Serverless means that your code runs on servers, but you do not need to 
provision or manage theses servers.
With serverless computin, you can focus more on innovating new products and
features instead of maintaining servers.
Another benefit of serverless computing is the flexibility to scale 
serverless applications automatically. Serverless computing can adjust the 
aplications' capacity by modifying the units of consumptions, such as 
throughput and memory.

## AWS Lambda
Is a service that lets you run code without needin to provision or manage 
servers.
While using Lambda, you pay only for the compute time that you consume. 
Charges apply onlyy when your code is running.
You set your code to trigger from an event source, such as AWS services, 
mobile applications, or HTTP endpoints.

## Containers
Containers provide you with a standard way to package your application's 
code and dependencies into a single object. You can also use containers for
processes and workflows in which there are essential requirements for 
security, reliability, and scalability.
When running containerized applications, it’s important to consider 
scalability. Suppose that instead of a single host with multiple 
containers, you have to manage tens of hosts with hundreds of containers. 
Alternatively, you have to manage possibly hundreds of hosts with thousands
of containers. At a large scale, imagine how much time it might take for 
you to monitor memory usage, security, logging, and so on.

## Amazon Elastic Container Service (ECS)
Is a highlyyy scalable, high-performance container management system that 
enables you to run and scale containerized applications on AWS.
ECS supports Docker containers.
AWS supports the use of open-source Docker Community Edition and 
subscription-based Docker Enterprise Edition.
With ECS you can use API calls to launch and stop Docker-enabled 
applications.

## Amazon Elastic Kubernetes Service (EKS)
Fully managed service that you can use to run Kubernetes on AWS.

## AWS Fargate
Serverless compute engine for containers. Works with both ECS and EKS.
When usin Fargate, you do not need to provision or manage servers. Fargate 
manages your server infrastructure for you.
You pay only for the resources that are required to run your containers.
