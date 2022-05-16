#pragma once
#include <stdlib.h>
#include "ListaDeUsuarios.h"
#include "Producto.h"
#include "Pedido.h"
#include "Envio.h"

class Gestor {
private:
	ListaUsuarios* Lista;
	ListaProducto* productos;
	ListaPedido* pedidos;
	ListaEnvio* envios;
public:
	Gestor()
	{
		Lista = new ListaUsuarios;
		productos = new ListaProducto();
		pedidos = new ListaPedido();
		envios = new ListaEnvio();
		productos->insertar();
	}
	~Gestor() {}

	void VerUsuarios()
	{
		Lista->MostrarUsuarios();
	}
	void MenuInicioSesion(short* opc)
	{
		cout << "\nENVIOS YA\t\n";
		cout << "---------------------------\n";
		cout << "1.Iniciar Sesion.\n";
		cout << "2.Registrarse.\n";
		cout << "3.Salir.\n";
		cin >> *opc;
	}
	void OpcionesInicioSesion(short* opc)
	{
		int o;
		string nombreUsuario;
		string nombre;
		string contrasenna;
		string direccion;
		unsigned int telefono;
		bool condicion;
		condicion = true;
		switch (*opc)
		{
		case 1:
			do {
				system("cls");
				cout << "Inicio de Sesion:\n";
				cout << "Ingrese nombre de Usuario: ";
				cin >> nombreUsuario;
				cout << "Ingrese Contrasenna: ";
				cin >> contrasenna;
				if (Lista->VerificarUsuarioyContrasenna(nombreUsuario, contrasenna) == true)
				{
					short* opt = new short;
					cout << "Inicio de Sesison Perfecto: \n";
					cout << "----------------------------\n";
					cout << "----------------------------\n";
					cout << "----------------------------\n";
					system("pause");
					system("cls");
					condicion = false;
					if (nombreUsuario == contrasenna && contrasenna == "admin")
					{
						do {
							cout << "1.Quieres ver los demas usuarios: (S/N)\n";
							cout << "\n2.Quieres ordenar los usuarios por su nombre de usuario: (S/N)\n";
							cout << "\n3.Quieres invertir el orden de usuarios: (S/N)\n";
							cout << "\n4.Quieres eliminar el primer usuario: (S/N)\n";
							cout << "\n5.Quieres eliminar el ultimo usuario: (S/N)\n";
							cout << "\n6.Quieres mostrar los usuarios con nombres de administradores: (S/N)\n";
							cout << "\n7.Quieres encontrar un usuario por su posicion en la lista: (S/N)\n";
							cout << "\n8.Salir.\n";
							cout << "\nIngrese opcion: "; cin >> o;
							switch (o)
							{

							case 1:	VerUsuarios();  break;
							case 2: Lista->OrdenarUsuarios();	  break;
							case 3:	Lista->InvertirOrdenUsuarios();   break;
							case 4:	Lista->EliminarPrimerUsuario();  break;
							case 5:	 Lista->EliminarUltimoUsuario();  break;
							case 6:	Lista->Mostrar_UsuariosAdmin();  break;
							case 7:Lista->Encontrar_imprimirUsuario_lambda();	  break;
							default:
								break;
							}
							system("pause");
							system("cls");
						} while (o != 8);

						run();
					}

					else
					{
						run();
					}
				}
				else
				{
					cout << "Nombre de Usuario o Contrasenna Incorrecto.";
					system("pause");
				}
			} while (condicion);
			break;

		case 2:
			system("cls");
			do {
				condicion = true;
				cout << "BIENVENIDO, PROCEDA A CREAR SU NOMBRE DE USARIO Y SU CONTRASENNA\n";
				cout << "Ingrese nombre de Usuario: ";
				cin >> nombreUsuario;
				cout << "Cree Contrasenna: ";
				cin >> contrasenna;
				if (Lista->VerificarUsuario(nombreUsuario) == true)
				{
					cout << "El nombre de usuario que ha escrito ya esta registrado, por favor pruebe otro nombre\n";
					system("pause");
					system("cls");
				}
				else
				{
					condicion = false;;
				}
			} while (condicion);
			cout << "Usuario creado\n";
			cout << "..........\n";
			cout << "..........\n";
			cout << "..........\n";
			system("pause");
			system("cls");
			cout << "Proceda a llenar sus datos personales: \n";
			cout << "Ingrese Nombre: ";
			cin >> nombre;
			cout << "Ingrese Direccion: ";
			cin >> direccion;
			cout << "Ingrese Telefono: ";
			cin >> telefono;
			cout << "Datos Guardados\n";
			cout << "..........\n";
			cout << "..........\n";
			cout << "..........\n";
			system("pause");
			system("cls");
			Lista->GuardarUsuario(nombreUsuario, nombre, contrasenna, direccion, telefono);

			break;
		case 3:
			exit(0);
			break;
		default:
			break;
		}
	}
	void CorrerGestor()
	{
		short* opc = new short;
		Lista->CargarUsuarios();
		do {
			system("cls");
			MenuInicioSesion(opc);
			OpcionesInicioSesion(opc);
			system("pause");
		} while (true);
	}

