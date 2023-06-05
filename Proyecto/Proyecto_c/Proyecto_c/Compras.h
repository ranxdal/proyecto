#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Compras {
private: string nit, nombres, apellidos, fecha_factura, fechaingreso;
	   int id, no_orden, id_proveedor, id_producto, id_compra, cantidad;
	   float precio_u;



	   // constructor
public:
	Compras() {
	}
	Compras(string n, string nom, string ape, string f_fac, string f_ing, int i, int n_ord, int idprov, int idprod, int idcom, int can, float preu) {
		nit = n;
		nombres = nom;
		apellidos = ape;
		fecha_factura = f_fac;
		fechaingreso = f_ing;
		cantidad = can;
		id = i;
		id_proveedor = idprov;
		id_producto = idprod;
		id_compra = idcom;
		no_orden = n_ord;
		precio_u = preu;
	}

	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		float total = 0;
		string nor = to_string(no_orden);
		string idp = to_string(id_proveedor);
		char r;
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO compras(no_orden_compra,idProveedor,fecha_orden,fechaingreso ) VALUES ('" + nor + "','" + idp + "',curdate(),now())";
			const char* i = insertar.c_str();
			
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				ver_proveedor();
				maxcompra();
				do {
					cout << " " << endl;
					cout << "Ingrese ID producto: ";
					cin >> id_producto;
					cin.ignore();
					ver_detalle_compra();
					cout << " " << endl;
					cout << "Ingrese Costo Unitario de producto: Q";
					cin >> precio_u;
					cin.ignore();
					detalle_compra();
					cout << "	Desea ingresar otro producto(s/n): ";
					cin >> r;
				} while (r == 's' || r == 'S');


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

			cout << "------------ Datos de compras------------" << endl;
			cout << "idcompra" << " | " << "No. Orden de Compra" << " | " << "idProveedor" << " | " << "Fecha Orden" << " | " << "Fecha Ingreso" << endl;
			string consulta = "SELECT * FROM db_empresa2.compras";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "       |      " << fila[1] << "     |     " << fila[2] << "   |   " << fila[3] << "   |    " << fila[4] << endl;
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

			string eliminar = "delete from compras where idcompra= '" + i + "'";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "eliminado con exito" << endl;

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
		string non = to_string(no_orden);
		string idpr = to_string(id_proveedor);
		if (cn.getConectar()) {
			string  insertar = "update compras set no_orden_compra = '" + non + "', idProveedor = '" + idpr + "', fecha_orden = '" + fecha_factura + "', fechaingreso = now() where idcompra = '" + i + "' ";
			const char* i = insertar.c_str();
			
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Modificacion Exitosa ..." << endl;
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
	void maxcompra() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "SELECT MAX(idcompra) from db_empresa2.compras";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);

			if (!q_estado) {
				if (fila != NULL) {
					id_compra = atof(fila[0]);
				}
				else {
					cout << " Error en detalle compras" << endl;
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
	void detalle_compra() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string no = to_string(no_orden);
		string idprod = to_string(id_producto);
		string idc = to_string(id_compra);
		string pre_u = to_string(precio_u);
		string can = to_string(cantidad);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO compras_detalle(idcompra,idProducto,cantidad,precio_costo_unitario) VALUES ('" + idc + "','" + idprod + "','" + can + "','" + pre_u + "')";
			const char* i = insertar.c_str();
			
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << " " << endl;
				cout << "Registro Exitoso..." << endl;
			}

			else {
				cout << " xxx Error   xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void ver_detalle_compra() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		string idp = to_string(id_producto);
		if (cn.getConectar()) {
			string consulta = "	SELECT producto, precio_costo FROM db_empresa2.productos where idProducto = '" + idp + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);
			if (!q_estado) {

				if (fila != NULL) {
					cout << "------------------------" << endl;
					cout << "Producto: " << fila[0] << endl; 
					cout << "Precio Costo: " << fila[1] << endl;
					cout << "------------------------" << endl;
					cout << "Ingrese cantidad a comprar: ";
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
	void ver_proveedor() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		string idpr = to_string(id_proveedor);
		if (cn.getConectar()) {
			string consulta = "	SELECT proveedor, nit FROM db_empresa2.proveedores where idProveedor = '" + idpr + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);
			if (!q_estado) {

				if (fila != NULL) {
					cout << "------------------------" << endl;
					cout << "Proveedor: " << fila[0] << "  " << "NIT :" << fila[1] << endl;
					cout << "------------------------" << endl;


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

};