# Programming 1

## Lesson 7

The **`break`** statement, when executed in a `while`, `for`, `do...while` or `switch` statement, causes an **immediate exit** from that statement.

Program execution then continues with the next statement after that `while`, `for`, `do...while` or `switch`.

---

### How the `break` statement works

#### In a `while` loop

```c
while (testExpression) {
    // codes
    if (condition_to_break) {
        break;   // exits the while loop immediately
    }
    // more codes
}
// execution continues here after break
```

#### In a `do...while` loop

```c
do {
    // codes
    if (condition_to_break) {
        break;   // exits the do...while loop immediately
    }
    // more codes
} while (testExpression);
// execution continues here after break
```

#### In a `for` loop

```c
for (init; testExpression; update) {
    // codes
    if (condition_to_break) {
        break;   // exits the for loop immediately
    }
    // more codes
}
// execution continues here after break
```

---

### Example: `break` in a `while` loop

The following example prints numbers from 1 upward, but stops when `i` becomes 3:

```c
#include <stdio.h>

int main(void)
{
    int i = 1;

    while (i <= 5) {
        printf("%d ", i);

        if (i == 3) {
            break;   // loop terminates when i is 3
        }

        i++;
    }

    return 0;
}
```

**Output:**

```text
1 2 3
```

---

### Notes about `break` in loops

- When the `if` statement detects that `x` has become `5`, `break` executes. This terminates the loop statement, and the program continues with the statement after the loop.
- When you declare the control variable in a `for` loop’s initialization expression, that variable no longer exists after the loop terminates.
- If you declare and initialize the loop variable **before** the loop (instead of in the `for` header), you can still use its final value after the loop terminates, because it remains in scope.
