# SortMetrics

### Sorting Algorithm Analysis and Comparison System in C

---

## Overview

**SortMetrics** is a C-based sorting analysis project that implements and compares two fundamental sorting algorithms: Merge Sort and Quick Sort.

The project sorts an initial dataset using both algorithms, counts the element comparisons performed during sorting, and displays their respective results.

It also provides an efficient merging feature that combines the previously sorted dataset with an additional sorted batch without sorting the entire collection again.

The program uses file handling to read input data from an external text file.

## Key Features

- **Merge Sort:** Sorts elements using the divide-and-conquer approach.
- **Quick Sort:** Sorts elements using partitioning and a pivot-based strategy.
- **Comparison Counting:** Tracks the number of element comparisons performed by both sorting algorithms.
- **Sorted Batch Merging:** Combines two sorted arrays into one sorted array.
- **Performance Analysis:** Displays comparison counts to help analyze sorting behavior.
- **File Handling:** Reads datasets from an external `input.txt` file.
- **Independent Sorting:** Uses separate arrays to ensure both algorithms process the same original dataset.

## Algorithms & Techniques

| Algorithm / Technique | Purpose |
|---|---|
| Merge Sort | Divide-and-conquer sorting |
| Quick Sort | Pivot-based sorting |
| Partitioning | Divides elements around a pivot |
| Two-Pointer Merging | Combines two sorted arrays |
| File Handling | Reads input from a text file |
| Arrays | Stores and processes datasets |

## Complexity Analysis

The following table represents the theoretical complexity of the implemented algorithms.

| Algorithm / Operation | Best Case | Average Case | Worst Case |
|---|---:|---:|---:|
| Merge Sort | \(O(n\log n)\) | \(O(n\log n)\) | \(O(n\log n)\) |
| Quick Sort | \(O(n\log n)\) | \(O(n\log n)\) | \(O(n^2)\) |
| Sorted Batch Merging | \(O(n+m)\) | \(O(n+m)\) | \(O(n+m)\) |

### Space Complexity

| Algorithm / Operation | Auxiliary Space |
|---|---:|
| Merge Sort | \(O(n)\) |
| Quick Sort | \(O(n)\) worst-case recursion stack |
| Sorted Batch Merging | \(O(n+m)\) for result array |

**Where:**

- \(n\) = Number of elements in the original dataset.
- \(m\) = Number of elements in the additional sorted batch.

*Note: Quick Sort uses the last element as its pivot. Its performance depends on the input arrangement. The additional arrays used by the program also require memory.*

## Comparison Counting

The project tracks element comparisons using two independent counters:

| Counter | What It Measures |
|---|---|
| `mergeComparisons` | Comparisons between elements in the two halves during Merge Sort |
| `quickComparisons` | Comparisons between array elements and the pivot during Quick Sort |

**Important:** These counters measure specific element comparisons, not every operation performed by the algorithms.

The comparisons performed during the final sorted batch merging are not included in either counter.

## Running Time Analysis

| Execution Stage | Operation |
|---|---|
| Stage 1 | Read input data from `input.txt` |
| Stage 2 | Create separate arrays for both algorithms |
| Stage 3 | Sort the first array using Merge Sort |
| Stage 4 | Sort the second array using Quick Sort |
| Stage 5 | Display both sorted arrays |
| Stage 6 | Display comparison counts |
| Stage 7 | Merge the original sorted array with the additional sorted batch |
| Stage 8 | Display the updated sorted array |

**Actual Running Time:** The current program counts element comparisons but does not measure execution time in seconds or milliseconds.

## Project Structure

```text
SortMetrics/
│
├── main.c
├── input.txt
└── README.md
```

## Input Format

The program reads input from `input.txt`.

### Sample Input

```text
8 4
7 2 9 1 5 3 4 6
0 2 8 10
```

### Input Explanation

| Input | Description |
|---|---|
| First number | Size of the original array |
| Second number | Size of the additional sorted batch |
| Second line | Original unsorted dataset |
| Third line | Additional dataset, already sorted in ascending order |

**Example:**

- Original array size: 8
- Additional batch size: 4
- Original dataset: `7 2 9 1 5 3 4 6`
- Additional sorted batch: `0 2 8 10

## Sample Output

```text
Merge Sort: 1 2 3 4 5 6 7 9
Quick Sort: 1 2 3 4 5 6 7 9
Merge Comparisons: 16
Quick Comparisons: 15
Updated Array: 0 1 2 2 3 4 5 6 7 8 9 10
```

*Comparison counts are based on the implementation's counting logic.*

## Installation & Execution

### Prerequisites

- C Compiler (GCC recommended)
- C99 compatible compiler
- Code editor or IDE

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/SortMetrics.git
```

### 2. Navigate to the Project Directory

```bash
cd SortMetrics
```

### 3. Compile the Program

```bash
gcc main.c -o sort -std=c99
```

### 4. Run the Program

**Windows:**

```bash
sort.exe
```

**Linux / macOS:**

```bash
./sort
```

Make sure `input.txt` is available in the program's working directory.

## Technical Specifications

| Specification | Details |
|---|---|
| Project Name | SortMetrics |
| Programming Language | C |
| Language Standard | C99 |
| Sorting Algorithms | Merge Sort and Quick Sort |
| Input Method | File Handling |
| Data Structure | Arrays |
| Comparison Counter | `long long` |
| Sorting Order | Ascending |

## Learning Objectives

- Understand the divide-and-conquer approach.
- Explore how Merge Sort and Quick Sort operate.
- Analyze the comparison behavior of sorting algorithms.
- Understand pivot selection and partitioning.
- Learn how to merge two already sorted datasets efficiently.
- Apply algorithmic concepts through practical C programming.

## Limitations & Assumptions

- Input data must follow the specified file format.
- The additional batch must already be sorted in ascending order.
- Quick Sort uses the last element as its pivot.
- Comparison counters track only the comparisons explicitly defined in the code.
- Actual execution time is not measured.
- Input sizes and file-reading operations are not fully validated.

## Future Improvements

- Add actual execution-time measurement.
- Support larger datasets with dynamic memory allocation.
- Improve Quick Sort pivot selection.
- Add input validation and error handling.
- Compare sorting performance across different input arrangements.
- Include additional sorting algorithms for comparison.
