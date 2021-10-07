# [Compiladores 2022-1] Grupo 7009 
## Práctica 2 Directorio base


### Estructura del directorio
```c++
practica2
```

### Uso

#### Compilación

```bash
$ cd src/
$ flex++ lexer.ll
$ g++ Lexer.cpp main.cpp -o compiler
```

#### Ejecución

```bash
$ ./compiler prueba
```


#### Salida esperada
```
12, int
15, float
11, if
14, else
13, while
12, int
16, 12345
16, 1.2e6
10, a1
10, a_23
10, ___
10, id2
10, if3
10, while4
10, _b
9, ;
8, ,
6, (
7, )
12, int
7, )
10, a
10, _qbc
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





