#include "cuadrado.hpp"



Cuadrado::Cuadrado(Color colorCuadrado, int posicionCuadrado):
colorCuadrado(colorCuadrado),
posicionCuadrado(posicionCuadrado)
{}

Cuadrado::Cuadrado():
colorCuadrado(Color::blanco)
{}

Cuadrado::~Cuadrado(){}

Color Cuadrado::getColor(){
  if (colorCuadrado == Color::negro)
  return colorCuadrado;
}

int Cuadrado::getPosicion(){
  return posicionCuadrado;
}

void Cuadrado::setColor(Color nuevoColor){
    colorCuadrado = nuevoColor;
}

std::ostream& Cuadrado::write(std::ostream& os) const{

  if (colorCuadrado == Color::blanco){
    os << " ";
  }else if (colorCuadrado == Color::negro){
    os << "\033[1;37mX\033[0m";
  }else if (colorCuadrado == Color::azul){
    os << "\033[1;34mX\033[0m";
  }else if (colorCuadrado == Color::rojo){
    os << "\033[1;31mX\033[0m";
  }

  return os;
}

std::ostream& Cuadrado::write(std::ostream& os, Color color){

  if (color == Color::blanco){
    os << " ";
  }else if (color == Color::negro){
    os << "\033[1;37mX\033[0m";
  }else if (color == Color::azul){
    os << "\033[1;34mX\033[0m";
  }else if (color == Color::rojo){
    os << "\033[1;31mX\033[0m";
  }
  return os;
}
