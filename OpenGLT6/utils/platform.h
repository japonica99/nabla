#ifndef _UTILS_PLATFORM_H_
#define _UTILS_PLATFORM_H_

#include "platform-info.h"

#ifdef _MSC_VER

#include "platform-msc.h"

#elif defined(__GNUC__)

#include "platform-gcc.h"

#else // __GNUC__

#define FORCE_INLINE inline

#define NO_VIRTUAL_TABLE

#endif // other compilers

// Temperally nest here.

#include <type_traits>
// Mark [Trait] as true, for stl optimization
#define MARK_TRAIT_TRUE(Class, Trait)          \
	namespace std {                            \
	template<>                                 \
	struct Trait<Class> {                      \
		static constexpr bool value = true;    \
	};                                         \
	}


//
//  boost/current_function.hpp - BOOST_CURRENT_FUNCTION
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//  http://www.boost.org/libs/utility/current_function.html
//

namespace boost
{

	namespace detail
	{
		// __FUNCSIG__ must be inside a function
		inline void current_function_helper()
		{

#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600))

# define BOOST_CURRENT_FUNCTION __PRETTY_FUNCTION__

#elif defined(__DMC__) && (__DMC__ >= 0x810)

# define BOOST_CURRENT_FUNCTION __PRETTY_FUNCTION__

#elif defined(__FUNCSIG__)

# define BOOST_CURRENT_FUNCTION __FUNCSIG__

#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))

# define BOOST_CURRENT_FUNCTION __FUNCTION__

#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)

# define BOOST_CURRENT_FUNCTION __FUNC__

#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)

# define BOOST_CURRENT_FUNCTION __func__

#else

# define BOOST_CURRENT_FUNCTION "(unknown)"

#endif
		}

	} // namespace detail

} // namespace boost

#endif // !_UTILS_PLATFORM_GCC_H_
