## Static Function 
Function can also have the static storage class. A Static function is only visible inside that file. 
It is used to make the function private. 

For example: 

```c
int *abc (void); 
void main () {
    int *p; 
    p = abc();
}

int *abc(void)
{
    int i = 10; 
    return &i; /* This is returing an address to local variable whose life is ended.*/  
}
```