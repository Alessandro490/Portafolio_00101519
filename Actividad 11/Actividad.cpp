#include <iostream>

using namespace std;

int ubicacion=0;
int frente=0;
int maximo=0;
int n=0;

void entradaElemento(int dato, int vcola[]);
void salidaElemento(int vcola[]);

int main(){
    cout<<"Introduzca el tamano de la cola circular: ";cin>>maximo;
    int vcola[maximo];
    entradaElemento(1,vcola);
    entradaElemento(2,vcola);
    entradaElemento(3,vcola);
    entradaElemento(4,vcola);
    entradaElemento(5,vcola);
    entradaElemento(6,vcola);
    salidaElemento(vcola);
    salidaElemento(vcola);
    salidaElemento(vcola);
    entradaElemento(7,vcola);
    entradaElemento(8,vcola);
    entradaElemento(9,vcola);
    entradaElemento(10,vcola);
    entradaElemento(11,vcola);
    entradaElemento(12,vcola);
    entradaElemento(13,vcola);

    return 0;
}

void entradaElemento(int dato, int vcola[]){
    if(n==maximo){
        cout<<"Cola llena"<<endl;
    }
    else{
        ubicacion=(frente+n)%maximo;
        vcola[ubicacion]=dato;
        cout<<"Frente:"<<frente<<" n:"<<n<<" maximo:"<<maximo<<" ubicacion:"<<ubicacion<<endl;
        n++;
    }
}

void salidaElemento(int vcola[]){
    cout<<"Sale elemento: "<<vcola[frente];
    frente=(frente+1)%maximo;
    n--;
    cout<<" frente:"<<frente<<" n:"<<n<<endl;
}