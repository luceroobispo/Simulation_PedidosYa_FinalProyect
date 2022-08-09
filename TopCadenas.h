#pragma once
#include "Mapa.h" 
#include <iostream>
#include <functional>
#include <string>

using namespace std;

class TopCadena {
	int pos;
	string cadena; //nombre cadena
	int fundacion;
	string producto;
	string jefe;
public:
	TopCadena(int pos = 0, string cadena = " ", int fundacion = 0, string producto = " ", string jefe = " ") : pos(pos), cadena(cadena), fundacion(fundacion), producto(producto), jefe(jefe) {}
	~TopCadena() {}

	string getcadena() { return cadena; }
	int getpos() { return pos; }
	int getfund() { return fundacion; }
	string getproducto() { return producto; }
	string getjefe() { return jefe; }

	void imprime() {
		cout << "[" << getpos() + 1 << "] -> " << getcadena() << " | " << getfund() << " | " << getproducto() << " | " << getjefe() << " | " << endl;
	}

	bool compara(TopCadena e) {
		return (e.getcadena() == " ");
	}

};

class MapaTCadenas {

	Mapa<TopCadena> cadenas;

public:

	MapaTCadenas() {
		
	}
	~MapaTCadenas() {}

	void ini_mapa() {
		for (size_t i = 0; i < 10; ++i) {
			cadenas.insert_start(i, TopCadena(i, " ", 0, " ", " "));
		}
	}

	void insert_mapa() {
		function<bool(TopCadena)> empty = [](TopCadena e) {return e.compara(e); };

		int po = 0, fund = 0;
		char opc = 'S';
		string cadena, pro, jefe;

		while (opc == 'S') {
			cout << "Ingrese la posicion de la cadena entre las top: ";
			cin >> po;
			cout << "Ingrese el nombre de esta cadena: ";
			cin >> cadena;
			cout << "Ingrese el anio de fundacion de esta cadena: ";
			cin >> fund;
			cout << "Ingrese el nombre del producto mas popular de esta cadena: ";
			cin >> pro;
			cout << "Ingrese el nombre del dueno de esta cadena: ";
			cin >> jefe;
			cadenas.insert(po - 1, TopCadena(po - 1, cadena, fund, pro, jefe), empty);
			cout << endl;
			cout << "¿Desea ingresar otra cadena al top? (S/N):";
			cin >> opc;
			opc = toupper(opc);
		}

	}

	void mostrar_mapa() {
		function<void(TopCadena)> imprime = [](TopCadena c) { c.imprime(); };
		cout << "Mapa - Top cadenas de Envios Ya : " << endl;
		cadenas.print(imprime);
		cout << endl;
	}

	void mostrar_en_pos() {
		function<void(TopCadena)> imprime = [](TopCadena c) { c.imprime(); };
		int top;
		cout << "Ingrese la posicion del TOP 10 CADENAS a buscar : ";
		cin >> top; cout << endl;
		cadenas.print_pos(imprime, top-1);
		cout << endl;
	}
};