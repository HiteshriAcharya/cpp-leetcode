#include <iostream>
#include <vector>
using namespace std;

class Heap{
    vector<int> vec; //CBT && Max Heap
public:

    void push(int val){

        //Step 1

        vec.push_back(val);

        //Step 2: Fix the heap
        int x = vec.size()-1;
        int parIdx = (x-1)/2;

        while(parIdx >= 0 && vec[x] > vec[parIdx]){  //O(log n)
            swap(vec[x], vec[parIdx]);
            x = parIdx;
            parIdx = (x-1)/2;
        }

    }

    void heapify(int parIdx){

        if(parIdx >= vec.size()) return;

        int leftChild = (parIdx*2) + 1;
        int rightChild = (parIdx*2) + 2;

        int maxIdx = parIdx; // Default

        if(leftChild <= vec.size()-1 && vec[leftChild] > vec[parIdx]){
            maxIdx = leftChild;
        }

        // Must be another if statement

        if(rightChild <= vec.size()-1 && vec[rightChild] > vec[parIdx]){
            maxIdx = rightChild;
        }

        swap(vec[parIdx], vec[maxIdx]);
        if(parIdx != maxIdx) heapify(parIdx);
    }

    void pop(){

        //Step 1
        swap(vec[0], vec[vec.size()-1]);

        //Step 2
        vec.pop_back();

        //Step 3
        heapify(0); //O(log n)

    }

    int top(){
        return vec[0]; // highest priority element
    }

    bool empty(){
        return vec.size() == 0;
    }
};

int main(){

    Heap maxHeap;

    maxHeap.push(50);
    maxHeap.push(10);
    maxHeap.push(100);
    maxHeap.push(500);
    maxHeap.push(9);

    while(!maxHeap.empty()){
        cout << maxHeap.top() << endl;
        maxHeap.pop();
    }
}