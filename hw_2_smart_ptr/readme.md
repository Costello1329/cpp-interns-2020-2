# H/w Smart pointer
In this task you'll have to implement a `smart_ptr` class. Before submitting, please, read `important` section! Also, please, watch the video description about this h/w before reading the problem statement!

### Problem statement
+ `smart_ptr<vt>` is a template class. `vt` type is guaranteed to be **default constructible** and **destructible** type.
+ `smart_ptr` class violates the single responsibility pronciple and has two responsibilities:
    + `smart_ptr<vt>` class should wrap a raw pointer to an instance of type `vt`
    + `smart_pointer<vt>` class must own a resource of type `vt`.
+ `smart_ptr<vt>` should have only one private member field: raw pointer to vt: `vt* _ptr`.
+ Rule of 5 should be followed:
    + The default constructor of `smart_ptr` should allocate the storage for the object of type `vt` and then call the default constructor of `vt` on it. Pointer to the allocated storage should be stored into the `_ptr` variable.
    + Destructor of `smart_ptr` should destruct the object owned by the `smart_ptr` instance and then, deallocate the previously allocated storage. Don't forget that object may be invalid at the time when destructor is called.
    + Copy constructor and copy assignment operator must be explicitly deleted.
    + Move constructor should be implemented. It should steal the pointer from the other `smart_ptr`.
    + Move assignment operator should be implemented. It should steal the pointer from the other `smart_ptr`. Also, don't forget to correctly handle such cases: `a = std::move(a);`
+ Next methods  should be supported:
    + Method `get`, which returnes the raw pointer.
    + `operator ->`, which does the same.
    + `operator *`, which returns a reference to the object owned by the `smart_ptr` instance.
    + All of the methods above should be const because they doesn't change the pointer itself.
+ All constuctors, destructors, operators and methods should be provided with correct noexcept-specifications (conditional or non-conditional ones).
    + For example, method `get` just returnes the raw pointer, so it definitely won't throw any exepltion, so it should be marked `noexcept`.
    + Another example: in the case when the provided type `vt` is not **noexcept destructible** (i.e has destructor with `noexcept(false)` specification), the destructor of `smart_ptr` is not noexcept too!
+ You should only use non-array nothrow operators new and delete for allocating and deallocating the memory.

### **Important**
+ **Hint**: in this task you should use some useful type definitions from <type\_traits> header: `is_nothrow_default_constructible_v` and `is_nothrow_destructible_v`. Furthermore, just to make things easier for you, it's **prohibited** to use any other type definitions of this family (for example: `is_constructible`, `is_nothrow_move_assignable`, ...). Also, don't use structure `is_nothrow_default_constructible` and structure `is_nothrow_destructible`, use `is_nothrow_default_constructible_v` and `is_nothrow_destructible_v`.
+ Solution of this task contains around 30 lines of code, so, please, don't overdo.
+ In order to implement move assignment operator, you can (but don't have to) use almost the same code I showed you at about `28:32` in [this](https://www.youtube.com/watch?v=3Yd8a1DEuVU&t=1716s) video. You just have to make one simple improvment in order to call the move constructor instead of the copy constructor (hint: use `std::move(...)`).
+ This is not a hard task, however, it's quite tricky, so don't be ashamed to ask help in the chat if you'll have any trouble.

#### Score
12pts

#### Deadline
End of the semester
