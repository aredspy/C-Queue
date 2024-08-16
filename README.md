## Linked List based Queue and Priority Queue implementation in C

This is a sample queue and priority queue implementation in C using a linked list data structure. 
This was originally used as part of a scheduler that used several task sharing algorithms for an OS project (hence the priority queue).

A sample makefile is provided to create a test program that displays the structures of the queues with sample nodes.

The priority queue will dequeue with highest priority number (uint), which can be modified for lowest or a different comparator.

### Complexity table

| Action | Queue | P_Queue |
|--------|-------|---------|
| Enqueue| O(1)  | O(1)    |
| Dequeue| O(1)  | O(n)    |
|is_empty| O(1)  | O(1)    |
| Peek   |       | O(n)    | 
