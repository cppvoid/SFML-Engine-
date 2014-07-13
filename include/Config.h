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
    /*
    *   read the config file if exist or create a new file
    */
    explicit Config( const std::string& filename );

    /*
    *   add one item to config file
    */
    void add( const std::string& ident, const std::string& value );

    /*
    *   create or rewrite the config file
    */
    void createFile( const std::map< std::string, std::string >& newData );

    /*
    *   return true if the config file not exist or empty
    */
    bool empty() const;

    /*
    *   return the value of the identifir or throw an exception
    */
    std::string get( const std::string& ident ) const;

    /*
    *   rewrite the config file
    */
    void updateFile();

private:
    std::string filename;

    std::map< std::string, std::string > data;
};

#endif // CONFIG_H
