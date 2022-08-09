#pragma once
#include <stdlib.h>
#include <iostream>
#include <functional>
#include <string>
#include <time.h>
#include "Cola.h"
#include <fstream>
#include <sstream>
using namespace std;

class Rating {
private:
	string apellido;
	int id;
	int puntuacion;

public:
	Rating(string apellido = " ", int id = 0, int puntuacion = 0)
		: apellido(apellido), id(id), puntuacion(puntuacion) {}
	~Rating() {}

	string getapellido() { return apellido; }
	int getid() { return id; }
	int getpuntuacion() { return puntuacion; }

	void setpuntuacion(int puntuacion) { this->puntuacion = puntuacion; }

	void mostrar() {
		cout << endl << "| " << apellido << " , ID." << id << ", ( " << puntuacion << " ) |" << endl;
	}

};

class ColaRatings {
private:
	Cola<Rating> resenas;
public:

	ColaRatings() {
		resenas.setn(1000001); //max posible de reseñas
	}
	~ColaRatings() {}

	void mostrarCola() {
		function<void(Rating)> imprime = [](Rating r) {r.mostrar(); };
		int pos = abs(resenas.getsize() - 1000);
		NodoC<Rating>* temp = resenas.getNodoByPos(pos);
		resenas.print(imprime, temp);
		cout << "\n\nTotal de ratings: " << resenas.getsize() << endl;
	}

	void insertarEnCola(Rating r) {
		resenas.enqueue(r);
	}

	void atenderCola() {
		cout << " Se elimino la primera resena" << endl;
		resenas.dequeue().mostrar();
	}

	void mostrarPrimerElemento() {
		NodoC<Rating>* front = resenas.peek();
		front->getdato().mostrar();
	}

	void mostrarUsuarioConPuntuacionEspecifica() {
		function<void(Rating)> imprime = [](Rating r) {r.mostrar(); };
		function<bool(Rating)> condicion = [](Rating r) { return r.getpuntuacion()<=20; };
		function<bool(Rating)> condicion2 = [](Rating r) { return r.getpuntuacion()>=60; };
		cout << "\nBuscar usuarios que calificaron a la aplicacion con una puntacion menor a 20\n";
		resenas.searchNodoByCondition(imprime, condicion);
		cout << "\nBuscar usuarios que calificaron a la aplicacion con una puntacion mayor a 60\n";
		resenas.searchNodoByCondition(imprime, condicion2);
		cout << endl;
	}

	void LeerDatasetCola() {
		ifstream archivo;
		archivo.open("data2.csv", ios::in);
		string linea, texto;
		char delimitador = ';';
		getline(archivo, linea); // Leemos la primer línea para descartarla, pues es el encabezado
		while (getline(archivo, linea)) // Leemos todas las líneas
		{
			stringstream stream(linea); // Convertir la cadena a un stream
			string nombre;
			int id = 0; int puntuacion = 1;
			// Extraer todos los valores de esa fila
			getline(stream, nombre, delimitador);
			getline(stream, texto, delimitador); id = atoi(texto.c_str());
			getline(stream, texto, delimitador); puntuacion = atoi(texto.c_str());
			insertarEnCola(Rating(nombre, id, puntuacion));
		}
		archivo.close();
	}

	void guardardatasetCola() {
		ofstream archivoR;
		archivoR.open("RatingsSaved.txt", ios::out);
		NodoC<Rating>* r = resenas.getinicio();
		archivoR << resenas.getsize() << endl;
		while (r != nullptr) {
			archivoR << r->getdato().getapellido() << endl;
			archivoR << r->getdato().getid() << endl;
			archivoR << r->getdato().getpuntuacion() << endl;
			r = r->getsiguiente();
		}
		archivoR.close();
	}

	void cargardatasetCola() {
		ifstream LeerArchivo;
		LeerArchivo.open("RatingsSaved.txt", ios::in);
		string apellido,texto;
		int cantTotal = 0;
		int id=0, puntuacion=0;
		if (LeerArchivo.is_open() == true) {
			getline(LeerArchivo, texto); cantTotal = atoi(texto.c_str());
			for (int i = 0; i < cantTotal;i++) {
				getline(LeerArchivo, apellido);
				getline(LeerArchivo, texto); id = atoi(texto.c_str());
				getline(LeerArchivo, texto); puntuacion = atoi(texto.c_str());
				resenas.enqueue(Rating(apellido,id,puntuacion));
			}
			LeerArchivo.close();
		}
	}

	void leerOcargar() {
		ifstream LeerArchivo;
		LeerArchivo.open("RatingsSaved.txt", ios::in);
		if (LeerArchivo.fail()) {
			LeerDatasetCola();
		}
		else cargardatasetCola();
	}
};