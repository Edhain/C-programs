#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name){ // naming hashtable hash
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i=0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table(){
    for (int i=0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    //table is empty
}

void print_table(){
    printf("Start\n");
    for (int i=0; i< TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i\t---\n",i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

bool hash_table_insert(person *p){
    if (p==NULL) return false;
    int index = hash(p->name);
    if (hash_table[index] != NULL){
        return false;
    }
    hash_table[index] = p;
    return true;
}

person *hash_table_lookup(char *name){
    int index = hash(name);
    if (hash_table[index] != NULL &&
        strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0){
            return hash_table[index];
    } else {
        return NULL;
    }
}

int main(){

    init_hash_table();
    print_table();

    person manas = {.name="Manas", .age=22};
    person tanu = {.name="Tanu", .age=13};
    person aditya = {.name="Aditya", .age=23};
    person anshul = {.name="Anshul", .age=21};

    hash_table_insert(&manas);
    hash_table_insert(&tanu);
    hash_table_insert(&aditya);
    hash_table_insert(&anshul);
    print_table();

    person *tmp = hash_table_lookup("Manas");
    if (tmp == NULL){
        printf("not found\n");
    } else {
        printf("found %s. \n", tmp->name);
    }

    tmp = hash_table_lookup("John");
    if (tmp == NULL){
        printf("not found\n");
    } else {
        printf("found %s. \n", tmp->name);
    }

    return 0;
}