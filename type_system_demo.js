// JavaScript: Type System and Closures Demo
// Demonstrates: dynamic typing, type coercion quirks,
// closures via returned objects, and var vs let scoping

// Dynamic typing
let x = 42;
console.log(`x is ${typeof x}: ${x}`);
x = "now a string";
console.log(`x is ${typeof x}: ${x}`);

// Type coercion quirks (JavaScript-specific)
console.log("\nType coercion:");
console.log(`"5" + 3 = ${"5" + 3}`);        // "53" - string concat
console.log(`"5" - 3 = ${"5" - 3}`);        // 2   - numeric subtraction
console.log(`true + 1 = ${true + 1}`);      // 2
console.log(`null + 1 = ${null + 1}`);      // 1

// Closure example
function makeCounter(start) {
    let count = start;
    return {
        increment: () => ++count,
        decrement: () => --count,
        value: () => count
    };
}

const counter = makeCounter(10);
counter.increment();
counter.increment();
counter.decrement();
console.log(`\nCounter value: ${counter.value()}`);  // 11

// var vs let scoping
console.log("\nScope demo (var vs let):");
for (var i = 0; i < 3; i++) {}
console.log(`var i after loop: ${i}`);   // 3 - leaks out of block

for (let j = 0; j < 3; j++) {}
try {
    console.log(j);   // ReferenceError
} catch(e) {
    console.log(`let j after loop: ReferenceError (block scoped)`);
}
