#include <chrono>
#include <string>

namespace xxx
{
    template <typename TTime>
    std::string TimeToString()
    {
        return "";
    }

    template <>
    std::string TimeToString<std::chrono::nanoseconds>()
    {
        return "nanoseconds";
    }

    template <>
    std::string TimeToString<std::chrono::microseconds>()
    {
        return "microseconds";
    }

    template <>
    std::string TimeToString<std::chrono::milliseconds>()
    {
        return "milliseconds";
    }

    template <>
    std::string TimeToString<std::chrono::seconds>()
    {
        return "seconds";
    }

    template <>
    std::string TimeToString<std::chrono::minutes>()
    {
        return "minutes";
    }

    template <>
    std::string TimeToString<std::chrono::hours>()
    {
        return "hours";
    }
}
