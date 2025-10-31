# Programming 1

## Lesson 5

### Infinite Loops

An **infinite loop** is a loop that never terminates on its own. It continues executing until the program is stopped or a `break` statement is encountered.

**Use cases:**
- Programs that run continuously (servers, game loops)
- Input validation until valid data is received
- Menu-driven applications

---

## Common Ways to Create Infinite Loops

### 1. Using `while(1)`

The most common method.

```c
#include <stdio.h>

int main(void) {
    int count = 0;
    
    while (1) {  // infinite loop
        printf("Count: %d\n", count);
        count++;
        
        if (count >= 5) {
            break;  // exit the loop
        }
    }
    
    printf("Loop ended.\n");
    return 0;
}
```

---

### 2. Using `for(;;)`

An empty `for` loop creates an infinite loop.

```c
#include <stdio.h>

int main(void) {
    int num = 1;
    
    for (;;) {  // infinite loop
        printf("%d ", num);
        num++;
        
        if (num > 10) {
            break;
        }
    }
    
    printf("\nDone!\n");
    return 0;
}
```

---

### 3. Using `do-while` Loop

```c
#include <stdio.h>

int main(void) {
    int choice;
    
    do {
        printf("\n=== Menu ===\n");
        printf("1. Option A\n");
        printf("2. Option B\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("You selected Option A\n");
        } else if (choice == 2) {
            printf("You selected Option B\n");
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
        
    } while (1);  // infinite loop until break
    
    return 0;
}
```

---

## Breaking Out of Infinite Loops

### Using `break` Statement

```c
#include <stdio.h>

int main(void) {
    int counter = 0;
    
    while (1) {
        printf("Running... %d\n", counter);
        counter++;
        
        if (counter == 3) {
            printf("Breaking out!\n");
            break;  // exits the loop
        }
    }
    
    return 0;
}
```

### Using `return` Statement

```c
#include <stdio.h>

int main(void) {
    int value;
    
    while (1) {
        printf("Enter a number (0 to quit): ");
        scanf("%d", &value);
        
        if (value == 0) {
            printf("Goodbye!\n");
            return 0;  // exits the program
        }
        
        printf("You entered: %d\n", value);
    }
}
```

---

## Practical Examples

### Example 1: Input Validation

```c
#include <stdio.h>

int main(void) {
    int age;
    
    while (1) {
        printf("Enter your age (1-120): ");
        scanf("%d", &age);
        
        if (age >= 1 && age <= 120) {
            printf("Valid age: %d\n", age);
            break;
        } else {
            printf("Invalid! Try again.\n");
        }
    }
    
    return 0;
}
```

### Example 2: Simple Calculator

```c
#include <stdio.h>

int main(void) {
    char operator;
    double num1, num2, result;
    
    while (1) {
        printf("\nCalculator: (+, -, *, /) or 'q' to quit: ");
        scanf(" %c", &operator);
        
        if (operator == 'q') {
            printf("Exiting...\n");
            break;
        }
        
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);
        
        switch (operator) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': 
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    printf("Error: Division by zero!\n");
                    continue;
                }
                break;
            default:
                printf("Invalid operator!\n");
                continue;
        }
        printf("Result: %.2lf\n", result);
    }
    
    return 0;
}
```

---

## Important Notes

⚠️ **Warning:**
- Always include an exit condition (`break` or `return`)
- Accidental infinite loops can freeze your program
- Use **Ctrl+C** to stop a runaway program

💡 **Best Practices:**
- Use `while(1)` or `for(;;)` for clarity
- Comment your infinite loops
- Test exit conditions thoroughly

---

## Summary

| Loop Type | Syntax | Use Case |
|-----------|--------|----------|
| `while(1)` | `while (1) { ... }` | Most common and clear |
| `for(;;)` | `for (;;) { ... }` | Traditional C style |
| `do-while` | `do { ... } while (1);` | Body executes at least once |

**Key Takeaway:** Infinite loops are useful when controlled with proper exit conditions!

