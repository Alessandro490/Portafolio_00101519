#include <iostream>
#include <stack>
using namespace std;

int main() {
   //dejando pila vacía
   stack <double> m;
   m.push(7.2);
   m.push(8.9);
   m.push(3.5);
   m.push(15.4);
   cout<<"El tamanio de la pila es:"<<m.size()<<endl;
   m.pop();
   m.pop();
   m.pop();
   cout<<"El primer elemento es:"<<m.top()<<endl;
   
   //dejando pila intacta
   if(m.empty()){
        cout<<-1;
    }
    else{
        float B= 0;
        int A=0;
        A=m.size();
        float arreglo[A];
        for(int i=0;i<A;i++){
            if(m.empty()){
                cout<<-1;
            }
            else{
                B=m.top();
                m.pop();
                arreglo[A-1-i]=B;
            }
        }
        for(int i=0;i<A;i++){
            m.push(arreglo[i]);

        }
         cout<<"El primer elemento (con pila intacta) es:"<<arreglo[0]<<endl;
    }
    return 0;
}

