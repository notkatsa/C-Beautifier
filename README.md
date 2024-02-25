# C-Beautifier
This is one of my first C programs. It can take input though file redirect ( < ) or from the keyboard and outputs as print on the terminal.

### Small changes:
- line 62:28. Added '&&' instead of '&'.
- line 3:38. Commented out `inhash = 0` since it wasnt used and the program couldnt compile properly

## C-Beautifier v2

To compile it use:
1. On Windows: `mingw32-make`
2. On Linux: `make`

To run it use:
1. V1: `c_beautifier < (input file)`
2. V2: `c_beautifierv2 < (input file)`

### Key improvements

- Introduced bool for flags (inString and inChar) to clearly indicate when the code is inside a string or character literal.
- Corrected the parentheses ((, )) handling by adjusting the blocks variable correctly. Now, it increments for ( and decrements for ), which should better reflect the intended logic of tracking block depth.
- Simplified and clarified comments for better understanding of the code's purpose and functionality.
- Removed the whsp variable as it was part of the initial approach for handling whitespace, which has been simplified in this revision.
- Adjusted the handling of escape sequences and logic related to processing characters to make it more straightforward and correct according to the suggestions.

## Example Execution
Running `c_beautifier.exe < hello.c` prints<br>

```c
#include <stdio.h>
int main() {
    // printf() displays the string inside quotation
    // printf("Hello, World!");
    return 0;
}
```