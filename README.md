# HackerRank 3rd Semester Algorithm Portfolio

## Student Profile

| Field | Details |
|---|---|
| Student Name | `[YOUR NAME]` |
| USN / Student ID | `[YOUR USN]` |
| Semester | `3rd Semester` |
| Branch | `Computer Science and Engineering` |
| HackerRank Profile | `[HACKERRANK PROFILE URL]` |
| GitHub Repository | `[GITHUB REPOSITORY URL]` |

## Introduction

This portfolio demonstrates algorithmic problem solving, C++ implementation skills, complexity analysis, and clear GitHub documentation through five foundational problems. Each solution is kept in its own folder, uses straightforward input/output, and includes an explanation of its approach and efficiency. Replace the student and evidence placeholders with your own details after completing the challenges and uploading the repository.

## Problem Summary

| No. | Problem | Topic | Time Complexity | Auxiliary Space Complexity | Status |
|---:|---|---|---|---|---|
| 1 | Mini-Max Sum | Arrays | O(N) | O(1) | Completed |
| 2 | Birthday Cake Candles | Arrays / Counting | O(N) | O(1) | Completed |
| 3 | Insertion Sort Part 1 | Sorting | O(N) worst case | O(1) | Completed |
| 4 | Binary Search | Searching | O(log N) | O(1) | Completed |
| 5 | Mark and Toys | Greedy / Sorting | O(N log N) | O(1) auxiliary* | Completed |

`N` is the number of input elements. Auxiliary space excludes the input/container that stores the values. For Mark and Toys, the greedy scan itself uses O(1) auxiliary space; `std::sort` may use O(log N) implementation stack space, excluding the input vector. Thus the full implementation's auxiliary space is O(log N) in the worst case when that sort stack is counted.

---

## 1. Mini-Max Sum

### 1. Problem Statement Summary

Given five integers, calculate the smallest and largest sums obtainable by adding exactly four of them, then print the two sums in ascending order.

### 2. Algorithm / Approach

Scan the values once while maintaining their total, minimum, and maximum. The minimum four-number sum is the total minus the maximum value; the maximum four-number sum is the total minus the minimum value.

### 3. Step-by-Step Explanation

1. Read the five values.
2. Add each value to a `long long` total.
3. Track the smallest and largest values while reading.
4. Print `total - largest` followed by `total - smallest`.

### 4. C++ Solution

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    const int count = 5;
    std::vector<long long> values(count);
    long long total = 0;

    for (long long& value : values) {
        std::cin >> value;
        total += value;
    }

    // Excluding the largest or smallest value gives the two four-item sums.
    const auto bounds = std::minmax_element(values.begin(), values.end());
    const long long minimumSum = total - *bounds.second;
    const long long maximumSum = total - *bounds.first;

    std::cout << minimumSum << ' ' << maximumSum << '\n';
    return 0;
}
```

### 5. Time Complexity

O(N), where N is the number of values (five in the HackerRank challenge).

### 6. Auxiliary Space Complexity

O(1) auxiliary space: the input vector is not counted as auxiliary space. The running total and bounds are constant-size values.

### 7. Alternative Approach

Sort the five values, then sum the first four for the minimum and the last four for the maximum. This takes O(N log N) time and is unnecessary because a scan provides the needed extremes.

### 8. Why the Selected Approach Is Efficient

It finds both extremes and the total in one pass, avoids sorting, and uses a wider integer type for sums.

### 9. HackerRank Challenge Link

[Mini-Max Sum](https://www.hackerrank.com/challenges/mini-max-sum/problem)

### 10. Accepted Submission Evidence

`[Add your actual accepted-submission URL or profile evidence here. Do not claim acceptance until you have submitted and received an accepted result.]`

---

## 2. Birthday Cake Candles

### 1. Problem Statement Summary

Given candle heights, find the tallest height and count how many candles have that height.

### 2. Algorithm / Approach

Traverse the input once. Whenever a taller candle is found, replace the current maximum and reset its count to one. When a candle equals the current maximum, increment the count.

### 3. Step-by-Step Explanation

1. Read the number of candles and the first height.
2. Initialize the tallest height and its count from the first candle.
3. For each remaining candle, update the maximum and count as appropriate.
4. Print the number of tallest candles.

### 4. C++ Solution

```cpp
#include <iostream>

