#include <iostream>
using namespace std;

// Pattern matching with a suffix trie

class SuffixTrieNode {
  public:
    SuffixTrieNode* child[26];
    bool end;

    SuffixTrieNode() {
      end = false;
      for(int i = 0; i < 26; ++i) {
        child[i] = nullptr;
      }
    }

    void insert(string s) {
      SuffixTrieNode* curr = this;
      for(char c : s) {
        int index = c - 'a';
        if(curr->child[index] == nullptr)
          curr->child[index] = new SuffixTrieNode();
        curr = curr->child[index];
      }
      curr->end = true;
      if(s.length() > 1) insert(s.substr(1));
    }

    bool search(string s) {
      SuffixTrieNode* curr = this;
      for(char c : s) {
        int index = c - 'a';
        if(curr->child[index] == nullptr) return false;
        curr = curr->child[index];
      }
      return true;
    }
};

bool suffixTrieMatch(string text, string pattern) {
  SuffixTrieNode root;
  root.insert(text);
  return root.search(pattern);
}

int main() {
  string text = "banana";
  string pattern = "nan";
  string pattern2 = "somebodyoncetoldme";

  cout << suffixTrieMatch(text, pattern) << "\n";
  cout << suffixTrieMatch(text, pattern2);
}
