#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include <numeric>
#include <algorithm>
#include <queue>
#include <limits>
#include <climits> 
#include <map>

using namespace std;

//Geeks for Geeks type Implementation
class trieNodeGFG
{
public:
    bool isEndOfWord;
    unordered_map<char, trieNodeGFG*> children;
};

class trieGFG
{
public:
    trieNodeGFG* root;

    //constructor
    trieGFG()
    {
        this->root = getNode();
    }

    //a wrapper to get new node
    trieNodeGFG* getNode()
    {
        trieNodeGFG* node = new trieNodeGFG();
        return node;
    };

    //insert the key
    void insert(string key)
    {
        trieNodeGFG* running_node = this->root;
        for(int i=0; i<key.size(); i++)
        {
            char curr_char = key[i];
            if(running_node->children.find(curr_char) == running_node->children.end())
                running_node->children[curr_char] = getNode();
            running_node = running_node->children[curr_char];
        }

        running_node->isEndOfWord = true;
        cout << "Inserted " << key << endl;
        return;
    }

    bool search(string key)
    {
        trieNodeGFG* running_node = this->root;
        for(int i=0; i<key.size(); i++)
        {
            char curr_char = key[i];
            if(running_node->children.find(curr_char) == running_node->children.end())
                return false;
            running_node = running_node->children[curr_char];
        }

        //if prefix is to be returned false
        /*
        if(running_node->isEndOfWord == true)
            return true;
        return false;
        */

       //if the prefix is to be returned true
        return true;
    }
};

//Algoexpert level stuff
class trieNode
{
public:
    unordered_map<char, trieNode*> children;
};

class trie
{
public:
    trieNode* root;
    char endOfWordChar;

    trie()
    {
        this->root = getNode();
        this->endOfWordChar = '*';
    }

    //a wrapper to get new node
    trieNode* getNode()
    {
        trieNode* node = new trieNode();
        return node;
    };

    void insert(string key)
    {
        trieNode* runningNode = this->root;
        for(int i=0; i<key.size(); i++)
        {
            char currChar = key[i];
            if(runningNode->children.find(currChar) == runningNode->children.end())
                runningNode->children[currChar] = getNode();
            runningNode = runningNode->children[currChar];
        }

        runningNode->children[this->endOfWordChar] = getNode();
        cout << "inserted " << key << endl;
        return;
    }

    bool search(string key)
    {
        trieNode* runningNode = this->root;
        for(int i=0; i<key.size(); i++)
        {
            char currChar = key[i];
            if(runningNode->children.find(currChar) == runningNode->children.end())
                return false;
            runningNode = runningNode->children[currChar];
        }

        return true;
    }
};

int main()
{
    /*
    trieGFG trie;
    vector<string> keysToBeInserted = { "GeeksForGeeks", "Geek", "hello", "hellow", "highway" };
    for(auto key: keysToBeInserted)
        trie.insert(key);

    //search
    vector<string> keysToBeSearched = { "hell", "Gee", "Geek", "hello", "hells" };
    for(string key: keysToBeSearched)
        cout << key << ": " << trie.search(key) << endl;
    */
    trie trieIns;
    vector<string> keysToBeInserted = { "GeeksForGeeks", "Geek", "hello", "hellow", "highway" };
    for(auto key: keysToBeInserted)
        trieIns.insert(key);
    
    vector<string> keysToBeSearched = { "hell", "Gee", "Geek", "hello", "hells" };
    for(string key: keysToBeSearched)
        cout << key << ": " << trieIns.search(key) << endl;

    return 0;
}