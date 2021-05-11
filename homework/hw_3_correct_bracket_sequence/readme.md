# H/w correct bracket sequence

### Definition:
Let us define a regular bracket sequence in the following way: 
+ Empty string is a regular bracket sequence.
+ If `s` is a regular bracket sequence, then `(s)` is a regular bracket sequence.
+ If `s` is a regular bracket sequence, then `[s]` is a regular bracket sequence.
+ If `s` and `t` are regular bracket sequences, then `st` is a regular bracket sequence.

### Problem statement:
You are given a non-empty string that contains only 4 characters: `(`, `)`, `[`, `]`. You have to determine if this string is a valid bracket sequence or not. If so – output `YES`, otherwise – output `NO`.

### Important:
+ You are only allowed to include the `<iostream>`, `<stack>` and `<string>` headers.
+ You are allowed to create **one** instance of `string` and **one** instance of `stack<char>`. Your solution must have `O(N)` space complexity.
+ Your solution must work in linear time. In other words, your solution must have `O(N)` time
  complexity where `N` is the size of the input string.

### Examples:
+ **Input**: `[]`
  **Output**: `YES`
+ **Input**: `[()]([](()))`
  **Output**: `YES`
+ **Input**: `[)(]`
  **Output**: `NO`

#### Score
14pts

#### Deadline
End of the semester
