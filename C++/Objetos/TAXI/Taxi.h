#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

class Taxi{

    public:
        Taxi();
        Taxi(Persona _responsable, int _ident);

        int getIdent();
        Persona getRespondable();

        void setIdent(int _ident);
        void setResponsable(Persona _responsable);

    private:
        Persona responsable;
        int ident;
};

Taxi::Taxi(){
    responsable.setNombre("-");
    responsable.setNumCel("-");
    ident = 0;
}

Taxi::Taxi(Persona _responsable, int _ident){
    responsable.setNombre(_nombre);
    responsable.setNumCel(_numcel);
    ident = _ident;
}

int Taxi::getIdent(){
    return ident;
}
Persona Taxi::getRespondable(){
    return responsable.getNombre(), responsable.getNumCel();
}

void Taxi::setIdent(int _ident){
    ident = _ident;   
}

void Taxi::setResponsable(Persona _responsable){
    responsable.setNombre(_nombre);
    responsable.setNumCel(_numcel);
}
