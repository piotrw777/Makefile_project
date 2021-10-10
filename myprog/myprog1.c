#include <person.h>
#include <stdio.h>

void fun1()
{
    person_t *janek = create("Jan Kowalski", 50);
    janek->introduce(janek);
    char marek_name[] = "Marek Nowak";
    person_t *marek = create(marek_name, 25);
    int wiek_marka = marek->get_age(marek);
    marek->introduce(marek);
    marek->get_older(marek, 6);
    marek->introduce(marek);

    printf("Wiek Marka: %d\n", wiek_marka);

    destroy(janek);
    destroy(marek);
}
