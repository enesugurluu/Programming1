# Lesson 10 — Pointers (C)

## Introduction
A **pointer** is one of C’s most important features. Pointers enable programs to:

1. **Pass-by-reference** behavior (let a function modify a variable in the caller).
2. **Share data between functions efficiently** (avoid copying large data).
3. **Work naturally with arrays and strings** (arrays decay to pointers in many expressions).
4. Build **dynamic data structures** that grow/shrink at runtime (linked lists, stacks, trees).

---

## Pointer variable definitions and initialization

### What is a pointer?
- A **pointer variable** stores a **memory address**.
- Typically, that address is the location of another variable (an “object”) in memory.

### Direct vs. indirect access (indirection)
- A normal variable name (like `count`) is used to access its value **directly**.
- A pointer (like `countPtr`) accesses a value **indirectly** by first holding an address, then using that address to reach the value.
- Accessing a value *through* a pointer is called **indirection**.

---

## Declaring pointers

Pointer declarations include `*` (star):

```c
int *countPtr;
```

Read it right-to-left: **“countPtr is a pointer to int.”**

Common naming conventions you may see:
- Suffix `Ptr` (e.g., `countPtr`, `namePtr`)
- Prefix `p` (e.g., `pCount`, `pName`)

> Tip: `*` is part of the declarator, so be careful when declaring multiple variables:
>
> ```c
> int* aPtr, b;   // aPtr is a pointer, b is a normal int
> ```
>
> Many instructors prefer:
>
> ```c
> int *aPtr;
> int b;
> ```

---

## Pointer operators

### Address-of operator `&`
The unary operator `&` returns the **address** of a variable.

Example:

```c
int y = 5;
int *yPtr = &y;  // yPtr now stores the address of y
```

Important rule:
- The operand of `&` must be something that **has an address you can take**, like a variable.
- You cannot apply `&` to most literals:

```c
// int *p = &27;   // ERROR
```

### Indirection (dereference) operator `*`
The unary operator `*` is used on a pointer to access the value **stored at the pointed-to address**.

Example:

```c
printf("%d\n", *yPtr);  // prints 5
```

⚠️ Error tip: Dereferencing an **uninitialized** pointer (or a pointer that does not point to valid memory) is a serious bug. It can crash your program, corrupt data, or create security issues.

---

## Pointer representation in memory (concept)
Think of it like this:
- Variable `y` holds a value (e.g., `5`) at some memory location.
- Pointer `yPtr` holds a number that is the **address of `y`**.

So:
- `yPtr == &y` is true
- `*yPtr == y` is true

---

## Initializing and assigning values to pointers
Pointers should be initialized when they are defined. Typical valid initial values:

1. **`NULL`** (recommended when you don’t have a real address yet)
2. **`0`** (equivalent to `NULL`, but less explicit)
3. A valid **address** (like `&y`)

Example:

```c
#include <stdio.h>

int main(void) {
    int *p = NULL; // safe “points to nothing” value

    if (p == NULL) {
        printf("p is NULL (not pointing anywhere yet)\n");
    }

    return 0;
}
```

---

## Example: Demonstrating `&` and `*`
This example prints:
- the address of a variable
- the value inside the pointer (same address)
- the value in the variable
- the value reached by dereferencing the pointer

```c
#include <stdio.h>

int main(void) {
    int a = 7;
    int *aPtr = &a;

    printf("Address of a      : %p\n", (void*)&a);
    printf("Value stored in aPtr: %p\n\n", (void*)aPtr);

    printf("Value of a        : %d\n", a);
    printf("Value of *aPtr    : %d\n\n", *aPtr);

    printf("Showing * and & are complements (when used correctly):\n");
    printf("&*aPtr == aPtr    : %s\n", (&*aPtr == aPtr) ? "true" : "false");
    printf("*&a   == a        : %s\n", (*&a == a) ? "true" : "false");

    return 0;
}
```

Notes:
- Use `%p` to print addresses.
- Cast to `(void*)` when using `%p` to match the expected type.

---

## Quick checklist (common mistakes)
- Don’t dereference a pointer before it points to a valid object.
- Initialize pointers (`NULL` is fine).
- Print addresses with `%p` (and cast to `(void*)`).
- Remember: `*` in a declaration means “pointer to …”; `*` in an expression means “dereference.”
