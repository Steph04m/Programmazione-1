//Implementazione dell'Insertion Sort in C
#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int* array, int n)
{
    for(int i = 1; i < n; i++){
        int key = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
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

    InsertionSort(array, 10);
    printf("Array dopo l'ordinamento:\n");
    printArray(array, 10);
}