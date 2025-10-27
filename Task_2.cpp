#include <iostream>

using namespace std;


// task 2

int recursive_sequential_search(int list[], int len, int value, int start=0) {
    int i = start;
    if (i==len) return -1;
    if (list[i] == value) return i;
    return recursive_sequential_search(list, len, value, ++start);
}

int recursive_binary_search(int list[], int value, int low, int high) {
    if (high<low) return -1;

    int mid = (low+high)/2;
    if (list[mid] == value) return mid;
    else if (value>list[mid]) {
        low = mid+1;
        return recursive_binary_search(list, value, low, high);
    }
    else {
        high = mid-1;
        return recursive_binary_search(list, value, low, high);
    }
}



int main() {
    int list[] = {2, 4, 3, 7, 5, 7};

    int index = recursive_sequential_search(list, 6, 5);
    cout << endl << index;

    int indx = recursive_binary_search(list, 5, 0, 5);
    cout << endl << indx;


    return 0;
}

