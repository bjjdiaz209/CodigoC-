#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct 
{
    int age;
    int type;
    void (*hablar)();
    void (*comer)();
} Animal;

typedef struct 
{
    Animal a;
    int n_eggs;	
} Oviparo;

void perro_hablar()
{
puts("Gua");
}

void perro_comer()
{
    puts("Como gato");
}

void gato_comer()
{
    puts("Como ratones");
}

void gato_hablar()
{
    puts("miau");
}

void pollo_hablar()
{
    puts("kikiriki");
}

void new_perro(Animal* p, int age)
{
    p->age = age;
    p->hablar = perro_hablar;
    p->comer = perro_comer;
}

void new_gato(Animal* g, int age){
    g->age = age;
    g->hablar = gato_hablar;
    g->comer = gato_comer;
}

void new_pollo(Oviparo* p, int age, int n_eggs)
{
    p->a.age = age;
    p->a.type = 3;
    p->a.hablar = pollo_hablar;
    p->a.comer = NULL;
    p->n_eggs = n_eggs;
}

void say_something(Animal* a)
{
    a->hablar();
    if (a->type==3)
    {
        Oviparo* ov = (Oviparo*) a;
        printf("%d\n", ov->n_eggs);
    }
}

int main(int argc, char const *argv[])
{
    Animal perro;
    Animal gato;

    new_perro(&perro, 15);
    new_gato(&gato, 1);

    perro.comer();
    perro.hablar();
    gato.hablar();
    gato.comer();

    ///simular herencia en c
    Oviparo pollo;
    new_pollo(&pollo, 1, 200);

    say_something((Animal*)&pollo);
    return 0;
}