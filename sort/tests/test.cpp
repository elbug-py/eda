
#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <chrono>
#include <iostream>
#include <ctime>

long getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> t1,
		std::chrono::time_point<std::chrono::high_resolution_clock> t2){
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	return static_cast<long>(int_ms.count());
}

void testSort(int max_size, int n_sizes){
	int* sizes = sort::linspace(max_size, n_sizes);
	float* A = nullptr;
	int n = 0;
	for (int i = 0; i < n_sizes; i++){
		n = sizes[i];
		A = sort::createRandomIntArray(n, 0, 100);
		auto start = std::chrono::high_resolution_clock::now();
		//change the sort method here
		sort::quickSort(A, n);
		//
		auto end = std::chrono::high_resolution_clock::now();
		long elapsed =  getElapsedTime(start, end);
		sort::deleteArray(A);
		std::cout << " [" << n << "," << elapsed << "]" << std::endl;
	}
	delete[] sizes;
}


//int main(int nargs, char** nvargs){
//	int n_sizes = 10;
//	int max_size = 100000;
//	testSort(max_size, n_sizes);
//	return 0;
//}


int main(int nargs, char** args){

	std::srand(std::time(nullptr));
	int n = 10;
	
	
	//QUICKSORT
	float* A = sort::createRandomArray(n);
	//sort::printArray(A, n);
	auto start = std::chrono::high_resolution_clock::now();
	sort::quickSort(A, n);
	//sort::printArray(A, n);
	sort::deleteArray(A);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout<<" Elapsed : " << getElapsedTime(start, end) << std::endl;
	
	
	//SELECTION SORT
	//float* B = sort::createRandomArray(n);
	//sort::printArray(B, n);
	//start = std::chrono::high_resolution_clock::now();
	//sort::selectionSort(B, n);
	//sort::printArray(B, n);
	//sort::deleteArray(B);
	//end = std::chrono::high_resolution_clock::now();
	//std::cout<<" Elapsed : " << getElapsedTime(start, end) << std::endl;
	
	
	//INSERTION SORT
	//float* C = sort::createRandomArray(n);
	//sort::printArray(C, n);
	//start = std::chrono::high_resolution_clock::now();
	//sort::insertionSort(C, n);
	//sort::printArray(C, n);
	//sort::deleteArray(C);
	//end = std::chrono::high_resolution_clock::now();
	//std::cout<<" Elapsed : " << getElapsedTime(start, end) << std::endl;
	
	
	//MERGESORT
	//float* D = sort::createRandomArray(n);
	//sort::printArray(D, n);
	//start = std::chrono::high_resolution_clock::now();
	//sort::mergeSort(D, 0, n);
	//sort::printArray(D, n+1);
	//sort::deleteArray(D);
	//end = std::chrono::high_resolution_clock::now();
	//std::cout<<" Elapsed : " << getElapsedTime(start, end) << std::endl;
	

	//RADIXSORT
	float* E = sort::createRandomIntArray(n, 0, 9);
	sort::printArray(E, n);
	sort::bucketSort(E, n);
	return 0;

}
