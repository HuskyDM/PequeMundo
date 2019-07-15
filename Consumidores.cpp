#include "Consumidores.h"
#include <vector>
#include <string>

Consumidores::Consumidores()
{
    string nombre;
    int capital;
    vector <Bienes> productos;
}

void Consumidores::crearConsumidor(string n, int v)
{
    nombre=n;
    capital=v;
}

void Consumidores::setCapital(int v)
{
    capital=v;
}


void Consumidores::incrementarCap(int v)
{
    capital=capital+v;
}

void Consumidores::comprarBien(Bienes b)
{
    productos.push_back(b);
}

Consumidores::~Consumidores()
{
    //dtor
}