int main() {
    int candleCount;
    std::cin >> candleCount;

    int tallestHeight;
    std::cin >> tallestHeight;
    int tallestCount = 1;

    for (int i = 1; i < candleCount; ++i) {
        int height;
        std::cin >> height;

        // Reset the count for a new maximum; otherwise count another tallest candle.
        if (height > tallestHeight) {
            tallestHeight = height;
            tallestCount = 1;
        } else if (height == tallestHeight) {
            ++tallestCount;
        }
    }

    std::cout << tallestCount << '\n';
    return 0;
}
```

### 5. Time Complexity

O(N), where N is the number of candles.

### 6. Auxiliary Space Complexity

O(1) auxiliary space. Heights are processed directly from input and only a fixed number of variables are retained.

### 7. Alternative Approach

Store all heights, find the maximum with a standard-library algorithm, and count its occurrences in a second pass. This uses O(N) container space and still takes O(N) time.

### 8. Why the Selected Approach Is Efficient

The single-pass solution avoids storing the array and updates the maximum count as it reads each height.

### 9. HackerRank Challenge Link

[Birthday Cake Candles](https://www.hackerrank.com/challenges/birthday-cake-candles/problem)

### 10. Accepted Submission Evidence

`[Add your actual accepted-submission URL or profile evidence here. Do not claim acceptance until you have submitted and received an accepted result.]`

---

## 3. Insertion Sort – Part 1

### 1. Problem Statement Summary

Given an array whose final element is the value to insert into the sorted prefix, shift larger elements one place to the right and print the array after every shift and after insertion.

### 2. Algorithm / Approach

Save the last element, scan the sorted prefix from right to left, and shift each larger value one position right. Insert the saved value into the resulting gap.

### 3. Step-by-Step Explanation

1. Save the final array element as the value to insert.
2. Start at the last index of the sorted prefix.
3. While the current element is larger than the saved value, shift it one place right and print the array.
4. Put the saved value in the open position and print the final array.

### 4. C++ Solution

```cpp
#include <iostream>
#include <vector>

void printArray(const std::vector<int>& values) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << values[i];
    }
    std::cout << '\n';
}

