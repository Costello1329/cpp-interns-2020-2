# H/w Bucket allocator
In this task you'll have to implement a `bucket_allocator` class. Before submitting, please, read `important` section!

### Problem statement
+ Class `bucket_allocator` should receive a `size_t threshold_size` via the constructor which will indicate the theshold size of buckets. This variable should be defaulted like this `const size_t threshold_size = 1024` in order to make the class [default constructible](https://en.cppreference.com/w/cpp/named_req/DefaultConstructible).
+ Copy constructor **must** be deleted with implicit `= delete` declaration.
+ Operator= **must** be deleted with implicit `= delete` declaration.
+ Destructor shouldn't do anything (you **can** use `= default` declaration for that).
+ Class `bucket_allocator` should store a `vector` of buckets as quartets of `void*`, `size_t`, `size_t` and `size_t` (adress of the bucket, it's size, amount of the allocated objects and amount of the dealocated ones). Buckets can be represented by an inner-defined struct. By default, there is no buckets, so the vector is empty.
+ Class `bucket_allocator` should be compatible with an `std::allocator_traits`.
+ **Allocation**. Let's suppose that user wants to allocate `n` objects. New bucket should be allocated when it is necessary.
    + If `n` is greater than `threshold_size`, you should allocate new bucket of size `n` and 'place' chunk inside of it.
    + Otherwise, you should iterate on all of the buckets (strictly in the order of their creation) and search for a place where to 'allocate' the new chunk.
        + If there is such place in some bucket, you need to 'place' the chunk there and increase `allocations_count` counter by `n`.
        + If there is no such place, you should allocate new bucket of size `threshold_size` and 'place' the chunk inside of it.
+ **Deallocation**. You should iterate on all of the buckets (strictly in the order of their creation) and find a bucket which holds a chunk of data that the user wants to deallocate. Let's suppose that user wants to allocate `n` objects. You should increase `deallocation_count` of this bucket by `n`. If new `deallocation_count` counter is now equals to buckets size – you need to deallocate the bucket and then, remove it from the `vector` of buckets.

### **Important**
+ Due to some limitations of the testing program, you are allowed to allocate and deallocate memory only using the standard operator new[] and operator delete[]. It is forbidden to use malloc, or alignment operators new[]/delete[], or ordinary operators new/delete and others (otherwise the testing program will not notice your allocations and deallocations).
+ Moreover, it is forbidden to allocate memory dynamically for the needs of your allocator. This means that you should not allocate any memory other than what will be stored in buckets. Moreover, it is forbidden to store the buckets in a dynamically allocated array! Therefore, I suggest you use `std::vector` (or any other sequential container) for storing your buckets. We recommend that you create an inner `bucket` helper-class that will contain all the information it needs. So you can store buckets like this: `std::vector<bucket>`.
+ Some tests contain large input data, which makes it impossible to display them with Yandex.Contest in output logs. If you are stuck on some test and you do not see the full output data, please, try to resubmit the same code (od course with minor changes that do not affect the program, but allow you to send the code again). After resubmitting, checker will run other tests (because tests are randomly generated), so after that - enough data can fit into the output log. If even a few resubmits do not help (you are still not able to understand what exactly the error is, since you cannot see the entire log) - please write to us and send the code (in the **same** message, please!). We will run your code locally and send you the output log.
+ This tester is one of the most difficult ones that we have written, so if you find a testing mistake, feel free to write to us (even if our program accepted your wrong code by mistake). We will reward the most discerning students for finding serious bugs in our tester with extra points.

#### Score
10pts

#### Deadline
End of the semester
