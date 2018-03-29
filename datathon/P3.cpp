/***************************************
/Para: Datathon                        /
/Problema 3                            /
/Hecho por: Tomas j. Casas Rodriguez   /
***************************************/
#include <stdlib.h>
#include <iostream>
#include <time.h>
struct nodo{
int x;
struct nodo *siguiente;
};
typedef struct nodo *plista;
void insertar_inicio(plista &lista,int valor);
void mostrar(plista lista);
void ordenaElimina(plista lista);
using namespace std;

int main(int argc, char *argv[]){
int op;	
do{cout<<endl;
cout<<"********** MENU ************\n"<<endl;
cout<<"\t1---> Iniciar "<<endl;
cout<<"\t2---> Ejemplo"<<endl;
cout<<"\t3---> Aleatorio"<<endl;
cout<<"\t4---> Salir\n"<<endl;
cout<<"Ingrese la opcion"<<endl;
cin>>op;
switch(op){
case 1:{
		plista lista=NULL;
		int n,i,valor;
		cout<<"Numero de datos:";cin>>n;
		for(i=0;i<n;i++){
		cout<<"elemento "<<i+1<< " :";
		cin>>valor;
		insertar_inicio(lista,valor);
		}
		cout<<endl<<"Arreglo original:"<<endl;
		mostrar(lista);
		//FUNCION QUE  ELIMINA DATOS Y ORDENA
		ordenaElimina(lista);
		cout<<"Arreglo  final : "<<endl;
		mostrar(lista);
		break;
		}
case 2:{
		static int tabla[7]={2,6,3,1,1,8,10};
		plista lista=NULL;
		int i,valor;
		for(i=0;i<7;i++){
		valor=tabla[i];
		insertar_inicio(lista,valor);
		}
		cout<<endl<<"\nArreglo original:"<<endl;
		mostrar(lista);
		//FUNCION QUE  ELIMINA DATOS Y ORDENA
		ordenaElimina(lista);
		cout<<"\nArreglo  final : "<<endl;
		mostrar(lista);
		break;
		}
case 3:{
		plista lista=NULL;
		int i,n,valor;
		cout<<"Numero de datos:";cin>>n;
		srand(unsigned(time(NULL)));
		for(i=0;i<n;i++){
		valor=rand()%15;
		insertar_inicio(lista,valor);
		}
		cout<<endl<<"\nLista original:"<<endl;
		mostrar(lista);
		//FUNCION QUE  ELIMINA DATOS Y ORDENA
		ordenaElimina(lista);
		cout<<"\nLista  final : "<<endl;
		mostrar(lista);
		break;
		}
}
}while(op!=4);


  system("PAUSE");
    return EXIT_SUCCESS;
}

void ordenaElimina(plista lista){
plista q,p,r,ant;
int num;
q=lista;
while(q!=NULL){
num=q->x;
ant=q;
r=q->siguiente;
	while(r!=NULL){
		if(num==r->x){
		cout<<"Eliminando..."<<num<<endl;	
		ant->siguiente=r->siguiente;
		p=r;
		r=r->siguiente;
		delete(p);
		}
		else{
		ant=r;
		r=r->siguiente;
		}
	}//fin while
q=q->siguiente;
}//fin while

plista actual,sgte,marca;
int i;marca=NULL;
while(marca!=lista->siguiente){
	actual=lista;
	sgte=actual->siguiente;
	while(sgte!=marca){
		if(actual->x > sgte->x)
		{i=sgte->x;
		sgte->x=actual->x;
		actual->x=i;
		}
	actual=actual->siguiente;
	sgte=actual->siguiente;
	}
marca=actual;
}


}

void insertar_inicio(plista &lista,int valor){
plista q;
q=new (struct nodo);
q->x=valor;
q->siguiente=lista;
lista=q;
}

void mostrar(plista lista){
while(lista!=NULL){
cout<<lista->x<<"  ";
lista=lista->siguiente;
}
cout<<endl;
}


