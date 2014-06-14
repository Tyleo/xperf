#include <algorithm>
#include <deque>
#include <map>
#include <unordered_map>
#include <vector>

#include "xperf\xperf.h"

using namespace std;
using namespace xxx;

using TKey = size_t;

template <typename TItem>
void DequeTest(vector<pair<TKey, TItem>> & items)
{
    PrettyMultiTest([&]()
    {
        deque<TItem> testContainer{};

        for (auto & item : items)
        {
            auto insertLocation = lower_bound(testContainer.begin(), testContainer.end(), item.second);
            testContainer.insert(insertLocation, item.second);
        }
    }, 10, "Deque Insert");
}

template <typename TItem>
void MapTest(vector<pair<TKey, TItem>> & items)
{
    PrettyMultiTest([&]()
    {
        map<TKey, TItem> testContainer{};

        for (auto & item : items)
        {
            testContainer.insert(item);
        }
    }, 10, "Map Insert");
}

template <typename TItem>
void UnorderedMapTest(vector<pair<TKey, TItem>> & items)
{
    PrettyMultiTest([&]()
    {
        unordered_map<TKey, TItem> testContainer{};

        for (auto & item : items)
        {
            testContainer.insert(item);
        }
    }, 10, "Unordered Map Insert");
}

template <typename TItem>
void VectorTest(vector<pair<TKey, TItem>> & items)
{
    PrettyMultiTest([&]()
    {
        vector<TItem> testContainer{};

        for (auto & item : items)
        {
            auto insertLocation = lower_bound(testContainer.begin(), testContainer.end(), item.second);
            testContainer.insert(insertLocation, item.second);
        }
    }, 10, "Vector Insert");
}

int main()
{
    vector<pair<TKey, uint32_t>> testItems{};

    for (int i = 0; i < 100000; ++i)
    {
        testItems.push_back(make_pair(i, i));
    }

    random_shuffle(testItems.begin(), testItems.end());

    //DequeTest(testItems);
    MapTest(testItems);
    UnorderedMapTest(testItems);
    VectorTest(testItems);

    char buffer;
    cin.getline(&buffer, 1);
}
