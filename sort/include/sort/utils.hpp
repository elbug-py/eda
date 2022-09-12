#ifndef SORT_UTILS_HPP
#define SORT_UTILS_HPP

namespace sort{
	float* createArray(int n);
	float* createRandomArray(int n);
	float* createRandomIntArray(int n, int minVal = 0, int maxVal = 100);
	void deleteArray(float* A);
	void printArray(float* A, int n);
	void setAll(float* A, int n, float value);
	void swap(float* A, int i, int j);
	int getRandomInt(int min, int max);
	int* linspace(int max, int n_parts);
}

namespace eda {

class Node {
private:
	int data;
	Node* ptrNext;
public:
	Node();
	Node(int _data, Node* next = nullptr);
	void setData(int _data);
	void setNext(Node* _next);
	int getData();
	Node* getNext();
	void print();
	virtual ~Node();
	};

class LinkedList {
private:
	Node* head;

public:
	LinkedList();
	void insertLast(int val);
	void insertFirst(int val);
	void removeFirst();
	void remove(int val);
	void removeAll();
	Node* find(int val);
	void print();
	virtual ~LinkedList();
	};


}

#endif
