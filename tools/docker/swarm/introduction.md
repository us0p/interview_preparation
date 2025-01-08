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

## Wiring up swarm nodes
If you want to deploy more than one node, they need to be accessible by 
network.
The IP address of the manager node must be assigned to a network interface 
available to the host operating system in the manager node. All nodes in 
the swarm need to connect to the manager at the IP address.

Because other nodes contact the manager node on its IP address, you should 
use a fixed IP address.

The following ports must be available. On some systems, these ports are 
open by default.
- Port `2377` TCP for communication with and between manager nodes
- Port `7946` TCP/UDP for overlay network node discovery
- Port `4789` UDP (configurable) for overlay network traffic. Also known as
  VXLAN port.

Port 4789 is the default value for the Swarm data path port. It is 
important to prevent any untrusted traffic from reaching this port, as 
VXLAN does not provide authentication. This port should only be opened to a
trusted network, and never at a perimeter firewall.

To add services to the swarm, the service image needs to be available at a 
public or private repository, it's not possible to use local images.

Once you have deployed a service to a swarm, you are ready to use the 
Docker CLI to scale the number of containers in the service. Containers 
running in a service are called tasks.

You configure the rolling update policy at service deployment time.
By default, when an update to an individual task returns a state of 
RUNNING, the scheduler schedules another task to update until all tasks are
updated. If at any time during an update a task returns FAILED, the 
scheduler pauses the update.
The scheduler applies rolling updates as follows by default:
- Stop the first task.
- Schedule update for the stopped task.
- Start the container for the updated task.
- If the update to a task returns RUNNING, wait for the specified delay 
  period then start the next task.
- If, at any time during the update, a task returns FAILED, pause the 
  update.

## Node availability
- Active: Swarm manager can assign tasks to any `Active` node.
- Drain: Prevents a node from receiving new tasks from the swarm manager. 
  It also means the manager stops tasks running on the node and launches 
  replica tasks on a node with `Active` availability.
  A node's status, including Drain, only affects the node's ability to 
  schedule swarm service workloads.
  Setting a node to `Drain` does not remove standalone containers from that
  node.

Swarm manager nodes use the Raft Consensus Algorithm to manage the swarm 
state. 
There is no limit on the number of manager nodes. The decision about how 
many manager nodes to implement is a trade-off between performance and 
fault-tolerance. Adding manager nodes to a swarm makes the swarm more 
fault-tolerant. However, additional manager nodes reduce write performance 
because more nodes must acknowledge proposals to update the swarm state.
Raft requires a majority of managers, also called the quorum, to agree on 
proposed updates to the swarm, such as node additions or removals. 
Membership operations are subject to the same constraints as state 
replication.
If the swarm loses the quorum of managers, the swarm cannot perform 
management tasks. If your swarm has multiple managers, always have more 
than two. To maintain quorum, a majority of managers must be available. An 
odd number of managers is recommended, because the next even number does 
not make the quorum easier to keep. For instance, whether you have 3 or 4 
managers, you can still only lose 1 manager and maintain the quorum. If you
have 5 or 6 managers, you can still only lose two.
Even if a swarm loses the quorum of managers, swarm tasks on existing 
worker nodes continue to run. However, swarm nodes cannot be added, 
updated, or removed, and new or existing tasks cannot be started, stopped, 
moved, or updated.
Because manager nodes are meant to be a stable component of the 
infrastructure, you should use a fixed IP address for the advertise address
to prevent the swarm from becoming unstable on machine reboot.

If the whole swarm restarts and every manager node subsequently gets a new 
IP address, there is no way for any node to contact an existing manager. 
Therefore the swarm is hung while nodes try to contact one another at their
old IP addresses.

Dynamic IP addresses are OK for worker nodes.

Distribute manager nodes

In addition to maintaining an odd number of manager nodes, pay attention to
datacenter topology when placing managers. For optimal fault-tolerance, 
distribute manager nodes across a minimum of 3 availability-zones to 
support failures of an entire set of machines or common maintenance 
scenarios.

Run manager-only nodes
By default manager nodes also act as a worker nodes. This means the 
scheduler can assign tasks to a manager node. For small and non-critical 
swarms assigning tasks to managers is relatively low-risk as long as you 
schedule services using resource constraints for cpu and memory.

However, because manager nodes use the Raft consensus algorithm to 
replicate data in a consistent way, they are sensitive to resource 
starvation. You should isolate managers in your swarm from processes that 
might block swarm operations like swarm heartbeat or leader elections.
To avoid interference with manager node operation, you can drain manager 
nodes to make them unavailable as worker nodes

An unreachable health status means that this particular manager node is 
unreachable from other manager nodes. In this case you need to take action 
to restore the unreachable manager:
- Restart the daemon and see if the manager comes back as reachable.
- Reboot the machine.
- If neither restarting nor rebooting works, you should add another manager
  node or promote a worker to be a manager node. You also need to cleanly 
  remove the failed node entry from the manager set with docker node demote
  <NODE> and docker node rm <id-node>.

You should never restart a manager node by copying the raft directory from 
another node. The data directory is unique to a node ID. A node can only 
use a node ID once to join the swarm. The node ID space should be globally 
unique.

## Deploy a stack to a swarm
You can deploy a complete application stack to the swarm. The stack 
description is in the form of a Compose file.

