#ifndef HASHENTRY_H
#define HASHENTRY_H
#include <iostream>

using namespace std;

template<class T>
class NodoArbol {
private:
    NodoArbol<T> *izq;
    NodoArbol<T> *der;
    T dato;
public:
    NodoArbol(T dato) : dato(dato) {
        izq = NULL;
        der = NULL;
    }

    T getDato();

    void put(T dat);
    void put(NodoArbol<T> *nuevo);

    T search(T dat);

    NodoArbol<T>* remover(T dat);

    void postorder();
    void preorder();
    void inorder();

    int porNivel(int nivel, int x);

    void espejo();

    void print(bool esDerecho, string identacion);
};

template<class T>
T NodoArbol<T>::getDato() {
    return dato;
}

template<class T>
void NodoArbol<T>::put(T dat) {
    if (dat==dato) {
        throw 1;
    }
    if (dat < dato) {
        if (izq == NULL) {
            izq = new NodoArbol<T>(dat);
            return;
        }
        izq->put(dat);
        return;
    }
    if (der == NULL) {
        der = new NodoArbol<T>(dat);
        return;
    }
    der->put(dat);
}

template<class T>
void NodoArbol<T>::put(NodoArbol<T> *nuevo) {
    if (nuevo->getDato() == NULL) {
        throw 1;
    }
    if (nuevo->getDato() < dato) {
        if (izq == NULL) {
            izq = new NodoArbol<T>(nuevo->getDato());
            return;
        }
        izq->put(nuevo);
        return;
    }
    if (der == NULL) {
        der = new NodoArbol<T>(nuevo->getDato());
        return;
    }
    der->put(nuevo);
}

template<class T>
T NodoArbol<T>::search(T dat) {
    if (dato == dat) {
        return dato;
    }
    if (dat<dato) {
        if (izq == NULL) {
            throw 1;
        }
        return izq->search(dat);
    }
    if (der == NULL) {
        throw 1;
    }
    return der->search(dat);
}

template<class T>
NodoArbol<T>* NodoArbol<T>::remover(T dat) {
    NodoArbol<T>* aux;
    if (dat == dato) {
        if (der != NULL) {
            der->put(izq);
            return der;
        }
        return izq;
    }

    if (dat < dato) {
        if (izq == NULL) {
            throw 1;
        }
        aux = izq;
        izq = izq->remover(dat);
        if (izq != aux) {
            delete aux;
        }
    }
    else {
        if (der == NULL) {
            throw 1;
        }
        aux = der;
        der = der->remover(dat);
        if (der != aux) {
            delete aux;
        }
    }
    return this;
}

template<class T>
void NodoArbol<T>::postorder() {
    if (izq != NULL) izq->postorder();
    if (der != NULL) der->postorder();
    cout << dato << ", ";
}

template<class T>
void NodoArbol<T>::preorder() {
    cout << dato << ", ";
    if (izq != NULL) izq->preorder();
    if (der != NULL) der->preorder();
}

template<class T>
void NodoArbol<T>::inorder() {
    if (izq != NULL) izq->inorder();
    cout << dato << ", ";
    if (der != NULL) der->inorder();
}

template<class T>
int NodoArbol<T>::porNivel(int nivel, int x) {
    if (nivel == x) {
        return 1;
    }
    if (izq != NULL && der != NULL) {
        return izq->porNivel(nivel,x+1) + der->porNivel(nivel,x+1);
    }
    if (izq != NULL) {
        return izq->porNivel(nivel,x+1);
    }
    if (der != NULL) {
        return der->porNivel(nivel,x+1);
    }
    return 0;
}

template<class T>
void NodoArbol<T>::espejo() {
    NodoArbol<T>* aux;
    aux = izq;
    izq = der;
    der = aux;
    if (izq != NULL) {
        izq->espejo();
    }
    if (der != NULL) {
        der->espejo();
    }
}

template<class T>
void NodoArbol<T>::print(bool esDerecho, string identacion) {
    if (der != NULL) {
        der->print(true, identacion + (esDerecho ? "     " : "|    "));
    }
    cout << identacion;
    if (esDerecho) {
        cout << " /";
    } else {
        cout << " \\";
    }
    cout << "-- ";
    cout << dato << endl;
    if (izq != NULL) {
        izq->print(false, identacion + (esDerecho ? "|    " : "     "));
    }
}

#endif //HASHENTRY_H
