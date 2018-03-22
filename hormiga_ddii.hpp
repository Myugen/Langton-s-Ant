#pragma once
#include "hormiga_.hpp"

class Hormiga_ddii : public Hormiga {

  public:

    Hormiga_ddii(std::pair<int,int> posicionHormiga, Direccion direccionMovimiento);
    Hormiga_ddii(int posX, int posY, Direccion direccionMovimiento);
    ~Hormiga_ddii();

    /* Método para establecer el sentido de la dirección
      de la hormiga*/
    void setDireccion(Direccion nuevaDireccion);

    /* Método para que la hormiga gire a la derecha*/
    void girarIzquierda();

    /* Método para que la hormiga gire a la izquierda */
    void girarDerecha();

    /* Método para que la hormiga avance */
    void avanzar();

    /* Método que devuelve el color */
    Color devolverColor(Color colorEntrada);

    /* Método que devuelve la posicion de la hormiga*/
    std::pair<int,int> getPosicion();

    /* Método para mostrar por pantalla la dirección de la hormiga*/
    std::ostream& write(std::ostream& os) const;


};
