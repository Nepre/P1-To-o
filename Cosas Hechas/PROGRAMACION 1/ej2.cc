#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;

typedef struct {

    char nombre[50];
    int precio;

} TObjeto;


int menu() {

    int op;

    cout << "1. NUEVO OBJETO" << endl;
    cout << "2. ELIMIR OBJETO" << endl;
    cout << "3. MODIFICAR OBJETO" << endl;
    cout << "4. CONSULTAR OBJETOS" << endl;
    cout << "5. SALIR" << endl;
    cout << "Opcion: ";
    cin >> op;
    cin.get();


    return op;
}


void altaObjeto(TObjeto objetos[], int &numObjetos) {

    char r;
    TObjeto nuevo;

    if (numObjetos==MAX) {

        cout << "Lista llena" << endl;

    } else {


        do {

            cout << "Nombre: ";
            cin.getline(nuevo.nombre, 50);

            cout << "Precio: ";
            cin >> nuevo.precio;
            cin.get();

            objetos[numObjetos] = nuevo;

            numObjetos++;

            cout << "¿Quieres introducir un producto más? [s/n]: ";
            cin >> r;
            cin.get();

        } while (r=='s');


    }


}


void bajaObjeto(TObjeto objetos[], int &numObjetos, int &valorVentas, int &numBajas) {

    TObjeto baja;
    char res;
    int i = 0;

    cout << "Nombre del objeto: ";
    cin.getline(baja.nombre, 50);

    while (strcmp(objetos[i].nombre, baja.nombre)!=0) {

        i++;

    }

    cout << "Nombre: " << objetos[i].nombre << endl;
    cout << "Precio: " << objetos[i].precio << endl;

    cout << "¿Estás seguro que quieres dar de baja el objeto? [s/n]: ";
    cin >> res;
    cin.get();

    if (res=='s') {

        int i = 0;

        if (numObjetos==0) {

            cout << "No hay objetos" << endl;

        } else {

            numBajas++;

            valorVentas = valorVentas + objetos[i].precio;

            if (numObjetos==1) {

                for (int i=0; i<numObjetos; i++) {

                    objetos[i] = objetos[i+1];

                }

                numObjetos--;

            } else {

                for (i=i; i<MAX; i++) {

                    if (i!=MAX-1) {

                        objetos[i] = objetos[i+1];

                    }

                }

                numObjetos--;

            }


        }

    }


}



void modificarObjeto(TObjeto objetos[], int numObjetos) {

    TObjeto cambio;

    cout << "¿Qué objeto quieres modificar? ";
    cin.getline(cambio.nombre, 50);

    int i = 0;

    while (strcmp(cambio.nombre, objetos[i].nombre)!=0) {

        i++;

    }

    cout << "Nombre: " << objetos[i].nombre << endl;
    cout << "Precio: " << objetos[i].precio << endl;

    cout << "Introduce el nuevo precio: ";
    cin >> cambio.precio;
    cin.get();

    objetos[i].precio = cambio.precio;

}



void consultaObjetos(TObjeto objetos[], int numObjetos) {

    int valorTotal = 0;

    if (numObjetos==0) {

        cout << "No hay objetos." << endl;

    } else {

        for (int i=0; i<numObjetos; i++) {

            cout << "Objeto " << i+1 << endl;
            cout << "Nombre: " << objetos[i].nombre << endl;
            cout << "Precio: " << objetos[i].precio << endl;

            valorTotal = valorTotal + objetos[i].precio;

        }

        cout << "El valor total de los objetos es " << valorTotal << "." << endl;

    }

}



void ventaObjetos(TObjeto objetos[], int numObjetos, int valorVentas, int numBajas) {

    if (numBajas>=1) {

        cout << "Las ganancias totales han sido de " << valorVentas << " pavos." << endl;

    }

}



int main() {

    TObjeto objetos[MAX];
    int opcion;
    int numObjetos = 0;

    int numBajas = 0;
    int ganancias = 0;

    do {

        opcion = menu();

        switch (opcion) {

            case 1:

                    altaObjeto(objetos, numObjetos);

            break;
            case 2:

                    bajaObjeto(objetos, numObjetos, ganancias, numBajas);

            break;
            case 3:

                    modificarObjeto(objetos, numObjetos);

            break;
            case 4:

                    consultaObjetos(objetos, numObjetos);

            break;
            case 5:

                    ventaObjetos(objetos, numObjetos, ganancias, numBajas);

            break;
            default:

                    cout << "Opcion incorrecta" << endl;

            break;


        }


    } while (opcion!=5);




    return 0;
}
