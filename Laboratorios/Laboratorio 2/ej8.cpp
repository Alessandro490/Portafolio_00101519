#include <iostream>

using namespace std;
int digitos(int a, int conteo){
if(a/10==0){
    return conteo;      
}    
else {
    conteo++;
    digitos(a/10,conteo);
}
}
int main() {
    int m,y=1;
    cout<<"digite su numero:"<<endl;
    cin>>m;
    cout<<"los digitos:"<<digitos(m,y)<<endl;
    return 0;
}
