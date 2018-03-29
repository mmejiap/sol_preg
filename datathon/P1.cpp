/***************************************
/Para: Datathon                        /
/Problema 1                            /
/Hecho por: Tomas j. Casas Rodriguez   /
***************************************/
#include <cstdlib>
#include <iostream>
using namespace std;
//FUNCION QUE IMPRIME LOS DOS ULTIMOS NUMEROS DE LA SECUENCIA DE FIBONACCI
//Se usa programacion dinamica
unsigned long  finonacci(unsigned long n){
static unsigned long tabla[10000];
//valores iniciales
static int i=1;
tabla[0]=0;
tabla[1]=1;
//casos bases
if(n==tabla[0])return tabla[0];
if(n==tabla[1]) return tabla[1];
//si el parametro ingresado no es numero de fibonacci , no valido
 if(tabla[i]>n && n>tabla[i-1]){
cout<<"El parametro ingresado no es numero de fibonacci"<<endl;
return 0;
}
//Si el numero de finonacci n , no es igual al llenado hasta ahora
else if(n!=tabla[i]){
i++;
//se agrega otro valor de fibonacci al arreglo
tabla[i]=tabla[i-1]+tabla[i-2];
return finonacci(n);
}
//caso que se busca : que el numero n sea igual al elemento de tabla[i]
else cout<<"-> "<<tabla[i-1]<<" , "<<tabla[i-2]<<endl;
}

int main()
{
int op;	
do{cout<<endl;
cout<<"********** MENU ************\n"<<endl;
cout<<"\t1---> Iniciar "<<endl;
cout<<"\t2---> Ejemplo"<<endl;
cout<<"\t3---> Salir\n"<<endl;
cout<<"Ingrese la opcion"<<endl;
cin>>op;
switch(op){
case 1:{
		unsigned long  n=0;
		cout<<"\nIngrese el numero de fibonacci N=";
		cin>>n;
		cout<<"\nSalida : ";
		n=finonacci(n);
		break;
		}
case 2:{
unsigned long  n=0;
		cout<<"\nEjemplo fibonacci N=6765 ";
		cout<<"\nSalida : ";
		n=finonacci(6765);
		break;
		}
}
}while(op!=3);
return EXIT_SUCCESS;
}
