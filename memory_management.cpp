// C++: Manual Memory Management
// Demonstrates: raw new/delete, delete[] for arrays,
// memory leak (intentional demo), dangling pointer prevention,
// unique_ptr (exclusive ownership), and shared_ptr (reference counting)

#include <iostream>
#include <memory>
using namespace std;

// Demonstrates raw new/delete
void rawPointerDemo() {
    cout << "--- Raw Pointer Demo ---" << endl;

    int* ptr = new int(42);          // allocate single int on heap
    cout << "Heap allocated: " << *ptr << endl;
    delete ptr;                       // manual free
    ptr = nullptr;                    // avoid dangling pointer
    cout << "Freed and nulled" << endl;

    // Array allocation requires delete[]
    int* arr = new int[5]{1, 2, 3, 4, 5};
    int sum = 0;
    for (int i = 0; i < 5; i++) sum += arr[i];
    cout << "Array sum: " << sum << endl;
    delete[] arr;   // MUST use delete[] for arrays, not delete
    cout << "Array freed" << endl;
}

// Demonstrates smart pointers (RAII - modern C++ best practice)
void smartPointerDemo() {
    cout << "\n--- Smart Pointer Demo ---" << endl;

    // unique_ptr: sole ownership, auto-freed when out of scope
    {
        unique_ptr<int> uptr = make_unique<int>(100);
        cout << "unique_ptr value: " << *uptr << endl;
    }   // uptr destructor runs here — heap memory freed automatically
    cout << "unique_ptr freed (left scope)" << endl;

    // shared_ptr: reference counted ownership
    shared_ptr<int> sptr1 = make_shared<int>(200);
    {
        shared_ptr<int> sptr2 = sptr1;   // ref count = 2
        cout << "shared_ptr count: " << sptr1.use_count() << endl;
    }   // sptr2 destroyed, ref count drops to 1
    cout << "After inner scope, count: " << sptr1.use_count() << endl;
    // sptr1 destroyed at end of function — memory freed when count reaches 0
}

// Memory leak example (intentional demo — do NOT do this in production)
void memoryLeakDemo() {
    cout << "\n--- Memory Leak Demo (intentional) ---" << endl;
    int* leaky = new int(999);
    cout << "Allocated: " << *leaky << endl;
    // forgot to delete leaky!
    // In a real program, this memory is lost until the process exits.
    // Fix: delete leaky;
    cout << "WARNING: Memory leak! 'leaky' never deleted." << endl;
}

// Dangling pointer prevention
void danglingPointerDemo() {
    cout << "\n--- Dangling Pointer Demo ---" << endl;
    int* ptr = new int(77);
    cout << "Before delete: " << *ptr << endl;
    delete ptr;
    ptr = nullptr;   // best practice: null the pointer after delete
    if (ptr == nullptr) {
        cout << "ptr is null - safe to check before use" << endl;
    }
}

int main() {
    rawPointerDemo();
    smartPointerDemo();
    memoryLeakDemo();
    danglingPointerDemo();
    return 0;
}
