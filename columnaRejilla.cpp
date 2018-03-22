#include "columnaRejilla.hpp"

columnaRejilla::columnaRejilla(int indice):
indiceColumna(indice)
{}

columnaRejilla::~columnaRejilla(){}

int columnaRejilla::getIndice(){
  return indiceColumna;
}
