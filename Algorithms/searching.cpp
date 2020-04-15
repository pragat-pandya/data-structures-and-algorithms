/****
    This file contains source code for two most fundamantel searching algorithms:
        1. Linear Search
        2. Binary Search
        (FOR ARRAYS)
    Author : Pragat Pandya (@psp2103)
****/

#include <iostream>
#include <algorithm>
using namespace std;

int linear_search (int *a, int start, int end, int key);
int binary_search (int *a, int start, int end, int key);

int main () {
    cout<<"Please insert number of elements in the array: ";
    int n; cin>>n;

    int arr[n];
    cout<<"Please insert "<<n<<" space separated values: "<<endl;
    for (int i = 0 ; i < n; i++) cin>>arr[i];
    cout<<binary_search(arr,1,n,10)<<endl;
    return 0;
}


// PRE-CONDITION: 1. start<end 2.start&end are within bounds of array
int linear_search (int *a, int start, int end, int key) {
    if (a == nullptr) return -1;
    for (int i = start - 1; i < end; i++ ) {
        if (a[i] == key) return i;
    }
    return -1;
}
// POST-CONDITION: Returns: -1: If key does not exists in a[]
//                           i: Index of the key in a[]

// PRE-CONDITION: a[] is sorted in incresing order
int binary_search (int *a, int start, int end, int key) {
    if (end == start+1) {   // Array has exactly 1 element.
        if (a[start] == key) {return start;}
        else return -1;
    }
    int mid = (start+end) / 2;
    if (a[mid] == key) return mid;
    else {
        if (a[mid] < key) return binary_search(a, mid, end, key);
        else return binary_search(a, start, mid, key);
    }
}
// POSTCONDITION: If srchElementin A[start] ... A[end-1], return its index, else -1
