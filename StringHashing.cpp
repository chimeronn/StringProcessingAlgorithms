#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// Using string hashing helps us compare strings in a faster time complexity

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

int countDuplicates(vector<string> strings) {
  int ans = 0;
  unordered_set<long long> set;
  sort(strings.begin(), strings.end());
  string prev = strings[0];
  for(int i = 1; i < strings.size(); ++i) {
    if(computeHash(strings[i]) == computeHash(prev) &&                  set.find(computeHash(prev)) == set.end()) {
      ans++;
      set.insert(computeHash(prev));
    }
    prev = strings[i];
  }
  return ans;
}

int main() {
  vector<string> strings = {"somebody", "once", "told", "me", "the", "world", "was", "gonna", "roll", "me", "I", "ain't", "the", "sharpest", "tool", "in", "the", "shed"};
  cout << countDuplicates(strings);
}
