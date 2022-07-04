#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Este Proyecto fue realizado por RaulIsmaelTrochezBarahona
//Programa para el registro de Productos Cosmeticos con diferentes opciones en la base de datos txt
// como ser: Agregar,Ver productos,Buscar,Modificar,Eliminar

int menu(){
	int x;
	system("cls");
	cout<<"<<-------BIENVENIDO---------->>"<<endl<<endl;
	cout<<"1. Agregar Producto"<<endl;
	cout<<"2. Ver Productos"<<endl;
	cout<<"3. Buscar Productos"<<endl;
	cout<<"4. Modificar Producto"<<endl;
	cout<<"5. Eliminar Producto"<<endl;
	cout<<"6. Salir"<<endl;
	cout<<"Elige una Opcion:";
	cin>>x;
	return x;
	
}

bool verifica(string cod){
	ifstream leer("Proyecto1.txt", ios::in);
	string Nom;//nombre
	string Gen;//genero
	string Orig;//origen
	string Prec;//precio
	string Cod;//codigo
	leer>>Nom;
	while(!leer.eof()){
		leer>>Gen;
		leer>>Orig;
		leer>>Prec;
		leer>>Cod;
		if(Cod == cod){
			leer.close();
			return false;
		}
		leer>>Nom;
	}
	leer.close();
	return true;
}

void agregar(ofstream &es) {
	system("cls");
	string Nom, Gen, Orig, Prec, Cod;
	
	es.open("Proyecto1.txt", ios::out | ios::app);

	cout<<"Nombre del Producto: ";
	cin>>Nom;
	cout<<"Genero: ";
	cin>>Gen;
	cout<<"Origen: ";
	cin>>Orig;
	cout<<"Precio: ";
	cin>>Prec;
	cout<<"Codigo: ";
	cin>>Cod;
		
	es<<Nom<<" "<<Gen<<" "<<Orig<<" "<<Prec<<" "<<Cod<<"\n";
	es.close();

}

void verRegistros(ifstream &Lec){
	system("cls");
	string nom;//nombre
	string gen;//genero
	string orig;//origen
	string prec;//precio
	string cod;//codigo
	Lec.open("Proyecto1.txt", ios::in);
	cout<<"-----Productos Cosmeticos Registrados-----"<<endl<<endl;
		while(!Lec.eof()){
			Lec>>nom;
			Lec>>gen;
		    Lec>>orig;
		    Lec>>prec;
			Lec>>cod;
			if(!Lec.eof()){
			
			cout<<"Nombre---: "<<nom<<endl;
			cout<<"Genero---: "<<gen<<endl;
			cout<<"Origen---: "<<orig<<endl;
			cout<<"Precio---: "<<prec<<endl;
			cout<<"Codigo---: "<<cod<<endl;
			cout<<"-------------------------"<<endl;
			}
		}						
				Lec.close();
				system("pause");	
	}

void buscarProducto(ifstream &Lec){
	system("cls");
	Lec.open("Proyecto1.txt", ios::in);
	string nom,gen,orig,prec,cod,codaux;
	bool encontrado = false;
	cout<<"Digite el Codigo: ";
	cin>>codaux;
	Lec>>nom;
	while(!Lec.eof() && !encontrado){
		Lec>>gen;
		Lec>>orig;
		Lec>>prec;
		Lec>>cod;
		
		if(cod == codaux){
		cout<<"Nombre---: "<<nom<<endl;
		cout<<"Genero---: "<<gen<<endl;
		cout<<"Origen---: "<<orig<<endl;
		cout<<"Precio---: "<<prec<<endl;
		cout<<"Codigo---: "<<cod<<endl;
		cout<<"-------------------------"<<endl;
		encontrado = true;
			
		}
		Lec>>nom;
	}
	Lec.close();
	
	if(!encontrado)
		cout<<"Producto NO Encontrado en los Registros"<<endl;
		system("pause");
	
}

void modificar(ifstream &Lec){
	system("cls");
	string nom;//nombre
	string gen;//genero
	string orig;//origen
	string prec;//precio
	string cod;//codigo
	string nomaux;//Nombre Auxiliar
	string codaux;//Codigo auxiliar
	Lec.open("Proyecto1.txt", ios::in);
	ofstream aux("Indice.txt", ios::out);//escritura
	if(Lec.is_open()){
		cout<<"Codigo: ";
		cin>>codaux;
		Lec>>nom;//nombre
		while(!Lec.eof()){
			Lec>>gen;//genero
			Lec>>orig;//origen
			Lec>>prec;//precio
			Lec>>cod;//codigo
			
			if(cod == codaux){
				cout<<"Ingrese el Nuevo Nombre del Producto: ";
				cin>>nomaux;
				aux<<nomaux<<" "<<gen<<" "<<orig<<" "<<prec<<" "<<cod<<"\n";
			}else{	
				
				aux<<nom<<" "<<gen<<" "<<orig<<" "<<prec<<" "<<cod<<"\n";
					
		}
		Lec>>nom;
	}
		Lec.close();
		aux.close();
	}else
	cout<<"Error! "<<endl;
	remove("Proyecto1.txt");
	rename("Indice.txt","Proyecto1.txt");
	
}

void eliminar(ifstream &Lec){
		system("cls");
	string nom;
	string gen;
	string orig;
	string prec;
	string cod;
	string codaux;
	string nomaux;
	Lec.open("Proyecto1.txt", ios::in);
	ofstream aux("Indice.txt", ios::out);
	if(Lec.is_open()){
		cout<<"Codigo ";
		cin>>codaux;
		Lec>>nom;
		while(!Lec.eof()){
			Lec>>gen;
			Lec>>orig;
			Lec>>prec;
			Lec>>cod;
			if(cod == codaux){
				cout<<"Producto Eliminado con EXITO!!** ";
				Sleep(1500);
			
			}else{
				aux<<nom<<" "<<gen<<" "<<orig<<" "<<prec<<" "<<cod<<"\n";

			}
			Lec>>nom;
			
		}
		Lec.close();
		aux.close();
	}else
	cout<<"Error! "<<endl;
	remove("Proyecto1.txt");
	rename("Indice.txt","Proyecto1.txt");
	
}
int main() {
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		system("cls");
		op = menu();
		switch(op)
		{
			case 1: 
					agregar(Esc);
			break;
			
			case 2:
					verRegistros(Lec);
			break;
			
			case 3:
					buscarProducto(Lec);
			break;
			
			case 4:
				 	modificar(Lec);		
			break;
			
			case 5:
					eliminar(Lec);
			break;
			
		}
		
	}while(op != 6);
	
	return 0;
}
