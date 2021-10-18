/*
642. Design Search Autocomplete System

Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#').

You are given a string array sentences and an integer array times both of length n where sentences[i] is a previously typed sentence and times[i] is the corresponding number of times the sentence was typed. For each input character except '#', return the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed.

Here are the specific rules:

The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same hot degree, use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Implement the AutocompleteSystem class:

AutocompleteSystem(String[] sentences, int[] times) Initializes the object with the sentences and times arrays.
List<String> input(char c) This indicates that the user typed the character c.
Returns an empty array [] if c == '#' and stores the inputted sentence in the system.
Returns the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed. If there are fewer than 3 matches, return them all.
 

Example 1:

Input
["AutocompleteSystem", "input", "input", "input", "input"]
[[["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]], ["i"], [" "], ["a"], ["#"]]
Output
[null, ["i love you", "island", "i love leetcode"], ["i love you", "i love leetcode"], [], []]

Explanation
AutocompleteSystem obj = new AutocompleteSystem(["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]);
obj.input("i"); // return ["i love you", "island", "i love leetcode"]. There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.
obj.input(" "); // return ["i love you", "i love leetcode"]. There are only two sentences that have prefix "i ".
obj.input("a"); // return []. There are no sentences that have prefix "i a".
obj.input("#"); // return []. The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.
 

Constraints:

n == sentences.length
n == times.length
1 <= n <= 100
1 <= sentences[i].length <= 100
1 <= times[i] <= 50
c is a lowercase English letter, a hash '#', or space ' '.
Each tested sentence will be a sequence of characters c that end with the character '#'.
Each tested sentence will have a length in the range [1, 200].
The words in each input sentence are separated by single spaces.
At most 5000 calls will be made to input.
*/

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
class treeNode
{
public:
    map<char, treeNode*> children;
    char c;

    //default constructor
    treeNode()
    {

    }
    //custom constructor
    treeNode(char c_input)
    {
        this->c = c_input;
    }
};

class trie
{
public:
    treeNode* root;
    char endOfWord;
    bool verbose;

    //constructor
    trie()
    {
        this->root = new treeNode('\0');
        this->endOfWord = '*';
        this->verbose = false;
    }
    
    //insert the key
    void insert(string key)
    {
        if(verbose) cout << "Inserting: " << key << endl;
        treeNode* runningNode = this->root;
        for(int  i=0; i<key.size(); i++)
        {
            char curr_char = key[i];
            if(runningNode->children.find(curr_char) == runningNode->children.end())
                runningNode->children[curr_char] = new treeNode(curr_char);
            runningNode = runningNode->children[curr_char];
        }
        runningNode->children[endOfWord] = new treeNode(endOfWord);
        return;
    }

    //search the key
    treeNode* search(string key)
    {
        treeNode* runningNode = this->root;
        for(int  i=0; i<key.size(); i++)
        {
            runningNode = searchChar(runningNode, key[i]);
            if(runningNode == nullptr)
            {
                if(verbose) cout << "prefix key: " << key << " NOT found" << endl;
                return runningNode;
            }
                
        }
        if(verbose) cout << "prefix key: " << key << " found" << endl;
        return runningNode;
    }

    treeNode* searchChar(treeNode* runningNode, char curr_char)
    {
        if(runningNode == nullptr)
            return runningNode;
            
        if(runningNode->children.find(curr_char) == runningNode->children.end())
            return nullptr;
        
        return runningNode->children[curr_char];
    }   

    //this is the GOAT
    void getAllSentenceFromNode(treeNode* runningNode, string running_word, vector<string> &output)
    {
        //boundary condition
        if(runningNode->c == '*') //enndof word characterizer
        {
            output.push_back(running_word);
            return;
        }

        //get all the releveant children
        for(auto& child: runningNode->children)
        {
            if(child.first == '*')
            {
                getAllSentenceFromNode(child.second, running_word, output);
            }
            else
            {
                string new_running_word = running_word + child.first;
                getAllSentenceFromNode(child.second, new_running_word, output);

            }
        }
        return;
    }
};

