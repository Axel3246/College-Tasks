#include <iostream>
#include <string>
using namespace std;
#include "Fecha.h"

class Empleado{

    public:
        Empleado();
        Empleado(string _nombreEmp, float _sueldoEmp, Fecha _f);
        ~Empleado();
        // -GET-
        string getNombreEmp();
        float getSueldoEmp();
        Fecha getFecha();
        // -SET-
        void setNombreEmp(string _nombreEmp);
        void setSueldo(float _sueldoEmp);
        void setFecha(Fecha _f);
        // -MISC-
        void subeSueldo(float);

    private:
        string nombreEmp;
        float sueldoEmp;
        Fecha cumpleAniosEmp;
};

Empleado::Empleado(){
    nombreEmp = "";
    sueldoEmp = 0;
    cumpleAniosEmp.getDia();
    cumpleAniosEmp.getMes();
}

Empleado::Empleado(string _nombreEmp, float _sueldoEmp, Fecha _f){
    nombreEmp = _nombreEmp;
    sueldoEmp = _sueldoEmp;
    cumpleAniosEmp = _f;
}

//~Empleado();
// -GET-
string Empleado::getNombreEmp(){
    return nombreEmp;
}

float Empleado::getSueldoEmp(){
    return sueldoEmp;
}

Fecha Empleado::getFecha(){
    return cumpleAniosEmp;
}
// -SET-
void Empleado::setNombreEmp(string _nombreEmp){
    nombreEmp = _nombreEmp;
}

void Empleado::setSueldo(float _sueldoEmp){
    sueldoEmp = _sueldoEmp;
}

void Empleado::setFecha(Fecha _f){
    cumpleAniosEmp = _f;
}

// -MISC-
void Empleado::subeSueldo(float _sueldo){

}