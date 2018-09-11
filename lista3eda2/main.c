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

int* copyVector(int *copiedVector, int lenght) {
    int *finalVector;
    
    finalVector = malloc(lenght * sizeof(int));
    
    for (int i=0; i < lenght; i++) {
        finalVector[i] = copiedVector[i];
    }
    
    return finalVector;
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

void quickSort(int vector[], int inicioVetor, int fimVetor) {
    int i, j, pivo, aux;
    
    i = inicioVetor;
    j = fimVetor;
    
    //printf("--%d--", vector[(inicioVetor+fimVetor)/2]);
    
    pivo = vector[(inicioVetor+fimVetor)/2];
    
    while (i <= j) {
        while (vector[i] < pivo) {
            i = i+1;
        } while (pivo < vector[j]) {
            j = j-1;
        }
    
        if (i <= j) {
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i = i+1;
            j = j-1;
        }
    }
    if (inicioVetor < j) {
        quickSort(vector, inicioVetor, j);
    }
    if (fimVetor > i) {
        quickSort(vector, i, fimVetor);
    }
    
}

void bucketSort(int vector[], int lenght)
{
    int i, j;
    int count[lenght];
    
    double duration;
    
    clock_t start = clock();
    for (i = 0; i < lenght; i++) {
        count[i] = 0;
    }
    
    for (i = 0; i < lenght; i++) {
        (count[vector[i]])++;
    }
    
    for (i = 0, j = 0; i < lenght; i++) {
        for(; count[i] > 0; (count[i])--) {
            vector[j++] = i;
        }
    }
    clock_t end = clock();
    
    duration = end-start;
    printf("Bucket sort: %lf segundos\n", duration/ CLOCKS_PER_SEC);
}

int main() {
    int lenght;
    int range;
    
    int *vector1;
    int *vector2;
    int *vector3;
    
    
    printf("Selecione o tamanho do vetor a ser gerado: ");
    scanf("%d", &lenght);
    
    printf("Defina o valor máximo para os inteiros do vetor: ");
    scanf("%d", &range);
    
    vector1 = generateRandomVector(lenght, range);
    vector2 = copyVector(vector1, lenght);
    vector3 = copyVector(vector1, lenght);
    
    printf("Vetor gerado: ");
    for (int i=0; i < lenght; i++) {
        printf("%d ", vector1[i]);
    }
    
    printf("\n\n - Tempo de execução de cada algorítmo -\n");
    
    //ShellSort
    shellSort(vector1, lenght);
    
    //QuickSort
    double duration;
    clock_t start = clock();
    quickSort(vector2, 0, lenght-1);
    clock_t end = clock();
    duration = end-start;
    printf("Quick sort: %lf segundos\n", duration/ CLOCKS_PER_SEC);
    
    //Bucket Sort
    bucketSort(vector3, lenght);
    
    printf("Vetor ordenado: ");
    for (int i=0; i < lenght; i++) {
        printf("%d ", vector2[i]);
    }
    
    return 0;
}
