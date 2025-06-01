## Enums
It is a datatype in C used to assign names to integer constants. This makes the code easier to read.

```c
enum State {
    Working = 1, 
    Failed = 0
}; 
```
Example program: 

```c
#include<stdio.h>
 
enum week {
    Mon, /* If not given any value then it will start from 0 and will increment by 1*/
    Tue, 
    Wed, 
    Thur, 
    Fri, 
    Sat, 
    Sun
};
 
int main()
{
    enum week day;
    day = Wed;
    printf("%d",day);
    return 0;
} 
```

Output: 
```sh
2 
```