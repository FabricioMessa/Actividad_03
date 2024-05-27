#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Pseudocódigo del algortimo de cambio de monedas
Procedimiento cambioMonedas(cantidad, denominaciones)
    Ordenar denominaciones en orden descendente
    Inicializar una lista vacía, resultado

    Para cada moneda en denominaciones hacer
        Mientras cantidad sea mayor o igual a moneda hacer
            Restar moneda de cantidad
            Añadir moneda a resultado
        Fin Mientras
    Fin Para

    Si cantidad es igual a 0 entonces
        Devolver resultado
    Sino
        Devolver 'No es posible dar el cambio exacto'
    Fin Sino
Fin Procedimiento
*/

vector<int> cambioMonedas(int cantidad, vector<int>& monedas) 
{
	sort(monedas.rbegin(), monedas.rend()); //ordena las monedas de mayor a menor
	vector<int> resultado; //inicializa un vector vacio para las monedas de cambio

	for (auto& p : monedas) { //recorre las monedas
		while (cantidad >= p) { //mientras la cantidad sea mayor o igual a la moneda
			cantidad -= p; //resta la moneda de la cantidad
			resultado.push_back(p); //añade la moneda al vector de resultado
		}
	}

	if (cantidad == 0) { //si la cantidad es igual a 0
		return resultado; //devuelve el vector de resultado
	}
	else { //si no
		throw runtime_error("No es posible dar el cambio exacto"); //lanza un error
	}
}

int main() {
	vector<int> monedas = {1, 2, 5, 10, 20, 50, 100, 200 }; //vector de monedas
	int cantidad = 123; //cantidad a cambiar

	try {
		vector<int> resultado = cambioMonedas(cantidad, monedas); //llama a la funcion de cambio de monedas
		cout << "El cambio de " << cantidad << " es: "; //imprime el cambio
		for (auto& p : resultado) { //recorre el vector de resultado
			cout << p << " "; //imprime la moneda
		}
		cout << endl;
	}
	catch (const runtime_error& e) { //captura el error
		cout << e.what() << endl; //imprime el error
	}
}