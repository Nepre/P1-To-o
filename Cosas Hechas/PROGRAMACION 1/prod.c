//Grupo 5
/***************************************************************************************
 * Permite almacenar en un array de registros información relativa a productos (nombre, código, precio y número
 * de unidades. Muestra un menú que permita dar de alta productos, dar de baja y calcular valor de los productos
 ***************************************************************************************/
#include <iostream>
using namespace std;

const int MAX=100;

typedef char TCadena[10];

typedef struct{
	int cod;
	float precio;
	TCadena nombre;
	int unid;
}TProducto;

typedef TProducto TAlmacen[MAX];

char menu ();
void alta (TAlmacen, int);
void baja (TAlmacen, int &);
float calcVal (TAlmacen, int);

int main(){
	TAlmacen prods;
	int numProd;
	char opcion;

	numProd=0;
	do{
		opcion=menu();
		switch (opcion){
			case '1': alta(prods, numProd);
					  numProd++;
					  break;
			case '2': baja(prods, numProd);
					  break;
			case '3': cout << "El valor es " << calcVal(prods, numProd);
					  break;
		}
	}while (opcion!='4');

	return 0;
}

char menu (){
	char op;

	cout << endl;
	do{
		cout << "1. Dar de alta" << endl;
		cout << "2. Dar de baja" << endl;
		cout << "3. Calcular el valor de los productos" << endl;
		cout << "4. Salir" << endl;
		cout << "Introduce opcion: ";
		cin >> op;
	}while (op<'1' || op>'4');

	return op;
}

//Añadir productos al vector
// equivalente a TProducto prods[100];
void alta (TAlmacen prods, int num){

	cout << "Código: ";
	cin >> prods[num].cod;
	cout << "Nombre: ";
	cin >> prods[num].nombre;
	cout << "Precio: ";
	cin >> prods[num].precio;
	cout << "Unidades: ";
	cin >> prods[num].unid;
}

//Dar de baja un producto
void baja (TAlmacen prods, int &num){
	int codigo, i, j;

	cout << "Código a dar de baja: ";
	cin >> codigo;
	i=0;
	while (i<num && codigo!=prods[i].cod)
		i++;
	if (i==num) //el producto no existe
		cout << "Error: el producto no existe";
	else{
		//Desplazamos los registros
		for (j=i; j<num-1; j++)
			prods[j]=prods[j+1];
		num--; //Decrementamos el contador de productos
	}
}

//Calcular el valor de todos los productos
float calcVal (TAlmacen prods, int num){
	int i;
	float sumaPrecios;

	sumaPrecios=0.0;
	for (i=0; i<num;i++)
		sumaPrecios=sumaPrecios+prods[i].precio*prods[i].unid;

	return sumaPrecios;
}
