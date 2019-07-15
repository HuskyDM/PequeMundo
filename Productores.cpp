#include "Productores.h"
#include "Materiales.h"
#include "Bienes.h"
#include <string>

Productores::Productores()
{
    string nombre;
    int capital;
    vector <Materiales> materia;
    vector <Bienes> productos;
}
void Productores::crearProductores(string n, int v)
{
    nombre=n;
    capital=v;
}


void Productores::setCapital(int v)
{
    capital=v;
}

void Productores::crearProducto(Bienes b)
{
    bool hayMaterial=false;
    vector<Materiales>::iterator iter;
    vector<Materiales>::iterator iter2;

    for(iter=materia.begin(); iter != materia.end(); ++iter)
    {
        for(iter2=b.requerimentos.begin(); iter2 != b.requerimentos.end(); ++iter2)
        {
            if(iter2->nombre==iter->nombre)
            {
                hayMaterial=true;
            }
        }
    }
    if(hayMaterial==true)
    {
        productos.push_back(b);
    }
}

Productores::~Productores()
{
    //dtor
}
