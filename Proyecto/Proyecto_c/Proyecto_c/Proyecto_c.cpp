#include "Cliente.h"
#include "Compras.h"
#include "Empleados.h"
#include "Marcas.h"
#include "Puestos.h"
#include "Productos.h"
#include "Proveedores.h"
#include "Ventas.h"
#include <iostream>

using namespace  std;

void tclientes();
void tcompras();
void templeados();
void tmarcas();
void tproductos();
void tproveedores();
void tpuestos();
void tventas();


int main()
{

	int op;
	do {
		system("cls");
		cout << "***************** MINI MARKET UWU *****************" << endl;
		cout << "Bienvenido a Mini Market UWU, que desea realizar: "<<endl;
		cout << "1. Ir a Clientes " << endl;
		cout << "2. Ir a Compras" << endl;
		cout << "3. Ir a Empleados" << endl;
		cout << "4. Ir a Marcas" << endl;
		cout << "5. Ir a Productos" << endl;
		cout << "6. Ir a Proveedores" << endl;
		cout << "7. Ir a Puestos" << endl;
		cout << "8. Ir a Ventas" << endl; 
		

		cout << "Ingrese una opcion: ";
		cin >> op;
		cin.ignore();
		switch (op) {
		case 1:
			tclientes();
			break;
		case 2:
			tcompras();
			break;
		case 3:
			templeados();
			break;
		case 4:
			tmarcas();
			break;
		case 5:
			tproductos();
			break;
		case 6:
			tproveedores();
			break;
		case 7:
			tpuestos();
			break;
		case 8:
			tventas();
			break;
		}
	} while (op <= 6 || op >= 6);

	return 0;

}

void tclientes() {
	system("cls");
	int op;
	string nombres, apellidos, nit, genero, correo, fechaingreso;
	int id = 0, telefono = 0;
	Cliente c;
	cout << "---------CLIENTES----------" << endl;
	cout << "1.Ingresar Nuevo Cliente: " << endl;
	cout << "2.Modificar Informacion del Cliente: " << endl;
	cout << "3.Eliminar Cliente: " << endl;
	cout << "4.Mostrar Clientes: " << endl;
	cout << "Ingrese opcion: ";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		cout << "Ingrese Nombres: ";
		getline(cin, nombres);
		cout << "Ingrese Apellidos: ";
		getline(cin, apellidos);
		cout << "Ingrese NIT: ";
		getline(cin, nit);
		cout << "Ingrese Genero(m/f): ";
		getline(cin, genero);
		cout << "Ingrese Correo Electronico: ";
		getline(cin, correo);
		cout << "Ingrese Telefono: ";
		cin >> telefono;
		cin.ignore();
		c = Cliente(nombres, apellidos, nit, genero, correo, fechaingreso, id, telefono);
		c.Crear();

		break;
	case 2:
		cout << "Ingrese ID que desea Modificar: ";
		cin >> id;
		cin.ignore();
		cout << "Ingrese Nombres: ";
		getline(cin, nombres);
		cout << "Ingrese Apellidos: ";
		getline(cin, apellidos);
		cout << "Ingrese NIT: ";
		getline(cin, nit);
		cout << "Ingrese Genero(m/f): ";
		getline(cin, genero);
		cout << "Ingrese Correo Electronico: ";
		getline(cin, correo);
		cout << "Ingrese Telefono: ";
		cin >> telefono;
		cin.ignore();
		c = Cliente(nombres, apellidos, nit, genero, correo, fechaingreso, id, telefono);
		c.Modificar();
		break;
	case 3:
		cout << "Ingrese ID que desea Eliminar: ";
		cin >> id;
		c = Cliente(nombres, apellidos, nit, genero, correo, fechaingreso, id, telefono);
		c.Eliminar();

		break;
	case 4:

		c = Cliente(nombres, apellidos, nit, genero, correo, fechaingreso, id, telefono);

		c.Leer();

		break;


	}
	system("pause");

}

