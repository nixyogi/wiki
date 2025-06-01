# Storage Classes 

-   While declaring the variable we can define a storage class.
-   This storage class defines the 4 important properties of a variable. 
    1.  Default value
    2.  Memory allocation
    3.  Scope
    4.  Life

-   There are 4 storage classes 
    1.  Auto
    2.  Register
    3.  Static 
    4.  Extern 

-   Static and Extern can be used in function declartion, But their meaning changes when used in function declaration. 

-   A variable can be declared in two places 
    1.  Inside a function or block (local)
    2.  Outside a function but inside a file (global)

#### Auto
-   Any local variable by default is `auto` storage class.
-   `auto` keyword cannot be used while defining global variables.

#### Static 
-   Uninitialized static varialbes are stored in BSS (Block started by symbols) or in unintialized data segments, whereas initialized static variables are stored in initialized data segments.
-   For static variable re-initialization will not happen. 

### Table 

Storage class | Place of declaration | Life | Scope | Initial Value | Place of storage | Linkage 
--- | --- | --- | --- | --- | --- | ---
auto | Inside a function or block | Function | Function/Block | Garbage Value | Memory (Stack frame) | None  
register | Inside a function or block | Function | Function/Block | Garbage Value | CPU Registers (if full then will store in stack) | None  
static (local) | Inside a function or block | Program | Function/Block | Zero | Memory (data segment) | None  
static (global) | Outside a function | Program | From declaration to end of file | Zero | Memory (data segment) | Internal
extern | Outside a function | Program | From declaration to end of file | Zero | Memory (data segment) | Internal