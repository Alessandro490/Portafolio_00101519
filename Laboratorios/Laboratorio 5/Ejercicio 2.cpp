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

int Par=0,Impar=0;
int Sumapar=0, SumaImpar=0;
int negativo=0,Cero=0, Positivo=0;

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

void sumanodospares(Arbol a){
    if(a != NULL){
        if(a->info%2==0){
            Sumapar+=a->info;
        }
        sumanodospares(a->izq);
        sumanodospares(a->der);
    }
}

void sumanodosimpares(Arbol a){
    if(a != NULL){
        if(a->info%2==1){
            SumaImpar+=a->info;
        }
        sumanodosimpares(a->izq);
        sumanodosimpares(a->der);
    }
}

void recorrerArbol(Arbol a){
    cout << "Recorrido PRE orden:"; preorden(a); cout << endl;
    cout << "Recorrido IN orden:"; inorden(a); cout << endl;
    cout << "Recorrido POST orden:"; postorden(a); cout << endl;
}
void mostrarnodopositivo(Arbol a){
    if(a != NULL){
        if(a->info>0){
            Positivo+=1;
        }
        mostrarnodopositivo(a->izq);
        mostrarnodopositivo(a->der);
    }
}

void mostrarnodos(Arbol a){
   if (a == NULL){
           z+=1;
        mostrarnodos(a->izq);
        mostrarnodos(a->der);
    }
   }

void mostrarnodospares(Arbol a){
    if(a != NULL){
        if(a->info%2==0){
            Par+=1;
        }
        mostrarnodospares(a->izq);
        mostrarnodospares(a->der);
    }
}

void mostrarnodosimpares(Arbol a){
    if(a != NULL){
        if(a->info%2==1){
            Impar+=1;
        }
        mostrarnodosimpares(a->izq);
        mostrarnodosimpares(a->der);
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

void mostrarnodonegativo(Arbol a){
    if(a != NULL){
        if(a->info<0){
            negativo+=1;
        }
        mostrarnodonegativo(a->izq);
        mostrarnodonegativo(a->der);
    }
}

void mostrarnodosceros(Arbol a){
    if(a != NULL){
        if(a->info==0){
            Cero+=1;
        }
        mostrarnodosceros(a->izq);
        mostrarnodosceros(a->der);
    }
}


int main(){
    int variable = 0;
    cout<<"Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> variable;

    Arbol arbol = crearArbol(variable);

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu:\n\t1) Agregar Nodo";
        cout << "\n\t2) Recorrer Nodo";
        cout << "\n\t3) Recorrer Personalizado \n\t4) Mostrar profundidad \n\t5) Par e impar"
        <<"\n\t6) Suma par \n\t7) Suma impar"
        <<"\n\t8) Negativo, positivo y ceros \n\t9) Salir  \n\tOpcion elegida:" <<endl;
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
            case 5: Par=0;mostrarnodospares(arbol);cout<<"Cantidad de nodos pares: "<<Par <<endl; 
            Impar=0;mostrarnodosimpares(arbol);cout<<"Cantidad de nodos impares: "<<Impar<<endl;
            break;
            case 6: Sumapar=0;sumanodospares(arbol);cout<<"Suma de los nodos pares: "<<Sumapar<<endl;
            break;
            case 7: SumaImpar=0;sumanodosimpares(arbol);cout<<"Suma de los nodos impares: "<<SumaImpar<<endl;
            break;
            case 8: negativo=0;mostrarnodonegativo(arbol);cout<<"Cantidad de nodos negativos: "<<negativo<<endl;
            Cero=0;mostrarnodosceros(arbol);cout<<"Cantidad de nodos ceros: "<<Cero<<endl;
            Positivo=0;mostrarnodopositivo(arbol);cout<<"Cantidad de nodos positivos: "<<Positivo<<endl;
            break;
            case 9: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}

