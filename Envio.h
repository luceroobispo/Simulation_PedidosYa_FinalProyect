#pragma once
#include <iostream>
#include <string>
#include "Grafo.h"
#include "Pila.h"
using namespace std;

class Envio {
private:
	string nenvio; //nombre del objeto que va a enviar
	string preceptor; //nombre de la persona que va a recibir el objeto
	string direccion; //direccion de la entrega
	double km; //kilometro del lugar en donde estas hasta la direccion
	double precio;
public:
	Envio(string nenvio = "", string preceptor = "", string direccion = "", double km = 0.0, double precio = 0.0)
		:nenvio(nenvio), preceptor(preceptor), direccion(direccion), km(km), precio(precio) {}
	~Envio() {}
	//set
	void setnenvio(string nenvio) { this->nenvio = nenvio; }
	void setpreceptor(string preceptor) { this->preceptor = preceptor; }
	void setdireccion(string direccion) { this->direccion = direccion; }
	void setkm(double km) { this->km = km; }
	void setprecio(double precio) { this->precio = precio; }
	//get
	double getprecio() { return precio; }
	double getkm() { return km; }
	string getnenvio() { return nenvio; }
	string getdireccion() { return direccion; }
	string getpreceptor() { return preceptor; }

	//otras funciones
	string toString() {
		return "\nObjeto: " + nenvio +
			"\nReceptor:  " + preceptor +
			"\nDireccion del receptor: " + direccion +
			"\nDistancia: " + to_string(km) +
			"\nPrecio de envio: S/." + to_string(precio);
	}
};

class ListaEnvio {
private:
	Pila<Envio> envios;
	Grafo<int, string> g;
public:
	ListaEnvio() { }
	~ListaEnvio() {}

	void Insertar() {
		string nenvio, preceptor, direccion;
		double km, precio;

		cin.ignore();
		cout << "\nIngrese el objeto que va a enviar: ";
		getline(cin, nenvio);

		cin.ignore();
		cout << "Ingrese la persona que va a recibir el objeto: ";
		getline(cin, preceptor);

		cin.ignore();
		cout << "Ingrese la direccion de la persona que va a recibir el objeto: ";
		getline(cin, direccion);

		cout << "\nIngrese la cantidad de km entre su casa y la del receptor: "; cin >> km;
		precio = km * 1.3;
		envios.push(Envio(nenvio, preceptor, direccion, km, precio));
	}

	void MostrarEnvios() {
		envios.print([](Envio e) {cout << e.toString() << endl; });
	}

	void EliminarEnvio() {
		envios.pop();
	}

	void Mostrar_Enviosadmins() { 
		function<bool(NodoP<Envio>*)>  condicion = [](NodoP<Envio>* p) { //LAMBDA
			return p->getdato().getpreceptor() == "eric" || 
				p->getdato().getpreceptor() == "jair" || 
				p->getdato().getpreceptor() == "lucero";
		};
		function<void(Envio)> imprime = [](Envio e) { cout << e.toString() << endl; };
		envios.print_c(condicion, imprime);
	}

	void Buscar_Nodo() { //buscar envio
		short posb;
		cout << "Ingrese la posición del envio en la pila: ";
		cin >> posb;
		function<void(Envio)> imprime = [](Envio e) { cout << e.toString() << endl; };
		envios.BuscarNodoP(posb, imprime);
	}

	void ModificarNodo() { //modificar envio
		string nenvio, preceptor, direccion;
		double km, precio;
		cin.ignore();
		cout << "\nIngrese el objeto que va a enviar: ";
		getline(cin, nenvio);

		cin.ignore();
		cout << "Ingrese la persona que va a recibir el objeto: ";
		getline(cin, preceptor);

		cin.ignore();
		cout << "Ingrese la direccion de la persona que va a recibir el objeto: ";
		getline(cin, direccion);

		cout << "\nIngrese la cantidad de km entre su casa y la del receptor: "; cin >> km;
		precio = km * 1.3;
		NodoP<Envio>* aux = new NodoP<Envio>(Envio(nenvio, preceptor, direccion, km, precio));
		function<void(Envio)> imprime = [](Envio e) { cout << e.toString() << endl; };
		envios.modificar(aux->getdato(), envios.gettope());
		envios.BuscarNodoP(envios.gettope()->getpos(), imprime);
	}

	void InsertarUbicacion() {
		string valor; int id;
		cout << "Nuevo Envio -" << endl;
		cout << "Nueva ubicacion (valor): "; 
		cin.ignore(); getline(cin, valor);
		cout << "Nueva id (id): "; 
		cin >> id;
		Vertice<int, string> v (valor, id);
		g.addVertice(v);
	}

	void InsertarKilometrajeEntreUbicaciones() {
		int id1, id2, peso;
		cout << "Nuevo enlace entre ubicaciones -" << endl;
		cout << "Ingresa el ID de la primera ubicacion: ";
		cin >> id1;
		cout << "Ingresa el ID de la segunda ubicacion: ";
		cin >> id2;
		cout << "Ingresa el kilometraje entre ambas ubicaciones: ";
		cin >> peso;
		g.addEdgePorID(id1, id2, peso);
	}

	void printUbicacionesGuardadas() {
		g.print();
	}
};