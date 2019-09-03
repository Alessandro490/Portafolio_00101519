//Fernando Daniel Gonzélez Batarsé 00014419
//Diego Alessandro Rodríguez Vilalata 00101519

#include <iostream>
using namespace std;

int multiplicacion(int a,int  b){
    if(b==1){
        return a;
    }
    else{
        return a+multiplicacion(a,b-1);
    }
}

int main(){
    int num1,num2;
    cout<<"Ingrese numero 1: ";cin>>num1;
    cout<<"Ingrese numero 2: ";cin>>num2;
    cout << "Resultado de la multiplicacion: " <<multiplicacion(num1,num2)<< endl;
}