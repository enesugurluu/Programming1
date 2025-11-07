# Programming 1 — Lesson 6

## do…while Iteration Statement

The do…while loop is similar to the while loop, but the loop-continuation test happens after the body executes, so the body always runs at least once.

- while: tests the condition before executing the loop body (the body may not run at all).
- do…while: tests the condition after executing the loop body (the body runs at least once).

---

## Syntax

```c
do {
	// action(s)
} while (condition);   // note the required semicolon
```

Key points:
- The semicolon after the condition is required.
- Use this loop when you must perform the action(s) once before checking the condition (e.g., menu prompts, input validation).

---

## Example: Print 1 through 5 (from fig04_06.c)

```c
// Using the do…while iteration statement.
#include <stdio.h>

int main(void) {
	int counter = 1;  // initialize counter

	do {
		printf("%d ", counter);
	} while (++counter <= 5);   // pre-increment in the test

	return 0;
}
```

Output:

```
1 2 3 4 5
```

Why pre-increment here? The loop prints the current value, then the test runs using ++counter (so the test sees the incremented value). An equivalent, often clearer alternative moves the increment inside the body:

```c
int counter = 1;
do {
	printf("%d ", counter);
	counter++;                 // post-increment in the body
} while (counter <= 5);
```

---

## Execution Flow (conceptual flowchart)

1) Execute action(s) in the loop body once.
2) Evaluate condition.
   - If true → repeat from step 1.
   - If false → exit the loop.

This matches the flowchart shown in class: action(s) first, then the decision diamond; true loops back, false exits.

---

## When to use do…while

- Menu-driven programs that should display at least once.
- Input validation that prompts the user, then checks validity.
- Tasks where one pass is required before testing a continuation condition.

---

## Common pitfalls

- Trailing semicolon placement:
  - Correct: `} while (condition);`
  - Buggy: `do; while (condition);` (empty body)
- Infinite loop risk: ensure the body changes something that can make the condition false.

---

## Mini exercise: positive number prompt

Write a program that keeps asking for a positive integer until the user enters one, then prints it.

```c
#include <stdio.h>

int main(void) {
	int n;
	do {
		printf("Enter a positive integer: ");
		scanf("%d", &n);
	} while (n <= 0);

	printf("You entered: %d\n", n);
	return 0;
}
```

---

## Summary

- do…while executes the body once before testing the condition.
- Prefer do…while when at-least-once execution is required.
- Don’t forget the semicolon after `while (condition)`.

