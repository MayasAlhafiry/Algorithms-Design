#include <iostream>
using namespace std;

class MaxHeap { // Define a class/structure for the heap.
private:
    int* arr;  // Dynamic Array
    int size;  // Maximum size of the array
    int count; // current number of elements actually in the heap

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < count && arr[left] > arr[largest])
            largest = left;

        if (right < count && arr[right] > arr[largest])
            largest = right;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && arr[index] > arr[parent]) {
            swap(arr[index], arr[parent]);
            heapifyUp(parent);
        }
    }

public:
    MaxHeap(int s) { //Constructor
        size = s;          // Set max size
        arr = new int[size]; 
        count = 0;    // Start empty
        cout << "Heap created successfully" << endl;
    }


    void insert(int value) {
        if (count == size) {
            cout << "Heap is full!" << endl;
            return;
        }
        arr[count] = value;
        heapifyUp(count);
        count++;
    }

    int extractMax() {
        if (count == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int maxValue = arr[0];
        arr[0] = arr[count - 1];
        count--;
        heapifyDown(0);
        return maxValue;
    }
    

    int extractMin() {
        if (count == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int minValue = arr[0];
        for (int i = 1; i < count; i++) {
            if (arr[i] < minValue)
                minValue = arr[i];
        }
        return minValue;
    }

    void display() {
        cout << "Heap elements: ";
        for (int i = 0; i < count; i++)
            cout << arr[i] << " ";
        cout << endl;
    }


};


int main()
{

    MaxHeap heap(10); // create heap of size 10 for example

    heap.insert(40);
    heap.insert(30);
    heap.insert(60);
    heap.insert(20);

    heap.display();

    cout << "Max element: " << heap.extractMax() << endl;
    cout << "Min element: " << heap.extractMin() << endl;

    heap.display();

    return 0;
}
   


