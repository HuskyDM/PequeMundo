#ifndef MATERIALES_H
#define MATERIALES_H
#include <string>

using namespace std;

class Materiales
{
public:
    string nombre;
    Materiales();
    void crearMaterial(string n);
    virtual ~Materiales();

protected:

private:
};

#endif // MATERIALES_H
