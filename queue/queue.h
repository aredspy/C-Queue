// Header file

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

// NOTE: "Head" is front and "Tail" is back

// Regular fixed sized queue

typedef struct Queue {
    struct Node* front;
    struct Node* back;
} Queue;

// regular node

typedef struct Node {
    void* object;
    struct Node* next;
} Node;


// prototypes

bool is_empty(Queue*);
void enqueue(Queue*, Node*);
Node* dequeue(Queue*);
Queue create_queue();
Node create_node(void*);

#endif