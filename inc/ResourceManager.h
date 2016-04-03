#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <memory>
#include <stdexcept>
#include <utility>
#include <SFML/Graphics.hpp>

template<typename Identifier, typename Resource>
class ResourceManager
{
    public:
        ResourceManager();

        void add(Identifier ident, const std::string& filename);

        const Resource& get(Identifier ident) const;

        Resource& get(Identifier ident);

    private:
        std::map<Identifier, std::unique_ptr<Resource>> m_data;
};

#include "ResourceManager.cpp"

#endif // RESOURCEMANAGER_H
