
// Copyright (c) 2010-2018 niXman (i dot nixman dog gmail dot com). All
// rights reserved.
//
// This file is part of YAS(https://github.com/niXman/yas) project.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//
//
// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef __yas__detail__type_traits__fnv1a_hpp
#define __yas__detail__type_traits__fnv1a_hpp

#include <cstdint>

namespace yas {
namespace detail {

/***************************************************************************/

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4307)
#endif

constexpr std::uint32_t fnv1a(std::nullptr_t) { return 0; }

#if __cplusplus >= 201402L

template<typename CharT>
constexpr std::uint32_t fnv1a(const CharT *s) {
    std::uint32_t seed = 0x811c9dc5;
    for ( ; *s; ++s ) {
        seed = ((seed ^ (*s)) * 0x01000193);
    }

    return seed;
}

#else

template<typename CharT>
constexpr std::uint32_t fnv1a(const CharT *s, std::uint32_t h = 0x811c9dc5) {
    return (*s == 0) ? h : fnv1a(s+1, ((h ^ (*s)) * 0x01000193));
}

#endif // __cplusplus >= 201402L

#ifdef _MSC_VER
#pragma warning(pop)
#endif

/***************************************************************************/

} // ns detail
} // ns yas

#endif // __yas__detail__type_traits__fnv1a_hpp
