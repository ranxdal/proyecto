#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Productos {
private: string producto, descripcion, imagen, fechaingreso;
	   int id, id_marca, existencia;
	   float precio_costo, precio_venta;


	   // constructor
public:
	Productos() {
	}
	Productos(string prod, string des, string img, float pre_costo, float pre_venta, int exist, string fe_ing, int i, int idma) {
		producto = prod;
		descripcion = des;
		imagen = img;
		precio_costo = pre_costo;
		precio_venta = pre_venta;
		existencia = exist;
		fechaingreso = fe_ing;
		id = i;
		id_marca = idma;
	}


	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string i = to_string(id);
		string idmar = to_string(id_marca);
		string pre_c = to_string(precio_costo);
		string pre_v = to_string(precio_venta);
		string exi = to_string(existencia);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO productos(producto,idMarca,descripcion,imagen,precio_costo,precio_venta,existensia,fecha_ingreso) VALUES ('" + producto + "','" + idmar + "','" + descripcion + "','" + imagen + "','" + pre_c + "','" + pre_v + "','" + exi + "',now())";
			const char* i = insertar.c_str();
			
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
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

			cout << "------------ PRODUCTOS ------------" << endl;
			string consulta = "SELECT idProducto,producto,marca,descripcion,imagen,precio_costo,precio_venta,existensia,fecha_ingreso FROM db_empresa2.productos INNER JOIN db_empresa2.marcas where productos.idMarca = marcas.idMarca";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | "<< fila[6] << " | " << fila[7] << " | " << fila[8] << " | " << endl;
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

			string eliminar = "delete from productos where idProducto = '" + i + "'";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "Eliminado con exito" << endl;

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
		string i_ma = to_string(id_marca);
		string p_cos = to_string(precio_costo);
		string p_ven = to_string(precio_venta);
		string exis = to_string(existencia);
		if (cn.getConectar()) {
			string  insertar = "update productos set producto = '" + producto + "', idMarca = '" + i_ma + "', descripcion = '" + descripcion + "',imagen = '" + imagen + "',precio_costo = '" + p_cos + "',precio_venta = '" + p_ven + "', existencia = '" + exis + "', fecha_ingreso = now() where idProducto = '" + i + "' ";
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
};