# B-Trees

## Prerequisites

### Disk Structure

- Disk has logical circles called tracks
- Each track is divided into sectors
- Intersecting areas in tracks and sectors are called blocks.
- Every location in the disk can be represented as track number and sector number.
- It is assumed that each block can store 512 bytes of data.
- Each byte in the block has its unique address called offset.
 
### M-Way Search Tree

- An M-Way Search Tree is a tree data structure where each node can have a maximum of M children.
- Each node contains up to M-1 keys that help in guiding the search process.
- Major disadvantage is that there is no rule to insert keys in the node. Whether to insert in the key or the child pointer is not defined.

## B-Tree Definition

- M-way tree with some additional properties / rules.
- Each node must have at least ⌈M/2⌉ children.
- Root can have minimum 2 children.
- All leaf nodes must be at the same level.
- Created bottom up.