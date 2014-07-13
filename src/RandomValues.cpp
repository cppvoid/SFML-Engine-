#ifndef RANDOMVALUES_CPP
#define RANDOMVALUES_CPP

#include "RandomValues.h"

template< typename T >
typename std::enable_if< std::is_integral<T>::value, T>::type
randomValues::getIntegral( T minimalValue, T maximalValue )
{
    return static_cast<T> ( minimalValue + ( std::rand() % ( maximalValue - minimalValue + 1) ) );
}

template< typename T >
typename std::enable_if< std::is_floating_point<T>::value, T>::type
randomValues::getFloatingPoint( T minimalValue, T maximalValue )
{
    return minimalValue + static_cast<float>( std::rand() ) / ( static_cast <float> (RAND_MAX / ( ( maximalValue - minimalValue ) == static_cast<T>(0) ? 1 : ( maximalValue - minimalValue ) ) ) );
}

#endif //RANDOMVALUES_CPP

