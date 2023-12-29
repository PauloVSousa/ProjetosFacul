#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  ppilha p = aloc_pilha();
  char *comando = aloc_pilcom();
  inici_pilha(p);

  while (1) {
    scanf("%s", comando);
      if(comando[1] == 'i'){
        push_pilha(p);
      }
      if (comando[1] == 'c') {
        limpar_pilha(p);
      }
      if (comando[1] == 's') {
        exifull_pilha(p);
        free_pilha(p);
        return 0;
      }
      if (comando[1] == 'r') {
        pop_pilha(p);
      }
    }
  return 0;
}