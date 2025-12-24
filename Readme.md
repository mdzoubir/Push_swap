*This project has been created as part of the 42 curriculum by [mzoubir].*

# Push Swap

## Description

Push Swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations and the smallest number of moves possible. The program uses two stacks (stack A and stack B) and a specific set of operations to sort the numbers in ascending order on stack A.

The goal is to implement an efficient sorting algorithm that can handle various data set sizes while minimizing the number of operations. This project teaches algorithm optimization, complexity analysis, and problem-solving with constraints.

**Key objectives:**
- Sort integers using only predefined stack operations
- Optimize for the minimum number of moves
- Handle edge cases and various data set sizes
- Understand algorithmic complexity and efficiency

## Instructions

### Compilation

To compile the project, run:

```bash
make
```

This will generate the `push_swap` executable.

Additional make rules:
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Recompile the entire project

### Usage

```bash
./push_swap [list of integers]
```

**Example:**
```bash
./push_swap 3 2 5 1 4
```

The program outputs the series of operations needed to sort the stack.

### Available Operations

- `sa` - Swap the first two elements of stack A
- `sb` - Swap the first two elements of stack B
- `ss` - Execute sa and sb simultaneously
- `pa` - Push the top element of stack B to stack A
- `pb` - Push the top element of stack A to stack B
- `ra` - Rotate stack A (shift all elements up by one)
- `rb` - Rotate stack B (shift all elements up by one)
- `rr` - Execute ra and rb simultaneously
- `rra` - Reverse rotate stack A (shift all elements down by one)
- `rrb` - Reverse rotate stack B (shift all elements down by one)
- `rrr` - Execute rra and rrb simultaneously

### Checker (Optional)

If you've implemented a checker program:

```bash
./push_swap [numbers] | ./checker [numbers]
```

The checker validates whether the operations correctly sort the stack.

## Algorithm Overview

The implementation typically uses different strategies based on stack size:

- **Small stacks (≤3 elements)**: Hardcoded optimal solutions
- **Medium stacks (4-5 elements)**: Specific algorithm with minimal moves
- **Large stacks (>5 elements)**: Efficient sorting algorithm (e.g., chunk-based, Turkish algorithm, or optimized quicksort adaptation)

The choice of algorithm significantly impacts the number of operations and overall performance.

## Performance Benchmarks

Typical operation counts for a well-optimized solution:

- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations (target: < 900 for full points)
- 500 numbers: ≤ 5500 operations (target: < 7000 for full points)

## Resources

### Documentation & Tutorials
- [Visualizer for Push Swap](https://github.com/o-reo/push_swap_visualizer)
- [Sorting Algorithms Complexity](https://www.bigocheatsheet.com/)
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

### Algorithm Resources
- Introduction to Algorithms (CLRS) - Chapters on sorting
- Turkish Algorithm explanation for Push Swap optimization
- Radix Sort and its application to push swap

### AI Usage

AI tools were used in this project for the following purposes:

- **Code debugging**: Identifying logic errors and memory leaks
- **Algorithm optimization**: Exploring different sorting strategies and their trade-offs
- **Documentation**: Structuring this README and clarifying technical explanations
- **Edge case identification**: Generating test cases and corner scenarios

**Specifics:**
- AI was consulted to understand the Turkish algorithm concept and its application
- Used for refactoring code sections to improve readability
- Assisted in writing comprehensive error handling for input validation
- The core sorting logic and implementation were developed independently with AI serving as a learning aid and debugging assistant


## Testing

Test your program with various inputs:

```bash
# Test with random numbers
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Test with reverse sorted
ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker $ARG

# Stress test with 100 numbers
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

---

**Author**: [mzoubir]  
**42 School Project** - December 2024