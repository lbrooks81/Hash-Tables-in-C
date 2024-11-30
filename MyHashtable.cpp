#include "MyHashtable.h"

using namespace Hashtable;

template<typename TKey, typename TValue>
size_t MyHashtable<TKey, TValue>::getHashIndex(const TKey& key) const
{
    return std::hash<TKey>{}(key) % capacity;
}

template<typename TKey, typename TValue>
MyHashtable<TKey, TValue>::MyHashtable(): MyHashtable(DEFAULT_CAPACITY)
{}

template<typename TKey, typename TValue>
MyHashtable<TKey, TValue>::MyHashtable(int capacity)
{
    this->capacity = capacity;
    buckets = new std::vector<std::tuple<TKey, TValue>>[capacity];
    count = 0;
}

template<typename TKey, typename TValue>
MyHashtable<TKey, TValue>::~MyHashtable()
{
    delete[] buckets;
}

template<typename TKey, typename TValue>
TValue & MyHashtable<TKey, TValue>::operator[](TKey key)
{
    int index = getHashIndex(key);

    if(buckets[index].empty() == false)
    {
        for(int i = 0; i < buckets[index].size(); i++)
        {
            if(get<0>(buckets[index][i]) == key)
            {
                return get<1>(buckets[index][i]);
            }
        }
    }

    throw std::invalid_argument("Key does not exist in the hash table.");
}

template<typename TKey, typename TValue>
bool MyHashtable<TKey, TValue>::remove(TKey key)
{
    int index = getHashIndex(key);

    if(buckets[index].empty() == false)
    {
        for(int i = 0; i < buckets[index].size(); i++)
        {
            if(get<0>(buckets[index][i]) == key)
            {
                buckets[index].erase(buckets[index].begin() + i);
                count--;
                return true;
            }
        }
    }

    return false;
}

template <typename TKey, typename TValue>
void MyHashtable<TKey, TValue>::add(TKey key, TValue value)
{
    int index = getHashIndex(key);
    if(buckets[index].empty())
    {
        buckets[index] = std::vector<std::tuple<TKey, TValue>>();
    }

    for(int i = 0; i < buckets[index].size(); i++)
    {
        if(get<0>(buckets[index][i]) == key)
        {
            throw std::invalid_argument("Key already exists in the hash table.");
        }
    }

    buckets[index].push_back(std::tuple<TKey, TValue>(key, value));
    count++;
}

template <typename TKey, typename TValue>
void MyHashtable<TKey, TValue>::clear()
{
    delete [] buckets;
    buckets = new std::vector<std::tuple<TKey, TValue>>[capacity];
    count = 0;
}

template<typename TKey, typename TValue>
std::string MyHashtable<TKey, TValue>::toString()
{
    std::string s;


    for(int i = 0; i < capacity; i++)
    {
        if(buckets[i].empty() == false)
        {
            for(int j = 0; j < buckets[j].size(); j++)
            {
                int pos = std::to_string(get<1>(buckets[i][j])).find(".");
                s += "[" + std::to_string(i) + "] " + get<0>(buckets[i][j]) + " = " + std::to_string(get<1>(buckets[i][j])).substr(0, pos + 3) + "\n";
            }
        }
    }

    return s;
}

template<typename TKey, typename TValue>
bool MyHashtable<TKey, TValue>::containsKey(TKey key) const
{
    int index = getHashIndex(key);

    if(buckets[index].empty())
    {
        for(int i = 0; i < capacity; i++)
        {
            if(get<0>(buckets[index][i]) != key)
            {
                return true;
            }
        }
    }

    return false;
}

template<typename TKey, typename TValue>
int MyHashtable<TKey, TValue>::getCount() const
{
    return count;
}

template class MyHashtable<std::string, float>;