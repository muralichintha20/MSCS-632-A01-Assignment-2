// JavaScript: Calculate the sum of an array
// BUG: space in function call name on line 11 — "calculate Sum" instead of "calculateSum"
// Error produced: SyntaxError: Unexpected identifier

function calculateSum(arr) {
    let total = 0;
    for (let num of arr) {
        total += num;
    }
    return total;
}

let numbers = [1, 2, 3, 4, 5];
let result = calculate Sum(numbers);   // BUG: space in function name
console.log("Sum in JavaScript:", result);