void tcompras() {
	system("cls");
	int op;
	string nit, nombres, apellidos, f_factura, fingreso;
	int id = 0, no_orden = 0, id_proveedor = 0, id_producto = 0, id_compra = 0, cantidad = 0;
	float precio_u = 0;
	Compras c;
	cout << "--------COMPRAS-------" << endl;
	cout << "1. Ingresar Nueva Compra: " << endl;
	cout << "2. Modificar Informacion de Compra: " << endl;
	cout << "3. Eliminar Compra: " << endl;
	cout << "4. Mostrar Compras: " << endl;
	cout << "Ingrese opcion: ";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		system("cls");
		cout << "Ingrese No. Orden: ";
		cin >> no_orden;
		cin.ignore();
		cout << "Ingrese idProveedor: ";
		cin >> id_proveedor;
		cin.ignore();
		c = Compras(nit, nombres, apellidos, f_factura, fingreso, id, no_orden, id_proveedor, id_producto, id_compra, cantidad, precio_u);
		c.Crear();
		break;
	case 2:
		cout << "Ingrese ID que desea Modificar: ";
		cin >> id;
		cout << "Ingrese No. Orden: ";
		cin >> no_orden;
		cin.ignore();
		cout << "Ingrese idProveedor: ";
		cin >> id_proveedor;
		cin.ignore();
		cout << "Ingrese Fecha de Factura:";
		getline(cin, f_factura);
		c = Compras(nit, nombres, apellidos, f_factura, fingreso, id, no_orden, id_proveedor, id_producto, id_compra, cantidad, precio_u);
		c.Modificar();
		break;
	case 3:
		cout << "Ingrese ID que desea Eliminar: ";
		cin >> id;

		c = Compras(nit, nombres, apellidos, f_factura, fingreso, id, no_orden, id_proveedor, id_producto, id_compra, cantidad, precio_u);
		c.Eliminar();

		break;
	case 4:

		c = Compras(nit, nombres, apellidos, f_factura, fingreso, id, no_orden, id_proveedor, id_producto, id_compra, cantidad, precio_u);

		c.Leer();

		break;


	}
	system("pause");
}

void templeados() {
	system("cls");
	int op;
	string nombres, apellidos, direccion, dpi, genero, fn, fingreso, f_inicio;
	int id_puesto = 0;
	int telefono = 0, id = 0;
	Empleados c;
	cout << "---------EMPLEADOS-------" << endl;
	cout << "1. Ingresar un Nuevo Empleado: " << endl;
	cout << "2. Modificar Informacion de Empleado: " << endl;
	cout << "3. Eliminar Empleado: " << endl;
	cout << "4. Mostrar Empleados: " << endl;
	cout << "Ingrese opcion: ";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		cout << "Ingrese Nombres: ";
		getline(cin, nombres);
		cout << "Ingrese Apellidos: ";
		getline(cin, apellidos);
		cout << "Ingrese Direccion: ";
		getline(cin, direccion);
		cout << "Ingrese Telefono: ";
		cin >> telefono;
		cin.ignore();
		cout << "Ingrese DPI:";
		getline(cin, dpi);
		cout << "Ingrese Genero(m/f): ";
		getline(cin, genero);
		cout << "Ingrese Fecha de Nacimiento: ";
		getline(cin, fn);
		cout << "Ingrese ID de Puesto: ";
		cin >> id_puesto;
		cin.ignore();
		cout << "Ingrese Fecha de Inicio: ";
		getline(cin, f_inicio);
		c = Empleados(nombres, apellidos, direccion, dpi, genero, fn, telefono, fingreso, f_inicio, id, id_puesto);
		c.Crear();

		break;
	case 2:
		cout << "Ingrese ID que desea Modificiar: ";
		cin >> id;
		cin.ignore();
		cout << "Ingrese Nombres: ";
		getline(cin, nombres);
		cout << "Ingrese Apellidos: ";
		getline(cin, apellidos);
		cout << "Ingrese Direccion: ";
		getline(cin, direccion);
		cout << "Ingrese Telefono: ";
		cin >> telefono;
		cin.ignore();
		cout << "Ingrese DPI: ";
		getline(cin, dpi);
		cout << "Ingrese Genero(m/f): ";
		getline(cin, genero);
		cout << "Ingrese Fecha de Nacimiento: ";
		getline(cin, fn);
		cout << "Ingrese ID de Puesto: ";
		cin >> id_puesto;
		cin.ignore();
		cout << "Ingrese Fecha de Inicio: ";
		getline(cin, f_inicio);

		c = Empleados(nombres, apellidos, direccion, dpi, genero, fn, telefono, fingreso, f_inicio, id, id_puesto);
		c.Modificar();

		break;
	case 3:
		cout << "Ingrese ID a Eliminar: ";
		cin >> id;
		c = Empleados(nombres, apellidos, direccion, dpi, genero, fn, telefono, fingreso, f_inicio, id, id_puesto);
		c.Eliminar();

		break;
	case 4:

		c = Empleados(nombres, apellidos, direccion, dpi, genero, fn, telefono, fingreso, f_inicio, id, id_puesto);

		c.Leer();

		break;
	}

	system("pause");
}

