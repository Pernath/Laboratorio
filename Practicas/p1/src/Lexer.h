#ifndef LEXER_H
#define LEXER_H
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

namespace C_1{    

  class Lexer
  {
    
  private:        
    const int ERROR = -1;
    ifstream yyin; // Para manejar la entrada
    int **table; // Tabla de transiciones
    bool *acc; // Estados de aceptacion
    string yytext; // Buffer de lexema actual
    char c; // Caracter actual de lectura de entrada
    int edos, sims; // #estados y #simbolos
    map<char, int> simbolos; // Diccionario de simbolos <simbolo, #clase lexica>

  public:
    map<int, string> TOKEN; // Diccionario de Tokens <#clase lexica, valor lexico>
    
  public:
    Lexer(); // Constructor por omision
    Lexer(string file); // Constructor con argumentos, file refiere al archivo donde esta definida nuestra tabla de transiciones
    ~Lexer(); // Destructor

    
    void getChar(); // Actualiza el caracter de lectura actual de entrada
    bool openFile(string file); // Abre el archivo de entrada file e inmediatamente lee el primer caracter
    void closeFile(); // Cierra el stream de entrada
    int yylex(); // Intenta producir un componente lexico de acuerdo a la entrada        
    void printTable(); // Imprime la tabla del AFD
    int token(int q); // Devuelve el token correspondiente al estado q
    string getYytext(); // Devuelve la porcion del lexema alojado en el buffer
  };  
    
    
}

#endif