int main() {
    int size;
    std::cin >> size;

    std::vector<int> values(size);
    for (int& value : values) {
        std::cin >> value;
    }

    const int valueToInsert = values[size - 1];
    int index = size - 2;

    // Shift larger sorted-prefix values right, showing every intermediate state.
    while (index >= 0 && values[index] > valueToInsert) {
        values[index + 1] = values[index];
        printArray(values);
        --index;
    }

    values[index + 1] = valueToInsert;
    printArray(values);
    return 0;
}
```

### 5. Time Complexity

O(N) in the worst case, when every element in the sorted prefix must be shifted. The best case is O(1) shifts when the final value already belongs at the end.

### 6. Auxiliary Space Complexity

O(1) auxiliary space beyond the input array; the insertion uses a fixed number of variables.

### 7. Alternative Approach

The general insertion-sort algorithm can insert each item of an unsorted array into its sorted prefix. This specific challenge only requires the final insertion step, so sorting the entire array would do unnecessary work and would not produce the required intermediate output.

### 8. Why the Selected Approach Is Efficient

It performs only the shifts required for this insertion, uses constant extra space, and prints every intermediate state in the required order.

### 9. HackerRank Challenge Link

[Insertion Sort – Part 1](https://www.hackerrank.com/challenges/insertionsort1/problem)

### 10. Accepted Submission Evidence

`[Add your actual accepted-submission URL or profile evidence here. Do not claim acceptance until you have submitted and received an accepted result.]`

---

## 4. Binary Search

### 1. Problem Statement Summary

Given an ascending sorted array and a target value, return the target's zero-based index, or `-1` if the value is absent.

### 2. Algorithm / Approach

Use iterative binary search. At each step, inspect the middle element and discard the half of the search interval that cannot contain the target.

### 3. Step-by-Step Explanation

1. Set the search interval to the full array.
2. Compute the middle index without risking addition overflow.
3. Return the middle index if its value matches the target.
4. Otherwise narrow the interval to the appropriate half.
5. If the interval becomes empty, print `-1`.

### 4. C++ Solution

```cpp
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& values, int target) {
    // The input must be sorted in ascending order.
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;

    while (left <= right) {
        const int middle = left + (right - left) / 2;

        if (values[middle] == target) {
            return middle;
        }
        if (values[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    int size;
    int target;
    std::cin >> size >> target;

    std::vector<int> values(size);
    for (int& value : values) {
        std::cin >> value;
    }

    std::cout << binarySearch(values, target) << '\n';
    return 0;
}
```

### 5. Time Complexity

O(log N) for an array of N elements, because each comparison approximately halves the remaining search interval.

### 6. Auxiliary Space Complexity

O(1) auxiliary space. The search is iterative and uses only a fixed number of indices.

### 7. Alternative Approach

A linear scan can find the target in O(N) time and O(1) auxiliary space, but it does not take advantage of sorted input.

### 8. Why the Selected Approach Is Efficient

Each comparison eliminates about half of the remaining candidates, making it substantially faster than a linear scan for large sorted arrays.

### 9. HackerRank Challenge Link

No exact assigned HackerRank challenge was specified. This folder contains a standard, suitable binary-search implementation as an approved equivalent; replace this note with the exact assigned challenge link if one is provided.

### 10. Accepted Submission Evidence

`[Add your actual accepted-submission URL or profile evidence here, if submitted to an assigned challenge. Otherwise, document that this is the portfolio implementation.]`

---

## 5. Mark and Toys

### 1. Problem Statement Summary

Given toy prices and a budget, buy the maximum number of toys without spending more than the budget.

### 2. Algorithm / Approach

Sort prices from lowest to highest, then greedily buy each next-cheapest toy while it fits within the remaining budget.

### 3. Step-by-Step Explanation

1. Read the number of toys, budget, and prices.
2. Sort prices in ascending order.
3. Visit prices from cheapest to most expensive.
4. If the next price exceeds the remaining budget, stop; otherwise subtract it and increment the purchase count.
5. Print the count.

### 4. C++ Solution

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int toyCount;
    long long budget;
    std::cin >> toyCount >> budget;

    std::vector<long long> prices(toyCount);
    for (long long& price : prices) {
        std::cin >> price;
    }

    // The cheapest-first greedy choice maximizes how many toys fit the budget.
    std::sort(prices.begin(), prices.end());

    int purchasedCount = 0;
    for (long long price : prices) {
        if (price > budget) {
            break;
        }
        budget -= price;
        ++purchasedCount;
    }

    std::cout << purchasedCount << '\n';
    return 0;
}
```

### 5. Time Complexity

O(N log N) overall, dominated by sorting N prices. The greedy scan is O(N).

### 6. Auxiliary Space Complexity

The greedy scan uses O(1) auxiliary space. `std::sort` can use O(log N) implementation stack space; the input vector is separate from auxiliary space.

### 7. Alternative Approach

One could repeatedly search for the least expensive unpurchased toy, but doing so without sorting can take O(N²). Sorting once and scanning is simpler and faster.

### 8. Why the Selected Approach Is Efficient

Buying the cheapest available toy first maximizes the number of purchases: replacing any chosen toy with a more expensive one cannot allow more toys to fit. Sorting then makes this greedy choice easy to apply.

### 9. HackerRank Challenge Link

[Mark and Toys](https://www.hackerrank.com/challenges/mark-and-toys/problem)

### 10. Accepted Submission Evidence

`[Add your actual accepted-submission URL or profile evidence here. Do not claim acceptance until you have submitted and received an accepted result.]`

---

## Evidence

Add your own screenshots or links in the placeholders below. Do not fabricate acceptance status, badges, profile details, or submission URLs.

1. **Screenshot 1 — Mini-Max Sum accepted:** Show the HackerRank challenge result with Accepted status and enough page context to identify the challenge.
2. **Screenshot 2 — Birthday Cake Candles accepted:** Show the challenge name and Accepted result.
3. **Screenshot 3 — Insertion Sort Part 1 accepted:** Show the challenge name and Accepted result.
4. **Screenshot 4 — Binary Search accepted/implemented:** Show an Accepted result for the assigned binary-search challenge, or show this implementation and its test output if no exact HackerRank challenge was assigned.
5. **Screenshot 5 — Mark and Toys accepted:** Show the challenge name and Accepted result.
6. **Screenshot 6 — HackerRank Profile:** Show your profile name/handle and profile page.
7. **Screenshot 7 — HackerRank Badge:** Show the relevant badge(s) earned on your profile.
8. **Screenshot 8 — GitHub Repository:** Show the public repository name and the completed folder structure.

`[Add screenshot files or links here after capturing your own evidence.]`

## Reflection

Working through these five problems helped me become more comfortable turning a short problem statement into a clear algorithm and then into working C++ code. Mini-Max Sum and Birthday Cake Candles strengthened my understanding of arrays and how a single pass can keep only the information that matters. Insertion Sort Part 1 made the movement of values easier to visualize, especially because printing each shift exposes what the algorithm is doing. Mark and Toys showed me how sorting can support a greedy strategy: buying the cheapest items first gives the best chance of fitting more purchases into a fixed budget. Binary Search helped me practice using the sorted order to reduce a search range by half instead of checking every element.

I also learned to pay closer attention to Big-O complexity and auxiliary space. An approach that works on a small sample may be too slow or use unnecessary memory on larger inputs, so choosing an efficient method matters. Using `long long` where sums or budgets can grow was another useful implementation detail. Keeping each solution in its own folder and documenting its approach on GitHub makes the work easier to review, maintain, and share. These habits will be useful in future CSE projects, coding assessments, and placements, where I will need to explain not only that a solution works, but also why it is correct and efficient.

## Final Submission Checklist

- [ ] Replace `[YOUR NAME]`, `[YOUR USN]`, profile URL, and repository URL.
- [ ] Compile and test each solution using the documented input format.
- [ ] Submit the relevant challenges on HackerRank and update evidence only after seeing the actual result.
- [ ] Capture and add the eight screenshots listed in the Evidence section.
- [ ] Confirm the repository is public and its name is `HackerRank-3rdSem-Algorithm-Portfolio`.
- [ ] Confirm all five problem folders and `solution.cpp` files are present.
- [ ] Review the README and remove or complete any remaining placeholders.
