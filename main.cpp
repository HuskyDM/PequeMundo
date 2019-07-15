#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <ostream>
#include <istream>
#include <sstream>
#include "Consumidores.h"
#include "Productores.h"
#include "Bienes.h"
#include "Materiales.h"

using namespace std;

vector <Consumidores> listaConsumidores; //Contenedores para cada tipo de clase que se cree para su uso sencillo
vector <Productores> listaProductores;
vector <Bienes> listaProductos;
vector <Materiales> listaMateriales;

Consumidores con; //Variables globales
Productores pro;
Bienes bien;
Materiales mat;

std::vector<Consumidores>::iterator con2;//Iteradores para trabajar globalmente
std::vector<Productores>::iterator pro2;
std::vector<Bienes>::iterator bien2;
std::vector<Materiales>::iterator mat2;

int opcion;
int opcion2;
int aumentar;
string nombreAux;
string nombreAux2;
int valorAux;
int valorAux2;
string nombreIter;
bool sePuede;
char nombreArch[15]; //Para el guardado de archivo



int main()
{

    bool hayPersona=false;
    bool acabar=false;

    cout<<"Bienvenido a 'Mi Pequeño Mundo"<<endl;
    cout<<"En este mundo existen Consumidores, Productores, Bienes y Materia"<<endl;
    cout<<"Todos estos objetos trabajan en conjunto gracias a ti"<<endl;
    cout<<"A continuacion se iniciara el juego, empieza por crear Consumidores, Productores, Bienes y Materia"<<endl;
    cout<<"Luego asignales objetos a los actores"<<endl;
    cout<<"Comenzemos"<<endl;


    while(acabar==false)
    {
        cout<<"\n";
        cout<<"Menu Principal"<<endl;
        cout<<"\n";
        cout<<"1=Crear Consumidor 2=Crear Productor 3=Crear Bien 4=Crear Materia"<<endl;
        cout<<"5=Comprar a Productor 6=Asignar Capital 7=Asignar Material 8=Mostrar 9=Ayuda"<<endl;
        cout<<"10=Asignar Bien a Productor 0=Guardar/Cargar o Salir"<<endl;
        cin>>opcion;
        switch(opcion)
        {
        case 1://Crear Consumidor
            cout<<"Introduzca un nombre para el Consumidor (unicamente una sentencia)"<<endl;
            cin>>nombreAux;
            cout<<"Introduzca el capital inicial de este Consumidor"<<endl;
            cin>>valorAux;
            con.crearConsumidor(nombreAux,valorAux);
            listaConsumidores.push_back(con);

            break;
        case 2://Crear Productor
            cout<<"Introduzca un nombre para este Productor (solo una sentencia)"<<endl;
            cin>>nombreAux;
            cout<<"Introduzca un capital inicial para este Productor"<<endl;
            cin>>valorAux;
            pro.crearProductores(nombreAux,valorAux);
            listaProductores.push_back(pro);


            break;
        case 3://Crear Bien

            cout<<"Introduzca el nombre para el Bien a crear"<<endl;
            cin>>nombreAux;
            cout<<"Introduzca un precio para el Bien a crear"<<endl;
            cin>>valorAux;
            cout<<"Que requerimento quiere anadir?"<<endl;
            cin>>nombreAux2;

            for(int i=0; i!=1; ++i)
            {
                vector<Materiales>::iterator iter;
                for(iter=listaMateriales.begin(); iter!=listaMateriales.end(); ++iter)
                {
                    if(nombreAux2==iter->nombre)
                    {
                        sePuede=true;
                        mat=*iter;
                    }
                }
                if(sePuede==true)
                {
                    bien.crearBien(nombreAux,valorAux);
                    bien.setRequerimentos(mat);
                    listaProductos.push_back(bien);



                }
                else
                {
                    cout<<"El requerimento seleccionado no existe, creelo e intente de nuevo"<<endl;
                }
                sePuede=false;
            }

            break;

        case 4://Crear Materia
            cout<<"Introduzca un nombre para el material"<<endl;
            cin>>nombreAux;
            mat.crearMaterial(nombreAux);
            listaMateriales.push_back(mat);

            break;
        case 5://Comprar a Productor
            cout<<"Cual consumidor sera el comprador?"<<endl;
            cin>>nombreAux;
            for(int i=0; i!=1; ++i)
            {
                vector<Consumidores>::iterator iter;
                for(iter=listaConsumidores.begin(); iter!=listaConsumidores.end(); ++iter)
                {
                    if(iter->nombre==nombreAux)
                    {
                        sePuede=true;
                        con2=iter;
                    }
                }
                if(sePuede==true)
                {
                    cout<<"Cual productor sera el vendedor?"<<endl;
                    cin>>nombreAux2;
                    bool sePuede2=false;
                    vector<Productores>::iterator iter2;
                    for(iter2=listaProductores.begin(); iter2!=listaProductores.end(); ++iter2)
                    {
                        if(iter2->nombre==nombreAux2)
                        {
                            sePuede2=true;
                            pro2==iter2;
                        }
                    }
                    if(sePuede2==true)
                    {
                        cout<<"Cual producto le quiere comprar a este productor?"<<endl;
                        cin>>nombreAux;
                        vector<Bienes>::iterator iter3;
                        for(iter3=pro2->productos.begin(); iter3!=pro2->productos.end(); ++iter3)
                        {
                            if(iter3->nombre==nombreAux)
                            {
                                if(con2->capital>=iter3->precio)
                                {
                                    con2->capital=con2->capital-iter3->precio;
                                    pro2->capital=pro2->capital+iter3->precio;
                                    con2->comprarBien(*iter3);
                                }
                            }
                        }
                    }
                }
            }
            break;


        case 6://Asignar Capital

            cout<<"Quiere 1:aumentar capital o 2:asignar un capital?"<<endl;
            cin>>opcion2;
            if(opcion2==1)
            {
                cout<<"A quien le quiere asignar capital?"<<endl;
                cout<<"1:Consumidor 2:Productor"<<endl;
                cin>>opcion2;

                if(opcion2==1)
                {
                    cout<<"Introduzca el nombre de la persona a quien le quiere aumentar el capital"<<endl;
                    cin>>nombreIter;
                    vector<Consumidores>::iterator iter;
                    for(iter=listaConsumidores.begin(); iter!=listaConsumidores.end(); ++iter)
                    {
                        cout<<nombreIter<<"."<<iter->nombre<<"."<<endl;
                        if (nombreIter==iter->nombre)
                        {
                            hayPersona=true;
                            con2=iter;
                        }
                    }

                    if (hayPersona==true)
                    {
                        cout<<"Cuanto quiere aumentar?"<<endl;
                        cin>>aumentar;
                        con2->capital+=aumentar;
                    }
                    else
                    {
                        cout<<"Parece que esta persona no existe..."<<endl;
                    }
                }
                else
                {
                    cout<<"Introduzca el nombre de la persona a quien le quiere aumentar el capital"<<endl;
                    cin>>nombreIter;
                    vector<Productores>::iterator iter;
                    for(iter=listaProductores.begin(); iter!=listaProductores.end(); ++iter)
                    {
                        if (nombreIter==iter->nombre)
                        {
                            hayPersona=true;
                            pro2=iter;
                        }
                    }

                    if (hayPersona==true)
                    {
                        cout<<"Cuanto quiere aumentar?"<<endl;
                        cin>>aumentar;
                        pro2->capital+=aumentar;
                    }
                    else
                    {
                        cout<<"Parece que esta persona no existe..."<<endl;
                    }
                }
            }
            else
            {
                cout<<"A quien le quiere asignar capital?"<<endl;
                cout<<"1:Consumidor 2:Productor"<<endl;
                cin>>opcion2;

                if(opcion2==1)
                {
                    cout<<"Introduzca el nombre de la persona a quien le quiere definir el capital"<<endl;
                    cin>>nombreIter;
                    vector<Consumidores>::iterator iter;
                    for(iter=listaConsumidores.begin(); iter!=listaConsumidores.end(); ++iter)
                    {
                        if (nombreIter==iter->nombre)
                        {
                            hayPersona=true;
                            con2=iter;
                        }
                    }

                    if (hayPersona==true)
                    {
                        cout<<"Cuanto quiere aumentar?"<<endl;
                        cin>>aumentar;
                        con2->setCapital(aumentar);
                    }
                    else
                    {
                        cout<<"Parece que esta persona no existe..."<<endl;
                    }
                }
                else
                {
                    cout<<"Introduzca el nombre de la persona a quien le quiere aumentar el capital"<<endl;
                    cin>>nombreIter;
                    vector<Productores>::iterator iter;
                    for(iter=listaProductores.begin(); iter!=listaProductores.end(); ++iter)
                    {
                        if (nombreIter==iter->nombre)
                        {
                            hayPersona=true;
                            pro2=iter;

                        }
                    }

                    if (hayPersona==true)
                    {
                        cout<<"Cuanto quiere aumentar?"<<endl;
                        cin>>aumentar;
                        pro2->capital=aumentar;
                    }
                    else
                    {
                        cout<<"Parece que esta persona no existe..."<<endl;
                    }
                }
            }
            break;

        case 7://Asignar Material
            cout<<"Defina a cual Productor le quiere asignar un Material"<<endl;
            cin>>nombreAux;
            for(int j=0; j!=1; ++j)
            {
                vector<Productores>::iterator iter;
                for(iter=listaProductores.begin(); iter!=listaProductores.end(); ++iter)
                {
                    if(nombreAux==iter->nombre)
                    {
                        sePuede=true;
                        pro2=iter;
                    }
                }
                if(sePuede==true)
                {
                    cout<<"Que materia quiere anadirle?"<<endl;
                    cin>>nombreAux2;
                    vector<Materiales>::iterator iter2;
                    for(iter2=listaMateriales.begin(); iter2!=listaMateriales.end(); ++iter2)
                    {
                        if(nombreAux2==iter2->nombre)
                        {
                            mat2=iter2;

                        }
                    }
                    pro2->materia.push_back(*mat2);

                }
                else
                {
                    cout<<"Parece que este productor no existe"<<endl;
                }

            }
            break;


        case 8://Mostrar
            cout<<"Quiere mostrar..."<<endl;
            cout<<"1.Consumidores 2.Productores 3.Bienes"<<endl;
            cout<<"4.Materia"<<endl;
            cin>>opcion2;
            if(opcion2==1)
            {
                vector<Consumidores>::iterator iter;
                vector<Bienes>::iterator iter2;
                for(iter=listaConsumidores.begin(); iter!=listaConsumidores.end(); ++iter)
                {
                    cout<<"Nombre:"<<iter->nombre<<" Capital:"<<iter->capital<<endl;
                    cout<<"Posee:"<<endl;
                    for(iter2=iter->productos.begin(); iter2!=iter->productos.end(); ++iter2)
                    {
                        cout<<iter2->nombre<<endl;
                    }
                }

            }
            if(opcion2==2)
            {
                vector<Productores>::iterator iter;
                vector<Bienes>::iterator iter2;
                vector<Materiales>::iterator iter3;
                for(iter=listaProductores.begin(); iter!=listaProductores.end(); ++iter)
                {
                    cout<<"\n";
                    cout<<"Nombre:"<<iter->nombre<<" Capital:"<<iter->capital<<endl;
                    cout<<"Posee:"<<endl;

                    for(iter3=iter->materia.begin(); iter3!=iter->materia.end(); ++iter3)
                    {
                        cout<<iter3->nombre<<endl;
                    }
                    cout<<"...como materiales"<<endl;
                    for(iter2=iter->productos.begin(); iter2!=iter->productos.end(); ++iter2)
                    {

                        cout<<iter2->nombre<<endl;
                    }
                    cout<<"...de productos"<<endl;
                    cout<<"\n";
                }
            }
            if(opcion2==3)
            {
                vector<Bienes>::iterator iter;
                vector<Materiales>::iterator iter2;
                for(iter=listaProductos.begin(); iter!=listaProductos.end(); ++iter)
                {
                    cout<<"Nombre:"<<iter->nombre<<" Precio:"<<iter->precio<<endl;
                    cout<<"Tiene como requerimentos"<<endl;
                    for(iter2=iter->requerimentos.begin(); iter2!=iter->requerimentos.end(); ++iter2)
                    {
                        cout<<iter2->nombre<<endl;
                    }
                }

            }
            if(opcion2==4)
            {
                cout<<"Los materiales disponibles son"<<endl;
                vector<Materiales>::iterator iter;
                for(iter=listaMateriales.begin(); iter!=listaMateriales.end(); ++iter)
                {
                    cout<<iter->nombre<<endl;
                }

            }


            break;
        case 9://Ayuda
            cout<<"Aqui se explican las reglas del juego"<<endl;
            cout<<"El mundo consiste de Consumidores, Productores, Bienes y Materia\n"<<endl;
            cout<<"Consumidores:Estas personas poseen un capital, un nombre y una lista de productos/n que poseen en ese momento"<<endl;
            cout<<"Estas pueden comprarle productos a los productores siempre y cuando tengan suficiente dinero\n"<<endl;
            cout<<"Los productores pueden crear productos siempre y cuando poseean materia en su lista de materia"<<endl;
            cout<<"Ellos poseen un nombre, un capital, una lista de materia y una de productos\n"<<endl;
            cout<<"Los bienes poseen un nombre, un precio y una lista de requerimentos\n"<<endl;
            cout<<"Al ser creados se debe de asignar uno o mas requerimentos de manera que"<<endl;
            cout<<"puedan ser creados"<<endl;
            cout<<"La materia solo posee un nombre y deben de ser los primeros objetos creados"<<endl;
            cout<<"El orden del juego debe de ser crear la materia, crear los productores y asignarles la creacion de bienes"<<endl;
            cout<<"con la materia creada. Luego crear consumidores que le compren a los productores"<<endl;
            cout<<"El juego acaba cuando tu quieras. Selecciona Guardar/Cargar y usa la opcion SALIR"<<endl;
            cout<<"Asi concluye la explicacion de ayuda, suerte"<<endl;

            break;

        case 10://Crear Bien con Productor
            cout<<"Introduzca el productor con el que quiere crear un bien"<<endl;
            cin>>nombreAux;
            for(int i=0; i!=1; ++i)
            {

                vector<Productores>::iterator iter;
                for(iter=listaProductores.begin(); iter!=listaProductores.end(); ++iter)
                {
                    if(iter->nombre==nombreAux)
                    {
                        sePuede=true;
                        pro2=iter;
                    }
                }
                if(sePuede==true)
                {
                    cout<<"Introduzca el Bien a crear"<<endl;
                    cin>>nombreAux;
                    vector<Bienes>::iterator iter2;

                    for(iter2=listaProductos.begin(); iter2!=listaProductos.end(); ++iter2)
                    {
                        if(nombreAux==iter2->nombre)
                        {
                            bien2=iter2;
                            pro2->crearProducto(*bien2);
                        }

                    }

                }

                else
                {
                    cout<<"No se puede realizar el metodo indicado"<<endl;
                }
                sePuede=false;

            }
            break;

        case 0://Guardar Cargar
            cout<<"Quiere 1:guardar, 2:cargar o 3:salir?"<<endl;
            cin>>opcion2;
            if(opcion2==1)
            {
                cout<<"Introduzca el nombre del archivo"<<endl;
                cin>>nombreArch;
                ofstream outputFile(nombreArch,ios::out);

                vector<Consumidores>::iterator iter;
                vector <Bienes>::iterator iter2;
                for(iter=listaConsumidores.begin(); iter!=listaConsumidores.end(); ++iter)
                {
                    outputFile<<"Nombre: "<<iter->nombre<<" Capital: "<<iter->capital<<endl;
                    outputFile<<"Productos \n";
                    for(iter2=iter->productos.begin(); iter2!=iter->productos.end(); ++iter2)
                    {
                        outputFile<<iter2->nombre<<endl;
                    }
                }
                vector<Productores>::iterator iter3;
                vector<Bienes>::iterator iter4;
                vector<Materiales>::iterator iter5;
                for(iter3=listaProductores.begin(); iter3!=listaProductores.end(); ++iter3)
                {
                    outputFile<<"Nombre: "<<iter3->nombre<<" Capital: "<<iter3->capital<<endl;
                    outputFile<<"Productos \n";
                    for(iter4=iter3->productos.begin(); iter4!=iter3->productos.end(); ++iter4)
                    {
                        outputFile<<iter4->nombre<<endl;
                    }
                    outputFile<<"Materiales:"<<endl;
                    for(iter5=iter3->materia.begin(); iter5!=iter3->materia.end(); ++iter5)
                    {
                        outputFile<<iter5->nombre<<endl;
                    }
                }
                vector<Bienes>::iterator iter6;
                vector<Materiales>::iterator iter7;
                for (iter6=listaProductos.begin(); iter6!=listaProductos.end(); ++iter6)
                {
                    outputFile<<"Nombre: "<<iter6->nombre<<" Precio: "<<iter6->precio<<endl;
                    outputFile<<"Requerimentos\n";
                    for(iter7=iter6->requerimentos.begin(); iter7!=iter6->requerimentos.end(); ++iter7)
                    {
                        outputFile<<iter7->nombre<<endl;
                    }
                }
                vector<Materiales>::iterator iter8;
                for(iter8=listaMateriales.begin(); iter8!=listaMateriales.end(); ++iter8)
                {
                    outputFile<<"Nombre: "<<iter8->nombre<<endl;
                }

            }

            if(opcion2==2)
            {
                cout<<"Este comando aun no esta definido"<<endl;
            }
            if(opcion2==3)
            {
                cout<<"Gracias por jugar"<<endl;
                acabar=true;
            }

            break;
        }

    }
    return 0;
}
