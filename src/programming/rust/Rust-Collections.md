# Rust: Collections

Status: Courses

1. Collections are types used to process multiple instances of data. 
2. Simple collections are 
    1. Array 
    2. Tuples
3. Dynamic collections are 
    1. vectors (list of items)
    2. maps (key/value items)
4. References to collections are slices. 

## arrays

```rust
// Array with 10 elements
let num: [u8, 10] = [1,2,3,4,5,6,7,8,9,10];

println!("5 element is {}", num[5]);
```

## tuples

```rust
// Construct a tuple
let num_and_str: (u8, &str) = (40, "Have a good day"); 
// Deconstruct a tuple 
let (num, str1) = num_and_str; // num contains 40 and str1 contains Have a good day
```

## vectors

```rust
// Vector init
let mut num_vec: Vec<u8> = Vec::new(); 
num_vec.push(1);
num_vec.push(2); // Push 

// Alternative way 
let mut num_vec2 = vec![1];
num_vec2.push(2); 
let _ = num_vec2.pop(); // Value is poped and ignored
```

## Hashmaps

1. Stores key-value data. 
    
    ```rust
    use std::collections::Hashmap;
    
    fn main() {
    	// Initialise map
    	let mut fruits = HashMap::new(); 
    	// Insert new value
    	fruits.insert("apple", 3);
    	// Iterate values 
    	for (key, value) in &fruits {
    		println!("Key: {}, Value: {}", key, value);
    	}
    	// Get the value of a key 
    	println!("Value of apple: {}", fruits["apple"]);
    	// Remove value
    	fruits.remove("apple");
    }
    ```