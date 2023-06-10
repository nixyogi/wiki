# Rust: Enums

Status: Courses

1. Typically used to model things that can be of different kinds. 
    
    ```rust
    // Simple Enum 
    enum Direction {
    	N, // These are called as variants 
    	E, // Variants are all posiblities of a Type.
    	S,
    	W
    }
    ```
    
2. Variants can be defined with or without data. Data can be any type in Rust, see example below 
    
    ```rust
    // Simple Enum 
    enum Direction {
    	N, // These are called as variants 
    	E, // Variants are all posiblities of a Type.
    	S,
    	W
    }
    // Enum with Data 
    enum PlayerAction {
    	// Variant with 2 data
    	Move {
    		direction: Direction,
    		speed: u8
    	},
    	// Variant without data 
    	Wait, 
    	// Variant with direction
    	Attack(Direction)
    }
    
    fn main() {
    	// Init the player action 
    	let player1_action = PlayerAction::Move {
    		direction: Direction::N,
    		speed: 189
    	}
    	// match 
    	match player1_action {
    		// Deconstruct direction and speed in this branch
    		PlayerAction::Move { direction, speed } => {
    		  println!("Player moved {:?} with speed {}.", direction, speed);
    		}, 
    		PlayerAction::Attack(direction) => {
    		  println!("Player Attacked {:?}", direction);
    		}, 
    		PlayerAction::Wait => println!("Player Waits"); 
    	}
    }
    ```