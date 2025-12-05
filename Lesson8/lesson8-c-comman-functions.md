# Programming 1
---

# Lesson 8: Common C Functions

## Table of Contents
- [Math Library Functions](#math-library-functions)
- [String Functions](#string-functions)
- [Character Functions](#character-functions)
- [Input/Output Functions](#inputoutput-functions)

---

## Math Library Functions

To use these functions, include: `#include <math.h>`

### Ceiling and Floor Functions

#### `ceil(x)`
Returns the smallest integer greater than or equal to x.

```c
#include <stdio.h>
#include <math.h>

int main() {
    double num1 = 4.3;
    double num2 = -4.3;
    
    printf("ceil(4.3) = %.1f\n", ceil(num1));    // Output: 5.0
    printf("ceil(-4.3) = %.1f\n", ceil(num2));   // Output: -4.0
    
    return 0;
}
```

#### `floor(x)`
Returns the largest integer less than or equal to x.

```c
#include <stdio.h>
#include <math.h>

int main() {
    double num1 = 4.7;
    double num2 = -4.7;
    
    printf("floor(4.7) = %.1f\n", floor(num1));    // Output: 4.0
    printf("floor(-4.7) = %.1f\n", floor(num2));   // Output: -5.0
    
    return 0;
}
```

### Power and Square Root Functions

#### `pow(base, exponent)`
Returns base raised to the power of exponent.

```c
#include <stdio.h>
#include <math.h>

int main() {
    double result = pow(2, 3);  // 2^3
    printf("2^3 = %.1f\n", result);  // Output: 8.0
    
    result = pow(5, 2);  // 5^2
    printf("5^2 = %.1f\n", result);  // Output: 25.0
    
    return 0;
}
```

#### `sqrt(x)`
Returns the square root of x.

```c
#include <stdio.h>
#include <math.h>

int main() {
    double num = 16.0;
    printf("sqrt(16) = %.2f\n", sqrt(num));  // Output: 4.00
    
    num = 25.0;
    printf("sqrt(25) = %.2f\n", sqrt(num));  // Output: 5.00
    
    return 0;
}
```

### Absolute Value Functions

#### `fabs(x)`
Returns the absolute value of a floating-point number.

```c
#include <stdio.h>
#include <math.h>

int main() {
    double num1 = -5.7;
    double num2 = 3.2;
    
    printf("fabs(-5.7) = %.1f\n", fabs(num1));  // Output: 5.7
    printf("fabs(3.2) = %.1f\n", fabs(num2));   // Output: 3.2
    
    return 0;
}
```

#### `abs(x)`
Returns the absolute value of an integer. (Requires `#include <stdlib.h>`)

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1 = -10;
    int num2 = 15;
    
    printf("abs(-10) = %d\n", abs(num1));  // Output: 10
    printf("abs(15) = %d\n", abs(num2));   // Output: 15
    
    return 0;
}
```

### Trigonometric Functions

#### `sin(x)`, `cos(x)`, `tan(x)`
Calculate sine, cosine, and tangent (x must be in radians).

```c
#include <stdio.h>
#include <math.h>

int main() {
    double angle = 3.14159 / 4;  // 45 degrees in radians
    
    printf("sin(45°) = %.2f\n", sin(angle));  // Output: 0.71
    printf("cos(45°) = %.2f\n", cos(angle));  // Output: 0.71
    printf("tan(45°) = %.2f\n", tan(angle));  // Output: 1.00
    
    return 0;
}
```

### Logarithmic Functions

#### `log(x)`
Returns the natural logarithm (base e) of x.

```c
#include <stdio.h>
#include <math.h>

int main() {
    double num = 2.718282;  // e
    printf("log(e) = %.2f\n", log(num));  // Output: 1.00
    
    return 0;
}
```

#### `log10(x)`
Returns the base-10 logarithm of x.

```c
#include <stdio.h>
#include <math.h>

int main() {
    double num = 100.0;
    printf("log10(100) = %.1f\n", log10(num));  // Output: 2.0
    
    return 0;
}
```

### Rounding Function

#### `round(x)`
Rounds x to the nearest integer.

```c
#include <stdio.h>
#include <math.h>

int main() {
    printf("round(4.3) = %.1f\n", round(4.3));   // Output: 4.0
    printf("round(4.5) = %.1f\n", round(4.5));   // Output: 5.0
    printf("round(4.7) = %.1f\n", round(4.7));   // Output: 5.0
    printf("round(-4.5) = %.1f\n", round(-4.5)); // Output: -4.0
    
    return 0;
}
```

---

## String Functions

To use these functions, include: `#include <string.h>`

#### `strlen(str)`
Returns the length of a string.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello World";
    printf("Length: %lu\n", strlen(str));  // Output: 11
    
    return 0;
}
```

#### `strcpy(dest, src)`
Copies string from src to dest.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello";
    char dest[20];
    
    strcpy(dest, src);
    printf("Copied string: %s\n", dest);  // Output: Hello
    
    return 0;
}
```

#### `strcat(dest, src)`
Concatenates (appends) src string to dest string.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char dest[50] = "Hello ";
    char src[] = "World";
    
    strcat(dest, src);
    printf("Concatenated: %s\n", dest);  // Output: Hello World
    
    return 0;
}
```

#### `strcmp(str1, str2)`
Compares two strings. Returns 0 if equal, negative if str1 < str2, positive if str1 > str2.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Apple";
    char str2[] = "Banana";
    
    int result = strcmp(str1, str2);
    
    if (result == 0)
        printf("Strings are equal\n");
    else if (result < 0)
        printf("str1 is less than str2\n");  // This will print
    else
        printf("str1 is greater than str2\n");
    
    return 0;
}
```

---

## Character Functions

To use these functions, include: `#include <ctype.h>`

#### `isalpha(c)`
Checks if character is alphabetic.

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch1 = 'A';
    char ch2 = '5';
    
    printf("isalpha('A') = %d\n", isalpha(ch1));  // Output: non-zero (true)
    printf("isalpha('5') = %d\n", isalpha(ch2));  // Output: 0 (false)
    
    return 0;
}
```

#### `isdigit(c)`
Checks if character is a digit (0-9).

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch1 = '5';
    char ch2 = 'A';
    
    printf("isdigit('5') = %d\n", isdigit(ch1));  // Output: non-zero (true)
    printf("isdigit('A') = %d\n", isdigit(ch2));  // Output: 0 (false)
    
    return 0;
}
```

