#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct comando {
  char *comando;
};
// Struct para a pilha
struct pilha {
  char *pilha;
  int tamanho;
};
char *aloc_pilcom() {
  char *c;
  c = (char *)malloc(2);
  return c;
}
// Função para alocar uma pilha
ppilha aloc_pilha() {
  ppilha p;
  p = (ppilha)malloc(sizeof(tpilha));
  p->pilha = NULL;
  return p;
};

// Inicializa a pilha com -1;
void inici_pilha(ppilha p) {
  if (p != NULL) {
    p->tamanho = 0;
    p->pilha[p->tamanho] = 0;
  }
}

// Libera a memoria alocada
inline void free_pilha(ppilha p) {
  if (p->pilha != NULL) {
    free(p->pilha);
  }
  if (p != NULL) {
    free(p);
  }
}

// Função para verificar se a pilha está vazia;
int vazia_pilha(ppilha p) {
  if (p != NULL) {
    return p->tamanho == 0;
  }
  return 0;
}

// Função para adicionar um dado a pilha
void push_pilha(ppilha p) {
  if (p != NULL) {
    p->tamanho++;
    p->pilha = (char *)realloc(p->pilha, p->tamanho * sizeof(char));
    char letra;
    scanf(" %c", &letra);
    p->pilha[p->tamanho - 1] = letra;
  }
}
// Função para remover o ultimo dado da pilha
void pop_pilha(ppilha p) {
  if (p != NULL) {
    if (vazia_pilha(p)) {
      return;
    } else {
      p->pilha[(p->tamanho)--];
    }
  }
}

// Função para exibir todos os dados da pilhas
void exifull_pilha(ppilha p) {
  if (p == NULL || vazia_pilha(p)) {
    printf("Pilha vazia");
    return;
  } else {
    int max = p->tamanho;
    for (int i = 0; i < (max + 1); i++) {
      printf("%c", p->pilha[i]);
    }
  }
}

// Função para exibir apenas um indice da pilha
void exi_pilha(ppilha p, int indice) {
  if (p == NULL || vazia_pilha(p)) {
    printf("Pilha vazia ou erro de memoria!");
    return;
  } else if (indice > (p->tamanho) || indice < 0) {
    printf("O indice informado esta fora dos limites!");
  } else {
    printf("Valor no indice[%d]: %d", indice, p->pilha[indice]);
  }
}
void limpar_pilha(ppilha p) {
  if (p != NULL) {
    int max = p->tamanho;
    for (int i = 0; i < max; i++) {
      pop_pilha(p);
    }
  }
}