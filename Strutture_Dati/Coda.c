//Implementazione di una Coda di interi in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo{
    int data;
    struct Nodo* next;
}Nodo;

typedef struct Coda{
    Nodo* head;
    Nodo* tail;
    int size;
}Coda;

Coda* getQueue()
{
    Coda* Queue = (Coda*)malloc(sizeof(Coda));
    if(Queue == NULL){
        fprintf(stderr, "Errore: Impossibile allocare la Coda.\n");
        exit(EXIT_FAILURE);
    }

    Queue->head = NULL;
    Queue->tail = NULL;
    Queue->size = 0;
    return Queue;
}

bool isEmpty(Coda* Queue)
{
    if(Queue->size == 0){
        return true;
    } else {
        return false;
    }
}

void EnQueue(Coda* Queue, int n)
{
    Nodo* newnode = (Nodo*)malloc(sizeof(Nodo));
    if(newnode == NULL){
        fprintf(stderr, "Errore: Impossibile allocare il nodo.\n");
        exit(EXIT_FAILURE);
    }

    newnode->data = n;
    newnode->next = NULL;
    if(Queue->tail == NULL){
        Queue->head = Queue->tail = newnode;
    } else {
        Queue->tail->next = newnode;
        Queue->tail = newnode;
    }
    Queue->size++;
}

void DeQueue(Coda* Queue)
{
    if(isEmpty(Queue)){
        fprintf(stderr, "Errore: La Coda è vuota.\n");
        exit(EXIT_FAILURE);
    }

    Nodo* tmp = Queue->head;
    if(Queue->head == Queue->tail){
        Queue->head = Queue->tail = NULL;
    } else {
        Queue->head = Queue->head->next;
    }
    free(tmp);
    Queue->size--;
}

void printQueue(Coda* Queue)
{
    Nodo* tmp = Queue->head;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void clearQueue(Coda* Queue)
{
    while(Queue->head != NULL){
        Nodo* tmp = Queue->head;
        Queue->head = Queue->head->next;
        free(tmp);
        Queue->size--;
    }
    printf("Coda eliminata al termine del programma.\n");
    free(Queue);
}

int main(int argc, char* argv[])
{
    Coda* Queue = getQueue();

    EnQueue(Queue, 1);
    EnQueue(Queue, 2);
    EnQueue(Queue, 3);
    EnQueue(Queue, 4);
    EnQueue(Queue, 5);
    EnQueue(Queue, 6);
    EnQueue(Queue, 7);
    EnQueue(Queue, 8);
    EnQueue(Queue, 9);

    printf("Contenuto della Coda:\n");
    printQueue(Queue);
    printf("Size Coda: %d\n", Queue->size);

    DeQueue(Queue);
    DeQueue(Queue);

    printf("\n");
    printf("Contenuto della Coda dopo due DeQueue:\n");
    printQueue(Queue);
    printf("Size Coda: %d\n", Queue->size);

    clearQueue(Queue);
}
