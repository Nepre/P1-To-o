#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;

//Antonio Gómez Martínez 48791884Y
//g++ -Wall -g converter.o prac2.cc -o prac2




const int KSIZE=10;
const int KMAXTEXTS=15;
const int KMAXTEXTL=1000;


struct BinIntent{
char name[KMAXTEXTS];
unsigned numExamples;
char response[KMAXTEXTL];
};

struct BinChatbot{
float threshold;
char similarity[3];
unsigned numIntents;
};


struct Example{
int id;
string text;
vector<string> tokens;
};

struct Intent{
string name;
vector<Example> examples;
string response;
};

struct Chatbot{
int nextId;
float threshold;
char similarity[3];
vector<Intent> intents;
};

enum Error{
  ERR_OPTION,
  ERR_INTENT,
  ERR_EXAMPLE,
  ERR_RESPONSE,
  ERR_FILE,
  ERR_THRESHOLD,
  ERR_SIMILARITY,
  ERR_ARGS
}; 

string cleanString(string);
vector<string> tokenizador(string example);
vector<string> n_grama(string example);
<<<<<<< HEAD
void loadChatbotFile(Chatbot &megabot,string filename, bool param);
=======
void loadChatbotFile(Chatbot &megabot,string filename);
>>>>>>> master

const string greetings[KSIZE]={
  "Hola, ¿en qué puedo ayudarte?",
  "¿Qué puedo hacer hoy por ti?",
  "Oh, gran prócer de los bits, ¿cuál es tu deseo?",
  "Buenas",
  "¿Qué quieres?",
  "¿Otra vez necesitas ayuda?",
  "¡Hola! Soy Megabot 3000. ¿En qué puedo ayudarte?",
  "Bonito día para ser Megabot 3000",
  "Pregunta sin miedo",
  "Soy todo oídos"
};



void error(Error n){
  switch(n){
    case ERR_OPTION:
      cout << "ERROR: wrong menu option" << endl;
      break;
    case ERR_INTENT:
      cout << "ERROR: wrong intent name" << endl;
      break;
    case ERR_EXAMPLE:
      cout << "ERROR: wrong example id" << endl;
      break;
    case ERR_RESPONSE:
      cout << "Lo siento, pero no tengo respuesta para eso" << endl;
      break;
    case ERR_FILE:
      cout << "ERROR: cannot open file" << endl;
      break;
    case ERR_THRESHOLD:
      cout << "ERROR: the threshold value must be between 0 and 1" << endl;
      break;
    case ERR_SIMILARITY:
      cout << "ERROR: valid values are \"jc\" (Jaccard) and \"ng\" (n-grams)" << endl;
      break;
    case ERR_ARGS:
      cout << "ERROR: invalid arguments" << endl;
  }
}

void showMainMenu(){
  cout << "1- Train" << endl
      << "2- Test" << endl
      << "3- Report" << endl
      << "4- Configure"<<endl
      << "5- Import data"<<endl
      << "6- Export data"<<endl
      << "7- Load chatbot"<<endl
      << "8- Save chatbot"<<endl
      << "q- Quit" << endl
      << "Option: ";
}

