#include <iostream>
#include "funciones.h"
using namespace std;


void mostrarmenu() {
    cout << "1. Cargar lote de generos " << endl;
    cout << "2. Cargar lote de contenidos " << endl;
    cout << "3. Cargar lote de suscriptores " << endl;
    cout << "4. Cargar lote de reproducciones " << endl;
    cout << "5. Mostrar reportes (submenu) " << endl;
    cout << "6. Salir del programa " << endl;
    cout << " Ingrese una opcion: " << endl;
}

//LOTE DE GENEROS

int cargargeneros(int codigos[], string nombres[]) {

    for (int i = 0; i < 8; i++) {
        int cg;
        string ng;
        cout << "\nRegistro " << i + 1 << " de 8:" << endl;
        do {
            cout << "Ingrese el codigo de genero (1 a 8)" << endl;
            cin >> cg;
            if (cg <= 0 || cg > 8)
                cout << "El codigo de genero ingresado es incorrecto" << endl;
        } while (cg <= 0 || cg > 8);
        cin.ignore();
        cout << "Ingrese el nombre del genero..." << endl;
        getline(cin, ng);
        codigos[i] = cg;
        nombres[i] = ng;
    }

    cout << "La carga del lote numero 1 se ha realizado con exito!!" << endl;
    return 1;
}

//LOTE DE CONTENIDOS

int cargarcontenidos(int lotegeneroscargado, int codigosCont[], string titulos[], char tipos[], int duraciones[], float puntajes[], int codGenerosCont[], int codigos[]) {
    string titulo;
    char tipo;
    int duracion, puntaje, codcont, codg;
    if (lotegeneroscargado==0) {
        cout << "ERROR: Debe cargar el lote 1 primero." << endl;
        return 0;
    }
    for (int i = 0; i < 15; i++) {
        cout << "Ingrese el codigo del contenido(3 digitos no consecutivos)" << endl;
        cin >> codcont;
        cout << "Ingrese el titulo" << endl;
        cin.ignore();
        getline(cin, titulo);
        cout << "Ingrese el tipo de contenido (P/S/D)" << endl;
        cin >> tipo;
        if (tipo != 'P' && tipo != 'S' && tipo != 'D') {
            cout << "Se ha ingresado un tipo de contenido erroneo, recuerde que se puede utilizar P/S/D " << endl;
            return 0;
        }
        cout << "Ingrese la duracion promedio por episodio o pelicula en minutos" << endl;
        cin >> duracion;
        cout << "Ingrese el puntaje promedio del contenido segun resenas de usuarios(1.0 -5.0)" << endl;
        cin >> puntaje;
        if (puntaje < 1 || puntaje > 5) {
            cout << "El puntaje ingresado es incorrecto. Recuerde que tiene que ser entre 1.0 - 5.0" << endl;
            return 0;
        }
        cout << "Ingrese el codigo de genero (cargado previamente)" << endl;
        cin >> codg;
        bool existe = false;
        for (int j = 0; j < 8; j++) {
            if (codigos[j] == codg)
                existe = true;
        }
        if (existe == false) {
            cout << "Error: El genero ingresado no existe en el Lote 1. Se interrumpe la carga." << endl;
            return 0;
        }
        codigosCont[i] = codcont;
        titulos[i] = titulo;
        tipos[i] = tipo;
        duraciones[i] = duracion;
        puntajes[i] = puntaje;
        codGenerosCont[i] = codg;
    }
    cout << "\nLa carga del lote numero 2 se ha realizado con exito!" << endl;
    return 1;
}

//LOTE DE SUSCRPTORES

