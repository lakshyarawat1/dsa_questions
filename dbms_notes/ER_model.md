# Entity Relationship Model (ER Model)

## Data Model

- Collection of conceptual tool for describing data, data relationships, semantics and consistency constraints.

## Introduction

- High-level data model.
- Perception of real world that consists of collection of basic objects called entities and relationships among those objects.
- Graphical representation of ER model is called ER diagram.

### Entity

- Real world object distinguishable from other objects.
- Uniquely identifiable.
- Has physical existence.
- Strong entity : Can be uniquely identified by its attributes.
- Weak entity : Can't be uniquely identified, depends on other strong entities
    - It doesn't have sufficient attributes, to select a unique entity.

### Entity Set

- Set of entities of the same type that share same properties or attributes.
- Student, Customer etc.

### Attributes

- Describes properties of an entity.
- For each attribute, there is a set of permitted values, called domain, or value set.
- Types of attributes are :

    - Simple : Atomic value, can't be divided. Ex: Name, Age etc.
    - Composite : Can be divided into smaller sub-parts. Ex: Address.
    - Single-valued : Only one value. Ex: Age.
    - Multi-valued : Can have multiple values. Ex: Phone number.
    - Derived : Value can be derived from other attributes. Ex: Age from DOB.
    - NULL value : Value is unknown or not applicable.

### Relationship

- Association of entities
- Strong relationship : between two independent entities.
- Weak relationship : between a weak entity and its owner entity.
- Degree of relationship : Number of entities associated with the relationship.
- Relationship constraints : 
    - Mapping Cardinality / Cardinality Ratio : No. of entities to which another entity can be associated. Ex : One to One, One to Many, Many to One, Many to Many.

    - Participation Constraints : 
        - Partial participation : Some entities are not participating in the relationship.
        - Total participation : All entities are participating in the relationship.

## Notations

- Entity : Rectangle
- Weak Entity : Double Rectangle
- Attribute : Oval
- Multi-valued attribute : Double Oval
- Derived attribute : Dashed Oval
- Key attribute : Underlined Oval
- Weak Key attribute : Dashed Underlined Oval
- Relationship : Diamond
- Weak Relationship : Double Diamond
- Total Participation : Double line
- Partial Participation : Single line
- Cardinality Ratio : Line with 1 or M

## Extended ER Model

- Enhanced ER model with additional concepts.

### Specialization

- Splitting up the entity set into further sub entity sets on the basis of their functionalities, specialities and features.
- Its a top-down approach.
- For example, Employee entity can be split into Manager and Worker entities.
- Always have a 'is-a' relationship.
- Depicted by triangle.
- Why ?
    - Certain attributes may only be applicable to certain sub-entities.
    - Distinctive features can be easily identified.
    - We apply specialization to refine DB design.

### Generalization