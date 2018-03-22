#include "filaRejilla.hpp"


filaRejilla::filaRejilla(int incrementoNegativo, int incrementoPositivo):
fila()
{

  for (int indice = 0; indice < incrementoPositivo; indice++){
    fila.push_back(std::make_pair(indice, Cuadrado() ));
  }

  for (int indice = -1 ; indice >= -incrementoNegativo ; indice--){
    fila.push_front(std::make_pair(indice, Cuadrado() ));
  }

}

filaRejilla::filaRejilla():
fila()
{}

filaRejilla::~filaRejilla(){}

int filaRejilla::getPositiveSize(){
  return fila.back().first;
}

int filaRejilla::getNegativeSize(){
  return fila.front().first;
}

void filaRejilla::cambiarColorCuadrado(int posX, Color colorNuevo){
    auto it = fila.begin();
    while (it != fila.end()){
      if (it -> first == posX)
      break;
      it++;
    }

      if (it != fila.end()){
        it -> second.setColor(colorNuevo);
      }else{
        std::cout << "ERROR::CUADRADO NO EXISTE";
      }
}

Color filaRejilla::obtenerColorCuadrado(int posX){
    auto it = fila.begin();
    while (it != fila.end()){
      if (it -> first == posX)
      break;
      it++;
    }

    Color nuevoColor;

      if (it != fila.end()){
        nuevoColor = it -> second.getColor();
      }else{
        std::cout << "ERROR::CUADRADO NO EXISTE";
      }

      return nuevoColor;
}


void filaRejilla::ampliarFila (int longitudAmpliar){
  int ultimoElemento = fila.back().first;
  for (int indice = 1; indice <= longitudAmpliar; indice++)
       fila.push_back(std::make_pair(ultimoElemento + indice, Cuadrado()));
}

void filaRejilla::decrementarFila (int longitudAmpliar){
  int ultimoElemento = fila.front().first;
  for (int indice = 1; indice <= longitudAmpliar; indice++)
       fila.push_front(std::make_pair(ultimoElemento - indice, Cuadrado()));
}

void filaRejilla::writeFila(){
  auto it = fila.begin();
  while (it != fila.end()){
    std::cout << "[" << it -> first << ",";
    it -> second.write(std::cout);
    std::cout << "] ";
    it++;
  }
    std::cout << "\n";
}

void filaRejilla::writeFila(int limiteX){
    int minPosX = fila.front().first;
    int offset = (minPosX - limiteX)-1;

    auto it = fila.begin();
    std::advance(it, offset);

    while (it != fila.end()){
      std::cout << "[" << it -> first << ",";
      it -> second.write(std::cout);
      std::cout << "] ";
      it++;
      if (it -> first == limiteX)
          break;
    }
        std::cout << "\n";
}


void filaRejilla::writeFila(int limiteX, int posY, std::vector<Hormiga*> vectorHormigas){

    std::vector<Hormiga*> vectorAuxiliar;
    bool hayHormiga = false;
    for (int indice = 0; indice < vectorHormigas.size(); indice++){
      if (vectorHormigas[indice] -> getPosicion().second == posY){
          vectorAuxiliar.push_back(vectorHormigas[indice]);
          hayHormiga = true;
      }
    }

    auto it = fila.begin();
    int offset = fabs(it -> first);
    offset -= limiteX;
    offset += vectorHormigas[0] -> getPosicion().first;

    std::advance(it, offset);

    int index = 0;

    while (it != fila.end()){
    //  std::cout << "[" << it -> first << ",";

        //std::cout << "1\n";
      if ((hayHormiga)&&(it -> first == vectorAuxiliar[index] -> getPosicion().first) && (posY == vectorAuxiliar[index] -> getPosicion().second)){
        vectorAuxiliar[index] -> write(std::cout);
        if (index < vectorAuxiliar.size() - 1)
        index++;

    }else {
      it -> second.write(std::cout);
    }
  //    std::cout << "] ";
      it++;
      if (it -> first == 50 + vectorHormigas[0] -> getPosicion().first)
          break;
    }
        std::cout << "|\n";
}