void tmarcas() {
	system("cls");
	int op;
	string  marca;
	int id = 0;
	Marcas c;
	cout << "------------MARCAS-----------" << endl;
	cout << "1. Ingresar una Nueva Marca: " << endl;
	cout << "2. Modificar Marca: " << endl;
	cout << "3. Eliminar Marca: " << endl;
	cout << "4. Mostrar Marca: " << endl;
	cout << "Ingrese opcion: ";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		cout << "" << endl;
		cout << "Ingrese Marca: ";
		getline(cin, marca);
		c = Marcas(marca, id);
		c.Crear();

		break;
	case 2:
		cout << "" << endl;
		cout << "Ingrese ID que desea modificar: ";
		cin >> id;
		cin.ignore();
		cout << "Ingrese Marca a Modificar: ";
		getline(cin, marca);
		c = Marcas(marca, id);
		c.Modificar();

		break;
	case 3:
		cout << "" << endl;
		cout << "Ingrese ID que desea Eliminar: ";
		cin >> id;
		c = Marcas(marca, id);
		c.Eliminar();

		break;
	case 4:
		cout << "" << endl;
		c = Marcas(marca, id);
		c.Leer();

		break;
	}

	system("pause");
}

void tproductos() {
	system("cls");
	int op;
	string producto, descripcion, imagen, fechaingreso;
	int id = 0, id_marca = 0, existencia = 0;
	float precio_costo = 0, precio_venta = 0;
	Productos c;
	cout << "---------Productos-----------" << endl;
	cout << "1. Ingresar Nuevo Producto: " << endl;
	cout << "2. Modificar Informacion del Producto: " << endl;
	cout << "3. Eliminar Informacion del Producto: " << endl;
	cout << "4. Mostrar Productos: " << endl;
	cout << "Ingrese opcion: ";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		cout << "Ingrese Producto: ";
		getline(cin, producto);
		cout << "Ingrese ID de Marca: ";
		cin >> id_marca;
		cin.ignore();
		cout << "Ingrese Descripcion del Producto: ";
		getline(cin, descripcion);
		cout << "Ingrese Imagen: ";
		getline(cin, imagen);
		cout << "Ingrese Precio de Costo: Q";
		cin >> precio_costo;
		cin.ignore();
		cout << "Ingrese Precio de Venta: Q";
		cin >> precio_venta;
		cin.ignore();
		cout << "Ingrese Existencia: ";
		cin >> existencia;
		cin.ignore();

		c = Productos(producto, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso, id, id_marca);
		c.Crear();

		break;
	case 2:
		cout << "Ingrese ID a Modificar: ";
		cin >> id;
		cin.ignore();
		cout << "Ingrese Producto: ";
		getline(cin, producto);
		cout << "Ingrese ID de Marca: ";
		cin >> id_marca;
		cin.ignore();
		cout << "Ingrese Descripcion del Producto: ";
		getline(cin, descripcion);
		cout << "Ingrese Imagen: ";
		getline(cin, imagen);
		cout << "Ingrese Precio de Costo: Q";
		cin >> precio_costo;
		cin.ignore();
		cout << "Ingrese Precio de Venta: Q";
		cin >> precio_venta;
		cin.ignore();
		cout << "Ingrese Existencia: ";
		cin >> existencia;
		cin.ignore();
		c = Productos(producto, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso, id, id_marca);
		c.Modificar();

		break;
	case 3:
		cout << "Ingrese ID que desea eliminar: ";
		cin >> id;
		c = Productos(producto, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso, id, id_marca);
		c.Eliminar();

		break;
	case 4:

		c = Productos(producto, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso, id, id_marca);
		c.Leer();

		break;
	}

	system("pause");
}

void tproveedores() {
	system("cls");
	int op;
	string proveedor, nit, direccion;
	int id = 0, telefono = 0;

	Proveedores c;
	cout << "-------PROVEEDORES--------" << endl;
	cout << "1. Nuevo Proveedor: " << endl;
	cout << "2. Modificar Informacion de Proveedor: " << endl;
	cout << "3. Eliminar Proveedor: " << endl;
	cout << "4. Mostrar Proveedores: " << endl;
	cout << "Ingrese opcion :";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		cout << "Ingrese Proveedor: ";
		getline(cin, proveedor);
		cout << "Ingrese NIT: ";
		getline(cin, nit);
		cout << "Ingrese Direccion: ";
		getline(cin, direccion);
		cout << "Ingrese Telefono: ";
		cin >> telefono;
		cin.ignore();
		c = Proveedores(proveedor, nit, direccion, telefono, id);
		c.Crear();

		break;
	case 2:
		cout << "Ingrese ID que desea Modificar: ";
		cin >> id;
		cin.ignore();
		cout << "Ingrese Proveedor: ";
		getline(cin, proveedor);
		cout << "Ingrese NIT: ";
		getline(cin, nit);
		cout << "Ingrese Direccion: ";
		getline(cin, direccion);
		cout << "Ingrese Telefono: ";
		cin >> telefono;
		cin.ignore();
		c = Proveedores(proveedor, nit, direccion, telefono, id);
		c.Modificar();
		
		break;
	case 3:
		cout << "Ingrese ID a Eliminar: ";
		cin >> id;
		c = Proveedores(proveedor, nit, direccion, telefono, id);
		c.Eliminar();

		break;
	case 4:

		c = Proveedores(proveedor, nit, direccion, telefono, id);

		c.Leer();

		break;


	}
	system("pause");

}

