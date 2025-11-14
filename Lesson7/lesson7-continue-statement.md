# Programming 1

## Lesson 7

### continue statement

The `continue` statement, when executed inside a `while`, `do...while`, or `for` loop, skips the remaining statements in the current loop iteration and proceeds to the next iteration of the loop.

- In `while` and `do...while` statements the loop-continuation test is evaluated immediately after the `continue` executes.
- In a `for` statement, the update (increment) expression executes first, then the loop-continuation test is evaluated.

### How `continue` works

The behavior of `continue` can be illustrated with the following patterns:

While loop pattern:

```c
while (testExpression) {
	// some code
	if (someCondition) {
		continue; // skip remaining code in this iteration
	}
	// more code that is skipped when continue runs
}
```

Do...while pattern:

```c
do {
	// some code
	if (someCondition) {
		continue; // control jumps to the while(testExpression) check
	}
	// more code
} while (testExpression);
```

For loop pattern:

```c
for (init; testExpression; update) {
	// some code
	if (someCondition) {
		continue; // runs update expression, then evaluates testExpression
	}
	// more code
}
```

### Example: `continue` in a `for` loop (fig04_08.c)

This example skips printing the value `5` and continues with the next iteration.

```c
#include <stdio.h>

int main(void) {
	// loop 10 times
	for (int x = 1; x <= 10; ++x) {
		// if x is 5, skip remaining code in this iteration
		if (x == 5) {
			continue; // skip printing 5
		}
		printf("%d ", x);
	}

	puts("\nUsed continue to skip printing the value 5");
	return 0;
}
```

Expected output:

```
1 2 3 4 6 7 8 9 10
Used continue to skip printing the value 5
```

### Example: `continue` in a `while` loop

In this example, when `i == 3` we increment `i` and `continue` so the value `3` is never printed.

```c
#include <stdio.h>

int main(void) {
	int i = 1;
	while (i <= 5) {
		if (i == 3) {
			i++;        // advance i so loop can progress
			continue;   // skip printing the value 3
		}

		printf("%d ", i);
		i++;
	}
	return 0;
}
```

Expected output:

```
1 2 4 5
```

### Notes

- Use `continue` when you want to skip only the remainder of the current iteration and keep looping.
- Be careful to ensure loop variables are updated appropriately before a `continue` in `while`/`do...while` loops to avoid infinite loops.

### References

- Diagram and examples adapted from classroom slides (fig. 4.8 style examples).

