//Programa que: Implementa el Algoritmo de Meet In The Middle.
//Programadores: León Emiliano García Pérez [A00573074], Carla Morales López [A01639225].
//Fecha de entrega: Jueves 17 de Noviembre de 2022.

//Inclusión de librerías.
#include <bits/stdc++.h>

//Ajuste a estandar.
using namespace std;

//Definición de variables globales.
long long int valoresX[100000000];
long long int valoresY[100000000];

//Función que calcula un subarreglo, recibe dos arreglos de long long ints, uno datos y uno x, un entero n y un entero c; no tiene valor de retorno ya que actualiza las variables que fueron enviadas como parámetro.
void calcularSubArreglo(long long int datos[], long long int x[], int n, int c) { //Complejidad Computacional: O(n2^n).

    //Complejidad Computacional: O(n2^n).
	for (int i = 0; i < (1 << n); i++) { //Complejidad Computacional: O(2^n).

		long long int s;
		s = 0;

		for (int j = 0; j < n; j++){
			if (i & (1 << j)){
				s += datos[j + c]; //Complejidad Computacional: O(n).
            }
        }

		x[i] = s;
	}

}

//Función que implementa el algoritmo de Meet In The Middle, recibe un arreglo de long long ints con los datos, un entero objetivo, y un long long int s. Retorna el valor resultante long long int.
long long int reunionEnElMedio(long long int datos[], int n, long long int objetivo) { //Complejidad Computacional: O(2^(n/2) log(2^(n/2))).
	
	int tamanioX;
	int tamanioY;
	long long int max;

	calcularSubArreglo(datos, valoresX, n / 2, 0); //Complejidad Computacional: O( (n/2) 2^ (n/2)).
	calcularSubArreglo(datos, valoresY, n - n / 2, n / 2); //Complejidad Computacional: O((n-n/2) 2^ (n-n/2)).

	max = 0;
	tamanioX = 1 << (n / 2);
	tamanioY = 1 << (n - n / 2);

	sort(valoresY, valoresY + tamanioY); //Complejidad Computacional: O(n log n) -> O((n-n/2) log (n-n/2)).
	
	for (int i = 0; i < tamanioX; i++) {  //Complejidad Computacional: O(2^(n/2)).

		if (valoresX[i] <= objetivo) {

			int p;
            p = lower_bound(valoresY, valoresY + tamanioY, objetivo - valoresX[i]) - valoresY; //Complejidad Computacional: L(n).

			if (p == tamanioY || valoresY[p] != (objetivo - valoresX[i])){
				p--;
            }

			if ((valoresY[p] + valoresX[i]) > max){
				max = valoresY[p] + valoresX[i];
            }

		}

	}

	return max;
}

//Función que ejecuta el código main driver de ejecución.
int main() { //Dentro de su ejecución lineal, se encuentra un ciclo for con complejidad O(n), y se ejecuta el algoritmo de solución para Meet In The Middle, de Complejidad  Computacional: O(2^(n/2) log(2^(n/2))).

	long long int n;
    long long int objetivo;

    cout << "INPUT: " << endl;
    cout << "n:" << endl;
    cin >> n;

    cout << "set:" << endl;
    long long int datos[n];

    for (long long int i = 0; i < n; i++){ //Compejidad Computacional O(n).
        long long int aux;
        cin >> aux;
        datos[i] = aux;
    }

    cout << "s:" << endl;
    cin >> objetivo;

    cout << "OUTPUT: " << endl;
    cout << reunionEnElMedio(datos, n, objetivo) << endl; //Complejidad Computacional: O(2^(n/2) log(2^(n/2))).

    return 0;
}