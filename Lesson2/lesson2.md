# Programming 1
## Lesson 2

### The `&` Operator

The `&` operator is used to obtain the memory address of a variable.

---

### Memory Concepts

Every variable has:
- a **name**
- a **type**
- a **value**
- a **location** in the computer’s memory

For example, the following program places the user’s input into `integer1`’s memory location:

```c
scanf("%d", &integer1);
```

When a value is placed in a memory location, it replaces the location’s previous value, which is lost. This process is said to be **destructive**.

For example, when the following statement is executed, the value in memory will be `23`:

```c
integer1 = 23;
```

The new value can be seen by running the following statement:

```c
printf("New value is %d\n", integer1);
```

---

### Rules of Operator Precedence

1. **Expressions grouped in parentheses** evaluate first (highest level of precedence).
	- Example: `(a + b) + c`
2. `*`, `/`, and `%` are applied next. These three operators are on the same level of precedence. If an expression contains several of these operators, evaluation proceeds **left-to-right**.
3. `+` and `-` are evaluated next. If an expression contains these operators, evaluation proceeds **left-to-right**. They have the same level of precedence, which is lower than that of `*`, `/`, and `%`.
4. The **assignment operator** (`=`) is evaluated last.

---

### Checking if a Number is Even or Odd in C

The following code demonstrates how to check if an integer is even or odd using the modulo operator in C:

```c
int number = 7;
if (number % 2 == 0) {
	printf("%d is even\n", number);
} else {
	printf("%d is odd\n", number);
}
```

This code initializes an integer variable `number` with the value 7, then checks if it is divisible by 2. If true, it prints that the number is even; otherwise, it prints that the number is odd.

---

## `if` Statements (Conditional Execution)

`if` statements allow your program to choose between different actions depending on a condition. A condition is an expression that evaluates to true (non-zero) or false (zero).

Basic syntax:

```c
if (condition) {
	/* statements executed when condition is true */
}
```

Simple example:

```c
int x = 5;
if (x > 0) {
	printf("%d is positive\n", x);
}
```

if-else example:

```c
int x = -3;
if (x >= 0) {
	printf("%d is non-negative\n", x);
} else {
	printf("%d is negative\n", x);
}
```

else-if ladder (multiple branches):

```c
int score = 76;
if (score >= 90) {
	printf("A\n");
} else if (score >= 80) {
	printf("B\n");
} else if (score >= 70) {
	printf("C\n");
} else {
	printf("D or below\n");
}
```

Nested `if` example:

```c
int a = 10, b = 20;
if (a > 0) {
	if (b > 0) {
		printf("Both a and b are positive\n");
	}
}
```

Using logical operators in conditions:

```c
int age = 25;
int hasLicense = 1; // 1 = true, 0 = false
if (age >= 18 && hasLicense) {
	printf("Allowed to drive\n");
}

int temperature = -5;
if (temperature < 0 || temperature > 35) {
	printf("Extreme temperature\n");
}
```

Notes and common pitfalls:
- Use comparison operators (`==`, `!=`, `<`, `>`, `<=`, `>=`) inside the condition.
- Use `=` for assignment and `==` for equality comparison—mixing them causes bugs.
- Braces `{}` are required for multi-statement blocks; for single statements they are optional but recommended for clarity.
- Conditions treat 0 as false and any non-zero value as true.

Short complete program example (compile and run):

```c
#include <stdio.h>

int main(void) {
	int n;
	printf("Enter an integer: ");
	if (scanf("%d", &n) != 1) return 1;

	if (n == 0) {
		printf("Zero\n");
	} else if (n % 2 == 0) {
		printf("%d is even\n", n);
	} else {
		printf("%d is odd\n", n);
	}
	return 0;
}
```

This program reads an integer and uses an `if` / `else if` / `else` chain to print whether the number is zero, even, or odd.