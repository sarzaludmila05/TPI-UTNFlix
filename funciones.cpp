#include <iostream>
#include "funciones.h"
#include <cstdlib>
#include <ctime>
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

    for (int i = 0; i < 3; i++) {
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
    for (int i = 0; i < 4; i++) {
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
    for (int i = 0; i < 5; i++) {
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
                         int repsPorPlan[], int repsPorSuscriptor[],
                         int repsLunes[], int repsMartes[], int repsMiercoles[],
                         int repsJueves[], int repsViernes[], int repsSabado[], int repsDomingo[]) {

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

 //ACUMULADOR
repsPorContenido[indiceContenido]++;
        if (completo == 1) {
            compPorContenido[indiceContenido]++;
        }

        repsPorSuscriptor[indiceSuscriptor]++;

        int indiceGenero = codGenerosCont[indiceContenido] - 1;

        if (dia == 1) repsLunes[indiceGenero]++;
        else if (dia == 2) repsMartes[indiceGenero]++;
        else if (dia == 3) repsMiercoles[indiceGenero]++;
        else if (dia == 4) repsJueves[indiceGenero]++;
        else if (dia == 5) repsViernes[indiceGenero]++;
        else if (dia == 6) repsSabado[indiceGenero]++;
        else if (dia == 7) repsDomingo[indiceGenero]++;

        char planDelSuscriptor = planes[indiceSuscriptor];

        if (planDelSuscriptor == 'B') {
            repsPorPlan[0]++;
        } else if (planDelSuscriptor == 'S') {
            repsPorPlan[1]++;
        } else if (planDelSuscriptor == 'P') {
            repsPorPlan[2]++;
        }

cout << "--> Reproduccion " << nroReproduccion << " registrada correctamente." << endl;
        cout << "\nIngrese el numero de reproduccion (0 para terminar): ";
        cin >> nroReproduccion;

    }

    cout << "\n Lote de reproducciones cargado correctamente!" << endl;
    return 1;
}

void mostrarReportes(int lotegeneroscargado, int lotecontenidoscargado, int lotesuscriptorcargado, int lotereproduccionescargado,
                     int codigos[], string nombres[],
                     int codigosCont[], string titulos[], char tipos[], float puntajes[], int codGenerosCont[],
                     int repsPorContenido[], int compPorContenido[],
                     int repsPorPlan[],
                     int codSus[], string nomSus[], char planes[], int repsPorSuscriptor[],
                     int repsLunes[], int repsMartes[], int repsMiercoles[],
                     int repsJueves[], int repsViernes[], int repsSabado[], int repsDomingo[]) {

    if (lotegeneroscargado == 0 || lotecontenidoscargado == 0 ||
        lotesuscriptorcargado == 0 || lotereproduccionescargado == 0) {
        cout << "Error: Faltan cargar lotes para poder ver los reportes." << endl;
        return;
    }

//SUBMENU

    int opcionReporte;
    do {
        cout << "\n=== MENU DE REPORTES ===" << endl;
        cout << "1. Ranking de contenidos mas reproducidos" << endl;
        cout << "2. Actividad por plan de suscripcion" << endl;
        cout << "3. Reproducciones por genero y dia de la semana" << endl;
        cout << "4. Contenidos sin reproducciones" << endl;
        cout << "5. Top 5 suscriptores + sorteo de acceso anticipado" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcionReporte;

        switch(opcionReporte) {
        case 1: {
            int auxrep, auxcc, auxcomp, auxgen;
            string auxtc;
            char auxtipo;
            for (int x = 0; x < 15; x++) {
                for (int j = 0; j < 14; j++) {
                    if (repsPorContenido[j] < repsPorContenido[j+1]) {

                        auxrep = repsPorContenido[j];
                        repsPorContenido[j] = repsPorContenido[j+1];
                        repsPorContenido[j+1] = auxrep;

                        auxcc = codigosCont[j];
                        codigosCont[j] = codigosCont[j+1];
                        codigosCont[j+1] = auxcc;

                        auxtc = titulos[j];
                        titulos[j] = titulos[j+1];
                        titulos[j+1] = auxtc;

                        auxtipo = tipos[j];
                        tipos[j] = tipos[j+1];
                        tipos[j+1] = auxtipo;

                        auxgen = codGenerosCont[j];
                        codGenerosCont[j] = codGenerosCont[j+1];
                        codGenerosCont[j+1] = auxgen;

                        auxcomp = compPorContenido[j];
                        compPorContenido[j] = compPorContenido[j+1];
                        compPorContenido[j+1] = auxcomp;
                    }
                }
            }

//REPORTE 1
            cout << "RANKING DE CONTENIDOS" << endl;
            for (int i = 0; i < 15; i++) {
                cout << "\n-----------------------------------" << endl;
                cout << "Codigo: " << codigosCont[i] << endl;
                cout << "Titulo: " << titulos[i] << endl;
                cout << "Tipo: " << tipos[i] << endl;
                string nombreGeneroActual = "";
                for (int g = 0; g < 8; g++) {
                    if (codigos[g] == codGenerosCont[i])
                        nombreGeneroActual = nombres[g];
                }
                cout << "Genero: " << nombreGeneroActual << endl;
                cout << "Reproducciones totales: " << repsPorContenido[i] << endl;
                if (repsPorContenido[i] > 0)
                    cout << "Porcentaje completadas: " << (compPorContenido[i] * 100.0) / repsPorContenido[i] << "%" << endl;
                else
                    cout << "Sin reproducciones" << endl;
            }
            break;
        }

//REPORTE 2
        case 2: {
            cout << "ACTIVIDAD POR PLAN" << endl;
            int totalSemana = repsPorPlan[0] + repsPorPlan[1] + repsPorPlan[2];
            string nombresPlanes[3] = {"Basico", "Estandar", "Premium"};
            for (int p = 0; p < 3; p++) {
                cout << "\n-----------------------------------" << endl;
                cout << "Plan: " << nombresPlanes[p] << endl;
                cout << "Reproducciones totales: " << repsPorPlan[p] << endl;
                if (totalSemana > 0)
                    cout << "Porcentaje: " << (repsPorPlan[p] * 100.0) / totalSemana << "%" << endl;
                else
                    cout << "Porcentaje: 0% (No hubo reproducciones)" << endl;
            }
            break;
        }

//REPORTE 3
            case 3: {
            cout << "REPRODUCCIONES POR GENERO Y DIA" << endl;

            for (int g = 0; g < 8; g++) {
                cout << "\n-----------------------------------" << endl;
                cout << "Genero: " << nombres[g] << endl;
                cout << "Lunes: " << repsLunes[g] << " reproducciones" << endl;
                cout << "Martes: " << repsMartes[g] << " reproducciones" << endl;
                cout << "Miercoles: " << repsMiercoles[g] << " reproducciones" << endl;
                cout << "Jueves: " << repsJueves[g] << " reproducciones" << endl;
                cout << "Viernes: " << repsViernes[g] << " reproducciones" << endl;
                cout << "Sabado: " << repsSabado[g] << " reproducciones" << endl;
                cout << "Domingo: " << repsDomingo[g] << " reproducciones" << endl;
            }
            break;
        }

//REPORTE 4
        case 4: {
            cout << "CONTENIDOS SIN REPRODUCCIONES" << endl;
            bool contSinReps = false;
            for (int i = 0; i < 15; i++) {
                if (repsPorContenido[i] == 0) {
                    contSinReps = true;
                    cout << "\n-----------------------------------" << endl;
                    cout << "Codigo: " << codigosCont[i] << endl;
                    cout << "Titulo: " << titulos[i] << endl;
                    cout << "Tipo: " << tipos[i] << endl;
                    string nombreGenero = "";
                    for (int g = 0; g < 8; g++) {
                        if (codigos[g] == codGenerosCont[i])
                            nombreGenero = nombres[g];
                    }
                    cout << "Genero: " << nombreGenero << endl;
                    cout << "Calificacion promedio: " << puntajes[i] << endl;
                }
            }
            if (contSinReps == false)
                cout << "Todos los contenidos tuvieron reproducciones esta semana." << endl;
            break;
        }
        case 5:{
int auxreps,auxcod;
char auxplan;
 string auxnom;
for (int x=0;x<12;x++){
    for (int i=0;i<11;i++){
        if (repsPorSuscriptor[i]<repsPorSuscriptor[i+1]){

            auxreps=repsPorSuscriptor[i];
            repsPorSuscriptor[i]=repsPorSuscriptor[i+1];
            repsPorSuscriptor[i+1]=auxreps;

            auxcod=codSus[i];
            codSus[i]=codSus[i+1];
            codSus[i+1]=auxcod;

            auxnom = nomSus[i];
            nomSus[i] = nomSus[i+1];
            nomSus[i+1] = auxnom;

            auxplan=planes[i];
            planes[i]=planes[i+1];
            planes[i+1]=auxplan;


        }
    }
}

//reporte 5
        cout << "\n--- LOS 5 SUSCRIPTORES CON MAS ACTIVIDAD ---" << endl;
            for (int i = 0; i < 5; i++) {
                cout << "Puesto #" << i + 1 << ":" << endl;
                cout << "Nombre: " << nomSus[i] << endl;
                cout << "Codigo: " << codSus[i] << endl;
                cout << "Plan: " << planes[i] << endl;
                cout << "Reproducciones: " << repsPorSuscriptor[i] << "\n" << endl;
            }

           int ganador1 = rand() % 5;
            int ganador2;

            do {
                ganador2 = rand() % 5;
            } while (ganador2 == ganador1);

            cout << "--- GANADORES DEL SORTEO DE ACCESO ANTICIPADO ---" << endl;
            cout << "Primer ganador: " << nomSus[ganador1] << " (" << repsPorSuscriptor[ganador1] << " reproducciones)" << endl;
            cout << "Segundo ganador: " << nomSus[ganador2] << " (" << repsPorSuscriptor[ganador2] << " reproducciones)" << endl;

            break;
        }
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion incorrecta." << endl;
            break;
        }
    } while (opcionReporte != 0);
}

