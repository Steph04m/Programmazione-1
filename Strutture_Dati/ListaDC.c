// Implementazione di una Lista Doppiamente Concatenata in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo{
    int data;
    struct Nodo* next;
    struct Nodo* prev;
}Nodo;

typedef struct Lista{
    Nodo* head;
    int size;
}Lista;

Lista* getList()
{
    Lista* list = (Lista*)malloc(sizeof(Lista));
    if(list == NULL){
        fprintf(stderr, "Errore: Impossibile allocare la Lista.\n");
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->size = 0;
    return list;
}

bool isEmpty(Lista* list)
{
    if(list->size == 0){
        return true;
    } else {
        return false;
    }
}

void Insert(Lista* list, int n)
{
    Nodo* newnode = (Nodo*)malloc(sizeof(Nodo));
    if(newnode == NULL){
        fprintf(stderr, "Errore: Impossibile allocare il nodo.\n");
        exit(EXIT_FAILURE);
    }

    newnode->data = n;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(list->head == NULL){
        list->head = newnode;
    } else if(newnode->data <= list->head->data){
        newnode->next = list->head;
        list->head->prev = newnode;
        list->head = newnode;
    } else {
        Nodo* current = list->head;
        while(current->next && newnode->data > current->next->data){
            current = current->next;
        }

        newnode->next = current->next;
        if(current->next != NULL){
            current->next->prev = newnode;
        }
        current->next = newnode;
        newnode->prev = current;
    }
    list->size++;
}

void Remove(Lista* list, int n)
{
    if(isEmpty(list)){
        fprintf(stderr, "Errore: La lista è vuota.\n");
        exit(EXIT_FAILURE);
    }

    if(list->head->data == n){
        Nodo* tmp = list->head;
        list->head = list->head->next;
        if(list->head != NULL){
            list->head->prev = NULL;
        }
        free(tmp);
        list->size--;
        return;
    }

    Nodo* current = list->head;
    while(current->next != NULL && current->data != n){
        current = current->next;
    }

    if(current == NULL){
        fprintf(stderr, "Errore: elemento non presente nella lista.\n");
        exit(EXIT_FAILURE);
    }

    if(current->prev != NULL){
        current->prev->next = current->next;
    }

    if(current->next != NULL){
        current->next->prev = current->prev;
    }
    free(current);
    list->size--;
}

void printList(Lista* list)
{
    if(isEmpty(list)){
        fprintf(stderr, "Errore: La lista è vuota.\n");
        exit(EXIT_FAILURE);
    }
    
    Nodo* tmp = list->head;
    while(tmp != NULL){   
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void clearList(Lista* list)
{
    while(list->head != NULL){
        Nodo* tmp = list->head;
        list->head = list->head->next;
        free(tmp);
        list->size--;
    }
    printf("Lista eliminata al termine del programma.\n");
    free(list);
}

int main(int argc, char* argv[])
{   
    Lista* list = getList();

    Insert(list, 4);
    Insert(list, 8);
    Insert(list, 2);
    Insert(list, 1);
    Insert(list, 3);
    Insert(list, 5);
    Insert(list, 7);
    Insert(list, 6);
    Insert(list, 9);

    printf("Contenuto della Lista:\n");
    printList(list);
    printf("Size Coda: %d\n", list->size);

    int n;
    printf("Inserisci un numero presente nella lista da eliminare:\n");
    scanf("%d", &n);
    Remove(list, n);

    printf("\n");
    printf("Contenuto della Lista dopo la rimozione:\n");
    printList(list);
    printf("Size Coda: %d\n", list->size);
    
    clearList(list);
}
