## Todo
- [x] Create a list of concepts to review every morning.
- [x] Create Morning routine that need to be executed every day.
- [x] Change experiences from backend to fullstack in linkedin.
- [x] Change linkedin cover.
- [ ] Search techniques to read and solve problems faster.

- [ ] Event Loop
- [ ] AJAX
- [ ] modules
- [ ] CommonJS
- [ ] ESM
- [ ] global object Node.js
- [ ] process.nextTick()
- [ ] setImmediate()
- [ ] Event Emitters
- [ ] npx
- [ ] Node.js Strams
- [ ] Node.js child_process
- [ ] Node.js Cluters
- [ ] JS and Node.js Memory Leaks

## Routine - 12h
25m english
1h interview preparation
    - Common Node.js interview question and answers
    - Common Web interview question and answers
    - Common AWS lambda interview question and answer
    - Common React interview question and answers
    - Common JavaScript interview question and answers
1h LeetCode - DSA, white board and interview preparation
Core concepts 5h:
    - DSA
    - Tests and Testing strategies
    - OOP
    - SOLID
    - Design Patterns
    - Clean Architecture
        - use cases should only receive expected data, validation and
          data conversion should be done in the controller (presenter) 
          layer, with data, use cases shouldn't receive entities directly, 
          but it can convert a DTO to an entity if it needs to handle 
          domain logic.
        - DTO belongs to the interface and adpters interface as they are 
          used in the communication between layers.
        - use cases and entities cannot refer to DTO because of the 
          dependency rule.
        - because of that DTOs must be instantiated in the Controller and 
          passed to the use cases.
        - if entities and use cases should return plain data structures 
          (e.g. plain objects).
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
        - Repositories shouldn't return entities, that would couple the 
          framework and drivers layer with the domain layer.
        - You should always use plain objects as communication between 
          layers and use objects in the presentation layers (e.g. DTO) to 
          convert data from the form most convenient for entities and use 
          cases in the form most convenient for the persistence framework 
          being used.
        - the downside is that you always need to convert between different
          contracts, but the big win is that you got a clear contracs.
        - DTO
        - POJO
        - ad-hoc
        - comon folder structure
        - common design patterns -> Design patterns
            - repository
    - JavaScript
    - TypeScript
    - Node.js
    - Backend: overall backend knowledge
    - Microservices Architecture
    - Nest.js
    - Docker
    - Kafka
    - Cloud: lambda, sns, sqs, s3, API Gateway
    - MongoDB
    - Redis
    - PostgreSQL
4h 40m exams


Advent of Code - problem solving, language practice
- YouTube
    - Video Editing
    - Image Editing
- SaaS
    - Figma
    - Marketing
- freelas
    - upwork
    - freelancer
    - 99freelas

## University study plan
The exam will have 3h of duration.
I'm estimating 30 minutes for the essay and 150 minutes for the 46 
questions.
This leaves and average of 3 minutes per question.

The study plan will follow the calendar provided by Hexag, having 24 
lessons per week, with 5 blocks per day, in which
- 5 blocks for lessons

Each block of work is 44 minutes long and it's followed by a block of rest 
of 6 minutes.

30 minutes to read required books.

during the saturday and sunday you should do a block of 3 hours and 30 
minutes focused only in exercises of the lessons of the past week.

## Points of attention
- What causes delays during the activities to cause them to finish after 
  the estimated time?

## Pomodoro timers
- **3h:** 45m/w + 10m/sr + 25m/lr -> 75% work rate
- **1h 30m:** 25m/w + 5m/sr + 5m/lr -> 83% work rate
- **1h:** 50m/w + 10m/lr -> 83% work rate
- **2h:** 30m/w + 5m/r + 20m/lr -> 75% work rate
- **30m:** 25m/2 + 5m/r -> 83% work rate

## Study
Studying is divided in two parts:
- Study (gather new concepts and ideas)
- Review (revisit and further knoledge already studied)

Should take notes only about concepts, patterns and principles.
Should not take notes about the functionality or details about tools and 
technologies, the understanding of these things should be from practical 
experience, taking notes about it won't help as you won't remember all the 
details you noted about all the tools, and when you need to remember or 
learn some detail you'll probably go to the tool documentation anyway.
You should maintain a list of the most required technologies in the market 
and try to be familiar with most of them by using them in side projects and
keep up to date with them.

1. According to recruiters i'm lacking practical experience, so i must 
   create more projects around what people are looking in a developer.
2. Those projects should be around the stack that i want to work with.
3. The vast majority of the opportunities look for a developer which 
   understand:
   - unit and integration tests
   - microservices architecture
   - cloud services (specialy lambda)
  
