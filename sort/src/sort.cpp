#include <iostream>
#include "sort/sort.hpp"
#include "sort/utils.hpp"


namespace sort{

	void selectionSort(float* A, int n){
		int smallest = 0;
		int i = 0;
		int j = 0;
		for (i = 0; i < n - 1; i++){
			smallest = i;
			for (j = i + 1; j < n; j++){
				if (A[j] < A[smallest]){
					smallest = j;
				}
			}
			swap(A,i,smallest);
		}
	}

	int split_qs(float* A, int i, int j){
		/***
		 * split for quicksort
		 * i,j are the endpoints
		 */
		int p = getRandomInt(i, j);

		while (i  < j) {

			while ( i < p && A[i] <= A[p]){
				i = i + 1;
			}

			while ( j > p && A[j] >= A[p]){
				j = j - 1;
			}

			swap(A, i, j);

			if (i == p){
				p = j;
			}
			else if (j == p){
				p = i;
			}
		}
		return p;
	}

	void quickSort(float* A, int i, int j){
		if (i < j){
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}

	void quickSort(float* A, int n){
		quickSort(A, 0, n - 1);
	}

	int  k_smallest(float* A, int i, int j, int k){
		int p = split_qs(A, i, j);
		int val = 0;
		if (k == p){
			val = A[p];
		}
		else if (k < p){
			val = k_smallest(A, i, p-1, k);
		}
		else{
			val = k_smallest(A, p+1, j, k);
		}
		return val;
	}

	int  k_smallest(float* A, int n, int k){
		return k_smallest(A, 0, n-1, k);
	}

	//CODIGO SORTS DESDE AQUÍ ABAJO:

	void insertionSort(float* A, int n){
		float elem = 0;
		int j=0;
		for (int i = 1; i < n; i++)
		{
			elem = A[i];
			j = i-1;
			while (j>=0 && elem<A[j])
			{
				A[j+1] = A[j];
				j= j-1;
			}
			A[j+1] = elem;
		
		}
		
	}

	void merge(float* A, int i, int j, int k){
		float* B = createRandomIntArray(j-i+1, 0, 0);
		//std::cout<<i<<","<<j<<","<<k<<std::endl;
		//std::cout<<j-i+1<<std::endl;
		//printArray(B, j-i+1);
		//setAll(B, j-i+1, 0);

		int q = 0;
		int p1 = i;
		int p2 = k+1;
		//std::cout<<"ESTE ES A ";
		//printArray(A, j-i+1);

		while (p1 <= k && p2<=j)
		{
			if (A[p1]<=A[p2])
			{
				B[q] = A[p1];
				//std::cout<<"entré"<<std::endl;
				p1++;
			}
			else
			{
				B[q] = A[p2];
				p2++;
			}
			
			q++;
		}

		//std::cout<<"\nESTE ES B ";
		//printArray(B, j-i+1);

		while (p1 <= k )
		{
			B[q] = A[p1];
			p1++;
			q++;
		}
		while (p2 <= j)
		{
			B[q] = A[p2];
			p2++;
			q++;
		}
		
		//std::cout<<"\nESTE ES B2 ";
		//printArray(B, j-i+1);
		
		for (int b = 0; b < j-i+1; b++)
		{
			A[i+b] = B[b];
		}
		
		
		//std::cout<<"\nESTE ES A2 ";
		//printArray(A, j-i+1);

		//deleteArray(B);
		
	}

	void mergeSort(float* A, int i, int j){
		int k = (i+j)/2;
		//std::cout<<"k vale: "<<k<<std::endl;
		
		if (i<j)
		{
			
			
			mergeSort(A, i, k);
			mergeSort(A, k+1, j);
			merge(A, i, j, k);
		}
		
	}

	void bucketSort(float* A, int M){
		eda::LinkedList bucket[M];

		for(int b = 0; b < M; b++){
			int elem = A[b];
			bucket[elem].insertFirst(b);
		}
		
		for (int i = 0; i < M; i++)
		{	
			std::cout<<i<<": ";
			bucket[i].print();
		}
		
		
		
		
	}

}












