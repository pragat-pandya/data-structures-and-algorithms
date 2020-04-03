/****
This files implements a data structure called STACK using a linked list
It can also be implemented using an array.
Author : Pragat Pandya (GitHub:@psp2103)
****/

#include <iostream>
using namespace std;


// Structure describing each node of out stack data-structure.
struct stacknode {
    int data;
    stacknode *next;
};


// Structure used to operate and pass stack data-structure to member functions by reference.
struct stack {
    stacknode *head = nullptr;
};


// Function prototypes for helper stack functions
stacknode *init_stack (int a);
void stack_print(stack *x);
void push (stack *x, int a);
int pop (stack *x);
int peek (stack *x);
int stack_len (stack *x);
void clear (stack *x);
bool is_in(stack *x, int a);


// Driver code as desired.
int main (void) {
    // Suit Yourself :)
}


// Parameters: a:: Data whished to be contained by the newly created node
// Returns: a pointer to newly created node with data = a.
stacknode *init_stack (int a) {
    stacknode *p = (stacknode *) malloc(sizeof(stacknode));
    p->data = a;
    return p;
    p->next = nullptr;
}


// Parameter: x::Pointer to stack structure
// Prints: all the data contained by the stacknode associated with argumented stack pointer.
void stack_print(stack *x) {
    stacknode *itr = x->head;
    while (itr != nullptr) {
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    cout<<endl;
}


// Parameters:   x::Pointer to stack structure  a::Item to be pused onto stack
// Returns: nothing, i.e., stack will remain accesible by the same poiner passed to this function
void push (stack *x, int a) {
    stacknode *new_node = init_stack(a);
    if (x->head == nullptr) x->head = new_node;
    else {
        new_node->next = x->head;
        x->head = new_node;
    }
}


// Parameter: x:: Pointer to stack structure.
// Returns : The value at the top of the stack.
int pop (stack *x) {
    if (x->head == nullptr) return -1;
    else {
        stacknode *h = x->head;
        int a = h->data;
        x->head = h->next;
        free(h);
        return a;
    }
}


// Parameter: x:: Pointer to stack structure.
// Returns: The data field of the top most node.
int peek (stack *x) {
    if (x->head == nullptr) return -1;
    else {
        return x->head->data;
    }
}


// Parameter: x :: Pointer to stack structure.
// Returns: The total number of nodes contained by the stack.
int stack_len (stack *x) {
    if (x->head == nullptr) return 0;
    else {
        int count = 0;
        stacknode *itr = x->head;
        while (itr != nullptr) {
            count++;
            itr = itr->next;
        }
        return count;
    }
}


//Paramete: x:: Pointer to stack Structure   a:: int that will be chacked for the occurence in the stack.
// Returns: True:: if a exists in stack   False:: If a does not exist in stack
bool is_in(stack *x, int a) {
    if (x->head == nullptr) return false;
    else {
        stacknode *itr = x->head;
        while (itr != nullptr) {
            if (itr->data == a) return true;
            itr = itr->next;
        }
    }
}


// Parameter: x:: Pointer to the stack Structure
// Returns: Nothing && sets x to null after freeing up the space
void clear(stack *x) {
    if (x->head == nullptr) {
        free(x->head);      // This is redundent but still let it be ;
    }
    else {
        stacknode *itr = x->head, *temp;
        while (itr != nullptr) {
            temp = itr;
            itr = itr->next;
            free(temp);
        }
        x->head = nullptr;
    }
}
