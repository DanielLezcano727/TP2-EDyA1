# TP2-EDyA1

## Tareas:
 - [X] Decidir estructura para los intervalos
 - [X] Implementar arbol AVL de *inserte estructura de intervalos*
 - [X] Implementar función eliminar_nodo para arboles AVL
 - [X] Implementar funciones para buscar intersecciones en un AVL
 - [X] Implementar menú de uso del programa
 - [X] Revisar implementacion bfs
 - [X] Repensar nombres estructuras
 - [X] Hacer consultas para no tomar decisiones de diseño :)
 - [X] No insertar elementos iguales
 - [X] Pasar codigo por programa convenciones
 - [ ] Buscar implementaciones de eliminar
 - [ ] Testear TODOS los casos posibles
 - [ ] Hacer informe

 ## Notas para el TP (a implementar)
 - [X] Intervalos de igual inicio se agregan a la izquierda
 - [X] Validar TODAS las entradas(intervalos validos, datos validos, comando valido, etc) (incluido mayusc)
 - [X] Usar funcionvisitante para imprimir

## Consultas:
 - [X] Usar funcionVisitante en itree.c en lugar de printf
 - [X] Es necesario chequear que los datos dados (por ejemplo, intervalos a busar o intervalos para el arbol) esten bien generados?
 - [X] Usar punteros para estructura Intervalos
 - [X] Es necesario validar que los intervalos sean correctos en las funciones itree? (Solo se usara desde el interprete o hay que hacer eso tambien por si se importa la libreria de itree?)
 - [X] Cual es el maximo numero que debemos considerar que nos pueden ingresar?
 - [X] Esta mal aceptar los intervalos sin un espacio en el medio? (Por ahora aceptamos las dos opciones)
 - [ ] IMPORTANTE: consultar/buscar sobre implementacion de itree_insertar, quizas no debería rebalancear recursivo hacia arriba

## Decisiones de diseño:
 - Crear funcion itree_crear_nodo para aligerar itree_insertar

## Informe:
 - Agregar por que pusimos maySub en el nodo del arbol y no en intervalo (es un dato del arbol auxiliar para saber donde ubicar los subintervalos, no es un dato de un intervalo)
 - Tener una estructura intervalo nos sirve para la funcion visitante (su signatura)
 - Explicar el problema de strtok que tuvimos (No toma el primer caracter)
 - Explicar por que elegimos imprimirlo en pre order (Es una forma sencilla de ver si esta balanceado) (Se puede ver si esta balanceado con otro tipo de recorrido? Creo que no)
 - Agregar lo del maximo double
 - Agregar que strtod ya lee en notacion cientifica
 - ¿Intento de strtok que no funciono?
 - tutorialspoint maximo double, wikipedia