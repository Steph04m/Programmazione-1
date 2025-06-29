//Implementazione del Bubble Sort in C
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int* array, int n)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void printArray(int* array, int n)
{
    for(int i = 0; i < n; i++){
        printf("array[%d] = %d\n", i, array[i]);
    }
    puts("");
}

int main(int argc, char* argv[])
{
    int array[] = {3,8,5,2,1,7,0,4,9,6};
    printf("Array prima dell'ordinamento:\n");
    printArray(array, 10);

    BubbleSort(array, 10);
    printf("Array dopo l'ordinamento:\n");
    printArray(array, 10);
}