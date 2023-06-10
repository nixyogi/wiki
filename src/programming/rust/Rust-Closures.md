# Rust: Closures

Status: Courses

1. Closures are functions but with env and scope.
2. They do not have names assigned to them.
3. Closures use the syntax `| | { }`
    1. where `| |` holds the arguments being passed
    2. `{ }` holds the code
4. For Example 
    
    ```rust
    // Definition of the Closure
    let adder = |a, b| {
    	a + b;
    };
    // Usage of the closure 
    let five_plus_two = adder(5,2);
    ```