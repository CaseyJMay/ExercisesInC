/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}
/*
the arrays that foo and bar return both try and point
at the same memory, which leads to plenty of confusion on
the side of the computer. While this is in place, the code
continuously "core dumps", or has a segmentation fault,
which is an error that triggers when the computer tries to
access memory it shouldn't.
*/

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

/*
Stack Allocated Data:
1. It appears that as is the code is meant to Initialize
an array of length 5, make all the values 42, and then
make a new array with the same name with values
equal to the index of the value.

2. The warning indicates that the function 'foo' returns the Address
of a local variable. This appears to mean the "return array"
line

3. There is a segmentation fault, the core has been dumped, so I get no return value,
but both print statements return the same value.

4. The warning and error both still come, so it's not just the print statement!
*/
