# Swarm
Is an advanced feature for managing a cluster of Docker daemons.
Current versions of Docker include Swarm mode for nativerly managing a 
cluster of Docker Engines called a swarm.
Use the Docker CLI to create a swarm, deploy application services to a 
swarm, and manage swarm behavior.

The cluster management and orchestration features embedded in Docker Engine
are built using `swarmkit`. Swarmkit is a separate project which implements
Docker's orchestration layer and is used directly within Docker.

> Docker Swarm mode isn't the same as the Docker Classic Swarm which is no 
  longer actively developed.

A swarm consists of multiple Docker hosts which run in Swarm mode and act 
as managers, to manage membership and delegation, and workers, which run 
swarm services. A given Docker host can be a manager, a worker, or perform 
both roles. When you create a service, you define its optimal state - 
number of replicas, network and storage resources available to it, ports 
the service exposes to the outside world, and more.

A task is a running container which is part of a swarm service and is 
managed by a swarm manager, as opposed to a standalone container.

When Docker is running in Swarm mode, you can still run standalone 
containers on any of the Docker hosts participating in the swarm, as well 
as swarm services.
A key difference between standalone containers and swarm services is that 
only swarm managers can manage a swarm, while standalone containers can be 
started on any daemon. Docker daemons can participate in a swarm as 
managers, workers, or both.

In the same way that you can use Docker Compose to define and run 
containers, you can define and run Swarm service stacks.

## Nodes
A node is an instance of the Docker engine participating in the swarm. You 
can also think of this as a Docker node. You can run one or more nodes on a
single physical computer or cloud server, but production swarm deployments 
typically include Docker nodes distributed across multiple physical cloud 
machines.

To deploy your application to a swarm, you submit a service definition to a
manager node. The manager node dispatches units of work called `tasks` to 
worker nodes.

Manager nodes also perform the orchestration and cluster management 
functions required to maintain the desired state of the swarm. Manager 
nodes select a single leader to conduct orchestration tasks.

Worker nodes receive and execute tasks dispatched from manager nodes. By 
default manager nodes also run services as worker nodes, but you can 
configure them to run manager tasks exclusively and be manager-only nodes. 
An agent runs on each worker node and reports on the tasks assigned to it. 
The worker node notifies the manager node of the current state of its 
assigned tasks so that the manager can maintain the desired state of each 
worker.

## Services and tasks
A service is the definition of the tasks to execute on the manager or 
worker nodes. It's the central structure of the swarm system and the 
primary root of user interaction with the swarm.

When you create a service, you specify which container image to use and 
which commands to execute inside running containers.

In the replicated services model, the swarm manager distributes a specific 
number of replica tasks among the nodes based upon the scale you set in the
desired state.

For global services, the swarm runs one task for the service on every 
available node in the cluster.

A task carries a Docker container and the commands to run inside the 
container. It is the atomic scheduling unit of swarm. Manager nodes assign 
tasks to worker nodes according to the number of replicas set in the 
service scale. Once a task is assigned to a node, it cannot move to another
node. It can only run on the assigned node or fail.

## Load Balancing
The swarm manager uses ingress load balancing to expose the services you 
want to make available externally to the swarm. The swarm manager can 
automatically assign the service a published port or you can configure a 
published port for the service. You can specify any unused port. If you do 
not specify a port, the swarm manager assigns the service a port in the 
30000-32767 range.

External components, such as cloud load balancers, can access the service 
on the published port of any node in the cluster whether or not the node is
currently running the task for the service. All nodes in the swarm route 
ingress connections to a running task instance.

Swarm mode has an internal DNS component that automatically assigns each 
service in the swarm a DNS entry. The swarm manager uses internal load 
balancing to distribute requests among services within the cluster based 
upon the DNS name of the service.

## Features
Cluster management integrated with Docker Engine: Use the Docker Engine CLI
to create a swarm of Docker Engines where you can deploy application 
services. You don't need additional orchestrarion software to create or 
manage a swarm.

Descentralized design: Instead of handling differentiation between node 
roles at deployment time, the Docker Engine handles any specialization at 
runtime.

Declarative service model: Docker Engine uses a declarative approach to let
you define the desired state of the various services in your application 
stack.

Scaling: For each service, you can declare the number of tasks you want to 
run.

Desired state reconciliation: The swarm manager node constantly monitors 
the cluster state and reconciles any differences between the actual state 
and your expressed desired state.

Multi-host networking: You can specify an overlay network for your 
services. The swarm manager automatically assigns addresses to the 
containers on the overlay network when it initializes or updates the 
application.

Service Discovery: Swarm manager nodes assign each service in the swarm a 
unique DNS name and load balance running containers.

Load balancing: You can expose the ports for services to an external load 
balancer. Internally, the swarm lets you specify how to distribute service 
containers between nodes.

Secure by default: Each node in the swarm enforces TLS mutual 
authentication and encryption to secure communications between itself and 
all other nodes.

Rolling updates: At rollout time you can apply service updates to nodes 
incrementally.
