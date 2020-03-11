#!/bin/bash

MAXTIME=20 # Tiempo máximo de ejecución (en segundos) de una prueba
ENT=pruebas # Directorio con los ficheros de pruebas de entrada
SAL=salida-correcta-esperada # Directorio con los ficheros de salidas correctas
OBT=salida-obtenida # Directorio con los ficheros obtenidos tras la ejecución de la práctica
VAL="valgrind -q" # Si valgrind no está instalado, quitar "valgrind -q" de esta linea (quedaría VAL=""). Ojo: La práctica debe probarse siempre con valgrind antes de la entrega.
mata=./mata
comparefiles=./comparefiles

fuente=prac0.cc

# -------------- generar y compilar los ficheros auxiliares mata.c y comparefiles.cc -----
function genMata() {

if ! test -x mata ; then  # Si ya existe no se genera
echo "#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

const int TAMMAXFICH=300000;
int f;int segundos,st;
int segejec=0;
char *nfsal=NULL;
void SeAcabo(int i){  
  fprintf(stderr,\"ERROR, tiempo de ejecución agotado... (%d segundos)\\n\",segundos);
  fflush(stderr); 
  kill(f,SIGKILL);  
  exit(-1); 
}
void SeAcaboFich(int i){  
  fprintf(stderr,\"ERROR, fichero de salida muy grande (cuelgue?)... \\n\");
  fflush(stderr); 
  kill(f,SIGKILL);  
  exit(-1); 
}
int FicheroGrande() {  
  struct stat s;  int ret=0;
  if (nfsal != NULL) {   
    stat(nfsal,&s);    
    if (s.st_size > TAMMAXFICH) ret = 1;  
  }  
  return ret;
}
void Control(int i){ 
  segejec++; 
  if (segejec >= segundos) SeAcabo(i); 
  else if (FicheroGrande()) SeAcaboFich(i); 
  else alarm(1); 
}
void Salir(int i){exit(1);}
int main(int argc,char *argv[]){ 
  if (argc < 4) exit(1);  
  segundos = atoi(argv[1]);  
  nfsal = argv[2]; 
  signal(SIGALRM,Control);  
  signal(SIGCHLD,Salir);  
  alarm(1);  
  if ((f = fork()) == 0) execvp(argv[3],&argv[3]);   
  else wait(&st);
}
" > mata.c
gcc -o mata mata.c
fi
}

function genComparefiles() {

if ! test -x comparefiles ; then # Si ya existe no se genera
echo "#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
  int salida=0;

  if (argc!=3) cout << \"Sintaxis: \" << argv[0] << \" <obtenido.txt> <correcto.txt>\" << endl;
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
        tmp=\"\";
        fo >> tmp;
      }
      fc >> tmp;
      while (!fc.eof() || tmp.length()!=0)
      {
        sc=sc+tmp;
        tmp=\"\";
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
      cout << \"Fichero \" << argv[1] << \" o \" << argv[2] << \" no encontrado\" << endl;
      exit(-1);
    }
  }
  exit(0);
  return salida;
}
" > comparefiles.cc

g++ -o comparefiles comparefiles.cc

fi
}

echo "*********************************************************"
echo "Autocorrector P2p0 "


# Comprobar si está valgrind instalado
hayValgrind=$(which valgrind)
if test "$hayValgrind" == "" ; then
  echo "ERROR: no está instalado el programa 'valgrind', debes instalarlo"
  echo "para poder ejecutar el autocorrector. Se puede instalar con la orden:"
  echo "   $ sudo apt-get install valgrind"
  echo
  exit -1
fi

echo " Generando ficheros auxiliares... "
genMata
genComparefiles

let npruebas=8
pok=0;

# En esta Práctica 0, cada prueba es un programa que se compila con el fichero prac0.cc; Si no compila o no funciona, la prueba está mal

# Compilacion
echo
echo "*********************************************************"
echo " Compilando..."
echo "*********************************************************"

for i in $(ls $ENT/*.cc) ; do
 nf=$(basename $i .cc)
 echo -n "$nf "
 g++ -Wall -Wno-sign-compare -std=c++11 -g $fuente $i -o $nf 2>&1
done

# Ejecucion y comprobacion de la salida
echo
echo
echo "*********************************************************"
echo " Ejecutando y comprobando salida a la vez..."
echo "*********************************************************"

for i in $(ls $ENT/*.cc) ; do
  nf=$(basename $i .cc)
  echo "Prueba: $nf"
  if test -s $nf ; then

        tempfile=`mktemp /tmp/prog2iiXXXXX`
      
	# Ejecucion del programa 
        $mata $MAXTIME $OBT/$nf.salida $VAL ./$nf > $OBT/$nf.salida 2> $tempfile

	if test -s $tempfile; then
		echo "ERROR DE EJECUCION..."
		cat $tempfile
		rm -rf $OBT/$nf.salida $tempfile
	else 
		$comparefiles $OBT/$nf.salida $SAL/$nf.salida-esperada
		if [ $? -ne 0 ]; then
			diff -EwB -I "---" $OBT/$nf.salida $SAL/$nf.salida-esperada 2>&1
		else  
		     echo "OK"
		     let pok++
		fi
	fi
	
	# Borra el binario generado para cada prueba
  	rm $nf
  else
    echo "NO COMPILA"
  fi
  echo "--------------------------"
done
