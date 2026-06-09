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
                         int repsPorPlan[], int repsPorGenDia[][7], int repsPorSuscriptor[]);


#endif
