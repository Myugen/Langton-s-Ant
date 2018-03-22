#pragma once

#include "cuadrado.hpp"
#include "columnaRejilla.hpp"
#include "filaRejilla.hpp"
#include "hormiga_.hpp"
#include <cmath>
#include <algorithm>
#include <utility>
#include <iostream>
#include <list>

class Rejilla{


  private:

    std::list < std::pair < columnaRejilla , filaRejilla > > rejilla;
    Color     colorDefecto;

  public:

    Rejilla(int dimensionX, int dimensionY);
    ~Rejilla();

    /* Método para expandir los límites de la rejilla */

    void expandirRejilla ( int _ejeX, int ejeX, int _ejeY, int ejeY);

    /* Métodos para obtener los límites de la rejilla */

    int getLimite_X();
    int getLimiteX();
    int getLimite_Y();
    int getLimiteY();

    /* Método para modificar un cuadrado */

    void modificarCuadrado(Hormiga* hormiga, Color colorNuevo);
    void writeRejilla();
    void writeRejilla(int limiteX, int limiteY);
    void writeRejilla(int limiteX, int limiteY, std::vector<Hormiga*> vectorHormigas);

    void evaluarExpansion(Hormiga* hormiga);

    Color obtenerColor (int posX, int posY);

};
