
# Programming 1 — Lesson 4

## Type conversion in C (casting)

This lesson covers implicit (automatic) and explicit (manual) conversions between types in C, how to format floating-point output, and why you should avoid testing floating-point values for strict equality.

### Implicit conversion (automatic)

When an expression contains different data types, C will automatically convert one operand to the other type so the operation can proceed. This is called implicit conversion (or implicit casting).

Example (implicit conversion from `int` to `double`):

```c
/* implicit_casting.c */
#include <stdio.h>

int main(void) {
	int x = 5;
	double y = 2.0;
	double result;

	/* int x is implicitly converted to double */
	result = x + y;
	printf("Result = %.1f\n", result); /* Output: 7.0 */
	return 0;
}
```

### Explicit conversion (casting)

You can force a conversion using a cast operator. This is useful when you want to change how an operation is performed (for example, to avoid integer division).

```c
/* explicit_casting.c */
#include <stdio.h>

int main(void) {
	int total = 7;
	int count = 2;
	double average;

	/* cast total to double so division is floating-point */
	average = (double) total / count;
	printf("Average = %.2f\n", average); /* Output: 3.50 */
	return 0;
}
```

See also `cast_floating_point_to_integer.c` for an example that shows truncation when casting floating-point values to integers.

### Formatting floating-point numbers with printf

The `printf` family lets you control the number of digits after the decimal point using a precision specifier. The format `%.nf` prints a floating-point number with `n` digits after the decimal point. If no precision is specified (just `%f`), the default is 6 digits after the decimal point.

Important points:
- The precision affects only the printed representation, not the value stored in memory.
- Examples:
  - `%.2f` prints two digits after the decimal point (e.g., 3.45)
  - `%.1f` prints one digit after the decimal point (e.g., 3.4)
  - `%f` prints six digits by default (e.g., 3.446000)

Example:

```c
/* printf_precision.c */
#include <stdio.h>

int main(void) {
	double v = 3.446;
	printf("%%f (default)  : %f\n", v);
	printf("%%.2f         : %.2f\n", v);
	printf("%%.1f         : %.1f\n", v);
	return 0;
}
```

### Floating-point precision and equality

Floating-point values are only approximations in most computers. For example, a temperature shown as `98.6` may be stored as `98.599947...`. Many decimal fractions cannot be represented exactly in binary floating point. Because of this, you should avoid comparing floating-point values for exact equality.

Instead, compare the absolute difference against a small tolerance (`epsilon`). Example:

```c
/* equality_comparison.c */
#include <stdio.h>
#include <math.h>

int main(void) {
	double a = 0.1 * 3; /* may not be exactly 0.3 */
	double b = 0.3;
	double eps = 1e-9;

	if (fabs(a - b) < eps) {
		printf("Equal (within epsilon)\n");
	} else {
		printf("Not equal\n");
	}
	return 0;
}
```

Notes:
- Choose an appropriate `eps` based on the magnitudes involved.
- For integer-like comparisons (values that should be exact integers), prefer integer types where possible.

## Summary
- Implicit conversions happen automatically when operands have different types.
- Use explicit casts to control conversions and avoid unwanted integer division.
- Use `printf` precision specifiers to format output; this does not change the underlying value.
- Avoid direct equality checks on floating-point values; use an epsilon-based comparison instead.

Relevant example files referenced in this lesson: `implicit_casting.c`, `explicit_casting.c`, `cast_floating_point_to_integer.c`, `equality_comparison.c`.



Formatting Floating-Point Numbers
•
In C, the printf function allows you to control how many digits appear after the decimal point using the precision specifier.
•
The format %.nf prints a floating-point number with n digits after the decimal point.If no precision is specified (just %f), the default precision is 6 digits to the right of the decimal point.
•
The value in memory does not change — only the printed representation is rounded.
•
For example:
•
%.2f → prints two digits after the decimal point → rounded to 3.45
•
%.1f → prints one digit after the decimal point → rounded to 3.4
•
Without precision (%f), six digits are displayed by default → 3.446000


•
Floating-point numbers are not always precise.
•
For example, a temperature shown as 98.6°F may actually be 98.599947…
•
They often result from division.For example, dividing 10 by 3 produces 3.33333…, an infinite repeating value.
•
Computers store numbers using a fixed amount of space, so these values are only approximations.Assuming floating-point values are exact can lead to incorrect results.
•
Floating-point numbers are represented only approximately by most computers.For this reason, you should not compare floating-point values for equality.See example equality_comparison.c