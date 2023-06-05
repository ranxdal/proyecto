#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <fstream>
#include "ConexionBD.h"

using namespace std;

class Ventas {
private: string nit, nombres, apellidos, serie, fecha_factura, fechaingreso, correo, genero;
	   int id, id_venta, id_cliente, id_empleado, no_factura, id_producto, cantidad, telefono;
	   float precio_u;



	   // constructor
public:
	Ventas() {
	}
	Ventas(string n, string nom, string ape, string ser, int no_fac, string fe_fac, string fe_ingreso, string co, string gener, int can, int i, int id_cl, int id_emp, int id_ven, int id_pro, float pre_uni, int tel) {
		nit = n;
		nombres = nom;
		apellidos = ape;
		serie = ser;
		no_factura = no_fac;
		fecha_factura = fe_fac;
		fechaingreso = fe_ingreso;
		cantidad = can;
		correo = co;
		genero = gener;
		id = i;
		id_cliente = id_cl;
		id_empleado = id_emp;
		id_venta = id_ven;
		id_producto = id_pro;
		precio_u = pre_uni;
		telefono = tel;
	}

	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		float total = 0;
		string idcl = to_string(id_cliente);
		string idem = to_string(id_empleado);
		string nofac = to_string(no_factura);
		char r;
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO ventas(nofactura,serie,fechafactura,idCliente,idEmpleado,fechaingreso) VALUES ('" + nofac + "','" + serie + "',curdate(),'" + idcl + "','" + idem + "',now())";
			const char* i = insertar.c_str();
		
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "..." << endl;
				maxventa();
				do {
					cout << "Ingrese ID producto, o finalizar compra(0): ";
					cin >> id_producto;
					cin.ignore();
					cout << "------------------------" << endl;
					total += precio_u * cantidad;
					if (id_producto == 0) {
						cout << " " << endl;
						cout << "..............................................." << endl;
						cout << "Gracias por su preferencia, vuelva pronto ewe " << endl;
						cout << " TOTAL : Q" << total << endl;
						cout << "..............................................." << endl;
						cout << " " << endl;
						cout << " Desea adquirir factura (s/n): " << endl;
						cin >> r;
						cin.ignore();
						if (r == 's' || r == 'S') {
							Imprimir();
						}
						else {
							cout << "..." << endl;
						}

					}
					else {
						Ver_Venta_Detalle();
						Venta_Detalle();
					}

				} while (id_producto != 0);
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void Leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ VENTAS ------------" << endl;
			string consulta = "SELECT * FROM db_empresa2.ventas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | "<< fila[6] << " | " << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void Eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		string i = to_string(id);
		if (cn.getConectar()) {

			string eliminar = "delete from ventas where idVenta= '" + i + "'";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "Se ha eliminado con exito" << endl;

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void Modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string i = to_string(id);
		string id_e = to_string(id_empleado);
		string nfac = to_string(no_factura);
		string idcl = to_string(id_cliente);
		if (cn.getConectar()) {
			string  insertar = "update ventas set nofactura = '" + nfac + "', serie = '" + serie + "', fechafactura = '" + fecha_factura + "', idCliente = '" + idcl + "', idEmpleado = '" + id_e + "', fechaingreso = now() where idVenta = '" + i + "' ";
			const char* i = insertar.c_str();
			
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Se ha modificado exitosamente ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void Crear_Con_Fi() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		float total = 0;
		string idc = to_string(id_cliente);
		string ide = to_string(id_empleado);
		string nf = to_string(no_factura);
		char r;
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO ventas(nofactura,serie, fechafactura,idempleado,fechaingreso ) VALUES ('" + nf + "','" + serie + "',curdate(),'" + ide + "',now())";
			const char* i = insertar.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "..." << endl;
				maxventa();
				do {
					cout << "Ingrese ID producto, cerrar venta(0): ";

					cin >> id_producto;
					cin.ignore();
					cout << "------------------------" << endl;
					total += precio_u * cantidad;
					if (id_producto == 0) {
						cout << " " << endl;

						cout << "Gracias por su compra uwu" << " TOTAL : " << total << endl;
						cout << " " << endl;
						cout << " " << endl;
						cout << " Desea imprimir factura(s/n) " << endl;
						cin >> r;
						cin.ignore();
						if (r == 's' || r == 'S') {
							Imprimir_cf();
						}
						else {
							cout << "GRACIAS POR SU COMPRA uwu" << endl;
						}
					}
					else {
						Ver_Venta_Detalle();
						Venta_Detalle();
					}

				} while (id_producto != 0);
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void Sin_nit() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		float total = 0;
		char r;

		if (cn.getConectar()) {
			string consulta = "	SELECT nombres, apellidos, idCliente, now() FROM db_empresa2.clientes where	NIT = '" + nit + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);

			if (nit.empty()) {
				cout << " xxx Se debe ingresar NIT  xxx" << endl;
			}
			else {
				if (nit == "cf") {
					Factura();
					string idc = to_string(id_cliente);
					idc = " ";
					cout << "Ingrese ID empleado:";
					cin >> id_empleado;
					cin.ignore();
					Crear_Con_Fi();

				}
				else {
					if (!q_estado) {

						if (fila != NULL) {

							cout << "------------ DATOS ------------" << endl;
							cout << fila[0] << "  " << fila[1] << " | " << fila[2] << " | " << "Fecha: " << fila[3] << endl;
							id_cliente = atof(fila[2]);
							Factura();
							cout << "Ingrese ID empleado: ";
							cin >> id_empleado;
							cin.ignore();
							Crear();


						}
						else {
							cout << " Desea ingresar NIT a la factura (s/n): " << endl;
							cin >> r;
							cin.ignore();
							if (r == 's' || r == 'S') {
								cout << "Ingrese Nombres: ";
								getline(cin, nombres);
								cout << "Ingrese Apellidos: ";
								getline(cin, apellidos);
								cout << "Ingrese genero(m/f): ";
								getline(cin, genero);
								cout << "Ingrese correo electronico: ";
								getline(cin, correo);
								cout << "Ingrese telefono: ";
								cin >> telefono;
								cin.ignore();
								CrearCliente();
							}
							else {
								cout << "..." ;
							}

						}
					}
					else {
						cout << " xxx Error al Consultar  xxx" << endl;
					}
				}

			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}

		cn.cerrar_conexion();
	}

	void Factura() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "SELECT MAX(nofactura) from db_empresa2.ventas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);

			if (!q_estado) {
				if (fila != NULL) {

					cout << "No. Factura: ";
					no_factura = atof(fila[0]) + 1;
					cout << no_factura << " ";
					serie = "E";
					cout << "Serie: ";
					cout << serie << endl;

				}
				else {
					cout << " Error al ingresar" << endl;
				}
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}

		cn.cerrar_conexion();
	}

