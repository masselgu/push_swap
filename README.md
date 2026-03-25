# Push_swap

> Sorting with Bitwise Radix Sort - Because sorting with two stacks is an art.

[![norminette](https://img.shields.io/badge/norminette-OK-brightgreen)](https://github.com/42School/norminette)
[![42](https://img.shields.io/badge/42-cursus-blue)](https://42.fr)
[![Sorting Algorithm](https://img.shields.io/badge/Algorithm-Radix%20Sort-orange)](https://en.wikipedia.org/wiki/Radix_sort)

## 📖 Introduction

The **push_swap** project is an algorithmic challenge: sort data on a stack with a limited set of instructions, using the lowest possible number of actions. This implementation utilizes a **Radix Sort** algorithm, which sorts numbers by processing individual bits rather than comparing values directly.

> **Key takeaway:** Understanding bitwise operations and stack-based sorting is crucial for optimizing sorting algorithms with limited operations.

---

## 🎯 Project Objectives

- Implement an efficient sorting algorithm using only two stacks
- Minimize the number of operations (instructions)
- Handle edge cases (duplicates, negative numbers, already sorted)
- Understand time complexity and algorithm efficiency
- **Bonus**: Create a checker program to validate sorting

---

## 🔢 The Algorithm: Radix Sort

Radix Sort is a **non-comparative sorting algorithm**. Instead of comparing `a` to `b`, it looks at the **binary representation** of the numbers and sorts them bit by bit.

### Why Radix Sort for Push_swap?

| Advantage | Explanation |
|-----------|-------------|
| **Predictable** | Consistent performance regardless of input values |
| **Bitwise operations** | Fast and efficient |
| **Easy to implement** | Clear logic with minimal edge cases |
| **Scalable** | Handles 100, 500, or more numbers consistently |


## 🛠️ Operations

| Code | Instruction | Action | Visualization |
|------|-------------|--------|---------------|
| `sa` | Swap A | Swap the top 2 elements of Stack A | `[2,1,3] → [1,2,3]` |
| `sb` | Swap B | Swap the top 2 elements of Stack B | `[2,1,3] → [1,2,3]` |
| `ss` | Swap Both | `sa` and `sb` simultaneously | `-` |
| `pa` | Push A | Move top element from B to A | `A:[1] B:[2,3] → A:[2,1] B:[3]` |
| `pb` | Push B | Move top element from A to B | `A:[2,1] B:[3] → A:[1] B:[2,3]` |
| `ra` | Rotate A | Shift A up by 1 (first becomes last) | `[1,2,3] → [2,3,1]` |
| `rb` | Rotate B | Shift B up by 1 | `[1,2,3] → [2,3,1]` |
| `rr` | Rotate Both | `ra` and `rb` simultaneously | `-` |
| `rra` | Reverse Rotate A | Shift A down by 1 (last becomes first) | `[1,2,3] → [3,1,2]` |
| `rrb` | Reverse Rotate B | Shift B down by 1 | `[1,2,3] → [3,1,2]` |
| `rrr` | Reverse Rotate Both | `rra` and `rrb` simultaneously | `-` |


## 📊 Performance Analysis

### Time Complexity

- **Radix Sort**: `O(n × k)` where `n` is the number of elements and `k` is the number of bits
- For `n` numbers, `k = log2(n)` bits needed
- Total complexity: **O(n log n)**

### Instruction Count

| Number of Elements | Average Instructions | Status |
|--------------------|---------------------|--------|
| 3 | 0 - 2 | ✅ (Hardcoded) |
| 5 | 5 - 12 | ✅ (Hardcoded) |
| 100 | ~800 - 1100 | ✅ Passes |
| 500 | ~5500 - 7000 | ✅ Passes |

## 🚀 Usage
### 📦 Compilation
```bash

# Compile mandatory push_swap
make

# Compile bonus checker
make bonus

# Clean up
make clean
make fclean

# Recompile everything
make re
```

### Performance Comparison

```bash
# 100 random numbers
./push_swap $(seq 1 100 | shuf) | wc -l

# 500 random numbers
./push_swap $(seq 1 500 | shuf) | wc -l


## 📥 Getting Started

### 🔧 Clone the Repository

To get a local copy of the project, run:

```bash
# Clone the repository
git clone https://github.com/masselgu/push_swap.git

# Navigate to the project directory
cd push_swap

# Compile the project
make
