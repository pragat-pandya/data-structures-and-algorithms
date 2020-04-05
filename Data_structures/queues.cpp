#include <iostream>
using namespace std;

struct qnode {
    int data;
    qnode *next;
};

struct q {
    qnode *head = nullptr;
    qnode *tail = nullptr;
};


void createQ (q* x, int a);
qnode *init_qnode (int a);
void enQ (q *x, int a);
int printQ (q* x);
int front(q *x);
int deQ (q *x);


int main (void) {
    q queue;
    q *Q = &queue;
    enQ(Q, 12);enQ(Q, 1);enQ(Q, 2);enQ(Q, 3);enQ(Q, 4);enQ(Q, 5);enQ(Q, 6);enQ(Q, 7);enQ(Q, 8);enQ(Q, 9);
    deQ(Q); deQ(Q);
    cout<<deQ(Q)<<endl;
    printQ(Q);
}


// To initialize a queue with one node
// Parameter: x:: Pointer to a empty structure of type "q"
// Creates a queue with one element 'a' at the pointer passed to function.
void createQ (q* x, int a) {
    x->head = init_qnode(a);
    x->tail = x->head;
}


// Parameter: a:: Element to be stored in data field of the qnode.
// Return: pointer to the newly created node.
qnode *init_qnode (int a) {
    qnode *p = (qnode *) malloc(sizeof(qnode));
    p->data = a; p->next = nullptr;
    return p;
}


// Parameter: x:: Pointer to the structure 'q'
// Insertes a new item into the queue.
void enQ (q *x, int a) {
    qnode *new_node = init_qnode(a);
    if (x->head == nullptr && x->tail == nullptr) {
        x->head = new_node; x->tail = new_node;
    }
    else {
        (x->tail)->next = new_node;
        x->tail = new_node;
    }
}


// Prints the keys contained by the queue if the *X contains any
// Parameter: x:: Pointer to the sturcute of type 'q'.q
// Return: 0:: If the printing successfully  -1:: Passed pointer was not pointing to any q
int printQ (q* x) {
    if (x->head == nullptr) return -1;
    qnode *itr = x->head;
    while (itr != nullptr) {
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    cout<<endl;
    return 0;
}


// Parameter: x:: Pointer to structure of type ' q'
// Returns: The element at the front of the queue
int front(q *x) {
    if (x->head == nullptr) return -1;
    else {
        return x->head->data;
    }
}


// Parameter: x:: Pointer to structure of type 'q'
// Returns: -1:: Fails to deQ or if the queue is empty else returns the element at the front of the queue.
int deQ (q *x) {
    if (x->head == nullptr) {
        return -1;
    }
    else {
        qnode *tmp = x->head;
        x->head = tmp->next;
        int a = tmp->data;
        free(tmp);
        return a;
    }
}
/***
deQ
****/
