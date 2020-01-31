#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("%i", y);
    return 0;
}

/* pre5hello: initial file
hello.s: file after adding in the 5
optimizedhello: optimized file after 5 added
printxnot: x print not optimized
printxopt: x print optimized
printynot: y print not optimized
printyopt: y print optimized
*/

/*
1. it appears the line that corresponds is:
movl	$5, -4(%rbp)

2. it shortens it extensively and the movq and movl lines
dissappear entirely

3. it appears that adding x adds quite a few movl lines
and that optimizing merges them into a line titled "xorl"

4. again, all that I can tell is that optimization condenses
the amount of space information takes up by condensing inconcise
syntax in the storage of numbers.
*/
