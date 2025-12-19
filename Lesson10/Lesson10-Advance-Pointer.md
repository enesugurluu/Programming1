# Using the const Qualifier with Pointers

The `const` qualifier enables you to inform the compiler that a particular variable's value should not be modified (principle of least privilege).

There are four ways to pass a pointer to a function:
1. A **non-constant pointer** to **non-constant data**
2. A **constant pointer** to **non-constant data**
3. A **non-constant pointer** to **constant data**
4. A **constant pointer** to **constant data**

> **Note:** Each of the four combinations provides different access privileges. Always award a function enough access to the data in its parameters to accomplish its specified task, but absolutely no more.

## 1. Non-Constant Pointer to Non-Constant Data

The highest level of data access is granted by a **non-constant pointer to non-constant data**.
* The data can be modified through the dereferenced pointer.
* The pointer can be modified to point to other data items.

A function might use such a pointer to receive a string argument, then process each character in the string.

### Example: Converting a String to Uppercase

Function `convertToUppercase` declares its parameter `sPtr` as a non-constant pointer to non-constant data (`char *sPtr`).

```c
#include <ctype.h>
#include <stdio.h>

void convertToUppercase(char *sPtr); // prototype

int main(void) {
    char string[] = "cHaRaCters and $32.98"; // initialize char array

    printf("The string before conversion is: %s\n", string);
    convertToUppercase(string);
    printf("The string after conversion is: %s\n", string);
}

// convert string to uppercase letters
void convertToUppercase(char *sPtr) {
    while (*sPtr != '\0') { // current character is not null
        *sPtr = toupper(*sPtr); // convert to uppercase
        ++sPtr; // make sPtr point to the next character
    }
}
```

**Output:**
```
The string before conversion is: cHaRaCters and $32.98
The string after conversion is: CHARACTERS AND $32.98
```

## 2. Non-Constant Pointer to Constant Data

A **non-constant pointer to constant data** can be modified to point to any data item of the appropriate type, but **the data to which it points cannot be modified**.

A function might receive such a pointer to process an array argument's elements without modifying them.

### Example: Printing a String One Character at a Time

Function `printCharacters` declares parameter `sPtr` to be of type `const char *sPtr`.
* The declaration is read from right to left as "sPtr is a pointer to a character constant".

```c
#include <stdio.h>

void printCharacters(const char *sPtr);

int main(void) {
    // initialize char array
    char string[] = "print characters of a string";

    puts("The string is:");
    printCharacters(string);
    puts("");
}

// sPtr cannot be used to modify the character to which it points,
// i.e., sPtr is a "read-only" pointer
void printCharacters(const char *sPtr) {
    // loop through entire string
    for (; *sPtr != '\0'; ++sPtr) { // no initialization
        printf("%c", *sPtr);
    }
}
```

**Output:**
```
The string is:
print characters of a string
```

### Example: Trying to Modify Constant Data

If you attempt to modify data through a pointer to constant data, the compiler will generate an error.

```c
#include <stdio.h>
void f(const int *xPtr); // prototype

int main(void) {
    int y = 7; // define y

    f(&y); // f attempts illegal modification
}

// xPtr cannot be used to modify the
// value of the variable to which it points
void f(const int *xPtr) {
    *xPtr = 100; // error: cannot modify a const object
}
```

**Error Message:**
```
error C2166: l-value specifies const object
```

## 3. Constant Pointer to Non-Constant Data

A **constant pointer to non-constant data** always points to the same memory location, but the data at that location can be modified through the pointer.

* This is the default for an **array name**, which is a constant pointer to the array's first element.
* Pointers that are declared `const` must be initialized when they're defined.

### Example: Attempting to Modify a Constant Pointer

```c
// Attempting to modify a constant pointer to non-constant data.
#include <stdio.h>

int main(void) {
    int x = 0; // define x
    int y = 0; // define y

    // ptr is a constant pointer to an integer that can be modified
    // through ptr, but ptr always points to the same memory location
    int * const ptr = &x;

    *ptr = 7; // allowed: *ptr is not const
    ptr = &y; // error: ptr is const; cannot assign new address
}
```

**Error Message:**
```
error C2166: l-value specifies const object
```

## 4. Constant Pointer to Constant Data

The **least access privilege** is granted by a **constant pointer to constant data**.
* Such a pointer always points to the same memory location.
* The data at that memory location cannot be modified.

Declaration: `const int *const ptr`. Read right-to-left as "ptr is a constant pointer to an integer constant".

### Example: Attempting to Modify a Constant Pointer to Constant Data

```c
#include <stdio.h>

int main(void) {
    int x = 5;
    int y = 0;

    // ptr is a constant pointer to a constant integer. ptr always
    // points to the same location; the integer at that location
    // cannot be modified
    const int *const ptr = &x; // initialization is OK

    printf("%d\n", *ptr);
    *ptr = 7; // error: *ptr is const; cannot assign new value
    ptr = &y; // error: ptr is const; cannot assign new address
}
```

**Error Messages:**
```
error C2166: l-value specifies const object
error C2166: l-value specifies const object
```
