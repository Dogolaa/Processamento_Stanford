#include <iostream>
#include <fstream>

using namespace std;

void imagemNegativa(int valorMaximo, int stfd[], int lin, int col){
    int *p, i;
    ofstream newimage;
    newimage.open ("images/imagemNegativa.pgm");
    if (newimage.is_open()) {
        cout << "Criando a nova imagem..." << endl;
        newimage << "P2" << endl;
        newimage << "# Edited" << endl;
        newimage << lin << " " << col << endl;
        newimage << valorMaximo << endl;
        for (p = &stfd[0], i = 1; p < &stfd[0] + (lin * col); p++, i++){
            newimage << valorMaximo - *p << " ";
            if (i == col){
                newimage << endl;
            }
        }
        newimage.close();
    }
}

void inversaoVertical(int valorMaximo, int stfd[], int lin, int col){
    int *p, *q;
    ofstream newimage;
    newimage.open ("images/inversaoVertical.pgm");
    if (newimage.is_open()) {
        cout << "Criando a nova imagem..." << endl;
        newimage << "P2" << endl;
        newimage << "# Edited" << endl;
        newimage << lin << " " << col << endl;
        newimage << valorMaximo << endl;
        for (p = &stfd[0] + (lin * col) - lin; p > &stfd[0]; p -= lin){
            for (q = p; q < p + lin; q++){
                newimage << *q << " ";
            }
            newimage << endl;
        }
        newimage.close();
    }
}

void inversaoHorizontal(int valorMaximo, int stfd[], int lin, int col){
    int *p, *q;
    ofstream newimage;
    newimage.open ("images/inversaoHorizontal.pgm");
    if (newimage.is_open()) {
        cout << "Criando a nova imagem..." << endl;
        newimage << "P2" << endl;
        newimage << "# Edited" << endl;
        newimage << lin << " " << col << endl;
        newimage << valorMaximo << endl;
        for (p = &stfd[0] + lin; p <= &stfd[0] + (lin * col); p += lin){
            for (q = p; q > p - lin; q--){
                newimage << *q << " ";
            }
            newimage << endl;
        }
        newimage.close();
    }
}

void rotacaoDireita(int valorMaximo, int stfd[], int lin, int col){
    int *p, *q;
    int aux =  lin;
    lin = col;
    col = aux;
    ofstream newimage;
    newimage.open ("images/RotacaoDireita.pgm");
    if (newimage.is_open()) {
        cout << "Criando a nova imagem..." << endl;
        newimage << "P2" << endl;
        newimage << "# Edited" << endl;
        newimage << lin << " " << col << endl;
        newimage << valorMaximo << endl;
        for (p = &stfd[0] + (lin * col) - col; p <= &stfd[0] + (lin * col); p++){
            for (q = p; q >= p - (lin * col) + col; q -= col){
                newimage << *q << " ";
            }
            newimage << endl;
        }
        newimage.close();
    }
}

void escurecimentoDeBordas(int valorMaximo, int stfd[], int lin, int col){
    int *p1, *q1, *q2, *p2, *r, i, j;
    p1 = &stfd[0];
    q1 = &stfd[0] + lin;
    q2 = &stfd[0] + (lin * col);
    p2 = &stfd[0] + (lin * col) - lin;
    ofstream newimage;
    newimage.open ("images/EscurecimentoDeBordas.pgm");
    if (newimage.is_open()) {
        cout << "Criando a nova imagem..." << endl;
        newimage << "P2" << endl;
        newimage << "# Edited" << endl;
        newimage << lin << " " << col << endl;
        newimage << valorMaximo << endl;
        for (int i = 0, j = 150; i < 60; i++, j-=2){
            
            //Laço for para escurecimento da parte superior
            for (r = p1; r < q1; r++){
                *r -= j;
                if (*r <= 0){
                    *r = 0;
                }
            }
            
            //Laço for para escurecimento da parte lateral direita
            for (r = q1; r < q2; r += lin){
                *r -= j;
                if (*r <= 0){
                    *r = 0;
                }
            }
            
            //Laço for para escurecimento da parte inferior
            for (r = q2; r > p2; r--){
                *r -= j;
                if (*r <= 0){
                    *r = 0;
                }
            }
            
            //Laço for para escurecimento da parte lateral esquerda
            for (r = p2; r > p1; r -= lin){
                *r -= j;
                if (*r <= 0){
                    *r = 0;
                }
            }

            
            p1 = p1 + lin + 1;          //Altera os valores iniciais de r
            q1 = (q1 + lin) - 1;        //para evitar escurecer mais de uma vez
            q2 = q2 - lin - 1;
            p2 = (p2 - lin) + 1;
        }
        
        
        //Laço for para imprimir a parte da imagem que não foi escurecida
        for (r = &stfd[0], i = 1; r < &stfd[0] + (lin * col); r++, i++){
            newimage << *r - j << " ";
            if (i == col){
                newimage << endl;
                i = 0;
            }
        }
        newimage.close();
    }
}

void simetria(int valorMaximo, int i, int stfd[], int lin, int col){
    int *p, *q, *r;
    p = &stfd[0];
    for (q = &stfd[0] + lin; q <= &stfd[0] + (lin * col); q += lin)
    {
        for (r = q; r > q - lin; r--)
        {
            *p = *r;
            p++;
        }
    }
ofstream newimage;
    newimage.open ("images/simetria.pgm");
    if (newimage.is_open()) 
    {
        newimage << "P2" << endl;
        newimage << "# Edited " << endl;
        newimage << lin << " " << col << endl;
        newimage << valorMaximo << endl;
        for (p = &stfd[0], i = 1; p <= &stfd[0] + (lin * col); p++, i++)
        {
            newimage << *p << " ";
            if (i == col)
            {
                newimage << endl;
            }
        }
        newimage.close();
    }
}

void binarizarImagem(int valorMaximo, int stfd[], int lin, int col){
    int *p, i;
    
    //Imprime os valores escuros como 0 e os claros como 255
    
    ofstream newimage;
    newimage.open ("images/Binarizar.pgm");
    if (newimage.is_open()) {
        cout << "Criando a nova imagem..." << endl;
        newimage << "P2" << endl;
        newimage << "# Edited" << endl;
        newimage << lin << " " << col << endl;
        newimage << valorMaximo << endl;
        for (p = &stfd[0], i = 1; p < &stfd[0] + (lin * col); p++, i++){
            if (*p <= (valorMaximo / 2)){
                *p = 0;
            } else {
                *p = 255;
            }
            newimage << *p << " ";
            if (i == col){
                newimage << endl;
            }
        }
        newimage.close();
    }
}

void printMenu(){
    cout << "--------Menu de opcoes----- " << endl;
    cout << "Digite o valor para opção desejada:" << endl;
    cout << "1 - Imagem negativa" << endl;
    cout << "2 - Inversão vertical" << endl;
    cout << "3 - Inversão horizontal" << endl;
    cout << "4 - Rotação à direita" << endl;
    cout << "5 - Escurecer bordas" << endl;
    cout << "6 - Imagem simétrica" << endl;
    cout << "7 - Binarizar" << endl;
    cout << endl << "0 - Sair da aplicação" << endl;
}
   
    


   
    

 
    
