#pragma once

#include "rejilla_.hpp"

Rejilla::Rejilla(int dimensionX, int dimensionY):
rejilla(),
colorDefecto(Color::blanco)
{

  //rejilla.push_back(std::make_pair(columnaRejilla(0),filaRejilla(dimensionX,dimensionX)));

  int maxPosY = rejilla.back().first.getIndice();
  for (int indice = 0; indice < dimensionY; indice++){
      rejilla.push_back(std::make_pair(columnaRejilla(maxPosY + indice),filaRejilla(dimensionX,dimensionX)));
  }

  int minPosY = rejilla.front().first.getIndice();
  for (int indice = 1; indice <= dimensionY; indice++){
      rejilla.push_front(std::make_pair(columnaRejilla(minPosY - indice),filaRejilla(dimensionX,dimensionX)));
  }

}

Rejilla::~Rejilla(){}

Color Rejilla::obtenerColor (int posX, int posY){

  auto it = rejilla.begin();
  while (it != rejilla.end()){
    if (it -> first.getIndice() == posY)
        break;
    it++;
  }

  Color nuevoColor;

  if (it != rejilla.end()){
    nuevoColor = it -> second.obtenerColorCuadrado(posX);
  }else{
    std::cout << "ERROR::NO EXISTE EL CUADRADO\n";
  }

  return nuevoColor;
}

/* Método para expandir los límites de la rejilla */
                                // -10x        10x     - 10y         10y
void Rejilla::expandirRejilla ( int _ejeX, int ejeX, int _ejeY, int ejeY){

    int minPosX = fabs(rejilla.back().second.getNegativeSize());
    int maxPosX = rejilla.back().second.getPositiveSize() + 1;

    std::cout << "MIN POSX - >" << minPosX << "\n";
    std::cout << "MAX POSX - >" << maxPosX << "\n";

    int maxPosY = rejilla.back().first.getIndice();
    for (int indice = 1; indice <= ejeY; indice++){
        rejilla.push_back(std::make_pair(columnaRejilla(maxPosY + indice),filaRejilla(minPosX, maxPosX)));
    }

    int minPosY = rejilla.front().first.getIndice();
    for (int indice = 1; indice <= _ejeY; indice++){
        rejilla.push_front(std::make_pair(columnaRejilla(minPosY - indice),filaRejilla(minPosX, maxPosX)));
    }


    auto it = rejilla.begin();
    while (it != rejilla.end()){

      it -> second.ampliarFila(ejeX);
      it -> second.decrementarFila(_ejeX);

      it++;
    }
}

/* Métodos para obtener los límites de la rejilla */

int Rejilla::getLimite_X(){
  return rejilla.front().second.getNegativeSize();
}
int Rejilla::getLimiteX(){
    return rejilla.front().second.getPositiveSize() + 1;
}
int Rejilla::getLimite_Y(){
    return rejilla.front().first.getIndice();
}
int Rejilla::getLimiteY(){
    return rejilla.back().first.getIndice() + 1;
}

/* Método para modificar un cuadrado */

void Rejilla::modificarCuadrado(Hormiga* hormiga, Color colorNuevo){

  int posX = hormiga -> getPosicion().first;
  int posY = hormiga -> getPosicion().second;

    auto it = rejilla.begin();
    while (it != rejilla.end()){
      if (it -> first.getIndice() == posY)
          break;
      it++;
    }

    if (it != rejilla.end()){
      it -> second.cambiarColorCuadrado(posX, colorNuevo);
    }else{
      std::cout << "ERROR::NO EXISTE EL CUADRADO\n";
    }

    evaluarExpansion(hormiga);
}

void Rejilla::writeRejilla(){
    auto it = rejilla.begin();

    while (it != rejilla.end()){
      std::cout << "COLUMNA: " << it -> first.getIndice();
      it -> second.writeFila();
      it++;
    }

    std::cout << "LIMITE X POSITIVO -> " << getLimiteX() << "\n";
    std::cout << "LIMITE X NEGATIVO -> " << getLimite_X() << "\n";
    std::cout << "LIMITE Y POSITIVO -> " <<  getLimiteY() << "\n";
    std::cout << "LIMITE Y NEGATIVO -> " << getLimite_Y() << "\n";

}

