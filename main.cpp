//Programa que: Implementa el Algoritmo de Meet In The Middle con Backtracking.
//Programadores: León Emiliano García Pérez [A00573074], Carla Morales López [A01639225].
//Fecha de entrega: Jueves 11 de Noviembre de 2022.

//Inclusión de librerías.
#include <bits/stdc++.h>

//Ajuste a estandar.
using namespace std;

//Definición de variables globales.
long long int valoresX[2000005];
long long int valoresY[2000005];

//Función que calcula un subarreglo, reicbe dos arreglos de long long ints, uno a y uno x, un entero n y un entero c; no tiene valor de retorno ya que actualiza las variables que fueron enviadas como parámetro.
void calcularSubArreglo(long long int a[], long long int x[], int n, int c) {

	for (int i=0; i<(1<<n); i++){

		long long int s;
		s = 0;

		for (int j=0; j<n; j++)
			if (i & (1<<j))
				s += a[j+c];
		x[i] = s;
	}

}

//Función que implementa el algoritmo de Meet In The Middle, recibe un arreglo de long long ints, un entero n, y un lon long int s. Retorna el valor resultante long long int.
long long int reunionEnElMedio(long long int a[], int n, long long int s) {

	calcularSubArreglo(a, valoresX, n/2, 0);
	calcularSubArreglo(a, valoresY, n-n/2, n/2);

	int tamanioX;
	int tamanioY;

	tamanioX = 1<<(n/2);
	tamanioY = 1<<(n-n/2);

	sort(valoresY, valoresY+tamanioY);

	long long int max;
	max = 0;

	for (int i=0; i<tamanioX; i++) {

		if (valoresX[i] <= s) {

			int p = lower_bound(valoresY, valoresY+tamanioY, s-valoresX[i]) - valoresY;

			if (p == tamanioY || valoresY[p] != (s-valoresX[i]))
				p--;

			if ((valoresY[p]+valoresX[i]) > max)
				max = valoresY[p]+valoresX[i];
		}
	}

	return max;
}

//Función que ejecuta el código main driver de ejecución.
int main() {

    int n;

	cout << "Input: " << endl;
    cin >> n;

    long long int datos[n];

	for (int i = 0; i < n; i++){
		int aux;
		cin >> aux;
		datos[i] = aux;
	}

    int s;
    cin >> s;

    cout << "Output: " << endl;
	cout << reunionEnElMedio(datos, n, s) << endl;

    return 0;
}