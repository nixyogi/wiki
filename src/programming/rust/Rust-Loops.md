# Rust: Loops

Status: Courses
Tags: Rust

1. Repeating things in Rust can be done using 3 contructs 
    1. loop
    2. while
    3. for

## loop construct

1. `loop` is Infinite loop
    
    ```rust
    let mut x = 1024;
    loop {
    	if x < 0 {
    	  // Break statement to get out of the loop
        // can also use continue in the loop
    		break; 
    	}
    	println!("{} more runs to go", x);
      // Decrement the runs
    	x -= 1; 
    }
    ```
    
2. loop construct can be tagged 
    
    ```rust
    'increment: loop {
    	'decrement: loop {
    	// tags can be used to break out of loops like this 
    		break 'increment; // This will break out of increment loop.  
    	}
    }
    ```
    

## while construct

```rust
// Nothing fancy, simple while loop
let x = 1000;
while x > 0 {
	println!("{} more runs to go", x);
	x -= 1
}
```

## for construct

```rust
// Simple for loop, to print 0 to 9
for i in 0..10 {
	println!("{}", i);
}

// Simple for loop to print 0 to 10
for i in 0..=10 {
	println!("{}", i)
}
```