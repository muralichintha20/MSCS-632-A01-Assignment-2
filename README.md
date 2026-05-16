# Programming Languages Analysis

Assignment repository for the Programming Languages course.

## Repository Structure

```
├── part1_section1/         # Section 1: Syntax Error Analysis
│   ├── listing1_python_buggy.py        # Python with intentional NameError bug
│   ├── listing1_python_fixed.py        # Python corrected version
│   ├── listing2_javascript_buggy.js    # JavaScript with intentional SyntaxError bug
│   ├── listing2_javascript_fixed.js    # JavaScript corrected version
│   ├── listing3_cpp_buggy.cpp          # C++ with 3 intentional compile errors
│   └── listing3_cpp_fixed.cpp          # C++ corrected version
│
├── part1_section2/         # Section 2: Type Systems, Scopes, and Closures
│   ├── type_system_demo.py             # Python: dynamic typing, closures, LEGB scope
│   ├── type_system_demo.js             # JavaScript: coercion, closures, var vs let
│   └── type_system_demo.cpp            # C++: static typing, lambdas, block scope
│
└── part2_section3/         # Section 3: Memory Management
    ├── memory_management.rs            # Rust: ownership, borrowing, Box, Vec
    ├── memory_management.java          # Java: garbage collection, heap lifecycle
    └── memory_management.cpp          # C++: raw pointers, smart pointers, RAII
```

## How to Run

### Python
```bash
python listing1_python_buggy.py
python listing1_python_fixed.py
python type_system_demo.py
```

### JavaScript (Node.js)
```bash
node listing2_javascript_fixed.js
node type_system_demo.js
```

### C++
```bash
g++ listing3_cpp_fixed.cpp -o listing3 && ./listing3
g++ type_system_demo.cpp -o type_demo && ./type_demo
g++ memory_management.cpp -o mem_demo && ./mem_demo
```

### Rust
```bash
rustc memory_management.rs -o mem_rust && ./mem_rust
```

### Java
```bash
# Rename memory_management.java to Main.java first, then:
javac Main.java && java Main
```

## Languages and Tools Used

| Language | Version Used (online) |
|----------|-----------------------|
| Python   | 3.8.1                 |
| JavaScript | Node.js v22.08.0    |
| C++      | GCC 9.2.0             |
| Rust     | 1.40.0                |
| Java     | OpenJDK 13.0.1        |

All programs were written and tested using [TutorialsPoint Coding Ground](https://www.tutorialspoint.com/codingground.htm).
