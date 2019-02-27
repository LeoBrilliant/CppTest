/*
 * IterateOverTuple.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: bliu
 */

#include <tuple>
#include <utility>
#include <iostream>
#include <boost/fusion/tuple.hpp>
#include <boost/fusion/algorithm.hpp>

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
print( std::tuple<Tp...>& t )
{

}

template<std::size_t I = 0, typename...Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
print( std::tuple<Tp...>& t )
{
    std::cout << std::get<I>(t) << std::endl;
    print<I + 1, Tp...>(t);
}

struct PrintTuple
{
    template<typename T>
    void operator()( const T& t ) const
    {
        std::cout << std::boolalpha << t << std::endl;
    }
};

void IterateOverTuple()
{
    typedef std::tuple<int, float, double> TupleType;
    TupleType t = std::make_tuple(2, 3.14159F, 2345.678);

    print( t );

    typedef boost::fusion::tuple<int, std::string, bool, double> tuple_type;
    tuple_type bt{ 10, "Boost", true, 3.14 };
    boost::fusion::for_each( bt, PrintTuple{} ); // std::tuple not working here
}

/*
 * https://stackoverflow.com/questions/1198260/how-can-you-iterate-over-the-elements-of-an-stdtuple
 * https://theboostcpplibraries.com/boost.fusion
 */
