#include <iostream>

using namespace std;

typedef char TCadena[20];

typedef struct{
  TCadena nombre;
  double lat;
  double longi;
  float area;
  float hab;
}TMunicipio;

typedef TMunicipio espanya[100];

int menu();
void nuevo(espanya munisipios, int &lugar);
void todo(espanya munisipios, int lugar);
void cien(espanya munisipios, int lugar);
void letra(espanya munisipios, int lugar);
//void atol(espanya munisipios, int lugar);

int main() {
  espanya munisipios;
  int lugar;
  int op;

  do {
    op = menu();
    if (op == 1) {
      nuevo(munisipios, lugar);
    }
    else if (op == 2) {
      todo(munisipios, lugar);
    }
    else if (op == 3) {
      cien(munisipios, lugar);
    }
    else if (op == 4){
      letra(munisipios, lugar);
    }
    else{
      cout<<"Qué cojones es HTML bro."<<endl;
      /*atol(munisipios, lugar);*/
    }
  } while(op != 6);



  return 0;
}

int menu(){
int op;
do {
  cout<<"Menú: "<<endl;
  cout<<"1.-Añadir nuevo Municipio"<<endl;
  cout<<"2.-Listar los Municipios"<<endl;
  cout<<"3.-Listar Municipios con más de 100K habitantes"<<endl;
  cout<<"4.-Listar Municipios por letra"<<endl;
  cout<<"5.-Exportar a HTML"<<endl;
  cout<<"6.-Salir"<<endl;
  cin>>op;
  cout<<"Opción seleccionada: "<<op<<endl;
} while(op<1 || op>6);
return op;

}

void nuevo(espanya munisipios, int &lugar){
  cout <<"Nombre: ";
  cin.get();
  cin.getline(munisipios[lugar].nombre, 20);
  cout<<endl;
  cout <<"Latitud: ";
  cin>>munisipios[lugar].lat;
  cout<<endl;
  cout <<"Longitud: ";
  cin>>munisipios[lugar].longi;
  cout<<endl;
  cout <<"Área(Km^2): ";
  cin>>munisipios[lugar].area;
  cout<<endl;
  cout <<"Número de habitantes: ";
  cin>>munisipios[lugar].hab;
  cout<<endl;
  lugar++;
}
void todo(espanya munisipios, int lugar){
  for (int i = 0; i < lugar; i++) {
    cout<<munisipios[i].nombre<<", ";
    cout<<munisipios[i].lat<<", ";
    cout<<munisipios[i].longi<<", "<<endl;
    cout<<munisipios[i].area<<", ";
    cout<<munisipios[i].hab<<endl;
  }
}
void cien(espanya munisipios, int lugar){
  for (int i = 0; i < lugar; i++) {
    if (munisipios[i].hab>=100000) {
      cout<<munisipios[i].nombre<<", ";
      cout<<munisipios[i].lat<<", ";
      cout<<munisipios[i].longi<<", "<<endl;
      cout<<munisipios[i].area<<", ";
      cout<<munisipios[i].hab<<endl;
    }
  }
}
void letra(espanya munisipios, int lugar){
  char let;
  cin>>let;
  for (int i = 0; i < lugar; i++) {
    if(munisipios[i].nombre[0] == let){
      cout<<munisipios[i].nombre<<", ";
      cout<<munisipios[i].lat<<", ";
      cout<<munisipios[i].longi<<", "<<endl;
      cout<<munisipios[i].area<<", ";
      cout<<munisipios[i].hab<<endl;
    }
  }
}
