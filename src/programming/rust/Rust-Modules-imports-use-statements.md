# Rust: Modules, imports, use statements

Status: Courses

1. Modules are used to split big code to multiple files
2. Key-points are 
    1. Each Rust program needs a root module.
        1. For executable, it is `main.rs`
        2. For a library, it is `lib.rs`
    2. Modules can be 
        1. Files
        2. Directories
        3. Declared inside a module.
    3. Declare module like below
        
        ```rust
        // In root module use mod keyword
        mod my_module;
        ```
        
    4. To use items within the module you need to use the `use` keyword
        
        ```rust
        use my_module;
        ```
        
    5. Items inside a module are Private by default. To make them public use `pub` keyword.