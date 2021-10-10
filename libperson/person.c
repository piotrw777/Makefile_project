#include <person.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stars.h>
#include <base.h>

#define MAX_NAME_LENGTH 32

struct ctx_t {
    char name[MAX_NAME_LENGTH];
    int age;
};

void get_older(struct person_t * person, int years)
{
    person->ctx->age += years;
}

int get_age(struct person_t * person)
{
    return person->ctx->age;
}

void introduce(struct person_t * person)
{
    int age = person->ctx->age;
    char * name = person->ctx->name;
    printf("\n");
    draw_stars(7);
    printf("Hello, my name is %s and \
I am %d years old\n", name, age);
    draw_stars(7);
    printf("\n");
}

person_t * create(const char * name, int age)
{
    base();
    //create an object
    person_t * person = (person_t *) calloc(1, sizeof(person_t));
    //allocate memory for ctx
    person->ctx = (ctx_t *) calloc(1, sizeof(ctx_t));
    //fill data
    strcpy(person->ctx->name, name);
    person->ctx->age = age;
    //assign functions pointers
    person->get_older    = get_older;
    person->get_age      = get_age;
    person->introduce    = introduce;

    return person;
}

void destroy(struct person_t * person)
{
    free(person->ctx);
    free(person);
}


