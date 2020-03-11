#include <stdio.h>
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
  fprintf(stderr,"ERROR, tiempo de ejecución agotado... (%d segundos)\n",segundos);
  fflush(stderr); 
  kill(f,SIGKILL);  
  exit(-1); 
}
void SeAcaboFich(int i){  
  fprintf(stderr,"ERROR, fichero de salida muy grande (cuelgue?)... \n");
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