void showTrainMenu(){
  cout << "1- Add intent" << endl
       << "2- Delete intent" << endl
       << "3- Add example" << endl
       << "4- Delete example" << endl
       << "5- Add response" << endl
       << "b- Back to main menu" << endl
       << "Option: ";
}
<<<<<<< HEAD
int bPosicion(Chatbot megabot, string name){ //busca la posicion en el chatbot del string que se introduzca
  int i, pos;                                //poniendo pos con el vlaor de -1, si esto es así el valor no cambia
=======
int bPosicion(Chatbot megabot, string name){
  int i, pos;
>>>>>>> master
	pos = -1;
	for(i = 0; i < (int) megabot.intents.size() && pos == -1; i++){
		if(megabot.intents[i].name.compare(name) == 0){
			pos = i;
		}
	}
	return pos;
}

<<<<<<< HEAD
bool isequal(char sim[3], string compare) //compara un array de tres caracteres con un string y según sea o no devuelve un bool
{
  bool itIs=true;
  for (int i = 0; i < 3; i++)
=======
bool isequal(char sim[3], string compare)
{
  bool itIs=false;
  for (int i = 0; i < 3; i++)
  {
    if((sim[i] != compare[i]) && (sim[i]>2)){
      itIs = false;
    }
    else
    {
      itIs = true;
    }    
  }
  if(itIs){
    return true;
  }
  else return false;
  
}

bool isequal(const char sim[3], string jcng) //Lo usamos para en el caso que necesitemos comparar un array de caracteres con un string,
{
  for (int i = 0; i < (int)jcng.size(); i++) //está repetido pero declarando el array de caracteres como constante
>>>>>>> master
  {
    if((sim[i] != compare[i])){
      itIs = false;
    }    
  }

  return itIs;
  
}

bool isequal(const char sim[3], string jcng) //Lo usamos para en el caso que necesitemos comparar un array de caracteres con un string,
{
  for (int i = 0; i < (int)jcng.size(); i++) //está repetido pero declarando el array de caracteres como constante por que es necesario 
  {                                          // para mandar por parámetros a argv que es un array de caracteres constantes
    if((sim[i] != jcng[i]) && (sim[i]>2)){
      return false;
    }
    else
    {
      return true;
    }    
  }
  return true;
}

void loadChatbot(Chatbot &megabot){
  cout<<"Enter filename: ";
  string filename;
  getline(cin, filename);
<<<<<<< HEAD
  loadChatbotFile(megabot, filename, false); //lo hacemos en una función para que a la hora de hacer los argumentos sea más sencillo acceder a load
}


void loadChatbotFile(Chatbot &megabot,string binName, bool param){
  Chatbot newMegabot;
  char res;
=======
  loadChatbotFile(megabot, filename); //lo hacemos en una función para que a la hora de hacer los argumentos sea más sencillo acceder a load
}


void loadChatbotFile(Chatbot &megabot,string binName){
  Chatbot newMegabot;
>>>>>>> master
  BinChatbot bcb;
  vector<Intent> intents;
  BinIntent bi;
  Example expAux;
  Intent intAux;
  char exampleAux[KMAXTEXTL];
  string auxStr;
  int id = 1;
  ifstream fl;

<<<<<<< HEAD
  fl.open(binName,ios::in | ios::binary); //abrimos el archivo para leer binario
  if(fl.is_open()){                       //si se consigue abrir(es decir, existe)
    if(!param){                           //y no lo ha abierto por parametros
      do{
        cout<<"Confirm [Y/N]?: ";         //pide la confirmación hasta que introduzca un caracter valido
        cin>>res;
      }while(res != 'y' && res != 'Y' && res != 'n' && res != 'N');
    }
    else{
      res = 'y';
    }

    if(res == 'y' || res == 'Y'){
      fl.read((char *)&bcb,sizeof(bcb));

      newMegabot.threshold = bcb.threshold; //creamos un nuevo struct en el que guardaremos todos los datos para luego meterlos en el megabot
      for (int i = 0; i < 3; i++)           //que es el que modificaremos (Chatbot megabot)
      {
        newMegabot.similarity[i] = bcb.similarity[i];
      }
      newMegabot.nextId = id;
      for (unsigned i = 0; i < bcb.numIntents; i++) //los dos bucles anidados sirven para acceder a los intents y dentro de estos a cada ejemplo
      {
        fl.read((char *)&bi,sizeof(bi));            // de cada uno de los intents
        intAux.name = (string)bi.name;
        intAux.response = (string) bi.response;  
        intAux.examples.clear();    
        for (int j = 0; j < (int)bi.numExamples; j++)
        { 
          fl.read((char *)&exampleAux,sizeof(exampleAux));  //leemos el example y lo guardamos en un string auxiliar para luego tokenizarlo de
                                                            //la manera que corresponda
          auxStr = exampleAux;
          expAux.text = exampleAux;

          if (isequal(megabot.similarity, "jc"))
          {
            expAux.tokens = tokenizador(exampleAux);
          }
          else if(isequal(megabot.similarity, "ng"))
          {
            expAux.tokens = n_grama(exampleAux);
          }
      
          expAux.id = id;
          if(expAux.tokens.size() != 0){
            id++;
            intAux.examples.push_back(expAux);
          }

        }   
        newMegabot.intents.push_back(intAux); 
      }
      megabot = newMegabot; //metemos al megabot que usaremos todo lo almacenado y leido del binario
    }
  }
  else{
    error(ERR_FILE);
  }
  fl.close();
}


void saveChatbot(Chatbot megabot){
  BinChatbot bcb;
  vector<Intent> intents;
  BinIntent bi;
  char exampleAux[KMAXTEXTL];
  string binName;
  ofstream fl;


  cout<< "Enter filename: ";
  cin.clear();
  getline(cin, binName);
  fl.open(binName,ios::out | ios::binary);//abrimos para escritura el archivo

  if(fl.is_open()){
     bcb.threshold = megabot.threshold;//metemos en la variable todo el megabot que ya tenemos, en este caso el threshold


    for (int i = 0; i < 3; i++) //aqui metemos cada caracter del similarity que se comprobará luego para ver si es Jaccard o N-gramas
    {
      bcb.similarity[i] = megabot.similarity[i]; 
    }
    bcb.numIntents = megabot.intents.size();
    fl.write((char *)&bcb,sizeof(bcb));//una vez guardadas algunas partes escribimos en el fichero

    for (unsigned i = 0; i < megabot.intents.size(); i++)
    {
      
      strcpy(bi.name,  megabot.intents[i].name.c_str()); //después de almacenar cada uno de los strings, datos etc... lo escribimos en el fichero binario
      bi.name[KMAXTEXTS-1] = '\0';
      bi.numExamples = megabot.intents[i].examples.size();//leemos el name, examples y responses y dentro de cada uno el text
      strcpy(bi.response, megabot.intents[i].response.c_str());
      bi.response[KMAXTEXTL-1] = '\0';
      fl.write((char *)&bi,sizeof(bi));
      
      for (int j = 0; j <  (int)megabot.intents[i].examples.size(); j++)
      { 
       
        strcpy(exampleAux, megabot.intents[i].examples[j].text.c_str());
        exampleAux[KMAXTEXTL-1] = '\0';
        fl.write((char *)&exampleAux,sizeof(exampleAux));

      }   
    }
  }
  else{
    error(ERR_FILE);
  }
  fl.close();

}


=======
  fl.open(binName,ios::in | ios::binary);
  if(fl.is_open()){
    fl.read((char *)&bcb,sizeof(bcb));

    newMegabot.threshold = bcb.threshold; //creamos un nuevo struct en el que guardaremos todos los datos para luego meterlos en el megabot
    for (int i = 0; i < 3; i++)           //que es el que modificaremos (Chatbot megabot)
    {
      newMegabot.similarity[i] = bcb.similarity[i];
    }
    newMegabot.nextId = id;
    for (unsigned i = 0; i < bcb.numIntents; i++) //los dos bucles anidados sirven para acceder a los intents y dentro de estos a cada ejemplo
    {
      fl.read((char *)&bi,sizeof(bi));            // de todos los intents
      intAux.name = (string)bi.name;
      intAux.response = (string) bi.response;  
      intAux.examples.clear();    
      for (int j = 0; j < (int)bi.numExamples; j++)
      { 
        fl.read((char *)&exampleAux,sizeof(exampleAux));
        
        auxStr = exampleAux;
        expAux.text = exampleAux;
        //expAux.tokens = tokenizador(exampleAux);

        if (isequal(megabot.similarity, "jc"))
        {
          expAux.tokens = tokenizador(exampleAux);
        }
        else if(isequal(megabot.similarity, "ng"))
        {
          expAux.tokens = n_grama(exampleAux);
        }
    
        expAux.id = id;
        id++;
        intAux.examples.push_back(expAux);
      }   
      newMegabot.intents.push_back(intAux); 
    }
    megabot = newMegabot; //metemos al megabot que usaremos todo lo almacenado y leido del binario
  }
  fl.close();
}


void saveChatbot(Chatbot megabot){
  BinChatbot bcb;
  vector<Intent> intents;
  BinIntent bi;
  char exampleAux[KMAXTEXTL];
  string binName;
  ofstream fl;


  cout<< "Enter filename: ";
  cin.clear();
  getline(cin, binName);
  fl.open(binName,ios::out | ios::binary);

  if(fl.is_open()){
     bcb.threshold = megabot.threshold;


    for (int i = 0; i < 3; i++) //realizamos el proceso de loadChatbot pero a la inversa, es decir, todo lo de megabot lo metemos en un nuevo struct
    {
      bcb.similarity[i] = megabot.similarity[i]; 
    }
    bcb.numIntents = megabot.intents.size();
    fl.write((char *)&bcb,sizeof(bcb));

    for (unsigned i = 0; i < megabot.intents.size(); i++)
    {
      
      strcpy(bi.name,  megabot.intents[i].name.c_str()); //después de almacenar cada uno de los strings, datos etc... lo escribimos en el fichero binario
      bi.name[KMAXTEXTS-1] = '\0';
      bi.numExamples = megabot.intents[i].examples.size();//leemos el name, examples y responses y dentro de cada uno el text
      strcpy(bi.response, megabot.intents[i].response.c_str());
      bi.response[KMAXTEXTL-1] = '\0';
      fl.write((char *)&bi,sizeof(bi));
      
      for (int j = 0; j <  (int)megabot.intents[i].examples.size(); j++)
      { 
       
        strcpy(exampleAux, megabot.intents[i].examples[j].text.c_str());
        exampleAux[KMAXTEXTL-1] = '\0';
        fl.write((char *)&exampleAux,sizeof(exampleAux));

      }   
    }
  }
  fl.close();

}


>>>>>>> master
void config(Chatbot &megabot){
  char sim[3];
  float thresh;
  cout<<"Enter threshold: ";
  cin>>thresh;
  if (thresh<0 || thresh>1) //si el threshold se sale no lo almcenamos e imprimimos el error
  {
    error(ERR_THRESHOLD);
  }
  else{
    megabot.threshold = thresh;
  }
  cout<<"Enter algorithm: ";
  cin>>sim;  
  if (isequal(sim, "jc") || isequal(sim, "ng"))
  {
   for (int i = 0; i < 3; i++)
   {
     megabot.similarity[i] = sim[i]; //de lo contrario se almacena el threshold y el tipo de similitud que usaremos, comprobando si es valido o no
   }
  }
  else
  {
    error(ERR_SIMILARITY);
  }
}

void impDataFile(Chatbot &megabot, string filename){
  ifstream lec;
  string line;
  Intent nuevo;
  string name, response;
  int pos = -1;
  name = line = response = "";
  bool isResponse=false;
  lec.open(filename, ios::in);
  if (lec.is_open())
  {
    while (getline(lec,line))
    {
      if (line[0]=='#')                   //comprobamos si comienza por un #
      {
        if(pos == -1 && name != ""){      
          megabot.intents.push_back(nuevo);//hacemos push back del nuevo intent
        }
        name = response = "";
        isResponse=false;
        nuevo.examples.clear();
        for (int i = 1; i < (int)line.size(); i++) //para ver si tenemos más intents que comiencen por # comprobamos con un if y utilizamos un 
        {
          if (line[i]=='#')                       // bool y segun sea o no lo ponemos a true o false
          {
            isResponse=true;
          }
          else
          {
            if (isResponse)                       //si no hay # no es nombre de intent y response en la misma linea, entonces es un example
            {
              response += line[i];
            }
            else
            {
              name += line[i];
            } 
          }   
        }
        nuevo.name = name;
        nuevo.response = response;
        pos = bPosicion(megabot,nuevo.name);
      }
<<<<<<< HEAD
      else if(name != "")  { //si no esta vacio el string name
        if(pos == -1){        //y encuentra la posicion, es decir, existe
          Example example;
          example.text = line;

          line = cleanString(line);//lo limpia

          if (isequal(megabot.similarity, "jc"))//comprueba como tokenizarlo
=======
      else if(name != "")  { 
        if(pos == -1){
          Example example;
          example.text = line;

          line = cleanString(line);
          //example.tokens = tokenizador(line);

          if (isequal(megabot.similarity, "jc"))
>>>>>>> master
          {
            example.tokens = tokenizador(line);
          }
          else if(isequal(megabot.similarity, "ng"))
          {
            example.tokens = n_grama(line);
          }
          example.id = megabot.nextId;
          if(example.tokens.size() != 0){
            megabot.nextId++;
            nuevo.examples.push_back(example);//realiza un pushback de example
          }

        }
        else{
          error(ERR_INTENT);//y si no existe emite el mensaje de error
        }
      }
    } 
    if(pos == -1 && nuevo.name != ""){
      megabot.intents.push_back(nuevo);
    } 
  }
  else
  {
<<<<<<< HEAD
    error(ERR_FILE);
=======
    error(ERR_INTENT);
>>>>>>> master
  }
  
  
}

void expData(Chatbot megabot){
  char saveInt;
  ofstream esc;
  string filename;

  do
  {
    cout<<"Save all intents [Y/N]?: ";
    cin>> saveInt;
  } while (saveInt != 'Y' && saveInt != 'y' && saveInt != 'N' && saveInt != 'n');
  if (saveInt == 'Y' || saveInt == 'y')
  {
    cout<<"Enter filename: ";
    cin.ignore();
    getline(cin, filename);
    esc.open(filename, ios::out);
    if (esc.is_open())
    {
      for (int i = 0; i < (int)megabot.intents.size(); i++) //simplemente escribimos en el fichero todos los intents que tenemos mediante un for
      {
        esc<<"#";
        esc<<megabot.intents[i].name;                       //el nombre entre almohadillas, a continuacion la respuesta
        esc<<"#";
        esc<<megabot.intents[i].response;
        esc<<"\n";
<<<<<<< HEAD
        for (int j = 0; j < (int)megabot.intents[i].examples.size(); j++)//y en la siguiente linea, a el texto de cada example por linea
=======
        for (int j = 0; j < (int)megabot.intents[i].examples.size(); j++)
>>>>>>> master
        {
          esc<<megabot.intents[i].examples[j].text;

          if(megabot.intents[i].examples[j].text[megabot.intents[i].examples[j].text.size()-1] != '\n' && (j != (int)megabot.intents.size()-1)){
<<<<<<< HEAD
            esc<<"\n";//comprobamos que no es la ultima posicion y que no hay un endline y si es así le metemos uno
=======
            esc<<"\n";
>>>>>>> master
          }
        }        
        esc<<"\n";
      }    
    }
    else{
      error(ERR_FILE);
    }
  }
  else
  {
    string intentName;
    string filename;
    int pos = -1;
    cout<<"Intent name: ";
    cin.ignore();
    getline(cin, intentName);
    pos = bPosicion(megabot, intentName);
    if (pos != -1)
    {
      cout<<"File name: "; //si se da el caso de que solo queremos guardar un intent
      getline(cin, filename);//pedimos el nombre del intentque quiere guardar y el archivo en el que guardarlo
      ofstream esc;
      esc.open(filename, ios::out); //y volvemos a escribir todo de nuevo pero esta vez solo un intent, quitamos el for
      if(esc.is_open()){
        esc<<"#";
        esc<<megabot.intents[pos].name;
        esc<<"#";
        esc<<megabot.intents[pos].response;
        esc<<"\n";
        for (int j = 0; j < (int)megabot.intents[pos].examples.size(); j++)
        {
          esc<<megabot.intents[pos].examples[j].text<<"\n";
        }
      }
      esc.close();
    }
    else
    {
      error(ERR_INTENT);
    }
    
    
  }
  else
  {
    string intentName;
    string filename;
    int pos = -1;
    cout<<"Intent name: ";
    cin.ignore();
    getline(cin, intentName);
    pos = bPosicion(megabot, intentName);
    if (pos != -1)
    {
      cout<<"File name: "; //si se da el caso de que solo queremos guardar un intent
      getline(cin, filename);//pedimos el nombre del intentque quiere guardar y el archivo en el que guardarlo
      ofstream esc;
      esc.open(filename, ios::out); //y volvemos a escribir todo de nuevo pero esta vez solo un intent, quitamos el for
      if(esc.is_open()){
        esc<<"#";
        esc<<megabot.intents[pos].name;
        esc<<"#";
        esc<<megabot.intents[pos].response;
        esc<<"\n";
        for (int j = 0; j < (int)megabot.intents[pos].examples.size(); j++)
        {
          esc<<megabot.intents[pos].examples[j].text<<"\n";
        }
      }
      esc.close();
    }
    else
    {
      error(ERR_INTENT);
    }
    
    
  }
  
}

void impData(Chatbot &megabot){
  cout<<"Enter filename: ";
  string filename;
  getline(cin, filename);
  impDataFile(megabot, filename);

}

void addIntent(Chatbot &megabot){
  Intent nuevo;
	int pos;
	cout<<"Intent name: ";
	getline(cin,nuevo.name);
  pos = bPosicion(megabot,nuevo.name); //si ese intent no existe lo añade, de lo contrario imprimiría el error
	if(pos == -1){
		megabot.intents.push_back(nuevo);
	}
	else{
		error(ERR_INTENT);
	}
}

char preguntar(){ //checkeamos si de verdad quiere borrar cualquier intent example, depende de en la función en la que lo llamemos
  char confirmacion;
  do{
    cout<<"Confirm [Y/N]?: ";
    cin>>confirmacion;
    
  }while(confirmacion != 'Y' && confirmacion != 'y' && confirmacion != 'N' && confirmacion != 'n');
  return confirmacion; //devuelve un char y ya se comprueba en la función que se use
}

void deleteIntent(Chatbot &megabot){
  string name;
  char respuesta;
  int pos;
  cout << "Intent name: ";
  getline(cin, name);
  pos = bPosicion(megabot, name);
  if(pos == -1){ //si no encuentra el intent que borrar da el error, de lo contrario checkea si lo quiere borrar de verdad y si es así lo borra
    error(ERR_INTENT);
  }
  else{
    respuesta = preguntar();
      if(respuesta == 'Y' || respuesta == 'y'){
        megabot.intents.erase(megabot.intents.begin() + pos);
    }
  }
}

bool isalphanum(char example){
  return (isdigit(example) || isalpha(example));
}

vector<string> tokenizador(string example){ 
  string token = "";
  vector<string> tokens;
  example = cleanString(example);

  for (int i = 0; i < (int)example.size(); i++)
  {
    example[i] = tolower(example[i]); //hace que todo el texto se en minusculas
    
<<<<<<< HEAD
    if ((isdigit(example[i]) || isalpha(example[i])))
=======
    if ((isdigit(example[i]) || isalpha(example[i])) && 
    !(example[i] == 's' && example[i+1] == ' ') && 
    !(example[i] == 's' && example[i+1] == ',') && 
    !(example[i] == 's' && example[i+1] == '?')&& 
    !(example[i] == 's' && example[i+1] == '!') )//para ver que no sean ni interrogaciones, exclamaciones, comas o espacios a final de palabra
>>>>>>> master
    {
      token += example[i];  //si esto se cumple se añade al token
    }
    
<<<<<<< HEAD
    else if (!token.empty() && example[i] != ',' && example[i] != '-' && example[i] == ' ') //para que si detecta dos tokens separados por una coma los una en uno
=======
    else if (!token.empty() && example[i] != ',') //para que si detecta dos tokens separados por una coma los una en uno
>>>>>>> master
    {
      if(token[token.size()-1] == 's') token.erase(token.begin() + token.size() - 1);//si la ultima posicion de los tokens es una ese la borra
      tokens.push_back(token);
      token = "";
    }     
  }

  if(token != ""){ 
    if(token[token.size()-1] == 's')
    {
    token.erase(token.size()-1, 1);
    }
    tokens.push_back(token);
    token = "";
  }
<<<<<<< HEAD
  for(unsigned i = 0; i<tokens.size(); i++){
    if(tokens[i] == ""){
      tokens.erase(tokens.begin()+i);
      i--;
    }
  }
=======
>>>>>>> master
  return tokens;
}

vector<string> n_grama(string example){
<<<<<<< HEAD

  vector<string> separated;
  vector<string> tokens;
  string token;
  example = cleanString(example); 

  for (int i = 0; i <= (int)example.size(); i++)
  {
    example[i] = tolower(example[i]); //hace que todo el texto se en minusculas
  
    
    if ((isdigit(example[i]) || isalpha(example[i])) &&  i != (int)example.size())//comprueba si es un alphanumerico y si no es el ultimo, para 
    {                                                                             //separar palabras
      token += example[i];                                                         //si esto se cumple se añade al token
    }
    
    else if (!token.empty() && example[i] != ',' && example[i] != '-') //para que si detecta dos tokens separados por una coma los una en uno
    {
      unsigned cont = 0;
      string auxstr = "";
      while (cont+2 < token.size()) 
      {
        auxstr += token[cont];
        auxstr += token[cont+1];
        auxstr += token[cont+2];
        if(auxstr.size() == 3) separated.push_back(auxstr);
        auxstr = "";
        cont++;
      } 
      
      
      token = "";
    }     
  }

  for (int i = 0; i < (int)separated.size(); i++)
  {
    for (int j = 0; j < (int)separated.size(); j++)
    {
      if (i!=j && separated[i].compare(separated[j]) == 0) //compara los duplicados, haciendo que si encuentra dos iguales se borre uno de ellos
      {
        separated.erase(separated.begin()+j);
=======
  string token = "";
  vector<string> tokens;
  for (int i = 0; i < (int)example.size(); i++)
  {
    example[i] = tolower(example[i]);
    if ((isdigit(example[i]) || isalpha(example[i])) && 
    !(example[i] == 's' && example[i+1] == ' ') &&
     !(example[i] == ' ')) //tokeniza
    {
      token += example[i];     
    } 
    else if (!token.empty()) //si ha encontrado tokens
    {

      if (token.size()>=3) //y estos son de 3 o más letras
      {
        int cont = 0;
        int pos = 0;
        string aux = "";
        while (pos < (int)token.size())
        {

          if(cont >= 3){ //los divide de 3 en tres haciendo que si queda una letra suelta no la use
            tokens.push_back(aux);
            pos -= 2;
            cont = 0;
            aux = "";
          }
          else
          {
            aux += token[pos];
            cont++;
            pos++;
          }
          
        }
      }
              
      token="";
      
      
    }
  
  }
  for (int i = 0; i < (int)tokens.size(); i++)
  {
    for (int j = 0; j < (int)tokens.size(); j++)
    {
      if (i!=j && tokens[i].compare(tokens[j]) == 0) //compara los duplicados, haciendo que si encuentra dos iguales se borre uno de ellos
      {
        tokens.erase(tokens.begin()+j);
>>>>>>> master
        j++;
      }
      
    }
    
  }
  
<<<<<<< HEAD
  return separated;    
}


=======
  return tokens;    
}

>>>>>>> master
bool onlySpaces(string str){ //por si en alguna función necesitamos comprobar si son solo espacios y no tiene contenido util
  for(unsigned i = 0; i<str.size(); i++){
  
    if(str[i]!=' '){
      return false;
    }
  }
  return true;
}

void addExample(Chatbot &megabot){
  Example nuevo;
  string intentName;
	int pos;
	cout<<"Intent name: ";
	getline(cin,intentName);
  pos = bPosicion(megabot,intentName);
	if(pos != -1){
    string example;
    do
    {
      cout<<"New example: ";
      getline(cin, example);
      nuevo.id = megabot.nextId;
      
      if(!(example[0] == 'q' && example.size() <= 1)&& !(onlySpaces(example))){ //vemos si no es una q, es mayor de uno(para que no haya dos q seguidas por ej)
        nuevo.text = example;                                                   //y que no sean todo espacios
        example = cleanString(example);
        //nuevo.tokens = tokenizador(example);
        if (isequal(megabot.similarity, "jc")) //sirve para ver si el similarity es n-gramas o jaccard
        {
          nuevo.tokens = tokenizador(example);
        }
        else if(isequal(megabot.similarity, "ng"))
        {
          nuevo.tokens = n_grama(example);
        }
<<<<<<< HEAD
        nuevo.id = megabot.nextId;

        if(nuevo.tokens.size() != 0){
          megabot.nextId++;
          megabot.intents[pos].examples.push_back(nuevo);
        }

=======
>>>>>>> master

      }
    } while (!(example[0] == 'q' && example.size() <= 1) );    
	}
	else{
		error(ERR_INTENT);
	}
}

void deleteExample(Chatbot &megabot){
  int id;
  bool deletedRight = false;
  cout<<"Example id: ";
  cin>>id;
  if (megabot.nextId > id && id>0) //comprueba si el id es válido
  {
    for (int i = 0; i < (int)megabot.intents.size(); i++)
    {
      for (int j = 0; j < (int)megabot.intents[i].examples.size(); j++)//recorre todos los ids en busca del que coincida y lo borra
      {
        if(megabot.intents[i].examples[j].id == id){
          megabot.intents[i].examples.erase(megabot.intents[i].examples.begin()+j);
<<<<<<< HEAD
          deletedRight = true;
=======
>>>>>>> master
          
        }    
      }
    }
  }
  
  if(!deletedRight)
  {
     error(ERR_EXAMPLE);//si esto no se cumple emitirá el mensaje de error
     
  }
  
}

void addResponse(Chatbot &megabot){
  string response; 
  string intentName;
	int pos;
	cout<<"Intent name: ";
	getline(cin,intentName);
  pos = bPosicion(megabot,intentName);//añade una respuesta siempre y cuando exista un intent al que meter esa respuesta
	if(pos != -1){
    cout<<"New response: ";
    getline(cin,response);
    megabot.intents[pos].response = response;
  }
  else{
    error(ERR_INTENT);
  }
}

void train(Chatbot &megabot){
  char option;
  do{
    showTrainMenu();
    cin >> option;
    cin.get();

    switch (option){
      case '1':  
        addIntent(megabot);
        break;
      case '2':
        deleteIntent(megabot);
        break;
      case '3':
        addExample(megabot);
        break;
      case '4':
        deleteExample(megabot);
        break;
      case '5':
        addResponse(megabot);
        break;
      case 'b':
        break;
      default:
        error(ERR_OPTION);
    }
  }while(option!='b');
}

double jaccard(vector<string> tokens, vector<string> example){ //realiza el coeficiente de jaccard y lo calcula
  float similares = 0; // Un entero no es divisible en decimal

  for (int i = 0; i < (int)tokens.size(); i++)
  {
    for (int j = 0; j < (int)example.size(); j++)//hace la interseccion de los que son similares (A con B), si lo es añade uno a similares
    {
      if(tokens[i].compare(example[j]) == 0){
        similares++;
      }
    }
  }
  double coeficiente = (double) similares / (tokens.size() + example.size() - similares);//hace la ecuación, (A∩B)/((A+B)-(A∩B))
<<<<<<< HEAD
  
=======
>>>>>>> master
  return coeficiente;//devuelve el resultado 
}

void test(const Chatbot &megabot){
  string pregunta;
  vector<string> tokens;
  int position = rand() % KSIZE;
  cout << ">> " << greetings[position] << endl;
  do
  {
    cout << "<< ";
    getline(cin, pregunta);
    pregunta = cleanString(pregunta);
    if (isequal(megabot.similarity, "jc"))
    {
      tokens = tokenizador(pregunta);
    }
    else if(isequal(megabot.similarity, "ng"))
    {
      tokens = n_grama(pregunta);
    }
    
    
    

    for (int i = 0; i < (int)tokens.size(); i++)
    {
      // Así no comparamos con uno mismo, sino que empezamos por donde esté i
      for (int j = 0; j < (int) tokens.size(); j++)
      {
        if(i != j && (tokens[i].compare(tokens[j]) == 0)){
          tokens.erase(tokens.begin() + j);
          j--;
        }
      }
    }
    float jaccardNum = megabot.threshold;
    int posVector = -1;
    for (int i = (int)megabot.intents.size() - 1; i >= 0 ; i--)
    {
      for (int j = (int)megabot.intents[i].examples.size() - 1; j >= 0; j--)
      {
<<<<<<< HEAD
        float auxJaccard = 0;
        if(isequal(megabot.similarity, "ng")){
          vector<string> ngTokens = n_grama(megabot.intents[i].examples[j].text);
          auxJaccard = jaccard(tokens, ngTokens);          
        }
        else{
          auxJaccard = jaccard(tokens, megabot.intents[i].examples[j].tokens);          
        }

=======
        float auxJaccard = jaccard(tokens, megabot.intents[i].examples[j].tokens);
        
>>>>>>> master
        if(auxJaccard >= jaccardNum){
          jaccardNum = auxJaccard;
          posVector = i;
        }
      } 
    }
    if(posVector != -1){
      cout<< ">> " << megabot.intents[posVector].response<<endl;
    }
    else if (pregunta != "q"){
      error(ERR_RESPONSE);
    }
  } while (pregunta != "q");
  
 

  
}

void report(const Chatbot &megabot){
  float totalIntents = 0, totalExamples = 0, expIntent = 0;
<<<<<<< HEAD
  if (strcmp(megabot.similarity, "jc")==0) //según sea jaccard o n-gramas imprime uno u otro, esto se comprueba con ifs que hay en el codigo
=======
  if (strcmp(megabot.similarity, "jc")==0) //según sea jaccard o n-gramas imprime uno u otro
>>>>>>> master
  {
    cout<<"Similarity: Jaccard"<<endl;
  }
  else
  {
    cout<<"Similarity: N-grams"<<endl;
  }
  
  
  
  cout<<"Threshold: "<<megabot.threshold<<endl;

  
  for ( int i = 0; i < (int)megabot.intents.size(); i++) //imprime todo el contenido del megabot
  {
    Intent in = megabot.intents[i];
    cout << "Intent: "<< in.name << endl;
    totalIntents++;
    cout << "Response: "<< in.response << endl;
    for (int j = 0; j < (int)in.examples.size(); j++)
    {
      Example ex = in.examples[j];
      cout<< "Example "<< ex.id << ":"<< ex.text<< endl;
      totalExamples++;
      cout<< "Tokens " <<ex.id<<":";
      for (int k = 0; k < (int)ex.tokens.size(); k++)
      {
        cout<<"<"<<ex.tokens[k]<<">";      
      }
      cout<<endl;
    }
  }  
  if (megabot.intents.size() == 0) //si estamos en el caso de que el megabot esté vacío para que no de error(NaN) imprimimos comprobandolo
  {
    cout<<"Total intents: "<<totalIntents<<endl;
    cout<<"Total examples: "<<totalExamples<<endl;
    cout<<"Examples per intent: "<<expIntent<<endl;
  }
  else{
    expIntent = totalExamples/totalIntents;
    cout<<"Total intents: "<<totalIntents<<endl;
    cout<<"Total examples: "<<totalExamples<<endl;
    cout<<"Examples per intent: "<<expIntent<<endl;
  }
}

bool argumentos(Chatbot &megabot, int argc, char *argv[]){
  bool hasi, hasl, hast, test;
  hasi = hasl = hast = test = false;
  if (argc>1)
  {
    for (int i = 1; i < argc; i+=2)
    {
<<<<<<< HEAD
      if (strcmp(argv[i], "-i")==0)//según sea el valor añadido detrás de la ejecucion de la práctica aquí se comprueba, si es un -i, -l o -t
                                   // utilizamos un bool para
=======
      if (strcmp(argv[i], "-i")==0)//según sea el valor añadido detrás de la ejecucion de l a práctica aquí se comprueba, utilizamos un bool para
>>>>>>> master
      {                            //ver si uno de los argumentos ya ha sido puesto, es decir, si ya has puesto -i que no se repita
        if (hasi)
        {
          error(ERR_ARGS);
          return false;
        }
        
        hasi = true;
        impDataFile(megabot, argv[i+1]);
      }
      else if (strcmp(argv[i], "-l")==0)
      {
        if (hasl)
        {
          error(ERR_ARGS);
          return false;
        }
        hasl = true;
<<<<<<< HEAD
        loadChatbotFile(megabot, argv[i+1], true);
=======
        loadChatbotFile(megabot, argv[i+1]);
>>>>>>> master
      }
      else if (strcmp(argv[i], "-t")==0)
      {
        if (hast)
        {
          error(ERR_ARGS);
          return false;
        }
        test = true;
      }
            
    }
    
  }
  return test;
}

int main(int argc, char *argv[]){
  Chatbot megabot;
  megabot.nextId=1;
  megabot.threshold=0.25;
  strcpy(megabot.similarity,"jc");

  srand(666);
  bool test_bool = argumentos(megabot, argc, argv);
  char option;
  if (test_bool)
  {
    option = '2';
  }
  else
  {
    showMainMenu();
    cin >> option;
    cin.get();
  }
  do{
    
    switch (option){
      case '1':
        train(megabot);
        break;
      case '2':
        test(megabot);
        break;
      case '3':
        report(megabot);
        break;
      case '4':
        config(megabot);
        break;
      case '5':
        impData(megabot);
        break;
      case '6':
        expData(megabot);
        break;
      case '7':
        loadChatbot(megabot);
        break;
      case '8':
        saveChatbot(megabot);
        break;
      case 'q':
        break;
      default:
        error(ERR_OPTION);
    }
    showMainMenu();
    cin >> option;
    cin.get();
  }while(option!='q');

  return 0;
}
