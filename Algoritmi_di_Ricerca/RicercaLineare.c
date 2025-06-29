//Implementazione della Ricerca Lineare (o Sequenziale) in C
#include <stdio.h>
#include <stdlib.h>

int RicercaLineare(int* array, int n, int r)
{
    for(int i = 0; i < n; i++){
        if(array[i] == r){
            return i;
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
    int array[] = {3,8,5,2,1,7,0,4,9,6};
    printf("Contenuto dell'array:\n");
    printArray(array, 10);

    int n;
    printf("Inserisci l'elemento da ricercare nell'array:\n");
    scanf("%d", &n);

    int r = RicercaLineare(array, 10, n);
    if(r != -1){
        printf("L'elemento cercato si trova qui: array[%d] = %d\n", r, n);
    } else {
        printf("Elemento non trovato.\n");
    }
}