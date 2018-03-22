#pragma once

#include <iostream>
#include <list>
#include <utility>

#include "cuadrado.hpp"

class columnaRejilla{

private:

  int indiceColumna;

public:

    columnaRejilla(int indice);
    ~columnaRejilla();

    int getIndice();

};
