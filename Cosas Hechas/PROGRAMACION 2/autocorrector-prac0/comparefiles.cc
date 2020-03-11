#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
  int salida=0;

  if (argc!=3) cout << "Sintaxis: " << argv[0] << " <obtenido.txt> <correcto.txt>" << endl;
  else 
  {
    ifstream fo(argv[1]);
    ifstream fc(argv[2]);
    if (fo.is_open() && fc.is_open())
    {
      string so,sc,tmp;

      fo >> tmp;
      while (!fo.eof() || tmp.length()!=0)
      {
        so=so+tmp;
        tmp="";
        fo >> tmp;
      }
      fc >> tmp;
      while (!fc.eof() || tmp.length()!=0)
      {
        sc=sc+tmp;
        tmp="";
        fc >> tmp;
      }

      // ignorar los '-' en las líneas
      string scok, sook;
      for (unsigned int i=0; i<so.length(); i++)
        if (so[i]!='-') sook=sook+so[i];
      for (unsigned int i=0; i<sc.length(); i++)
        if (sc[i]!='-') scok=scok+sc[i];
                                 
      if (sook!=scok) {
        exit(-1);
      }
    }
    else {
      cout << "Fichero " << argv[1] << " o " << argv[2] << " no encontrado" << endl;
      exit(-1);
    }
  }
  exit(0);
  return salida;
}

