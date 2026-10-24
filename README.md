# push_swap — Constrained Stack Sorting Algorithm in C

An algorithmic sorting project developed in C as part of the **42 School** core curriculum. The goal of `push_swap` is to sort a random set of unique integers in ascending order using only **two stacks** (`Stack A` and `Stack B`) and a **restricted set of stack operations**, while minimizing the total number of instructions executed.

---

## Table of Contents

- [Overview](#overview)
- [Allowed Operations](#allowed-operations)
- [Algorithm & Data Structures](#algorithm--data-structures)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage & Examples](#usage--examples)
- [Testing & Verification](#testing--verification)

---

## Overview

At the start of execution:
- **`Stack A`** is initialized with a list of unique positive and/or negative integers passed via command-line arguments.
- **`Stack B`** starts empty.

The program outputs the shortest sequence of valid stack instructions (separated by newlines) required to sort `Stack A` with the smallest element at the top. If the input contains non-numeric characters, integer overflows (`< INT_MIN` or `> INT_MAX`), or duplicate values, the program outputs `ERROR` and terminates cleanly without memory leaks.

---

## Allowed Operations

| Operation | Description |
| :--- | :--- |
| **`sa`** | **Swap A** — Swap the first 2 elements at the top of `Stack A`. |
| **`sb`** | **Swap B** — Swap the first 2 elements at the top of `Stack B`. |
| **`pa`** | **Push A** — Take the first element at the top of `Stack B` and put it at the top of `Stack A`. |
| **`pb`** | **Push B** — Take the first element at the top of `Stack A` and put it at the top of `Stack B`. |
| **`ra`** | **Rotate A** — Shift up all elements of `Stack A` by 1 (the first element becomes the last). |
| **`rb`** | **Rotate B** — Shift up all elements of `Stack B` by 1 (the first element becomes the last). |
| **`rra`** | **Reverse Rotate A** — Shift down all elements of `Stack A` by 1 (the last element becomes the first). |
| **`rrb`** | **Reverse Rotate B** — Shift down all elements of `Stack B` by 1 (the last element becomes the first). |

---

## Algorithm & Data Structures

### 1. Stack Representation
Each stack (`t_stack`) is implemented as a singly linked list of nodes (`t_item`) tracking its current `head` pointer and `size`. For large inputs, an auxiliary structure (`t_ordered_stack`) stores a pre-sorted reference array of the input values to compute chunk boundaries in $O(1)$ lookup per element.

### 2. Small-Input Sorting ($N \le 5$)
- **2 Elements (`two_elements`)**: Performs at most a single `sa` if the top element is greater than the second.
- **3 Elements (`three_elements`)**: Uses a decision tree over all $3! = 6$ permutations to sort the stack in at most **2 operations**.
- **5 Elements (`five_elements`)**: Isolates the minimum and maximum values into `Stack B`, sorts the remaining 3 elements in `Stack A` using `three_elements`, and pushes the two extrema back into their final positions.

### 3. Chunk-Based Partitioning ($N \ge 100$)
For larger datasets, the algorithm partitions the sorted value range into **$K$ chunks** (`5` chunks for $N \approx 100$, `11` chunks for $N \ge 500$):

1. **Bidirectional Scan (`define_hold_position`)**:
   - Scans `Stack A` from the **top** (`find_first`) and from the **bottom** (`find_last`) for elements belonging to the active chunk.
   - Compares the rotation cost of bringing the top candidate to the head via `ra` versus bringing the bottom candidate to the head via `rra`, always choosing the cheaper path.
2. **Sub-Chunk Pre-Sorting (`is_in_subchunk`)**:
   - After pushing an element to `Stack B` (`pb`), if the element belongs to the lower half of the current chunk, `Stack B` is rotated (`rb`) to send smaller elements toward the bottom of `Stack B`, creating a rough hourglass distribution.
3. **Greedy Reconstruction (`push_back_all`)**:
   - Once `Stack A` is empty, the algorithm repeatedly locates the maximum element in `Stack B`, rotates it to the top via the shortest direction (`rb` or `rrb`), and pushes it back to `Stack A` (`pa`).

---

## Project Structure

```text
push_swap/
├── Makefile                        # Build configuration for push_swap and libft
├── includes/
│   ├── push_swap.h                 # Core data structures and function prototypes
│   └── ft_printf.h                 # Custom printf header
├── libft/                          # Custom C standard library implementation (Libft + ft_printf)
└── src/
    ├── main.c                      # Application entry point
    ├── stack/
    │   ├── stack_init.c            # Argument parsing & stack construction
    │   ├── stack_operations.c      # Core push_swap instructions (pa, pb, sa, ra, rra, ...)
    │   ├── stack_utils.c           # Stack traversal, min/max lookup, and sorted check
    │   └── stack_free.c            # Memory deallocation & error handling
    ├── sorting/
    │   ├── sort_dispatch.c         # Strategy dispatcher based on stack size
    │   ├── sort_small.c            # Optimal routines for 2, 3, and 5 elements
    │   ├── sort_chunks.c           # Chunk initialization, partitioning, and reconstruction
    │   └── chunk_utils.c           # Bidirectional chunk search & cost evaluation
    └── utils/
        └── parse_utils.c           # Safe integer conversion (ft_atol) & duplicate detection
```

---

## Getting Started

### Prerequisites
- A C compiler (`cc`, `clang`, or `gcc`)
- `make`

### Building the Project

Clone the repository and run `make`:

```bash
git clone <your-repo-url> push_swap
cd push_swap
make
```

Available `Makefile` targets:
- `make` or `make all` — Compiles `libft` and builds the `push_swap` executable.
- `make clean` — Removes intermediate `.o` object files.
- `make fclean` — Removes object files, `libft.a`, and the `push_swap` binary.
- `make re` — Performs a full rebuild (`fclean` followed by `all`).

---

## Usage & Examples

You can pass integers either as separate arguments or as a single space-separated string:

```bash
# Separate arguments
./push_swap 4 67 3 87 23

# Single quoted string
./push_swap "4 67 3 87 23"
```

Example output for `./push_swap 3 2 1`:
```text
sa
rra
```

---

## Testing & Verification

Count the number of operations generated for **100** and **500** random integers using Python:

```bash
# Count instructions for 100 random numbers (~700 operations)
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-500, 500), 100))))"); ./push_swap $ARG | wc -l

# Count instructions for 500 random numbers (~6100 operations)
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-1000, 1000), 500))))"); ./push_swap $ARG | wc -l
```
