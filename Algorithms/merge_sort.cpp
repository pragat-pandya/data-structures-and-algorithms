// Merge sort works on the principal of dividing the original array into subarrays and sorting thsese small sub-arrays (DIVIDE)
// and then merging these sorted sub-arrays to form a fully sorted array. (CONQUER)
// The merge() method lies at the heart of the merge_sort() algorithm.
// One drawback though: space-complexity = O(n)
// for merge sort recursive design is intuitive.
#include <bits/stdc++.h>
using namespace std;

// Merge(): s1: Sorted_left_sub_array, s2: Sorted_right_sub_array, s: New array to merge two sorted arrays
void merge (vector<int> &s1, vector<int> &s2, vector<int> &s) {
    // iterator for left_sorted
    vector<int>::iterator p1 = s1.begin();
    // oterator for right_sorted
    vector<int>::iterator p2 = s2.begin();
    // while we haven't reached at the end of either arrays.
    while (p1 != s1.end() && p2 != s2.end()) {
        // compare smallest elements of each list
        if (*p1 <= *p2) s.push_back(*p1++); // add the smallest to the resultant array
        else s.push_back(*p2++);
    }
    // checking for one non-empty lists IF ANY
    while (p1 != s1.end()) s.push_back(*p1++);
    while (p2 != s2.end()) s.push_back(*p2++);
}
// Variations on merge:
//      It is a very generic operation in field of computer science:
//      can be used for the following purpose:
//      We can remove duplicates: using if (*j == *i) {c[*j++]; i++;j++}
//      Can also be used to obtain set-difference and list-difference


// Merge_sort(): a: Array to be sorted
void merge_sort(vector<int> &a) {
    int n = a.size();
    // base-case
    if (n <= 1) return;
    // Divide in two sub-arrays
    vector<int> s1, s2;
    vector<int>::iterator p = a.begin();
    // populate the sub-arrays
    for (int i = 0; i < n/2; i++) s1.push_back(*p++);
    for (int i = n/2; i < n; i++) s2.push_back(*p++);
    // empty the input array, so that we can merge the sorted sub-arrrays into it
    // in this way we wouldn't be wasting any space .
    // i.e., space-complexity: O(1)
    a.clear();

    // recursively sort both these sub-arrays.
    merge_sort (s1);
    merge_sort (s2);

    // merge two sorted sub-arrays using method Merge().
    merge (s1, s2, a);
}

// SHORT-COMMINGS::
//  1. Requires extra space to achive merge in linear time. (space-time trade-off)
//  2. It's inherently recursive. cannot be easily implemented iteratively.

int main () {
    vector<int> arr = {10, 8, 1, 5, 3, 9, 12};
    merge_sort (arr);
    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<' ';
    }
    return 0;

}


// :::::ANALYSIS OF MERGE SORT ALGORITHM::::::
// Time complexity for Merge() : T(n) = T(s1.size()) + T(s2.size()) : O(max(s1.size(),s2.size())) === O(n)
// For 'T' being time taken by merge_sort()
//  t(n) = 2t(n/2) + n;  && t(1) = 1
//  which eventually leads us to 'O(nlogn)' on expanding this recurrance relation.
// t(n) = n + nlogn
