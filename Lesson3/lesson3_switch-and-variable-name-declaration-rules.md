# Programming 1

## Lesson 3



## switch — Multiple-selection statement
The switch multiple-selection statement performs one of many different actions depending on the value of an expression.

### Syntax

```c
switch (expression) {
case constant1:
	// code block
	break;
case constant2:
	// code block
	break;
default:
	// code block
	break; // optional when default is last, but often included for clarity
}
```

### Details

- The keyword `switch` is followed by the controlling expression in parentheses. The switch compares this expression's value with each `case` label.
- Each `case` label must be a constant expression (for C: integer constant or `char` or `enum` value).
- When a matching `case` is found, execution begins at that `case` label and continues until a `break` statement or the end of the `switch` block.
- The `break` statement exits the `switch` immediately. Without `break`, execution falls through to subsequent cases.
- The `default` case runs if no `case` matches. It's common to place `default` last.
- Multiple statements may appear in a `case` without braces. If you declare variables inside a case, you should use a block (`{ ... }`).

### Example (grading counters)

This example shows how the `switch` compares a grade and increments a counter. If the user enters the letter `'C'`, the `case 'C'` branch executes and `cCount` is incremented.

```c
#include <stdio.h>

int main(void) {
	int aCount = 0, bCount = 0, cCount = 0, dCount = 0, fCount = 0;
	char grade = 'C'; // assume user entered 'C'

	switch (grade) {
	case 'A':
		++aCount;
		break;
	case 'B':
		++bCount;
		break;
	case 'C':
		++cCount;
		break;
	case 'D':
		++dCount;
		break;
	case 'F':
		++fCount;
		break;
	default:
		printf("Invalid grade: %c\n", grade);
		break;
	}

	printf("A:%d B:%d C:%d D:%d F:%d\n", aCount, bCount, cCount, dCount, fCount);
	return 0;
}
```

Output for `grade = 'C'`:

```
A:0 B:0 C:1 D:0 F:0
```
### Grouping cases and fall-through

You can group cases to run the same code for multiple values. When you intentionally want fall-through, omit `break` and document the intention with a comment.

```c
switch (grade) {
case 'A':
case 'B':
	// treat A and B as "excellent"
	++excellentCount;
	break;
case 'C':
	++cCount;
	break;
case 'D':
case 'F':
	// intentional fall-through: both are failing grades
	++failCount;
	break;
}
```

### Best practices and notes

- Always include a `default` case unless you have a deliberate reason not to; it helps catch unexpected values.
- Place `default` last for readability. The `break` after `default` is optional if it's the final clause, but including it can make future edits safer.
- Remember that in C the `switch` expression must be an integral type (such as `int`, `char`, or an `enum`). Strings are not valid directly.
- When declaring variables inside a `case`, wrap the statements in braces to avoid crossing initialization rules:

```c
switch (x) {
case 1: {
	int y = 5; // allowed inside its own block
	printf("y=%d\n", y);
	break;
}
case 2:
	// ...
	break;
}
```

### Summary

The `switch` statement provides a clear way to select among many alternatives. Use `break` to prevent unintended fall-through, include a `default` to handle unexpected input, and group cases when multiple labels should share the same action.

## Variable Name Declaration Rules

This section covers the rules for declaring identifiers (names) in C: what characters are allowed, how names must start, reserved words, and platform-specific considerations.

### Identifiers — the basics

- An identifier is the name you give to variables, functions, types, macros, and labels.
- Identifiers consist of letters (A–Z, a–z), digits (0–9), and the underscore character (`_`).
- Identifiers must not start with a digit — they must start with a letter or an underscore.
- Identifiers are case-sensitive: `count`, `Count`, and `COUNT` are different names.

Valid examples:

```c
int count;
double total_sum;
char _flag;
int value123;
```

Invalid examples (illegal identifier forms):

```c
int 2ndValue;   // invalid: starts with a digit
int total-sum;   // invalid: '-' is not allowed
int my var;      // invalid: spaces are not allowed
```

### Reserved words (keywords)

- C has reserved keywords that cannot be used as identifiers (for example: `int`, `return`, `if`, `else`, `switch`, `for`, `while`, `static`, `extern`, `const`, etc.).
- Trying to declare a variable with a keyword name will cause a compilation error.

Example (invalid):

```c
int for = 5; // error — `for` is a keyword
```

### Reserved identifiers and portability

