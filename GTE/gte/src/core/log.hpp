#ifndef GTE_LOG_HPP
#define GTE_LOG_HPP

#include <string>

namespace GTE
{
    void log(const std::string& tag, const std::string& message);

    void log(const std::string& tag, const std::string& message, const std::exception& error);
} // namespace GTE

#endif // !GTE_LOG_HPP
