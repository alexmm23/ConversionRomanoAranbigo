#include <iostream>
#include <string>
using namespace std;
//Adrian Alejandro Montes Mendoza
//si meto 9 el romano debe ser IX
//Numeros romanos son: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000.
//
//Maximo - [MMMCMXCIX] 3999
//Minimo - [--------I] 1
//Millares [    ]
//Si el numero es > 3999 y < 1 entonces es invalido
//como comparar que una cadena no tenga mas de 3 M,C,X y que no tenga mas de 1 D,L,V.

template <typename T, size_t N>
T ultimo_elem(T(&a)[N])
{
    return a[N - 1];
}

char* StringToCharArray(string, int);
bool validar_romano(char[], int);
int* letra_a_numero(char[], int);
int Sumatoria_total(int*, int);

bool validar_romano(char _romano[], int _tamano) {
    int i = 0, validNum = 1;
    int counterC = 0, counterM = 0, counterX = 0, counterI = 0;
    int counterD = 0, counterL = 0, counterV = 0;
    for (i = 0; i < _tamano; i++) {

        if (_romano[i] == 'c' || _romano[i] == 'C') {
            counterC++;
        }
        else if (_romano[i] == 'M' || _romano[i] == 'm') {
            counterM++;
        }
        else if (_romano[i] == 'I' || _romano[i] == 'i') {
            counterI++;
        }
        else if (_romano[i] == 'X' || _romano[i] == 'x') {
            counterX++;
        }
        else if (_romano[i] == 'D' || _romano[i] == 'd') {
            counterD++;
        }
        else if (_romano[i] == 'L' || _romano[i] == 'l') {
            counterL++;
        }
        else if (_romano[i] == 'V' || _romano[i] == 'v') {
            counterV++;
        }
        else 
        {
            validNum = 0;
            break;
        }
    }
    if (counterC > 3 || counterM > 3 || counterX > 3 || counterD > 1 || counterL > 1 || counterV > 1 || validNum == 0) {
        //cout << "Numero invalido" << endl;
        return false;

    }
    else 
    { 
        //cout << "Numero valido" << endl;
        return true; 
    }
}
int* letra_a_numero(char ArrayChar[], int _tamano) {
    int sumatoria = 0, i;
    int* numerosEnt = new int[_tamano];

    for (i = 0; i < _tamano; i++) {
        if (ArrayChar[i] == 'c' || ArrayChar[i] == 'C') {
            numerosEnt[i] = 100;
        }
        else if (ArrayChar[i] == 'M' || ArrayChar[i] == 'm') {
            numerosEnt[i] = 1000;
        }
        else if (ArrayChar[i] == 'I' || ArrayChar[i] == 'i') {
            numerosEnt[i] = 1;
        }
        else if (ArrayChar[i] == 'X' || ArrayChar[i] == 'x') {
            numerosEnt[i] = 10;
        }
        else if (ArrayChar[i] == 'D' || ArrayChar[i] == 'd') {
            numerosEnt[i] = 500;
        }
        else if (ArrayChar[i] == 'L' || ArrayChar[i] == 'l') {
            numerosEnt[i] = 50;
        }
        else if (ArrayChar[i] == 'V' || ArrayChar[i] == 'v') {
            numerosEnt[i] = 5;
        }
        else
        {
            break;
        }
    }
    return numerosEnt;
}
char* StringToCharArray(string Cadena, int Tamano) {
    if (!(Cadena.empty()) && Tamano != 0) {
        char* ArrayChar = new char[Tamano];
        //Obtenemos los caracteres uno a uno y posicionamos en el Arreglo.
        for (int i = 0; i < Tamano; i++) {
            ArrayChar[i] = Cadena[i];
        }
       
        return ArrayChar;
        
    }
    
}
int Sumatoria_total(int* NumsToSum, int _tamano) {
    int total = 0;
  
    for (int i = 0; i < _tamano; i++) {
        if (i + 1 < _tamano && NumsToSum[i] < NumsToSum[i + 1]) {
            total += NumsToSum[i + 1] - NumsToSum[i];
            i++;
        }
        else total += NumsToSum[i];
    }
    return total;
}
int main()
{
    int respuesta = 1;
    int Tamano = 0;
    string romano[1] = {};
    char* ArregloCaracteres;
    int* ArregloNumeros = NULL;
    bool validate;
    
    do {
        cout << "Adrian Alejandro Montes Mendoza - 22110135 " << endl;
        cout << "Convertidor de numeros romanos a arabigos" << endl;
        getline(cin, romano[0]);
        Tamano = romano[0].length();
        ArregloCaracteres = StringToCharArray(romano[0], Tamano);
        validate = validar_romano(ArregloCaracteres, Tamano);

        if (validate == false)
        {
            cout << "Ingrese un numero valido" << endl;
        }
        else if (validate == true)
        {
            ArregloNumeros = letra_a_numero(ArregloCaracteres, Tamano);
            cout << Sumatoria_total(ArregloNumeros, Tamano) << endl;
        }
        cout << "Desea convertir otro numero [1 - Si / 2 - No]" << endl;
        cin >> respuesta;
        system("cls");
        cin >> romano[0];

    } while (respuesta == 1);
    
    return 0;
}
