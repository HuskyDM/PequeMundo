#ifndef PRODUCTORES_H
#define PRODUCTORES_H
#include <string>
#include <vector>
#include "Bienes.h"
#include "Materiales.h"

using namespace std;

class Productores
{
public:
    string nombre;
    int capital;
    vector <Materiales> materia;//Para la creacion de productos
    vector <Bienes> productos;//Para la venta de productos
    Productores();
    void crearProductores(string n, int v);
    void setCapital(int v);
    void crearProducto(Bienes b);
    virtual ~Productores();

protected:

private:
};

#endif // PRODUCTORES_H
