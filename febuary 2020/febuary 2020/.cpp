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
	Queue(int size);

	void push(T x);
	T pop();
	int getSize();
	bool isEmpty();
	T front();
	T back();
};

template<typename T> inline Queue<T>::Queue(int capacity) {
	size = 0;
	head = -1;
	tail = -1;
	this->capacity = capacity;
	mem = new int[size];
}
template<typename T> inline void Queue<T>::push(T x) {
	tail = (tail + 1) % capacity;
	mem[tail] = x;
	size++;
}
template<typename T> inline T Queue<T>::pop() {
	if (getSize() == 0) {
		return -1;
	}
	T temp = mem[head];
	head = (head + 1) % capacity;
	size--;
	return temp;
}
template<typename T> inline int Queue<T>::getSize() {
	return this->size;
}
template<typename T> inline bool Queue<T>::isEmpty() {
	return size == 0;
}
template<typename T> inline T Queue<T>::front() {
	return mem[head];
}
template<typename T> inline T Queue<T>::back() {
	return mem[tail];
}

int main() {
	Queue<int> queue(10000);

	int n;
	cin >> n;

	while (n--) {
		string command;
		cin >> command;

		if (command == "push") {
			int x; cin >> x;
			queue.push(x);
			cout << x << endl;
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