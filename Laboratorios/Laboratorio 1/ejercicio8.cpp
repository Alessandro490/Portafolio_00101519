#include <iostream>

using namespace std;

int contar (int m){
   
    int x=0;
   
    if (m==1){
        return 0;
        }
        else{
        x= 1+contar(m-1);
        cout<<x<<endl;
        return x;
        }
   
}

int main(void) {
    int l, x;
    cout<<"Ingrese el numero a utilizar"<<endl;
    cin>>l;
    contar(l);
    cout<<l<<endl; 
    int i=1;
    while (i<l){
        cout<<l-i<<endl;
        i++;
    }
    return 0;
}
