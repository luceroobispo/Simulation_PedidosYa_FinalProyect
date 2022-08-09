#pragma once
#include <iostream>
#include <functional>

using namespace std;

template<class T>
class NodoC {
private:
	T dato;
	NodoC<T>* siguiente;
	int pos;
public:
	NodoC(T v, NodoC<T>* sig = nullptr) {
		dato = v;
		siguiente = sig;
		pos = 0;
	}
	~NodoC() {}

	void setdato(T dato) { this->dato = dato; }
	void setpos(int pos) { this->pos = pos; }
	void setsiguiente(NodoC<T>* siguiente) { this->siguiente = siguiente; }
	T getdato() { return dato; }
	int getpos() { return pos; }
	NodoC<T>* getsiguiente() { return siguiente; }
};

template<class T>
class Cola {
private:
	NodoC<T>* inicio;
	NodoC<T>* fin;
	int n;
	int cont;
public:
	Cola() {
		this->inicio = NULL;
		this->fin = NULL;
		cont = 0;
		n = 10;
	}
	~Cola() {}

	int getsize() { return cont; }
	NodoC<T>* getinicio() { return inicio; }
	NodoC<T>* getfin() { return fin; }
	void setn(int n) { this->n = n; }

	void enqueue(T v) { //1
		NodoC<T>* nodo = new NodoC<T>(v);//2
		if (isFull() == false) { //1
			if (esVacia()) { //1
				inicio = nodo; //1
				fin = inicio; //1
			}
			else {
				nodo->setpos(cont);//1
				fin->setsiguiente(nodo);//1
				fin = nodo;//1
			}
			cont++;//2
			nodo = NULL; //1
		}
	};

	T dequeue() {
		T dato = inicio->getdato(); //2

		if (inicio == fin) { //1
			inicio = NULL; //1
			fin = NULL; //1
		}
		else {
			inicio = inicio->getsiguiente(); //2
		}
		cont--; //2
		return dato; //1
	}

	void print(function<void(T)> imprime, NodoC<T>* aux) { //2
		if (aux == nullptr) return; //1
		imprime(aux->getdato()); //2
		print(imprime, aux->getsiguiente()); //logn + 1
	}

	bool esVacia() {
		return (inicio == NULL); //1
	}

	bool isFull() {
		return (cont == n); //1
	}

	NodoC<T>* peek() {
		if (esVacia()) //1
		{
			cout << "La cola esta vacia\n"; //1
			exit(EXIT_FAILURE); //1
		}
		return inicio; //1
	}
	
	void searchNodoByCondition(function<void(T)> imprime, function<bool(T)> condicion) { //2
		NodoC<T>* actual = inicio; //2
		bool encontrado = false; //2
		if (inicio != NULL) {//1
			while (actual != NULL && encontrado != true) { // n(3 + INTERNA)

				if (condicion(actual->getdato())) { // 2
					imprime(actual->getdato()); //2
					encontrado = true; //1
				}
				actual = actual->getsiguiente(); //2
			}
			if (!encontrado) { //1
				cout << "\nNo se encontro elementos en base a ese requerimiento"; //1
			}
		}
		else {
			cout << "\nNo hay datos"; //1
		}
	}

	NodoC<T>* getNodoByPos(int pos) {  //1
		NodoC<T>* actual = inicio;//2
		bool encontrado = false;//2
		if (inicio != NULL) {//1
			while (actual != NULL && encontrado != true) {//n(3 + INTERNA)
				if (actual->getpos() == pos) { encontrado = true; break; } //4
				actual = actual->getsiguiente();//2
			}
			if (!encontrado) { cout << "\nNo se encontro el nodo en esa posicion"; }//2
		}
		else {
			cout << "\nNo hay datos";//1
		}
		return actual;//1
	}

};