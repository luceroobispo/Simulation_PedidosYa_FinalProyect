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

	void push_back(Generico e) { //1
		++posicion; //2
		Nodo<Generico>* nuevo = new Nodo<Generico>(e); //2
		nuevo->setpos(posicion); //1
		if (inicio == nullptr) { //1
			inicio = fin = nuevo; //2
		}
		else {
			fin->setsig(nuevo); //1
			nuevo->setsig(nullptr);//1
			nuevo->setatras(fin);//1
			fin = nuevo;//1
		}
		cantidad++;//2

	}
	void print(function<void(Generico)> imprime) { //1
		Nodo<Generico>* aux = inicio; //2
		while (aux != nullptr) {//n (1 + INTERNA)
			imprime(aux->getelemento()); //2
			aux = aux->getsig();//2
		}
	}
	Generico obtenerobj_pos(short pos) { //1
		Nodo<Generico>* aux = inicio; //2
		while (aux != nullptr) { //n (1 + INTERNA)
			if (aux->getpos() == pos) { // 2
				return aux->getelemento(); //2
			}
			aux = aux->getsig(); //2
		}
	}

	void swap(Nodo<Generico>* a, Nodo<Generico>* b) { //2
		Generico temp = a->getelemento(); //3
		a->setelemento(b->getelemento()); //2
		b->setelemento(temp);//1
	}

	void ordenarj(Nodo<Generico>* j, Nodo<Generico>* i, function<bool(Nodo<Generico>*, Nodo<Generico>*)> condicion) { //3
		if (j == nullptr)return; //1
		if (condicion(j,i)) { //1
			swap(j,i); //8
		}
		j = j->getsig(); //2
		ordenarj(j, i,condicion);//logn
	}

	void ordenari(Nodo<Generico>* i, function<bool(Nodo<Generico>*, Nodo<Generico>*)> condicion) { //2
		if (i == nullptr) return; //1
		Nodo<Generico>* j = i->getsig();//3
		ordenarj(j, i,condicion); //15  + logn
		i = i->getsig(); //2
		ordenari(i,condicion);//logn
	}

	void ordenar(Nodo<Generico>* _inicio, function<bool(Nodo<Generico>*, Nodo<Generico>*)> condicion) { //2       RECURSIVIDAD
		Nodo<Generico>* i = _inicio; //2
		ordenari(i, condicion);// 23 + 2logn
	}

	Nodo<Generico>* reverse(Nodo<Generico>* inicio) { //1
		Nodo<Generico>* nodo1 = inicio; //2
		Nodo<Generico>* nodo2 = nodo1->getsig();//3

		nodo1->setsig(nullptr); //1
		nodo1->setatras(nodo2);//1
		while (nodo2!=nullptr) {//n(1 + INTERNA)
			nodo2->setatras(nodo2->getsig());//2
			nodo2->setsig(nodo1);//1
			nodo1 = nodo2;//1
			nodo2 = nodo2->getatras();//2
		}
		inicio = nodo1;//1
		return inicio;//1
	}

	Nodo<Generico>* deleteFirstNodo(Nodo<Generico>* inicio, function<bool(Nodo<Generico>*)>  condicion) { //2
		Nodo<Generico>* aux = inicio; //2
		if (condicion(aux)) {//1
			inicio = inicio->getsig();//2
			delete aux;//1
			aux = nullptr;//1
			inicio->setatras(nullptr);//1
		}
		return inicio;//1
	}
	
	void print_nom(function<bool(Nodo<Generico>*)> condicion, function<void(Generico)> imprime) { //2
		Nodo<Generico>* aux = inicio;//2
		while (aux != NULL) { //n(1 + INTERNA)
			if (condicion(aux)) { //1
				imprime(aux->getelemento());//2
			}
			aux = aux->getsig();//2
		}
	}

	void Encontrar_pos_imp(int posicion, function<void(Generico)> imprime) {//2
		Nodo<Generico>* aux = fin;//2
		bool existe = false;//2
		while (aux != NULL && existe != true) {//n(3 + INTERNA)
			if (aux->getpos() == posicion) { //2
				imprime(aux->getelemento()); //2
				existe = true;//1
			}
			aux = aux->getatras();//2
		}
	}

	Nodo<Generico>* Elim_UltimoNodo(Nodo<Generico>* f, function<bool(Nodo<Generico>*)> condicion) { //2
		Nodo<Generico>* aux = fin; //2
		if (condicion(aux)) { //1
			fin = fin->getatras();//2
			delete aux; //1
			aux = nullptr; //1
			fin->setsig(nullptr);//1
		}
		return inicio;//1
	}
};
