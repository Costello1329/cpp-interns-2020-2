# H/w #1: Bucket allocator
In this task you'll have to implement a `bucket_allocator` class.

#### Problem statement
+ Class `bucket_allocator` should receive a `size_t threshold_size` via the constructor which will indicate the theshold size of buckets.
+ Copy constructor **must** be deleted with implicit `= delete` declaration.
+ Operator= **must** be deleted with implicit `= delete` declaration.
+ Destructor shouldn't do anything (you **can** use `= default` declaration for that).
+ Class `bucket_allocator` should store a `vector` of buckets as quartets of `void*`, `size_t`, `size_t` and `size_t` (adress of the bucket, it's size, amount of the allocated objects and amount of the dealocated ones). Buckets can be represented by an inner-defined struct. By default, there is no buckets, so the vector is empty.
+ You should implment method `buckets_count` which returns **current** of buckets.
+ Class `bucket_allocator` should be compatible with an `std::allocator_traits`.
+ **Allocation**. Let's suppose that user wants to allocate `n` objects. New bucket should be allocated when it is necessary.
    + If `n` is greater than `threshold_size`, you should allocate new bucket of size `n` and 'place' chunk inside of it.
    + Otherwise, you should iterate on all of the buckets (strictly in the order of their creation) and search for a place where to 'allocate' the new chunk.
        + If there is such place in some bucket, you need to 'place' the chunk there and increase `allocations_count` counter by `n`.
        + If there is no such place, you should allocate new bucket of size `threshold_size` and 'place' the chunk inside of it.
+ **Deallocation**. You should iterate on all of the buckets (strictly in the order of their creation) and find a bucket which holds a chunk of data that the user wants to deallocate. Let's suppose that user wants to allocate `n` objects. You should increase `deallocation_count` of this bucket by `n`. If new `deallocation_count` counter is now equals to buckets size – you need to deallocate the bucket and then, remove it from the `vector` of buckets.

##### Score: 10pts
