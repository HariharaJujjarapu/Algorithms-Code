#include <iostream>
#include <vector>
using namespace std;

long long mergeVectors(vector<int> &arr, int l, int m, int r) {

    int i = l;
    int j = m + 1;
    int k = 0;

    long long count = 0;

    vector<int> mergeArray(r - l + 1);

    while (i <= m && j <= r) {

        if (arr[i] <= arr[j]) {
            mergeArray[k++] = arr[i++];
        }
        else {
            mergeArray[k++] = arr[j++];

            // All remaining elements in left
            // are greater than arr[j-1]
            count += (m - i + 1);
        }
    }

    while (i <= m)
        mergeArray[k++] = arr[i++];

    while (j <= r)
        mergeArray[k++] = arr[j++];

    for (int i = l, j = 0; i <= r; i++, j++)
        arr[i] = mergeArray[j];

    return count;
}

long long mergeSort(vector<int> &arr, int l, int r) {

    if (l >= r)
        return 0;

    int m = l + (r - l) / 2;

    long long count = 0;

    count += mergeSort(arr, l, m);
    count += mergeSort(arr, m + 1, r);

    count += mergeVectors(arr, l, m, r);

    return count;
}

int main() {

    vector<int> arr = {4, 3, 1, 9, 7, 6};

    long long count = mergeSort(arr, 0, arr.size() - 1);

    cout << "Inversion Count = " << count << endl;

    return 0;
}