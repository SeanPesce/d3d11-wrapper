// Read an INI file into easy-to-access name/value pairs.

// inih and INIReader are released under the New BSD license (see LICENSE.txt).
// Go to the project home page for more info:
//
// https://github.com/benhoyt/inih

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include "../ini.h"
#include "INIReader.h"

using std::string;

// Extendable value-getter function
template <typename T>
T INIReader::Get(const std::string& section, const std::string& name, const T& default_value) const
{
    return default_value;
}

template <typename T>
T INIReader::Get(const std::string& section, const std::string& name) const
{
    T result;
    return result;
}

template <>
std::string INIReader::Get<std::string>(const std::string& section, const std::string& name, const std::string& default_value) const
{
    std::string key = MakeKey(section, name);
    // Use _values.find() here instead of _values.at() to support pre C++11 compilers
    return _values.count(key) ? _values.find(key)->second : default_value;
}


template <>
long INIReader::Get<long>(const std::string& section, const std::string& name, const long& default_value) const
{
    return this->GetInteger(section, name, default_value);
}

template <>
long INIReader::Get<long>(const std::string& section, const std::string& name) const
{
    return this->GetInteger(section, name, 0L);
}

template <>
int INIReader::Get<int>(const std::string& section, const std::string& name, const int& default_value) const
{
    return static_cast<int>(this->GetInteger(section, name, default_value));
}

template <>
int INIReader::Get<int>(const std::string& section, const std::string& name) const
{
    return static_cast<int>(this->GetInteger(section, name, 0L));
}

template <>
short INIReader::Get<short>(const std::string& section, const std::string& name, const short& default_value) const
{
    return static_cast<short>(this->GetInteger(section, name, default_value));
}

template <>
short INIReader::Get<short>(const std::string& section, const std::string& name) const
{
    return static_cast<short>(this->GetInteger(section, name, 0L));
}

template <>
double INIReader::Get<double>(const std::string& section, const std::string& name, const double& default_value) const
{
    return this->GetReal(section, name, default_value);
}

template <>
double INIReader::Get<double>(const std::string& section, const std::string& name) const
{
    return this->GetReal(section, name, 0.0);
}

template <>
float INIReader::Get<float>(const std::string& section, const std::string& name, const float& default_value) const
{
    return static_cast<float>(this->GetReal(section, name, default_value));
}

template <>
float INIReader::Get<float>(const std::string& section, const std::string& name) const
{
    return static_cast<float>(this->GetReal(section, name, 0.0));
}

template <>
bool INIReader::Get<bool>(const std::string& section, const std::string& name, const bool& default_value) const
{
    return this->GetBoolean(section, name, default_value);
}

template <>
bool INIReader::Get<bool>(const std::string& section, const std::string& name) const
{
    return this->GetBoolean(section, name, false);
}

template <>
uint8_t INIReader::Get<uint8_t>(const std::string& section, const std::string& name, const uint8_t& default_value) const
{
    return this->GetVkCode(section, name, default_value);
}

template <>
uint8_t INIReader::Get<uint8_t>(const std::string& section, const std::string& name) const
{
    return this->GetVkCode(section, name, 0);
}

INIReader::INIReader(const string& filename)
{
    _error = ini_parse(filename.c_str(), ValueHandler, this);
}

int INIReader::ParseError() const
{
    return _error;
}

long INIReader::GetInteger(const string& section, const string& name, long default_value) const
{
    string valstr = Get<std::string>(section, name, "");
    const char* value = valstr.c_str();
    char* end;
    // This parses "1234" (decimal) and also "0x4D2" (hex)
    long n = strtol(value, &end, 0);
    return end > value ? n : default_value;
}

double INIReader::GetReal(const string& section, const string& name, double default_value) const
{
    string valstr = Get<std::string>(section, name, "");
    const char* value = valstr.c_str();
    char* end;
    double n = strtod(value, &end);
    return end > value ? n : default_value;
}

bool INIReader::GetBoolean(const string& section, const string& name, bool default_value) const
{
    string valstr = Get<std::string>(section, name, "");
    // Convert to lower case to make string comparisons case-insensitive
    std::transform(valstr.begin(), valstr.end(), valstr.begin(), ::tolower);
    if (valstr == "true" || valstr == "yes" || valstr == "on" || valstr == "1")
        return true;
    else if (valstr == "false" || valstr == "no" || valstr == "off" || valstr == "0")
        return false;
    else
        return default_value;
}

uint8_t INIReader::GetVkCode(const string& section, const string& name, uint8_t default_value) const
{
    string valstr = Get<std::string>(section, name, "0");
    unsigned short vk_code = default_value;
    std::stringstream in;
    in << std::hex << valstr;
    in >> vk_code;
    return static_cast<uint8_t>(vk_code);
}

string INIReader::MakeKey(const string& section, const string& name)
{
    string key = section + "=" + name;
    // Convert to lower case to make section/name lookups case-insensitive
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);
    return key;
}

int INIReader::ValueHandler(void* user, const char* section, const char* name,
                            const char* value)
{
    INIReader* reader = (INIReader*)user;
    string key = MakeKey(section, name);
    if (reader->_values[key].size() > 0)
        reader->_values[key] += "\n";
    reader->_values[key] += value;
    return 1;
}
