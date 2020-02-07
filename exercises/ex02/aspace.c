/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    int var2 = 5;
    int var3 = 6;
    void *p = malloc(128);
    void *q = malloc(128);
    void *r = malloc(19);
    void *t = malloc(19);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of var3 is %p\n", &var3);
    printf ("p points to %p\n", p);
    printf ("r points to %p\n", r);
    printf ("t points to %p\n", t);
    printf ("s points to %p\n", s);

    return 0;
}

/*
1-3: see scan in repo, called "diagram"
 4. the stack doesn't appear to grow up, just
 changes some of the letters in the code rather than increasing
 the magnitude of the numbers

 5. the stack does appear to grow down based on outputs!

 6. the space between them is 20,
 which is one greater than the value that they contain
 */