> The `docker stack deploy` command uses the legacy compose file version 3 
format, used by Compose V1.

["Compose file version 3 format"](https://github.com/docker/compose/tree/v1/docs)

Keep in mind that all `docker stack` and `docker service` commands must be 
run from a manager node.

create the stack with `docker stack deploy`

## Services
Swarm services use a declarative model, which means that you define the 
desired state of the service, and rely upon Docker to maintain this state. 
The state includes information such as (but not limited to):
- The image name and tag the service containers should run
- How many containers participate in the service
- Whether any ports are exposed to clients outside the swarm
- Whether the service should start automatically when Docker starts
- The specific behavior that happens when the service is restarted (such as
  whether a rolling restart is used)
- Characteristics of the nodes where the servi

To create a single-replica service with no extra configuration, you only 
need to supply the image name.

Created services do not always run right away. A service can be in a 
pending state if its image is unavailable, if no node meets the 
requirements you configure for the service, or for other reasons.

When you update a service, Docker stops its containers and restarts them 
with the new configuration.

When you create a service, the image's tag is resolved to the specific 
digest the tag points to at the time of service creation. Worker nodes for 
that service use that specific digest forever unless the service is 
explicitly updated. This feature is particularly important if you do use 
often-changing tags such as latest, because it ensures that all service 
tasks use the same version of the image.
Note that if a service is created with a diferent version in `latest`, 
you'll have services tasks running different versions.
If the manager can't resolve the tag to a digest, each worker node is 
responsible for resolving the tag to a digest, and different nodes may use 
different versions of the image. If this happens, a warning like the 
following is logged

```bash
unable to pin image <IMAGE-NAME> to digest: <REASON>
```

After you create a service, its image is never updated unless you 
explicitly run docker service update with the `--image` flag as described 
below. Other update operations such as scaling the service, adding or 
removing networks or volumes, renaming the service, or any other type of 
update operation do not update the service's image.

## Publish ports
When you create a swarm service, you can publish that service's ports to 
hosts outside the swarm in two ways:
- You can rely on the routing mesh. When you publish a service port, the 
  swarm makes the service accessible at the target port on every node, 
  regardless of whether there is a task for the service running on that 
  node or not. This is less complex and is the right choice for many types 
  of services.
- You can publish a service task's port directly on the swarm node where 
  that service is running. This bypasses the routing mesh and provides the 
  maximum flexibility, including the ability for you to develop your own 
  routing framework. However, you are responsible for keeping track of 
  where each task is running and routing requests to the tasks, and 
  load-balancing across the nodes.

## Connect the service to an overlay network
You can use overlay networks to connect one or more services within the 
swarm.
After you create an overlay network in swarm mode, all manager nodes have 
access to the network.
You can create a new service and pass the `--network` flag to attach the 
service to the overlay network.
The swarm extends the overlay network to each node running the service.

## Control service placement
Swarm services provide a few different ways for you to control scale and 
placement of services on different nodes.
- You can specify whether the service needs to run a specific number of 
  replicas or should run globally on every worker node. See Replicated or 
  global services.
- You can configure the service's CPU or memory requirements, and the 
  service only runs on nodes which can meet those requirements.
- Placement constraints let you configure the service to run only on nodes 
  with specific (arbitrary) metadata set, and cause the deployment to fail 
  if appropriate nodes do not exist. For instance, you can specify that 
  your service should only run on nodes where an arbitrary label 
  pci_compliant is set to true.
- Placement preferences let you apply an arbitrary label with a range of 
  values to each node, and spread your service's tasks across those nodes 
  using an algorithm. Currently, the only supported algorithm is spread, 
  which tries to place them evenly.

## Replicated or global services
Swarm mode has two types of services: replicated and global. For replicated
services, you specify the number of replica tasks for the swarm manager to 
schedule onto available nodes. For global services, the scheduler places 
one task on each available node that meets the service's placement 
constraints and resource requirements.
You control the type of service using the `--mode` flag. If you don't 
specify a mode, the service defaults to replicated.

## Automatically roll back if an update fails
You can configure a service in such a way that if an update to the service 
causes redeployment to fail, the service can automatically roll back to the
previous configuration. This helps protect service availability.

## Give a service access to volumes or bind mounts
For best performance and portability, you should avoid writing important 
data directly into a container's writable layer. You should instead use 
data volumes or bind mounts. This principle also applies to services. 

## Data volumes
Volumes can be created before deploying a service, or if they don't exist 
on a particular host when a task is scheduled there, they are created 
automatically according to the volume specification on the service.

## Bind mounts
The file system path must exist before the swarm initializes the container 
for the task.
Bind mounts can be useful but they can also cause problems. In most cases, 
it is recommended that you architect your application such that mounting 
paths from the host is unnecessary. The main risks include the following:
- If you bind mount a host path into your service’s containers, the path 
  must exist on every swarm node.
- The Docker swarm mode scheduler may reschedule your running service 
  containers at any time if they become unhealthy or unreachable.
- Host bind mounts are non-portable. When you use bind mounts, there is no 
  guarantee that your application runs the same way in development as it 
  does in production.

## Nodes
A swarm consists of one or more nodes: physical or virtual machines running
Docker Engine.
There are two types of nodes: managers and workers.

!["manager vs worker nodes"](https://docs.docker.com/engine/swarm/images/swarm-diagram.webp)

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