#### `isupper(c)` and `islower(c)`
Checks if character is uppercase or lowercase.

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch1 = 'A';
    char ch2 = 'a';
    
    printf("isupper('A') = %d\n", isupper(ch1));  // Output: non-zero (true)
    printf("islower('a') = %d\n", islower(ch2));  // Output: non-zero (true)
    
    return 0;
}
```

#### `toupper(c)` and `tolower(c)`
Converts character to uppercase or lowercase.

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'a';
    
    printf("toupper('a') = %c\n", toupper(ch));  // Output: A
    printf("tolower('A') = %c\n", tolower('A')); // Output: a
    
    return 0;
}
```

#### `isspace(c)`
Checks if character is a whitespace character (space, tab, newline, etc.).

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch1 = ' ';
    char ch2 = 'A';
    
    printf("isspace(' ') = %d\n", isspace(ch1));  // Output: non-zero (true)
    printf("isspace('A') = %d\n", isspace(ch2));  // Output: 0 (false)
    
    return 0;
}
```

---

## Input/Output Functions

To use these functions, include: `#include <stdio.h>`

#### `printf()`
Prints formatted output to the console.

```c
#include <stdio.h>

int main() {
    int age = 25;
    float height = 5.9;
    
    printf("Age: %d, Height: %.1f\n", age, height);
    
    return 0;
}
```

#### `scanf()`
Reads formatted input from the user.

```c
#include <stdio.h>

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("You entered: %d\n", num);
    
    return 0;
}
```

#### `getchar()`
Reads a single character from input.

```c
#include <stdio.h>

int main() {
    char ch;
    
    printf("Enter a character: ");
    ch = getchar();
    printf("You entered: %c\n", ch);
    
    return 0;
}
```

#### `putchar(c)`
Prints a single character to output.

```c
#include <stdio.h>

int main() {
    char ch = 'A';
    
    putchar(ch);  // Output: A
    putchar('\n');
    
    return 0;
}
```

---

## Complete Example Program

Here's a comprehensive example using various functions:

```c
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    // Math functions
    printf("=== Math Functions ===\n");
    printf("ceil(4.3) = %.1f\n", ceil(4.3));
    printf("floor(4.7) = %.1f\n", floor(4.7));
    printf("round(4.5) = %.1f\n", round(4.5));
    printf("pow(2, 3) = %.1f\n", pow(2, 3));
    printf("sqrt(16) = %.1f\n", sqrt(16.0));
    printf("abs(-10) = %d\n", abs(-10));
    printf("fabs(-5.7) = %.1f\n", fabs(-5.7));
    
    // String functions
    printf("\n=== String Functions ===\n");
    char str1[50] = "Hello";
    char str2[] = " World";
    printf("Original: %s\n", str1);
    printf("Length: %lu\n", strlen(str1));
    strcat(str1, str2);
    printf("After strcat: %s\n", str1);
    
    // Character functions
    printf("\n=== Character Functions ===\n");
    char ch = 'a';
    printf("Character: %c\n", ch);
    printf("Is alpha: %d\n", isalpha(ch));
    printf("Is digit: %d\n", isdigit(ch));
    printf("To upper: %c\n", toupper(ch));
    
    return 0;
}
```

---

## Notes

- **Math functions** require linking with the math library. When compiling, use:
  ```bash
  gcc program.c -o program -lm
  ```
- Most math functions work with `double` type
- String functions don't automatically allocate memory - ensure destination arrays are large enough
- Character functions return non-zero (true) or 0 (false)
- Always include the appropriate header files for the functions you use

---

## Common Compilation Command

```bash
gcc -o program program.c -lm
```

The `-lm` flag links the math library, which is required for math functions.


