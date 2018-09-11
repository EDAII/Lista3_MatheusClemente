//
//  main.c
//  lista3eda2
//
//  Matheus Clemente Carvalho de Azevedo
//  15/0042817

#include <stdio.h>
#include <time.h>

int* generateRandomVector(int lenght, int maxValue) {
    int *vector;
    
    vector = malloc(lenght * sizeof(int));
    
    for (int i=0; i < lenght; i++) {
        vector[i] = rand() % maxValue+1;
    }
    
    return vector;
}

void shellSort(int vector[], int lenght) {
    int gap = lenght/2;
    int auxValue, auxIndex;
    double duration;
    
    clock_t start = clock();
    while (gap > 0) {
        for (int i = gap; i< lenght; i++) {
            auxValue = vector[i];
            auxIndex = i;
            while (auxIndex >= gap && vector[auxIndex - gap] > auxValue) {
                vector[auxIndex] = vector[auxIndex - gap];
                auxIndex = auxIndex - gap;
            }
            vector[auxIndex] = auxValue;
            
        }
        gap = gap/2;
        
    }
    clock_t end = clock();
    
    duration = end-start;
    printf("Shell sort: %lf segundos\n", duration/ CLOCKS_PER_SEC);
}

int main() {

    int *vector1;
    int lenght;
    int range;
    
    printf("Selecione o tamanho do vetor a ser gerado: ");
    scanf("%d", &lenght);
    
    printf("Defina o valor máximo para os inteiros do vetor: ");
    scanf("%d", &range);
    
    vector1 = generateRandomVector(lenght, range);
    
    printf("Vetor gerado: ");
    for (int i=0; i < lenght; i++) {
        printf("%d ", vector1[i]);
    }
    
    printf("\n\n - Tempo de execução de cada algorítmo -\n");
    shellSort(vector1, lenght);
    
    printf("Vetor ordenado: ");
    for (int i=0; i < lenght; i++) {
        printf("%d ", vector1[i]);
    }
    
    return 0;
}
