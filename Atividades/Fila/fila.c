#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
// Struct para comand
struct comand {
  char *comand;
};

// Struct para fila
struct fila {
  int *fila;
  int tamanho;
};
// aloca o comand
char *fila_caloc() {
  char *c;
  c = (char *)malloc(2 * sizeof(char));
  return c;
};
// Aloca a fila
pfila fila_aloc() {
  pfila f = (pfila)malloc(sizeof(tfila));
  f->fila = NULL;
  f->tamanho = 0;
  return f;
}
// Desaloca a fila
void fila_free(pfila f) {
  if (f != NULL) {
    free(f->fila);
    free(f);
  }
}
// Inicializa a fila com -1
void fila_iniciar(pfila f) {
  if (f != NULL) {
    f->tamanho = 0;
  }
}

// Verifica se a fila está vazia, retorna 1 caso esteja vazia
int fila_vazia(pfila f) {
  if (f != NULL) {
    return f->tamanho == 0;
  }
  return 0;
}

// Função para adicionar um valor na fila;
void fila_push(pfila f) {
  if (f != NULL) {
    f->tamanho++;
    f->fila = (int *)realloc(f->fila, f->tamanho * sizeof(int));
    int valor;
    scanf(" %d", &valor);
    f->fila[f->tamanho - 1] = valor;
  }
}

// Função para remover o primeiro item inserido na fila
void fila_pop(pfila f) {
  if (f != NULL) {
    if (fila_vazia(f)) {
      printf("vazia");
    } else {
      for (int i = 0; i < f->tamanho; i++) {
        f->fila[i] = f->fila[i + 1];
      }
      (f->tamanho)--;
    }
  }
}
void fila_popfull(pfila f) {
  if (f != NULL) {
    if (fila_vazia(f)) { // Verifica se a fila está vazia
      exit(1);
    } else {
      while (1) {
        for (int i = 0; i < f->tamanho; i++) {
          f->fila[i] = 0;
        }
        f->tamanho = 0;
        if (fila_vazia(f)) {
          break;
        }
      }
    }
  }
}

// Função para exibir toda a fila
void fila_exifull(pfila f) {
  if (f == NULL || fila_vazia(f)) {
    printf("Fila vazia");
    return;
  } else {
    for (int i = 0; i < f->tamanho; i++) {
      printf("%d, ", f->fila[i]);
      if (i == (f->tamanho - 1)) {
        printf("%d", f->fila[i]);
      }
    }
  }
}

// Função para exibir apenas um indice da fila.
void fila_exibir(pfila f, int indice) {
  if (f == NULL || fila_vazia(f)) {
    printf("Fila vazia ou erro de memoria!");
    return;
  } else if (indice > (f->tamanho) || indice < 0) {
    printf("O indice informado esta fora dos limites!");
  } else {
    printf("Valor no indice[%d]: %d", indice, f->fila[indice]);
  }
}