void tpuestos() {
	system("cls");
	int op;
	string  puesto;
	int id = 0;
	Puestos c;
	cout << "--------PUESTOS-------" << endl;
	cout << "1. Crear Nuevo Puesto: " << endl;
	cout << "2. Modificar Puesto: " << endl;
	cout << "3. Eliminar Puesto: " << endl;
	cout << "4. Mostrar Puesto: " << endl;
	cout << "Ingrese opcion :";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		cout << "" << endl;
		cout << "Ingrese Puesto: ";
		getline(cin, puesto);
		c = Puestos(puesto, id);
		c.Crear();

		break;
	case 2:
		cout << "" << endl;
		cout << "Ingrese ID que desea Modificar: ";
		cin >> id;
		cin.ignore();
		cout << "Ingrese Puesto a Modificar: ";
		getline(cin, puesto);
		c = Puestos(puesto, id);
		c.Modificar();

		break;
	case 3:
		cout << "" << endl;
		cout << "Ingrese ID que desea Eliminar: ";
		cin >> id;
		c = Puestos(puesto, id);
		c.Eliminar();

		break;
	case 4:
		cout << "" << endl;
		c = Puestos(puesto, id);
		c.Leer();

		break;
	}

	system("pause");
}

void tventas() {
	system("cls");
	int op;
	string nombres, apellidos, nit, serie, f_factura, f_ingreso, correo, genero;
	int id = 0, id_empleado = 0, id_cliente = 0, no_factura = 0, id_venta = 0, id_producto = 0, cantidad = 0, telefono = 0;
	float precio_u = 0;
	Ventas c;
	cout << "-----------VENTAS----------" << endl;
	cout << "1. Ingresar Nueva Venta: " << endl;
	cout << "2. Modificar informacion de Venta: " << endl;
	cout << "3. Eliminar Venta: " << endl;
	cout << "4. Mostrar Ventas: " << endl;
	cout << "Ingrese opcion: ";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		system("cls");
		
		cout << "Ingresar NIT o C/F: ";
		getline(cin, nit);
		
		c = Ventas(nit, nombres, apellidos, serie, no_factura, f_factura, f_ingreso, correo, genero, cantidad, id, id_cliente, id_empleado, id_venta, id_producto, precio_u, telefono);
		c.Sin_nit();
		
		break;
	case 2:
		cout << "Ingrese idVenta: ";
		cin >> id;
		cin.ignore();
		cout << "Ingrese No. Factura: ";
		cin >> no_factura;
		cin.ignore();
		cout << "Ingrese Serie: ";
		getline(cin, serie);
		cout << "Ingrese Fecha de Factura: ";
		getline(cin, f_factura);
		cout << "Ingrese idCliente: ";
		cin >> id_cliente;
		cin.ignore();
		cout << "Ingrese idEmpleado: ";
		cin >> id_empleado;
		cin.ignore();
		c = Ventas(nit, nombres, apellidos, serie, no_factura, f_factura, f_ingreso, correo, genero, cantidad, id, id_cliente, id_empleado, id_venta, id_producto, precio_u, telefono);
		c.Modificar();
		break;
	case 3:
		cout << "Ingrese ID que desea Eliminar: ";
		cin >> id;
		c = Ventas(nit, nombres, apellidos, serie, no_factura, f_factura, f_ingreso, correo, genero, cantidad, id, id_cliente, id_empleado, id_venta, id_producto, precio_u, telefono);
		c.Eliminar();

		break;
	case 4:
		c = Ventas(nit, nombres, apellidos, serie, no_factura, f_factura, f_ingreso, correo, genero, cantidad, id, id_cliente, id_empleado, id_venta, id_producto, precio_u, telefono);
		c.Leer();

		break;
	}
	system("pause");

}
