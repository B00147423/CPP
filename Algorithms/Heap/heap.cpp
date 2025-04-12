#include <iostream>
#include <vector>
#include <climits>  // Include for INT_MIN

using namespace std;

class Heap {
    private:
        vector<int> heap;

        int leftChild(int index) {
            return 2 * index + 1;
        }

        int rightChild(int index) {
            return 2 * index + 2;
        }

        int parent(int index) {
            return (index - 1) / 2;
        }

        void swap(int index1, int index2) {
            int temp = heap[index1];
            heap[index1] = heap[index2];
            heap[index2] = temp;
        }

        void sinkDown(int index) {
            int maxIndex = index;
            while (true) {
                int leftIndex = leftChild(index);
                int rightIndex = rightChild(index);

                if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex]) {
                    maxIndex = leftIndex;
                }

                if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]) {
                    maxIndex = rightIndex;
                }

                if (maxIndex != index) {
                    swap(index, maxIndex);
                    index = maxIndex;
                } else {
                    return;
                }
            }
        }

    public:
        void insert(int value) {
            heap.push_back(value);
            int current = heap.size() - 1;

            while (current > 0 && heap[current] > heap[parent(current)]) {
                swap(current, parent(current));
                current = parent(current);
            }
        }

        int remove() {
            if (heap.empty()) return INT_MIN;
            
            int minValue = heap[0];  // Store the minimum value (the root of the heap)
            heap[0] = heap.back();   // Move the last element in the heap to the root (index 0)
            heap.pop_back();         // Remove the last element from the heap
            
            sinkDown(0);  // Readjust the heap by sinking down the new root element
            
            return minValue;  // Return the removed minimum value
        }
};