class AutocompleteSystem {
public:
    //stuff needed to keep track of states
    unordered_map<string, int> histCount;
    char endOfSentence;
    string runningWord;
    trie* trieIns;
    treeNode* runningNode;

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i=0; i<times.size(); i++)
        {
            histCount[sentences[i]] = times[i];
        }
        endOfSentence = '#';
        runningWord = "";

        //create trie for all the sentences
        trieIns = new trie();
        for(string sentence: sentences)
        {
            trieIns->insert(sentence);
        };

        //base case scenario
        this->runningNode = trieIns->root;

        //for testing trie
        /*
        string running_word = "i";
        treeNode* temp = trieIns->search(running_word);
        if(temp == nullptr) cout << "null ptr is returned" << endl;
        if(temp->c == '\0') cout << "root is returned" << endl;
        cout << "returned node is: " << temp->c << endl;
        vector<string> suggestions = {};
        trieIns->getAllSentenceFromNode( temp, running_word, suggestions);

        for(auto suggestion: suggestions)
            cout << "\t" << suggestion << endl;
        */
    };
    
    void resetSettings()
    {
        runningWord = "";
        this->runningNode = this->trieIns->root;
        return;
    }

    vector<string> pickTop3Suggestions(vector<string> allOutputs )
    {
        //create multimap
        map<int, vector<string>> batMan;
        for(string curr_output: allOutputs)
        {
            int key = histCount[curr_output];
            batMan[key].push_back(curr_output);
        };

        //now return top 3
        int count = 0;
        vector<string> output = {};
        for(auto it = batMan.rbegin(); it != batMan.rend(); it++)
        {
            if(false)
            {
                cout << "count is: " << it->first << endl;
                for(auto x: it->second)
                {
                    cout <<  x << " ";
                }
                cout << endl << endl;
            }
            

            vector<string> temp = it->second;
            sort(temp.begin(), temp.end());
            output.insert(output.end(), temp.begin(), temp.end());
            count++;
            if(count >= 3)
                break;
        }

        if(output.size() < 3)
            return output;
        vector<string> output_actual(output.begin(), output.begin()+3);
        return output_actual;

    }

    vector<string> input(char c) {
        //handle the end of sentence stuff
        if(c == this->endOfSentence)
        {
            if(histCount.find(runningWord) == histCount.end())
            {
                histCount[runningWord] = 0;
                //INPUT THIS WORD INTO THE TRIE, if not already
                trieIns->insert(runningWord);
            }
                
            histCount[runningWord]++;

            

            //reset settings
            resetSettings();
            return {};
        }

        //append the current character to the runningWord
        runningWord += c;
        //cout << "RunningWord is: " << runningWord << endl;
        
        runningNode = trieIns->searchChar(runningNode, c);
        if(runningNode == nullptr)
        {
            //there are no new suggestions: return empty stuff
            //cout << "nullptr returned" << endl;
            return {};
        }
        else
        {
            //now get ALL the suggestions
            vector<string> allOutput = {};
            trieIns->getAllSentenceFromNode(runningNode, runningWord, allOutput);

            return(pickTop3Suggestions(allOutput));
        }

        return {};
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
int main()
{
    //data
    vector<string> sentences = { "c ccccc c", "c ccccc" };
    vector<int> times = { 3, 3 };

    //inputs
    vector<vector<string>> output = {};
    vector<char> input_chars = { 'c', '#'};

    //processing
    AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
    for(char input_char: input_chars)
    {
        vector<string> suggestions = obj->input(input_char);
        output.push_back(suggestions);
    }

    //print the output;
    for(int i=0; i<input_chars.size(); i++)
    {
        char input_char = input_chars[i];
        vector<string> suggest = output[i];

        cout << input_char << ": " ;
        for(auto x: suggest)
            cout << x << " ";
        cout  << endl;
    }
    return 0;
}


/*
ANOTHER CLASS SOLUTION:

//
// Constructor: n log n (sorting sentences) n (hash inserts) 
//       Input: log n (binary search) m = matches found
//              ^-- each subsequent input uses previous subset bounds for binary search
//              m log m (run all matches through priority_queue/minheap, keep hottest 3)
//              1 (prepping results for return)
//      Insert: log n (find insertion point) n (vector insert) 1 (hash insert)
//
class AutocompleteSystem {
public:
    typedef pair<int,const char*> hotstr;
    unordered_map<string,int> hotmap;
    vector<string>::iterator l, r;
    vector<string> sentences;
    string userString;
    
    AutocompleteSystem(vector<string>& sentences_, vector<int>& times) {
        hotmap.clear();
        userString = "";
        sentences = sentences_;
        for (int i = 0; i < sentences.size(); ++i)
            hotmap[sentences[i]] = times[i];
        sort(sentences.begin(), sentences.end());
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            insert(userString);
            userString = "";
            return {};
        } else if (userString.length() == 0) {
            l = sentences.begin();
            r = sentences.end();
        }
        userString += c;
        
        // Get iterator to range start that matches userString (lower_bound)
        // lower_bound: Iterator to the first element in the range [first,last) which does not compare less than val.
        auto cmp = [](hotstr& a, hotstr& b) { return a.first == b.first ? strcmp(a.second,b.second) < 0 : a.first > b.first; };
        priority_queue<hotstr,vector<hotstr>,decltype(cmp)> minheap(cmp);
        if ((l = lower_bound(l, r, userString)) == r) return {}; // nothing found case
        for (r = l; r != sentences.end() && !strncmp(r->c_str(), userString.c_str(), userString.length()); ++r) {
            // Pass through a 3-size minheap, keeping hottest at bottom, popping off coldest at top
            minheap.emplace(hotmap[*r], r->c_str());
            if (minheap.size() > 3) minheap.pop();
        }

        vector<string> results;
        while (minheap.size())
            results.push_back(minheap.top().second), minheap.pop();
        std::reverse(results.begin(), results.end());
        return results;
    }
    
    void insert(string& str) {
        auto existsIter = hotmap.find(str);
        if (existsIter != hotmap.end()) {
            existsIter->second++;
        } else {
            // upper_bound: Iterator to the first element in the range [first,last) which compares greater than val.
            auto insertIter = upper_bound(sentences.begin(), sentences.end(), str);
            sentences.insert(insertIter, str);
            hotmap[str] = 1;
        }
    }
};
*/