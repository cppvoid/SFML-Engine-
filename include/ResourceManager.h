#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <memory>
#include <stdexcept>
#include <utility>
#include <SFML/Graphics.hpp>

template< typename Identifier, typename Resource >
class ResourceManager
{
    public:
        ResourceManager();

        //add an resource and load it from file, the identifier is used for get function to get the right element
        void add( Identifier ident, const std::string& filename );

        //get a reference of the resource identified by identifier
        const Resource& get( Identifier ident ) const;

        //get a reference of the resource identified by identifier
        Resource& get( Identifier ident );

    private:
        std::map< Identifier, std::unique_ptr<Resource> > data;
};

#include "ResourceManager.cpp"

#endif // RESOURCEMANAGER_H
