
#pragma once
#include "common.hpp"
#include <iostream>

class Hormiga{
  protected:

    std::pair<int,int>  posicionHormiga;
    Direccion           direccionMovimiento;

    public:

      Hormiga(std::pair<int,int> posicionHormiga, Direccion direccionMovimiento);
      Hormiga(int posX, int posY, Direccion direccionMovimiento);
      ~Hormiga();

      /* Método para establecer el sentido de la dirección
        de la hormiga*/
      virtual void setDireccion(Direccion nuevaDireccion);

      /* Método para que la hormiga gire a la derecha*/
      virtual void girarIzquierda();

      /* Método para que la hormiga gire a la izquierda */
      virtual void girarDerecha();

      /* Método para que la hormiga avance */
      virtual void avanzar();

      /* Método que devuelve el color */
      virtual Color devolverColor(Color nuevoColor);

      /* Método que devuelve la posicion de la hormiga*/
      virtual std::pair<int,int> getPosicion();

      /* Método para mostrar por pantalla la dirección de la hormiga*/
      virtual std::ostream& write(std::ostream& os) const;


};
