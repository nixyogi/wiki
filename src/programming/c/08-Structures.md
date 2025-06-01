## Structures 
Structures can hold unsimilar data and can be used to create custom data types using regular data types.

Syntax: 
```c
struct employee {
    int id; 
    float salary;
    char name[10];
};

/* Usage */
struct employee e1; 
e1.id = 100; 
e1.salary = 71.22; 
strcpy(e1.name, "Name");

/* Array of structures */
struct employee list[100]; 

/* Init of structures */
struct employee e2 = {100, 71.2, "Harry"};
struct employee e3 = {0} /* Set all elements to zero */

/* Pointer to a structure */
struct employee *ptr; 
ptr = &e1; 

/* Access the struct using the pointer */
int idOfe1 = ptr->id; /* -> is used instead of . when there is a struct pointer*/

```

## Typedef 
This is used to create an alias for datatypes in C.

```c
typedef struct employee {
    int id; 
    float salary;
    char name[10];
} worker;
```