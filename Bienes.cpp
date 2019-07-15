#include "Bienes.h"
#include<string>
#include <vector>

Bienes::Bienes() //Constructor
{
    string nombre;
    int precio;
    vector <Materiales> requerimentos;
}

//Metodos

void Bienes::crearBien(string n,int v)
{
    nombre=n;
    precio=v;
}


void Bienes::setRequerimentos(Materiales b)
{
requerimentos.push_back(b);
}

Bienes::~Bienes()
{
    //dtor
}
