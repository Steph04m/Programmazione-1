//Implementazione del Selection Sort in C
#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int* array, int n)
{
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
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

    SelectionSort(array, 10);
    printf("Array dopo l'ordinamento:\n");
    printArray(array, 10);
}