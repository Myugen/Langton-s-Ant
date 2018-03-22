#pragma once

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <cmath>

#include "cuadrado.hpp"
#include "hormiga_.hpp"

class filaRejilla{

private:

  std::list < std::pair <int, Cuadrado> > fila;

public:

    filaRejilla(int incrementoNegativo, int incrementoPositivo);
    filaRejilla();
    ~filaRejilla();

    void ampliarFila (int longitudAmpliar);
    void decrementarFila (int longitudAmpliar);

    void writeFila();
    void writeFila(int limiteX);
    void writeFila(int limiteX, int posY, std::vector<Hormiga*> vectorHormigas);

    int getPositiveSize();
    int getNegativeSize();

    void cambiarColorCuadrado(int posX, Color colorNuevo);

    Color obtenerColorCuadrado(int posX);


};
