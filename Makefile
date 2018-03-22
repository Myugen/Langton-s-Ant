CC = gcc
CXX = g++ -std=c++11
RM = rm -f
FLAGS = -o

langton: cuadrado.o hormiga_.o hormiga_di.o hormiga_diid.o hormiga_iddi.o hormiga_iidd.o  hormiga_ddii.o filaRejilla.o columnaRejilla.o rejilla_.o maquina.o main.o
	$(CXX) $(FLAGS) langton cuadrado.o hormiga_.o hormiga_di.o hormiga_diid.o hormiga_iddi.o hormiga_iidd.o  hormiga_ddii.o filaRejilla.o columnaRejilla.o rejilla_.o maquina.o main.o

cuadrado.o: cuadrado.cpp cuadrado.hpp common.hpp

hormiga_.o: hormiga_.cpp hormiga_.hpp

hormiga_di.o: hormiga_di.cpp hormiga_di.hpp

hormiga_diid.o: hormiga_diid.cpp hormiga_diid.hpp

hormiga_iddi.o: hormiga_iddi.cpp hormiga_iddi.hpp

hormiga_iidd.o: hormiga_iidd.cpp hormiga_iidd.hpp

hormiga_ddii.o: hormiga_ddii.cpp hormiga_ddii.hpp

filaRejilla.o: filaRejilla.cpp filaRejilla.hpp

columnaRejilla.o: columnaRejilla.cpp columnaRejilla.hpp

rejilla_.o: rejilla_.cpp rejilla_.hpp

maquina.o: maquina.cpp maquina.hpp common.hpp

main.o: main.cpp

clean:
	$(RM) langton cuadrado.o hormiga_.o hormiga_di.o hormiga_diid.o hormiga_iddi.o hormiga_iidd.o  hormiga_ddii.o filaRejilla.o columnaRejilla.o rejilla_.o maquina.o main.o
