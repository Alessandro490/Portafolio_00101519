#include <iostream>
using namespace std;

struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;
int n=0;

Arbol crearArbol(int x){
    Arbol p = new Nodo;
    p->info= x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}
int z=0;
int aux=0;

void asignarIzq(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
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

void recorrerPersonalizado(Arbol p){
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n Se encuentra en el nodo " << p->info <<endl;
        cout << "\t1)Agregar nodo izquierda\n\t2)Agregar nodo derecha\n";
        cout << "\t3)Ir sub-arbol izquierdo\n\t4)Ir sub-arbol derecho\n";
        cout << "\t5)Regresar al nodo padre\n\tOpcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                if (p->izq == NULL){
                    int numero = 0;
                    cout << "Numero a agregar: ";
                    cin >> numero;
                    asignarIzq(p, numero);
                    cout << "Numero agregado exitosamente" << endl;
                }
                else
                    cout << "Error: ya existe sub-arbol izquierdo" << endl;
                break;
            case 2:
                if (p->der == NULL){
                    int numero = 0;
                    cout << "Numero a agregar: ";
                    cin >> numero;
                    asignarDer(p, numero);
                    cout << "Numero agregado exitosamente" << endl;
                }
                else
                    cout << "Error: ya existe sub-arbol derecho" << endl;
                break;
            case 3:
                if (p->izq != NULL)
                    recorrerPersonalizado(p->izq);
                else
                    cout << "Error: NO existe sub-arbol izquierdo" << endl;
                break;
            case 4:
                if (p->der != NULL)
                    recorrerPersonalizado(p->der);
                else
                    cout << "Error: NO existe sub-arbol derecho" << endl;
                break;
            case 5:
                continuar = false;
                break;
            default:
                cout << "Error: Opcion no valida" << endl;
                break;
        }
    }while(continuar);
}

//------ Recorrer un arbol (in, pre y post orden) ------
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
void mostrarnodos(Arbol a){
   if (a == NULL){
           z+=1;
        mostrarnodos(a->izq);
        mostrarnodos(a->der);
    }
   } 

int mostrarprofundidad(Arbol a) {
    if (a == NULL){
        return 0;
    }
    else {
        int izquierda = mostrarprofundidad(a->izq);
        int derecha = mostrarprofundidad(a->der);
        if (izquierda <= derecha){
            return derecha + 1;
        }
        else{
            return izquierda + 1;
        }
    }
}
void sumarNodo(Arbol a){
    if (a !=NULL){
        aux+=a->info;
        sumarNodo (a->izq);
        sumarNodo (a->der);
    }
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

int main(){
    int variable = 0;
    cout<<"Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> variable;

    Arbol arbol = crearArbol(variable);

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu:\n\t1) Mostrar recorridos";
        cout << "\n\t2) Recorrer personalizado";
        cout << "\n\t3) Mostrar profundidad\n\t4) Suma\n\tOpcion elegida: "
        <<"\n\t 5) Salir"<<endl;
        cin >> opcion;
        switch(opcion){
            case 1: agregarNodo(arbol);
            break;
            case 2: recorrerArbol(arbol);
            break;
            case 3: recorrerPersonalizado(arbol);
            break;
            case 4: cout<<"Profundidad: "<<mostrarprofundidad(arbol)-1<<endl;
            break;
            case 5: aux=0; sumarNodo(arbol); cout<<"La suma es:"<<aux<<endl;
            break;
            case 6: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}

