#include "maquina.hpp"



Maquina::Maquina():
rejilla(100,100),
vectorHormiga()
{
  std::cout << "Tenemos cuatro tipos de hormiga:\n";
  std::cout << "Tipo 1 - Hormiga DIDI [\033[1;36m^\033[0m]\n";
  std::cout << "Tipo 2 - Hormiga DDII [\033[1;31m^\033[0m]\n";
  std::cout << "Tipo 3 - Hormiga IIDD [\033[1;32m^\033[0m]\n";
  std::cout << "Tipo 4 - Hormiga DIID [\033[1;33m^\033[0m]\n";
  std::cout << "Tipo 5 - Hormiga IDDI [\033[1;34m^\033[0m]\n";
  std::cout << "¿Cuántas hormigas quiere introducir?\n";

  int numeroHormigas;
  std::cin >> numeroHormigas;

  for (int indice = 0; indice < numeroHormigas; indice++){
    int tipoHormiga;
    std::cout << "Indique el tipo de la hormiga [" << indice + 1 << "]\n";
    std::cin >> tipoHormiga;

    switch(tipoHormiga){
      case 1 : {
      Hormiga* nuevaHormiga = new Hormiga_didi(indice, 0, Direccion::Arriba);
      vectorHormiga.push_back(nuevaHormiga);
      break;
    }
      case 2:{
      Hormiga* nuevaHormiga = new Hormiga_ddii(indice, 0, Direccion::Arriba);
      vectorHormiga.push_back(nuevaHormiga);
      break;
    }
      case 3:{
      Hormiga* nuevaHormiga = new Hormiga_iidd(indice, 0, Direccion::Arriba);
      vectorHormiga.push_back(nuevaHormiga);
      break;
    }
      case 4:{
      Hormiga* nuevaHormiga = new Hormiga_diid(indice, 0, Direccion::Arriba);
      vectorHormiga.push_back(nuevaHormiga);
      break;
    }

      case 5:{
      Hormiga* nuevaHormiga = new Hormiga_iddi(indice, 0, Direccion::Arriba);
      vectorHormiga.push_back(nuevaHormiga);
      break;
    }
      default:{
      std::cout << "Tipo incorrecto, se introducirá Hormiga_didi por defecto\n";
      Hormiga* nuevaHormiga = new Hormiga_didi(indice, 0, Direccion::Arriba);
      vectorHormiga.push_back(nuevaHormiga);
      break;
    }
  }

  }
}

Maquina::~Maquina(){}

void Maquina::run(){

  std::cout << "Seleccione la velocidad de la simulación\n";
  std::cout << "0 - Baja\n";
  std::cout << "1 - Media\n";
  std::cout << "2 - Alta\n";

  int velocidadSim;
  std::cin >> velocidadSim;

  if (velocidadSim == 0){
    velocidadSim = 500000;
  }else if (velocidadSim == 1){
    velocidadSim = 50000;
  }else if (velocidadSim == 2){
    velocidadSim = 5000;
  }

  std::cout << "Introduzca el número de Iteraciones\n";
  int numeroIteraciones;
  std::cin >> numeroIteraciones;

  rejilla.writeRejilla(50,15,vectorHormiga);
  usleep(500000);

    for (int indice = 0; indice < numeroIteraciones; indice++){
  for (int indice_ = 0; indice_ < vectorHormiga.size(); indice_++){
    int hormigaPosX = vectorHormiga[indice_] -> getPosicion().first;
    int hormigaPosY = vectorHormiga[indice_] -> getPosicion().second;

    Color colorActual = rejilla.obtenerColor(hormigaPosX, hormigaPosY);
    rejilla.modificarCuadrado(vectorHormiga[indice_], vectorHormiga[indice_] -> devolverColor(colorActual));
    vectorHormiga[indice_] -> avanzar();

    }

    rejilla.writeRejilla(50,15,vectorHormiga);
    usleep(velocidadSim);

  }

}


std::ostream& Maquina::write(std::ostream& os, int maxPosX, int minPosX,  std::vector<Hormiga*> vectorHormigas) const{

}
