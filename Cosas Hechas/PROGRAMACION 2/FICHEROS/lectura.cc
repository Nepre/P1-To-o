#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;


int main(int argc, char const *argv[])
{
    //argc == numero de argumentos que tiene (minimo 1)
    //argv[1] == "ficheroLeer.txt"
    // ./lecturatxt ficheroLeer.txt
    if(argc <= 1){
        cout<<"error";
        return 1;
    }
/*

    ficheroLeer.txt
    ficheroLeer.dat
    char * ch = argv[1];
    for (size_t i = 0; i < count; i++)
    {
        if(ch[i] == '.' && ch[i+1] == 't')
    }*/
    
    ifstream l;
    ofstream e("leerMayus.txt");
    l.open("ficheroLeer.txt", ios::in);



    if (l.is_open() && e.is_open())
    {
        string smin;
        string smay;
        e << "En mayusculas: "<<endl;
        while(getline(l,smin)){
            for (int i = 0; smin[i] != '\0'; i++)
            {
                //cout<<smin<<endl;
                //cout<<smay<<endl;
                smay += toupper(smin[i]);
                
            }
            e << smay << endl;
            smay = "";
           
        }
        e.close();
        l.close();
    }
    else
    {
        cout<<"Error al abrir el fichero"<<endl;
    }
    
    
    return 0;
}
