# Python: Type System and Closures Demo
# Demonstrates: dynamic typing, implicit type promotion,
# closures via nested functions, and global scope keyword

# Dynamic typing - variable type changes at runtime
x = 42
print(f"x is {type(x).__name__}: {x}")
x = "now a string"
print(f"x is {type(x).__name__}: {x}")
x = [1, 2, 3]
print(f"x is {type(x).__name__}: {x}")

# Implicit type coercion
a = 5
b = 2.0
result = a + b   # int + float = float automatically
print(f"\n{a} (int) + {b} (float) = {result} ({type(result).__name__})")

# Closure example
def make_multiplier(factor):
    def multiplier(x):
        return x * factor   # 'factor' is captured from outer scope
    return multiplier

double = make_multiplier(2)
triple = make_multiplier(3)
print(f"\nClosure demo:")
print(f"double(5) = {double(5)}")
print(f"triple(5) = {triple(5)}")

# Scope demonstration
counter = 0
def increment():
    global counter
    counter += 1

increment()
increment()
print(f"\nGlobal counter after 2 increments: {counter}")
