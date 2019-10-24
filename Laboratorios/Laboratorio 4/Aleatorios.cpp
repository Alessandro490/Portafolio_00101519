#include <cstdlib>
#include <iostream>
using namespace std;

struct numbers {
   int number;
   numbers *sig;
};

void display (int y,numbers *PInicio){
    if(PInicio==NULL){
        return;
    }
    else{
        cout<<"Numero "<<y<<":"<<PInicio->number<<endl;
        return display(++y, PInicio->sig);
    }
}

void par(int z, numbers *PInicio){
     if(PInicio==NULL){
        return;
    }
     else if(PInicio->number%2==0){
        cout<<"Numero "<<z<<":"<<PInicio->number<<endl;
}
}
void impar(int m, numbers *PInicio){
    if(PInicio==NULL){
        return;
    }
    else if(PInicio->number%2==1){
        cout<<"Numero "<<m<<":"<<PInicio->number<<endl;
        }
    }
void invertir(int g, numbers *PInicio){
       if(PInicio==NULL){
        return;
    }
    else{
        cout<<"Numero "<<g<<":"<<PInicio->number<<endl;
        return;
    }
}

int main(){
    int i, x, r;
    int L=0;
    numbers *PInicio=NULL;
    numbers *nuevo=NULL;
    bool continuar=true;
    do {
        cout<<"opciones \n 1) Agregue cantidad de numeros aleatorios: \n 2) Mostrar numeros en lista:"
        <<"\n 3) Mostrar numeros pares:  \n 4) Mostrar numeros impares: "    
        <<"\n 5) Mostrar numeros invertidos: \n 6) Salir."<<endl;
        cin>>L;
    switch (L){
    case 1: cout<<"Digite la cantidad de numeros aleatorios a generar: "<<endl;
    cin>>x;
    srand (time(NULL));
    nuevo= new numbers;
            for(i=0;i<x;i++) {
		nuevo->number = (rand() % 100) + 1;
                nuevo->sig=NULL;
                cout<<"numeros: "<<nuevo->number<<endl;
            if(PInicio==NULL){
                PInicio=nuevo;
            }
            else{
                nuevo->sig=PInicio;
                PInicio=nuevo;
            }
            }
    break;
    case 2 :cout<<"Mostrando..."<<endl;
    display(2, PInicio);
    break;
    case 3 :cout<<"Pares de la lista..."<<endl;
    par(3, PInicio);
    break;
    case 4 :cout<<"Impares de la lista..."<<endl;
    impar(4, PInicio);
    break;
    case 5 :cout<<"Mostrando numeros invertido..."<<endl;
    invertir(5, PInicio);
    break;
    case 6: cout<<"Saliendo"<<endl;
            break;
            default: cout << "Opcion Erronea!" << endl;
            break;
    } 
    }while(L!=6);
    return 0;
}
