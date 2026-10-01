#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

void MaxTopDownHeapify(vector<int>& H, int root, int n){
    while(2 * root + 2 < n){
        int leftChild = 2 * root + 1;
        int rightChild = 2 * root + 2;

        int maxIdx;

        if(H[leftChild] > H[rightChild])
            maxIdx = leftChild;
        else
            maxIdx = rightChild;

        if(H[root] < H[maxIdx]){
            swap(H[root], H[maxIdx]);
            root = maxIdx;
        }
        else{
            root = n;
        }
    }

    // There can be a possibility of left leftChild
    int leftChild = 2 * root + 1;
    if(leftChild < n && H[root] < H[leftChild]){
        swap(H[root], H[leftChild]);
        root = leftChild;
    }
}

void MinTopDownHeapify(vector<int>& H, int root, int n){
    while(2 * root + 2 < n){
        int leftChild = 2 * root + 1;
        int rightChild = 2 * root + 2;

        int minIdx;

        if(H[leftChild] < H[rightChild])
            minIdx = leftChild;
        else
            minIdx = rightChild;
        
        if(H[root] > H[minIdx]){
            swap(H[root], H[minIdx]);
            root = minIdx;
        }
        else{
            root = n;
        }
    }

    // There can be a possiblity of leftChild
    int leftChild = 2 * root + 1;
    if(leftChild < n && H[root] > H[leftChild]){
        swap(H[root], H[leftChild]);
        root = leftChild;
    }
}

void MaxBottomUpHeapify(vector<int>& H, int i, int n){
    int parent = (i-1)/2;
    while(parent > -1){
        if(H[parent] < H[i]){
            swap(H[parent], H[i]);
            i = parent;
            parent = (i-1)/2;
        }
        else{
            parent = -1;
        }
    }
}

void MinBottomUpHeapify(vector<int>& H, int i, int n){
    int parent = (i-1)/2;
    while(parent > -1){
        if(H[parent] > H[i]){
            swap(H[parent], H[i]);
            i = parent;
            parent = (i-1)/2;
        }
        else{
            parent = -1;
        }
    }
}

void DecreaseKey (vector<int>& H,  int i, int X, int n) {
  H[i] = X;
  MinBottomUpHeapify(H, i, n);
}

void IncreaseKey (vector<int>& H,  int i, int X, int n) {
  H[i] = X;
  MaxBottomUpHeapify(H, i, n);
}

void DeleteMin(vector<int>& H, int *n){
    *n = *n - 1;
    int temp = H[0];
    H[0] = H[*n];
    H[*n] = temp;
    MinTopDownHeapify (H,0,*n);
}

void BuildHeap(vector<int>& H, int n){
    int i = n/2;

    while(i > -1){
        MinTopDownHeapify(H, i, n);
        i--;
    }
}

void HeapSort(vector<int>& H, int n){
    BuildHeap(H, n);

    int m = n;
    for(int i = 0; i < n; i++){
        DeleteMin(H, &m);
    }
}

int main() {
    int n = 8;
    vector<int> H(n);

    for(int i = 0; i < n; i++){
        H[i] = rand() % 100 + 100;
    }

    HeapSort(H, n);

    for(int i = 0; i < n; i++){
        cout << H[i] << " ";
    }

    return 0;
}