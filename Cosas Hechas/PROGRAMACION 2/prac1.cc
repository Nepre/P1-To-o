#include <iostream>
#include <string.h>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;

//Antonio Gómez Martínez 48791884Y
//g++ -Wall -g converter.o prac1.cc -o prac1


string cleanString(string);

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
  ERR_RESPONSE
};

const int KSIZE=10;

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
  }
}

void showMainMenu(){
  cout << "1- Train" << endl
       << "2- Test" << endl
       << "3- Report" << endl
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
int bPosicion(Chatbot megabot, string name){
	int i, pos;
	pos = -1;
	for(i = 0; i < megabot.intents.size() && pos == -1; i++){
		if(megabot.intents[i].name.compare(name) == 0){
			pos = i;
		}
	}
	return pos;
}

void addIntent(Chatbot &megabot){
  Intent nuevo;
	int pos;
	cout<<"Intent name: ";
	getline(cin,nuevo.name);
  pos = bPosicion(megabot,nuevo.name);
	if(pos == -1){
		megabot.intents.push_back(nuevo);
	}
	else{
		error(ERR_INTENT);
	}
}

char preguntar(){
  char confirmacion;
  cout<<"Confirm [Y/N]?: ";
  cin>>confirmacion;
  return confirmacion;
}

void deleteIntent(Chatbot &megabot){
  string name;
  char respuesta;
  int pos;

  cout << "Intent name: ";
  getline(cin, name);
  pos = bPosicion(megabot, name);
  if(pos == -1){
    error(ERR_INTENT);
  }
  else{
    respuesta = preguntar();
      if(respuesta == 'Y' || respuesta == 'y'){
        megabot.intents.erase(megabot.intents.begin() + pos);
    }
  }
}

vector<string> tokenizador(string example){
  string token = "";
  vector<string> tokens;
  for (int i = 0; i < example.size(); i++)
  {
    example[i] = tolower(example[i]);
    
    if ((!(isdigit(example[i]) || isalpha(example[i])) && !(example[i] == ' ')) || example[i] == '?')
    {
      example.erase(i, 1);
      i--;
    }
    

    if (example[i] != ' ')
    {
      token.push_back(example[i]);
    }
    else if (!token.empty())
    {
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
  
 /* cout<<endl<<"---------------"<<endl;
  cout<<tokens.size()<<endl;
  for (int i = 0; i < tokens.size(); i++)
  {
    cout<<tokens[i]<<endl;
  }
  cout<<endl<<"---------------"<<endl;*/

  
  return tokens;
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
      nuevo.id = megabot.nextId;
      getline(cin, example);
      if(!(example[0] == 'q' && example.size() <= 1)){
        nuevo.text = example;
        example = cleanString(example);
        nuevo.tokens = tokenizador(example);

        megabot.nextId++;
        megabot.intents[pos].examples.push_back(nuevo);
      }
    } while (!(example[0] == 'q' && example.size() <= 1));    
	}
	else{
		error(ERR_INTENT);
	}
}

void deleteExample(Chatbot &megabot){
  int id;
  cout<<"Example id: ";
  cin>>id;
  if (megabot.nextId<= id && megabot.nextId>0)
  {
    for (int i = 0; i < megabot.intents.size(); i++)
    {
      for (int j = 0; j < megabot.intents[i].examples.size(); j++)
      {
        if(megabot.intents[i].examples[j].id == id){
          megabot.intents[i].examples.erase(megabot.intents[i].examples.begin()+j);
        }    
      }
    }
  }
  else
  {
     cout<<ERR_EXAMPLE<<endl;
     
  }
  
  
}

void addResponse(Chatbot &megabot){
  string response; 
  string intentName;
	int pos;
	cout<<"Intent name: ";
	getline(cin,intentName);
  pos = bPosicion(megabot,intentName);
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

float jaccard(vector<string> tokens, vector<string> example){
  float similares = 0; // Un entero no es divisible en decimal
  for (int i = 0; i < tokens.size(); i++)
  {
    for (int j = 0; j < example.size(); j++)
    {
      if(tokens[i].compare(example[j]) == 0){
        similares++;
      }
    }
  }


  float coeficiente = similares / (tokens.size() + example.size() - similares);

  return coeficiente;
}

void test(const Chatbot &megabot){
  string pregunta;
  vector<string> tokens;
  int position = rand() % KSIZE;
  cout << ">> " << greetings[position] << endl;
  cout << "<< ";
  getline(cin, pregunta);
  pregunta = cleanString(pregunta);
  tokens = tokenizador(pregunta);

  for (int i = 0; i < tokens.size(); i++)
  {
    // Así no comparamos con uno mismo, sino que empezamos por donde esté i
    for (int j = i + 1; j < tokens.size(); j++)
    {
      if(tokens[i].compare(tokens[j])){
        tokens.erase(tokens.begin() + j);
        j--;
      }
    }
  }

  
  float jaccardNum = megabot.threshold;
  int posVector = -1;

  for (int i = 0; i < megabot.intents.size(); i++)
  {
    for (int j = 0; j < megabot.intents[i].examples.size(); j++)
    {
      float auxJaccard = jaccard(tokens, megabot.intents[i].examples[j].tokens);
      if(auxJaccard > jaccardNum){
        jaccardNum = auxJaccard;
        posVector = i;
      }

    }
    
  }

  if(posVector != -1){
    cout<< ">> " << megabot.intents[posVector].response<<endl;
  }
  else{
    error(ERR_RESPONSE);
  }
  

  
}

void report(const Chatbot &megabot){
  float totalIntents = 0, totalExamples = 0, expIntent = 0;

  cout<<"Similarity: Jaccard"<<endl;
  cout<<"Threshold: "<<megabot.threshold<<endl;
  for (int i = 0; i < megabot.intents.size(); i++)
  {
    Intent in = megabot.intents[i];
    cout << "Intent: "<< in.name << endl;
    totalIntents++;
    cout << "Response: "<< in.response << endl;
    for (int j = 0; j < in.examples.size(); j++)
    {
      Example ex = in.examples[j];
      cout<< "Example "<< ex.id << " : "<< ex.text<< endl;
      totalExamples++;
      cout<< "Tokens " <<ex.id<<" : ";
      for (int k = 0; k < ex.tokens.size(); k++)
      {
        cout<<"< "<<ex.tokens[k]<<" >  ";      
      }
      cout<<endl;
      
      
    }
    cout<<"Total intents: "<<totalIntents<<endl;
    cout<<"Total examples: "<<totalExamples<<endl;
    expIntent = totalExamples/totalIntents;
    cout<<"Examples per intent: "<<expIntent<<endl;
    
    
  }
  
  
}

int main(){
  Chatbot megabot;
  megabot.nextId=1;
  megabot.threshold=0.25;
  strcpy(megabot.similarity,"jc");

  srand(101);

  char option;
  do{
    showMainMenu();
    cin >> option;
    cin.get();

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
      case 'q':
        break;
      default:
        error(ERR_OPTION);
    }
  }while(option!='q');

  return 0;
}
