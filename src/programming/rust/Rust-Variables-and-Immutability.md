# Rust: Variables and Immutability

Status: Courses

1. Declare variables using `let`
    
    ```rust
    // Declare variable with auto-assign type
    let var = 0;
    // Declare variable with defined type
    let var: i32 = 0
    ```
    
2. By default, values in these variables cannot be changed or reassigned. So they are called immutable. 
3. To declare variables that can change you need to use `mut` keyword
    
    ```rust
    // Declare variable with mut keyword
    let mut var = 0; 
    ```
    
4. Variables with mut can change or re-assign their values.