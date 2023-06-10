# Rust: Struct

Status: Courses

1. 3 forms of `struct`
    1. unit struct
    2. tuple struct 
    3. C-like struct

## unit struct

1. Zero sized struct.
2. Typically used to model errors or states with no data. 

```rust
struct Dummy; 

fn main() {
	// value is zero sized struct Dummy.
	let value = Dummy;
}
```

## tuple struct

1. Fields are not named but are referred by their positions 

```rust
// Tuple struct 
struct Color(u8,u8,u8)
fn main() {
	// Define while are 255,255,255
	let white = Color(255,255,255) 
  // Get the individual values using their positions 
	let white_r = white.0
	let white_g = white.1
  let white_b = white.2
	// You can deconstruct the RGB value of white by using the syntax below
	let Color(whiteR, whiteG, whiteB) = white;
  // You can ignore one field using _ 
  let Color(r, _, b) = white; // Green value is ignored
}
```

1. Fields have to be initialised in the order as defined. 
2. Typically used to model data that has 4-5 attributes 

## C-like structs

```rust
// C-like struct definition 
struct Player {
	name: String,
	iq: u8,
	friends: u8,
	score: u16
}

fn main() {
	let name = "Alice".to_string();
	// C-like struct declaration 
	let mut player1 = Player {
		name,
		iq: 90,
		friends: 0,
		score: 1129
	}
	// Changing values in C-like struct 
	player1.score = 1130
}
```

1. fields can be initialised in any order in C-like struct.