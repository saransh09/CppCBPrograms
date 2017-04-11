

#ifndef Tries_h
#define Tries_h
#include<iostream>
#include<list>
#include<string>
#include<vector>
#include<unordered_map>
#include<cstdio>
using namespace std;

class TrieNode
{
    bool isTerminal;
    vector<TrieNode *> children;
    bool hasAChild()
    {
        for(int i=0;i<children.size();i++)
        {
            if(children[i]!=NULL)
                return true;
        }
        return false;
    }
public:
    TrieNode() : isTerminal(false)
    {
        children.resize(26,NULL);
        cout<<"called construvtor"<<endl;
        for(int i=0;i<26;i++){
            children[i] =NULL;
            cout<<children[i]<<" ";
        }
    }
    friend class Trie;
};

class Trie
{
    TrieNode * root;

public:
    Trie()
    {
        root = new TrieNode;
        cout<<"called"<<endl;
        for(int i=0;i<26;i++){
            cout<<root->children[i]<<" ";
        }
        cout<<endl;
        cout<<"printing child"<<endl;
        cout<<root->hasAChild()<<endl;
    }

    bool hasWordIter(const string & word) const
    {
        const TrieNode *it = root;
        for(int i=0;i<word.size();i++)
        {
            if(it->children[word[i]-'a']==NULL)
            {
                return false;
            }
            it = it->children[word[i]-'a'];
        }
        return it->isTerminal;
    }

    void insertWord(const string & word)
    {
        TrieNode * it = root;
        cout << word << endl;
        cout<<root->hasAChild()<<endl;
        for(int i=0;i<word.size();i++)
        {
           // cout<<it<<" "<<root<<endl;
            //cout<<i<<endl;
            //cout<<it->children[word[i]-'a']<<endl;
            cout << "Accessing " << word[i] <<endl;
            if(  it->children[word[i]-'a']==NULL )
            {
                it->children[word[i]-'a'] = new TrieNode;
                cout<<"here"<<endl;
            }
            it = it->children[word[i]-'a'];
        }
        it->isTerminal=true;
        return;
    }

    void deleteWord(const string & word)
    {
        if(word.size()==0 || root->children[word[0]-'a'] == NULL)
        {
            throw "Invalid Word";
        }
        deleteWordHelper(root,word,0);
    }

private:
    static TrieNode * deleteWordHelper(TrieNode * curr,const string & word,int index)
    {
        if(index==word.size())
        {
            if(curr->isTerminal==false)
            {
                throw "Invalid Word";
            }
            curr->isTerminal = false;
            if(curr->hasAChild())
            {
                return curr;
            }
            else
            {
                delete curr;
                return NULL;
            }
        }
        TrieNode * child = curr->children[word[index]-'a'];
        if(child==NULL)
        {
            throw "Invalid Word";
        }
        curr->children[word[index]-'a'] = deleteWordHelper(child,word,index+1);
        if(curr->isTerminal==false && curr->hasAChild()==false)
        {
            delete curr;
            return NULL;
        }
        return curr;
    }

public:



private:
//    vector<string> findAllWordsWithPrefix(string )

};
#endif // Tries_h
