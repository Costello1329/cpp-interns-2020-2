### Exam questions

1.  Memory management: raw data (definition, examples, etc). Lifecycle of the data. Allocator pattern, std::allocator.
2.  Operators new/delete: difference between new/delete and new[]/delete[], nothrow operator new/delete, operator placement new. Implicit calls of constructor and destructor.
3.  Function operator new/delete. Overloading functions operator new/delete (motivation & examples).
4.  std::allocator_traits: motivation, examples (typedefs and methods).
5.  Implementation of the simplest allocator compatible with the std::allocator_traits.
6.  Custom allocation strategy: linear allocator. Motivation, properties, implementation.
7.  Rvalue referecnes, std::move(...), invalidation of the initial objects after std::move(...).
8.  Move constructor (signature, examples) & move assignment operator (signature, examples), default move constructor, default move assignment operator, the rule of 0/3/5.
9.  Copy elision, RVO, NRVO.
10. Universal references, std::move implementation.
11. std::forward, std::forward implementation, example of usage: corrent allocator::construct method implementation.
12. Complete and incomplete types, value categories: definitions, properties, examples.
13. Reference qualifiers, example of usage (fixing bigint's operator++).
14. Noexcept specifiers in C++17 (recap), conditional noexcept specifiers in C++17, potentially throwing functions in C++17, noexcept operator in C++17.
15. std::remove_reference_t, std::is_constructible/std::is_destructible/std::is_assignable (and all others): overview, example of usage.
16. STL containers: defintion, groups (consequent, associative, adaptors): difference between them and basic properties.
17. Iterators: 5 types, properties, difference between them.
