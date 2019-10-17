#include <iostream>
#include <string>
using namespace std;

struct Tpersona{
    int carnet;
    string nombre;
    string apellido;
    int edad;
    int numerodetelefono;
    string correo;
};
typedef struct Tpersona Persona;

Persona solicitarPersona(){
    Persona p;
    cout << "Digite el carnet: "; cin >> p.carnet;cin, 
    cin.ignore();
    cout << "Ingrese su nombre: "; getline(cin, p.nombre);
    cout << "Ingrese su apellido: "; getline(cin, p.apellido);
    cout <<"Ingrese su edad: "; cin>> p.edad;
    cout <<"Digite su numero de telefono: "; cin>>p.numerodetelefono;
    cin.ignore();
    cout <<"Digite su correo: "; getline(cin, p.correo);   
    return p;
}

void mostrarPersona(Persona p){
    cout << "Carnet: "<<p.carnet<<endl;
    cin.ignore();
    cout << "Nombre: "<<p.nombre<<endl;
    cout << "Apellido: "<<p.apellido<<endl;
    cout <<"Edad: "<<p.edad<<endl;
    cout <<"Telefono: "<<p.numerodetelefono<<endl;
    cout <<"Correo: "<<p.correo<<endl; 
};

struct TNodo{
    Persona dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(Persona p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;
    
    pInicio = nuevo;
}

void insertarFinal(Persona p) {
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

void insertarDespuesDe(Persona p) {
    int uncarnet = 0;
    cout << "Carnet de persona de referencia: ";
    cin >> uncarnet;
    
    Nodo *s = pInicio;
    
    while(s != NULL && (s->dato).carnet != uncarnet)
        s = s->sig;
    if(s == NULL){
        cout << "Libro de referencia NO existe" << endl;
        return;
    }
    
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s->sig;
    
    s->sig = nuevo;
    cout << "persona ingresada con exito" << endl;
}

void insertarAntesDe(Persona p) {
    int uncarnet = 0;
    cout << "Carnet de persona de de referencia: ";
    cin >> uncarnet;
    
    Nodo *s = pInicio, *q = NULL;
    
    while(s != NULL && (s->dato).carnet != uncarnet){
        q = s;
        s = s->sig;
    }
    if(s == NULL){
        cout << "Persona de referencia NO existe" << endl;
        return;
    }
    
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s;
    
    if(q == NULL)
        pInicio = nuevo;
    else
        q->sig = nuevo;
    cout << "Persona ingresada con exito" << endl;
}

void agregarPersona(){
    Persona p = solicitarPersona();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\t3) Despues de\n\t4) Antes de"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);  continuar = false;
            break;
            case 2: insertarFinal(p);   continuar = false;
            break;
            case 3: insertarDespuesDe(p);   continuar = false;
            break;
            case 4: insertarAntesDe(p);   continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarPersona(s->dato);
        s = s->sig;
    }
}

void eliminarPersona(){
    int uncarnet = 0;
    cout << "Carnet de persona a eliminar: ";
    cin >> uncarnet;
    
    Nodo *p = pInicio, *q = NULL;
    
    while(p != NULL && (p->dato).carnet != uncarnet){
        q = p;
        p = p->sig;
    }
    if(p == NULL){
        cout << "Persona a elimianr NO existe" << endl;
        return;
    }
    if(q == NULL)
        pInicio = p->sig;
    else
        q->sig = p->sig;
    delete(p);
    cout << "Persona borrada!" << endl;
}

void actualizarPersona() {
    Persona p;
    int uncarnet=0;
    cout<<"Actualizar datos de la persona "<<endl;
    cout << "Carnet de persona a buscar: ";
    cin >> uncarnet;
    
    Nodo *s = pInicio;

    while(s != NULL && (s->dato).carnet != uncarnet){
                cout<<"\n\t Datos de la persona ";
                                mostrarLista();       
    }
      cout<<"\n\t Cambie los datos de la persona: ";
                      solicitarPersona();  
}

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Persona\n\t2) Ver Listado de Personas"
            << "\n\t3) Eliminar Persona\n\t4) Actualizar datos de la persona"
            << "\n\t5) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarPersona();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: cout << "Eliminando..." << endl;
                eliminarPersona();
            break;
            case 4: cout << "Actualizando... " << endl;
            actualizarPersona();
            break;
            case 5: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}