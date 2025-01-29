# Clean Architecture
It's a mix of ideas regarding the architecture of software. It's built 
upon:
- Hexagonal Architecture
- Onion Architecture
- Screaming Architecture
- DCI
- BCE

Though these architectures all vary somewhat in their details, they are 
very similar. They all have the same objective, which is the separation of 
concerns. They all achieve this separation by dividing the software into 
layers.

Each of these architectures produce systems that are:
- Independent of Frameworks: The architecture does not depend on the 
  existence of some library. This allows you to use such frameworks as 
  tools, rather than having to cram your system into their limited 
  constraints.
- Testable: The business rules can be tested without the UI, Database, Web 
  Server, or any other external element.
- Independent of UI: The UI can change easily, without changing the rest of
  the system.
- Independent of Database: Your business rules are not bound to the 
  database.
- Independent of any external agency: In fact your business rules simply 
  don’t know anything at all about the outside world.

!["clean architecture diagram"](https://blog.cleancoder.com/uncle-bob/images/2012-08-13-the-clean-architecture/CleanArchitecture.jpg)

Note that there's no rule that says you must always have just these four 
circles. However the **dependency rule** always applies. Source code 
dependencies always point inwards. As you move inwards the level of 
abstraction increases. The outermost circle is low level concrete detail. 
As you move inwards the software grows more abstract, and encapsulates 
higher level policies. The inner most circle is the most gerenal.

## The Dependency Rule
The concentric circles represent different areas of software. In general, 
the further in you go, the higher level the software becomes. The outer 
circles are mechanisms. The inner circles are policies.
This rule says that source code dependencies can only point inwards. 
Nothing in an inner circle can know anything at all about something in an 
outer circle.

In particular, the name of something declared in an outer circle must not 
be mentioned by the code in the an inner circle. That includes, functions, 
classes. variables, or any other named software entity.

By the same token, data formats used in an outer circle should not be used 
by an inner circle, especially if those formats are generate by a framework
in an outer circle.

## Entities - Enterprise Business Rules
Entities encapsulate Enterprise wide business rules. An entity can be used 
by many different applications in the enterprise.
They encapsulate the most general and high-level rules. They are the least 
likely to change when something external changes.
They are designed to evolve with the business logic.

They are, high-level business objects or domain objects which represent the
core application logic, regardless of how or where it's used.
For example, in an e-commerce application, entities could be `Order`, 
`Product`, or `User`.

They encapsulates business rules and policies, validation logic and 
behaviours specific to the domain. They enable reuse of the core business 
logic across different applications or systems.
They are often simple objects that contain properties and methods 
representing the business logic.

## Use Cases - Application Business Rules
The software in this layer contains application specific business rules. It
encapsulates and implements all of the use cases of the system. These use 
cases orchestrate the flow of data to and from the entities, and direct 
those entities to use their enterprise wide business rules to achieve the 
goals of the use case.

It's expected that changes to the operation of the application will affect 
the use-cases and therefore the software in this layer. If the details of a
use-case change, then some code in this layer will certainly be affected.

They define and implement specific actions or workflows that the 
application can perform.
Coordinate interactions between entities, data sources, and external 
systems.

Some responsibilities of use cases are:
- Interact with entities to call methods to enforce business rules.
- Define workflows to combine and sequence operations to accomplish 
  specific tasks.
- Prepare data for external layers to transform or structure data for 
  output, often using DTOs.
- Each use case handles one specific workflow or action.

For example, an user login use case, uses the `User` entity to validade 
username and password, then aplies the use case business rule and generates
a JWT and returns the token or an error message.

## Controllers, Gateways, Presenters - Interface Adapters
The software in this layer is a set of adapters that convert data from the 
format most convenient for the use cases and entities, to the format most 
convenient for some external agency such as the Database or the Web.
The Presenters, Views, and Controllers all belong in here. The models are 
likely just data structures that are passed from the controllers to the use
cases, and then back from the use cases to the presenters and views.
Also in this layer is any other adapter necessary to convert data from some
external form, such as an external service, to the internal form used by 
the use cases and entities.

## DB, Devices, Web, UI, External Interfaces - Frameworks and Drivers
The outermost layer is generally composed of frameworks and tools such as 
the Database, the Web Framework, etc. Generally you don’t write much code 
in this layer other than glue code that communicates to the next circle 
inwards.

## Crossing Boundaries
The communication and relation between boundaries is achieved by the use of
**dependency inversion** as an inner circle can know nothing about an outer
circle, an interface is created in the innermost circle and implemented in 
the outhermost circle.

## What data crosses the boundaries
Typically the data that crosses the boundaries is simple data structures. 
You can use basic structs or simple DTO's if you like. Or the data can 
simply be arguments in function calls. The important thing is that 
isolated, simple, data structures are passed across the boundaries. We 
don’t want to cheat and pass Entities or Database rows.

For example, many database frameworks return a convenient data format in 
response to a query. We might call this a RowStructure. We don’t want to 
pass that row structure inwards across a boundary. That would violate The 
Dependency Rule because it would force an inner circle to know something 
about an outer circle.

## Common used patterns
- Repository
- CQRS
- Unity of work
- Mediator
- Result
- Dependency Injection
- Inversion of Control
- OOP -> Dependency Inversion

## Entity x Model
Entity represents the core business logic and data for a domain object 
(note the relation with DDD), residing in the domain layer.

Model is a data structure that represents data in a specific format for 
presentation or sorage, often adapting the entity data to suit external 
needs like the UI or database, and typically located in the data access 
layer.

Essentially, an entity is the "pure" business concept, while a model is a 
tailored representation of that concept for a specific context.
