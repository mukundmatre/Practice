// C code to illustrate Internal Linkage

#include <stdio.h>
#include "animals.cpp"

int main()
{
    call_me();
    animals = 2;
    printf(" %d", animals);
    return 0;
}