	void menu() {
		cout << "1. Listar todos los productos disponibles" << endl;
		cout << "2. Listar productos de bajo costo" << endl;
		cout << "3. Listar productos por categoria" << endl;
		cout << "4. Hacer un pedido" << endl;
		cout << "5. Listar todos los pedidos" << endl;
		cout << "6. Desordenar vector de Pedidos" << endl;
		cout << "7. Modificar la cantidad de pedidos" << endl;
		cout << "8. Calcular el precio total de los pedidos" << endl;
		cout << "9. Buscar el menor precio de los pedidos" << endl;
		cout << "10. Hacer un envio" << endl;
		cout << "11. Listar envios" << endl;
		cout << "12. Cancelar el ultimo envio" << endl;
		cout << "13. Mostrar los envios hechos a admins " << endl;
		cout << "14. Buscar Envio por posicion " << endl;
		cout << "15. Modificar ultimo envio" << endl;
		cout << "16. Cerrar sesion " << endl;
	}

	void run() {
		int opc;
		Envio tenvio;
		do {
			menu();
			cout << "Ingrese una opcion: ";
			cin >> opc;
			system("CLS");
			switch (opc) {
			case 1:
				productos->listarTodosProductosR(0);
				break;
			case 2:
				cout << "\nPRODUCTOS MENOR A S/.10 ------------------------------------" << endl;
				productos->listarTodosProductosL([](Producto* p) {return p->getprecio() < 10.0; });
				break;
			case 3:
				cout << "\nCATEGORIA MASCOTAS -----------------------------------------" << endl;
				productos->listarTodosProductosL([](Producto* p) {return p->getcategoria()[0] == 'M'; });//Mascotas
				cout << "\nCATEGORIA FARMACIA -----------------------------------------" << endl;
				productos->listarTodosProductosL([](Producto* p) {return p->getcategoria()[0] == 'F'; });
				cout << "\nCATEGORIA TIENDA -------------------------------------------" << endl;
				productos->listarTodosProductosL([](Producto* p) {return p->getcategoria()[0] == 'T'; });
				break;
			case 4:
				pedidos->insertar(productos->getvector());
				break;
			case 5:
				pedidos->MostrarPedidos();
				break;
			case 6:
				pedidos->DesordenarPedidos();
				break;
			case 7:
				pedidos->ModificarPedido_Cantidad();
				break;
			case 8:
				pedidos->CalcularPrecioLambda();
				break;
			case 9:
				pedidos->calcularMenorPrecioPedido();
				break;
			case 10:
				envios->Insertar();
				break;
			case 11:
				envios->MostrarEnvios();
				break;
			case 12:
				envios->EliminarEnvio();			
				break;
			case 13: 
				envios->Mostrar_Enviosadmins();
				break;
			case 14:
				envios->Buscar_Nodo();
				break;
			case 15:
				envios->ModificarNodo();
				break;
			case 16:
				cout << "Sesion Cerrada....\n";
				system("pause");
				CorrerGestor();
			default:

				break;
			}

			system("pause");
			system("CLS");

		} while (1);
	}
};

