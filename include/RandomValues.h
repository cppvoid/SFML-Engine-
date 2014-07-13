#ifndef RANDOMVALUES_H
#define RANDOMVALUES_H

#include <ctime>
#include <cstdlib>
#include <type_traits>

//need srand initialized to work!!!
namespace randomValues
{
    //return random integer value between minimal and maximal values
    template< typename T >
    typename std::enable_if< std::is_integral<T>::value, T>::type
    getIntegral( T minimalValue, T maximalValue );

    //return random floating-point value between minimal and maximal values
    template< typename T >
    typename std::enable_if< std::is_floating_point<T>::value, T>::type
    getFloatingPoint( T minimalValue, T maximalValue );
}

#include "RandomValues.cpp"

#endif // RANDOMVALUES_H
