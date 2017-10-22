#include <iostream>
#include "../ArbolBinario/ArbolBinario.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int A[31];
    ArbolBinario<int> arbol;

    cout << "Se creo el siguiente array:" << '\n';
    for (int i = 0; i < 30; i++) {
        A[i] = rand()%400+100;
        cout << A[i] << ", ";
    }

    for (int i = 0; i < 30; i++) {
        arbol.put(A[i]);
    }

cout << '\n' << '\n';
    arbol.print();

    cout << '\n' << '\n';

    arbol.inorder();
    return 0;
}
