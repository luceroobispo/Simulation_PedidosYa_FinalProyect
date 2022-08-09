#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
using namespace std;

template<class G>
class MyVector {
private:
	G* arr;
	int size;
	int pos;

public:

	MyVector(int size = 8) : size(size), pos(-1) { arr = new G[size];}
	~MyVector() {}

	int getsize() { return size; }
	int getpos() { return pos; }
	G* getarr() { return arr; }

	void swap(G* a, G* b) { //2
		G temp = *a; //2
		*a = *b; //1
		*b = temp; //1
	}
	void push_back(G elemento) { //1
		if(pos<size) //1
			arr[++pos] = elemento; //4
	}

	void print(function<void(G)> mostrar) { //1 
		for (int i = 0; i <= pos; i++) // 1 + 2 + n(INTERNA + 2)
			mostrar(arr[i]); //2
    }

	void modificar(G obj, int pos) { //2
		arr[pos] = obj; //2
	}

	void desordenar(int i) { //1
		if (i <= 0) return; //2
		srand(time(NULL)); //2
		int j = 1 + rand() % pos - 1; //5
		swap(&arr[i], &arr[j]); //6
		i = i - 1; //2
		desordenar(i); // logn
	}

	void Merge(G* A1, G* A2, G* A, int n, function<bool(G, G)> condicion) {
		int i = 0, j = 0, k = 0;
		int mitad = n / 2;
		while (i < mitad && j < n - mitad) {
			if (condicion(A1[i],A2[j])) {
				A[k] = A1[i];
				i++; k++;
			}
			else {
				A[k] = A2[j];
				j++; k++;
			}
		}
		while (i < mitad) {
			A[k] = A1[i];
			i++; k++;
		}
		while (j < n - mitad) {
			A[k] = A2[j];
			j++; k++;
		}
	}

	void mergeSort(G* A, int n, function<bool(G, G)> condicion) {
		if (n > 1) {
			int mitad = n / 2;
			G* A1 = new G[mitad];
			G* A2 = new G[n - mitad];

			for (int i = 0; i < mitad; i++) {
				A1[i]= A[i];
			}
			for (int i = mitad; i < n; i++) {
				A2[i - mitad]= A[i];
			}
			mergeSort(A1, mitad, condicion);
			mergeSort(A2, n - mitad, condicion);
			Merge(A1, A2, A, n, condicion);
		}
	}
};