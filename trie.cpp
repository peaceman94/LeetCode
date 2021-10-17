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

class trieNode
{
    public:
    unordered_map<char, trieNode*> children;
};

class trie
{
    public:
    trieNode* root;
    char endSymbol;

    //initialize the class
    //trie() : root( getNode() ), endSymbol('*') {};
    trie()
    {
        this->root = getNode();
        this->endSymbol = '*';
    }

    //create a new node
    trieNode* getNode()
    {
        trieNode* output = new trieNode();
        return output;
    };

    //insert key into this triee
    void insertKey(string key)
    {
        trieNode* running_node = root;
        for(int i=0; i<key.size(); i++)
        {
            char curr_char = key[i];
            if(running_node->children.find(curr_char) == running_node->children.end())
                running_node->children[curr_char] = getNode();
                           
            running_node = running_node->children[curr_char];
        }
        //mark the last word as end of word
        running_node->children[endSymbol] = getNode();
        return;
    };

    bool search(string key)
    {
        trieNode* running_node = root;
        for(int i=0; i<key.size(); i++)
        {
            char curr_char = key[i];
            if(running_node->children.find(curr_char) == running_node->children.end())
                return false;
             running_node = running_node->children[curr_char];
        }

        //check if the item to be returned is endof word or not
        if(running_node->children.find(endSymbol) != running_node->children.end())
            return true;
        return false;
    }
};

int main()
{
    vector<string> wordList = {"hello", "a", "ab", "abcd"};
    trie tree1;
    //trieNode* root = tree1.getNode();
    for(auto x: wordList)
    {
        tree1.insertKey(x);
    };

    vector<string> wordListToSearch = {"hell", "a", "abx", "abcd"};
    for(auto x: wordListToSearch)
    {
        bool output = tree1.search(x);
        cout << x << ": " << output << endl;
    }

    return 0;
}

