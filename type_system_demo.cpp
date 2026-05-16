// C++: Type System and Scope Demo
// Demonstrates: static typing with explicit cast,
// lambda closures with value capture, and lexical block scope

#include <iostream>
#include <functional>
#include <string>
using namespace std;

// Static typing: types enforced at compile time
void typeDemo() {
    int x = 42;
    double y = 3.14;
    // x = "hello";   // Would cause compile error: cannot assign string to int

    // Explicit casting required for mixed-type arithmetic
    double result = (double)x + y;
    cout << "int " << x << " + double " << y << " = " << result << " (double)" << endl;
}

// Closure via lambda with value capture
function<int(int)> makeMultiplier(int factor) {
    return [factor](int x) {   // capture 'factor' by value
        return x * factor;
    };
}

// Scope demonstration
int globalVar = 100;

void scopeDemo() {
    int localVar = 200;
    {
        int blockVar = 300;
        cout << "Inside block - global: " << globalVar
             << ", local: " << localVar
             << ", block: " << blockVar << endl;
    }
    // blockVar is not accessible here — compile error if referenced
    cout << "Outside block - global: " << globalVar
         << ", local: " << localVar << endl;
}

int main() {
    typeDemo();

    auto triple = makeMultiplier(3);
    cout << "\nLambda closure: triple(7) = " << triple(7) << endl;

    cout << "\n";
    scopeDemo();
    return 0;
}
