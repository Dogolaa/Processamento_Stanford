#ifndef FUNCOES_H
#define FUNCOES_H

void printMenu ();

void imagemNegativa(int valorMaximo, int stfd[], int lin, int col);
void inversaoVertical(int valorMaximo, int stfd[], int lin, int col);
void inversaoHorizontal(int valorMaximo, int stfd[], int lin, int col);
void rotacaoDireita(int valorMaximo, int stfd[], int lin, int col);
void escurecimentoDeBordas(int valorMaximo, int stfd[], int lin, int col);
void simetria(int valorMaximo, int i, int stfd[], int lin, int col);
void binarizarImagem(int valorMaximo, int stfd[], int lin, int col);

#endif /* FUNCOES_H */