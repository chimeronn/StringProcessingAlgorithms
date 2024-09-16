#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Rabin-Karp allows us to do the regex matching operation in O(s.length() +     p.length())

long long computeHash(string s) {
  const int p = 31;
  const int m = 1e9 + 9;
  long long hashVal = 0;
  long long pow = 1;

  for(char c : s) {
    hashVal += (c - 'a') * pow % m;
    pow *= p;
    pow %= m;
  }
  return hashVal;
}

vector<int> rabinKarp(string text, string pattern) {
  vector<int> ans;
  int pSize = pattern.length();
  vector<long long> textHashes;
  long long patternHash = computeHash(pattern);

  for(int i = 0; i + pSize <= text.length(); ++i) {
    string curr = text.substr(i, pSize);
    textHashes.push_back(computeHash(curr));
  }

  int index = 0;
  for(long long hash : textHashes) {
    if(hash == patternHash) ans.push_back(index);
    index++;
  }
  return ans;
}

int main() {
  string text = "AABAACAADAABAABA";
  string pattern = "AABA";

  for(int i : rabinKarp(text, pattern)) {
    cout << i << " ";
  }
}
