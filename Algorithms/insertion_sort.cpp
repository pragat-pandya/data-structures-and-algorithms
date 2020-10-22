// code for insertion sort on cpp std vectors<int>
// Essentially, insertion sort is how we sort a pack of playing cards.
// Keeping a sorted sub-array to sort in-place.
#include <bits/stdc++.h>
using namespace std;

// Recursive version of insertion sort:
void rec_sort (vector<int> &a, int start = 0) {
    // base-case
    if (start > a.size()-1) return;
    // recursive step
    int pos = start;
    // add a[start] to the sorted sub-array (a[0],a[1],..,a[start-1])
    while (pos > 0 && a[pos] < a[pos-1]) {
        swap (a[pos], a[pos-1]);
        pos--;
    }
    // Call rec_sort for the next element of the vector (increment the start position)
    rec_sort(a, start+1);
}
// Analysis of insertion sort: (Recursive)
// t(n) = n-1 + t(n-1) == O(n^2)


// Iterative version of insertion sort:
void insertion_sort(vector<int> &arr) {
    for (int j = 1; j < arr.size(); j++) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {      // Here arr[j] will serve as key
            arr[i+1] = arr[i];
            i -= 1;
        }
        arr[i+1] = key;
    }
}
// Analysis of insertion_sort: (Iterative)
//  t(n) = 1 + 2 + 3 + ... + n = n(n+1)/2 ::: O(n^2)

int main () {
    vector<int> a = {10,9,8,7,6,5,4,3,3,22,1,1};
    rec_sort(a);
    for (int item: a) cout<<item<<' ';
    cout<<endl;
    return 0;
}
