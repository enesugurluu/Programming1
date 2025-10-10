# Programming 1

This repository contains simple C programs and lesson notes for an introductory Programming 1 course. The code files demonstrate basic C concepts (data types, arithmetic, input/output, conditionals, operators, and memory access).

## Repository structure

- `Lesson1/`
	- `lesson1.c` — simple arithmetic and printf examples.
	- `in-class-work1.c` — reads two integers and prints sum, subtraction, division, multiplication and modulus results.
	- `lesson1.md` — lesson notes about basic data types and short examples.
- `Lesson2/`
	- `lesson2.c` — examples demonstrating averages, even/odd check, `if`/`else if` chains and `scanf` usage.
	- `lesson2.md` — lesson notes about the `&` operator, memory concepts and conditional statements.
	- `lesson2.exe` — compiled binary (checked in). You can remove this if you prefer source-only repositories.

## Goals / contract

- Inputs: C source files in `Lesson1/` and `Lesson2/`.
- Output: buildable executables and console output demonstrating the examples.
- Success: Each `.c` file compiles and runs on a machine with a C compiler (GCC/MinGW/MSYS) and produces the expected console output.

Edge cases to watch
- Missing or invalid user input to `scanf` (programs don't currently validate input return values).
- Integer division yields truncated results; expect that in examples using `/`.

## Prerequisites

- A C compiler such as `gcc` available in your PATH, or use the provided VS Code build task which uses MSYS2's `gcc.exe`.
- Windows PowerShell (examples below use PowerShell). Adjust commands for other shells.

## Build and run (PowerShell)

Recommended: use the VS Code build task `C/C++: gcc.exe build active file` (already present in the workspace tasks).

From PowerShell you can compile and run each lesson manually. Run these commands from the repository root (where this `readme.md` lives):

```powershell
# Compile Lesson1 examples
gcc -g .\Lesson1\lesson1.c -o .\Lesson1\lesson1.exe
gcc -g .\Lesson1\in-class-work1.c -o .\Lesson1\in-class-work1.exe

# Run
.\Lesson1\lesson1.exe
.\Lesson1\in-class-work1.exe

# Compile and run Lesson2
gcc -g .\Lesson2\lesson2.c -o .\Lesson2\lesson2.exe
.\Lesson2\lesson2.exe
```

If `gcc` is not on your PATH but you have MSYS2 installed like the VS Code task, you can run the same commands with the full `gcc.exe` path used by the task.

## What each source file demonstrates (quick)

- `Lesson1/lesson1.c`
	- Declares integer variables, computes `sum` and `multiply`, and prints results with `printf`.

- `Lesson1/in-class-work1.c`
	- Prompts for two integers via `scanf` and prints the five basic arithmetic operations (sum, subtract, divide, multiply, mod).
	- Note: `divide` is integer division; decimals are truncated.

- `Lesson2/lesson2.c`
	- Calculates an average of five integers.
	- Demonstrates an even/odd check using `%`.
	- Contains an interactive `scanf` example that reads a `grade` and prints a letter grade using an `if` / `else if` ladder.

## Common pitfalls and recommendations

- Always check the return value of `scanf` in real programs to avoid undefined behaviour when input is missing or malformed.
- For floating-point division, use `float`/`double` variables and `%f` / `%lf` in `printf`/`scanf`.
- Remove compiled binaries (`*.exe`) from source control or add them to `.gitignore` to keep the repo source-only.

## Next steps (suggested)

- Add small unit-test-like input scripts or expected-output comments for each example.
- Add input validation to `scanf` calls.
- Add a `.gitignore` to exclude binaries and object files.

## Contributing

Open a pull request with small, focused changes. If you add exercises, include example inputs and expected outputs.

## License

Place a license file if you want to share these materials publicly (e.g., `LICENSE` with CC-BY or MIT as appropriate).

---

Generated: documented code examples and build instructions for this workspace.
