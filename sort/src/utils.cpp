#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "sort/utils.hpp"

namespace sort{

	float* createArray(int n){
		return new float[n];
	}

	float* createRandomArray(int n){
		float* A = createArray(n);
		for (int i = 0; i < n; i++){
			A[i] =  std::rand() / static_cast<float>(RAND_MAX);
		}
		return A;
	}

	float* createRandomIntArray(int n, int minVal, int maxVal){
		float* A = createArray(n);
		for (int i = 0; i < n; i++){
			A[i] = getRandomInt(minVal, maxVal);
		}
		return A;
	}

	void deleteArray(float* A){
		delete[] A;
	}

	void printArray(float* A, int n){
		for (int i = 0; i < n; i++){
			std::cout<<A[i]<<" ";
		}
		std::cout<<std::endl;
	}

	void setAll(float* A, int n, float value){
		for (int i = 0; i < n; i++){
			A[i] =  value;
		}
	}

	void swap(float* A, int i, int j){
		float aux = A[i];
		A[i] = A[j];
		A[j] = aux;
	}

	int getRandomInt(int min, int max){
		float a = rand() / static_cast<float>(RAND_MAX);
		return static_cast<int>(a * (max - min) + min + 0.5);
	}

	int* linspace(int max, int n_parts){
		int* V = new int[n_parts];
		int part_size = max / n_parts;
		for(int i = 1; i <= n_parts; i++){
			V[i - 1] = part_size * i;
		}
		return V;
	}
}

namespace eda {


Node::Node(): data(-1), ptrNext(nullptr) {
}

Node::Node(int val, Node* next): data(val), ptrNext(next) {

}

void Node::setData(int _data){
	data = _data;
}

void Node::setNext(Node* next){
	ptrNext = next;
}

int Node::getData(){
	return data;
}
Node* Node::getNext(){
	return ptrNext;
}

void Node::print(){
	std::cout << data ;
}

Node::~Node() {

}


LinkedList::LinkedList(): head(nullptr) {

}

void LinkedList::insertFirst(int val){
	Node* node = new Node(val);
	if (head == nullptr) {
		head = node;
	}
	else{
		node->setNext(head);
		head = node;
	}
}

void LinkedList::insertLast(int val){
	Node* node = new Node(val);
	if (head == nullptr) {
		head = node;
	}
	else{
		Node* ptr = head;
		while(ptr->getNext() != nullptr){
			ptr = ptr->getNext();
		}
		ptr->setNext(node);
	}
}

void LinkedList::removeFirst(){
	Node* ptr = head;
	if (head != nullptr){
		head = head->getNext();
		delete ptr;
	}
}

void LinkedList::remove(int val){
	Node* ptr = head;
	Node* ptr_prev = nullptr;
	while (ptr != nullptr){
		if (ptr->getData() == val){
			//erase node
			if (ptr_prev == nullptr) {
				head = ptr->getNext();
				delete ptr;
				ptr = head;
			}
			else{
				ptr_prev->setNext(ptr->getNext());
				delete ptr;
				ptr = ptr_prev->getNext();
			}
		}
		else{
			ptr_prev = ptr;
			ptr = ptr->getNext();
		}
	}
}

void LinkedList::removeAll(){

	while (head != nullptr){
		removeFirst();
	}
}

Node* LinkedList::find(int val){
	Node* ptr = head;
	while ((ptr != nullptr) && (ptr->getData() != val)){
		ptr = ptr->getNext();
	}
	return ptr;
}

void LinkedList::print(){
	Node* ptr = head;
	while (ptr != nullptr) {
		ptr->print();
		std::cout << " -> ";
		ptr = ptr->getNext();
	}
	std::cout << std::endl;
}

LinkedList::~LinkedList() {
	removeAll();
}


}
