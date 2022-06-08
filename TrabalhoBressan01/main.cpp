/*
 * Editor de imagens PGM 
 * Trabalho 1 - Aeds 2
 * Professor  Paulo Bressan
 * 
 * 
 * Caio Costa
 * Matricula: 2020.1.08.007
 * 
 * Lucas Dogo
 * Matricula: 2020.1.08.026
 * 
 * Brandon Afonso de Souza
 * Matricula: 2021.1.08.045
 */

#include <iostream>
#include <fstream>
#include "funcoes.h"

using namespace std;

int main() {
    int lin, col, i, j, valorMaximo, opcao;
    int  *p;
    string line;
    ifstream original("stanford.pgm");
    
    //Leitura das informações do cabeçalho.
    if (original.is_open()){       
        getline(original, line);
        getline(original, line);
        original >> lin;
        original >> col;
        original >> valorMaximo;
    } 
    
    //Leitura das informações do corpo da imagem.
    int stfd[lin * col];
    while ( !original.eof()){
        for (p = &stfd[0], i = 1; p < &stfd[0] + (lin * col); p++, i++){
            original >> *p;
            if (i == col){
                i = 1;
            }
        }
    }     
    original.close();
    
    //Display do menu e input da função escolhida pelo usuário.
    printMenu();
    cin >> opcao;
    switch (opcao)   
    {
        case 1: 
            imagemNegativa(valorMaximo, stfd, lin, col);
            break;
        case 2:
            inversaoVertical(valorMaximo, stfd, lin, col);
            break;
        case 3:
            inversaoHorizontal(valorMaximo, stfd, lin, col);
            break;
        case 4:
            rotacaoDireita(valorMaximo, stfd, lin, col);
            break;
        case 5:
            escurecimentoDeBordas(valorMaximo, stfd, lin, col);
            break;
        case 6:
            simetria(valorMaximo, i, stfd, lin, col);
            break;
        case 7:
            binarizarImagem(valorMaximo, stfd, lin, col);
            break;
        default: 
            cout << "Saindo do editor..." << endl;
            break;
    }
    return 0;
}