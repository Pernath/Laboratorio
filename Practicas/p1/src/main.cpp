#include  <iostream>
#include "Lexer.h"
#include "tokens.h"

using namespace std;
using namespace C_1;


int main(int argc, char *argv[]){
    
  if(argc <2){
    cout << "Faltan argumentos" << endl;
    return EXIT_FAILURE;
  }

  cout << "Inicializando analizador lexico con archivo de tabla de transiciones..." << endl;
  Lexer lexer("afd");

  cout << "Abriendo archivo de entrada..." << endl;
  lexer.openFile(string(argv[1]));
  
  cout << "Analizando archivo de entrada..." << endl;
  int token = lexer.yylex();

  while(token != 0){
    (token==ID || token==NUMERO)? cout << lexer.TOKEN[token] << ", " << lexer.getYytext() << endl : cout << lexer.TOKEN[token] << endl;
    /* Actualizacion del componente lexico */
    token= lexer.yylex();
  }

  cout << "Cierre de archivo de entrada..." << endl; 
  lexer.closeFile();
  //lexer.printTable();
  return 0;
}
