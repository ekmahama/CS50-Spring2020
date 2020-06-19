#include <stdio.h>
#include <cs50.h>

struct Person
{
    string name;
    string number;
};

typedef struct
{
    int winner;
    int loser;
} pair;

int
main(int argc, char const *argv[])
{
    struct Person person1;
    person1.name = "Eddy";
    person1.number = "12345";

    printf("%s\n",person1.number);
    printf("%s\n",person1.name);
    return 0;
}