	void maxventa() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "SELECT MAX(idVenta) from db_empresa2.ventas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);

			if (!q_estado) {
				if (fila != NULL) {
					id_venta = atof(fila[0]);
				}
				else {
					cout << " Error en detalle ventas " << endl;
				}
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}

		cn.cerrar_conexion();
	}

	void Venta_Detalle() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string idv = to_string(id_venta);
		string idp = to_string(id_producto);
		string p_u = to_string(precio_u);
		string can = to_string(cantidad);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO ventas_detalle(idVenta,idProducto,cantidad,precio_unitario) VALUES ('" + idv + "','" + idp + "','" + can + "','" + p_u + "')";
			const char* i = insertar.c_str();
			
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "..." << endl;
			}

			else {
				cout << " xxx Error no existe producto  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void Ver_Venta_Detalle() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		string idp = to_string(id_producto);
		if (cn.getConectar()) {
			string consulta = "	SELECT producto, precio_venta FROM db_empresa2.productos where idProducto = '" + idp + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);
			if (!q_estado) {

				if (fila != NULL) {
					cout << fila[0] << "  " << "Precio: Q" << fila[1] << endl;
					cout << "------------------------" << endl;
					precio_u = atof(fila[1]);
					cout << "Ingrese Cantidad: ";
					cin >> cantidad;
					cin.ignore();

				}
				else {
					cout << " xxx Error del producto xxx" << endl;

				}
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}

		cn.cerrar_conexion();
	}

	void CrearCliente() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO clientes(nombres,apellidos,NIT,genero,telefono, correo_electronico,fechaingreso) VALUES ('" + nombres + "','" + apellidos + "','" + nit + "','" + genero + "','" + t + "','" + correo + "',now())";
			const char* i = insertar.c_str();
			
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
				Sin_nit();

			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	
	void Imprimir() {
		system("cls");
		int q_estado;
		int q_estado2;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		MYSQL_ROW fila2;
		MYSQL_RES* resultado2;
		float precio = 0, total = 0;
		int canti = 0;
		string idven = to_string(id_venta);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select v.nofactura,v.serie,v.fechafactura,c.NIT,c.nombres,c.apellidos from db_empresa2.clientes c inner join db_empresa2.ventas v on c.idCliente = v.idCliente where idVenta = '" + idven + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);

			if (!q_estado) {
				if (fila != NULL) {
					ofstream archivo;
					archivo.open("factura.txt");
					
					archivo << " No. Factura: " << fila[0] << endl;
					
					archivo << " Serie: " << fila[1] << endl;
					
					archivo << " Fecha: " << fila[2] << endl;
					
					archivo << "NIT: " << fila[3] << endl;
					
					archivo << "Cliente: " << fila[4] << " " << fila[5] << endl;


					archivo << "-------------------PRODUCTOS-----------------------" << endl;
					archivo << "ID" << " | " << " PRODUCTOS " << " | " << " MARCA " << " | " << " CANTIDAD " << " | " << " PRECIO " << endl;
					archivo << "  " << endl;
					string consulta2 = "select  d.idProducto,p.producto,m.marca, d.cantidad,d.precio_unitario from db_empresa2.ventas_detalle d inner join db_empresa2.productos p on p.idProducto = d.idProducto inner join db_empresa2.marcas m on m.idMarca = p.idMarca where idVenta = '" + idven + "'";
					const char* c = consulta2.c_str();
					q_estado2 = mysql_query(cn.getConectar(), c);
					if (!q_estado2) {
						resultado2 = mysql_store_result(cn.getConectar());
						while (fila2 = mysql_fetch_row(resultado2)) {
							archivo << fila2[0] << "	|	 " << fila2[1] << "		|	 " << fila2[2] << "		|	 " << fila2[3] << "	 Q. " << fila2[4] << endl;
							archivo << "---------------------------------------------------" << endl;
							precio = atof(fila2[4]);
							canti = atof(fila2[3]);
							total += precio * canti;
						}
						archivo << "TOTAL : " << total << endl;
						archivo << "---------------------------------------------------" << endl;
						archivo << "racias por su preferencia, vuelva pronto uwu" << endl;

						archivo.close();
						system("start C:\\Users\\usuario\\OneDrive\\Escritorio\\Proyecto_Final\\Proyecto\\Proyecto_c\\Proyecto_c\\factura.txt");
					}
					else {
						cout << " xxx Error al Consultar  xxx" << endl;
					}
				}
				else {
					cout << " Error en detalle ventas " << endl;
				}
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}

		cn.cerrar_conexion();
	}
	
	void Imprimir_cf() {
		system("cls");
		int q_estado;
		int q_estado2;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		MYSQL_ROW fila2;
		MYSQL_RES* resultado2;
		float precio = 0, total = 0;
		int canti = 0;
		string idv = to_string(id_venta);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select v.nofactura,v.serie,v.fechafactura from db_empresa2.clientes c inner join db_empresa2.ventas v where idVenta = '" + idv + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);

			if (!q_estado) {
				if (fila != NULL) {
					ofstream archivo;
					archivo.open("factura.txt");
					
					archivo << " No. Factura: " << fila[0] << endl;
					
					archivo << " Serie: " << fila[1] << endl;
					
					archivo << " Fecha: " << fila[2] << endl;
					
					archivo << "NIT: " << "C/F" << endl;
					

					archivo << "******************* PRODUCTOS *********************" << endl;
					archivo << "ID" << " | " << " PRODUCTOS " << " | " << " MARCA " << " | " << " CANTIDAD " << " | " << " PRECIO " << endl;
					archivo << "  " << endl;
					string consulta2 = "select  d.idProducto,p.producto,m.marca, d.cantidad,d.precio_unitario from db_empresa2.ventas_detalle d inner join db_empresa2.productos p on p.idProducto = d.idProducto inner join db_empresa2.marcas m on m.idMarca = p.idMarca where idVenta = '" + idv + "'";
					const char* c = consulta2.c_str();
					q_estado2 = mysql_query(cn.getConectar(), c);
					if (!q_estado2) {
						resultado2 = mysql_store_result(cn.getConectar());
						while (fila2 = mysql_fetch_row(resultado2)) {
							archivo << fila2[0] << "	 |	 " << fila2[1] << " 	|	 " << fila2[2] << " 	|	 " << fila2[3] << " Q. " << fila2[4] << endl;
							archivo << "---------------------------------------------------" << endl;
							precio = atof(fila2[4]);
							canti = atof(fila2[3]);
							total += precio * canti;
						}
						archivo << "TOTAL : " << total << endl;
						archivo << "****************************************" << endl;
						archivo << "Gracias por su preferencia, vuelva pronto uwu" << endl;

						archivo.close();
						system("start C:\\Users\\usuario\\OneDrive\\Escritorio\\Proyecto_Final\\Proyecto\\Proyecto_c\\Proyecto_c\\factura.txt");
					}
					else {
						cout << " xxx Error al Consultar  xxx" << endl;
					}


				}
				else {
					cout << " Error en detalle ventas " << endl;
				}
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}

		cn.cerrar_conexion();
	}
};
