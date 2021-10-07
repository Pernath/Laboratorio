# [Compiladores 2022-1] Grupo 7009 
## Práctica 1 Repositorio base


### Estructura del directorio
```c++
practica1
├── src //carpeta de código
│   ├── tokens.h //definición de tokens
│   ├── prueba //archivo de entrada para el analizador léxico 
│   ├── Makefile //archivo de reglas de compilación 
│   ├── main.cpp //contiene la función principal del programa
│   ├── Lexer.h //header de la clase Lexer
│   ├── Lexer.cpp //código fuente de la clase Lexer
│   └── afd //archivo descriptor del AFD y conjunto de símbolos terminales
├── README.md
└── extras //ejercicios extra
```

### Uso

#### Compilación

```bash
$ cd src/
$ make
```

#### Ejecución

```bash
$ ./compiler prueba
```


#### Ejercicios

1. Implementar constructor Lexer::**Lexer(string file)** en _Lexer.cpp_. (2.5 pts.)
2. Documentar Lexer::**openFile(string file)** en  _Lexer.cpp_. (1 pt.)
3. Implementar método Lexer::**yylex()** _Lexer.cpp_. (2.5 pts.)

---
#### Extras

4. Generalizar la implementación para cualquier AFD de entrada. (2 pts.)
5. Corregir todos los errores ortográficos en los comentarios del código. (0.25pts)
6. Traducir el AFD de su tarea en archivo de entrada afd. (1 pts.)
7. Proponer 4 archivos de prueba nuevos, 2 válidos y 2 inválidos. (0.25pts)





