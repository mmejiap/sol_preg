/***************************************
/Para: Datathon                        /
/Problema 2                            /
/Hecho por: Tomas j. Casas Rodriguez   /
***************************************/
#include <cstdlib>
#include <iostream>
using namespace std;
void mostrar(int a[][50],int n)
{int x,y;
     for(y=0;y<n;y++){
                for(x=0;x<n;x++)
                    cout<<"\t"<<a[y][x];
                    cout<<endl;
                }
                cout<<endl;
}

void problema2(int a[][50],int n)
{int x,y,t;
     for(x=0;x<n-1;x++){
                for(y=0;y<n-x-1;y++){
                t=a[n-y-1][n-x-1];
                a[n-y-1][n-x-1]=a[x][y];
                a[x][y]=t;
                }
        }
}


int main(int argc, char *argv[])
{/*L MATRIZ DE ENTRADA*/
int l[50][50];
l[0][0]=11;     l[0][1]=12;     l[0][2]=13;     l[0][3]=14;
l[1][0]=21;     l[1][1]=22;     l[1][2]=23;     l[1][3]=24;
l[2][0]=31;     l[2][1]=32;     l[2][2]=33;     l[2][3]=34;
l[3][0]=41;     l[3][1]=42;     l[3][2]=43;     l[3][3]=44;
int n=4;
cout<<"\n\tMATRIZ DE ENTRADA\n"<<endl;
mostrar(l,n);
problema2(l,n);
cout<<"\n\tMATRIZ DE SALIDA\n"<<endl;
mostrar(l,n);
system("PAUSE");
return EXIT_SUCCESS;
}
