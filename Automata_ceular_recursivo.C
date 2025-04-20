//Automata celular recursivo - Gomez Rivera Amir

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM1 500// número de generaciones, max 500
#define TAM2 940 // tamaño de la matriz, max 940


void FRecursiva(int Generaciones[TAM1][TAM2], int binario[8], int i, int j);
void Rule(int vecindad[3], int binario[8]);

int main() {
    int decimal, i, j;
    int binario[8];
    int Generaciones[TAM1][TAM2];

    printf("Ingresa un numero decimal entre 0 y 255: ");
    scanf("%d", &decimal);

    if (decimal < 0 || decimal > 255) {
        printf("El numero ingresado está fuera del rango válido (0-255).\n");
        return 1;
    }

    // Conversión a binario
    for (i = 7; i >= 0; i--) {
        binario[i] = decimal % 2;
        decimal /= 2;
    }

    printf("El numero en binario para utilizar como regla es: ");
    for (i = 0; i < 8; i++) {
        printf("%d", binario[i]);
    }
    printf("\n");

   
    srand(time(0));
    for (j = 0; j < TAM2; j++) {
        Generaciones[0][j] = rand() % 2;  
    }

    FRecursiva(Generaciones, binario, 1, 0); 
    

    return 0;
}

void FRecursiva(int Generaciones[TAM1][TAM2], int binario[8], int i, int j) {
    if (i >= TAM1) {
        return;
    }

    for (j = 0; j < TAM2; j++) {
        int vecindad[3] = {
            Generaciones[i - 1][(j + TAM2 - 1) % TAM2],
            Generaciones[i - 1][j],
            Generaciones[i - 1][(j + 1) % TAM2]
        };
        Rule(vecindad, binario);
        Generaciones[i][j] = vecindad[1];
    }
//impresion de las generaciones
    for (int k = 0; k < TAM2; k++) {
        printf("%d ", Generaciones[i][k]);
    }
    printf("\n");

    FRecursiva(Generaciones, binario, i + 1, 0);
    
}

// Reglas del automata celular
void Rule(int vecindad[3], int binario[8]) {
    
    if (vecindad[0] == 1 && vecindad[1] == 1 && vecindad[2] == 1) {
        vecindad[1] = binario[0];
    } else if (vecindad[0] == 1 && vecindad[1] == 1 && vecindad[2] == 0) {
        vecindad[1] = binario[1];
    } else if (vecindad[0] == 1 && vecindad[1] == 0 && vecindad[2] == 1) {
        vecindad[1] = binario[2];
    } else if (vecindad[0] == 1 && vecindad[1] == 0 && vecindad[2] == 0) {
        vecindad[1] = binario[3];
    } else if (vecindad[0] == 0 && vecindad[1] == 1 && vecindad[2] == 1) {
        vecindad[1] = binario[4];
    } else if (vecindad[0] == 0 && vecindad[1] == 1 && vecindad[2] == 0) {
        vecindad[1] = binario[5];
    } else if (vecindad[0] == 0 && vecindad[1] == 0 && vecindad[2] == 1) {
        vecindad[1] = binario[6];
    } else if (vecindad[0] == 0 && vecindad[1] == 0 && vecindad[2] == 0) {
        vecindad[1] = binario[7];
    }
}