**Concepts to study**
**My stack**
- Docker
- Kafka
- Cloud computing: overall cloud understanding
    - lambda
    - sns
    - sqs
    - s3
    - API Gateway
- JavaScript.
    - Typescript.
    - Node.js.
    - Swagger
    - Nest.js
    - Jest
- MongoDB.
- Redis.
- PostgreSQL
    - pg_isready

- DSA
- Clean Architecture
- SOLID
- OOP
- Microservices
- DDD
- Backend: overall backend knowledge
- Tests and Testing strategies
- Design Patterns

--- Work ready ---
- Event Programming patterns
- Hexagonal Architecture
- Onion Architecture
- Screaming Architecture
- DCI Architecture
- BCE Architecture
- Architecture principles
- Data-Oriented Design
- Entity-Components-System
- MVVM
- MVC
- Extreme programming

- Terraform
- Grafana
- Kubernetes
- Jenkins (CI/CD pipeline configuration)

## Courses
- [MIT Distributed Systems](https://pdos.csail.mit.edu/6.824/)
- [Papers on distributed systems](https://github.com/theanalyst/awesome-distributed-systems)
- [More about distributed systems](https://github.com/binhnguyennus/awesome-scalability)
- [Simple patterns explanations](https://github.com/kamranahmedse/design-patterns-for-humans)
  
## Review
**Solidified concepts**
- SOLID
- OOP
- DSA
    - Algorithms
        - binary search
        - bubble sort
        - linear search
        - quick sort
        - merge sort
        - floyd's fast slow pointer
        - sliding window
        - two pointers
    - Data Structures
        - dynamic array
        - hash table
        - array
        - linked list
        - queue
        - stacks
- Database concepts
    - ACID
    - BASE
    - CAP_theorem
    - PACELC
    - n+1_problem
    - replication
    - sharding

**Reviewing**
- Docker, Docker Compose, Docker swarm
    - How to use the compose properties healthcheck and depends_on to 
      ensure service startup sequence.
    - Dockerfile ENTRYPOINT vs CMD
- Clean Architecture

**Must review**
- DSA
    - Algorithms
        - breadth_first
        - depth_first
        - dijkstra_shortest_path
        - insertion_sort
        - selection_sort
    - Data Structures
        - trees
        - graphs
        - heap
        - spanning_tree
        - tries
        - sets
- Mircroservices Architecture
    - database_per_service
    - saga
    - command-side_replica
    - api_composition
    - cqrs
    - event_sourcing
    - transactional_outbox
    - transaction_log_tailing
    - polling_publisher
    - idempotent_consumer
    - api_gateway
    - circuit_breaker
    - log_aggregation
    - application_metrics
    - audit_logging
    - distributed_tracing
    - exception_tracking
    - health_check_api
    - cdc
- Clean Code

## DSA
**Goal:** Understand basic DSA and algorithm strategies to efficiently 
solve problems.

- array
  - hash-table
    - set
- graph
  - spanning-tree
- tree
  - heap
  - binary-tree
  - trie
  - set
- linked-list
  - stack
  - queue

- mon -> array
- tue -> linked-list
- wed -> tree
- thu -> graph
- fri -> interview prep list

## Side Project Ideas
- AI Quizz: define a set of documents which you should review every day and
  make an AI assistant that will make questions based on the separated 
  documents, wich you should answer with your own words.
- Stay up to date: A software that pulls updates about specified techs from
  many sources to give you the most recent information about the tech 
  world.
- Pattern Mentor: Create a cli tool based on a AI model to perform pattern 
  implementation checks in a code base and provide meaningful insights of 
  how to improve.
- Refactor: A code repository with projects with bad designs that the user 
  can clone and refactor the application to apply some pattern or principle
  to improve the maintanability, scalability and testability of the 
  application.
  - [Projects in C# you can try to refactor to your language and apply some design patterns](https://github.com/dodyg/practical-aspnetcore)
- [Microservice project ideas](https://github.com/mjebrahimi/Awesome-Microservices-DotNet?tab=readme-ov-file#sample-projects)
- [Distributed systems ideas](https://github.com/roma-glushko/awesome-distributed-system-projects)
- AICommitMessage: Provide code changes to the LLM and let it create the 
  commit message.
- TradingBot: A bot that performs simple trading operations on ebinex

## English topics
- Expressions.
- Practice to interview questions, specially what to say for the question 
  "tell me about yourself".
- Practice describing past projects, what was your role, challenges you 
  faced, how you solved them and the result of the projects.

## Linkedin
- Increase number of connections - 20x/day.
