#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Omar Rodríguez Álvarez 48679912k
*/

// PROTOTIPOS
void intercambiar(int i, int d);
void quicksort(int n, int * procesos, int izquierda, int derecha);
void imprimirVector(int *vector, int n);
int mochila(int *procesos, int numeroProcesos);

int *procesos, *indiceProceso;

int main(){

  int i, numeroProcesos;

	cout << "Introduce num.total de procesos:";
	cin >> numeroProcesos;
  cout << endl;
	procesos = new int[numeroProcesos + 1];
	indiceProceso = new int[numeroProcesos + 1];
  if(procesos != NULL){
		for(i = 1; i <= numeroProcesos; i++) {
	  	cout<<"Introduce tiempo del proceso " << i << ":";
			cin>> procesos[i];
			cout <<endl;
			indiceProceso[i] = i;
		}
  }
	quicksort(numeroProcesos, procesos, 1, numeroProcesos);
  cout << "Tiempo minimo: " << mochila(procesos, numeroProcesos);
  cout <<endl<< "Orden: ";
	imprimirVector(indiceProceso, numeroProcesos);
	return 0;
}

///
/// IMPRIMIR  procesosECTOR CON EL ORDEN ACTUAL
///
 void imprimirVector(int *vector, int n) {
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			cout << vector[i]<< endl;
		}
		else {
			cout << vector[i] << " ";
		}
	}
}
///
/// QUICKSORT
///
 void quicksort(int n, int *procesos, int izquierda, int derecha) {

	int i, d, p;
	int pivote;

	p = (izquierda + derecha)/2;
	if (p > 0) {
		// Obtenemos el  procesosalor de la posicion P del  procesosector y lo copiamos a pivote
		pivote =  procesos[p];
		// Obtenemos los  procesosalores de izquierda y derecha
		i = izquierda;
		d = derecha;

		while (i < d) {
			// nos desplazamos hacia la derecha enel  procesosector
			while ( procesos[i] < pivote) {
				i++;
			}
			// nos desplazamos hacia la izquierda enel  procesosector
			while ( procesos[d] > pivote) {
				d --;
			}
			if (i <= d) {
				intercambiar(i, d);
				i++;
				d--;
			}
		}
		if (izquierda < d) {
			quicksort(n,  procesos, izquierda, d);
		}
		if (i < derecha) {
			quicksort(n,  procesos, i, derecha);
		}
	}
}

///
/// Intercambair los elementos del  procesosector
///

void intercambiar (int i, int d) {
	int aux;
	aux =  procesos[i];
	procesos[i] =  procesos[d];
	procesos[d] = aux;

	aux = indiceProceso[i];
	indiceProceso[i] =  indiceProceso[d];
	indiceProceso[d] = aux;

}

int mochila(int *procesos, int numeroProcesos){

  int *X;
  X = new int[numeroProcesos + 1];
	int sumatorio = 0;
	for(int i = 1; i <= numeroProcesos; i++){
    //aux = i;
		X[i] = 1;
		for(int j = 1; j <= numeroProcesos; j++){
			if(X[j] == 1 ){
				sumatorio += procesos[j];
			}else{
				break;
			}
		}
	}
	return sumatorio;
}
