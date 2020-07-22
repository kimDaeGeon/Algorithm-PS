#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
	vector<int> heap = { 0 };

public:
	void push(int data) {
		// append in heap
		heap.push_back(data);

		int child = heap.size()-1;
		int parent = child / 2;
		while (child > 1 && heap[parent] < heap[child]) {
			std::swap(heap[parent], heap[child]);
			child = parent;
			parent = child / 2;
		}
	}

	int pop() {
		if (heap.size() == 1) {
			return 0;
		}

		int root = heap[1];

		std::swap(heap[1], heap.back());
		
		int parent = 1;
		int child = parent * 2;
		if (child + 1 <= heap.size()-1) {
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}

		while (child <= heap.size()-1 && heap[parent] < heap[child]) {
			std::swap(heap[parent], heap[child]);

			parent = child;
			child = child * 2;
			if (child + 1 <= heap.size()-1) {
				child = (heap[child] > heap[child + 1]) ? child : child + 1;
			}
		}

		return root;
	}
};

int main() {
	vector<int> output;
	MaxHeap heap;

	int op_size;
	cin >> op_size;

	while (op_size--) {
		int n;
		cin >> n;

		// push
		if (n != 0) {
			heap.push(n);
		}
		else {
			cout << heap.pop() << '\n';
		}
	}

	return 0;
}