#include <iostream>
using namespace std;

class Fecha
{

public:
    Fecha();
    Fecha(int _dia, int _mes);
    ~Fecha();

    int getDia();
    int getMes();

    void setMes(int _mes);
    void setDia(int _dia);

private:
    int dia;
    int mes;
};

Fecha::Fecha(){
    dia = 0;
    mes = 0;
}

Fecha::Fecha(int _dia, int _mes){
    dia = _dia;
    mes = _mes;
}

//~Fecha();

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

void Fecha::setMes(int _mes){
    mes = _mes;
}

void Fecha::setDia(int _dia){
    dia = _dia;
}