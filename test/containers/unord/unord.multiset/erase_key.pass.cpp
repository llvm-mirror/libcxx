//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <unordered_set>

// template <class Value, class Hash = hash<Value>, class Pred = equal_to<Value>,
//           class Alloc = allocator<Value>>
// class unordered_multiset

// size_type erase(const key_type& k);

#include <unordered_set>
#include <string>
#include <cassert>

#include "../../min_allocator.h"

int main()
{
    {
        typedef std::unordered_multiset<int> C;
        typedef int P;
        P a[] =
        {
            P(1),
            P(2),
            P(3),
            P(4),
            P(1),
            P(2)
        };
        C c(a, a + sizeof(a)/sizeof(a[0]));
        assert(c.erase(5) == 0);
        assert(c.size() == 6);
        assert(c.count(1) == 2);
        assert(c.count(2) == 2);
        assert(c.count(3) == 1);
        assert(c.count(4) == 1);

        assert(c.erase(2) == 2);
        assert(c.size() == 4);
        assert(c.count(1) == 2);
        assert(c.count(3) == 1);
        assert(c.count(4) == 1);

        assert(c.erase(2) == 0);
        assert(c.size() == 4);
        assert(c.count(1) == 2);
        assert(c.count(3) == 1);
        assert(c.count(4) == 1);

        assert(c.erase(4) == 1);
        assert(c.size() == 3);
        assert(c.count(1) == 2);
        assert(c.count(3) == 1);

        assert(c.erase(4) == 0);
        assert(c.size() == 3);
        assert(c.count(1) == 2);
        assert(c.count(3) == 1);

        assert(c.erase(1) == 2);
        assert(c.size() == 1);
        assert(c.count(3) == 1);

        assert(c.erase(1) == 0);
        assert(c.size() == 1);
        assert(c.count(3) == 1);

        assert(c.erase(3) == 1);
        assert(c.size() == 0);

        assert(c.erase(3) == 0);
        assert(c.size() == 0);
    }
#if __cplusplus >= 201103L
    {
        typedef std::unordered_multiset<int, std::hash<int>,
                                      std::equal_to<int>, min_allocator<int>> C;
        typedef int P;
        P a[] =
        {
            P(1),
            P(2),
            P(3),
            P(4),
            P(1),
            P(2)
        };
        C c(a, a + sizeof(a)/sizeof(a[0]));
        assert(c.erase(5) == 0);
        assert(c.size() == 6);
        assert(c.count(1) == 2);
        assert(c.count(2) == 2);
        assert(c.count(3) == 1);
        assert(c.count(4) == 1);

        assert(c.erase(2) == 2);
        assert(c.size() == 4);
        assert(c.count(1) == 2);
        assert(c.count(3) == 1);
        assert(c.count(4) == 1);

        assert(c.erase(2) == 0);
        assert(c.size() == 4);
        assert(c.count(1) == 2);
        assert(c.count(3) == 1);
        assert(c.count(4) == 1);

        assert(c.erase(4) == 1);
        assert(c.size() == 3);
        assert(c.count(1) == 2);
        assert(c.count(3) == 1);

        assert(c.erase(4) == 0);
        assert(c.size() == 3);
        assert(c.count(1) == 2);
        assert(c.count(3) == 1);

        assert(c.erase(1) == 2);
        assert(c.size() == 1);
        assert(c.count(3) == 1);

        assert(c.erase(1) == 0);
        assert(c.size() == 1);
        assert(c.count(3) == 1);

        assert(c.erase(3) == 1);
        assert(c.size() == 0);

        assert(c.erase(3) == 0);
        assert(c.size() == 0);
    }
#endif
}
