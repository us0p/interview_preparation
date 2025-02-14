# Clean Architecture
- POJO - Plain Old Java/JavaScript Object
  - Is a simple object that doesn't adhere to any specific framework or 
    requirement.
  - It typically represents and encapsulates data.
  - No need to implement interfaces or extend classes.
  - Can be used in any layer as it's simply a data structure.
  - may contain business logic but better to keep as simple as possible.
  - can be defined in any layer as it's just a data container but it's 
    better to define it in the domain layer to enable a simple data 
    structure as communication amongst the application.
  - DTO - Data Transfer Object
  - are often immutable.
  - should be used when you have a significant mismatch between the model 
    in your presentation layer and the underlaing domain.
  - the whole purpose is to shift data in expensive remote calls.
  - using it for more than network communication can lead to conversions 
    from DTO to Domain objects and back can which increases complexity.
  - An object that carries data between processes.
  - Useful when you want to transfer data across different layers of an 
    application or over the network.
  - It doesn't include business logic, but it can include some methods to 
    format data.
  - Can contain serialization and deserialization mechanisms for 
    transfering data over the wire.
  - Often requires conversion from and to POJOs or entities, which can be a
    costly process.
  - Usually used between layers.
  - most commonly used in the services layer (?) in a N-tier application to 
    transfer data between itself and the UI layer, the service layer must 
    control what data leaves the application layer.
  - some DTOs belong in the interface adapters layer when they are specific
    to UI representation, Framework, external services, or if the response 
    format is differente from the use case (e.g. must be snake_case instead
    of camelCase).
- DAO - Data Access Object
  - Provides an abstract interface for accessing data from a persistent 
    storage mechanism like a database.
  - It encapsulates data access logic.
- DAO x Repository
  - DAO is an abstraction of data persistance.
  - Repository is an abstraction of a collection of objects it has a narrower interface.
  - A Repository can be implemented using a DAO but a DAO shouldn't be 
    implemented by using a Repository.
  - a method like Update is appropriate on a DAO, but not in a Repository.
  - DAO doesn't restrict you to store data of the same type, thus you can 
    easily have a DAO that deals with related objects.
  - Repositories handle only one type of objects.
- ad-hoc

- Using POJOS creates the need to convert entities to POJOs which can 
  increase complexity but it allows for clearer contracts.

- DTO belongs to the interface and adpters interface as they are 
  used in the communication between layers.
- the difference between DTOs and plain objecst are:
    - intent, responsibility, and maintainability.
    - Plain Object (POJO)
        - purpose: temporary structure to hold data
        - layer: generated withing the Domain or Use Case Layer.
        - Dependency: No external dependencies (avoid cross-layer 
          dependencies)
        - Behavior: Usually has no additional logic
        - Reusability: typically ad-hoc and specific to the use 
          case.
        - Maintainability: can be easiliy modified within the use 
          case.
    - Data Transfer Object (DTO)
        - purpose: Defined explicitly for data transfer between 
          layers.
        - layer: belongs to the presenter/interface layer.
        - Dependency: Might be used with libraries like 
          serialization tools.
        - Behavior: may contain formatting, transformation, 
          serialization.
        - Reusability: explicitly structure to match API contracts 
          or external systems.
        - Maintainability: acts as a stable contract, ensuring API 
          consistency.
- DTO can control how data is exposed, if API response formats 
  change, we only modify the DTO without affecting the domain 
  logic.
- comon folder structure
  - Domain
    - Entities
    - Exceptions
    - Repositories (interfaces)
    - ?POJOs
  - Application
    - Interfaces
    - UseCases
        - Entity1
            - ...usecases
        - Entity2
            - ...usecases
    - ?DTOs
  - Adapters
    - Controllers
    - Middlewares
    - ViewModels
    - ?DTOs
  - Drivers
    - Databases
        - Repositories (impl)
    - Web APIs
- common design patterns
    - repository

## TLDR
**Goal:**
- Separation of concerns by dividing software into layers.

**Produce systems that are:**
- Independent of any external agency
- Testable

!["clean architecture diagram"](https://blog.cleancoder.com/uncle-bob/images/2012-08-13-the-clean-architecture/CleanArchitecture.jpg)

**Commonly splited around four areas of software:**
1. Entities - Enterprise Business Rules
   Represent the business/domain objects that are manipulated by the use 
   cases. Entities are the most stable part of the architecture.
   - Model domain objects in a data strorage agnostic way.
   - Perform validation to ensure that the object isn't in a invalid state.
   - Validation is usually made in the constructor and throwing an error if
     the provided state is invalid, this create less responsibility on the 
     developer to remember to call validation methods.
   - Objects contain behaviours that are common to all use cases across the
     system.
2. Use cases (Interactor, Commands, Service Layer) - Application Business Rules
   Represent application business rules that are are specific to the 
   application and not the enterprise. It represents the various ways that 
   the system can be used.
   - Perform validation on data to ensure the data is valid for the given 
     use case.
   - a use case must be a class with only one method?
     - It's not a rule rather a recommendation.
     - naming is more objective and less generic.
     - if the use case don't focus on one task usually end up being a wrapper 
       of the repository.
     - In a big code base the developer must find the right method in the use 
       case.
     - it's common for use cases to only wrap a respository function.
3. Interface Adapters - Controllers, Gateways, Presenters
   Responsible for converting data between the outside world and the use 
   case layer.
   - Controllers handle user input, they select the appropriate use case to
     execute based on the user input by extracting the input data. It only 
     delegates to the use case without validating.
     - controllers shoudld be focused on request handling.
   - Gateways are responsible for accessing external data sources, shuch as
     databases or web services.
     - It's an adapter between a data source and a particular 
       domain object (Repository).
     - Repositories are defined in the domain layer and implemented in the 
       framework and drivers layer. Some implementation allows repositories to 
       return entities if strictly used inside use cases to avoid conversion 
       between POJOs and Entities.

   - Presenters are responsible for rendering data in the user interface.
     - responsible for formatting the output from the Use Case into a 
       structure suitable for the delivery mechanism (Controller or View).
     - ensure consistent response structure.
     - usually sits between use case return value and controller return data, 
       it transforms raw data into a response-friendly format.
     - adapts the data returned from the use case for the designed output.
     - good to use when multiple delivery mechanisms need the same data 
       format.
4. Frameworks and Drivers - DB, Devices, Web, UI, External Interfaces
   Represents interfaces that the system has with the outside world. 
   Responsible for translating data between application and external 
   systems.

**Dependency rule:**
- Source code dependencies always point inwards.
- The outermost circle is low level concrete details.
- The inner most circle is the most general.
- Nothing in an inner circle can know anything at all about something in an
  outer circle. 
- The name of something declared in an outer circle must not be mentioned 
  by the code in an inner circle.
- Data formats used in an outer circle should not be used by an inner 
  circle
- Inner circles are policies, they define interfaces which must be 
  implemented by outer circles.

**Flow of data:**
Data that crosses the boundaries are simple data structures. 
You can use basic structs, simple DTO's, or simply arguments in function 
calls. The important thing is that isolated, simple, data structures are 
passed across the boundaries. Don’t pass Entities or Database rows.
  
---
  
## Getting deeper
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
