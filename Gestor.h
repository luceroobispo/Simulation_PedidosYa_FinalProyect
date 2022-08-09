#pragma once
#include <stdlib.h>
#include "ListaDeUsuarios.h"
#include "Producto.h"
#include "Pedido.h"
#include "Envio.h"
#include "Ratings.h"
#include "Delivery.h"
#include "TopCadenas.h"
using namespace std;
class Gestor {
private:
	ListaUsuarios* Lista;
	ListaProducto* productos;
	ListaPedido* pedidos;
	ListaEnvio* envios;
	ListaDelivery* delivery;
	ColaRatings* resenas;
	MapaTCadenas* tcadenas;
public:
	Gestor()
	{
		Lista = new ListaUsuarios;
		productos = new ListaProducto();
		pedidos = new ListaPedido();
		envios = new ListaEnvio();
		delivery = new ListaDelivery();
		resenas = new ColaRatings();
		tcadenas = new MapaTCadenas();
		productos->insertar();
		delivery->LeerDatasetHT(); //
		resenas->leerOcargar(); //
	}
	~Gestor() {}

	void VerUsuarios()
	{
		Lista->MostrarUsuarios();
	}
	void MenuInicioSesion(short* opc)
	{
		cout << "\n PEDIDOS YA\t\n";
		cout << " ---------------------------\n";
		cout << " 1.Iniciar Sesion.\n";
		cout << " 2.Registrarse.\n";
		cout << " 3.Salir.\n";
		cout << " Ingrese una opcion: ";
		cin >> *opc;
	}

	void MenuAdmin() {
		int o=0;
		do {
			cout << "\t\tU S U A R I O S" << endl;
			cout << " 1. Quieres ver los demas usuarios: (S/N)\n";
			cout << " 2. Quieres ordenar los usuarios por su nombre de usuario: (S/N)\n";
			cout << " 3. Quieres invertir el orden de usuarios: (S/N)\n";
			cout << " 4. Quieres eliminar el primer usuario: (S/N)\n";
			cout << " 5. Quieres eliminar el ultimo usuario: (S/N)\n";
			cout << " 6. Quieres mostrar los usuarios con nombres de administradores: (S/N)\n";
			cout << " 7. Quieres encontrar un usuario por su posicion en la lista: (S/N)\n";
			cout << "\t\tE M P L E A D O S" << endl;
			cout << " 8. Ver deliverys por areas (S/N)\n";
			cout << " 9. Ver deliverys con salario mayor a 2000 (S/N)\n";
			cout << " 10. El k-simo delivery con el salario mas bajo (S/N)\n";
			cout << " 11. Ordenar deliverys por mayor salario\n";
			cout << "\t\tR A T I N G S" << endl;
			cout << " 12. Mostrar ratings" << endl;
			cout << " 13. Eliminar primer rating" << endl;
			cout << " 14. Mostrar primer rating recibido" << endl;
			cout << " 15. Mostrar ratings con puntuacion baja y alta" << endl;
			cout << " 16. Guardar Ratings" << endl;			
			cout << "\t\tT O P  C A D E N A S" << endl;
			cout << "17. Insertar una cadena al top por posicion" << endl;
			cout << "18. Mostrar el top 10 cadenas actuales de la app" << endl;
			cout << "19. Buscar una cadena del top por su posicion" << endl << endl;

            cout << " 20. Ir al menu de productos, pedidos y envios.\n";
			cout << " Ingrese opcion: "; cin >> o;
			system("CLS");
			switch (o)
			{
			case 1:	VerUsuarios();  break;
			case 2: Lista->OrdenarUsuarios();	  break;
			case 3:	Lista->InvertirOrdenUsuarios();   break;
			case 4:	Lista->EliminarPrimerUsuario();  break;
			case 5:	 Lista->EliminarUltimoUsuario();  break;
			case 6:	Lista->Mostrar_UsuariosAdmin();  break;
			case 7:Lista->Encontrar_imprimirUsuario_lambda(); break;
			case 8: delivery->listarHT(); break;
			case 9: delivery->listar_condicionht(); break; 
			case 10: delivery->quickSelectDelivery(); break;
				
			case 11: delivery->quicksort(); break;
			case 12: resenas->mostrarCola(); break;
			case 13: resenas->atenderCola(); break;
			case 14: resenas->mostrarPrimerElemento(); break;
			case 15: resenas->mostrarUsuarioConPuntuacionEspecifica(); break;
			case 16: resenas->guardardatasetCola(); break;
			case 17: tcadenas->insert_mapa(); 
				break;
			case 18: tcadenas->mostrar_mapa(); break;
			case 19: tcadenas->mostrar_en_pos(); break;
			case 20:
				system("cls");
				run(); break;
			default:
				break;
			}
			system("pause");
			system("CLS");
		} while (o != 20);
	}


