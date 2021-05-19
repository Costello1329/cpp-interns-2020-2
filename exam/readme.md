### Exam questions

+ Memory management: raw data (definition, examples, etc). Lifecycle of the data. Allocator pattern, std::allocator.
+ Operators new/delete: difference between new/delete and new[]/delete[], nothrow operator new/delete, operator placement new. Implicit calls of constructor and destructor.
+ Function operator new/delete. Overloading functions operator new/delete (motivation & examples).
+ std::allocator_traits: motivation, examples (typedefs and methods).
+ Implementation of the simplest allocator compatible with the std::allocator_traits.
+ Custom allocation strategy: linear allocator. Motivation, properties, implementation.
+ Rvalue referecnes, std::move(...), invalidation of the initial objects after std::move(...).
+ Move constructor (signature, examples) & move assignment operator (signature, examples), default move constructor, default move assignment operator, the rule of 0/3/5.
+ Copy elision, RVO, NRVO.
+ Universal references, std::move implementation.
+ std::forward, std::forward implementation, example of usage: corrent allocator::construct method implementation.
+ Complete and incomplete types, value categories: definitions, properties, examples.
+ Reference qualifiers, example of usage (fixing bigint's operator++).
+ Noexcept specifiers in C++17 (recap), conditional noexcept specifiers in C++17, potentially throwing functions in C++17, noexcept operator in C++17.
+ std::remove_reference_t, std::is_constructible/std::is_destructible/std::is_assignable (and all others): overview, example of usage.
+ STL containers: defintion, groups (consequent, associative, adaptors): difference between them and basic properties.
+ Iterators: 5 types, properties, difference between them.
+ 
