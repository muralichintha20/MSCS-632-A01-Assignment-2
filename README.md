# Programming Languages Analysis

Assignment repository for **MSCS-632-A01** - Programming Languages course.

## Repository Contents

### Part 1 — Syntax and Semantics

| File | Description |
|------|-------------|
| `listing1_python_buggy.py` | Python sum program with intentional `NameError` bug (`o` instead of `0`) |
| `listing1_python_fixed.py` | Python corrected version |
| `listing2_javascript_buggy.js` | JavaScript sum program with intentional `SyntaxError` bug (space in function name) |
| `listing2_javascript_fixed.js` | JavaScript corrected version |
| `listing3_cpp_buggy.cpp` | C++ sum program with 3 intentional compile errors (undeclared identifier + broken string literal) |
| `listing3_cpp_fixed.cpp` | C++ corrected version |
| `type_system_demo.py` | Python: dynamic typing, implicit type promotion, closures, and LEGB scope |
| `type_system_demo.js` | JavaScript: type coercion quirks, closures, and `var` vs `let` scoping |
| `type_system_demo.cpp` | C++: static typing, lambda closures with value capture, and block scope |

### Part 2 — Memory Management

| File | Description |
|------|-------------|
| `memory_management.rs` | Rust: ownership, borrowing, `Box` heap allocation, and `Vec` dynamic allocation |
| `memory_management.java` | Java: garbage collection, heap lifecycle, and runtime memory measurement |
| `memory_management.cpp` | C++: raw pointers, `delete`/`delete[]`, memory leak demo, dangling pointer prevention, `unique_ptr`, and `shared_ptr` |

## Tools Used

All programs were written and tested using [TutorialsPoint Coding Ground](https://www.tutorialspoint.com/codingground.htm).

| Language | Compiler / Runtime Version |
|----------|---------------------------|
| Python | 3.8.1 |
| JavaScript | Node.js v22.08.0 |
| C++ | GCC 9.2.0 |
| Rust | 1.40.0 |
| Java | OpenJDK 13.0.1 |
