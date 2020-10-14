#include <iostream>
#include <iomanip>
#include "formulas ejemplo 6.h"
using namespace std;

int main() {
    int tam; double media = 0;
    int* pNumeros;

    cout << "Cantidad de números: "; cin >> tam;
    pNumeros = new int[tam];
    cout << "Números:\n";
    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        pNumeros[i] = rand() % 30 + 1;
        cout << pNumeros[i] << "\t";
    } cout << "\n\n";

    cout << fixed << setprecision(1);
    calcularMedia(pNumeros, tam, media);
    calcularModa(pNumeros, tam);
    calcularMediana(pNumeros, tam);
    calcularDesviacionRespectoDeLaMediana_DesviacionMedia(pNumeros, tam, media);
    calcularVarianza_DesviacionEstandar(pNumeros, tam, media);
    
    delete[] pNumeros;
    pNumeros = nullptr;
    return 0;
}

