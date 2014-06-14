#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

#include "DurationToString.h"

namespace xxx
{
    template <typename TTime = std::chrono::nanoseconds, typename TFunction>
    TTime Test(TFunction function)
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        function();

        auto endTime = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<TTime>(endTime - startTime);
    }

    template <typename TTime = std::chrono::nanoseconds, typename TFunction>
    TTime MultiTest(TFunction function, size_t numberOfRuns)
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        for (int i{ 0 }; i < numberOfRuns; ++i)
        {
            function();
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<TTime>(endTime - startTime);
    }

    template <typename TTime = std::chrono::nanoseconds, typename TFunction>
    TTime PrettyTest(TFunction function, std::string testName)
    {
        time_t now;
        struct tm * nowInfo;
        char * nowString;

        time(&now);
        nowInfo = localtime(&now);
        nowString = asctime(nowInfo);

        std::cout << nowString;
        std::cout << "Beginning test: " << testName << "." << std::endl;

        auto result = Test<TTime, TFunction>(function);

        time(&now);
        nowInfo = localtime(&now);
        nowString = asctime(nowInfo);

        std::cout << nowString;
        std::cout << "Finished test: " << testName << "." << std::endl;
        std::cout << "Runtime: " << result.count() << " " << TimeToString<TTime>() << "." << std::endl;

        return result;
    }

    template <typename TTime = std::chrono::nanoseconds, typename TFunction>
    TTime PrettyMultiTest(TFunction function, size_t numberOfRuns, std::string testName)
    {
        time_t now;
        struct tm * nowInfo;
        char * nowString;

        time(&now);
        nowInfo = localtime(&now);
        nowString = asctime(nowInfo);

        std::cout << nowString;
        std::cout << "Beginning " << numberOfRuns << " runs of test: " << testName << "." << std::endl;

        auto result = MultiTest<TTime, TFunction>(function, numberOfRuns);

        time(&now);
        nowInfo = localtime(&now);
        nowString = asctime(nowInfo);

        std::cout << nowString;
        std::cout << "Finished " << numberOfRuns << " runs of test: " << testName << "." << std::endl;
        std::cout << "Runtime: " << result.count() << " " << TimeToString<TTime>() << "." << std::endl;

        return result;
    }
}
