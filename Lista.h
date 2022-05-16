#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include <functional>
using namespace std;
template<class Generico>
class Nodo {
private:
	Generico elemento;
	Nodo<Generico>* sig;
	Nodo<Generico>* atras;
	int pos;
public:
	Nodo(Generico e) {
		elemento = e;
		sig = nullptr;
		atras = nullptr;
		pos = 0;
	}
	~Nodo() {}

	Nodo<Generico>* getsig() { return sig; }
	Nodo<Generico>* getatras() { return atras; }

	void setsig(Nodo<Generico>* sig) { this->sig = sig; }
	void setelemento(Generico elemento) { this->elemento = elemento; }
	void setatras(Nodo<Generico>* atras) { this->atras = atras; }

	Generico getelemento() { return elemento; }
	int getpos() { return pos; }
	void setpos(int pos) { this->pos = pos; }
};

template<class Generico>
class Lista {
	Nodo<Generico>* inicio;
	Nodo<Generico>* fin;
	size_t cantidad;
	int posicion;
public:
	Lista() {
		inicio = fin = nullptr;
		cantidad = 0;
		posicion = 0;
	}

	Nodo<Generico>* getinicio() { return inicio; }
	Nodo<Generico>* getfin() { return fin; }
	size_t getcantidad() { return cantidad; }
	void setcantidad(size_t cantidad) { this->cantidad = cantidad; }
	void setinicio(Nodo<Generico>* inicio) { this->inicio = inicio; }
	void setfin(Nodo<Generico>* fin) { this->fin = fin; }
	int getposicion() { return posicion; }

	void push_back(Generico e) {
		++posicion;
		Nodo<Generico>* nuevo = new Nodo<Generico>(e);
		nuevo->setpos(posicion);
		if (inicio == nullptr) {
			inicio = fin = nuevo;
		}//cantidad==0
		else {
			fin->setsig(nuevo);
			nuevo->setsig(nullptr);
			nuevo->setatras(fin);
			fin = nuevo;
		}
		cantidad++;

	}
	void print(function<void(Generico)> imprime) {
		Nodo<Generico>* aux = inicio;
		while (aux != nullptr) {
			imprime(aux->getelemento());
			aux = aux->getsig();
		}
	}
	Generico obtenerobj_pos(short pos) {
		Nodo<Generico>* aux = inicio;
		while (aux != nullptr) {
			if (aux->getpos() == pos) { return aux->getelemento(); }
			aux = aux->getsig();
		}
	}

	void swap(Nodo<Generico>* a, Nodo<Generico>* b) {
		Generico temp = a->getelemento();
		a->setelemento(b->getelemento());
		b->setelemento(temp);
	}

	void ordenarj(Nodo<Generico>* j, Nodo<Generico>* i, function<bool(Nodo<Generico>*, Nodo<Generico>*)> condicion) {
		if (j == nullptr)return;
		if (condicion(j,i)) {
			swap(j,i);
		}
		j = j->getsig();
		ordenarj(j, i,condicion);
	}

	void ordenari(Nodo<Generico>* i, function<bool(Nodo<Generico>*, Nodo<Generico>*)> condicion) {
		if (i == nullptr) return;
		Nodo<Generico>* j = i->getsig();
		ordenarj(j, i,condicion);
		i = i->getsig();
		ordenari(i,condicion);
	}

	void ordenar(Nodo<Generico>* _inicio, function<bool(Nodo<Generico>*, Nodo<Generico>*)> condicion) { //RECURSIVIDAD
		Nodo<Generico>* i = _inicio;
		ordenari(i, condicion);
	}

	Nodo<Generico>* reverse(Nodo<Generico>* inicio) {
		Nodo<Generico>* nodo1 = inicio;
		Nodo<Generico>* nodo2 = nodo1->getsig();

		nodo1->setsig(nullptr);
		nodo1->setatras(nodo2);
		while (nodo2!=nullptr) {
			nodo2->setatras(nodo2->getsig());
			nodo2->setsig(nodo1);
			nodo1 = nodo2;
			nodo2 = nodo2->getatras();
		}
		inicio = nodo1;
		return inicio;
	}

	Nodo<Generico>* deleteFirstNodo(Nodo<Generico>* inicio, function<bool(Nodo<Generico>*)>  condicion) {
		Nodo<Generico>* aux = inicio;
		if (condicion(aux)) {
			inicio = inicio->getsig();
			delete aux;
			aux = nullptr;
			inicio->setatras(nullptr);
		}
		return inicio;
	}
	
	void print_nom(function<bool(Nodo<Generico>*)> condicion, function<void(Generico)> imprime) {
		Nodo<Generico>* aux = inicio;
		while (aux != NULL) {
			if (condicion(aux)) {
				imprime(aux->getelemento());
			}
			aux = aux->getsig();
		}
	}

	void Encontrar_pos_imp(int posicion, function<void(Generico)> imprime) {
		Nodo<Generico>* aux = fin;
		bool existe = false;
		while (aux != NULL && existe != true) {
			if (aux->getpos() == posicion) {
				imprime(aux->getelemento());
				existe = true;
			}
			aux = aux->getatras();
		}
	}

	Nodo<Generico>* Elim_UltimoNodo(Nodo<Generico>* f, function<bool(Nodo<Generico>*)> condicion) {
		Nodo<Generico>* aux = fin;
		if (condicion(aux)) {
			fin = fin->getatras();
			delete aux;
			aux = nullptr;
			fin->setsig(nullptr);
		}
		return inicio;
	}
};
