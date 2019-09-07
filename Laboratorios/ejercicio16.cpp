#include <iostream>

using namespace std;

int main() {
    float x, acumulador=0;
    float div;
    float a[10];
    for (int i=0;i<10;i++){
        cout<<"digite los enteros"<<endl;
        cin>>a[i];
        acumulador=acumulador+a[i];
    }
        div=acumulador/10;
    cout<<"el promedio es:"<<div<<endl;        
    return 0;
}