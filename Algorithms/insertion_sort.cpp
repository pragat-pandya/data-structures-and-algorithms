#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n);


int main (void) {
    int a[] = {10,9,8,7,6,5,4,3,2,1};
    insertion_sort(a,10);
    for (int i = 0; i<10; i++) cout<<a[i]<<" ";
    cout<<endl;
}

void insertion_sort(int arr[], int n) {
    for (int j = 1; j < n; j++) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {      // Here arr[j] will serve as key
            arr[i+1] = arr[i];
            i -= 1;
        }
        arr[i+1] = key;
    }
}
