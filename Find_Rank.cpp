#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int Partition(vector<int> &arr, int l, int r){
    int pivot = l;
    int i = l+1, j = r;
    
    while( i <= j){
        while(i <= r && arr[i] <= arr[pivot])
            i++;
        while(j >= l+1 && arr[j] >= arr[pivot])
            j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    
    swap(arr[pivot], arr[j]);
    return j;
}

int findRank(vector<int> &arr, int l, int r, int rank){
    while(l <= r){
        int pivotIdx = l + (rand() % (r-l+1));
        swap(arr[pivotIdx], arr[l]);
        int k = Partition(arr, l, r);
        if(rank == r-k+1)
            return k;
        else if(rank < r-k+1)
            findRank(arr, k+1, r, rank);
        else
            findRank(arr, l, k-1, rank+k-r-1);
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 3, 1, 9, 7, 6};
    int idx = findRank(arr, 0, arr.size()-1, 3);
    if(idx)
        cout << arr[idx];
    else
        cout << "No Element is found";
    return 0;
}