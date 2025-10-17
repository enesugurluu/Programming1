# Programming 1

## Lesson 3 — While Loop in C

---

## What is a While Loop?

A **while loop** repeats a block of code as long as a condition is true.

**Syntax:**

```c
while (condition) {
    // code to repeat
}
```

---

## How It Works

1. Check if condition is true
2. If yes, execute the code block
3. Go back to step 1
4. If condition is false, exit loop

---

## Example 1: Count from 1 to 5

```c
#include <stdio.h>

int main(void) {
    int count = 1;

    while (count <= 5) {
        printf("Count: %d\n", count);
        count++;
    }

    return 0;
}
```

**Output:**
```
Count: 1
Count: 2
Count: 3
Count: 4
Count: 5
```

---

## Example 2: Sum User Input

```c
#include <stdio.h>

int main(void) {
    int number, sum = 0;

    printf("Enter numbers (0 to stop):\n");

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &number);

        if (number == 0) break;
        sum += number;
    }

    printf("Total: %d\n", sum);
    return 0;
}
```

---

## Example 3: Countdown

```c
#include <stdio.h>

int main(void) {
    int seconds = 5;

    while (seconds > 0) {
        printf("%d...\n", seconds);
        seconds--;
    }

    printf("Time's up!\n");
    return 0;
}
```

---

## Loop Control Statements

### `break` — Exit Loop

```c
int i = 1;
while (i <= 10) {
    if (i == 5) break;  // exit when i is 5
    printf("%d ", i);
    i++;
}
```
Output: `1 2 3 4`

### `continue` — Skip to Next Iteration

```c
int i = 1;
while (i <= 5) {
    if (i == 3) {
        i++;
        continue;  // skip 3
    }
    printf("%d ", i);
    i++;
}
```
Output: `1 2 4 5`

---

## Common Loop Patterns

**Pattern 1: Counting**
```c
int count = 0;
while (count < 10) {
    printf("%d\n", count);
    count++;
}
```

**Pattern 2: Flag-Based**
```c
int running = 1;
while (running) {
    printf("Continue? (0=no, 1=yes): ");
    scanf("%d", &running);
}
```

**Pattern 3: Input Validation**
```c
char response;
while (response != 'Q') {
    printf("Enter command (Q to quit): ");
    scanf(" %c", &response);
}
```

---

## Common Mistakes

| Mistake | Problem | Fix |
|---------|---------|-----|
| Forgot `count++` | Infinite loop | Add `count++` inside loop |
| Wrong condition | Loop never runs | Check initial value |
| `i < 5` instead of `i <= 5` | Off-by-one error | Use correct operator |
| Not initialized | Garbage value | Initialize: `int i = 0;` |

---

## Best Practices

1. **Initialize** the loop variable before the loop
2. **Update** the loop variable inside the loop
3. **Keep conditions simple** — easy to understand
4. **Use meaningful names** — `count` not `c`
5. **Test edge cases** — empty input, boundary values
6. **Avoid deeply nested loops** — hard to read

---

## While Loop vs. For Loop

| While Loop | For Loop |
|-----------|----------|
| Unknown iterations | Known iterations (counting) |
| `while (condition)` | `for (i=0; i<n; i++)` |
| Condition checked first | Compact syntax |

Both can do the same job — choose based on readability.

---

## Summary

- **while loop** repeats while condition is true
- Always **initialize** and **update** variables
- Use **`break`** to exit early
- Use **`continue`** to skip to next iteration
- **Avoid infinite loops** — ensure condition becomes false
- Keep code **clear and simple**

Master while loops and you'll write better C programs!

