## Memory Layout

```txt 
High Address -->    | CLI args and env variables | 
                    |----------------------------|
                    |   Stack |                  |
                    |         v                  |
                    |                            |
                    |                ^           |
                    |    Heap        |           |
                    |----------------------------|
                    |  Uninitialized Data (BSS)  |
                    |----------------------------|
                    |  Initialized Data          |
                    |----------------------------|
                    |  Text/Code Segment         |
Low Address    -->  |____________________________|
``` 

-   **Text segment** : Contains code and executable instructions, single copy and read-only.
-   **Initialized Data segment**: Initialized static and global varaibles are kept here. read-write area. 
-   **Uninitialized Data segment**: BSS (block started by symbol) contains all the unitinitalized global and external variables. They are set to zero by default.
-   **Stack** : Local variables, Function args and all variables that have a defined size are kept in stack. 
-   **Heap**: Dynamically allocated variables are located here. 

