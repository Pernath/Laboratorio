%{
#include <iostream>
#include <string>
using namespace std;

#include "tokens.h"
#include "Lexer.h"

%}

%option c++
%option outfile="Lexer.cpp"
%option yyclass="C_1::Lexer"
%option case-insensitive


DIG [0-9]

%%


.   { cout << "ERROR LEXICO" << yytext << endl;}

%%

int yyFlexLexer::yywrap(){
    return 1;
}

