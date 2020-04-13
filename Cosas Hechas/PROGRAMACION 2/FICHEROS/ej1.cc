#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

struct TAlumno{
    char dni[10];
    char apellidos[40];
    char nombre[20];
    int grupo;
};

const int nAlumno = 3;

int main(int argc, char const *argv[])
{
    TAlumno alumno;
    TAlumno alumnos[nAlumno];
    ifstream l;
    ofstream e;
    for (int i = 0; i < nAlumno; i++)
    {
        strcpy(alumnos[i].dni,"01969420z");
        strcpy(alumnos[i].apellidos,"Primo De Rivera");
        strcpy(alumnos[i].nombre,"Jose Antonio");
        alumnos[i].grupo = 7;    }
    e.open("alumno.dat",ios::out | ios::binary);
    if(e.is_open()){

        for (int i = 0; i < nAlumno; i++)
        {
            e.write((char *)&alumnos[i], sizeof(TAlumno));
        }
        e.close();
        
        l.open("alumno.dat",ios::in | ios::binary);
        
        while (l.read((char *)&alumno, sizeof(TAlumno))&& alumno.grupo==7){
            
            cout << alumno.nombre << "(" << alumno.dni<< ")" << ": " << alumno.grupo << endl;
            
        
        }
    l.close();

    }

    return 0;
}


/*PARA CAMBIAR DEL GRUPO 4 AL 8:
Se haría un if para ver si se tiene el grupo correcto, el 4 y el 8 y después
se guardarían los datos de uno de los grupos en variables y se sobrescribirían los del
otro en el grupo del cual hemos guardado los datos, cargando esos datos en el otro
4--->variables
8--->4
variables--->8
se abriría (e.open)
se comprueba si esta abierto(if(e.is_open))
*/