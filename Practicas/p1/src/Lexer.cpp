#include "Lexer.h"
#include "tokens.h"
#include <iostream>


namespace C_1{
  Lexer::Lexer(/* args */)
  {        
  }

  Lexer::Lexer(string file)
  {
    /* inicializar flujo de entrada */
    ifstream afd(file);
    /* buffer de linea y marca de estado de aceptacion */
    string line, aceptar;
    /* stream de cadena */
    stringstream s;

    /* Obtener primera linea del archivo descriptor de automata */
    getline(afd, line);
    /* Inicializar stream a partir de linea */
    s = stringstream(line);

    /* add line: asignacion de atributo de clase edos a partir del stream s */
    /* add line: asignacion de atributo de clase sims a partir del stream s */



    /**
     * Lectura de tabla de transiciones
     */

    /* Inicializacion  de atributo de clase table */
    table =  new int*[edos];

    /* Formar un arreglo bidimensional de tamano edos x sims, mediante tabla */
    for(int i=0; i<edos; i++) 
      table[i] = new int[sims];

    /* Arreglo de estados de aceptacion. Ej. para el estado inicial acc[0] = false */
    acc = new bool[edos];

    /* Variables iteradoras de renglones (#renglon -> #estado) y columnas (#columna -> #simbolo) */
    int ren = 0, col = 0;
    /* Variable de numero de estado */
    int q;

    /* Rellenar table con informacion del AFD */ 
    while(ren < edos){
      /* 1. add lines: Obtener renglon del archivo del AFD */
      /* 2. add lines: Recorrer renglon para llenar la tabla de transiciones (hint: table[ren][col] = q) */
      
      /* 3. add line: obtener final del renglon para saber si es un estado de aceptacion */
      
      /* Actualizar arreglo de estados de aceptacion */
      aceptar == "true"? acc[ren] = true : acc[ren] = false;

      /* Se termina la linea, asi que avanzamos de renglon */
      ren++;
      /* Reinicializamos variable de iteracion de columnas*/
      col=0;
    }


    /**
     * Lectura de diccionario de simbolos 
     */

    /* Declaracion de tupla llave,valor*/
    char key;
    int value;

    /* Variables iteradoras de la ultima seccion */
    int num, i=0;
    while(!afd.eof()){
      /* 1. add lines: obtener linea del stream y numero de parejas de esta */
      /* 2. add lines: iterar sobre la linea para obtener las parejas llave,valor*/
    }       

    /* Agregar a diccionario de simbolos los espacios en blanco */
    simbolos['\t']=5;
    simbolos['\n']=5;
    simbolos[' ']=5;
    simbolos['\r']=5;

    /* Cierre de flujo de entrada */
    afd.close();

    /* Asignacion de titulo de clase lexica en forma de cadena para impresion final */
    TOKEN[MAS]="MAS";
    TOKEN[MENOS]="MENOS";
    TOKEN[MUL]="MUL";
    TOKEN[DIV]="DIV";
    TOKEN[ASIG]="ASIG";
    TOKEN[LPAR]="LPAR";
    TOKEN[RPAR]="RPAR";
    TOKEN[COMA]="COMA";
    TOKEN[PYC]="PYC";
    TOKEN[ID ]="ID";
    TOKEN[IF]="IF";
    TOKEN[INT]="INT";
    TOKEN[WHILE]="WHILE";
    TOKEN[ELSE]="ELSE";
    TOKEN[FLOAT]="FLOAT";
    TOKEN[NUMERO]="NUMERO";
  }
    
  Lexer::~Lexer()
  {
    for(int i= 0; i <edos; i++){
      delete table[i];
    }
    delete table;
    delete acc;
  }

    
  void Lexer::getChar(){        
    yyin.get(c);                
  }

  bool Lexer::openFile(string file){
    yyin.open(file,ios::in);
    if (!yyin.is_open()) {
      cerr << "Could not open the file - '"
	   << file << "'" << endl;
      return EXIT_FAILURE;
    }
    getChar();
    return true;
  }    
    

  void Lexer::closeFile(){
    yyin.close();
  }

  int Lexer::yylex(){
    /* Inicializar iterador de estados */
    int q = 0;
    
    /* Variable para valor entero correspondiente al caracter de entrada en el diccionario de simbolos */
    int cc;

    /* Declaracion del iterador */
    map<char, int>::iterator it;

    /* Inicializar buffer de lexemas */
    yytext = "";        

    /* Revisar si entrada tiene algo que leer */
    if(yyin.eof()) return 0;

    /** 
     * Analisis lexico 
     */
    while(true){
      /* Buscar el caracter actual de entrada en diccionario de simbolos */
      it = simbolos.find(c);
      if(it == simbolos.end()){
	return ERROR;
      }
      /* Asignacion de id de simbolo encontrado*/
      cc = it->second;

      
      if(true /* replace condition: Caso en que δ(q,cc) no conduce a estado de error */){
	/* add lines: acciones lexicas necesarias */
	if(yyin.eof()) return token(q);
      } else { /* δ(q,cc) conduce a estado de error */                
	if(true /* replace condition: Caso en que q es estado de aceptacion */){
	  if(q == 17){ /* Estado de espacios en blanco */
	    /* add lines: acciones lexicas necesarias */
	  }
	  else  /* estado q de aceptacion no es estado de espacios en blanco */
	    return token(q); 
	} else {
	  return ERROR;
	}
      }
    }        
  }

  int Lexer::token(int q){        
    switch(q){
    case 1:
      return MAS;
    case 2:            
      return MENOS;
    case 3:
      return MUL;
    case 4:
      return DIV;
    case 5:
      return ASIG;
    case 6:
      return LPAR;
    case 7:
      return RPAR;
    case 8:
      return PYC;
    case 9:
      return COMA;
    case 10: case 20: case 35:
      return NUMERO;
    case 12: case 13: case 14: case 15: case 16: case 18: case 21: case 22: case 23: case 26: case 27: case 30:
      return ID;     
    case 17:
      return ESP;       
    case 19:
      return IF;
    case 24:
      return INT;
    case 29:
      return ELSE;
    case 31:
      return FLOAT;
    case 32:
      return WHILE; 
    default:
      return ERROR;
    }
  }

  string Lexer::getYytext(){
    return yytext;
  }

  void Lexer::printTable(){
    for(int i = 0; i < edos; i++){
      for(int j= 0; j < sims; j++){
	cout<<table[i][j]<<"\t";
      }
      cout<<endl;
    }

    for(int i = 0; i < edos; i++){
      cout<<acc[i]<<"\t";
    }
    cout<<endl;
  }

}
