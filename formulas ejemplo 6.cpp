#include <climits>
#include "formulas ejemplo 6.h"
#include <iostream>
#include <cmath>
using namespace std;

void calcularMedia(const int* array, int tam, double &media) {
    int sumatoria = 0;
    for (int i = 0; i < tam; i++) {
        sumatoria += array[i];
    } media = sumatoria*1.0 / tam;
    cout << "Media : " << media << "\n";
}


void calcularModa(int* array, int tam) {
    int N30[30];
    for (int i = 0; i < 30; i++) {
        N30[i] = i+1;
    }
    int maxRepeticion, pos = 0, repite; bool existe;
    int* repeticiones; int* numeros;

    for (int i = 0; i < 30; i++) {
        existe = false;
        for (int j = 0; j < tam; j++) {
            if (N30[i] == array[j])
                existe = true;
        }
        if (existe)
            pos++;
    } numeros = new int[pos]; repeticiones = new int[pos];

    pos = 0;
    for (int i = 0; i < 30; i++) {
        repite = 0;
        for (int j = 0; j < tam; j++) {
            if (N30[i] == array[j]) {
                numeros[pos] = N30[i];
                repite++;
            }
        }
        if (repite != 0) {
            repeticiones[pos] = repite;
            pos++;
        }
    }

    maxRepeticion = repeticiones[0];
    for (int i = 1; i < pos; i++) {
        if (maxRepeticion < repeticiones[i])
            maxRepeticion = repeticiones[i];
    }

    cout << "Moda : ";
    if (maxRepeticion == 1) {
        cout << "no existe.";
    } else {
        for (int i = 0; i < pos; i++) {
            if (maxRepeticion == repeticiones[i])
                cout << numeros[i] << "  ";
        }
    } cout << "\n";

    delete[] numeros;
    delete[] repeticiones;
    numeros = nullptr;
    repeticiones = nullptr;
}


void calcularMediana(int* array, int tam) {
    double D_mediana = 0; int I_mediana;
    //si cantidad de numeros es impar
    if (tam % 2 != 0) {
        I_mediana = array[tam / 2];
        cout << "Mediana : " << I_mediana << "\n";
    }

    //si cantidad de numeros es par
    else {
        D_mediana = (array[(tam - 1) / 2] + array[(tam - 1) / 2 + 1]) / 2.0;
        cout << "Mediana : " << D_mediana << "\n";
    }
}


void calcularDesviacionRespectoDeLaMediana_DesviacionMedia(int* array, int tam, double media) {
    double sumatoria = 0;

    //Desviación respecto de la media
    double Di;
    cout << "Desviación respecto de la media:\n";
    for (int i = 0; i < tam; i++) {
        Di = array[i] - media;
        if (Di < 0)
            Di *= -1;
        sumatoria += Di;
        cout << "\t" << i+1 << ")\t" << array[i] << "\t—>\t" << Di << "\n";
    }
    //———————————————————————————————————————————————————————————————————————————————————————
    //Desviación media
    cout << "Desviación media : " << sumatoria/tam << "\n";
    //———————————————————————————————————————————————————————————————————————————————————————
}


void calcularVarianza_DesviacionEstandar(int* array, int tam, double media) {
    double sumatoria = 0;
    //Varianza
    for (int i = 0; i < tam; i++) {
        sumatoria = pow(array[i] - media, 2);
    } cout << "Varianza : " << sumatoria/tam << "\n";
    //———————————————————————————————————————————————————————————————————————————————————————
    //Desviación estándar
    cout << "Desviación estándar : " << sqrt(sumatoria/tam);
    //———————————————————————————————————————————————————————————————————————————————————————
}