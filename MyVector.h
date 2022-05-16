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
	long size;
	long pos;

public:

	MyVector(long size = 8) : size(size), pos(-1) { arr = new G[size];}
	~MyVector() {}

	unsigned long getsize() { return size; }
	long getpos() { return pos; }
	G* getarr() { return arr; }

	void swap(G* a, G* b) {
		G temp = *a;
		*a = *b;
		*b = temp;
	}
	void push_back(G elemento) {
		if(pos<size)arr[++pos] = elemento;
	}

	void print(function<void(G)> mostrar) { 
		for (int i = 0; i <= pos; i++) mostrar(arr[i]);
    }

	void modificar(G obj, long pos) {
		arr[pos] = obj;
	}

	void desordenar(int i) { 
		if (i <= 0) return;
		srand(time(NULL));
		int j = 1 + rand() % pos - 1;
		swap(&arr[i], &arr[j]);
		desordenar(i - 1);
	}

};