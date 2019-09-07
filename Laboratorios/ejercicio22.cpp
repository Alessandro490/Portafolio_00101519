#include <iostream>

using namespace std;

int main() {
    int a[5][5];
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++){
            if(i==0 and j>=2){}
            else{ 
                if(i==1 and j>=3){}
            else{ 
                    if(i==2 and (j==0 or j==4)){}
            else{ 
                        if(i==3 and j<=1){}
            else{ 
                            if(i==4 and j<=2){}
            else{
                cout<<"Ingrese la casilla a rellenar :"<<i+1<<" "<<j+1<<endl;
                cin>>a[i][j];}
            }
            }
            }
            }
        }
    }
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            if (j==4){
                cout<<a[i][j]<<endl;
            }
            else{
                cout<<a[i][j]<<" ";
            }
        }
    }
    return 0;
}