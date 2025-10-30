#include <iostream>
using namespace std;

class MaxHeap { // Define a class/structure for the heap.
private:
    int* arr;  // Dynamic Array
    int size;  // Maximum size of the array
    int count; // current number of elements actually in the heap

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1; // Index of the left child
        int right = 2 * index + 2; // Index of the right child

        if (left < count && arr[left] > arr[largest]) // Check if the left child exists and is greater than the current largest
            largest = left;

        if (right < count && arr[right] > arr[largest]) // Check if the right child exists and is greater than the current largest
            largest = right;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && arr[index] > arr[parent]) { // If the current node is not the root and it's greater than its parent
            swap(arr[index], arr[parent]); // Swap the child with the parent
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
        if (count == size) { // Check if the heap is already full
            cout << "Heap is full!" << endl;
            return;
        }
        arr[count] = value; // Place the new value at the end of the heap
        heapifyUp(count);
        count++;  // Increase the number of elements in the heap
    }

    int extractMax() {
        if (count == 0) { // Check if the heap is empty
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int maxValue = arr[0];
        arr[0] = arr[count - 1];
        count--; // Reduce the heap size because one element is removed
        heapifyDown(0);
        return maxValue;
    }


    int extractMin() {
        if (count == 0) { // Check if the heap is empty
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int minValue = arr[0];
        for (int i = 1; i < count; i++) {
            if (arr[i] < minValue)
                minValue = arr[i];
        }
        count--; // Reduce the heap size because one element is removed
        return minValue;
    }
    bool isEmpty() {
        if (count == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void display() {
        cout << "Heap elements: ";
        for (int i = 0; i < count; i++)
            cout << arr[i] << " ";
        cout << endl;
    }


};

class PriorityQueue {
private:
    MaxHeap heap;
public:
    PriorityQueue(int size) : heap(size) {
        cout << "PriorityQueue is created using heap class" << endl;
    }
    // add the biggest value to the front
    void enqueue(int value) {
        heap.insert(value);
    }
    // remove the first value , which is the highest priorty
    int dequeue() {
        return heap.extractMax();
    }
    //checking the largest number without removing it , so i did use extractMax() from heap which returns and remove max and i did insert the value again
    int peek() {
        if (heap.isEmpty()) return -1;
        int value = heap.extractMax();
        heap.insert(value);
        return value;
    }
    //checks if empty
    bool isEmpty() {
        return heap.isEmpty();
    }
    //display what is inside the PriorityQueue
    void display() {
        heap.display();
    }

};


void heapSort(int arr[], int n) {
    MaxHeap heap(n);
    for (int i = 0; i < n; i++) {
        heap.insert(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = heap.extractMax();
    }
}



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

    PriorityQueue pq(10);
    pq.enqueue(40);
    pq.enqueue(30);
    pq.enqueue(60);
    pq.enqueue(20);
    pq.display();
    pq.dequeue();
    pq.display();
    cout << pq.peek() << endl;
    cout << pq.isEmpty() << endl;

    return 0;
}



