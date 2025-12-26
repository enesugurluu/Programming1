# Enumeration (enum) in C

An **enumeration** (short: **enum**) is a user-defined type that groups a set of **named integer constants**.

Enums help you:

- Replace “magic numbers” with meaningful names
- Make code easier to read and maintain
- Restrict a variable to a known set of values

> Reference (for extra reading): https://www.w3schools.com/c/c_enums.php

## 1) Basic enum syntax

Use the `enum` keyword, give the enum a name (type name), then list the constants separated by commas.

```c
enum Level {
	LOW,
	MEDIUM,
	HIGH
};
```

### Create a variable of an enum type

To use the enum, declare a variable of that enum type:

```c
enum Level myLevel;
```

### Assign a value

The value must be one of the enum items:

```c
enum Level myLevel = MEDIUM;
```

## 2) Default values (0, 1, 2, ...)

By default:

- The first enum constant is `0`
- The next is `1`
- And so on...

Example:

```c
#include <stdio.h>

enum Level { LOW, MEDIUM, HIGH };

int main(void) {
	enum Level myLevel = MEDIUM;
	printf("%d\n", myLevel);  // prints 1
	return 0;
}
```

## 3) Enumeration constants example: months

### Months numbered 0 to 11 (default)

```c
enum Months {
	JAN, FEB, MAR, APR, MAY, JUN,
	JUL, AUG, SEP, OCT, NOV, DEC
};
```

This produces:

- `JAN == 0`
- `FEB == 1`
- ...
- `DEC == 11`

### Months numbered 1 to 12 (custom start value)

If you explicitly set one value, the following items continue from there (+1):

```c
enum Months {
	JAN = 1, FEB, MAR, APR, MAY, JUN,
	JUL, AUG, SEP, OCT, NOV, DEC
};
```

This produces:

- `JAN == 1`
- `FEB == 2`
- ...
- `DEC == 12`

## 4) Changing enum values

You can assign specific numbers to make the enum “mean” something in your program.

```c
enum Level {
	LOW = 25,
	MEDIUM = 50,
	HIGH = 75
};
```

If only one constant is assigned, the rest follow automatically.

```c
enum Level {
	LOW = 5,
	MEDIUM,  // 6
	HIGH     // 7
};
```

## 5) Enum in a `switch` statement

Enums are commonly used with `switch` to select behavior based on a known set of values.

```c
#include <stdio.h>

enum Level { LOW = 1, MEDIUM, HIGH };

int main(void) {
	enum Level myLevel = MEDIUM;

	switch (myLevel) {
		case LOW:
			printf("Low level\n");
			break;
		case MEDIUM:
			printf("Medium level\n");
			break;
		case HIGH:
			printf("High level\n");
			break;
		default:
			printf("Unknown level\n");
			break;
	}

	return 0;
}
```

> Tip: Using `case LOW:` instead of `case 1:` makes your code clearer.

## 6) `typedef` with enums (shorter declarations)

Without `typedef`, you must write `enum` each time:

```c
enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };
enum Day today = WED;
```

With `typedef`, you can use the type name directly:

```c
typedef enum {
	MON, TUE, WED, THU, FRI, SAT, SUN
} Day;

int main(void) {
	Day today = WED;
	return 0;
}
```

## 7) Common mistakes / error tips

1. **Enum identifiers must be unique in the same scope**
   - You can’t reuse the same constant name in another enum if both are visible in the same scope.

2. **You can’t assign to an enum constant after it’s defined**
   - This is invalid:

   ```c
   enum Level { LOW, MEDIUM, HIGH };
   LOW = 10; // ❌ syntax error (LOW is a constant)
   ```

3. **Use uppercase names for enum constants (style recommendation)**
   - Example: `LOW`, `MEDIUM`, `HIGH` or `JAN`, `FEB`, ...
   - This helps you quickly spot constants in code.

## 8) Why and when to use enums

Use enums when the set of values is limited and known ahead of time, for example:

- Days of the week
- Months
- Menu options
- States in a program (e.g., `START`, `RUNNING`, `PAUSED`, `STOPPED`)
