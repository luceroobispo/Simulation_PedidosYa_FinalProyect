#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "MyVector.h"
#include <functional>
#include <cstdlib>
#include "Producto.h"

using namespace std;

class Pedido {
private:
	int cantp;
	string nombre;
	float precio;
	string marca;
	string categoria;

public:
	Pedido(string nombre = "", string marca = "", float precio = 0.0, int cantp = 0, string categoria = "")
		: nombre(nombre), marca(marca), precio(precio), cantp(cantp), categoria(categoria) {
	}

	~Pedido() {}

	string getnombre() { return nombre; }
	string getmarca() { return marca; }
	float getprecio() { return precio; }
	int getcantp() { return cantp; }
	string getcategoria() { return categoria; }

	void setcantp(int cantp) { this->cantp = cantp; }
	void setnombre(string nombre) { this->nombre = nombre; }

	void mostrar() {
		cout << endl << "[" << getmarca() << "] : " << "[" << getnombre() << "] " << endl;
		cout << "[Categoria: " << getcategoria() << "] " << endl;
		cout << "[ Precio: " << getprecio() << "] x" << "[Cantidad de pedidos: " << getcantp() << "] " << endl;
	}

};

class ListaPedido {
private:
	MyVector<Pedido> lpedidos;
	ofstream archivo;
public:
	ListaPedido() {
		archivo.open("pedidos.txt");
	}
	~ListaPedido() {}

	void insertar(vector<Producto*> pro) { //e
		int cantp = 0;
		string nombre = "";
		char opcion;

		do {
			cin.ignore();
			cout << "Ingrese el nombre del producto: ";
			getline(cin, nombre);

			for (int i = 0; i < pro.size(); ++i) {
				if (pro[i]->getnproducto() == nombre) {
					cout << "Ingrese el numero de pedidos que hara de este producto: ";
					cin >> cantp;
					lpedidos.push_back(Pedido(pro[i]->getnproducto(), pro[i]->getmarca(), pro[i]->getprecio(), cantp, pro[i]->getcategoria()));

					archivo << endl << "[" << pro[i]->getmarca() << "] : " << "[" << pro[i]->getnproducto() << "] " << endl <<
						"[Categoria: " << pro[i]->getcategoria() << "] " << endl
						<< "[Precio: " << pro[i]->getprecio() << "]  x" << " [Cantidad de pedidos: " << cantp << "] "
						<< endl;
				}
			}
			cout << "Desea continuar (S/N)";
			cin >> opcion;
			opcion = toupper(opcion);

		} while (opcion == 'S');
		archivo.close();
	}

	void MostrarPedidos() { //e
		lpedidos.print([](Pedido p) { p.mostrar(); });
	}

	void ModificarPedido_Cantidad() {
		int pos = 0;
		int ncantp = 0;
		cout << "Ingrese la posicion del producto: "; cin >> pos;
		for (int i = 0; i <= lpedidos.getpos(); ++i) {
			if (i == pos) {
				cout << "Ingrese el nuevo numero de pedidos que hara de este producto: "; cin >> ncantp;
				Pedido npedido = lpedidos.getarr()[i];
				npedido.setcantp(ncantp);
				lpedidos.modificar(npedido, pos);
			}
		}
	}
	
	float obtenerPrecio(function<float(Pedido)> mifuncion, Pedido p) {
		return mifuncion(p);
	}

	void operacionPrecio(function<float(Pedido)> mifuncion, Pedido p) {
		cout << mifuncion(p) << "\n";
	}

	void CalcularPrecioLambda() {
		function<float(Pedido)>  CalcularPrecioSinDescuentos = [](Pedido p) {return p.getprecio() * p.getcantp(); };
		function<float(Pedido)>  CalcularPrecioConDescuentos = [](Pedido p) {return p.getprecio() * p.getcantp() * 0.5; }; //descuento 50%
		float precioTotal = 0;
		for (int i = 0; i <= lpedidos.getpos(); ++i) {
			cout << "\nPedido: "<<lpedidos.getarr()[i].getnombre() << endl;
			cout << "Precio sin descuentos: " << endl;
			operacionPrecio(CalcularPrecioSinDescuentos, lpedidos.getarr()[i]);
			if (lpedidos.getarr()[i].getcantp() >= 5) {
				cout <<"Precio con descuento: " << endl;
				operacionPrecio(CalcularPrecioConDescuentos, lpedidos.getarr()[i]);
				precioTotal += obtenerPrecio(CalcularPrecioConDescuentos, lpedidos.getarr()[i]);
			}
			else {
				cout << "No hay descuento" << endl;
				precioTotal += obtenerPrecio(CalcularPrecioSinDescuentos, lpedidos.getarr()[i]);
			}

		}
		cout << "\nPrecio Total: " << precioTotal<<endl;
	}

	void calcularMenorPrecioPedido() {
		float menor = lpedidos.getarr()[0].getprecio()* lpedidos.getarr()[0].getcantp();
		int pos = 0;
		for (int i = 1; i <= lpedidos.getpos(); ++i) {
			float aux = lpedidos.getarr()[i].getprecio() * lpedidos.getarr()[i].getcantp();
				if (aux<menor) { //si aux es menor al menor, se actualiza el valor de menor y la posicion
					menor = aux;
					pos = i;
				}
		}
		cout << "\nEl precio menor es " << menor << " y se encuentra en la posicion " << pos;
		lpedidos.getarr()[pos].mostrar();
	}

	void DesordenarPedidos() { //RECURSIVIDAD
		int v = lpedidos.getpos();//pos final
		lpedidos.desordenar(v - 1);
		MostrarPedidos();
	}

};


