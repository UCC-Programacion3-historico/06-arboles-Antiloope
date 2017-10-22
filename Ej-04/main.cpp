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

    A.espejo();

    cout << '\n';
    A.print();
    cout << '\n';
    return 0;
}
