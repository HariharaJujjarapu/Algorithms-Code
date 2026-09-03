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

void quickSort(vector<int> &arr, int l, int r){
    if(l >= r)
            return;
    
    int pos = Partition(arr, l, r);
    
    quickSort(arr, l, pos-1);
    quickSort(arr, pos+1, r);
}

int main() {
    vector<int> arr = {4, 3, 1, 9, 7, 6};
    quickSort(arr, 0, arr.size()-1);
    for(int i  = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}