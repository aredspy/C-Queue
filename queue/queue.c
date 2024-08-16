// Main file

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

bool is_empty(Queue* q) {
    
    return !(q->front);
}

void enqueue(Queue* q, Node* n) {

    // set front and back if empty
    if (!q->front) {
        q->front = n;
        q->back = n;
        n->next = NULL;
        return;
    }

    // "Insert" node at back
    q->back->next = n;
    q->back = n;
    n->next = NULL;

}

Node* dequeue(Queue* q) {

    // "Deinsert (pop)" node 

    // empty check
    if (!q->front) {
        return NULL;
    }

    Node* n = q->front;
    q->front =  n->next;

    return n;
}

// some barely needed helper functions

Queue create_queue() {

    Queue q = {NULL, NULL};
    return q;

}

Node create_node(void* v) {
    
    Node n = {v, NULL};
    return n; 
}