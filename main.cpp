#include <bits/stdc++.h>

using namespace std;

long long int valoresX[2000005],valoresY[2000005];

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

long long int solveSubsetSum(long long int a[], int n, long long int s) {

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

int main() {

    int n;
    cin >> n;

    long long int datos[n];

	for (int i = 0; i < n; i++){
		int aux;
		cin >> aux;
		datos[i] = aux;
	}

    int s;
    cin >> s;

    cout << "Resultado: " << solveSubsetSum(datos, n, s) << endl;

    return 0;
}