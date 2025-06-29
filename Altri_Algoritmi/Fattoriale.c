//Implementazione ricorsiva in C per il Fattoriale di un numero
#include <stdio.h>
#include <stdlib.h>

int Fattoriale(int x)
{
    if(x == 0 || x == 1){
        return 1;
    } else {
        return (x * Fattoriale(x-1));
    }
}

int main(int argc, char* argv[])
{
    int n;
    printf("Inserisci un numero: \n");
    scanf("%d", &n);

    int f = Fattoriale(n);
    printf("Fattoriale di %d: %d", n, f);
    puts("");
}