#include <cstdlib>
#include <iostream>

using namespace std;

struct numbers {
   int number;
   numbers *sig;
};

void displaysuma(int y, numbers *PInicio){
    int i, par=0, impar=0;
    if (PInicio==NULL){
        return;        
    }
    else if (PInicio->number%2==0){
        par=par+PInicio->number;
        PInicio=PInicio->sig;
    }
    else{
       impar=impar+PInicio->number;
       PInicio=PInicio->sig; 
    }
    cout<<"La suma de los números pares es: "<<par<<endl;
    cout<<"La suma de los números impares es: "<<impar<<endl;
}

int main(){
    int i, x, r;
    int L=0;
    numbers *PInicio=NULL;
    numbers *nuevo=NULL;
    bool continuar=true;
    do {
        cout<<"opciones \n 1) Digitar numero: \n 2) Mostrar suma de numeros:"
        <<" \n 3) Salir."<<endl;
        cin>>L;
    switch (L){
    case 1: nuevo= new numbers; 
    cout<<"Digite el numero: "<<endl;
    cin>>nuevo->number;
            if(PInicio==NULL){
                PInicio=nuevo;
            }
            else{
                nuevo->sig=PInicio;
                PInicio=nuevo;
            }
    break;
    case 2: {cout<<"Mostrando..."<<endl;
    displaysuma(2, PInicio);}
    break;
    case 3: {cout<<"Saliendo..."<<endl;
            break;}
            default: cout << "Opcion Erronea!" << endl;
            break;}
    } while(L!=3);
    return 0;
}