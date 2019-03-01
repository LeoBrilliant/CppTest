/*
 * IntegralConstant.cpp
 *
 *  Created on: Feb 27, 2019
 *      Author: bliu
 */

/*
 * https://stackoverflow.com/questions/20368187/when-would-i-use-stdintegral-constant-over-constexpr
 */
#include <iostream>
#include <type_traits>

template<typename T>
void use_impl( const T& t, std::false_type )
{
    std::cout << std::boolalpha << std::is_integral<T>::value << t << std::endl;
}

template<typename T>
void use_impl( const T& t, std::true_type )
{
    std::cout << std::boolalpha << std::is_integral<T>::value << t << std::endl;
}

template<typename T>
void use( const T& v )
{
    use_impl( v, typename std::is_integral<T>::type() );
}

void IntegralConstantTest()
{
    int i = 1;
    use( i );

    float f = 3.1415926F;
    use( f );
}
