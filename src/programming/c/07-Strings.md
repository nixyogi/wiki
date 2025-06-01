## Strings
-   String is 1D char array terminated with `\0` (NULL character).
-   NULL character denotes the termination of the string in continious memory.
-   Init of string can be as follows
    ```c
    char s1[] = "Hello"; /* This is a string constant */
    char s2[10] = "Hello"; /* This auto adds the \0 */
    char s3[] = { 'H', 'E', 'L', 'L', 'O', '\0'};
    ```
-   Once the string is defined as `s1[]` it cannot be re-initialized. 
-   To re-initialize the string use `char *ptr`.
-   String in memory is stored just like an array.
-   Printing string can be done using 
    ```c
    printf("%s\n", s1);
    ```
-   `gets()` used to get a multi-word string from user/file.
-   `puts()` used to output a multi-word string.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char s1[] = "Hello"; 
    char s2[10] = "Hello"; /* This auto adds the \0 */
    char s3[] = { 'H', 'E', 'L', 'L', 'O', '\n','W', '\0'};
    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3); 
    
    s1[0] = 'W'; /* This works */
    s2[0] = 'W'; /* This works */
    s3[0] = 'W'; /* This works */

    puts(s1);
    puts(s2);
    puts(s3);
    
    char *ptr = "Hello World"; /* This creates a pointer to constant string, so changing the value of string does not work*/
    printf("%s\n", ptr);

    ptr[0] = 'W'; /* This does not work*/ 
    printf("%s\n", ptr);

    return 0;
}
```

## String Library functions 

-   `strlen(string)` - Gets the length of the string. 
-   `strcpy(Destination, Source)` - Copy content of Source to destination.
-   `strcat(Destination, Source)` - Add source to the end of destination
-   `strcmp(string1, string2)` - Compare string 1 and string 2, returns 0 if matching. 