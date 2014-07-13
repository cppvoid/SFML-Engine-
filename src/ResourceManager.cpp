#ifndef RESOURCEMANAGER_CPP
#define RESOURCEMANAGER_CPP

#include "ResourceManager.h"

template< typename Identifier, typename Resource >
ResourceManager< Identifier, Resource >::ResourceManager()
{
}

template< typename Identifier, typename Resource >
void ResourceManager< Identifier, Resource >::add( Identifier ident, const std::string& filename )
{
    std::unique_ptr< Resource > ptr( new Resource() );
    if( ! ptr->loadFromFile( std::move( filename ) ) )
    {
        std::string errorMsg("resource-manager: can`t load file ");
        throw std::runtime_error( errorMsg + filename );
    }
    data.insert( std::make_pair( ident, std::move( ptr ) ) );
}

template< typename Identifier, typename Resource >
const Resource& ResourceManager< Identifier, Resource >::get( Identifier ident ) const
{
    auto pos = data.find( ident );
    if( pos == data.end() )
    {
        throw std::logic_error("resource-manager: identifier not found in data");
    }
    return *pos->second;
}

template< typename Identifier, typename Resource >
Resource& ResourceManager< Identifier, Resource >::get( Identifier ident )
{
    return const_cast<Resource&>( static_cast<ResourceManager const*>(this)->get( ident ) );
}

#endif //RESOURCEMANAGER_CPP
