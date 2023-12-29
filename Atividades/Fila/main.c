#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  pfila f;
  char *comad = fila_caloc();
  f = fila_aloc();
  fila_iniciar(f);

  while (1) {
    scanf(" %s", comad);
    if (comad[1] == 'i') {
      fila_push(f);
    }
    if (comad[1] == 'c') {
      fila_popfull(f);
    }
    if (comad[1] == 's') {
      fila_exifull(f);
      fila_free(f);
      exit(1);
    }
    if (comad[1] == 'r') {
      fila_pop(f);
    }
  }
  return 0;
}