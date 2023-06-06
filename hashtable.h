#ifndef HashTable_h
#define HashTable_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename K, typename V> 
class HashTable {
  friend ostream &operator<<(ostream &os, const HashTable &ht) {
    for (int i = 0; i < ht.keys.size(); i++) {
      os << "[" << ht.keys[i] << "] = " << *ht.values[i] << endl;
    }
    return os;
  }

public:
  HashTable() = default;

  void put(K &key, V &value) {
    int index = this->indexOf(key);
    if (index == -1) { 
      keys.push_back(key);
      values.push_back(value);
    } else { 
      values[index] = value;
    }
  }

  bool isEmpty() { return keys.empty(); }
  bool clear() {
    if (this->isEmpty()) {
      return false;
    }
    keys.clear();
    values.clear();
    return true;
  }

  void remove(K key) {
    int indexToRemove = this->indexOf(key);
    if (indexToRemove == -1) {
      return;
    }
    keys.erase(keys.begin() + indexToRemove);
    values.erase(values.begin() + indexToRemove);
  }

  V &get(K key) {
    int index = this->indexOf(key);
    return values[index];
  }

  int indexOf(K key) {
    auto iterator = find(keys.begin(), keys.end(), key);
    if (iterator != keys.end()) {
      return iterator - keys.begin(); 
    }
    return -1; 
  }

private:
  vector<K> keys;
  vector<V> values;
};
#endif /* HashTable_h */