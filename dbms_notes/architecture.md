# Database Architecture

## Data abstraction

- Abstraction is the process of hiding the low-level details and showing only the essential features of the object.
- It helps to reduce programming complexity and effort.

## View of Data ( Three Schema Architecture )

- Database provides abstract view of the data.
- System hides certail details of how the data is stored and maintained.
- Abstraction is applied through several levels.

### Physical level / Internal level

- Lowest level of abstraction
- Describes how the data is stored
- Low level data structures are used
- Has physical schema which describes physical storage structure of DB.
- Topics : Storage allocation, data compression and encrpytion.
- Goals : Define algo's that allow efficient access to data.

### Logical level / Conceptual level

- Describes the design of a DB at conceptual level
- Describes what data are stored in DB and what relationship exists among those data.
- User at logical level does not need to know about physical level.
- Goal : Ease of Use

### View level / External level

- Highest level of abstraction 
- View schema describes the database part that a particular user group is interested in.
- At external level, a db contains multiple schemas called subschemas.
- Provides security mechanism to prevent users to access certain parts of DB.

## Instances and schemas


- Collection of information stored in DB at a particular moment is called instance of a DB.
- The overall design of DB is called its schema.
- Schema is structural description of data. 
- Schema doesn't frequently change.
- Schema corresponds to variable declarations in a program.
- Physical independence : Changes in physical schema do not affect the schema.

## Data Models

- Way to describe the design of DB in logical level.
- Underlying structure of DB.
- Tool to describe data, relationships, data semantics and consistency constraints.
- Ex : ER Model, Relational Model, Object Based Data Model.

## Database Languages

- DDL : Data Definition Language, specifies the database schema.
- DML : Data Manipulation Language, used to retrieve, insert, delete and modify data.
- DCL : Data Control Language, used to control access to data.

## Database Administrator (DBA)

- Centralized control of DB.
- Functions of DBA : 
    - Schema Defination
    - Storage structure and access methods
    - Schema and physical organization modification
    - Authorization control
    - Routine maintainance
        - Periodic backup
        - Security patches
        - Upgrades

## DBMS Application Architecture

### T1 Architecture

- Client, server and DB all are on the same machine.

### T2 Architecture

- App is partitioned into 2-components.
- Client machine, which invokes Db functionality at server end through query language statements.
- API standards like ODBC, JDBC are used to interact between client and server.

### T3 Architecture

- App is partitioned into 3-components.
- Client machine is just a frontend and doesn't contain any direct DB calls.
- Client machine communicates with App server, and App server comms with DB system to access data.
- Business logic, what action to take at that condition is in app itself.
- Advantages includes :
    - Scalability due to distributed nature.
    - Data integrity, App server acts as a middle layer between client and DB, which minimizes chances of data corruption.
    - Security, client can't directly access DB