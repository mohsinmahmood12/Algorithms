// Trie Data structure implementation and operations

// Language: cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Trie Node
struct TrieNode{
    struct TrieNode *children[26];
    bool isEndOfWord;

};
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void){
    struct TrieNode *pNode =  new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;
    return pNode;
}
// If not present, inserts key into trie. If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}
// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}
// Driver
int main(){
    // Input keys (use only 'a' through 'z' and lower case)
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(keys)/sizeof(keys[0]);
    struct TrieNode *root = getNode();
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
    // Search for different keys
    search(root, "the")? cout << "Yes" : cout << "No";
    search(root, "these")? cout << "Yes" : cout << "No";

    return 0;
}
