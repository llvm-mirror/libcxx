//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator Iter1, InputIterator Iter2,
//          Predicate<auto, Iter1::value_type, Iter2::value_type> Pred>
//   requires CopyConstructible<Pred>
//   pair<Iter1, Iter2>
//   mismatch(Iter1 first1, Iter1 last1, Iter2 first2, Pred pred);

#include <algorithm>
#include <functional>
#include <cassert>

#include "test_iterators.h"

#if _LIBCPP_STD_VER > 11
#define HAS_FOUR_ITERATOR_VERSION
#endif


int main()
{
    int ia[] = {0, 1, 2, 2, 0, 1, 2, 3};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    int ib[] = {0, 1, 2, 3, 0, 1, 2, 3};
    assert(std::mismatch(input_iterator<const int*>(ia),
                         input_iterator<const int*>(ia + sa),
                         input_iterator<const int*>(ib),
                         std::equal_to<int>()) ==
                         (std::pair<input_iterator<const int*>,
                                    input_iterator<const int*> >(
                            input_iterator<const int*>(ia+3),
                            input_iterator<const int*>(ib+3))));
#ifdef HAS_FOUR_ITERATOR_VERSION
    assert(std::mismatch(input_iterator<const int*>(ia),
                         input_iterator<const int*>(ia + sa),
                         input_iterator<const int*>(ib),
                         input_iterator<const int*>(ib + sa),
                         std::equal_to<int>()) ==
                         (std::pair<input_iterator<const int*>,
                                    input_iterator<const int*> >(
                            input_iterator<const int*>(ia+3),
                            input_iterator<const int*>(ib+3))));
#endif

    assert(std::mismatch(ia, ia + sa, ib, std::equal_to<int>()) ==
           (std::pair<int*,int*>(ia+3,ib+3)));
#ifdef HAS_FOUR_ITERATOR_VERSION
    assert(std::mismatch(ia, ia + sa, ib, ib + sa, std::equal_to<int>()) ==
           (std::pair<int*,int*>(ia+3,ib+3)));
    assert(std::mismatch(ia, ia + sa, ib, ib + 2, std::equal_to<int>()) ==
           (std::pair<int*,int*>(ia+2,ib+2)));
#endif
}
