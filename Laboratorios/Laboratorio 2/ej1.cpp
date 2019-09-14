#include <iostream>

using namespace std;
int MCD(int a,int b){
if(a%b==0){
    return b;      
}    
else {
    MCD(b,a%b);
}
}
int main() {
    int n,m;
    cout<<"digite numero mayor:"<<endl;
    cin>>m;
    cout<<"digite numero menor:"<<endl;
    cin>>n;
    cout<<"El mcd es:"<<MCD(m,n)<<endl;
    return 0;
}
