#pragma once
#include<iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

template<typename T>
class Edge {
private:
	T peso; //valor entre ambos vertices
	int destinoID; // Vertice ID destino
public:
	Edge() {}
	Edge(int destinoID, T peso) {
		this->destinoID = destinoID;
		this->peso = peso;
	}
	~Edge() {}

	void setdestinoID(int destinoID) { this->destinoID = destinoID; }
	void setPeso(T peso) { this->peso = peso; }

	int getdestinoID() { return destinoID; }
	T getPeso() { return peso; }
};

template<typename T, typename T2>
class Vertice {
private:
	int ID;
	T2 valor;
	list<Edge<T>> ListaEdge;
public:
	Vertice() {}
	Vertice(T2 valor, int ID) {
		this->valor = valor;
		this->ID = ID;
	}
	~Vertice() {}
	void setID(int ID) { this->ID = ID; }
	void setvalor(T2 valor) { this->valor = valor; }

	int getID() { return ID; }
	T2 getvalor() { return valor; }
	list<Edge<T>> getListaEdge() { return ListaEdge; }

	void print() {
		cout << "[";
		for (auto it = ListaEdge.begin(); it != ListaEdge.end(); it++) {
			cout << it->getdestinoID() << "(" << it->getPeso() << ") --> ";
		}
		cout << "]";
		cout << endl;
	}

	void addEdgeToEdgelist(int vid, T peso) {
		ListaEdge.push_back(Edge<T>(vid, peso));
		cout<<"Edge entre "<<ID <<" y "<<vid <<" agregado exitosamente "<<endl; 	
	}
};

template<typename T, typename T2>
class Grafo {
private:
	vector<Vertice<T,T2>> vertices;
public:
	Grafo() {}
	~Grafo() {}

	bool verificarSiVerticeExistePorID(int vid) { //1
		bool band = false; //2
		for (int i = 0; i < vertices.size(); i++) { // 1 + n (2 + 2 + INTERNA)
			if (vertices.at(i).getID() == vid) { //3
				band = true; //1
				break; //1
			}
		}
		return band; //1
	}

	bool verificarSiEdgeExistePorId(int vid1, int vid2) {//2
		Vertice<T,T2> v = getVerticePorID(vid1); //3
		list<Edge<T>> e; //1
		bool band = false; //2
		e = v.getListaEdge(); //2
		for (auto it = e.begin(); it != e.end(); it++) { //2 + n(2 + 2 + INTERNA)
			if (it->getdestinoID() == vid2) { //2
				band = true; //1
				break; //1
			}
		}
		return band;//1
	}

	void addVertice(Vertice<T,T2> nuevoVertice) { //1
		bool check = verificarSiVerticeExistePorID(nuevoVertice.getID()); // 2 + 5 + 9n + 1
		if (check == true) { //1
			cout << "Ya existe el vertice con este ID" << endl;//1
		}
		else {
			vertices.push_back(nuevoVertice);//1
			cout << "Nuevo Vertice agregado exitosamente" << endl;//1
		}
	}

	Vertice<T,T2> getVerticePorID(int vid) { //1
		Vertice<T,T2> temp; //1
		for (int i = 0; i < vertices.size(); i++) { //1 + n(2 + 2 + INTERNA)
			temp = vertices.at(i); //2
			if (temp.getID() == vid) { //2
				return temp; //1
			}
		}
		return temp; //1
	}
	
	void addEdgePorID(int V1, int V2, T peso) { //3
		bool check1 = verificarSiVerticeExistePorID(V1); // 2 + 5 + 9n
		bool check2 = verificarSiVerticeExistePorID(V2); // 2 + 5 + 9n

		bool check3 = verificarSiEdgeExistePorId(V1, V2); // 2 + 15 + 17n
		if ((check1 ==true)&& (check2 == true)) { //2
			if (check3 == true) { //1
				cout << "\nEdge entre " << getVerticePorID(V1).getvalor() << "(" << V1 << ") y " 
					<< getVerticePorID(V2).getvalor() << "(" << V1 << ") Ya existe" << endl; //1
			}
			else {
				for (int i = 0; i < vertices.size(); i++) { //2 + n(2 + 2 + INTERNA)
					if (vertices.at(i).getID() == V1) { //3
						vertices.at(i).addEdgeToEdgelist(V2, peso); //1 + 3
					}
					else if (vertices.at(i).getID() == V2) { //3
						vertices.at(i).addEdgeToEdgelist(V1, peso); //1 + 3
					}
				}
			}
		}
		else {
			cout << "\nNo existe vertice(s)"; //1
		}
	}

	void print() {
		for (int i = 0; i < vertices.size(); i++) { // 1 + n(2 + 2 + INTERNA)
			Vertice<T,T2> temp; //1
			temp = vertices.at(i); //2
			cout << temp.getvalor() << " (" << temp.getID() << ") --> "; //1
			temp.print();//4+7n
		}
	}
};