int cargarsuscriptores(int codSus[], int cantPan[], string nomSus[], char planes[]) {
    int codsuscriptor, cantpantallas;
    string nomsuscriptor;
    char plan;
    for (int i = 0; i < 12; i++) {
        cout << "Ingrese el codigo de suscriptor (1 a 12)" << endl;
        cin >> codsuscriptor;
        if (codsuscriptor < 1 || codsuscriptor > 12) {
            cout << "El codigo ingresado es invalido. Debe ingresar un codigo entre el 1 y el 12" << endl;
            return 0;
        }
        cout << "Ingrese el nombre y apellido del suscriptor" << endl;
        cin >> nomsuscriptor;
        cout << "Ingrese el plan de suscriptor (B = Basico, S = Estandar, P = Premium. Solo se aceptan estos valores.)" << endl;
        cin >> plan;
        if (plan != 'B' && plan != 'S' && plan != 'P') {
            cout << "El plan ingresado es incorrecto. Debe ingresar: B = Basico, S = Estandar, P = Premium." << endl;
            return 0;
        }
        cout << "Ingrese la cantidad de pantallas habilitadas segun el plan (1 a 4)" << endl;
        cin >> cantpantallas;
        if (cantpantallas < 1 || cantpantallas > 4) {
            cout << "El valor ingresado es incorrecto. La cantidad de pantallas debe ser un numero del 1 al 4" << endl;
            return 0;
        }
        codSus[i] = codsuscriptor;
        cantPan[i] = cantpantallas;
        nomSus[i] = nomsuscriptor;
        planes[i] = plan;
    }
    cout << "\nLote de suscriptores cargado correctamente." << endl;
    return 1;
}

//LOTE DE REPRODUCCIONES

int cargarreproducciones(int lotegeneroscargado, int lotecontenidoscargado, int lotesuscriptorcargado,
                         int codigosCont[], char tipos[], int duraciones[], int codGenerosCont[],
                         int codSus[], char planes[],
                         int repsPorContenido[], int compPorContenido[],
                         int repsPorPlan[], int repsPorGenDia[][7], int repsPorSuscriptor[]) {
    if (lotegeneroscargado == 0 || lotecontenidoscargado == 0 || lotesuscriptorcargado == 0) {
        cout << "ERROR: Debe cargar los lotes 1, 2 y 3 primero." << endl;
        return 0;
    }
    int nroReproduccion;
    cout << "Ingrese el numero de reproduccion (0 para terminar): ";
    cin >> nroReproduccion;
    while (nroReproduccion != 0) {

        int codContenido;
        cout << "Codigo de contenido: ";
        cin >> codContenido;
        int indiceContenido = -1;
        for (int i = 0; i < 15; i++) {
            if (codigosCont[i] == codContenido) {
                indiceContenido = i;
                break;
            }
        }
        if (indiceContenido == -1) {
            cout << "ERROR: Codigo de contenido inexistente." << endl;
            cout << "Ingrese el numero de reproduccion (0 para terminar): ";
            cin >> nroReproduccion;
            continue;
        }

        int codSuscriptor;
        cout << "Codigo de suscriptor: ";
        cin >> codSuscriptor;
        int indiceSuscriptor = -1;
        for (int i = 0; i < 12; i++) {
            if (codSus[i] == codSuscriptor) {
                indiceSuscriptor = i;
                break;
            }
        }
        if (indiceSuscriptor == -1) {
            cout << "ERROR: Codigo de suscriptor inexistente." << endl;
            cout << "Ingrese el numero de reproduccion (0 para terminar): ";
            cin >> nroReproduccion;
            continue;
        }

        int dia;
        cout << "Dia de la semana (1=Lunes ... 7=Domingo): ";
        cin >> dia;
        if (dia < 1 || dia > 7) {
            cout << "ERROR: Dia invalido." << endl;
            cout << "Ingrese el numero de reproduccion (0 para terminar): ";
            cin >> nroReproduccion;
            continue;
        }

        int completo;
        cout << "Completo la reproduccion? (1=Si / 0=No): ";
        cin >> completo;
        if (completo != 0 && completo != 1) {
            cout << "ERROR: Valor invalido, ingrese 0 o 1." << endl;
            cout << "Ingrese el numero de reproduccion (0 para terminar): ";
            cin >> nroReproduccion;
            continue;
        }
    return 1;
}
                         }
