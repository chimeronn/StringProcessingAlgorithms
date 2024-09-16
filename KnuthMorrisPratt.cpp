#include <iostream>
#include <vector>
using namespace std;

// Knuth-Morris-Pratt allows you to find the longest prefix that is also a suffix within a given length of a substring of s

vector<int> knuthMorrisPratt(string s) {
  int n = s.length();
  vector<int> pi(n);

  for(int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while(j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if(s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int main() {
  string s = "aabaaab";
  for(int i : knuthMorrisPratt(s)) cout << i << " ";
}
