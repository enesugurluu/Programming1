# Passing Arrays to Functions

- To pass an array argument to a function, specify the array's name without any brackets. For example, if an array has been defined as:
  ```c
  int numbers[5] = {1, 2, 3, 4, 5};
  ```
- The following function call passes array `numbers` and its size to function:
  ```c
  calculateSum(numbers, 5)
  ```
- **Examples:** `ex_pass_array_1.c`, `ex_pass_array_2.c` and `ex_pass_array_3.c`
- Recall that all **arguments in C are passed by value**. However, **C automatically passes arrays to functions by reference**—the called functions can modify the callers' original array element values.

---

## Passing Arrays to Functions: An Example

- **`ex_pass_array_1.c`** defines a function `calculateSum` that takes an array and its size as parameters.
    - Inside the function, a variable `sum` is initialized to 0.
    - A `for`-loop runs through the array, adding each element to `sum`.
    - The function returns the total sum of all array elements.
    - In `main`, an integer array `numbers[5] = {1, 2, 3, 4, 5}` is declared.
    - The array is passed to `calculateSum(numbers, 5)`, which returns the computed sum.
    - The result is printed: `"Sum of array elements: 15"`.

---

## Passing Arrays to Functions: An Example

- **`ex_pass_array_2.c`** prints all the elements of the array.
    - The function `printArray` receives an array and its size as parameters.
    - A `for`-loop iterates through the array from index 0 to `size - 1`.
    - Each element is printed on the same line using `printf("%d ", arr[i]);`.
    - After printing all elements, a newline is added with `printf("\n");`.
    - In `main`, the array `numbers` is defined with values `{1, 2, 3, 4, 5}`.
    - The program calculates the array size using:
      $$size = \frac{sizeof(numbers)}{sizeof(numbers[0])}$$
    - The array and its size are passed to `printArray`.

---

## Showing That an Array Name Is an Address

- Recall that all **arguments in C are passed by value**. However, **C automatically passes arrays to functions by reference**—the called functions can modify the callers' original array element values.
- **`fig06_10.c`** demonstrates that "the value of an array name" is really the address of the array's first element by printing `array`, `&array[0]` and `&array` using the `%p` conversion specification for printing addresses.
- **Performance tip:** Passing arrays by reference makes sense for performance reasons. If arrays were passed by value, a copy of each element would be passed. For large, frequently passed arrays, this would be time-consuming and would consume storage for the copies of the arrays.
- **Software Engineering Tip:** It's possible to pass an array by value (by placing it in a `struct`, as we explain in Chapter 10, Structures, Unions, Bit Manipulation and Enumerations).
