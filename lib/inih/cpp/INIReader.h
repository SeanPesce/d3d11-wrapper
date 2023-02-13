// Read an INI file into easy-to-access name/value pairs.

// inih and INIReader are released under the New BSD license (see LICENSE.txt).
// Go to the project home page for more info:
//
// https://github.com/benhoyt/inih

#ifndef __INIREADER_H__
#define __INIREADER_H__

#ifndef __cplusplus
#define __cplusplus
#endif

#include <map>
#include <string>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#endif

// Read an INI file into easy-to-access name/value pairs. (Note that I've gone
// for simplicity here rather than speed, but it should be pretty decent.)
class INIReader
{
public:
    // Construct INIReader and parse given filename. See ini.h for more info
    // about the parsing.
    INIReader(const std::string& filename);

    // Return the result of ini_parse(), i.e., 0 on success, line number of
    // first error on parse error, or -1 on file open error.
    int ParseError() const;

    // Extendable value-getter function
    template <typename T>
    T Get(const std::string& section, const std::string& name) const;
    template <typename T>
    T Get(const std::string& section, const std::string& name, const T& default_value) const;

    // Get a string value from INI file, returning default_value if not found.
    template <>
    std::string Get<std::string>(const std::string& section, const std::string& name, const std::string& default_value) const;
    template <>
    std::string Get<std::string>(const std::string& section, const std::string& name) const;

    // Get an integer (long) value from INI file, returning default_value if
    // not found or not a valid integer (decimal "1234", "-1234", or hex "0x4d2").
    long GetInteger(const std::string& section, const std::string& name, long default_value) const;
    template <>
    long Get<long>(const std::string& section, const std::string& name, const long& default_value) const;
    template <>
    long Get<long>(const std::string& section, const std::string& name) const;

    template <>
    int Get<int>(const std::string& section, const std::string& name, const int& default_value) const;
    template <>
    int Get<int>(const std::string& section, const std::string& name) const;

    template <>
    short Get<short>(const std::string& section, const std::string& name, const short& default_value) const;
    template <>
    short Get<short>(const std::string& section, const std::string& name) const;

    // Get a real (floating point double) value from INI file, returning
    // default_value if not found or not a valid floating point value
    // according to strtod().
    double GetReal(const std::string& section, const std::string& name, double default_value) const;
    template <>
    double Get<double>(const std::string& section, const std::string& name, const double& default_value) const;
    template <>
    double Get<double>(const std::string& section, const std::string& name) const;

    template <>
    float Get<float>(const std::string& section, const std::string& name, const float& default_value) const;
    template <>
    float Get<float>(const std::string& section, const std::string& name) const;

    // Get a boolean value from INI file, returning default_value if not found or if
    // not a valid true/false value. Valid true values are "true", "yes", "on", "1",
    // and valid false values are "false", "no", "off", "0" (not case sensitive).
    bool GetBoolean(const std::string& section, const std::string& name, bool default_value) const;
    template <>
    bool Get<bool>(const std::string& section, const std::string& name, const bool& default_value) const;
    template <>
    bool Get<bool>(const std::string& section, const std::string& name) const;

    // Get a virtual-key code value from INI file, returning 0 if not found or if
    // not a valid hex-formatted byte value. Valid values are 0 to FF (not case
    // sensitive). More info on virtual-key codes here:
    //   https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
    uint8_t GetVkCode(const std::string& section, const std::string& name, uint8_t default_value = 0) const;
    template <>
    uint8_t Get<uint8_t>(const std::string& section, const std::string& name, const uint8_t& default_value) const;
    template <>
    uint8_t Get<uint8_t>(const std::string& section, const std::string& name) const;

private:
    int _error;
    std::map<std::string, std::string> _values;
    static std::string MakeKey(const std::string& section, const std::string& name);
    static int ValueHandler(void* user, const char* section, const char* name,
                            const char* value);
};


#endif  // __INIREADER_H__
