#include "hormiga_.hpp"


Hormiga::Hormiga(std::pair<int,int> posicionHormiga, Direccion direccionMovimiento):
posicionHormiga(posicionHormiga),
direccionMovimiento(direccionMovimiento)
{}

Hormiga::Hormiga(int posX, int posY, Direccion direccionMovimiento){
  posicionHormiga = std::make_pair(posX, posY);
  this -> direccionMovimiento = direccionMovimiento;
}

Hormiga::~Hormiga(){}


std::ostream& Hormiga::write(std::ostream& os) const{

}

void Hormiga::girarIzquierda(){

}

std::pair<int,int> Hormiga::getPosicion(){

}

void Hormiga::girarDerecha(){

}


void Hormiga::avanzar(){


}

void Hormiga::setDireccion(Direccion nuevaDireccion){

}

Color Hormiga::devolverColor(Color nuevoColor){}
