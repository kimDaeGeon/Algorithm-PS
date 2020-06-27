#include<bits/stdc++.h>
using namespace std;

template<typename T> class MaxHeap{
    private:
    vector<T> heap;
    
    public:
    void insertNode(T data);
    int deleteNode();
};

template<typename T> void MaxHeap<T>::insertNode(T data){
    if(heap.empty()){
        heap.push_back(data);
        return;
    }

    heap.push_back(data);
    int currentNode = heap.size();
    int parentNode = currentNode/2;

    while(parentNode > 0){
        if(heap[parentNode-1] < heap[currentNode-1]){
            std::swap(heap[parentNode-1],heap[currentNode-1]);
            currentNode = parentNode;
            parentNode = currentNode/2;
        }
        else{
            break;
        }
    }
}

template<typename T> int MaxHeap<T>::deleteNode(){
    if(heap.empty()){
        return 0;
    }

    int max = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    int currentNode = 1;
    int leftNode = currentNode*2;
    int rightNode = currentNode*2+1;

    while(leftNode <= heap.size()){
        if(rightNode <= heap.size()){
            if(heap[leftNode-1] < heap[rightNode-1]){
                if(heap[leftNode-1] < heap[rightNode-1]){
                    if(heap[rightNode-1] < heap[currentNode-1]) break;

                    std::swap(heap[currentNode-1], heap[rightNode-1]);
                    currentNode = rightNode;
                    leftNode = currentNode*2;
                    rightNode = currentNode*2+1;
                }
                else{
                    if(heap[leftNode-1] < heap[currentNode-1]) break;
                    
                    std::swap(heap[currentNode-1],heap[leftNode-1]);
                    currentNode = leftNode;
                    leftNode = currentNode * 2;
                    rightNode = currentNode * 2 + 1;
                }
            }
        }
        else{
            if(heap[leftNode-1] < heap[currentNode-1]) break;

            std::swap(heap[currentNode-1], heap[leftNode-1]);
            currentNode = leftNode;
            leftNode = currentNode * 2;
            rightNode = currentNode * 2 + 1;
        }
    }

    return max;
}



//main

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    MaxHeap<int> maxheap;

    int size;
    cin >> size;

    for(int i = 0 ; i < size; i++){
        int data;
        cin >> data;

        if(data == 0 ){
            cout << maxheap.deleteNode() << '\n';
        }
        else{
            maxheap.insertNode(data);
        }
    }


    return 0;
}