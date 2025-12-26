
# Lesson 11 — File Processing (File Handling) in C

## Why files?

- **Data in variables is temporary** — it’s lost when a program terminates.
- **Files enable long-term data retention** (saved on SSD / hard drive / etc.).
- In this lesson we focus on how to **create, open, read, write, update, and close** files.
- We consider both:
  - **Sequential-access** file processing (read/write from start to end)
  - **Random-access** file processing (jump to positions in the file)

---

## Files and streams

- C views each file as a **sequential stream of bytes**.
- A file ends when the program reaches an **end-of-file marker (EOF)** or a file-size limit maintained by the OS.

### Standard streams in every program

When a C program starts, three streams are opened automatically:

1. **`stdin`**  — standard input (keyboard by default)
2. **`stdout`** — standard output (screen by default)
3. **`stderr`** — standard error (screen by default)

---

## The `FILE` structure and file pointers

- When you open a file, C returns a pointer to a **`FILE` structure**.
- This `FILE*` contains information the runtime uses to manage the file (buffering, current position, errors, etc.).

Include header:

```c
#include <stdio.h>
```

Typical variable:

```c
FILE *fp = NULL;
```

---

## Opening and closing files

### `fopen` — open a file

```c
FILE *fopen(const char *filename, const char *mode);
```

- Returns a non-`NULL` `FILE*` on success.
- Returns `NULL` on failure (file missing, permission denied, invalid path, etc.).

Always check for `NULL`:

```c
FILE *fp = fopen("data.txt", "r");
if (fp == NULL) {
	printf("Could not open file.\n");
	return 1;
}
```

### `fclose` — close a file

```c
int fclose(FILE *stream);
```

Why it matters:

- flushes buffered output
- releases OS resources
- prevents data loss and file corruption

---

## File open modes (access modes)

> Tip: add **`b`** for binary mode (e.g., `"rb"`, `"wb"`, `"ab+"`).

| Mode | Meaning (text mode) |
|---|---|
| `r` | Open existing file for **reading**. Fails if it doesn’t exist. |
| `w` | Open for **writing** (creates if missing). **Overwrites** if it exists. |
| `a` | Open for **appending** (creates if missing). Writes go to the **end**. |
| `r+` | Open existing file for **reading and writing** (update). |
| `w+` | Open for **reading and writing**. Creates if missing, overwrites if exists. |
| `a+` | Open for **reading and appending**. Creates if missing; writes go to end. |

Binary variants (common):

| Mode | Meaning (binary mode) |
|---|---|
| `rb` | Read binary |
| `wb` | Write binary (overwrite/create) |
| `ab` | Append binary (create if missing) |
| `rb+` | Read + write binary |
| `wb+` | Read + write binary (overwrite/create) |
| `ab+` | Read + append binary |

---

## Writing to a text file

Common functions:

- `fprintf()` — formatted output to a file (like `printf`)
- `fputs()` — write a string/line
- `fputc()` — write a single character

### Example: write a line with `fputs`

```c
#include <stdio.h>

int main(void) {
	FILE *fp = fopen("file.txt", "w");
	if (fp == NULL) {
		printf("file.txt could not be opened for writing.\n");
		return 1;
	}

	fputs("Hello from C file processing!\n", fp);
	fclose(fp);
	return 0;
}
```

---

## Reading from a text file

Common functions:

- `fscanf()` — formatted input from a file (like `scanf`)
- `fgets()` — read a whole line
- `fgetc()` — read a single character

### Example: read lines with `fgets`

```c
#include <stdio.h>

int main(void) {
	FILE *fp = fopen("file.txt", "r");
	if (fp == NULL) {
		printf("file.txt could not be opened for reading.\n");
		return 1;
	}

	char buffer[100];
	while (fgets(buffer, sizeof buffer, fp) != NULL) {
		printf("%s", buffer);
	}

	fclose(fp);
	return 0;
}
```

### `EOF` (End Of File)

- Character-based reads like `fgetc()` return **`EOF`** when the end is reached.
- Don’t store the return value of `fgetc()` in a `char` (because `EOF` is typically `-1`). Use `int`.

