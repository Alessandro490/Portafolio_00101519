#include <iostream>

using namespace std;

int hanoi(int n)
{
    if(n == 1)
        return 1;
    else
        return 2 * hanoi(n-1) + 1;
}

int main()
{
    int discos ;
    cout<< "       TORRES DE HANOI  \n\n";
    
    cout<< "Numero de discos: ";
    cin>> discos;

    cout<<"\nMovimientos necesarios: ";
    cout<< hanoi(discos);
    
    return 0;
}