//Implementazione della Ricerca Binaria in C
//N.B.: La ricerca binaria funziona ESCLUSIVAMENTE se l'array è ordinato.
#include <stdio.h>
#include <stdlib.h>

int RicercaBinaria(int* array, int n, int low, int high)
{
    while(low <= high){
        int mid = low + (high - low)/2;
        if(array[mid] == n){
            return mid;
        }

        if(array[mid] < n){
            low = mid + 1;
        }

        if(array[mid] > n){
            high = mid - 1;
        }
    }
    return -1;
}

void printArray(int* array, int n)
{
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    puts("");
}

int main(int argc, char* argv[])
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    printf("Contenuto dell'array:\n");
    printArray(array, 10);

    int n;
    printf("Inserisci l'elemento da ricercare nell'array:\n");
    scanf("%d", &n);

    int r = RicercaBinaria(array, n, 0, 10);
    if(r != -1){
        printf("L'elemento cercato si trova qui: array[%d] = %d\n", r, n);
    } else {
        printf("Elemento non trovato.\n");
    }
}