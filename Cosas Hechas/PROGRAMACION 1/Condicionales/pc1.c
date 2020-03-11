#include <iostream>
#include <math.h>
using namespace std;
/*Si los valores estan mal introducidos se han de intercambiar*/
int main(){
    int ds,ss,aux;
    cout<< "Introduzca los valores de la tensión de la diastole y la sistole respectivamente" <<endl;
    cin>> ds;
    cin>> ss;
    if (ds<ss){ //ss < ds
        aux = ds;
        ds  = ss;
        ss  = aux;
    }
    if((ds<90)&&(ss<60)){
        cout<< "Hipotensión"<< endl;
    }
    else if ((ds<=140)&&(ss<=90)) {
        cout<< "Normal"<<endl;
    }
    else if ((ds<=160)&&(ss<=100)) {
        cout<< "Hipertensión ligera"<<endl;
    }
    else if ((ds<=180)&&(ss<=110))  { //115 estaría en hipertensión severa, pero el valor 170 de presion sistolica en hipertension moderada
        cout<< "Hipertensión moderada"<<endl;
    }
    else if ((ds>180)&&(ss>110)){
        cout<< "Hipertensión severa- Al Hospital"<<endl;
    }
    else{
        cout<< "Error de lectura"<<endl;
    }
    return 0;
}
