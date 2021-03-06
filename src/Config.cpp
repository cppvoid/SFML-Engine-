#include "Config.h"

Config::Config(const std::string& filename)
    : m_filename(filename)
{
    std::ifstream file(filename);
    if(file)
    {

        std::vector<std::string> lines;
        for(std::string line; std::getline(file, line); lines.push_back(line));

        for(const auto& i : lines)
        {
            size_t pos = i.find("=");

            if(pos == std::string::npos)
                throw std::runtime_error("config: wrong syntax at " + i);

            std::string identifir(i, 0, pos);
            std::string value(i.begin() + pos +1, i.end());

            m_data.insert(std::make_pair(identifir, value));
        }
    }
    else
    {
        std::string errorMsg = "config: can`t open file ";
        throw std::runtime_error(errorMsg + filename);
    }
}

void Config::add(const std::string& ident, const std::string& value)
{
    m_data.insert(std::make_pair(ident, value));
    updateFile();
}

void Config::createFile(const std::map<std::string, std::string>& newData)
{
    m_data = newData;
    updateFile();
}

bool Config::empty() const
{
    return m_data.empty();
}

std::string Config::get(const std::string& ident) const
{
    auto pos = m_data.find(ident);

    if( pos == m_data.end() )
        throw std::runtime_error("config: " + ident + " not found");

    return pos->second;
}

void Config::updateFile()
{
    std::ofstream file(m_filename);

    if(!file)
        throw std::runtime_error("file: cant't open " + m_filename);

    for(const auto& i : m_data)
    {
        file << i.first << "=" << i.second << "\n";
    }
}
