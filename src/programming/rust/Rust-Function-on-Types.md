# Rust: Function on Types (impl)

Status: Courses

1. Types like `struct` and `enums` can have functions & methods attached to them using `impl`.
    
    ```rust
    // define struct 
    struct Player {
    	name: String,
    	iq: u8,
    	friends: u8,
    	score: u16
    }
    // define impl 
    impl Player {
    	// Initialize with Name
    	fn with_name(name: &str) -> Player {
    		Player {
    			name: name.to_string(),
    			iq: 100, 
    			friends: 100,
    			score: 100
    		}
    	}
      // Get friends field
    	fn get_friends(&self) -> u8 {
    		self.friends
    	}
    }
    
    fn main() {
    	// Init with name
    	let player1 = Player::with_name("Joe");
    	// Get the friends field
    	let player1_friends = player1.get_friends();
    	// Get the friends field another way. 
    	let player1_friend2 = Player::get_friends(&player);
    }
    ```
    
2. In `impl` block, there can be 2 types of functions 
    1. With `self` type as the first parameter - **Instance Methods**
        1. The **Instance Method can only be called on the existing variable of type.** For ex: ****the ****`get_friends` function in the above code.
        2.  **Instance Methods** also have 3 variants 
            1. `self` as the first parameter - Calling this method will consume the type, you cannot use the type anymore.
            2. `&self` as the first parameter - Provides read-only access to `self`
            3. `&mut self` as the first parameter - Provides mutable access to `self`
    2. Without `self` type as the first parameter - **Associated Methods**
        1. **Associated Methods don't require existing variables of the type.**  For ex: ****the ****`with_name` function in the above code.