Example:

```c
#include <stdio.h>

int main(void) {
	FILE *fp = fopen("file.txt", "r");
	if (fp == NULL) return 1;

	int ch;
	while ((ch = fgetc(fp)) != EOF) {
		putchar(ch);  // write to stdout
	}

	fclose(fp);
	return 0;
}
```

---

## Character I/O: `fgetc` and `fputc`

### `fgetc`

- Reads **one character** from a stream.
- `fgetc(stdin)` is equivalent to `getchar()`.

```c
int c = fgetc(fp);
```

### `fputc`

- Writes **one character** to a stream.
- `fputc('a', stdout)` is equivalent to `putchar('a')`.

```c
fputc('A', fp);
```

### Example: copy a file (character by character)

```c
#include <stdio.h>

int main(void) {
	FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");
	if (in == NULL || out == NULL) {
		printf("File open error.\n");
		if (in) fclose(in);
		if (out) fclose(out);
		return 1;
	}

	int ch;
	while ((ch = fgetc(in)) != EOF) {
		fputc(ch, out);
	}

	fclose(in);
	fclose(out);
	return 0;
}
```

---

## Moving the file position (random access)

When reading/writing, the file pointer advances automatically. To jump to another position, use:

- `fseek()` — move the file position indicator
- `ftell()` — get current position
- `rewind()` — return to beginning

### `fseek`

```c
int fseek(FILE *stream, long offset, int origin);
```

- `origin` is one of:
  - `SEEK_SET` (beginning)
  - `SEEK_CUR` (current position)
  - `SEEK_END` (end)

Example: move to 6 bytes before the end, then write:

```c
fseek(fp, -6, SEEK_END);
fputs("C!!!", fp);
```

### `ftell`

```c
long pos = ftell(fp);
```

### `rewind`

```c
rewind(fp);  // same idea as fseek(fp, 0, SEEK_SET)
```

---

## Binary files (`fread` / `fwrite`)

Binary files store raw bytes (not character text). To open a binary file, use a mode with `b`:

```c
FILE *fp = fopen("data.bin", "wb");
```

### `fwrite`

```c
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
```

### `fread`

```c
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
```

Example: write and read a struct

```c
#include <stdio.h>

typedef struct {
	int n1, n2, n3;
} ThreeNum;

int main(void) {
	ThreeNum out = {1, 5, 6};

	FILE *fp = fopen("numbers.bin", "wb");
	if (fp == NULL) return 1;
	fwrite(&out, sizeof out, 1, fp);
	fclose(fp);

	ThreeNum in = {0, 0, 0};
	fp = fopen("numbers.bin", "rb");
	if (fp == NULL) return 1;
	fread(&in, sizeof in, 1, fp);
	fclose(fp);

	printf("n1=%d n2=%d n3=%d\n", in.n1, in.n2, in.n3);
	return 0;
}
```

---

## Quick reference (common functions)

| Function | Purpose |
|---|---|
| `fopen()` | Open/create a file |
| `fclose()` | Close a file |
| `fprintf()` | Formatted write to a file |
| `fscanf()` | Formatted read from a file |
| `fputs()` | Write a string |
| `fgets()` | Read a line |
| `fputc()` / `putc()` | Write a character |
| `fgetc()` / `getc()` | Read a character |
| `fseek()` | Move file pointer |
| `ftell()` | Get current pointer position |
| `rewind()` | Move pointer to start |
| `fwrite()` | Write bytes (binary) |
| `fread()` | Read bytes (binary) |

---

## Common mistakes & tips

- Always check `fopen()` for `NULL`.
- Always call `fclose()` after you finish.
- When using `fgetc()`, store into an `int` so you can detect `EOF`.
- Prefer `fgets()` over unsafe functions when reading strings.
- Use text modes (`r`, `w`, `a`, etc.) for human-readable files; use binary modes (`rb`, `wb`, etc.) for raw data.

---

## Reference

- GeeksforGeeks: *File Handling in C* — https://www.geeksforgeeks.org/c/basics-file-handling-c/
