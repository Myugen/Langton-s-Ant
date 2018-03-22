#pragma once
#include <iostream>
#include <unistd.h>
/*
#include "rejilla.hpp"
#include "cuadrado.hpp"
#include "hormiga_.hpp"
#include "hormiga_di.hpp"*/
#include "maquina.hpp"
#include "hormiga_.hpp"
#include "hormiga_di.hpp"
#include "hormiga_ddii.hpp"
#include "hormiga_diid.hpp"
#include "hormiga_iidd.hpp"
#include "rejilla_.hpp"


int main(){

    Maquina myMaquina;
    myMaquina.run();

    /*std::cout << "Hello Ant\n";
    Rejilla reggie(100,100);

    std::vector<Hormiga*> vectorHormigas;


    Hormiga *flik = new Hormiga_didi(0 , 0 ,Direccion::Arriba);
    vectorHormigas.push_back(flik);
    Hormiga *flik_ = new Hormiga_ddii(1 , 0 ,Direccion::Arriba);
    vectorHormigas.push_back(flik_);
    Hormiga *flik__ = new Hormiga_iidd(2 , 0 ,Direccion::Arriba);
    vectorHormigas.push_back(flik__);
    Hormiga *flik___ = new Hormiga_diid(3 , 0 ,Direccion::Arriba);
    vectorHormigas.push_back(flik___);


/*
  for (int indice_ = 0; indice_ < 4; indice_++){
    std::cout <<  vectorHormigas[indice_] -> getPosicion().first;
    std::cout <<  hormigaPosY = vectorHormigas[indice_] -> getPosicion().second;

  }*/
  /*
  reggie.writeRejilla(50,15,vectorHormigas);
  usleep(500000);

    for (int indice = 0; indice < 15000; indice++){
  for (int indice_ = 0; indice_ < vectorHormigas.size(); indice_++){
    int hormigaPosX = vectorHormigas[indice_] -> getPosicion().first;
    int hormigaPosY = vectorHormigas[indice_] -> getPosicion().second;

    Color colorActual = reggie.obtenerColor(hormigaPosX, hormigaPosY);
    reggie.modificarCuadrado(vectorHormigas[indice_], vectorHormigas[indice_] -> devolverColor(colorActual));
    vectorHormigas[indice_] -> avanzar();

    }

    reggie.writeRejilla(50,15,vectorHormigas);
    usleep(5000);

  }*/

    /*Rejilla myRejilla;
    myRejilla.insertarCuadrado(0,0,Color::blanco);
    myRejilla.insertarCuadrado(1,0,Color::blanco);

    myRejilla.insertarCuadrado(2,0,Color::blanco);
    myRejilla.insertarCuadrado(2,1,Color::negro);
    myRejilla.insertarCuadrado(2,3,Color::negro);
    myRejilla.insertarCuadrado(2,4,Color::negro);

    myRejilla.insertarCuadrado(3,0,Color::blanco);
    myRejilla.write(std::cout,3,200);*/


    /*Hormiga Flik (0,0, Direccion::Arriba);

    for (int indice = 0; indice < 5; indice++){
    Flik.write(std::cout);
    Flik.girarDerecha();
    Flik.avanzar();
  }*/

  //Maquina machine(Color::blanco, Direccion::Arriba, 1);
  //machine.run();

//  std::cout << "Chilling in the neighbour\n";
/*
  std::cout << " --------------------------------------------------------------------------------------------------\n";
  for (int indice = 0; indice < 50; indice++)
  std::cout << "|                                                                                                  |\n";
  std::cout << " --------------------------------------------------------------------------------------------------\n";
*/


}
