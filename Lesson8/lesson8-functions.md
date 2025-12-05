# Programming 1
---

# Lesson 8


### Functions

* **Software Engineering Tip:** **Functions allow you to modularize a program**. In programs containing many functions, *main* is often implemented as a group of calls to functions that perform the bulk of the program’s work.

### Functionalizing Programs

* There are several motivations for "**functionalizing**" a program
    1. The divide-and-conquer approach
    2. Building new programs by using existing functions
    3. Avoiding repeating code in a program

* You can create programs from standardized functions that accomplish specific tasks. This is known as **abstraction**.
    * For example, we use abstraction each time we use standard library functions like *printf*, *scanf* and *pow*.

* **Software Engineering Tip:**
    1. Each function should be limited to performing a single, well-defined task, and the function name should express that task.
    2. If you cannot choose a concise name to describe what the function does, it may be performing too many diverse tasks. It’s usually best to break such a function into smaller functions.

### Function Definitions

* Consider a program that uses a function square to calculate and print the squares from 1 to 10 (see fig05_01.c).

```c
// fig05_01.c
// Creating and using a function.
#include <stdio.h>

int square(int number); // function prototype

int main(void) {
   // loop 10 times and calculate and output square of x each time
   for (int x = 1; x <= 10; ++x) {
      printf("%d  ", square(x)); // function call
   }

   puts("");
}

// square function definition returns the square of its parameter
int square(int number) { // number is a copy of the function's argument
   return number * number; // returns square of number as an int
}
```
*Fig. 5.1 | Creating and using a function.*

### Calling Function square

* Function square is **invoked or called** in main within the printf statement (line 10):
    ```c
    printf("%d ", square(x) ); // line 10
    ```

* Function **receives a copy of the argument x’s value** in the parameter number (line 17). Then square **calculates number * number** and **passes the result back** (line 10) in main where square was invoked. Line 10 **passes square’s result to function printf**, which displays the result on the screen.

```c
17 int square(int number) { // number is a copy of the function's argument
18    return number * number; // returns square of number as an int
19 }
```

### square Function Definition

* Function’s definition (lines 17–19) shows that **it expects an int parameter** number. The **keyword *int* preceding the function name** (line 17) indicates that **square returns an integer result**. The return statement in square **passes the result of number * number back to the calling function**.

```c
17 int square(int number) { // number is a copy of the function's argument
18    return number * number; // returns square of number as an int
19 }
```

* **Software Engineering Tip:** Choosing meaningful function names and meaningful parameter names makes programs more readable and helps avoid excessive comments.

* **Software Engineering Tip:** A function requiring many parameters may be performing too many tasks. Consider dividing the function into smaller functions that perform the separate tasks.
