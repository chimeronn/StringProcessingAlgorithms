#include <iostream>
using namespace std;

class TrieNode {
  public:
    TrieNode* child[26];
    bool end;

    TrieNode() {
      end = false;
      for(int i = 0; i < 26; ++i) {
        child[i] = nullptr;
      }
    }

    void insert(string s) {
      TrieNode* curr = this;
      for(char c : s) {
        int index = c - 'a';
        if(curr->child[index] == nullptr) {
          curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
      }
      curr->end = true;
    }

    bool search(string s) {
      TrieNode* curr = this;
      for(int i = 0; i < s.length() - 1; ++i) {
        char c = s[i];
        int index = c - 'a';
        if(curr->child[index] == nullptr) return false;
        curr = curr->child[index];
      }
      char c = s[s.length() - 1];
      int index = c - 'a';
      if(curr->child[index] == nullptr) return false;
      else {
        if(curr->child[index]->end) return true;
        else return false;
      }
    }
};

int main() {
  TrieNode root;
  root.insert("and");
  root.insert("ant");
  cout << root.search("an");
}
