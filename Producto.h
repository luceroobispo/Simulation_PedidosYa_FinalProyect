#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <functional>
using namespace std;

class Producto {
private:
	string nproducto; //nombre del producto
	string ntienda; //nombre de la tienda
	string marca; //nombre de la marca
	string categoria; //Bebidas, farmacias, mascotas
	double precio;
public:
	Producto(string nproducto = "", string marca = "", double precio = 0.0, string ntienda = "", string categoria = "")
		:nproducto(nproducto), marca(marca), precio(precio), ntienda(ntienda), categoria(categoria) {}
	~Producto() {}
	string getntienda() { return ntienda; }
	string getnproducto() { return nproducto; }
	string getmarca() { return marca; }
	string getcategoria() { return categoria; }
	double getprecio() { return precio; }

	string toStringNombreYPrecio() { return nproducto + " - S/." + to_string(precio); }
	string toStringTiendaYCategoria() { return ntienda + " - " + categoria; }

	void imprimir() {
		cout << "[" << setfill(' ') << setw(31) << getnproducto() << "]	" <<
			"[" << setfill(' ') << setw(11) << getmarca() << "]	" <<
			"[" << setfill(' ') << setw(5) << getprecio() << "] " <<
			"[" << setfill(' ') << setw(10) << getntienda() << "] " <<
			"[" << setfill(' ') << setw(8) << getcategoria() << "]";
	}
};

class ListaProducto {
private:
	vector<Producto*> vproductos;
public:
	ListaProducto() {}
	~ListaProducto() {}

	//size_t getsize() { return vproductos.size(); }
	vector<Producto*> getvector() { return vproductos; }

	void insertar() {//base de datos
		vproductos.push_back(new Producto("Helado Vainilla Pote", "Petzi Duri", 7.14, "Tambo", "Tienda"));
		vproductos.push_back(new Producto("Bebida citrico 1.5 Lt", "Cifrut", 2.99, "Tambo", "Tienda"));
		vproductos.push_back(new Producto("Canasto para transportar perros", "Winpet", 44.50, "Petshop", "Mascota"));
		vproductos.push_back(new Producto("Transportadora de mascota", "Happy home", 25.99, "Petshop", "Mascota"));
		vproductos.push_back(new Producto("Mochila transportadora de gatos", "Happy home", 36.99, "Petshop", "Mascota"));
		vproductos.push_back(new Producto("Bloqueador", "Bahia", 47.14, "Inkafarma", "Farmacia"));
		vproductos.push_back(new Producto("Repelente", "Floresta", 13.31, "Inkafarma", "Farmacia"));
		vproductos.push_back(new Producto("Desodorante de hombres", "Nivea", 13.09, "Mifarma", "Farmacia"));
		vproductos.push_back(new Producto("Desodorante de mujeres", "Nivea", 13.86, "Mifarma", "Farmacia"));
		vproductos.push_back(new Producto("Shampoo aclarante 415 ml", "Tio Nacho", 27.39, "Mifarma", "Farmacia"));
		vproductos.push_back(new Producto("Mermelada", "Gloria", 5.90, "VegaMarket", "Tienda"));
		vproductos.push_back(new Producto("Lenteja Bolsa 500 gr", "Costeno", 5.90, "VegaMarket", "Tienda"));
		vproductos.push_back(new Producto("Cereal 500 gr", "Corn Flakes", 13.90, "VegaMarket", "Tienda"));
		vproductos.push_back(new Producto("Comida para perros 18 kg", "Dog plus", 25.99, "Ricopet", "Mascota"));
		vproductos.push_back(new Producto("Arnes de gato", "Zeecat", 13.99, "Ricopet", "Mascota"));
		vproductos.push_back(new Producto("Arnes de perro", "Winpet", 15.90, "Ricopet", "Mascota"));
	}

	void listarTodosProductosR(unsigned short int i) { //listar con recursividad
		if (i == vproductos.size()) return;
		if (i == 0) { cout << "NOMBRE DEL PRODUCTO: \t\t\t" << "MARCA: \t	" << "PRECIO: " << "TIENDA:	     " << "CATEGORIA: " << endl; }//encabezado
		vproductos[i]->imprimir();
		cout << endl;
		listarTodosProductosR(i + 1);
	}

	void listarTodosProductosL(function<bool(Producto*)> condicion) { //listar con lambdas
		for (size_t i = 0; i < vproductos.size(); ++i) {
			if (i == 0) { cout << "NOMBRE DEL PRODUCTO: \t\t\t" << "MARCA: \t	" << "PRECIO: " << "TIENDA:	     " << "CATEGORIA: " << endl; }//encabezado
			if (condicion(vproductos[i])) { vproductos[i]->imprimir(); cout << endl; }
		}
	}

};