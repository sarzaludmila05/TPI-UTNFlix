#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    srand(time(0));
    int opcion;

    // Lote 1
    int codigos[8] = {0};
    string nombres[8] = {""};
    int lotegeneroscargado = 0;

    // Lote 2
    int codigosCont[15] = {0};
    string titulos[15] = {""};
    char tipos[15] = {' '};
    int duraciones[15] = {0};
    float puntajes[15] = {0.0};
    int codGenerosCont[15] = {0};
    int lotecontenidoscargado = 0;

    // Lote 3
    int codSus[12] = {0};
    int cantPan[12] = {0};
    string nomSus[12] = {""};
    char planes[12] = {' '};
    int lotesuscriptorcargado = 0;

    // Lote 4
    int repsPorContenido[15] = {0};
    int compPorContenido[15] = {0};
    int repsPorPlan[3] = {0};
    int repsPorSuscriptor[12] = {0};

    // Los 7 vectores para reemplazar la matriz
    int repsLunes[8] = {0};
    int repsMartes[8] = {0};
    int repsMiercoles[8] = {0};
    int repsJueves[8] = {0};
    int repsViernes[8] = {0};
    int repsSabado[8] = {0};
    int repsDomingo[8] = {0};

    int lotereproduccionescargado = 0;

    do {
        mostrarmenu();
        cin >> opcion;

        if (opcion >= 0 && opcion <= 6) {
            switch(opcion) {
            case 1:
                cout << "Seleccionaste la opcion numero 1." << endl;
                lotegeneroscargado = cargargeneros(codigos, nombres);
                break;
            case 2:
                cout << "Seleccionaste la opcion numero 2." << endl;
                lotecontenidoscargado = cargarcontenidos(lotegeneroscargado, codigosCont, titulos, tipos, duraciones, puntajes, codGenerosCont, codigos);
                break;
            case 3:
                cout << "Seleccionaste la opcion numero 3." << endl;
                lotesuscriptorcargado = cargarsuscriptores(codSus, cantPan, nomSus, planes);
                break;
            case 4:
                cout << "Seleccionaste la opcion numero 4." << endl;
                lotereproduccionescargado = cargarreproducciones(
                    lotegeneroscargado, lotecontenidoscargado, lotesuscriptorcargado,
                    codigosCont, tipos, duraciones, codGenerosCont,
                    codSus, planes,
                    repsPorContenido, compPorContenido,
                    repsPorPlan, repsPorSuscriptor,
                    repsLunes, repsMartes, repsMiercoles, repsJueves, repsViernes, repsSabado, repsDomingo);
                break;
            case 5:
                cout << "Seleccionaste la opcion numero 5 (Reportes)." << endl;
                mostrarReportes(lotegeneroscargado, lotecontenidoscargado, lotesuscriptorcargado, lotereproduccionescargado,
                    codigos, nombres,
                    codigosCont, titulos, tipos, puntajes, codGenerosCont,
                    repsPorContenido, compPorContenido,
                    repsPorPlan,
                    codSus, nomSus, planes, repsPorSuscriptor,
                    repsLunes, repsMartes, repsMiercoles, repsJueves, repsViernes, repsSabado, repsDomingo);
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            }
        } else {
            cout << "El numero ingresado es incorrecto." << endl;
        }

    } while (opcion != 6);

    return 0;
}
