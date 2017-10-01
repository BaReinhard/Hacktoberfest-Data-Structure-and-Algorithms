/**
  A simple hashtable in C++
  Author: PryDt
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>
#include <functional>
#include <utility>

template <class Key, class T>
class HashTable  // AKA Symbol Table or HashMap or Dictionary
{
 public:
  // constructor
  HashTable(size_t size = 13)
  {
    length = size;

    table = new std::list<std::pair<Key, T>>[length];
  }

  // destructor
  ~HashTable() { delete[] table; }

  // insert val w/ specified key
  void insert(Key key, T val)
  {
    size_t i = hash(key);

    for (auto it = table[i].begin(); it != table[i].end(); ++it)
    {
      if (std::get<0>(*it) == key)
      {
        (*it) = std::make_pair(key, val);
        return;
      }
    }
    table[i].push_front(std::make_pair(key, val));
    used++;
  }

  // delete key and value
  void remove(Key key)
  {
    size_t i = hash(key);

    if (!table[i].empty())
      for (auto it = table[i].begin(); it != table[i].end(); ++it)
      {
        if (std::get<0>(*it) == key)
        {
          it = table[i].erase(it);
          used--;
        }
      }
  }

  // search for a val w/ given key
  T get(Key key)
  {
    size_t i = hash(key);

    for (auto it = table[i].begin(); it != table[i].end(); ++it)
    {
      if (std::get<0>(*it) == key)
      {
        return std::get<1>(*it);
      }
    }
    return nullptr;
  }

  void printTable()
  {
    std::cout << "[\n";
    for (size_t i = 0; i < length; i++)
    {
      if (!table[i].empty())
      {
        for (auto it = table[i].begin();
            it != table[i].end(); ++it)
        {
          std::cout << '\t' << std::get<0>(*it)
            << "\t:\t" << std::get<1>(*it) << '\n';
        }
      }
    }
    std::cout << "]\n";
  }

  // returns true if hashtable is empty
  inline bool isEmpty() { return used == 0; }

  // returns true if hashtable
  // contains specific key
  bool contains(Key key) { return !(get(key) == nullptr); }

  // returns size of hashtable
  inline int size() { return used; }

 private:
  std::hash<Key> prehash;

  size_t length;
  size_t used;

  std::list<std::pair<Key, T>>* table;

  size_t hash(Key key) { return (prehash(key) & 0x7fffffff) % length; }
};

#endif  // HASHTABLE_H
