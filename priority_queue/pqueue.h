// Header file

#ifndef _PQUEUE_H_
#define _PQUEUE_H_

#include <stdbool.h>

// change if you want a different priority comparator
typedef unsigned int p_uint;

// NOTE: "Head" is front and "Tail" is back

// Regular fixed sized queue

typedef struct P_Queue {
    struct P_Node* front;
    struct P_Node* back;
} P_Queue;

// regular node

typedef struct P_Node {
    void* object;
    p_uint* priority;
    struct P_Node* next;
} P_Node;


// prototypes

bool p_is_empty(P_Queue*);
void p_enqueue(P_Queue*, P_Node*);
P_Node* p_dequeue(P_Queue*);
P_Node* peak(P_Queue*);
P_Node* __peak_n1(P_Queue*);
P_Queue p_create_queue();

#endif