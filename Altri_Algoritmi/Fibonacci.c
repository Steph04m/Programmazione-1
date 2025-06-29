//Implementazione ricorsiva in C per la Serie di Fibonacci di un numero
#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int n)
{
    if(n == 0 || n == 1){
        return n;
    } else {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main(int argc, char* argv[])
{
    int n;
    printf("Inserisci un numero: \n");
    scanf("%d", &n);

    printf("Serie di Fibonacci dato %d:\n", n);
    for(int i = 0; i < n; i++){
        int f = Fibonacci(i);
        printf("%d ", f);
    }
    puts("");
}