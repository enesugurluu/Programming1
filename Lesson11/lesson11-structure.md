
# Lesson 11 — Structures

## Structure definitions

- **Structures** are **derived data types** — they’re constructed using objects of other types.
- The keyword `struct` introduces a structure definition.
- A `struct` definition can contain members of different types (e.g., `char`, `int`, `float`).

Example:

```c
struct Person {
		char name[30];
		int age;
		float salary;
};
```

- The identifier name after `struct` (e.g., `Person`) is the **structure tag**, which you use with `struct` to declare variables of the structure type.
- Variables declared within a struct’s braces are the struct’s **members**.
	- Members must have **unique names** *within the same struct*.
	- Different struct types may contain members with the same name without conflict.
- Each structure definition ends with a **semicolon** `;`.

## Notes about structure members

- Structure members can be:
	- `const` or non-`const` primitive types
	- aggregates (such as arrays)
	- other struct objects
- Unlike arrays, structure members can consist of **different data types**.

## Operations that can be performed on structures

You can perform the following operations on structs:

1. Assigning one struct variable to another of the **same type**.
2. Taking the address (`&`) of a struct variable.
3. Accessing a struct variable’s members.
4. Using `sizeof` to determine a struct variable’s size.
5. Zero-initializing a struct variable in its definition, e.g.:

```c
struct Person person1 = {};
```

> **Error tip:** Assigning a structure of one type to one of a different type is a **compilation error**.

## Structure equality & memory alignment

- **No direct comparison:** Structures cannot be compared using `==` or `!=`.
- **Memory gaps (holes):** Members are not always stored in consecutive bytes due to **memory alignment**.
- **Padding:** Computers may insert “holes” to align data with memory boundaries (half-word, word, or double-word).
- **Machine dependent:** This behavior depends on the hardware architecture and word size (typically 4 or 8 bytes).

### Why raw struct comparison is risky (padding example)

```c
struct example {
		char c;
		int i;
} sample1, sample2;
```

- **Word alignment:** In a 4-byte word system, each member may be forced to start at a word boundary.
- **Memory gaps (padding):** Since a `char` is 1 byte and an `int` is 4 bytes, the system may insert a 3-byte hole (unspecified values) between them to align the integer.
- **Comparison risk:** Even if `c` and `i` are identical in both `sample1` and `sample2`, the padding bytes may contain different garbage data, making raw memory comparison unreliable.

## Initializing structures

- You can initialize a struct variable via an **initializer list**.

Example:

```c
struct Person p1 = {"Veli Baser", 34, 3000.0};
```

- If there are fewer initializers than members, the remaining members are automatically initialized to:
	- `0` (for numbers)
	- `\0` / empty (for `char` arrays)
	- `NULL` (for pointer members)

## Accessing structure members with `.` and `->`

You can access structure members with:

1. The **structure member operator** (`.`) — *dot operator*
2. The **structure pointer operator** (`->`) — *arrow operator*

### Operator precedence

- Highest precedence: struct member operators (`.` and `->`) share the highest priority.
- Associativity: they group from **left-to-right**.
- Same level as: parentheses `()` and array brackets `[]`.

### Structure member operator (`.`)

- The dot operator accesses a structure member via a **struct variable**.

Example:

```c
printf("%s", p1.name);  // displays name
```

### Structure pointer operator (`->`)

- The arrow operator accesses a structure member via a **pointer to a struct** (a minus sign `-` and a greater-than sign `>` with no spaces).

Example:

```c
printf("%s", person2Ptr->name);  // displays name
```

- The expression `person2Ptr->name` is equivalent to `(*person1Ptr).name`.
