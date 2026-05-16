// Rust: Memory Management via Ownership and Borrowing
// Demonstrates: move semantics, clone, immutable/mutable borrows,
// stack vs heap (Box), and dynamic allocation (Vec)

fn main() {
    // --- Ownership ---
    let s1 = String::from("hello");
    let s2 = s1;   // s1 is MOVED, no longer valid
    // println!("{}", s1);   // compile error: value moved to s2
    println!("Ownership moved: s2 = {}", s2);

    // Clone for deep copy
    let s3 = String::from("world");
    let s4 = s3.clone();   // explicit deep copy — both valid
    println!("Cloned: s3 = {}, s4 = {}", s3, s4);

    // --- Borrowing (immutable reference) ---
    let s5 = String::from("borrowing demo");
    let len = calculate_length(&s5);   // borrow, s5 still owned here
    println!("\nBorrowing: '{}' has {} characters", s5, len);

    // --- Mutable borrowing ---
    let mut s6 = String::from("hello");
    append_world(&mut s6);
    println!("After mutable borrow: {}", s6);

    // --- Stack vs Heap ---
    let stack_val: i32 = 42;               // stored on stack
    let heap_val = Box::new(42);           // stored on heap, freed when Box drops
    println!("\nStack value: {}", stack_val);
    println!("Heap (Box) value: {}", heap_val);
    // heap_val is automatically freed here when it goes out of scope

    // --- Vec dynamic allocation ---
    let mut numbers: Vec<i32> = Vec::new();
    for i in 1..=5 {
        numbers.push(i);
    }
    let sum: i32 = numbers.iter().sum();
    println!("\nDynamic Vec: {:?}, sum = {}", numbers, sum);
    // numbers is freed here automatically — no manual free needed
}

fn calculate_length(s: &String) -> usize {
    s.len()
}

fn append_world(s: &mut String) {
    s.push_str(", world");
}
