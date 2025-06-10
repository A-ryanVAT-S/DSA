#include <bits/stdc++.h>
using namespace std;

class heap{
    vector<int> arr;
    int size = 0;

    public:
    heap() {
      
    }

    //TC is O(log n) for insertion
    //SC is O(n) for storing the heap elements
    void insert(int val) {
        arr.push_back(val);
        size++;
        int index = size - 1;
        // Bubble up to maintain heap property
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (arr[index] > arr[parentIndex]) {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }    // for deletion, we generally remove the root element and then maintain the heap property
    // tc is O(log n) for deletion and sc is O(1) for deletion
    void deleteRoot() {
        if (size == 0) return; // Nothing to delete
        arr[0] = arr[size - 1]; // Move last element to root
        arr.pop_back(); // Remove last element
        size--;
        int index = 0;
        // Bubble down to maintain heap property
        while (index < size / 2) {
            int leftChildIndex = index * 2 + 1;
            int rightChildIndex = index * 2 + 2;
            int largestIndex = index;

            if (leftChildIndex < size && arr[leftChildIndex] > arr[largestIndex]) {
                largestIndex = leftChildIndex;
            }
            if (rightChildIndex < size && arr[rightChildIndex] > arr[largestIndex]) {
                largestIndex = rightChildIndex;
            }
            if (largestIndex != index) {
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            } else {
                break;
            }
        }
    }
    // Function to build a max-heap from an array
    //Tc is O(n) for building the heap
    // because we are calling heapify on each non-leaf node and each heapify call takes O(log n) time but
    // there are n/2 non-leaf nodes, so the overall time complexity is O(n) as the sum of the series 1 + 2 + ... + n/2 is O(n).
    //SC is O(1) for building the heap as we are not using any extra space
    void buildHeap(vector<int>& input) {
        int n = input.size(); // Since input is 0-indexed
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(i, n, input);
        }
    }    // Function to maintain the heap property
    // This function assumes that the subtrees rooted at leftChild and rightChild are already heaps
    void heapify(int index, int n, vector<int>& input) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < n && input[leftChild] > input[largest]) {
            largest = leftChild;
        }
        if (rightChild < n && input[rightChild] > input[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(input[index], input[largest]);
            heapify(largest, n, input);
        }
    }
    //heap sort function
    //tc= O(n log n) for heapsort
    //sc= O(1) for heapsort as we are not using any extra space
    void heapsort(vector<int>& input) {
       int size=input.size();

       while(size>1) {
           swap(input[0], input[size-1]);
           size--; 
           heapify(0, size, input);
       }

    }



};

int main() {
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);
    h.print(); // Output should be a max-heap representation of the inserted values
   
    vector<int> input = {10, 20, 5, 30, 15}; // Example input for building a heap (0-indexed)
    h.buildHeap(input);
    cout << "Heap after building from array: ";
    // Print the input array after heapify
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << endl;
    
    return 0;
}