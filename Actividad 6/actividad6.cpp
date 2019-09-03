#include <cstdlib>
#include <iostream>
using namespace std;

int a[] = {1,2,3,5,17,18,31,33};

int mostrar (int x, int low, int high){
    
if (low>high){
        return(-1);
    }
    int mid=(low+high)/2;
    if (x==a[mid]){
        return(mid);
    }
    if (x<a[mid]){
        mostrar(x, low, mid-1);
    }
    else{
        mostrar(x, mid+1, high);
    }
}
int main() {
    int x, low=0, high=8, mid,i;
    
    cout<<"digite un numero:";
    cin>>x;
    i =mostrar(x,low,high-1);
    cout<<i<<endl;
    return 0;
}