void Rejilla::writeRejilla(int limiteX, int limiteY){
    // Obtener la posicion minima de Y
    int minPosY = rejilla.front().first.getIndice();

    // Calcular cuanto hay que avanzar desde esa posición
    // a la que se quiere imprimir
    int offset = (minPosY - limiteY)-1;

    // Avanzar a esa posición
    auto it = rejilla.begin();

    std::cout << "OFFSET -> " << offset << "\n";
    std::cout << "minPosY -> " << minPosY << "\n";
    std::cout << "begin -> " << it-> first.getIndice() << "\n";

    std::advance(it, offset);

    std::cout << "begin2 -> " << it-> first.getIndice() << "\n";

    while (it != rejilla.end()){
      std::cout << "COLUMNA: " << it -> first.getIndice();
      it -> second.writeFila(limiteX);
      it++;
      if (it -> first.getIndice() == limiteY)
          break;
    }

    std::cout << "LIMITE X POSITIVO -> " << getLimiteX() << "\n";
    std::cout << "LIMITE X NEGATIVO -> " << getLimite_X() << "\n";
    std::cout << "LIMITE Y POSITIVO -> " <<  getLimiteY() << "\n";
    std::cout << "LIMITE Y NEGATIVO -> " << getLimite_Y() << "\n";

}

void Rejilla::writeRejilla(int limiteX, int limiteY, std::vector<Hormiga*> vectorHormigas){


    std::cout << " ";
    for (int indice = 0; indice < 100; indice++)
      std::cout << "_";
      std::cout <<"\n";

    auto it = rejilla.begin();
    int offset = fabs(it -> first.getIndice());
    offset += vectorHormigas[0] -> getPosicion().second;
    offset -= limiteY;


    //auto it = rejilla.begin();

      //  std::cout << "OFFSET -> " << offset << "\n";
      //  std::cout << "minPosY -> " << minPosY << "\n";
        //std::cout << "begin -> " << it-> first.getIndice() << "\n";

        std::advance(it, offset);

        //std::cout << "begin2 -> " << it-> first.getIndice() << "\n";

    while (it != rejilla.end()){
      //std::cout << "COLUMNA: " << it -> first.getIndice();
      std::cout << "|";
      it -> second.writeFila(limiteX, it -> first.getIndice(), vectorHormigas);
      it++; // Aqui he puesto el valor exacto para comprobar que funcionaba!!!!
      if (it -> first.getIndice() ==  15 + vectorHormigas[0] -> getPosicion().second  )
          break;
    }
    /*
    std::cout << "LIMITE X POSITIVO -> " << getLimiteX() << "\n";
    std::cout << "LIMITE X NEGATIVO -> " << getLimite_X() << "\n";
    std::cout << "LIMITE Y POSITIVO -> " <<  getLimiteY() << "\n";
    std::cout << "LIMITE Y NEGATIVO -> " << getLimite_Y() << "\n";
    */

    std::cout << " ";
    for (int indice = 0; indice < 100; indice++)
      std::cout << "_";
      std::cout <<"\n";
}

//void Rejilla::expandirRejilla ( int _ejeX, int ejeX, int _ejeY, int ejeY)
void Rejilla::evaluarExpansion(Hormiga* hormiga){


    int hormigaPosX = hormiga -> getPosicion().first;
    int hormigaPosY = hormiga -> getPosicion().second;

    int limite_Y = getLimite_Y();
    int limiteY  = getLimiteY();
    int limite_X = getLimite_X();
    int limiteX  = getLimiteX();

    if (limite_Y - hormigaPosY >= -20)
       expandirRejilla(0,0,5,0);

    if (limiteY - hormigaPosY  <= 20)
       expandirRejilla(0,0,0,5);

    if (limite_X - hormigaPosX >= -55){
       expandirRejilla(5,0,0,0);
     }

    if (limiteX - hormigaPosX  <= 55)
       expandirRejilla(0,5,0,0);



}
