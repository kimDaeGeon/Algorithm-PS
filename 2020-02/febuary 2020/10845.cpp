#include<iostream>
#include<string>
using namespace std;

template<typename T> class Queue {
private:
	T* mem;
	int size;
	int capacity;
	int head, tail;
public:
	Queue(int capacity);
	void push(T x);
	T pop();

	int getSize();
	bool isEmpty();
	T front();
	T back();
};

template<typename T> inline Queue<T>::Queue(int capacity) {
	this->capacity = capacity;
	mem = new T[capacity];

	this->size = 0;
	this->head = -1;
	this->tail = -1;
}
template<typename T> inline void Queue<T>::push(T x) {
	size++;
	tail = (tail + 1) % capacity;
	mem[tail] = x;
}
template<typename T> inline T Queue<T>::pop() {
	if (isEmpty()) return -1;
	size--;
	head = (head + 1) % capacity;
	return mem[head];
}
template<typename T> inline int Queue<T>::getSize() {
	return this->size;
}
template<typename T> bool Queue<T>::isEmpty() {
	return size == 0;
}
template<typename T> inline T Queue<T>::front() {
	if (isEmpty()) return -1;
	return mem[head + 1];
}
template<typename T> inline T Queue<T>::back() {
	if (isEmpty()) return -1;
	return mem[tail];
}



int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);
	
	Queue<int> queue(10000);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;

		if (command == "push") {
			int push;
			cin >> push;
			queue.push(push);
		}
		else if (command == "pop") {
			cout << queue.pop() << endl;
		}
		else if (command == "size") {
			cout << queue.getSize() << endl;
		}
		else if (command == "empty") {
			cout << queue.isEmpty() << endl;
		}
		else if (command == "front") {
			cout << queue.front() << endl;
		}
		else if (command == "back") {
			cout << queue.back() << endl;
		}
	}

	return 0;
}