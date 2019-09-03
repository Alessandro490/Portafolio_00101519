//Diego Alessandro Rodriguez Villalta 00101519
#include <string>
#include <iostream>
using namespace std;

struct continente{
string hola;
string pais;
string region;
string nacion;
string estado;
string p;
}c1;
struct paises{
     string nombre;
     string capital;
     float edad;
     int habitantes;
 }country[5];
int main() {
    int i,acumulador=0, mayor=0, sum=0, div, abr;
    cout<<"digite el continente:"<<endl;
    cin>>c1.hola;
    cout<<"primer pais:"<<endl;
    cin>>c1.pais;
    cout<<"segundo pais:"<<endl;
    cin>>c1.region;
    cout<<"tercer pais:"<<endl;
    cin>>c1.nacion;
    fflush(stdin);
    cout<<"cuarto pais:"<<endl;
    cin>>c1.estado;
    cout<<"quinto pais:"<<endl;
    cin>>c1.p;
    for (i=0;i<5;i++){
        fflush(stdin);
        cout<<"ingrese capital:";
        cin>> country[i].capital;
        cout<<"ingrese habitantes:";
        cin>>country[i].habitantes;
        cout<<"ingrese la edad del pais:";
        cin>>country[i].edad;
    acumulador=acumulador+country[i].habitantes;
    sum=(sum+country[i].edad);
    div=sum/5;
    if (country[i].habitantes>mayor){
        mayor=country[i].habitantes;
        abr=i;
    }
    }
    cout<<"los habitantes totales son:"<<acumulador<<endl;
    cout<<"la edad promedio es:"<<div<<endl;
    cout<<"Capital con mayor poblacion:"<<country[abr].habitantes<<endl;

    return 0;
}


