#ifndef CONFIG_H
#define CONFIG_H

#include <stdexcept>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <utility>

class Config
{
public:
    explicit Config(const std::string& filename);

    void add(const std::string& ident, const std::string& value);

    void createFile(const std::map< std::string, std::string >& newData);

    bool empty() const;

    std::string get(const std::string& ident) const;

    void updateFile();

private:
    std::string m_filename;

    std::map<std::string, std::string> m_data;
};

#endif // CONFIG_H
