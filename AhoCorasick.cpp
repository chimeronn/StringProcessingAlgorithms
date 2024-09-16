#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class AhoCorasickNode {
    public:
        AhoCorasickNode* child[26];
        bool end;
        AhoCorasickNode* failLink;

        AhoCorasickNode() {
            for(int i = 0; i < 26; ++i) {
                child[i] = nullptr;
            }
            end = false;
        }

        void insert(string s) {
            AhoCorasickNode* curr = this;
            for(char c : s) {
                int index = c - 'a';
                if(curr->child[index] == nullptr)
                    curr->child[index] = new AhoCorasickNode();
                curr = curr->child[index];
            }
            curr->end = true;
        }

        AhoCorasickNode* search(string s) {
            AhoCorasickNode* curr = this;
            for(char c : s) {
                int index = c - 'a';
                if(curr->child[index] == nullptr) return nullptr;
                curr = curr->child[index];
            }
            return curr;
        }

        void setFailureLinks() {
            queue<pair<pair<AhoCorasickNode*, AhoCorasickNode*>, int>> q;
            int index = 0;
            for(AhoCorasickNode* node : child) {
                if(node != nullptr) q.push({{node, this}, index});
                ++index;
            }

            while(!q.empty()) {
                pair<pair<AhoCorasickNode*, AhoCorasickNode*>, int> front = q.front();
                AhoCorasickNode* curr = front.first.first;
                AhoCorasickNode* parent = front.first.second;
                int index = front.second;

                AhoCorasickNode* parentFailLink = parent->failLink;
                if(parentFailLink == nullptr) {
                    curr->failLink = this;
                }
                else {
                    curr->failLink = parentFailLink->child[index] != nullptr ?
                        parentFailLink->child[index] : this;
                }

                for(int i = 0; i < 26; ++i) {
                    if(curr->child[index] != nullptr) q.push({{
                        curr->child[index], curr}, i});
                }
            }
        }
};

int main() {
}
