#include <stdio.h>
#include <string.h>

struct person
{
    char            name[64];
    int             age;
    struct person*  next;
};

struct person * findPerson(struct person* ptr, char name[]);
void insertPerson(struct person* insertionPerson, struct person* previousPerson);
void printPerson(struct person* ptr);
void printList(struct person* start);

int main(void){
    struct person koren = { .name = "Koren", .age = 20};
    struct person yahav = {.name = "Yahav", .age = 18};
    struct person romi = {.name = "Romi", .age = 10};
    struct person lear = {.name = "Lear", .age = 23};
    struct person eli = {.name = "Eli", .age = 52};
    struct person sagit = {.name = "Sagit", .age = 49}; 

    struct person* start_list = &romi;
    romi.next = &yahav;
    yahav.next = &koren;
    koren.next = &lear;
    lear.next = &sagit;
    sagit.next = &eli;
    eli.next = NULL;

    struct person snowy = {.name = "Snowy", .age = 10, .next = NULL};
    insertPerson(&snowy, &romi);
    printList(start_list);
    
}

struct person* findPerson(struct person* ptr, char name[]){

    while(strcmp(ptr->name, name) != 0) // target name doesn't equal current struct name
    {
        ptr = ptr -> next;
        if(ptr == NULL)
        {
            printf("Name not found...\n");
            return NULL;
        }
    }

    return ptr; 
}


void insertPerson(struct person* insertionPerson, struct person* previousPerson){
    struct person* temp = previousPerson -> next; //pointer to the next person in list
    previousPerson->next = insertionPerson;
    insertionPerson->next = temp; 
}

void printPerson(struct person* ptr){
    if(ptr == NULL)
    {
        printf("Not such person exists...");
    }
    printf("Name: %s\nAge:%i\n", ptr->name, ptr->age);
}

void printList(struct person* start){
    do{
        printPerson(start);
        start = start->next;
    }while(start ->next != NULL);
}