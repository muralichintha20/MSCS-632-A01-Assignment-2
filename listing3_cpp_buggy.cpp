// C++: Calculate the sum of an array
// BUG 1 (line 6):  'o' (letter) instead of 0 — undeclared identifier
// BUG 2 (line 7):  'o' (letter) instead of 0 in loop initializer
// BUG 3 (line 17): broken string literal — missing closing double-quote
// Errors produced: 'o' was not declared in this scope, missing terminating " character

#include <iostream>
using namespace std;

int calculateSum(int arr[], int size) {
    int total = o;              // BUG 1: 'o' instead of 0
    for (int i = o; i < size; i++) {   // BUG 2: 'o' instead of 0
        total += arr[i];
    }
    return total;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int result = calculateSum(numbers, size);
    cout << "Sum in C++" " << result << endl;   // BUG 3: broken string literal
    return 0;
}
