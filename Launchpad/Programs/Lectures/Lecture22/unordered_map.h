#ifndef Unorderd_Map
#define Unorderd_Map
#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int hash(int key)
{
    return key;
}
int hash(const string & key)
{
    int hash_value = 0;
    for(int i=0;i<key.size();i++)
    {
        hash_value = hash_value*29 + key[i];            //prime number larger than 26
    }
    return hash_value;
}

template<typename T,typename V>     //T->data,U->key
class unorderedMap                  // no need to write the assignment operator, copy constructor and destructor
{
    vector<list<pair<T,V> > > table;
    unsigned int count;

    int hash_function(const T & key) const
    {
        return hash(key)%table.size();
    }
    void rehash()
    {
        vector<list<pair<T,V> > > temp = table;
        clear();
        table.resize(2*temp.size());
        for(int i=0;i<temp.size();i++)
        {
            typename list<pair<T,V> >::iterator it = temp[i].begin();
            while(it != temp[i].end())
            {
                InsertOrUpdate(it->first,it->second);
            }
        }
    }

public:

    unorderedMap(int size=10) : count(0)
    {
        table.resize(count);
    }

    void InsertOrUpdate(const T & key,const V & value)
    {
        int index = hash_function(key);
        typename list<pair<T,V> >::iterator it = table[index].begin();          //typename should be used when making an iterator
        while(it!=table[index].end())
        {
            if((*it).first==key)
            {
                it->second = value;
                return;
            }
            it++;
        }
        pair<T,V> data(key,value);
        table[index].push_front(data);
        count++;
        if(count>table.size())
        {
            rehash();
        }
        return;
    }

    void clear()
    {
        for(int i=0;i<table.size();i++)
        {
            table[i].clear();
        }
    }

    bool empty() const
    {
        return size()==0;
    }

    int size() const
    {
        return count;
    }

    bool contains(const T & key) const
    {
        int index = hash_function(key);
        typename list<pair<T,V> >::const_iterator it = table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                return true;
            }
            it++;
        }
        return false;
    }

    const V & get(const T & key) const
    {
        int index = hash_function(key);
        typename list<pair<T,V> >::const_iterator it = table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                return it->second;
            }
            it++;
        }
        throw "There is no element with the above mentioned key in the Hash Map";
    }

    V & get(const T & key)
    {
        int index = hash_function(key);
        typename list<pair<T,V> >::iterator it = table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                return it->second;
            }
            it++;
        }
        throw "There is no element with the above mentioned key in the Hash Map";
    }

    void remove(const T & key)
    {
        int index = hash_function(key);
        typename list<pair<T,V> >::iterator it = table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                table[index].erase(it);
                return;
            }
            it++;
        }
        throw "There is no element with the above mentioned key in the Hash Map";
    }

    const V & operator[](const T & key) const
    {
        return get(key);
    }

    V & operator[](const T & key)
    {
        if(contains(key))
        {
            return get(key);
        }
        InsertOrUpdate(key,V());          //V()-> constructor is called for the given
        return(key);
    }


};



#endif // Unorderd_Map
