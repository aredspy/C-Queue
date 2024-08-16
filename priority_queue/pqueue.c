// Main file

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pqueue.h"

bool p_is_empty(P_Queue* q) {
    
    return !(q->front);
}

void p_enqueue(P_Queue* q, P_Node* n) {

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

P_Node* p_dequeue(P_Queue* q) {

    // Empty check
    if (!q->front) {
        return NULL;
    }

    // "Deinsert (pop)" node with highest priority

    P_Node* prev = __peak_n1(q);

    // First elem check
    if (!prev) {

        P_Node* n = q->front;

        if (!n->next) {
            q->front = NULL;
            return n;
        }
        
        q->front = n->next;
        return n;
    }

    P_Node* n = prev->next;

    // splice
    prev->next = n->next;

    return n;

}

P_Node* peak(P_Queue* q) {

    // empty check
    if (p_is_empty(q))
        return NULL;

    P_Node* highest = q->front;
    P_Node* n = highest->next;

    while(n) {

        // compare
        if (*n->priority > *highest->priority){
            highest = n;
        }

        n = n->next;
    }

    return highest;

}

// Gives the node (physcially not second highest) right before highest
P_Node* __peak_n1(P_Queue* q) {

    // empty check
    if (p_is_empty(q))
        return NULL;

    P_Node* highest = q->front;
    P_Node* n = q->front;
    P_Node* prev = NULL;

    while(n->next) {

        // compare
        if (*n->next->priority > *highest->priority){
            highest = n->next;
            prev = n;
        }
        
        n = n->next;
    }

    return prev;

}

// some barely needed helper functions

P_Queue p_create_queue() {

    P_Queue q = {NULL, NULL};
    return q;

}
