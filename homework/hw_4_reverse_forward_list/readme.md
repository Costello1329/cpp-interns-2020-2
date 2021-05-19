# H/w Reverse forward list

In this task, you have to implement the template `reverse_forward_list<vt>` class that has only one
member: `static void reverse (std::forward_list<vt>&) { ... }`.
+ Reverse method are getting provided with the forward list consisting of some `vt` objects. 
  It should reverse the list in-place. For example, if the initial list was `1-2-3-4-5`, then, 
  after the reverse, it should become `5-4-3-2-1`
  
### Important
+ You are only allowed to include the `<forward_list>` header.
+ It's prohibited to use `std::forward_list<vt>::reverse()` method.
+ You are not allowed to create another lists nor allocate/deallocate the memory on heap. In other
  words, your solution must have `O(1)` space complexity.
+ Your solution must work in linear time. In other words, your solution must have `O(N)` time
  complexity where `N` is the size of the list.

#### Score
16pts

#### Deadline
End of the semester
