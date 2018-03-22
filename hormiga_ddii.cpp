#include "hormiga_ddii.hpp"

Hormiga_ddii::Hormiga_ddii(std::pair<int,int> posicionHormiga, Direccion direccionMovimiento):
      Hormiga(posicionHormiga, direccionMovimiento)
{}

Hormiga_ddii::Hormiga_ddii(int posX, int posY, Direccion direccionMovimiento):
      Hormiga(posX, posY, direccionMovimiento)
{}

Hormiga_ddii::~Hormiga_ddii(){}



std::ostream& Hormiga_ddii::write(std::ostream& os) const{
  if (direccionMovimiento == Direccion::Izquierda){
    os << "\033[1;31m<\033[0m";
  }else if (direccionMovimiento == Direccion::Derecha){
    os << "\033[1;31m>\033[0m";
  }else if (direccionMovimiento == Direccion::Arriba){
    os << "\033[1;31m^\033[0m";
  }else if (direccionMovimiento == Direccion::Abajo){
    os << "\033[1;31mv\033[0m";
  }

//  os << "\n" << "POS -> " << posicionHormiga.first << "," << posicionHormiga.second << "\n";
  return os;
}

void Hormiga_ddii::girarIzquierda(){

  if (direccionMovimiento == Direccion::Izquierda){
      direccionMovimiento = Direccion::Abajo;
  }else if (direccionMovimiento == Direccion::Derecha){
      direccionMovimiento = Direccion::Arriba;
  }else if (direccionMovimiento == Direccion::Arriba){
      direccionMovimiento = Direccion::Izquierda;
  }else if (direccionMovimiento == Direccion::Abajo){
      direccionMovimiento = Direccion::Derecha;
  }

}

std::pair<int,int> Hormiga_ddii::getPosicion(){
  return posicionHormiga;
}

void Hormiga_ddii::girarDerecha(){

  if (direccionMovimiento == Direccion::Izquierda){
      direccionMovimiento = Direccion::Arriba;
  }else if (direccionMovimiento == Direccion::Derecha){
      direccionMovimiento = Direccion::Abajo;
  }else if (direccionMovimiento == Direccion::Arriba){
      direccionMovimiento = Direccion::Derecha;
  }else if (direccionMovimiento == Direccion::Abajo){
      direccionMovimiento = Direccion::Izquierda;
  }

}


void Hormiga_ddii::avanzar(){

  if (direccionMovimiento == Direccion::Izquierda){
      posicionHormiga.first -= 1;
  }else if (direccionMovimiento == Direccion::Derecha){
      posicionHormiga.first += 1;
  }else if (direccionMovimiento == Direccion::Arriba){
      posicionHormiga.second -= 1;
  }else if (direccionMovimiento == Direccion::Abajo){
      posicionHormiga.second += 1;
  }

}



void Hormiga_ddii::setDireccion(Direccion nuevaDireccion){
  direccionMovimiento = nuevaDireccion;
}


Color Hormiga_ddii::devolverColor(Color colorEntrada){

    if (colorEntrada == Color::blanco){

        girarDerecha();
        return Color::negro;

    }else if (colorEntrada == Color::azul){

        girarDerecha();
        return Color::blanco;

    }else if (colorEntrada == Color::negro){

        girarIzquierda();
        return Color::rojo;

    }else if (colorEntrada == Color::rojo){

        girarIzquierda();
        return Color::azul;

    }
}
