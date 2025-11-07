# Programming 1 — Lesson 6

## for Iteration Statement

The for statement is a compact way to write counter‑controlled loops. Its header holds three parts:

```c
for (initialization; loopContinuationCondition; increment) {
	statement(s)
}
```

Where:
- initialization names the loop’s control variable and provides its initial value.
- loopContinuationCondition determines whether the loop should continue executing.
- increment modifies the control variable’s value after executing the body so the condition eventually becomes false.

Notes:
- The two semicolons in the header are required.
- If the loop-continuation condition is initially false, the for statement’s body does not execute at all.

---

## Example (fig04_02.c): print 1 through 5

```c
// fig04_02.c
// Counter-controlled iteration with the for statement.
#include <stdio.h>

int main(void) {
	// initialization, condition, and increment are in the header
	for (int counter = 1; counter <= 5; ++counter) {
		printf("%d ", counter);
	}
	puts(""); // outputs a newline
}
```

Output

```
1 2 3 4 5
```

---

## Header components at a glance

Using `for (int counter = 1; counter <= 5; ++counter)`:
- `for` keyword — starts the loop.
- `int counter = 1` — control-variable declaration and initial value.
- first `;` — required separator.
- `counter <= 5` — loop-continuation condition (final true value is 5).
- second `;` — required separator.
- `++counter` — increment of the control variable executed after the body each iteration.

Always use braces around the body, even if it contains a single statement.

---

## Execution order (what happens in a for loop?)

1) When the loop begins, the control variable is defined and initialized (`counter = 1`).
2) The condition `counter <= 5` is tested. It’s true at first, so the body executes and prints `1`.
3) After the body, the increment `++counter` runs, then the condition is re-tested. With `counter == 2`, it’s still true, so the body runs again.
4) This continues until `counter` becomes `6`. The condition is now false, iteration terminates, and execution continues with the first statement after the for.

---

## Tips and common mistakes

- Prefer braces `{ }` even for a single statement to avoid bugs during later edits.
- Mind the boundary: `<=` vs `<` changes how many iterations run (off-by-one errors are common).
- Increment runs after the body each time; don’t also modify the control variable in the body unless you intend to.
- A variable declared in the `for` header (e.g., `int i = 0`) has scope limited to the loop.
- You can omit parts, but the semicolons must remain: `for (; condition; increment)` or `for (init; ; increment)`; an empty condition acts like `true` (risk of infinite loop).

---

## Useful variations

Count down:

```c
for (int i = 5; i >= 1; --i) {
	printf("%d ", i);
}
```

Custom step size:

```c
for (int i = 0; i <= 20; i += 5) {
	printf("%d ", i); // 0 5 10 15 20
}
```

Multiple expressions:

```c
for (int i = 0, j = 10; i < j; ++i, --j) {
	// work with i and j
}
```

---

## Summary

- The for header concisely expresses initialization, condition, and increment.
- Two semicolons are mandatory; the body may not execute if the condition is initially false.
- Understand execution order to avoid off‑by‑one and infinite-loop errors.

