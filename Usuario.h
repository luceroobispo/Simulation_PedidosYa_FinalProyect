#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include <functional>
using namespace std;
class Usuario
{

private:
	string nombre;
	string nombreUsuario;
	string contrasenna;
	string direccion;
	unsigned int telefono;

public:
	Usuario()
	{

	}
	Usuario(string nombreUsuario, string contrasenna, string nombre, string direccion, unsigned int telefono)
	{
		this->contrasenna = contrasenna;
		this->nombre = nombre;
		this->direccion = direccion;
		this->telefono = telefono;
		this->nombreUsuario = nombreUsuario;
		//convertir a minuscula
		this->nombre[0] = tolower(nombre[0]);
		this->nombreUsuario[0] = tolower(nombreUsuario[0]);
	}
	~Usuario() {}

	string getNombreUsuario() { return nombreUsuario; }
	string getContrasenna() { return contrasenna; }
	void setNombreUsuario(string nombreUsuario) { this->nombreUsuario = nombreUsuario; }
	void setContrasenna(string contrasenna) { this->contrasenna = contrasenna; }

	string toString() {
		return nombreUsuario + " " + contrasenna + " " + nombre + " " + direccion + " " + to_string(telefono);
	}
};
