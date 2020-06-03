#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "itree.h"

// int validar_intervalo(char* buff) {
//   int i;

//   if(buff[1] == ' ' && buff[2] == '[') {
//     for(i = 3; isdigit(buff[i]); i++);
//     if(buff[i] == ',')
//       for(i += 1; isdigit(buff[i]); i++);
//     else if(buff[i] == '.')
//       for(i += 1; isdigit(buff[i]); i++);
//       if(buff[i] == ',')
//         for(i = 3; isdigit(buff[i]); i++);
//   }
// }

Interval string_to_double(char* buff, Interval intervalo) {
  int j = 0, i;
  char aux[256];

  for(i = 3; isdigit(buff[i]) || buff[i] == '.'; i++) {
    aux[j] = buff[i];
    j++;
  }
  aux[j] = '\n';
  sscanf(aux, "%lf", &(intervalo->bgn));
  i++;
  j = 0;
  for(; isdigit(buff[i]) || buff[i] == '.'; i++) {
    aux[j] = buff[i];
    j++;
    aux[j] = '\n';
    sscanf(aux, "%lf", &(intervalo->end));
  }

  return intervalo;
}

int validar_op(char* buff) {
  int cond;
  switch(buff[0]) {
    case 's':
      if(strcmp(buff, "salida") == 0)
        cond = 6;
      break;
    case 'b':
      if(strcmp(buff, "bfs") == 0)
        cond = 5;
      break;
    case 'd':
      if(strcmp(buff, "dfs") == 0)
        cond = 4;
      break;
    case '?':
      // if(validar_intervalo(buff))
        cond = 3;
      break;
    case 'e':
      // if(validar_intervalo(buff))
        cond = 2;
      break;
    case 'i':
      // if(validar_intervalo(buff))
        cond = 1;
      break;
    
    default:
      cond = 0;
  }

  return cond;
}

int main(){
    ITree raiz = itree_crear();
    Interval intervalo = malloc(sizeof(IntervalStruct));
    Interval intervaloFin;
  
    int continuar = 1;
    int caso;
    char buff[256];

    while(continuar) {
      printf("Ingrese una operacion: \n");
      scanf(" %[^\n]s",buff); //buscar opcion mas elegante
      caso = validar_op(buff);

      if(caso) {
        switch(caso) {
          case 1:
            printf("insertar\n");
            intervalo = string_to_double(buff, intervalo);
            raiz = itree_insertar(raiz, intervalo);
            break;
          case 2:
            printf("eliminar\n");
            intervalo = string_to_double(buff, intervalo);
            raiz = itree_eliminar(raiz, intervalo);
            break;
          case 3:
            printf("intersectar\n");
            intervalo = string_to_double(buff, intervalo);
            intervaloFin = itree_intersectar(raiz, intervalo);
            printf("[%f, %f] interseca con [%f, %f]\n", intervalo->bgn, intervalo->end, intervaloFin->bgn, intervaloFin->end);
            break;
          case 4:
            printf("dfs\n");
            itree_recorrer_dfs(raiz);
            break;
          case 5:
            printf("bfs\n"); //notar que esta version no posee bfs
            itree_recorrer_dfs(raiz);
            break;
          case 6:
            printf("salir\n");
            continuar = 0;
            free(intervalo);
            itree_destruir(raiz);
            break;
          default:
            printf("Entrada inválida\n");
        }
      }
    }

    return 0;
}





    // intervalo->bgn = 16;
    // intervalo->end = 21;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 8;
    // intervalo->end = 9;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 25;
    // intervalo->end = 30;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 5;
    // intervalo->end = 8;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 15;
    // intervalo->end = 23;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 17;
    // intervalo->end = 19;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 26;
    // intervalo->end = 26;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 0;
    // intervalo->end = 3;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 6;
    // intervalo->end = 10;
    // raiz = itree_insertar(raiz, intervalo);
    
    // itree_recorrer_dfs(raiz);