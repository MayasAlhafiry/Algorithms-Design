#include <iostream>
#include <vector>
using namespace std;


// task 2

// Sequential Search
int SequentialSearch(vector<int> v, int key) {
    bool found = false;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key) {
            cout<<"the key found in index: " <<i;
            found = true;
        }
    }
    if (!found) {
        cout<<"key not found";
        return -1;
    }
}

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
    cout << endl << indx<<endl;

    vector<int> numbers = {5, 3, 8, 6, 2, 7};
    SequentialSearch(numbers, 3);


    return 0;
}

