#include <iostream>
#include <vector>
using namespace std;

void mergeVectors(vector<int> &arr, int l, int m, int r){
    int n1 = m - l + 1, n2 = r - m;
    int i = l, j = m+1, k = 0;
    vector<int> mergeArray(n1+n2);
    while(i <= m && j <= r){
        if(arr[i] <= arr[j])
            mergeArray[k++] = arr[i++];
        else
            mergeArray[k++] = arr[j++];
    }
    while(i <= m)
        mergeArray[k++] = arr[i++];
    while(j <= r)
        mergeArray[k++] = arr[j++];
    for(int i = l, j = 0; i <= r; i++, j++)
        arr[i] = mergeArray[j];
}

void mergeSort(vector<int> &arr, int l, int r){
    if(l >= r)
        return;
    int m = l + (r - l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    mergeVectors(arr, l, m, r);
}

int main() {
    vector<int> arr = {4, 3, 1, 9, 7, 6};
    mergeSort(arr, 0, arr.size()-1);
    for(int i  = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}