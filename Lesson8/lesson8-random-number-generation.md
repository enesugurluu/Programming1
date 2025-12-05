# Programming 1
---

# Lesson 8 – Random-Number Generation

## The `rand` Function

- Example statement:
	```c
	int value = rand();
	```
- `rand` is defined in the `<stdlib.h>` header.
- It returns an `int` value between **0** and **RAND_MAX** (a constant defined in `<stdlib.h>`).
- The range produced directly by `rand` is often **different** from the range we actually need in an application.
	- Example: A coin-tossing program might only need two values:
		- `0` for **heads**
		- `1` for **tails**

---

## Rolling a Six-Sided Die (Scaling and Shifting)

To simulate rolling a six-sided die, we need random integers from **1 to 6**.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
		for (int i = 1; i <= 10; ++i) {
				printf("%d ", 1 + (rand() % 6)); // display random die value
		}

		puts("");
}
```

- We use the **remainder operator** (`%`) with `rand` to produce integers in the range **0–5**:
	- `rand() % 6` → values: `0, 1, 2, 3, 4, 5`
	- This is called **scaling**, and `6` is the **scaling factor**.
- We then **shift** the range by adding `1`:
	- `1 + (rand() % 6)` → values: `1, 2, 3, 4, 5, 6`

---

## Rolling a Six-Sided Die Many Times

If we roll the die a very large number of times (for example, **60,000,000** rolls),
we expect each face (1–6) to appear **approximately** the same number of times.

- A program (like `fig05_05.c`) can:
	- Roll the die 60,000,000 times using `1 + (rand() % 6)`.
	- Count how often each face occurs.
	- Display a table of **Face** vs. **Frequency**.
- The output shows that each face appears with roughly equal frequency, confirming that `rand` can be used to **simulate** a fair die.

---

## Pseudorandom Numbers and Repeatability

Running the simple die-rolling program (for example `fig05_04.c`) **again** produces
the **same sequence** of values as before (for instance: `6 6 5 5 6 5 1 1 5 3`).

- How can these be "random" numbers?
	- `rand` actually generates **pseudorandom** numbers.
	- The sequence is determined by an internal **seed** value.
- This repeatability is very useful when **debugging**:
	- Getting the same sequence each run helps verify that changes in the code produce the expected results.

Once the program is debugged, we usually want a **different** sequence of random numbers each time it runs.
For that, we use the **`srand`** function.

---

## Using `srand` to Seed the Random-Number Generator

The function `srand` is also defined in `<stdlib.h>` and is used to **seed** the random-number generator.

Example program (similar to `fig05_06.c`):

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
		printf("%s", "Enter seed: ");

		int seed = 0;              // number used to seed the random-number generator
		scanf("%d", &seed);

		srand(seed);               // seed the random-number generator

		for (int i = 1; i <= 10; ++i) {
				printf("%d ", 1 + (rand() % 6)); // display random die value
		}

		puts("");
}
```

- Each time you run the program with a **different seed**, you get a **different sequence** of random numbers.
- If you run it again with the **same seed**, you get the **same sequence** again.

Example behavior:

- Enter seed: `67` → `6 1 4 6 2 1 6 1 6 4`
- Enter seed: `867` → `2 4 6 1 6 1 1 3 6 2`
- Enter seed: `67` again → `6 1 4 6 2 1 6 1 6 4` (same as the first time)

---

## Seeding with the Current Time

Typing a seed every time can be inconvenient. To **automatically** get a different seed
each run, we can use the current **time** as the seed.

For this we include `<time.h>` and call `time(NULL)`:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
		srand(time(NULL));         // seed using current time

		for (int i = 1; i <= 10; ++i) {
				printf("%d ", 1 + (rand() % 6));
		}

		puts("");
}
```

- `time(NULL)` returns the number of **seconds since midnight, January 1, 1970**.
- That integer value is used as the seed.
- Because the time changes from run to run, the seed changes and we usually get a **different sequence** of random numbers every time we execute the program.

---

## Summary

- `rand()` → generates pseudorandom integers in the range `0` to `RAND_MAX`.
- Use the remainder operator (`%`) to **scale** the range, and addition to **shift** it to the desired interval.
- `srand(seed)` → seeds the generator so you can control or change the sequence.
- Seeding with a **fixed** value reproduces the **same** sequence (useful for debugging).
- Seeding with `time(NULL)` produces a **different** sequence each time the program runs.


