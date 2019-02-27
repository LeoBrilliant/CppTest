/*
 * StaticTableGeneration.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: bliu
 */


#include <iostream>

/*
 * https://stackoverflow.com/questions/19019252/create-n-element-constexpr-array-in-c11?noredirect=1&lq=1
 */
const int ARRAY_SIZE = 5;

template <int N, int I = N - 1>
class Table : public Table<N, I - 1>
{
public:
    static const int dummy;
};

template <int N>
class Table<N, 0>
{
public:
    static const int dummy = 1;
    static int array[ N ];
};


template <int N>
class Table<N, 1>
{
public:
    static const int dummy = 1;
    static int array[ N ];
};

template <int N, int I>
// const int Table<N, I>::dummy = Table<N, 0>::array[ I ] = I * I + 0 * Table<N, I - 1>::dummy;
const int Table<N, I>::dummy = Table<N, 0>::array[ I ] = Table<N, I - 1>::dummy + Table<N, I - 2>::dummy;

template<int N>
int Table<N, 0>::array[ N ];

template class Table<ARRAY_SIZE>;

void StaticTableGeneration()
{
    const int * compilerFilledArray = Table<ARRAY_SIZE, 0>::array;

    for( int i = 0; i < ARRAY_SIZE; ++i )
    {
        std::cout << compilerFilledArray[ i ] << std::endl;
    }
}


/*
 * https://stackoverflow.com/questions/2226291/is-it-possible-to-create-and-initialize-an-array-of-values-using-template-metapr
 * looks good, but still need some further work.
 */
template <int N, int... Rest>
struct Array_impl
{
    static constexpr auto& value = Array_impl<N - 1, N, Rest...>::value;
};

template <int... Rest>
struct Array_impl<0, Rest...>
{
    static constexpr int value[] = { 0, Rest... };
};

template<int... Rest>
constexpr int Array_impl<0, Rest...>::value[];

template<int N>
struct Array
{
    static_assert( N >= 0, "N must be at least 0" );
    static constexpr auto& value = Array_impl<N>::value;

    Array() = delete;
    Array( const Array& ) = delete;
    Array( Array&& ) = delete;
};

void ArrayTest()
{
    auto & v = Array<4>::value;
    std::cout << sizeof( v ) << std::endl;
    std::cout << v[3] << std::endl;
}

template <size_t i>
struct fib
{
    static const size_t value = fib< i - 1 >::value + fib< i - 2 >::value;
};

/*
 * https://stackoverflow.com/questions/14542572/is-there-a-better-way-to-fill-array-with-precalculated-values-by-templates-for
 * This is what I am looking for a long time.
 * https://stackoverflow.com/questions/2978259/programmatically-create-static-arrays-at-compile-time-in-c/2981617#2981617
 * This is referenced by the above answer.
 */
template <>
struct fib<0>
{
    static const size_t value = 0;
};

template <>
struct fib<1>
{
    static const size_t value = 1;
};

template< unsigned... args >
struct ArrayHolder
{
    static const unsigned data[ sizeof...(args) ];
};

template< unsigned... args >
const unsigned ArrayHolder<args...>::data[ sizeof...(args) ] = { args... };

template< size_t N, template<size_t> class F, unsigned... args >
struct generate_array_impl
{
    typedef typename generate_array_impl< N - 1, F, F<N>::value, args... >::result result;
};

template < template <size_t> class F, unsigned... args >
struct generate_array_impl<0, F, args...>
{
    typedef ArrayHolder<F<0>::value, args...> result;
};

template< size_t N, template<size_t> class F>
struct generate_array
{
    typedef typename generate_array_impl< N - 1, F >::result result;
};

void FibonacciArray()
{
    const size_t count = 10;
    using fibs = generate_array<count, fib>::result;

    for( auto & i : fibs::data )
    {
        std::cout << i << std::endl;
    }
}

/*
 * https://stackoverflow.com/questions/19019252/create-n-element-constexpr-array-in-c11?noredirect=1&lq=1
 *
 */