	void OpcionesInicioSesion(short* opc)
	{
		int o=0;
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
				cout << " Inicio de Sesion:\n";
				cout << " Ingrese nombre de Usuario: ";
				cin >> nombreUsuario;
				cout << " Ingrese Contrasenna: ";
				cin >> contrasenna;
				if (Lista->VerificarUsuarioyContrasenna(nombreUsuario, contrasenna) == true)
				{
					short* opt = new short;
					cout << " Inicio de Sesison Perfecto: \n";
					cout << " ----------------------------\n";
					cout << " ----------------------------\n";
					cout << " ----------------------------\n";
					system("pause");
					system("cls");
					condicion = false;
					if (nombreUsuario == contrasenna && contrasenna == "admin")
					{
						MenuAdmin();
					}
					else
					{
						run();
					}
				}
				else
				{
					cout << " Nombre de Usuario o Contrasenna Incorrecto.";
					system("pause");
				}
			} while (condicion);
			break;

		case 2:
			system("cls");
			do {
				condicion = true;
				cout << " BIENVENIDO, PROCEDA A CREAR SU NOMBRE DE USARIO Y SU CONTRASENNA\n";
				cout << "Ingrese nombre de Usuario: ";
				cin >> nombreUsuario;
				cout << " Cree Contrasenna: ";
				cin >> contrasenna;
				if (Lista->VerificarUsuario(nombreUsuario) == true)
				{
					cout << " El nombre de usuario que ha escrito ya esta registrado, por favor pruebe otro nombre\n";
					system("pause");
					system("cls");
				}
				else
				{
					condicion = false;;
				}
			} while (condicion);
			cout << " Usuario creado\n";
			cout << " ..........\n";
			cout << " ..........\n";
			cout << " ..........\n";
			system("pause");
			system("cls");
			cout << " Proceda a llenar sus datos personales: \n";
			cout << " Ingrese Nombre: ";
			cin >> nombre;
			cout << " Ingrese Direccion: ";
			cin >> direccion;
			cout << " Ingrese Telefono: ";
			cin >> telefono;
			cout << " Datos Guardados\n";
			cout << " ..........\n";
			cout << " ..........\n";
			cout << " ..........\n";
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

	void run() {
		int opc;
		do {
			cout << "\t\tP R O D U C T OS" << endl;
			cout << " 1. Listar todos los productos disponibles" << endl;
			cout << " 2. Listar productos de bajo costo" << endl;
			cout << " 3. Listar productos por categoria" << endl;
			cout << "\t\tP E D I D O S" << endl;
			cout << " 4. Hacer un pedido" << endl;
			cout << " 5. Listar todos los pedidos" << endl;
			cout << " 6. Desordenar Pedidos" << endl;
			cout << " 7. Ordenar Pedidos por precio" << endl;
			cout << " 8. Modificar la cantidad de pedidos" << endl;
			cout << " 9. Calcular el precio total de los pedidos" << endl;
			cout << " 10. Buscar el menor precio de los pedidos" << endl;
			cout << "\t\tE N V I O S" << endl;
			cout << " 11. Hacer un envio" << endl;
			cout << " 12. Listar envios" << endl;
			cout << " 13. Cancelar el ultimo envio" << endl;
			cout << " 14. Mostrar los envios hechos a administradores " << endl;
			cout << " 15. Buscar Envio por posicion " << endl;
			cout << " 16. Modificar ultimo envio" << endl;
			cout << " 17. Guardar ubicacion" << endl;
			cout << " 18. Guardar kilometraje entre ubicaciones" << endl;
			cout << " 19. Listar ubicaciones guardadas y sus relaciones" << endl;
			cout << " 20. Cerrar sesion " << endl;
			cout << " Ingrese una opcion: ";
			cin >> opc;

			system("CLS");
			switch (opc) {
			case 1: productos->listarTodosProductosR(0); break;
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
			case 4: pedidos->insertar(productos->getvector()); break;
			case 5: pedidos->MostrarPedidos(); break;
			case 6: pedidos->DesordenarPedidos(); break;
			case 7: pedidos->OrdenarPedidos(); break;
			case 8: pedidos->ModificarPedido_Cantidad(); break;
			case 9: pedidos->CalcularPrecioLambda(); break;
			case 10: pedidos->calcularMenorPrecioPedido(); break;
			case 11: envios->Insertar(); break;
			case 12: envios->MostrarEnvios(); break;
			case 13: envios->EliminarEnvio(); break;
			case 14: envios->Mostrar_Enviosadmins(); break;
			case 15: envios->Buscar_Nodo(); break;
			case 16: envios->ModificarNodo(); break;
			case 17: envios->InsertarUbicacion(); break;
			case 18: envios->InsertarKilometrajeEntreUbicaciones(); break;
			case 19: envios->printUbicacionesGuardadas(); break;
			case 20:
				cout << "Sesion Cerrada....\n";
				system("pause");
				CorrerGestor();
			default: break;
			}
			system("pause");
			system("CLS");
		} while (1);
	}
};

