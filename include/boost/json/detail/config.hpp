//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/json
//

#ifndef BOOST_JSON_DETAIL_CONFIG_HPP
#define BOOST_JSON_DETAIL_CONFIG_HPP

#include <boost/config.hpp>

#ifndef BOOST_JSON_STANDALONE
# if defined(GENERATING_DOCUMENTATION)
#  define BOOST_JSON_DECL
# elif defined(BOOST_JSON_HEADER_ONLY)
#  define BOOST_JSON_DECL  inline
# else
#  if (defined(BOOST_JSON_DYN_LINK) || defined(BOOST_ALL_DYN_LINK)) && !defined(BOOST_JSON_STATIC_LINK)
#   if defined(BOOST_JSON_SOURCE)
#    define BOOST_JSON_DECL  BOOST_SYMBOL_EXPORT
#    define BOOST_JSON_BUILD_DLL
#   else
#    define BOOST_JSON_DECL  BOOST_SYMBOL_IMPORT
#   endif
#  endif // shared lib
#  ifndef  BOOST_JSON_DECL
#   define BOOST_JSON_DECL
#  endif
#  if !defined(BOOST_JSON_SOURCE) && !defined(BOOST_ALL_NO_LIB) && !defined(BOOST_JSON_NO_LIB)
#   define BOOST_LIB_NAME boost_json
#   if defined(BOOST_ALL_DYN_LINK) || defined(BOOST_JSON_DYN_LINK)
#    define BOOST_DYN_LINK
#   endif
#   include <boost/config/auto_link.hpp>
#  endif  // auto-linking disabled
# endif
#else
# define BOOST_JSON_DECL  inline
# ifndef BOOST_JSON_HEADER_ONLY
#  error Standalone configuration requires BOOST_JSON_HEADER_ONLY
# endif
#endif

#ifndef BOOST_JSON_FORCEINLINE
# ifdef _MSC_VER
#  define BOOST_JSON_FORCEINLINE __forceinline
# else
#  define BOOST_JSON_FORCEINLINE inline
# endif
#endif

#ifndef BOOST_NO_EXCEPTIONS
# define BOOST_JSON_THROW(x) throw(x)
#else
# define BOOST_JSON_THROW(x) do{}while(0)
#endif

#define BOOST_JSON_STATIC_ASSERT( ... ) static_assert(__VA_ARGS__, #__VA_ARGS__)

// optimizations

#ifndef BOOST_JSON_NO_SSE2
# if (defined(_M_IX86) && _M_IX86_FP == 2) || \
      defined(_M_X64) || defined(__SSE2__)
#  define BOOST_JSON_USE_SSE2
# endif
#endif

// These macros are private, for tests, do not change
// them or else previously built libraries won't match.
#ifndef BOOST_JSON_MAX_OBJECT_SIZE
# define BOOST_JSON_NO_MAX_OBJECT_SIZE
# define BOOST_JSON_MAX_OBJECT_SIZE  0x7ffffffe
#endif
#ifndef BOOST_JSON_MAX_ARRAY_SIZE
# define BOOST_JSON_NO_MAX_ARRAY_SIZE
# define BOOST_JSON_MAX_ARRAY_SIZE   0x7ffffffe
#endif
#ifndef BOOST_JSON_MAX_STRING_SIZE
# define BOOST_JSON_NO_MAX_STRING_SIZE
# define BOOST_JSON_MAX_STRING_SIZE  0x7ffffffe
#endif
#ifndef BOOST_JSON_MAX_STACK_SIZE
# define BOOST_JSON_NO_MAX_STACK_SIZE
# define BOOST_JSON_MAX_STACK_SIZE  ((std::size_t)(-1))
#endif
#ifndef BOOST_JSON_PARSER_BUFFER_SIZE
# define BOOST_JSON_NO_PARSER_BUFFER_SIZE
# define BOOST_JSON_PARSER_BUFFER_SIZE 2048
#endif

namespace boost {
namespace json {

using size_type = unsigned long;

} // json
} // boost

#endif
