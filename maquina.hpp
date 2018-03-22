/*Es el responsable de contar y gestionar los pasos de la simulación.
En cada paso la Hormiga realiza un movimiento y se actualiza la visualización de la Rejilla
y la propia Hormiga. Se debe visualizar un cuadrado de dimensiones MxN donde se
encuentre la Hormiga. La Máquina establecerá la situación inicial de la Rejilla y la Hormiga,
y comenzará a realizar los pasos de la simulación hasta que alcance la situación de
parada, esta puede ser por un número máximo de pasos o que el usuario detenga la
simulación.*/

#pragma once
#include "common.hpp"
#include "rejilla_.hpp"
#include "hormiga_di.hpp"
#include "hormiga_ddii.hpp"
#include "hormiga_diid.hpp"
#include "hormiga_iidd.hpp"
#include "hormiga_iddi.hpp"
#include <iostream>
#include <vector>
#include <unistd.h>

class Maquina{
  private:

    Rejilla                    rejilla;
    std::vector<Hormiga*>      vectorHormiga;

    public:

      Maquina();
      ~Maquina();
      void run();
      std::ostream& write(std::ostream& os, int maxPosX, int minPosX, std::vector<Hormiga*> vectorHormigas) const;
};
