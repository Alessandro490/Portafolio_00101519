#include <iostream>

using namespace std;
float mediana(int *p, int tamanio){
    float sum;
    if(tamanio%2==0){
        sum=((*(p+(tamanio/2-1)))+(*(p+(tamanio/2))));
        return sum/2;
    }
    else{
        sum=(*(p+(tamanio/2)));
    }
}
int main(){
    int m;
    cout<<"ingrese cantidad de datos a usar en la mediana"<<endl;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++){
        cout<<"ingrese el numero"<<endl;
        cin>>a[i];
    }
    cout<<"la mediana del arreglo es:"<<mediana(a,m)<<endl;
    return 0;
}  
