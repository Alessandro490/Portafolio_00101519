#include <iostream>
#include <string>

using namespace std;

struct Orden{
    int revueltas;
    int frijolConQueso;
    int queso;
    bool arroz;

    Orden *sig;
};

void menu();
void mostrar(Orden *lista, int x);

int main() {
    Orden *Pinicio=NULL;
    Orden *nuevo=NULL;
    Orden *aux=NULL;
    string sas;
    int x;
    do{
        menu();
        cout<<"Digite una opcion: ";
        cin>>x;
        if(x==0){
            cout<<"Saliendo del programa"<<endl;
        }
        
        else if(x==1){
            cout<<"Añadiendo..."<<endl;
            nuevo= new Orden;
            cout<<"Cuantas pupusas revueltas: ";
            cin>>nuevo->revueltas;
            cout<<"Cuantas pupusas frijol con queso: ";
            cin>>nuevo->frijolConQueso;
            cout<<"Cuantas pupusas queso: ";
            cin>>nuevo->queso;
            cout<<"¿Desea sus pupusas de arroz:?";
            cin>>sas;
             if(sas=="si" or sas=="yes" or sas=="SI" or sas=="Si"){
                nuevo->arroz=true;
            }
            else{
                nuevo->arroz=false;
            }
            nuevo->sig=NULL;
            
            if(Pinicio==NULL){
                Pinicio=nuevo;
            }
            else{
                aux=Pinicio;
                while(aux!=NULL){
                    aux=aux->sig;
                }
                nuevo->sig=aux;
                aux=nuevo;
            }
            
        } 
        else if(x==2){
            cout<<"mostrando..."<<endl;
             mostrar(Pinicio,1);
        }
        else{
            cout<<"Digito un numero incorrecto"<<endl;
        }
    }while(x!=0);
            
    return 0;
}

void menu(){
    cout<<"0. Salir"<<endl;
    cout<<"1. Digite su pedido"<<endl;
    cout<<"2. Mostrar su pedido"<<endl;
}

void mostrar(Orden *lista, int x){
    if(lista==NULL){
        return;
    }
    else{
         if(lista->arroz==true){
            cout<<"Pupusas son de arroz"<<endl;
        }
        else{
            cout<<"Pupusas son de maiz"<<endl;
        }
        cout<<"Pupusas revueltas:"<<lista->revueltas<<endl;
        cout<<"Pupusas de frijol con queso:"<<lista->frijolConQueso<<endl;
        cout<<"Pupusas de queso:"<<lista->queso<<endl;

        return mostrar(lista->sig,++x);
    }
}