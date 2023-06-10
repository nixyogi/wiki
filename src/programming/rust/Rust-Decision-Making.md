# Rust: Decision Making

Status: Courses
Tags: Rust

## if-else construct

1. `if-else` in Rust is not a statement but an expression.
    1. Statements do not return any value
    2. Expressions return value. 
2. Hence `if else` in Rust return value which can be ignored or assigned to a variable 
3. **Both `if` and `else` branches should return the same type of value. Because Rust does not allow multiple types to be stored in a variable.**
4. For example:
    
    ```rust
    // Simple example 
    if i < 10 {
       // the statement with semicolon hence the return value is ()
    	println!("Value is less than 10");
    } else {
       println!("Value is more than 10");
    }
    
    // complex example
    let result = if i < 10 {
       // the statement without semicolon is considered as return value
       1
    } else {
       // 0 is returned, and type is kept same
       0
    }
    ```
    
    ## match expression
    
    1. `match` in Rust is a replacement to `switch` and `case` in C. 
    2. For Example:
        
        ```rust
        // Simple match usage
        
        // Returns an HTTP status
        fn req_status() -> u32 {
        	200
        }
        
        fn main() {
        	let status = req_status();
        	let result = match status {
        		200 => {
        			println!("HTTP Success!");	
        		},
        		404 => println!("Page not found!"),
            other => println!("Reequest Failed, Status code {}!", other);
        	}
        }
        ```
        
    3. `match` statement has to have branches for all the possible cases **(match exhaustively)**. i.e in the Above case, we have to match against all the numbers until a maximum of u32. 
    4. `other` is used to catch all and store the value. 
    5. `_` is used to catch all and ignore the value.
    6. `match` is an expression so it returns a value.
    7. Each branch in `match` should return the same **type** of value because Rust does not allow one variable to store multiple types.