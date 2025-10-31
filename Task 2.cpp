#include <iostream>
#include <vector>
using namespace std;


// task 2

// Sequential Search
int SequentialSearch(vector<int> v, int key) {
    bool found = false; // to check if the key was found or not 
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key) { // looking for the key inside the array
            cout << "the key found in index: " << i<<" using SequentialSearch "<<endl;
            found = true; //change found
            return i;
        }
    }
    if (!found) {
        cout << "key not found";
        return -1;
       
    }
}

//Iterative binary search
int binary_search(const vector<int>& v, int key) {
    int low = 0;
    int high = v.size() - 1;

    while (low <= high) { // Continue searching while the range is valid
        int mid = (low + high) / 2; // Find the middle index

        if (v[mid] == key) // Check if the middle element is equal to the key.
            return mid;

        // If the key is greater than the middle element
        else if (v[mid] < key) // search in the right half
            low = mid + 1;

        // If the key is less than the middle element
        else
            high = mid - 1; // search in the left half
    }

    return -1; // not found
}

// Recursive Binary Search
int recursive_sequential_search(vector<int> list, int value) {
    if (list.empty()) return -1;
    if (list.front() == value) return 0;
    int index = recursive_sequential_search(vector<int>(list.begin() + 1, list.end()), value);
    if (index == -1) return -1;
    return index + 1;
}

int recursive_binary_search(int list[], int value, int low, int high) {
    if (high < low) return -1;

    int mid = (low + high) / 2;
    if (list[mid] == value) return mid;
    else if (value > list[mid]) {
        low = mid + 1;
        return recursive_binary_search(list, value, low, high);
    }
    else {
        high = mid - 1;
        return recursive_binary_search(list, value, low, high);
    }
}



int main() {
   cout<<"please note we are using 3 different lists so the answer may be different deppending on which list used in it"<<endl;
    int key;
    cout << "search for: "; cin >> key;
    int list[] = { 1, 2, 3, 5, 7, 9 };
    vector<int> numbers = { 5, 3, 8, 6, 2, 7 };
    vector<int> sorted_list = { 1, 2, 3, 5, 7, 9 };

    cout << "Sequential Search:" << endl;
    SequentialSearch(numbers, key);
    cout<<endl;
    //Recursive Sequential Search
    cout<<"Recursive Sequential Search"<<endl;
    int index = recursive_sequential_search(numbers, key);
    if (index != -1) {
        cout << "Search by recursive sequential search:" << endl;
        cout << "The key " << key << " found in index: " << index << endl << endl;
    } else {
        cout << "Search by recursive sequential search:" << endl;
        cout << "The key " << key << " not found" << endl << endl;
    }
    //Binary Search
    cout<<"Binary Search:"<<endl;
    int index2 = binary_search(sorted_list, key);
    if (index2 != -1) {
        cout << "Iterative Binary Search:" << endl;
        cout << "Key: " << key << " found at index: " << index2 << endl;
    } else {
        cout << "Iterative Binary Search:" << endl;
        cout << "Key not found" << endl;
    }
    //Recursive Binary Search
    cout<<"Recursive Binary Search"<<endl;
    int indx = recursive_binary_search(list, key, 0, 5);
    if (indx != -1) {
        cout << "Search by recursive binary search:" << endl;
        cout << "The key " << key << " found in index: " << indx << endl << endl;
    } else {
        cout << "Search by recursive binary search:" << endl;
        cout << "The key " << key << " not found" << endl << endl;
    }

    return 0;

}


