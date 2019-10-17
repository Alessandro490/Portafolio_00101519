#include <iostream>
#include <string>
using namespace std;

struct Libro{
    char titulo[35];
    int numPaginas;
    Libro *sig;
    };
typedef struct Libro Libro;

Libro solicitarLibro(){
    Libro p;
    cin.ignore();
    cout << "Titulo: "; cin>> p.titulo;
    cout << "Numero de paginas: "; cin>> p.numPaginas;
    return p;
}

void mostrarLibro(Libro p){
    cout << "Titulo: " << p.titulo << endl;
    cout << "Numeros de paginas del libro: " << p.numPaginas<< endl;
    cout << endl;
}

struct TNodo{
    Libro dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(Libro p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;
    
    pInicio = nuevo;
}

void insertarFinal(Libro p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;
    
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void agregarLibro(){
    Libro p = solicitarLibro();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final \n";
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
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarLibro(s->dato);
        s = s->sig;
    }
}

void buscarpag(Libro *lista, string nombre){
    if(lista==NULL){
        cout<<"No se encontro un libro con ese nombre"<<endl;
        return;
    }
    else if(nombre==lista->titulo){
        cout<<"El numero total de paginas del libro "<<lista->titulo<<" es: "<<lista->numPaginas<<endl;
        return;
    }
    else{
        return buscarpag(lista->sig,nombre);
    }
}
int main(){
    Libro *lista =NULL;
    Libro *nuevo=NULL;
    string nombre;
    cout << "Inicializando..." << endl;
    pInicio = NULL;
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Libro\n\t2) Ver Libros"
            << "\n\t3) Buscar Libro" "\n\t4) Salir \n";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
            nuevo = new Libro;
            cin.clear();cin.ignore(1000,'\n');
            cout<<"Titulo: "; cin>>nuevo->titulo;
            cout<<"Numero de paginas: ";cin>>nuevo->numPaginas;

            nuevo->sig=NULL;

            if(lista==NULL){
                lista=nuevo;
            }
            else{
                nuevo->sig=lista;
                lista=nuevo;
            }
            break;
            case 2: cout << "Mostrando..." << endl;
                if(lista==NULL){
            cout<<"No se encontro un libro con ese nombre"<<endl;
            }
                mostrarLista();
            break;
            case 3: cout << "Buscando..." << endl;
            cin.clear();cin.ignore(1000,'\n');
            cout<<"Digite el titulo del libro para saber su numero de paginas: ";getline(cin,nombre);
            buscarpag(lista,nombre);
            break;
            case 4: continuar = false;
            break;
            default: cout << "Dato incorrecto!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}


