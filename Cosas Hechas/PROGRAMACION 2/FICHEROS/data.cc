#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

struct TAlumno{
char nombre[100];
int grupo;
float notaMedia;
};

const int KTamanyoArrayAlumnos = 3;

int main(int argc, char const *argv[])
{
    TAlumno alumno;
    TAlumno alumnos[KTamanyoArrayAlumnos];
    ifstream l;
    ofstream e;
    for (int i = 0; i < KTamanyoArrayAlumnos; i++)
    {
        strcpy(alumnos[i].nombre,"Jose");
        alumnos[i].grupo = 27;
        alumnos[i].notaMedia = 0;
    }
    for (int i = 0; i < KTamanyoArrayAlumnos; i++)
    {
        cout << alumnos[i].nombre << ": " << alumnos[i].grupo << endl;

    }
    cout<<"-----------"<<endl;
    
    
    e.open("alumno.dat",ios::out | ios::binary);
    if(e.is_open()){

        for (int i = 0; i < KTamanyoArrayAlumnos; i++)
        {
            e.write((char *)&alumnos[i], sizeof(TAlumno));
        }
        e.close();
        
        l.open("alumno.dat",ios::in | ios::binary);
        
        while (l.read((char *)&alumno, sizeof(TAlumno))){
            
            cout << alumno.nombre << ": " << alumno.grupo << endl;
            
        
        }
    l.close();

    }

    return 0;
}

