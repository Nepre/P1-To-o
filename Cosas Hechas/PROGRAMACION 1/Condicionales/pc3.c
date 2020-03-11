#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float dis, vm, t;

    cout<<"A que distancia estan separadas las camaras?(en metros)"<<endl;
    cin>> dis;
    cout<<"Cual es la velocidad máxima permitida?(km/h)"<<endl;
    cin>>vm;
    cout<<"Y por último, cuánto ha tardado en recorrer de radar a radar?(segundos)"<<endl;
    cin>>t;
    if ((dis<0)||(vm<0)||(t<0)){
        cout<<"ERROR"<<endl;
    }
    else if ( ( (dis/1000)/(t/3600) ) <= vm ){
        cout<<"OK"<<endl;
    }
    else {
        cout<<"MULTA"<<endl;
    }
    return 0;
}