- Names beginning with an underscore followed by an uppercase letter or another underscore (e.g., `__MyName` or `_X`) are reserved for the implementation (compiler and standard library). Avoid such names in portable code.
- Identifiers beginning with a single underscore followed by a lowercase letter (e.g., `_temp`) are allowed but can still clash with library internals; prefer not to use them for public identifiers.

### Naming conventions and best practices

- Prefer descriptive names that convey purpose: `index`, `total`, `studentCount`.
- Use a consistent style across the project (camelCase, snake_case, or PascalCase). In C, `snake_case` is common for variables and functions.
- Keep names reasonably short but meaningful; avoid one-letter names except for loop indices (e.g., `i`, `j`).
- For constants and macros, a common convention is uppercase with underscores: `MAX_SIZE`.

Example conventions:

```c
// functions and variables
int compute_sum(int a, int b);
int student_count;

// macros/constants
#define MAX_BUFFER 1024
const int MAX_USERS = 100;
```

### Common Naming Cases

Different naming conventions are used in different contexts. Here are the most common ones:

**1. snake_case** (lowercase with underscores)
- Most common in C for variables, functions, and file names.
- Easy to read and widely adopted in C standard libraries.
- Example: `total_sum`, `calculate_average`, `max_students`

```c
int total_students = 150;
double average_grade = 85.5;
int (*get_student_info)(int id); // function pointer
```

**2. camelCase** (mixed case, first word lowercase)
- Common in JavaScript, Java, and some C codebases.
- Each word after the first starts with a capital letter.
- Less common in C, but sometimes used for readability in larger identifiers.
- Example: `totalSum`, `studentCount`, `processUserData`

```c
// Less conventional in C, but valid:
int studentCount = 50;
double averageGrade = 88.0;
```

**3. PascalCase** (mixed case, all words capitalized)
- Common for type names (structs, enums, typedef names) and class-like constructs.
- Also used for constants in some projects.
- Example: `StudentRecord`, `GradeCalculator`, `LinkedList`

```c
typedef struct {
    int StudentId;
    char StudentName[50];
} StudentRecord;

typedef struct Node {
    int data;
    struct Node *next;
} LinkedListNode;
```

**4. SCREAMING_SNAKE_CASE** (all uppercase with underscores)
- Used exclusively for constants and macro names.
- Makes it clear at a glance that a value should not be modified.
- Example: `MAX_SIZE`, `MIN_VALUE`, `DEFAULT_PORT`

```c
#define MAX_BUFFER_SIZE 1024
#define MIN_AGE 18
const int DEFAULT_TIMEOUT = 5000;
const double PI = 3.14159;
```

**5. Hungarian notation** (type prefix before name)
- An older convention that prefixes the type information into the name.
- Less popular in modern C, but still seen in some codebases (especially Windows code).
- Example: `iCount` (int), `dTotal` (double), `szName` (string, zero-terminated)

```c
// Not recommended in modern C, but sometimes seen:
int iCount = 10;
double dPrice = 29.99;
char szBuffer[256];
```

### Choosing a Naming Convention

- **In C projects**: Use `snake_case` for functions and variables, `SCREAMING_SNAKE_CASE` for constants and macros, and `PascalCase` for types (structs, typedefs, enums).
- **Consistency is key**: Pick a style and use it throughout your project. Mixed conventions harm readability.
- **Follow project standards**: If joining an existing project, adopt its naming style even if you prefer another.
- **Avoid abbreviations unless obvious**: Use `student_count` instead of `std_cnt`. Clarity trumps brevity.

### Special names to avoid

- Avoid names reserved by the standard library or ones used widely by third-party libraries.
- Avoid leading double underscores and names beginning with an underscore followed by an uppercase letter.

### Short checklist for choosing identifiers

1. Does the name start with a letter or underscore? (Yes)
2. Does the name avoid keywords? (Yes)
3. Is the name free of illegal characters (spaces, punctuation)? (Yes)
4. Is the name not reserved by the implementation (avoid `__` or `_Upper`)? (Yes)
5. Is the name clear and consistent with project conventions? (Yes)

### Quick examples

```c
int main_counter = 0;    // good
int _internal_flag = 0;  // ok for private/internal use
int __lib_helper = 0;    // avoid: reserved for implementation
int 3d_index = 0;        // invalid: starts with digit
```

### Summary

Identifiers (names) are fundamental to readable and maintainable code. Follow the language rules (allowed characters and starting character), avoid keywords and reserved implementation names, and use clear, consistent naming conventions.