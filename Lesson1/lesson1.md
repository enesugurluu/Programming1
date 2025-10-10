double price=12.35;
# Programming 1 Codes

## Basic Data Types

Data types are declarations for variables that determine the type and size of data associated with variables.

For example:

```c
int myVar;
```

Here, `myVar` is a variable of `int` (integer) type and the size of `int` is 4 bytes.

### `int` Data Type

Integers are whole numbers that can have zero, positive, and negative values (e.g., `0`, `-23`, `985`), but no decimal values.

We use `int` for declaring an integer variable. The size of `int` is usually 4 bytes (32 bits).

It can take 2,147,483,648 distinct states from `-2147483648` to `2147483647`.

### `float` and `double` Data Types

`float` and `double` are used to hold real numbers:

```c
float salary = 0.657;
double price = 12.35;
```

**What's the difference between float and double?**

- The size of `float` (single precision) is 4 bytes.
- The size of `double` (double precision) is 8 bytes.

### `char` Data Type

Used for declaring character type variables. For example:

```c
char test = 'h';
```

The size of the character variable is 1 byte.

### `short` and `long` Data Types

If you need to use a large number, you can use the `long` specifier. (Note: the size of the `long` data type is not fixed and varies by architecture, operating system, and compiler. See [GeeksforGeeks: Need of Long Data Type in C/C++](https://www.geeksforgeeks.org/cpp/need-long-data-type-c-cpp/))

```c
long a;
long long b;
long double c;
```

Here, variables `a` and `b` can store integer values, and `c` can store a floating-point number.

If you are sure only a small integer (`[−32767, +32767]` range) will be used, you can use `short`:

```c
short d;
```

### `void` Data Type

`void` is an incomplete type, meaning nothing or no type. You cannot create variables of `void` type.

For example, if a function is not returning anything, its return type should be `void`.

---

## Real-World Uses of C Data Types

### `short` (`−32,767` … `+32,767`)
- Thermometer readings (`−100` … `+100 °C`)
- Heart rate (`30` … `250 BPM`)
- Elevator floors (`< 1000`)

### `int` (commonly `−2,147,483,648` … `+2,147,483,647` on 32-bit/64-bit systems)
- Population of a country (~1.4 billion max)

### Unsigned Variants
- `unsigned short` (`0` … `65,535`): device IDs, port numbers, student IDs

### `char` (`−128` … `+127` or `0` … `255` if unsigned)
- Single characters in text
- Small numeric values (like age in years, `0` … `120`)
- Flags or status codes (`0 = off`, `1 = on`, etc.)

### Floating-point Types
- `float`: approximate real numbers, sensor values like temperature with decimals (`36.5 °C`)
- `double`: precise calculations, physics simulations, financial interest rates