
#include <stdio.h>

#include "queue/queue.h"
#include "priority_queue/pqueue.h"

void p_print_queue(P_Queue* q){

    printf("[FRONT] -> ");

    P_Node* n = q->front;
    P_Node* p = peak(q);

    while (n) {

        if (n == p) {

            printf("^[%d]^ -> ", *((int*) n->object));

        } else {

            printf("[%d] -> ", *((int*) n->object));
        }

        n = n->next;

    }

    printf("[BACK]\n");

}

void print_queue(Queue* q) {

    printf("[FRONT] -> ");

    Node* n = q->front;

    while (n) {

        printf("[%d] -> ", *((int*) n->object));
        n = n->next;

    }

    printf("[BACK]\n");

}

void test_queue() {

    // Create a linked list based queue
    Queue q = create_queue();
    // or Queque = {NULL, NULL};

    //Create some nodes
    int A = 1;
    int B = 2;
    int C = 3;

    Node n1 = create_node(&A);
    Node n2 = create_node(&B);
    Node n3 = create_node(&C);

    // Enqueue
    enqueue(&q, &n1);
    print_queue(&q);
    enqueue(&q, &n2);
    print_queue(&q);
    enqueue(&q, &n3);
    print_queue(&q);

    print_queue(&q);

    // Dequeue
    Node* n4 = dequeue(&q);
    print_queue(&q);
    Node* n5 = dequeue(&q);
    print_queue(&q);

    // Enqueue again
    enqueue(&q, &n2);
    print_queue(&q);

    // Dequeue all
    dequeue(&q);
    dequeue(&q);
    print_queue(&q);

}

void test_pqueue() {

    // Create a linked list based priority queue
    P_Queue q = p_create_queue();
    // or Queque = {NULL, NULL};

    // Create some nodes (yes this may husrt your eyes lol)
    int A = 1; int p1 = 5;
    int B = 2; int p2 = 10;
    int C = 3; int p3 = 2;

    // The verbosity is just to make it clear, you can skip this and use compound literals to create your sructs

    P_Node n1 = {&A, &p1, NULL};
    P_Node n2 = {&B, &p2, NULL};
    P_Node n3 = {&C, &p3, NULL};

    p_enqueue(&q, &n1);
    p_print_queue(&q);
    p_enqueue(&q, &n2);
    p_print_queue(&q);
    p_enqueue(&q, &n3);
    p_print_queue(&q);

    // Dequeue
    P_Node* n4 = p_dequeue(&q);
    p_print_queue(&q);
    P_Node* n5 = p_dequeue(&q);
    p_print_queue(&q);

    // Enqueue again
    p_enqueue(&q, &n2);
    p_print_queue(&q);

    // Dequeue all
    p_dequeue(&q);
    p_dequeue(&q);
    p_print_queue(&q);

}

int main() {

    printf("Regular Queue Test:\n");

    test_queue();

    printf("\n\nPriority Queue Test:\n");

    test_pqueue();

    return 0;

}