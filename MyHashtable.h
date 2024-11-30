#ifndef IT230_HASHTABLE_H
#define IT230_HASHTABLE_H

#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>

namespace Hashtable
{
    template<typename TKey, typename TValue>
    class MyHashtable
    {
    private:
        static const size_t DEFAULT_CAPACITY = 16;
        size_t getHashIndex(const TKey& key) const;
        std::vector<std::tuple<TKey, TValue>>* buckets;
        int capacity;
        int count;

    public:
        int bucketCount{};

        TValue & operator[](TKey key);
        MyHashtable();
        explicit MyHashtable(int capacity);
        ~MyHashtable();
        void add(TKey key, TValue value);
        bool remove(TKey key);
        void clear();
        std::string toString();
        bool containsKey(TKey key) const;
        int getCount() const;
    };

}




#endif //IT230_HASHTABLE_H
