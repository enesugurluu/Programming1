# Lesson 9 — Arrays (C)

## Arrays

- An array is a **group of elements of the same type** stored **contiguously in memory**.
- Example: an integer array named `c` containing **five** elements.

### Array elements and indexing

- To refer to a specific location (element) in an array, write the **array name** followed by the element’s **position number in square brackets**.
- The position number is called the element’s **subscript** (or **index**).
- The **first** element is at position **0**.

Example element names for an array with 5 items:

- `c[0]`, `c[1]`, `c[2]`, `c[3]`, `c[4]`

---

## Using array elements (examples)

Let’s examine the array `c` more closely:

- The array’s name is `c`.
- The value of `c[0]` can be `-45`.
- The value of `c[2]` can be `0`.
- The value of `c[4]` can be `1543`.

### Replace an element value

The following statement replaces `c[2]`’s current value with `1000`:

```c
c[2] = 1000;
```

### Sum elements

To print the sum of the values in array `c`’s first three elements:

```c
printf("%d", c[0] + c[1] + c[2]);
```

### Use an element in an expression

To divide the value of element `3` of array `c` by `2` and assign the result to `x`:

```c
x = c[3] / 2;
```

---

## Operator precedence note

- The brackets that enclose an array’s index (`[]`) are an operator with the **highest level of precedence**.

---

## Defining arrays

When you define an array, you specify:

- its **element type**, and
- its **number of elements**

so the compiler can reserve the appropriate amount of memory.

The following definition reserves **5 elements** for integer array `c`, which has indexes in the range **0–4**:

```c
int c[5];
```

### Note (character arrays)

- A `char` array can store a **character string**.
- (More details about strings/pointers are typically covered in later chapters.)

---

## Setting array elements with a loop

- Like any other local variable, **uninitialized array elements contain “garbage” values**.
- A common pattern is to use `for` statements to:
	- set an array’s elements to known values (often `0`), and
	- print the array in a tabular format.

### `size_t` for indexes

- The counter-control variable `i` is often declared as `size_t` in loops that index arrays.
- The C standard says `size_t` is an **unsigned integer type** and is recommended for variables representing:
	- an array’s **size**, or
	- an array **subscripts** (indexes).
- `size_t` is defined in header `<stddef.h>` (often included indirectly by headers like `<stdio.h>`).
- The conversion specification **`%zu`** is used to display `size_t` values.
