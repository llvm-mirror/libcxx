//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// template <class Key, class Compare = less<Key>,
//           class Allocator = allocator<Key>>
// class set
// {
// public:
//     // types:
//     typedef Key                                      key_type;
//     typedef key_type                                 value_type;
//     typedef Compare                                  key_compare;
//     typedef key_compare                              value_compare;
//     typedef Allocator                                allocator_type;
//     typedef typename allocator_type::reference       reference;
//     typedef typename allocator_type::const_reference const_reference;
//     typedef typename allocator_type::pointer         pointer;
//     typedef typename allocator_type::const_pointer   const_pointer;
//     typedef typename allocator_type::size_type       size_type;
//     typedef typename allocator_type::difference_type difference_type;
//     ...
// };

#include <set>
#include <type_traits>

#include "../../min_allocator.h"

int main()
{
    {
    static_assert((std::is_same<std::set<int>::key_type, int>::value), "");
    static_assert((std::is_same<std::set<int>::value_type, int>::value), "");
    static_assert((std::is_same<std::set<int>::key_compare, std::less<int> >::value), "");
    static_assert((std::is_same<std::set<int>::value_compare, std::less<int> >::value), "");
    static_assert((std::is_same<std::set<int>::allocator_type, std::allocator<int> >::value), "");
    static_assert((std::is_same<std::set<int>::reference, int&>::value), "");
    static_assert((std::is_same<std::set<int>::const_reference, const int&>::value), "");
    static_assert((std::is_same<std::set<int>::pointer, int*>::value), "");
    static_assert((std::is_same<std::set<int>::const_pointer, const int*>::value), "");
    static_assert((std::is_same<std::set<int>::size_type, std::size_t>::value), "");
    static_assert((std::is_same<std::set<int>::difference_type, std::ptrdiff_t>::value), "");
    }
#if __cplusplus >= 201103L
    {
    static_assert((std::is_same<std::set<int, std::less<int>, min_allocator<int>>::key_type, int>::value), "");
    static_assert((std::is_same<std::set<int, std::less<int>, min_allocator<int>>::value_type, int>::value), "");
    static_assert((std::is_same<std::set<int, std::less<int>, min_allocator<int>>::key_compare, std::less<int> >::value), "");
    static_assert((std::is_same<std::set<int, std::less<int>, min_allocator<int>>::value_compare, std::less<int> >::value), "");
    static_assert((std::is_same<std::set<int, std::less<int>, min_allocator<int>>::allocator_type, min_allocator<int> >::value), "");
    static_assert((std::is_same<std::set<int, std::less<int>, min_allocator<int>>::reference, int&>::value), "");
    static_assert((std::is_same<std::set<int, std::less<int>, min_allocator<int>>::const_reference, const int&>::value), "");
    static_assert((std::is_same<std::set<int, std::less<int>, min_allocator<int>>::pointer, min_pointer<int>>::value), "");
    static_assert((std::is_same<std::set<int, std::less<int>, min_allocator<int>>::const_pointer, min_pointer<const int>>::value), "");
    static_assert((std::is_same<std::set<int, std::less<int>, min_allocator<int>>::size_type, std::size_t>::value), "");
    static_assert((std::is_same<std::set<int, std::less<int>, min_allocator<int>>::difference_type, std::ptrdiff_t>::value), "");
    }
#endif
}
