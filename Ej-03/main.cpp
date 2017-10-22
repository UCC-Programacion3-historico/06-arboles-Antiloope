#include <iostream>
#include "../ArbolBinario/ArbolBinario.h"

int main() {
    int a = 1;
    ArbolBinario<int> A;
    while (a > 0) {
        cout << "Ingrese un nodo para el arbol: \n" << endl;
        cin >> a;
        A.put(a);
    }

    cout << '\n';
    A.print();
    cout << '\n';

    cout << "Solicitar nivel: " << '\n';
    cin >> a;
    cout << "Los nodos en ese nivel son: " << A.porNivel(a) << '\n';

    return 0;
}
