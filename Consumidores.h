#ifndef CONSUMIDORES_H
#define CONSUMIDORES_H
#include <vector>
#include <string>
#include "Bienes.h"
#include "Productores.h"

using namespace std;

class Consumidores
{
public:
    string nombre;
    int capital; //porder adquisitivo
    vector <Bienes> productos; //Para contener los productos de los consumidores
    Consumidores();
    void crearConsumidor(string n, int v); //crea consumidor
    void setCapital(int v); //define el capital
    void incrementarCap(int v);
    void comprarBien(Bienes b);
    virtual ~Consumidores();

protected:

private:
};

#endif // CONSUMIDORES_H
