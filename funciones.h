#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

// Prototipos de funciones
void mostrarmenu();
int cargargeneros(int codigos[], string nombres[]);
int cargarcontenidos(int lotegeneroscargado, int codigosCont[], string titulos[], char tipos[], int duraciones[], float puntajes[], int codGenerosCont[], int codigos[]);
int cargarsuscriptores(int codSus[], int cantPan[], string nomSus[], char planes[]);
int cargarreproducciones(int lotegeneroscargado, int lotecontenidoscargado, int lotesuscriptorcargado,
                         int codigosCont[], char tipos[], int duraciones[], int codGenerosCont[],
                         int codSus[], char planes[],
                         int repsPorContenido[], int compPorContenido[],
                         int repsPorPlan[], int repsPorSuscriptor[],
                         int repsLunes[], int repsMartes[], int repsMiercoles[],
                         int repsJueves[], int repsViernes[], int repsSabado[], int repsDomingo[]);

void mostrarReportes(int lotegeneroscargado, int lotecontenidoscargado, int lotesuscriptorcargado, int lotereproduccionescargado,
                     int codigos[], string nombres[],
                     int codigosCont[], string titulos[], char tipos[], float puntajes[], int codGenerosCont[],
                     int repsPorContenido[], int compPorContenido[],
                     int repsPorPlan[],
                     int codSus[], string nomSus[], char planes[], int repsPorSuscriptor[],
                     int repsLunes[], int repsMartes[], int repsMiercoles[],
                     int repsJueves[], int repsViernes[], int repsSabado[], int repsDomingo[]);

#endif
