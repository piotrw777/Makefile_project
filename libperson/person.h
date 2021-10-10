#ifndef MY_LIB_H
#define MY_LIB_H

typedef struct ctx_t ctx_t;

typedef struct person_t {
    ctx_t * ctx;
    void (*get_older)(struct person_t *, int years);
    int (*get_age)(struct person_t *);
    void (*introduce)(struct person_t *);
} person_t;

person_t * create(const char * name, int age);
void destroy(person_t * person);

#endif
