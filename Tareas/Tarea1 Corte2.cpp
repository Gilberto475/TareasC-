#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	system("Color fD");
    int num;
    cout << "Cuantos numeros desea digitar: ";
    cin >> num;

    int numerosInsercion[num], numerosBurbuja[num];
    int i, j, pos, aux;

    cout << "Digite los numeros:" << endl;
    for (i = 0; i < num; i++) {
        cout << "Digite en la Posicion[" << i << "]: ";
        cin >> numerosInsercion[i];
        numerosBurbuja[i] = numerosInsercion[i];
    }



    for (i = 1; i < num; ++i) {
        pos = i;
        aux = numerosInsercion[i];

        while (pos > 0 && numerosInsercion[pos - 1] > aux) {
            numerosInsercion[pos] = numerosInsercion[pos - 1];
            pos--;
        }
        numerosInsercion[pos] = aux;
    }



    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (numerosBurbuja[j] > numerosBurbuja[j + 1]) {
                aux = numerosBurbuja[j];
                numerosBurbuja[j] = numerosBurbuja[j + 1];
                numerosBurbuja[j + 1] = aux;
            }
        }
    }



 
    cout << "Numeros Ordenados por Insercion): ";
    for (i = 0; i < num; i++) {
        cout << numerosInsercion[i] << " ";
    }
    cout << endl;


    cout << "Numeros Ordenados por Burbuja): ";
    for (i = 0; i < num; i++) {
        cout << numerosBurbuja[i] << " ";
    }
    cout << endl;
    
    
    int buscar;
    cout << "Ingrese el numero que desea buscar: ";
    cin >> buscar;
    bool encontrado = false;
    int izq = 0;
    int derecha = num - 1;
    while (izq <= derecha) {
        int mitad = izq + (derecha - izq) / 2;
        if (numerosInsercion[mitad] == buscar) {
            cout << "Elemento " << buscar << " encontrado en la posicion " << mitad << " Ordenado por Insercion" << endl;
            encontrado = true;
            break;
        } else if (numerosInsercion[mitad] < buscar) {
            izq = mitad + 1;
        } else {
            derecha = mitad - 1;
        }
    }
    if (!encontrado)
        cout << "Elemento " << buscar << " no encontrado por Insercion)" << endl;

    izq = 0;
    derecha = num - 1;
    encontrado = false;
    while (izq <= derecha) {
        int mitad = izq + (derecha - izq) / 2;
        if (numerosBurbuja[mitad] == buscar) {
            cout << "Elemento " << buscar << " encontrado en la posicion " << mitad << " Ordenado por metodo Burbuja" << endl;
            encontrado = true;
            break;
        } else if (numerosBurbuja[mitad] < buscar) {
            izq = mitad + 1;
        } else {
            derecha = mitad - 1;
        }
    }
    if (!encontrado)
        cout << "Elemento " << buscar << " no encontrado por metodo Burbuja" << endl;
getch();
    return 0;
}
