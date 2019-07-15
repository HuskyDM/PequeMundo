#ifndef BIENES_H
#define BIENES_H
#include "Materiales.h"
#include <vector>
#include <string>

using namespace std;

class Bienes
{
public:
    string nombre;
    int precio;
    vector <Materiales> requerimentos;
    Bienes();
    void crearBien(string n,int v);
    void setRequerimentos(Materiales b);
    virtual ~Bienes();

protected:

private:
};

#endif // BIENES_H
