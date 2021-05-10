#include <type_traits>
#include <iostream>



template <typename vt>
struct simple_array {
    explicit simple_array (size_t size) noexcept(std::is_nothrow_default_constructible_v<vt>):
        /// Calling the nothrow version of the new[]
        _data(reinterpret_cast<vt*>(operator new[](size, std::nothrow))),
        _size(size)
    {
        for (size_t i = 0; i < _size; i ++)
            new (_data + i) vt; /// Calling the default constructor for every object in the array
    }

    ~simple_array () noexcept(std::is_nothrow_destructible_v<vt>) {
        for (size_t i = 0; i < _size; i ++)
            (_data + i)->~vt(); /// Calling the destructor for every object in the array

        operator delete[] (_data, std::nothrow); /// Calling the nothrow version of delete[]
    }

    simple_array (const simple_array& other) noexcept(std::is_nothrow_copy_assignable_v<vt>):
        simple_array(other._size)
    {
        /// Deep copy here, takes O(_size) time.
        for (size_t i = 0; i < _size; i ++)
            _data[i] = other._data[i]; /// Calling the operator= for every object in the array
    }

    simple_array& operator= (const simple_array& other) & noexcept(
        std::is_nothrow_destructible_v<simple_array<vt>> &&
        std::is_nothrow_copy_constructible_v<simple_array<vt>>
    ) {
        if (this != &other) {
            this->~simple_array();
            new (this) simple_array(other);
        }

        return *this;
    }

    simple_array (simple_array&& other) noexcept: _data(other._data), _size(other._size) {
        other._data = nullptr;
        other._size = 0;
    }

    simple_array& operator= (simple_array&& other) & noexcept(
        std::is_nothrow_destructible_v<simple_array<vt>> &&
        std::is_nothrow_move_constructible_v<simple_array<vt>>
    ) {
        if (this != &other) {
            this->~simple_array();
            new (this) simple_array(std::move(other));
        }

        return *this;
    }

    vt& operator[] (const size_t i) noexcept { return _data[i]; }
    const vt& operator[] (const size_t i) const noexcept { return _data[i]; }

    size_t size () const { return _size; }

private:
    vt* _data;
    size_t _size;
};


int main () {
    simple_array<int> a(3);

    for (size_t i = 0; i < a.size(); i ++)
        a[i] = i + 1;


    simple_array<int> b(std::move(a));

    for (size_t i = 0; i < b.size(); i ++)
        std::cout << b[i] << " ";

    std::cout << std::endl;


    simple_array<int> c(5);
    c = std::move(b);

    for (size_t i = 0; i < c.size(); i ++)
        std::cout << c[i] << " ";

    std::cout << std::endl;

    return 0;
}
