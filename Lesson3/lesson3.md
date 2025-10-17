#Programming1

##Lesson3



## switch — Multiple-selection statement
The switch multiple-selection statement performs one of many different actions depending on the value of an expression.

### Syntax

```c
case constant1:
	break;
	// code block
	break; // optional when default is last, but often included for clarity
}

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
	char grade = 'C'; // assume user entered 'C'
	switch (grade) {
	case 'A':
	printf("Invalid grade: %c\n", grade);
	printf("A:%d B:%d C:%d D:%d F:%d\n", aCount, bCount, cCount, dCount, fCount);
	return 0;
}

```

Output for `grade = 'C'`:

```
### Grouping cases and fall-through

You can group cases to run the same code for multiple values. When you intentionally want fall-through, omit `break` and document the intention with a comment.

```c
### Best practices and notes

- Always include a `default` case unless you have a deliberate reason not to; it helps catch unexpected values.
- Place `default` last for readability. The `break` after `default` is optional if it's the final clause, but including it can make future edits safer.
- Remember that in C the `switch` expression must be an integral type (such as `int`, `char`, or an `enum`). Strings are not valid directly.
- When declaring variables inside a `case`, wrap the statements in braces to avoid crossing initialization rules:

```c
### Summary

The `switch` statement provides a clear way to select among many alternatives. Use `break` to prevent unintended fall-through, include a `default` to handle unexpected input, and group cases when multiple labels should share the same action.
