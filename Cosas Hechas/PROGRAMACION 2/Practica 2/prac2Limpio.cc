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
void loadChatbotFile(Chatbot &megabot,string filename);

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
int bPosicion(Chatbot megabot, string name){
  int i, pos;
	pos = -1;
	for(i = 0; i < (int) megabot.intents.size() && pos == -1; i++){
		if(megabot.intents[i].name.compare(name) == 0){
			pos = i;
		}
	}
	return pos;
}

bool isequal(char sim[3], string jcng)
{
  for (int i = 0; i < (int)jcng.size(); i++)
  {
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

bool isequal(const char sim[3], string jcng)
{
  for (int i = 0; i < (int)jcng.size(); i++)
  {
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
  loadChatbotFile(megabot, filename);
}


void loadChatbotFile(Chatbot &megabot,string binName){
  Chatbot newMegabot;
  BinChatbot bcb;
  vector<Intent> intents;
  BinIntent bi;
  Example expAux;
  Intent intAux;
  char exampleAux[KMAXTEXTL];
  string auxStr;
  int id = 1;
  ifstream fl;

  fl.open(binName,ios::in | ios::binary);
  if(fl.is_open()){
    fl.read((char *)&bcb,sizeof(bcb));

    newMegabot.threshold = bcb.threshold;
    for (int i = 0; i < 3; i++)
    {
      newMegabot.similarity[i] = bcb.similarity[i];
    }
    newMegabot.nextId = id;
    for (unsigned i = 0; i < bcb.numIntents; i++)
    {
      fl.read((char *)&bi,sizeof(bi));
      intAux.name = (string)bi.name;
      intAux.response = (string) bi.response;  
      intAux.examples.clear();    
      for (int j = 0; j < bi.numExamples; j++)
      { 
        fl.read((char *)&exampleAux,sizeof(exampleAux));
        
        auxStr = exampleAux;
        expAux.text = exampleAux;
        //expAux.tokens = tokenizador(exampleAux);

        if (isequal(megabot.similarity, "jg"))
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
    megabot = newMegabot;
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


    for (int i = 0; i < 3; i++)
    {
      bcb.similarity[i] = megabot.similarity[i]; 
    }
    bcb.numIntents = megabot.intents.size();
    fl.write((char *)&bcb,sizeof(bcb));

    for (unsigned i = 0; i < megabot.intents.size(); i++)
    {
      
      strcpy(bi.name,  megabot.intents[i].name.c_str());
      bi.name[KMAXTEXTS-1] = '\0';
      bi.numExamples = megabot.intents[i].examples.size();
      strcpy(bi.response, megabot.intents[i].response.c_str());
      bi.response[KMAXTEXTL-1] = '\0';
      fl.write((char *)&bi,sizeof(bi));
      
      for (int j = 0; j <  megabot.intents[i].examples.size(); j++)
      { 
       
        strcpy(exampleAux, megabot.intents[i].examples[j].text.c_str());
        exampleAux[KMAXTEXTL-1] = '\0';
        fl.write((char *)&exampleAux,sizeof(exampleAux));

      }   
    }
  }
  fl.close();

}


void config(Chatbot &megabot){
  char sim[3];

  cout<<"Enter threshold: ";
  cin>>megabot.threshold;
  if (megabot.threshold<0 && megabot.threshold>1)
  {
    error(ERR_THRESHOLD);
  }
  cout<<"Enter algorithm: ";
  cin>>sim;  
  if (isequal(sim, "jg") || isequal(sim, "ng"))
  {
   for (int i = 0; i < 3; i++)
   {
     megabot.similarity[i] = sim[i];
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
      if (line[0]=='#')
      {
        if(pos == -1 && name != ""){
          megabot.intents.push_back(nuevo);
        }
        name = response = "";
        isResponse=false;
        nuevo.examples.clear();
        for (int i = 1; i < (int)line.size(); i++)
        {
          if (line[i]=='#')
          {
            isResponse=true;
          }
          else
          {
            if (isResponse)
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
      else if(name != "")  {
        if(pos == -1){
          Example example;
          example.text = line;

          line = cleanString(line);
          //example.tokens = tokenizador(line);

          if (isequal(megabot.similarity, "jg"))
          {
            example.tokens = tokenizador(line);
          }
          else if(isequal(megabot.similarity, "ng"))
          {
            example.tokens = n_grama(line);
          }
          example.id = megabot.nextId;

          megabot.nextId++;
          nuevo.examples.push_back(example);
        }
        else{
          error(ERR_INTENT);
        }
      }
    } 
    if(pos == -1 && nuevo.name != ""){
      megabot.intents.push_back(nuevo);
    } 
  }
  else
  {
    error(ERR_INTENT);
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
      for (int i = 0; i < (int)megabot.intents.size(); i++)
      {
        esc<<"#";
        esc<<megabot.intents[i].name;
        esc<<"#";
        esc<<megabot.intents[i].response;
        esc<<"\n";
        for (int j = 0; j < (int)megabot.intents[i].examples.size(); j++)
        {
          esc<<megabot.intents[i].examples[j].text;

          if(megabot.intents[i].examples[j].text[megabot.intents[i].examples[j].text.size()-1] != '\n' && (j != (int)megabot.intents.size()-1)){
            esc<<"\n";
          }
        }        
        esc<<"\n";
      }    
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
      cout<<"File name: ";
      getline(cin, filename);
      ofstream esc;
      esc.open(filename, ios::out);
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
  for (int i = 0; i < (int)example.size(); i++)
  {
    example[i] = tolower(example[i]);
    
    if ((isdigit(example[i]) || isalpha(example[i])) && !(example[i] == 's' && example[i+1] == ' '))
    {
      token += example[i]; 
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
  return tokens;
}

vector<string> n_grama(string example){
  string token = "";
  vector<string> tokens;
  for (int i = 0; i < (int)example.size(); i++)
  {
    example[i] = tolower(example[i]);
    if ((isdigit(example[i]) || isalpha(example[i])) && !(example[i] == 's' && example[i+1] == ' ') && !(example[i] == ' '))
    {
      token += example[i];     
    } 
    else if (!token.empty())
    {
      cout<<token<<endl;

      if (token.size()>=3)
      {
        int cont = 0;
        int pos = 0;
        string aux = "";
        while (pos < token.size())
        {

          if(cont >= 3){
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
  for (int i = 0; i < tokens.size(); i++)
  {
    for (int j = 0; j < tokens.size(); j++)
    {
      if (i!=j && tokens[i].compare(tokens[j]) == 0)
      {
        tokens.erase(tokens.begin()+j);
        j++;
      }
      
    }
    
  }
  
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
        //nuevo.tokens = tokenizador(example);
        if (isequal(megabot.similarity, "jg"))
        {
          nuevo.tokens = tokenizador(example);
        }
        else if(isequal(megabot.similarity, "ng"))
        {
          nuevo.tokens = n_grama(example);
        }

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
    for (int i = 0; i < (int)megabot.intents.size(); i++)
    {
      for (int j = 0; j < (int)megabot.intents[i].examples.size(); j++)
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
  for (int i = 0; i < (int)tokens.size(); i++)
  {
    for (int j = 0; j < (int)example.size(); j++)
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
  do
  {
    cout << "<< ";
    getline(cin, pregunta);
    pregunta = cleanString(pregunta);
    if (isequal(megabot.similarity, "jg"))
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
      for (int j = i + 1; j <(int) tokens.size(); j++)
      {
        if(tokens[i].compare(tokens[j])){
          tokens.erase(tokens.begin() + j);
          j--;
        }
      }
    }
    float jaccardNum = megabot.threshold;
    int posVector = -1;
    for (int i = 0; i < (int)megabot.intents.size(); i++)
    {
      for (int j = 0; j < (int)megabot.intents[i].examples.size(); j++)
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
    else if (pregunta != "q"){
      error(ERR_RESPONSE);
    }
  } while (pregunta != "q");
  
 

  
}

void report(const Chatbot &megabot){
  float totalIntents = 0, totalExamples = 0, expIntent = 0;
  if (strcmp(megabot.similarity, "jc")==0)
  {
    cout<<"Similarity: Jaccard"<<endl;
  }
  else
  {
    cout<<"Similarity: N-grams"<<endl;
  }
  
  
  
  cout<<"Threshold: "<<megabot.threshold<<endl;
  if (megabot.intents.size() == 0)
  {
    cout<<"Total intents: "<<totalIntents<<endl;
    cout<<"Total examples: "<<totalExamples<<endl;
    cout<<"Examples per intent: "<<expIntent<<endl;
  }
  
  for ( int i = 0; i < (int)megabot.intents.size(); i++)
  {
    Intent in = megabot.intents[i];
    cout << "Intent: "<< in.name << endl;
    totalIntents++;
    cout << "Response: "<< in.response << endl;
    for (int j = 0; j < (int)in.examples.size(); j++)
    {
      Example ex = in.examples[j];
      cout<< "Example "<< ex.id << " : "<< ex.text<< endl;
      totalExamples++;
      cout<< "Tokens " <<ex.id<<" : ";
      for (int k = 0; k < (int)ex.tokens.size(); k++)
      {
        cout<<"<"<<ex.tokens[k]<<"> ";      
      }
      cout<<endl;
    }
    cout<<"Total intents: "<<totalIntents<<endl;
    cout<<"Total examples: "<<totalExamples<<endl;
    expIntent = totalExamples/totalIntents;
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
      if (strcmp(argv[i], "-i")==0)
      {
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
        loadChatbotFile(megabot, argv[i+1]);
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

  srand(101);
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
