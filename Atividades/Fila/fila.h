#ifndef __fila__h
#define __fila__h
typedef struct fila tfila, *pfila;
char* fila_caloc();
pfila fila_aloc();
void fila_free(pfila f);
void fila_iniciar(pfila f);
int fila_cheia(pfila f);
int fila_vazia(pfila f);
void fila_push(pfila f);
void fila_pop(pfila f);
void fila_exifull(pfila f);
void fila_exibir(pfila f, int indice);
void fila_popfull(pfila f);
#endif