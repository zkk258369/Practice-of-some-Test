#include<bits/stdc++.h>
using namespace std;

#if 0
// ====================用数组存字母====================
class TrieNode
{
public:
    TrieNode() :isEnd(false) 
    { memset(next, 0, sizeof(next)); }
    bool ContainsKey(char ch) { return next[ch-'a'] != nullptr; }
    TrieNode* Get(char ch) { return next[ch-'a']; }
    void Put(char ch, TrieNode* node) { next[ch-'a'] = node; }
    void SetEnd() { isEnd = true; }
    bool IsEnd() { return isEnd; }
private:
    TrieNode* next[26];
    bool isEnd;
};

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++)
        {
            char curChar = word[i];
            if(!node->ContainsKey(curChar))
            {
                node->Put(curChar, new TrieNode());
            }
            node = node->Get(curChar);
        }
        node->SetEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* node = SearchPrefix(word);
        return node != nullptr && node->IsEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode* node = SearchPrefix(prefix);
        return node != nullptr;
    }
private:
    TrieNode* SearchPrefix(string word)
    {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++)
        {
            char curChar = word[i];
            if(node->ContainsKey(curChar)) node = node->Get(curChar);
            else return nullptr;
        }
        return node;
    }
private:
    TrieNode* root;
};
// ====================用数组存字母====================
#endif

/*
 * 参考
 * https://yq.aliyun.com/articles/345285?spm=a2c4e.11153940.0.0.37d3703c1ZPCsQ
 * https://blog.csdn.net/sunny_ss12/article/details/47683715
 * https://www.cnblogs.com/luxiaoxun/archive/2012/09/03/2668611.html
*/
#if 1
#include<iostream>
#include<unordered_map>
#include <memory>
#include<vld.h>//vs 中内存检测
using namespace std;

// ====================用map存字母===================
struct TrieNode
{
	unordered_map<char, TrieNode*> child;
	bool isEnd = false;
	~TrieNode()
	{
		for (auto& it : child)
		{
			if (it.second) delete it.second;
		}
	}
};
class Trie
{
public:
	Trie() :root(new TrieNode()) {}
	~Trie() { delete root; }
	void Insert(string word)
	{
		TrieNode* node = root;
		for (auto i : word)
		{
			if (node->child.count(i) == 0)
			{
				node->child.insert(pair<char, TrieNode*>(i, new TrieNode()));
			}
			node = node->child[i];
		}
		node->isEnd = true;
	}
	bool Search(string word)
	{
		TrieNode* node = SearchPrefix(word);
		return node != nullptr && node->isEnd;
	}
	bool StartWith(string word)
	{
		TrieNode* node = SearchPrefix(word);
		return node != nullptr;
	}
private:
	TrieNode* SearchPrefix(string word)
	{
		TrieNode* node = root;
		for (auto i : word)
		{
			if (node->child.count(i) > 0) node = node->child[i];
			else return nullptr;
		}
		return node;
	}
private:
	TrieNode* root;
};

int main()
{
	Trie t1;
	t1.Insert("abc");
	t1.Insert("bcde");
	t1.Insert("abcdef");
	t1.Insert("eftr");


	//system("pause");
	return 0;
}
// ====================用map存字母===================
#endif