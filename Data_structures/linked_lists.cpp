#include <iostream>
using namespace std;


struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};
struct SinglyLinkedList {
    SinglyLinkedListNode *head = nullptr;
};


SinglyLinkedListNode *init_node (int key);
void print_list (SinglyLinkedList *x);
void add_front (SinglyLinkedList *x, int key);
void add_back (SinglyLinkedList *x, int key);
bool is_in (SinglyLinkedList *x, int key);
bool insert_at(SinglyLinkedList *x, int position, int key);
bool del_key (SinglyLinkedList *x, int key);
bool remove_at (SinglyLinkedList *x, int position);
int pop (SinglyLinkedList *x);
void remove_front (SinglyLinkedList *x);
void clear_list(SinglyLinkedList *x);


int main (void) {
    SinglyLinkedList list, *a = &list;
    //a->head = init_node(3);
    add_front(a,2);
    add_front(a,1);
    add_front(a,0);
    add_back(a,3); add_back(a,4); add_back(a,5);
    del_key(a,0);
    clear_list (a);
    print_list(a);
    return 0;
}


SinglyLinkedListNode *init_node (int key) {
    SinglyLinkedListNode *ptr = (SinglyLinkedListNode *) malloc(sizeof(SinglyLinkedListNode));
    ptr->data = key;
    ptr->next = nullptr;
    return ptr;
}


void print_list (SinglyLinkedList *x) {
    SinglyLinkedListNode *itr = x->head;
    while (itr != nullptr) {
        cout<<itr->data<<endl;
        itr = itr->next;
    }
}


void add_front (SinglyLinkedList *x, int key) {
    SinglyLinkedListNode *ptr = x->head;
    SinglyLinkedListNode *new_node = init_node(key);
    if (ptr == nullptr) x->head = new_node;
    new_node->next = ptr;
    ptr = new_node;
    x->head = ptr;
}


void add_back (SinglyLinkedList *x, int key) {
    SinglyLinkedListNode *itr = x->head;
    SinglyLinkedListNode *new_node = init_node(key);
    if (itr == nullptr) x->head = new_node;
    while (itr->next != nullptr) itr = itr->next;
    itr->next = new_node;
}



bool is_in (SinglyLinkedList *x, int key) {
    SinglyLinkedListNode *itr = x->head;
    while (itr != nullptr) {
        if (itr->data == key) return true;
        itr = itr->next;
    }
    return false;
}


// Indexing starts from : ZERO. and inserts the key at the position-th index.
// Trusting the users for position input i.e., it will be a legal index in the given list
bool insert_at(SinglyLinkedList *x, int position, int key) {
    SinglyLinkedListNode *new_node = init_node(key);
    SinglyLinkedListNode *itr = x->head;
    for (int i = 0; i < position && itr!= nullptr; i++, itr = itr->next) {
        if (i == position - 1) {
            new_node->next = itr->next;
            itr->next = new_node;
            return true;
        }
    }
    return false;
}


bool del_key (SinglyLinkedList *x, int key) {
    if (x->head == nullptr) return false;
    SinglyLinkedListNode *itr0, *itr1;
    itr0 = x->head;
    itr1 = (x->head)->next;
    if (itr0->data == key) {
        x->head = itr0->next;
        free(itr0);
        return true;
    }
    while (itr1 != nullptr) {
        if (itr1->data == key) {
            itr0->next = itr1->next;
            free(itr1);
            return true;
        }
        itr0 = itr0->next;
        itr1 = itr1->next;
    }
    return false;
}

// Again trusting the users with non-errorneous index inputs
bool remove_at (SinglyLinkedList *x, int position) {
    SinglyLinkedListNode *itr = x->head;
    if (position == 0) {
        x->head = itr->next;
        free(itr);
        return true;
    }
    for (int i = 0; i < position&&itr!=nullptr; i++, itr=itr->next) {
        if (i == position - 1) {
            SinglyLinkedListNode *del = itr->next;
            itr->next = (itr->next)->next;
            free(del);
            return true;
        }
    }
    return false;
}


int pop (SinglyLinkedList *x) {
    SinglyLinkedListNode *p1, *p2;
    int result = 0;
    p1 = x->head;
    if (p1 == nullptr) return -1;
    if (p1->next == nullptr) {
        result = p1->data;
        free(p1); x->head = nullptr;
        return result;
    }
    while ((p1->next)->next != nullptr) p1 = p1->next;
    p2 = p1;
    p1 = p1->next;
    result = p1->data;
    p2->next = nullptr;
    free(p1);
    return result;
}

void remove_front (SinglyLinkedList *x) {
    SinglyLinkedListNode *p = x->head;
    x->head = p->next;
    free(p);
}

void clear_list(SinglyLinkedList *x) {
    SinglyLinkedListNode *itr = x->head;
    while (itr != nullptr) {
        SinglyLinkedListNode *temp = itr;
        itr = itr->next;
        free(temp);
    }
    x->head = nullptr;
}
