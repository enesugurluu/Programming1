
# Lesson 9: Character Arrays (Strings)

## Using Character Arrays to Store and Manipulate Strings

- **Arrays can hold data of any type**, though all the elements of a given array must have the **same type**.
- Here we discuss **storing strings in character arrays**.
- A string such as **"hello"** is really an **array of individual characters**.

---

## Initializing a Character Array with a String

A character array can be initialized using a **string literal**.

Example:

```c
char string1[] = "first";
```

Notes:

- The compiler determines `string1`’s size based on the string’s length.
- The string **"first"** contains **five characters** plus a **string-terminating null character** (`'\0'`).
	- So `string1` actually contains **six elements**.

Example (checking the size of the array):

```c
char string1[] = "first";
size_t size = sizeof(string1);
printf("%zu", size);
```

> A character array representing a string should always be defined large enough to hold the string’s number of characters **and** the terminating null character.

---

## Initializing a Character Array with an Initializer List of Characters

Character arrays can also be initialized with individual character constants in an initializer list.

Example (equivalent to the string-literal initialization above):

```c
char string1[] = {'f', 'i', 'r', 's', 't', '\0'};
```

This approach can be **tedious**, so string literals are often preferred.

---

## Accessing the Characters in a String

You can access a string’s individual characters directly using array subscript (index) notation.

Example:

```c
char string1[] = "first";

printf("%c\n", string1[0]);
printf("%c\n", string1[5]);
printf("%c\n", string1[4]);
```

---

## Inputting into a Character Array

The following definition creates a character array capable of storing a string of at most **19 characters** and a terminating null character:

```c
char string2[20];
```

The following statement reads a string from the keyboard into `string2`.

> You pass the array name to `scanf` **without** the `&` used with non-string variables.

```c
scanf("%19s", string2);
```

### Security Tip

- It’s your responsibility to ensure that the array into which the string is read is capable of holding any string that the user types.
- Function `scanf` **does not check** how large the array is.
	- It will read characters until a **space**, **tab**, **newline**, or **end-of-file indicator** is encountered.
- The string `string2` should be **no longer than 19 characters** to leave room for the terminating null character.
	- If the user types **20 or more** characters, your program may crash or create a security vulnerability called a **buffer overflow**.
	- For this reason, we used the conversion specification **`%19s`** to read a maximum of **19 characters**.

---

## Outputting a Character Array That Represents a String

A character array representing a string can be output with `printf` using the **`%s`** conversion specification.

Example:

```c
printf("%s\n", string2);
```

Notes:

- Like `scanf`, `printf` does not check how large the character array is.
- It displays the string’s characters until it encounters the terminating null character.
	- Consider what would print if, for some reason, the terminating null character were missing.
