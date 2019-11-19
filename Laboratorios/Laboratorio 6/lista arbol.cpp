#include <iostream>
#include <string>

using namespace std;

struct TElemento{
    int variable;    
};

typedef struct TElemento elemento;

struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

Arbol crearArbol(int x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

void asignarIzq(Arbol a, int unDato){
    if(a == NULL)
    cout << "Error: arbol vacio."<<endl;
    else if(a->izq != NULL)
        cout<<"Error: Subarbol IZQ ya existe."<<endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a){
        int numero = 0;
    cout << "Numero a agregar: ";
    cin >> numero;
   
    Arbol p = a;
   
    while(true){
        if(numero == p->info){
            cout << "Error: " << numero << " ya existe" << endl;
            return;
        }
        else if(numero < p->info){
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }
   
    if(numero < p->info)
        asignarIzq(p, numero);
    else
        asignarDer(p, numero);
}

void preorden(Arbol a){
    if(a != NULL){
        cout << " " << a->info;
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
    }
}
void postorden(Arbol a){
    if(a != NULL){
        postorden(a->izq);
        postorden(a->der);
        cout << " " << a->info;
    }
}

void recorrerArbol(Arbol a){
    cout << "Recorrido PRE orden:"; preorden(a); cout << endl;
    cout << "Recorrido IN orden:"; inorden(a); cout << endl;
    cout << "Recorrido POST orden:"; postorden(a); cout << endl;
}



elemento solicitardato(){
    elemento p;
    cout << "Dato: "; cin >> p.variable;
}

void mostrardatos(elemento p){
    cout << "Dato: " << p.variable << endl;
    cout << endl;
}

struct TNodo{
    elemento dato;
    struct TNodo *sig;
};
typedef struct TNodo LISTA;
LISTA*pInicio;

void insertarInicio(elemento p) {
    LISTA *nuevo = new LISTA;
    nuevo->dato = p;
    nuevo->sig = pInicio;
   
    pInicio = nuevo;
}

void insertarFinal(elemento p) {
    LISTA *nuevo = new LISTA;
    nuevo->dato = p;
    nuevo->sig = NULL;
   
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        LISTA *p = pInicio;
        LISTA *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}


void agregarLibro(){
    elemento p = solicitardato();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);  continuar = false;
            break;
            case 2: insertarFinal(p);   continuar = false;
            break;
           
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    LISTA *s = pInicio;

    while (s != NULL) {
        mostrardatos(s->dato);
        s = s->sig;
    }
}


int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Dato\n\t2) Ver datos"
            << "\n\t0) Salir de la lista y agregar datos a los árboles\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarLibro();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
           
            case 0: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
   
    int variable = 0;
    cout<<"Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> variable;
   
    Arbol arbol = crearArbol(variable);
   
    continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar \n\t2) Recorrer"
        << "\n\t3) Salir\n\t Opcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: agregarNodo(arbol);
            break;
            case 2: recorrerArbol(arbol);
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
   
    return 0;
}
