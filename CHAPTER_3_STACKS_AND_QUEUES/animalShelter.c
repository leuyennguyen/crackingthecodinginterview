/*
	Problem 3.6 ANIMAL SHELTER
	An animal shelter, which holds only dogs and cats, operates on a strictly 
    "first in, first out" basis. People must adopt either the "oldest" (based
    on arrival time) of all animals at the shelter, or they can select whether
    they would prefer a dog or a cat (and will receive the oldest animal of
    that type). They cannot select which specific animal they would like.
    Create the data structures to maintain this system and implement operations
    such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the
    built-in LinkedList data structure.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[10];
    char arrivalTime[9];
    struct node *next;
} node;

void enqueue(node **Head, node**Tail) {
    char name[10] = {}, arrTime[9] = {};
    printf("Enter the pet's name (less than 10 characters): ");
    scanf("%s", name);
    printf("Enter the pet's arrival time (mmddyyyy): ");
    scanf("%s", arrTime);
    
    node *newPet = malloc(sizeof(node));
    strcpy(newPet->name, name);
    strcpy(newPet->arrivalTime, arrTime);
    newPet->next = NULL;

    if (*Head == NULL) {
        *Head = *Tail = newPet;
    }
    else {
        (*Tail)->next = newPet;
        *Tail = newPet;
    }
}

void viewList(node *Head) {
    if (Head == NULL) {
        printf("There is no pet at the moment!\n");
        return;
    }
    node *temp = Head;
    int counter = 1;
    printf("=============================================\n");
    printf("\tLIST OF PETS\n")

    while (temp != NULL) {
        printf("%d. %10s\t", counter++, temp->name);
        int i;
        for (i = 0 ; i < 8 ; i++) {
            if (i == 2 || i == 4) {
                printf("/");
            }
            printf("%c", temp->arrivalTime[i]);
        }
        printf("\n");
        temp = temp->next;
    }
}

void adminMode(node **DogQueueHead, node **DogQueueTail,
                node  **CatQueueHead, node **CatQueueTail) {
    int passcode;
    printf("Enter admin's 4-digit passcode: ");
    scanf("%d", &passcode);
    if (passcode == 1234) {
        int choice;
        do {
            printf("=============================================\n");
            printf("Hello admin! What would you like to do today?\n");
            printf("1. View list of dogs\n");
            printf("2. View list of cats\n");
            printf("3. Enqueue a dog\n");
            printf("4. Enqueue a cat\n");
            printf("5. Exit\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1: viewList(*DogQueueHead); break;
                case 2: viewList(*CatQueueHead); break;
                case 3: enqueue(DogQueueHead, DogQueueTail); break;
                case 4: enqueue(CatQueueHead, CatQueueTail); break;
                case 5: break;
                default: printf("The system does not support this choice :(\n");
            }
        }
        while (choice != 5);
        
    }
    return;
}

void dequeuePet(node **Head) {
    node *temp = (*Head)->next;

    if (*Head == NULL) {
        printf("There is no dog to adopt at the moment!\n");
    }
    else {
        printf("Congratulation! You just adopted %s\n!", (*Head)->name);
        free(*Head);
        *Head = temp;
    }
}

void dequeueAny(node **DogList, node **CatList) {
    int age;
    age = strcmp((*DogList)->arrivalTime, (*CatList)->arrivalTime);
    if (age <= 0) {
        dequeuePet(DogList);
    }
    else if (age > 0) {
        dequeuePet(CatList);
    }
}

void adopterMode(node **DogQueueHead, node  **CatQueueHead) {
    int choice;
    printf("=============================================\n");
    printf("Hello! Would you like to adopt ... ?\n");
    printf("\t1. Dog\n\t2. Cat\n\t3. Any\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: dequeuePet(DogQueueHead); break;
        case 2: dequeuePet(CatQueueHead); break;
        case 3: dequeueAny(DogQueueHead, CatQueueHead); break;
        default: printf("Sorry! We currently don't have your dream pet!\n");
    }
}

int main() {
    node *DogQueueHead = NULL, *DogQueueTail = NULL;
    node *CatQueueHead = NULL, *CatQueueTail = NULL;

    enum Mode {
        Admin=1, Adopter, Exit
    };
    int mode;
    do {
        printf("=============================================\n");
        printf("Welcome to Animal Shelter!\n\n");
        printf("Are you ... ?\n\t1. Admin\n\t2. Adopter\n\t3. Exit\n");
        scanf("%d", &mode);
        switch (mode) {
            case Admin: adminMode(&DogQueueHead, &DogQueueTail, &CatQueueHead, &CatQueueTail);
                        break;
            case Adopter: adopterMode(&DogQueueHead, &CatQueueHead); 
                        break;
            case Exit: break;
            default: printf("The system does not support your choice.\n");
        }
    }
    while (mode != 3);
    
    return 0;
}