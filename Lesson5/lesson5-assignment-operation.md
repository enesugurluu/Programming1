# Programming 1

## Lesson 5

### Assignment Operation - Increment And Decrement Operations

#### Overview
C provides several **assignment operators** for abbreviating assignment expressions. These operators combine an operation with assignment, making code more concise and readable.

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

### Detailed Examples

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

### Common Mistakes to Avoid

| Mistake | Wrong | Correct |
|---------|-------|---------|
| Forgetting the operator | `c + 3;` | `c += 3;` |
| Wrong spacing | `c+ =3;` | `c += 3;` |
| Misunderstanding precedence | `c = d = 5;` | `c = d = 5;` (both get 5) |
| Using with incompatible types | `char ch += 1000;` | Ensure proper type casting | 1

## Lesson 5

### Assignment Operation

•
C provides several assignment operators for abbreviating assignment expressions. For example, the statement
c =c +3;
can be abbreviated with the addition assignment operator += as
c +=3;
•
The += operator adds the value of the expression on the operator’s right to the value of the variable on the operator’s left then stores the result in the variable on the left. So, the assignment c += 3 adds 3 to c’s current value.