// code for selection sort on cpp std vectors.
// Instead of using a new vector to store the sorted list we've used the swaping.
#include <bits/stdc++.h>
using namespace std;

// Recursive version of selection sort.
void rec_sort(vector<int> &a, int size, int start = 0) {
    if (start == size-1) return;
    int min = a[start];
    for (int i = start+1; i < size; i++) {
        if (a[i] < a[min]) min = i;
    }
    swap(a[start],a[min]);
    rec_sort(a, size, start+1);
}
// Analysis of selection sort: (recursive)
// recurrance relation : t(n) = n + t(n-1) :: O(n^2)
// NO change in performance but recursive one will cost us extra space and overhead of function calls.


// Iterative version of Selection sort.
void selection_sort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min = i;
        for (int j = min+1; j < arr.size(); j++) {
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
    }
}
// Analysis of insertion sort:
//  t(n) = n + (n-1) + (n-2) + (n-3) + ... + 1 = n(n+1)/2 = O(n^2)


int main() {
    vector<int> a = {10,9,8,7,6,5,4,3,3,22,1,1};
    rec_sort(a,a.size());
    for (int item: a) cout<<item<<' ';
    cout<<endl;
    return 0;
}
