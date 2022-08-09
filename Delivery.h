#pragma once
#include <stdlib.h>
#include "HashTable.h"
#include <iostream>
#include <string>
#include <array>
#include <list>
#include <functional>
#include <fstream>
#include <sstream>
using namespace std;
class Delivery {
private:
	string ndelivery;//trabajador de delivery
	int salario;
	string ntienda;
	string categoria;
	string disponibilidad; //ocupado o disponible para hacer deliverys
	
public:
	Delivery(string ndelivery="",int salario=0,string ntienda="",string categoria="", string disponibilidad ="") :
		ndelivery(ndelivery), salario(salario),ntienda(ntienda),categoria(categoria), disponibilidad(disponibilidad) {}
	~Delivery() {}

	int getsalario() { return salario; }
	string getndelivery() { return ndelivery; }
	string to_String() { return "[" + ntienda + ", " + categoria + ", " + "S/." + to_string(salario) + ", "+ disponibilidad+ "]"; }
};

class ListaDelivery {
private:
	HT<string, Delivery> ht;
public:
	ListaDelivery() {}
	~ListaDelivery() {}

	void insertarConHT(string nombre, Delivery d) {
		ht.add(nombre, d);
	}

	void listarHT() {
		function<void(string, Delivery)> imprime = [](string n, Delivery d) { cout << n << " | " << d.to_String(); };
		ht.display(imprime);
	}

	void quickSelectDelivery() {
		function<bool(Delivery, Delivery)> condicion = [](Delivery d1, Delivery d2) { return d1.getsalario()<=d2.getsalario(); };
		cout << "\n Buscar el primer personal de delivery con el k-esimo salario mas bajo por cada area: " << endl;
		int k =0;
		cout << "Ingresa el valor k: "; cin >> k; cout << endl;
		for (int i = 0; i < 5;i++) {
			Entity<string, Delivery> ans = ht.listaToArrayQuickselect(ht.getcontainer()[i], k, condicion);
			cout << "\n Area "<< i+1 << endl;
			cout << " El delivery con el "<< k <<"' salario mas bajo es: " << ans.getvalue().getndelivery() << " " << ans.getvalue().to_String() << endl;
		}
		
	}

	void quicksort() { 
		int i; cout << "Que Area quiere ordenar? "; cin >> i;
		function<bool(Delivery, Delivery)> cond = [](Delivery d1, Delivery d2) { return d1.getsalario() >= d2.getsalario(); };
		function<void(string, Delivery)> imprime = [](string n, Delivery d) { cout << n << " | " << d.to_String(); };
		ht.listaToArrayQuicksort(ht.getcontainer()[i], 0, ht.getcontainer()[i].size(), cond, imprime);
		cout << endl;
	}

	void LeerDatasetHT() {
		ifstream archivo;
		archivo.open("data.csv", ios::in);
		string linea, texto;
		char delimitador = ',';
		getline(archivo, linea); // Leemos la primer línea para descartarla, pues es el encabezado
		while (getline(archivo, linea)) // Leemos todas las líneas
		{
			stringstream stream(linea); // Convertir la cadena a un stream
			string ndelivery, ntienda, categoria, disponibilidad;
			int salario = 0;
			// Extraer todos los valores de esa fila
			getline(stream, ndelivery, delimitador);
			getline(stream, texto, delimitador); salario = atoi(texto.c_str());
			getline(stream, ntienda, delimitador);
			getline(stream, categoria, delimitador);
			getline(stream, disponibilidad, delimitador);
			insertarConHT(ndelivery, Delivery(ndelivery, salario, ntienda, categoria, disponibilidad));
		}
		archivo.close();
	}

	void listar_condicionht() {
		function<void(string, Delivery)> imprime = [](string n, Delivery d) { cout << n << " | " << d.to_String(); };
		function<bool( Delivery)> condicion = []( Delivery d) { return d.getsalario() > 2000; };
		ht.displayCondicion(imprime, condicion);
	}

};