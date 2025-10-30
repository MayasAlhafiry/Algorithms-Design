#include <iostream>
using namespace std;

class MaxHeap { // Define a class/structure for the heap.
private:
    int* values;
    int* priorities;
    int size;  // Maximum size of the array
    int count; // current number of elements actually in the heap

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1; // Index of the left child
        int right = 2 * index + 2; // Index of the right child

        if (left < count && priorities[left] > priorities[largest]) // Check if the left child exists and is greater than the current largest
            largest = left;

        if (right < count && priorities[right] > priorities[largest]) // Check if the right child exists and is greater than the current largest
            largest = right;

        if (largest != index) {
            swap(priorities[index], priorities[largest]);
            swap(values[index], values[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && priorities[index] > priorities[parent]) { 
            swap(priorities[index], priorities[parent]); 
            swap(values[index], values[parent]);
            heapifyUp(parent);
        }
    }

public:
    MaxHeap(int s) { //Constructor
        size = s;          // Set max size
        count = 0;    // Start empty
        values = new int[size];
        priorities = new int[size];
        cout << "Heap created successfully" << endl;  
    }


    void insert(int value, int priority) {
        if (count == size) { // Check if the heap is already full
            cout << "Heap is full" << endl;
            return;
        }
        values[count] = value; // Place the new value at the end of the heap
        priorities[count] = priority;
        heapifyUp(count);
        count++;  // Increase the number of elements in the heap
    }

    void extractMax(int& value, int& priority) {
        if (count == 0) { // Check if the heap is empty
            cout << "Heap is empty" << endl;
            value = -1;
            priority = -1;
            return;
        }
        value = values[0];
        priority = priorities[0];
        values[0] = values[count - 1];
        priorities[0] = priorities[count - 1];
        count--;
        heapifyDown(0);
    }


    int extractMin() {
        if (count == 0) { // Check if the heap is empty
            cout << "Heap is empty" << endl;
            return -1;
        }
        int minValue = values[0];
        for (int i = 1; i < count; i++) {
            if (values[i] < minValue)
                minValue = values[i];
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
            cout << "(" << values[i] << ", " << priorities[i] << ") ";
        cout << endl;
    }


};
//class PriorityQueue
class PriorityQueue {
private:
    MaxHeap heap;
    void dequeueHeloer(int& value,int& Priority) {
        if (heap.isEmpty()) {
            cout << "Heap is empty,nothing to remove" << endl;
        }
        heap.extractMax( value, Priority);
    }
    void peekHelper(int& value,int& Priority) {
        if (heap.isEmpty()) {
            cout << "Heap is empty,nothing to peek at" << endl;
        }
        heap.extractMax( value, Priority);
        heap.insert( value, Priority);
    }
public:
    PriorityQueue(int size) : heap(size) {
        cout << "PriorityQueue is created using heap class" << endl;
    }
    // add the biggest value to the front
    void enqueue(int value,int Priority ) {
        heap.insert(value,Priority);
    }
    // remove the first value , which is the highest priorty
    void dequeue() {
        int value, Priority;
        dequeueHeloer(value,Priority);
        cout<<"removed value(used dequeue): "<<value<<" the value priority: "<<Priority<<endl;
    }
    //checking the largest number without removing it , so i did use extractMax() from heap which returns and remove max and i did insert the value again
    int peek() {
        int value, Priority;
        peekHelper(value,Priority);
        cout<<"largest Priority(used peek): "<<value<<" with priority: "<<Priority<<endl;
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




/*void heapSort(int arr[], int n) {
    MaxHeap heap(n);
    for (int i = 0; i < n; i++) {
        heap.insert(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = heap.extractMax();
    }
}*/



int main()
{

    MaxHeap heap(10); // create heap of size 10 for example

    heap.insert(40, 2);
    heap.insert(30, 5);
    heap.insert(60, 1);
    heap.insert(20, 3);

    heap.display();

    int value, priority;
    heap.extractMax(value, priority);
    cout << "Max element: (" << value << ", " << priority << ")" << endl;

    int minValue = heap.extractMin();
    cout << "Min element (by value): " << minValue << endl;
    heap.display();
    //PriorityQueue test cases 
    PriorityQueue pq(10);
    pq.enqueue(40, 2);
    pq.enqueue(30, 5);
    pq.enqueue(60, 1);
    pq.enqueue(20, 3);
    pq.display();
    pq.peek();
    pq.display();
    pq.dequeue();
    pq.display();



    return 0;
}



