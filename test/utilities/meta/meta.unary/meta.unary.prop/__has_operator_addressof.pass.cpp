//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// type_traits

// extension

// template <typename _Tp> struct __has_operator_addressof


#include <type_traits>

#ifndef _LIBCPP_HAS_NO_CONSTEXPR

struct A
{
};

struct B
{
    constexpr B* operator&() const;
};

struct D;

struct C
{
    template <class U>
    D operator,(U&&);
};

struct E
{
    constexpr C operator&() const;
};

#endif  // _LIBCPP_HAS_NO_CONSTEXPR

int main()
{
#ifndef _LIBCPP_HAS_NO_CONSTEXPR
    static_assert(std::__has_operator_addressof<int>::value == false, "");
    static_assert(std::__has_operator_addressof<A>::value == false, "");
    static_assert(std::__has_operator_addressof<B>::value == true, "");
    static_assert(std::__has_operator_addressof<E>::value == true, "");
#endif  // _LIBCPP_HAS_NO_CONSTEXPR
}
