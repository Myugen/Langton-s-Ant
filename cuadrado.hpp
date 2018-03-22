#pragma once
#include "common.hpp"
#include <iostream>


class Cuadrado{

private:
  Color colorCuadrado;
  int   posicionCuadrado;

public:

  /*Constructor a partir de un color*/
  Cuadrado(Color colorCuadrado, int posicionCuadrado);

  /*Constructor por defecto*/
  Cuadrado();

  /*Destructor por defecto
  ¿Hay que definirlo si no se va a hacer nada dentro?*/
  ~Cuadrado();

  /* Método get del Color */
  Color getColor();

  int getPosicion();

  /* Método set del Color */
  void setColor (Color nuevoCuadrado);

  /*Sobrecarga del operador de salida*/

  std::ostream& write (std::ostream& os) const;
  static std::ostream& write(std::ostream& os, Color color);

  bool operator < (const Cuadrado& otroCuadrado){
    return ( otroCuadrado.posicionCuadrado > posicionCuadrado );
  }

};
