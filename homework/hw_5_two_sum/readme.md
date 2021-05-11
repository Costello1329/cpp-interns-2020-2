# H/w Two sum

You are given two arrays of integers: `a` and `b`. No number is repeated within each array, however the same number can be contained in both arrays.\
You are also given the integer `c`.\
You have to find the number of unique pairs of indices `(i, j)` such that `a[i] + b [i] = c`.

### Important:
+ You are only allowed to include the `<iostream>`, `<vector>` and `<unordered_set>` headers.
+ You are allowed to create **two** instances of `vector<int>` (exclusively for storing arrays `a` and `b`) and **one** instance of `unordered_set<int>`. Your solution must have `O(N)` space complexity.
+ Your solution must work in linear time. In other words, your solution must have `O(N)` time
  complexity where `N` is the size of the input string.

### Input data overview:
+ On the first line, you get the size of the first array (`n > 0`).
+ On the second line, you get exactly `n` numbers separated by one space (`-2^20 < a [i] < 2^20`)
+ On the third and fourth lines, by analogy with the first two, you get an array `b`.
+ On the fifth and last line, you get the number `c` (`-2^20 < c < 2^20`)

### Example:
**Input**:
```
4
1 2 3 4
3
2 3 1
4
```
Description: `a = [1, 2, 3, 4]`, `b = [2, 3, 1]`, `c = 4`\
**Output**: `3`\
Description: indices pairs `(0, 1)`, `(1, 0)`, `(2, 2)`

#### Score
18pts

#### Deadline
End of the semester
