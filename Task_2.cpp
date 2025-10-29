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

int recursive_sequential_search(vector<int> list, int value) {
    if (list.empty()) return -1;
    if (list.front() == value) return 0;
    int index = recursive_sequential_search(vector<int>(list.begin()+1, list.end()), value);
    if (index == -1) return -1;
    return index+1;
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

    int key;
    cout << "search for: "; cin >> key;

    int list[] = {1, 2, 3, 5, 7, 9};
    int indx = recursive_binary_search(list, key, 0, 5);
    cout << "search by recursive binary search\n" << "the key " << key << " found in index: " << indx << endl << endl;

    vector<int> numbers = {5, 3, 8, 6, 2, 7};

    int index = recursive_sequential_search(numbers, key);
    cout << "search by recursive sequential search\n" << "the key " << key <<" found in index: " << indx << endl << endl;

    SequentialSearch(numbers, key);


    return 0;
}
