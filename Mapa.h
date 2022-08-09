#pragma once
#include <iostream>
#include <functional>
#include <set>
using namespace std;

//Un mapa guarda elementos en pares, con un valor clave y uno asociado 
//no hay dos valores que puedan tener el mismo elemento clave

template<class G> //class G
class Mapa {
	G* mapa;
	int size;
	int pos;

public:

	//Mapa(int size = 10) : size(size), pos(-1) { mapa = new G[size]; }
	Mapa() : size(10), pos(0) { mapa = new G[size]; }
	~Mapa() {}


	bool isFull() {
		return (pos == size);
	}

	void insert_start(int key, G value) {//2
		mapa[key] = value;//1
	}

	void insert(int key, G value, function<bool(G)> empty) { //3
		if (empty(mapa[key]) && pos < size) {//4
			pos++;//2
			mapa[key] = value;//1
		}
	}

	void print(function<void(G)> imprime) { //1
		for (int i = 0; i < size; i++) { //1 + n(3 + INTERNA) 
			imprime(mapa[i]); //2
		}
	}

	void print_pos(function<void(G)> imprime, int pos) { // 2
		imprime(mapa[pos]); //2
	}

};