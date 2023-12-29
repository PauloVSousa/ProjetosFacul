#ifndef __pilha__h
#define __pilha__h

typedef struct pilha tpilha, *ppilha;

//Funções utilizaveis
ppilha aloc_pilha();
char *aloc_pilcom();
void free_pilha(ppilha p);
void inici_pilha(ppilha p);
void push_pilha(ppilha p);
void pop_pilha(ppilha p);
void exifull_pilha(ppilha p);
void exi_pilha(ppilha p, int indice);
void limpar_pilha(ppilha p);

//Funções apenas para o funcionamento da biblioteca
int vazia_pilha(ppilha p);
#endif