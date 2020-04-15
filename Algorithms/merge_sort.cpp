#include <iostream>
using namespace std;

void merge_sort (int *a, int start, int end);
void merge_sorted_subs (int *a, int start, int mid, int end);


int main (void) {
    //cout<<"Please enter the size of the array: ";
    int n = 8; //cin>>n;

    // Error-checking for array_length.
    if (n <= 0) {
        cout<<"Invalid array length!!!!"<<endl;
        return -1;
    }

    // Reading array elements from common input.
    int arr[n] //= {14,7,3,12,9,11,6,12};
    cout<<"Please enter "<<n<<" space separated arary elements: "<<endl;
    for (int i = 0; i < n; i++) cin>>arr[i];

    merge_sort(arr,0,n-1);
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}


// PRE-CONDITION: 1)start<end   2)start and end are both within the bound of A.
void merge_sort (int *a, int start, int end) {
    // Recursion base-case.
    if (end == start + 1) return;

    // Get the middle index of the given array
    int mid = (start+end) / 2;

    // Merge both the sub-arrays of length ~ n/2.
    merge_sort(a, start, mid);
    merge_sort(a, mid, end);

    merge_sorted_subs(a, start, mid, end);
}
// POST-CONDITION: array: A sorted in increasing order.


// PRE-CONDITION: a[start]...a[mid-1] && a[mid]...a[end-1] sorted in increasing order.
void merge_sorted_subs (int *a, int start, int mid, int end) {
    int i, j, tmp[end-start], index = start;
    for (i = start, j = mid; ((i<mid)||(j<end));) {
        if ((i < mid)&&(j<end)) { // None of the two sub-arrays has been seen fully yet.
            if (a[j] < a[i]) {
                tmp[index] = a[j];
                j++;
            }
            else {
                tmp[index] = a[i];
                i++;
            }
        }
        else { // One of the sub-array is been fully seen.
            if (i < mid) {
                tmp[index] = a[i];
                i++;
            }
            else {
                tmp[index] = a[j];
                j++;
            }
        }
        index++;
    }
    for (i = start; i < end; i++) a[i] = tmp[i];
    return;
}
// POST-CONDITION: a[start]...a[end-1] sorted in increasing order.
