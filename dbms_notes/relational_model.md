# Relational Model

## Introduction

- Organises data in form of relations (tables).
- Consists of collection of tables, each of which is assigned a unique name.
- A row in a table represents a relationship among a set of values, and table is collection of such relationships.
- Tuple: A single row of table representing a single data point / a unique record.
- Columns : represents the attributes of a relation. Each attribute, there is permitted value, called domain of the attribute.
- Relation Schema : defines the design and structure of the relation, contains the name of the relation and all the columns/attributes.
- Degree : Number of attributes / columns in a table / relation. 
- Cardinality : Number of tuples / rows in a table / relation.

### Properties

- Name of relation is unique
- Values have to be atomic, can't be broken down.
- Name of each attribute / column must be unique
- Each tuple must be unique in a table.
- The sequence of row and column has no significance.
- Table must follow integrity constraints - it helps to maintain data consistency across the tables.

## Relational Model Keys

### Super Key

Any P&C of attributes present in a table which can uniquely identify each tuple.

### Candidate Key

Minimum subset of super keys, which can uniquely identify each tuple, It contains no redundent attributes.

### Primary Key

Selected candidate key, has the least no. of attributes.

### Alternate Key

All CK except PK.

### Foreign Key

- It creates relation between two tables
- FK helps to cross reference using at least 2 attributes

### Composite Key

PK formed using atleast 2 attributes

### Compound Key

PK which is formed using 2 FK

### Surrogate Key

- Synthetic PK
- Generated automatically by DB, usually integer value.
- May be used as PK

## Integrity Constraints

- CRUD operations must be done with some integrity policy so that DB is always consistent.
- So that, we don't accidently corrupt the data.

### Domain Constraints

- Restricts the value in attribute of relation, specific domain.
- restricts the data types of the attributes.

### Entity Constraints

- Every relation should have a PK.

### Referential Constraints

- Specified between two relations & helps maintain consistency among tuples of two relations.
- Requires that the value appearing in specified attributes of any tuple in referencing relation also appear in the specified attributes of atleast one tuple of other relation.
- FK should have a matching PK in referenced relation.

### Key Constraints

- NOT NULL
- UNIQUE
- DEFAULT : If no value is provided, default value is used.
- CHECK : Ensures that the value in the column satisfies a specific condition.
- PRIMARY KEY
- FORIEGN KEY

## Transforming ER Model to Relational Model

### Notations to relations

- Strong Entity : 
    - Becomes an individual table with entity name, attributes becomes columns of the relation.
    - Entity's PK is used as relation's PK
    - FK are added to establish relationships with other relations.

- Weak Entity :
    - A table is formed with all the attributes of the entity.
    - PK of its corresponding strong entity will be added as FK
    - PK of the relation will be composite PK, i.e. FK + Partial Discriminator.

- Single Value Attributes :
    - Represented as columns directly in the tables.

- Composite Attributes :
    - Handled by creating a seperate attribute itself in the original relation for each composite attribute.
    
- Multi-Valued Attributes :
    - New tables are created for each multi-valued attribute.
    - PK of the entity is used as a column PK in the new table
    - Multi-valued attribute's similar name is added as a new column to define multiple values.
    - PK  of the new table would FK + multi-valued name.
    
- Derived attributes : 
    - Not considered in tables.

- Generalization : 
    - Method 1 :
        - Create a table for higher level entity set.
        - For each lower level entity set, create a table that include a column for each attributes of that entity set plus a column for primary key of higher level entity set.

    - Method 2 :
        - If generalization is disjoint and complete, i.e. if no entity is a member of two lower-level entity sets directly below a higher-level entity set, and if every entity in the higher level entity set.

- Aggregation :
    - Table of the relationship set is made.
    - Attributes include primary key of entity set and aggregation set's entities.
    - Also, add descriptive attribute of any relation.

