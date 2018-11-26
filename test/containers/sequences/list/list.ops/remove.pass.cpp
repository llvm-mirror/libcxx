//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <list>

// void remove(const value_type& value);

#include <list>
#include <cassert>

#include "../../../min_allocator.h"

int main()
{
    {
    int a1[] = {1, 2, 3, 4};
    int a2[] = {1, 2, 4};
    std::list<int> c(a1, a1+4);
    c.remove(3);
    assert(c == std::list<int>(a2, a2+3));
    }
#if __cplusplus >= 201103L
    {
    int a1[] = {1, 2, 3, 4};
    int a2[] = {1, 2, 4};
    std::list<int, min_allocator<int>> c(a1, a1+4);
    c.remove(3);
    assert((c == std::list<int, min_allocator<int>>(a2, a2+3)));
    }
#endif
}
