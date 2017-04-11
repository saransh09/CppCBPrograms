#ifndef MY_UNORDERED_MAP
#define MY_UNORDERED_MAP
#include<vector>
#include<list>
using namespace std;
int hash(int key) {
    return key;
}
int hash(const string & key) {
    int hash_value = 0;
    for (int i = 0; i < key.size(); i++) {
        hash_value  = hash_value * 29 + key[i];
    }
    return hash_value;
}

template <typename T, typename V>
class MyUnorderedMap {
    vector<list<pair<T, V> > > table;
    unsigned int count;
    int myhash(const T & key) const {
        return hash(key) % table.size();
    }
    void rehash() {
        vector<list<pair<T, V> > > temp = table;
        clear();
        table.resize(2* temp.size());
        for (int i = 0; i < temp.size(); i++) {
            typename list<pair<T, V> >::iterator it = temp[i].begin();
            while (it != temp[i].end()) {
                insertOrUpdate(it->first, it->second);
                it++;
            }
        }
    }
    public:
    MyUnorderedMap(int size = 10) : count(0) {
        table.resize(size);
    }
    void clear() {
        for (int i = 0; i < table.size(); i++) {
            table[i].clear();
        }
        count = 0;
    }
    bool empty() const {
        return size() == 0;
    }
    int size() const {
        return count;
    }


    void insertOrUpdate(const T & key, const V & value) {
        int index = myhash(key);
        typename list<pair<T,V> >::iterator it = table[index].begin();
        while (it != table[index].end()) {
            if ((*it).first == key) {
                it->second = value;
                return;
            }
            it++;
        }
        pair<T, V> data(key, value);
        table[index].push_front(data);
        count++;
        if (count > table.size()) {
            rehash();
        }
        return;
    }

    bool contains(const T & key) const {
        int index = myhash(key);
        typename list<pair<T,V> >::const_iterator it = table[index].begin();
        while (it != table[index].end()) {
            if ((*it).first == key) {
                return true;
            }
            it++;
        }
        return false;
    }
    
    // Throw error in all the below methods if it doesn't exist
    const V & get(const T & key) const {
        int index = myhash(key);
        typename list<pair<T,V> >::const_iterator it = table[index].begin();
        while (it != table[index].end()) {
            if ((*it).first == key) {
                return it->second;
            }
            it++;
        }
        throw "Key doesn't exist";
    }
    V & get(const T & key)  {
        int index = myhash(key);
        typename list<pair<T,V> >::iterator it = table[index].begin();
        while (it != table[index].end()) {
            if ((*it).first == key) {
                return it->second
            }
            it++;
        }
        throw "key doesn't exist";
    }
    void remove(const T & key) {
        int index = myhash(key);
        typename list<pair<T,V> >::iterator it = table[index].begin();
        while (it != table[index].end()) {
            if ((*it).first == key) {
                table[index].erase(it);
                return;
            }
            it++;
        }
        throw "key doesn't exist";
    }
    const V & operator[](const T & key) const {
        return get(key)
    }
    V & operator[](const T & key) {
        if (contains(key)) {
            return get(key);
        }
        insertOrUpdate(key, V());
        return get(key);
    }
};
#endif
