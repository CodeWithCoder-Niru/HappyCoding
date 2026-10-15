

#include <iostream>
#include <unordered_set>   

#include <iostream>
#include <vector>
#include <list>
#include <functional>

template <typename T>
class MyUnorderedSet
{
private:
    std::vector<std::list<T>> buckets;

    std::size_t elementCount;
    std::size_t bucketCount;

    float maxLoadFactor = 0.75f;

private:
    std::size_t getBucketIndex(const T& value) const
    {
        std::size_t hashValue = std::hash<T>{}(value);

        return hashValue % bucketCount;
    }

    void rehash()
    {
        std::size_t newBucketCount = bucketCount * 2;

        std::vector<std::list<T>> newBuckets(newBucketCount);

        for (const auto& bucket : buckets)
        {
            for (const auto& value : bucket)
            {
                std::size_t hashValue = std::hash<T>{}(value);

                std::size_t newIndex =
                    hashValue % newBucketCount;

                newBuckets[newIndex].push_back(value);
            }
        }

        buckets = std::move(newBuckets);

        bucketCount = newBucketCount;
    }

public:

    MyUnorderedSet(std::size_t initialBuckets = 8)
        : buckets(initialBuckets),
          elementCount(0),
          bucketCount(initialBuckets)
    {
    }

    bool insert(const T& value)
    {
        std::size_t index = getBucketIndex(value);

        // Check duplicate
        for (const auto& element : buckets[index])
        {
            if (element == value)
            {
                return false;
            }
        }

        buckets[index].push_back(value);

        ++elementCount;

        if (loadFactor() > maxLoadFactor)
        {
            rehash();
        }

        return true;
    }

    bool contains(const T& value) const
    {
        std::size_t index = getBucketIndex(value);

        for (const auto& element : buckets[index])
        {
            if (element == value)
            {
                return true;
            }
        }

        return false;
    }

    bool erase(const T& value)
    {
        std::size_t index = getBucketIndex(value);

        auto& bucket = buckets[index];

        for (auto it = bucket.begin();
             it != bucket.end();
             ++it)
        {
            if (*it == value)
            {
                bucket.erase(it);

                --elementCount;

                return true;
            }
        }

        return false;
    }

    std::size_t size() const
    {
        return elementCount;
    }

    bool empty() const
    {
        return elementCount == 0;
    }

    float loadFactor() const
    {
        return static_cast<float>(elementCount) /
               bucketCount;
    }

    void print() const
    {
        for (std::size_t i = 0;
             i < bucketCount;
             ++i)
        {
            std::cout << "Bucket " << i << " : ";

            for (const auto& value : buckets[i])
            {
                std::cout << value << " -> ";
            }

            std::cout << "NULL\n";
        }
    }
};
int main() {
    std::unordered_set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);

    for (const auto& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}