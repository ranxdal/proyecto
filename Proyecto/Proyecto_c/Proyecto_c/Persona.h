#pragma once
#include<iostream>
using namespace std;

class Persona
{
protected: string nombres, apellidos, direccion, dpi, genero, fn_nacimiento, f_ingreso;
         int telefono = 0;
         //constructor
protected:
    Persona() {

    }
    Persona(string nom, string ape, string dir, string dp, string gen, string fn, int tel, string fing) {
        nombres = nom;
        apellidos = ape;
        direccion = dir;
        dpi = dp;
        fn_nacimiento = fn;
        genero = gen;
        telefono = tel;
        f_ingreso = fing;


    }
};