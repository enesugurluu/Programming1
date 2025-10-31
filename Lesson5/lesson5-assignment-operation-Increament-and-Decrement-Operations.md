# Programming 1

## Lesson 5

### Assignment Operation - Increment And Decrement Operations

#### Overview
C provides several **assignment operators** for abbreviating assignment expressions. These operators combine an operation with assignment, making code more concise and readable. This lesson also covers the unary increment (`++`) and decrement (`--`) operators and how their prefix and postfix forms behave.

#### Basic Assignment Operator
- **`=`** : Simple assignment operator
  - Example: `c = 5;` (assigns 5 to variable c)

#### Arithmetic Assignment Operators

| Operator | Description | Example | Equivalent To |
|----------|-------------|---------|---------------|
| `+=` | Addition assignment | `c += 3;` | `c = c + 3;` |
| `-=` | Subtraction assignment | `c -= 3;` | `c = c - 3;` |
| `*=` | Multiplication assignment | `c *= 3;` | `c = c * 3;` |
| `/=` | Division assignment | `c /= 3;` | `c = c / 3;` |
| `%=` | Modulus assignment | `c %= 3;` | `c = c % 3;` |

#### Bitwise Assignment Operators

| Operator | Description | Example |
|----------|-------------|---------|
| `&=` | Bitwise AND assignment | `c &= 3;` |
| `\|=` | Bitwise OR assignment | `c \|= 3;` |
| `^=` | Bitwise XOR assignment | `c ^= 3;` |
| `<<=` | Left shift assignment | `c <<= 2;` |
| `>>=` | Right shift assignment | `c >>= 2;` |

---

### Detailed Examples (Assignment)

#### Example 1: Addition Assignment (`+=`)
```c
#include <stdio.h>

int main() {
    int c = 10;
    
    // Traditional approach
    // c = c + 3;
    
    // Using += operator
    c += 3;  // c is now 13
    
    printf("c = %d\n", c);  // Output: c = 13
    return 0;
}
```

#### Example 2: Multiple Assignment Operations
```c
#include <stdio.h>

int main() {
    int x = 20;
    
    x += 5;   // x = 20 + 5 = 25
    printf("After += 5: x = %d\n", x);
    
    x -= 3;   // x = 25 - 3 = 22
    printf("After -= 3: x = %d\n", x);
    
    x *= 2;   // x = 22 * 2 = 44
    printf("After *= 2: x = %d\n", x);
    
    x /= 4;   // x = 44 / 4 = 11
    printf("After /= 4: x = %d\n", x);
    
    x %= 5;   // x = 11 % 5 = 1
    printf("After %%= 5: x = %d\n", x);
    
    return 0;
}
```

#### Example 3: Practical Counter Example
```c
#include <stdio.h>

int main() {
    int count = 0;
    
    // Simulating a counter
    count += 1;  // Increment by 1
    printf("Count: %d\n", count);
    
    count += 1;
    printf("Count: %d\n", count);
    
    count += 5;  // Add multiple
    printf("Count: %d\n", count);
    
    return 0;
}
```

---

### Key Information

1. **How += Works**
   - The `+=` operator adds the value of the expression on the operator's right to the value of the variable on the operator's left
   - The result is stored back in the variable on the left
   - Example: `c += 3` means "add 3 to c and store the result in c"

2. **Order of Operations**
   - Assignment operators are evaluated right-to-left
   - They have lower precedence than arithmetic operators
   - Example: `a = b + c` performs addition first, then assignment

3. **All Compound Operators Follow Same Pattern**
   - `var op= expression` is equivalent to `var = var op expression`
   - This applies to all compound assignment operators

---

### Tips & Best Practices

✅ **DO:**
- Use assignment operators to make code more concise
- Use `+=` and `-=` frequently in loops and counters
- Prefer `+=` over `=` when modifying a variable
- Example: `i += 1;` is cleaner than `i = i + 1;`

❌ **DON'T:**
- Chain assignment operators excessively in a single line (reduces readability)
- Use assignment operators with complex expressions that might be unclear
- Example: `x += y * z + w;` may be confusing; consider breaking it down

⚠️ **Watch Out For:**
- Integer overflow when using `+=` with large numbers
- Division by zero when using `/=`
- Data type mismatches (ensure both sides are compatible)
- Example: `int x = 5; x += 2.5;` may cause unexpected results due to type casting

---

### Common Mistakes to Avoid (Assignment)

| Mistake | Wrong | Correct |
|---------|-------|---------|
| Forgetting the operator | `c + 3;` | `c += 3;` |
| Wrong spacing | `c+ =3;` | `c += 3;` |
| Chained assignment readability | `a=b=c=5;` | Prefer `c=5; b=c; a=b;` for beginners |
| Using with incompatible types | `char ch += 1000;` | Ensure proper type casting |

---

## Increment and Decrement Operators

The unary increment operator `++` and the unary decrement operator `--` add one to, and subtract one from, a variable respectively.

- To increment `c` by 1, you can use `++c` or `c++` rather than `c = c + 1` or `c += 1`.
- If you place `++` or `--` before a variable (prefixed), they’re called the **preincrement** or **predecrement** operators.
- If you place `++` or `--` after a variable (postfixed), they’re called the **postincrement** or **postdecrement** operators.
- By convention, unary operators should be placed next to their operands with **no intervening spaces** (write `++a`, not `++ a`).

### Prefix vs Postfix behavior

| Operator | Sample expression | Explanation |
|----------|-------------------|-------------|
| `++` (prefix) | `++a` | Increment `a` by 1, then use the new value of `a` in the expression in which `a` resides. |
| `++` (postfix) | `a++` | Use the current value of `a` in the expression in which `a` resides, then increment `a` by 1. |
| `--` (prefix) | `--b` | Decrement `b` by 1, then use the new value of `b` in the expression in which `b` resides. |
| `--` (postfix) | `b--` | Use the current value of `b` in the expression in which `b` resides, then decrement `b` by 1. |

### Examples: Seeing the Difference

#### Example A: Prefix increment
```c
#include <stdio.h>

int main(void) {
    int a = 5;
    int x = ++a; // a becomes 6, then x gets 6
    printf("a=%d, x=%d\n", a, x); // a=6, x=6
    return 0;
}
```

#### Example B: Postfix increment
```c
#include <stdio.h>

int main(void) {
    int a = 5;
    int x = a++; // x gets 5, then a becomes 6
    printf("a=%d, x=%d\n", a, x); // a=6, x=5
    return 0;
}
```

#### Example C: Mixed in expressions
```c
#include <stdio.h>

int main(void) {
    int a = 3, b = 3;
    printf("%d\n", ++a); // prints 4 (a becomes 4, then printed)
    printf("%d\n", b++); // prints 3 (b printed, then becomes 4)
    return 0;
}
```

#### Example D: Loop usage
```c
for (int i = 0; i < 3; i++) {
    // i++ increments after each iteration
}
```

### Tips & Pitfalls (++, --)

- Prefer simple, clear uses like `i++` in loops.
- Avoid using `++`/`--` on the same variable more than once in a single expression; it can be confusing and in C can lead to undefined behavior. Example to avoid: `i = i++ + ++i;`
- Only apply `++`/`--` to modifiable lvalues (variables). Expressions like `(a + 1)++` are invalid.
- They work with arithmetic types; be careful with signed overflow. Do not use them on values that might exceed type limits.
- Keep them next to their operands without spaces: `--x`, `x++`.

---