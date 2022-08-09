#pragma once
#include "Lista.h"
#include "Usuario.h"
class ListaUsuarios
{
private:
	Lista<Usuario> usuarios;
	ofstream guardar;
	ofstream guardarCant;
	ifstream cargar;
	ifstream cargarCant;
	short cant;
	short auxcant;
public:
	ListaUsuarios()
	{
		cant = 0;
		auxcant = 0;
	}
	~ListaUsuarios() {}

	void GuardarUsuario(string nombreUsuario, string nombre, string contra, string direccion, unsigned int telefono)
	{
		if (guardar.is_open() == false)
		{
			guardar.open("DatosUsuario.txt");
		}
		if (guardar.is_open() || guardarCant.is_open()) {
			if (guardarCant.is_open() == false)
			{
				guardarCant.open("CantidadUsuarios.txt");

			}
			guardar << nombreUsuario << " " << contra << nombre << " " << direccion << " " << telefono << endl;
			usuarios.push_back(Usuario(nombreUsuario, contra, nombre, direccion, telefono));
			cant++;
			auxcant++;
			guardarCant << cant;
			guardarCant.close();
		}
	}
	void CargarUsuarios()
	{
		string nombreUsuario;
		string nombre;
		string contra;
		string direccion;
		unsigned int telefono;
		short auxCant;
		cargarCant.open("CantidadUsuarios.txt");
		cargarCant >> auxCant;
		cargarCant.close();
		if (cargar.is_open() == false)
		{
			cargar.open("DatosUsuario.txt");
		}
		do {
			cargar >> nombreUsuario >> contra >> nombre >> direccion >> telefono;
			usuarios.push_back(Usuario(nombreUsuario, contra, nombre, direccion, telefono));
			cant++;
			auxcant++;
		} while (cant != auxCant);
		cargar.close();
		system("cls");
		guardar.open("DatosUsuario.txt");
		for (short i = 1; i < cant + 1; i++)
		{
			guardar << usuarios.obtenerobj_pos(i).toString() << endl;
		}
	}
	bool VerificarUsuarioyContrasenna(string userName, string Contrasenna)
	{
		if (auxcant != 0)
		{
			if (userName == usuarios.obtenerobj_pos(auxcant).getNombreUsuario() && Contrasenna == usuarios.obtenerobj_pos(auxcant).getContrasenna())
			{
				auxcant = cant;
				return true;
			}
			else
			{
				auxcant = auxcant - 1;
				return  VerificarUsuarioyContrasenna(userName, Contrasenna);
			}
		}
		else
		{
			auxcant = cant;
			return false;
		}
	}
	bool VerificarUsuario(string userName)
	{
		if (auxcant != 0)
		{
			if (userName == usuarios.obtenerobj_pos(auxcant).getNombreUsuario())
			{
				auxcant = cant;
				return true;
			}
			else
			{
				auxcant = auxcant - 1;
				return  VerificarUsuario(userName);
			}
		}
		else
		{
			auxcant = cant;
			return false;
		}
	}
	void MostrarUsuarios() {
		usuarios.print([](Usuario u) {cout << u.toString() << endl; });
	}

	void OrdenarUsuarios() { //LAMBDA Y RECURSIVIDAD
		function<bool(Nodo<Usuario>*, Nodo<Usuario>*)>  condicion = [](Nodo<Usuario>* j, Nodo<Usuario>* i) {
			return i->getelemento().getNombreUsuario()[0] > j->getelemento().getNombreUsuario()[0]; 
		};
		usuarios.ordenar(usuarios.getinicio(), condicion);
		MostrarUsuarios();
	}

	void InvertirOrdenUsuarios() {
		usuarios.setinicio(usuarios.reverse(usuarios.getinicio()));
		MostrarUsuarios();
	}

	void EliminarPrimerUsuario() { //LAMBDA
		function<bool(Nodo<Usuario>*)>  condicion = [](Nodo<Usuario>* n) {
			return n->getelemento().getNombreUsuario() != "admin";
		};
		usuarios.setinicio(usuarios.deleteFirstNodo(usuarios.getfin(),condicion));
		MostrarUsuarios();
	}
	
	void Mostrar_UsuariosAdmin(){ 
		function<bool(Nodo<Usuario>*)>  condicion = [](Nodo<Usuario>* u) {
			return u->getelemento().getNombreUsuario() == "eric" ||
				u->getelemento().getNombreUsuario() == "jair" ||
				u->getelemento().getNombreUsuario() == "lucero";
		};

		function<void(Usuario)> imprime = [](Usuario n) { cout << n.toString() << endl; };
		usuarios.print_nom(condicion, imprime);
	}

	void Encontrar_imprimirUsuario_lambda() { 
		int pos;
		cout << "Ingrese la posicion del usuario en la lista: ";
		cin >> pos;

		function<void(Usuario)> imprime = [](Usuario n) { cout << n.toString() << endl; };
		usuarios.Encontrar_pos_imp(pos, imprime);
	}
	
	void EliminarUltimoUsuario() { 
		function<bool(Nodo<Usuario>*)>  condicion = [](Nodo<Usuario>* u) {
			return u->getelemento().getNombreUsuario() != "admin"; 
		};

		usuarios.setfin(usuarios.Elim_UltimoNodo(usuarios.getfin(), condicion));
		MostrarUsuarios();
	}

};
