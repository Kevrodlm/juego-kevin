#pragma once
#include <iostream>

using namespace std;
int** matrizgenerator(const int tam) {
    int** mapa = new int* [tam];
    for (int i = 0; i < tam; i++) {
        mapa[i] = new int[tam];
    }
    for (int j = 0; j < tam; j++) {
        for (int i = 0; i < tam; i++) {
            mapa[j][i] = 0;
        }
    }
    return mapa;
}
void viewM(int** matriz, int tam) {
    for (int j = 0; j < tam; j++) {
        for (int i = 0; i < tam; i++) {
            cout << matriz[j][i] << " ";
        }
        cout << endl;
    }
}
void borrarM(int** matriz, int tam) {
    for (int j = 0; j < tam; j++) {
        delete[] matriz[j];
    }
    delete[] matriz;
}
int genPosMainRooms(int min, int max, int seedVal, int mapNum) {
    int pos = min + ((max + seedVal + mapNum) % 3);
    return pos;
}
void genMainRooms(int** matriz, int rangex, int rangey, int seed[8], int mapNum, int NumSeed, int* posx, int* posy, int type) {
    int i = 0;
    do {
        *posx = genPosMainRooms(rangex - 1, rangex + 1, seed[(0 + NumSeed + i) % 8], mapNum);
        *posy = genPosMainRooms(rangey - 1, rangey + 1, seed[(1 + NumSeed + i) % 8] + seed[*posx % 8], mapNum);
        i++;
    } while (matriz[*posy][*posx] != 0);
    matriz[*posy][*posx] = type;

}
void genOtherRooms(int** matriz, int posXIni, int posYIni, int posXFin, int posYFin, int NumSeed) {
    if (NumSeed % 2 == 0) {
        if (posYIni == posYFin) {
            posXFin++;
        }
        if (posXIni == posXFin) {
            posYIni++;
        }
        if (posXIni > posXFin) {
            for (int i = posXFin; i < posXIni; i++) {
                matriz[posYIni][i] = 1;
            }
        }
        else {
            for (int i = posXIni + 1; i <= posXFin; i++) {
                matriz[posYIni][i] = 1;
            }
        }
        if (posYIni > posYFin) {
            for (int i = posYFin + 1; i < posYIni; i++) {
                matriz[i][posXFin] = 1;
            }
        }
        else {
            for (int i = posYIni; i < posYFin; i++) {
                matriz[i][posXFin] = 1;
            }
        }
    }
    else {
        if (posYIni == posYFin) {
            posXFin++;
        }
        if (posXIni == posXFin) {
            posYIni++;
        }
        if (posXIni > posXFin) {
            for (int i = posXFin + 1; i < posXIni; i++) {
                matriz[posYFin][i] = 1;
            }
        }
        else {
            for (int i = posXIni + 1; i < posXFin; i++) {
                matriz[posYFin][i] = 1;
            }
        }
        if (posYIni > posYFin) {
            for (int i = posYFin; i < posYIni; i++) {
                matriz[i][posXIni] = 1;
            }
        }
        else {
            for (int i = posYIni + 1; i <= posYFin; i++) {
                matriz[i][posXIni] = 1;
            }
        }
    }
}
/*void genAllMap(int** matriz,int seed[8],int mapNum,int NumSeed,int tam){
    int *x[5];
    int *y[5];
    int *[8];
    int i=0;
    genMainRooms(matriz,4,4,seed,2,seed[0],x[0],y[0],2);
    genMainRooms(matriz,1,1,seed,2,seed[1],x[1],y[1],3);
    do{
    genMainRooms(matriz,1,1,seed,2,seed[i++%8],[0],[0],4);}
    while()
}*/
/*
int main()
{
    int seed[8] = { 1,2,8,4,2,2,7,8 };
    int** piso1 = matrizgenerator(5);
    int** piso2 = matrizgenerator(7);
    int** piso3 = matrizgenerator(9);
    int x = 0, y = 0, w = 0, z = 0;
    cout << "seed: ";
    for (int i = 0; i < 8; i++) {
        cout << seed[i] << " ";
    }
    cout << endl;
    cout << "vals: " << x << " " << y << endl;
    genMainRooms(piso3, 4, 4, seed, 2, seed[0], &x, &y, 9);
    genMainRooms(piso3, 1, 1, seed, 2, seed[1], &w, &z, 3);
    genOtherRooms(piso3, x, y, w, z, seed[1]);
    genMainRooms(piso3, 1, 7, seed, 2, seed[1], &w, &z, 4);
    genOtherRooms(piso3, x, y, w, z, seed[2]);
    genMainRooms(piso3, 7, 7, seed, 2, seed[1], &w, &z, 5);
    genOtherRooms(piso3, x, y, w, z, seed[3]);
    genMainRooms(piso3, 7, 1, seed, 2, seed[1], &w, &z, 6);
    genOtherRooms(piso3, x, y, w, z, seed[4]);
    //cuartos basura
    genMainRooms(piso3, 7, 1, seed, 2, seed[1], &w, &z, 2);
    genOtherRooms(piso3, x, y, w, z, seed[5]);
    viewM(piso3, 9);
    /*genMainRooms(piso3,1,1,seed,2,seed[1]);
    genMainRooms(piso3,7,1,seed,2,seed[2]);
    genMainRooms(piso3,7,7,seed,2,seed[3]);
    genMainRooms(piso3,1,7,seed,2,seed[4]);
    cout << endl;
    //viewM(piso3,9);
    borrarM(piso1, 5);
    borrarM(piso2, 7);
    borrarM(piso3, 9);
    return 0;
}*/