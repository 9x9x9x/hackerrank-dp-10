#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isUpcase(char c){
    return (c >= 'A') && (c <= 'Z');
}

char upcase(char c){
    if (isUpcase(c)) return c;
    return (char)(c - 32);
}

bool dp[1011][1011];

int main() {
    int test;
    cin >> test;

    while(test--) {
        string s1, s2;
        cin >> s1;
        cin >> s2;

        for(int i = 0; i <= s1.length(); i++) {
            for(int j = 0; j <= s2.length(); j++) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;

        for (int i = 0; i < s1.length(); i++){
            for (int j = 0; j <= s2.length(); j++)if (dp[i][j]){
                if(j < s2.length() && (upcase(s1[i]) == s2[j]))dp[i + 1][j + 1] = true;
                if(!isUpcase(s1[i])) dp[i + 1][j] = true;
            }
        }

        if (dp[s1.length()][s2.length()]) cout << "YES" << endl; else cout << "NO" << endl;
    }
}

/*
#include <bits/stdc++.h>

const int M = 1010;

using namespace std;

string s, t;
bool d[M][M];

bool isUpper(char c) {
  return 'A' <= c && c <= 'Z';
}

bool equal(char a, char b) {
  if (!isUpper(a))
    a = a + 'A' - 'a';
  assert(isUpper(b));
  return a == b;
}

bool isUpper(const string &s) {
  for (char c : s)
    if (!isUpper(c))
      return false;
  return true;
}


void read() {
  cin >> s >> t;
  assert(s.length() <= 1000);
  assert(t.length() <= 1000);
  assert(isUpper(t));
}


void kill() {
  int n = s.length();
  int m = t.length();

  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      d[i][j] = false;

  d[0][0] = true;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) {
      if (i < n && !isUpper(s[i]))
        d[i + 1][j] |= d[i][j];
      if (i < n && j < m && equal(s[i], t[j]))
        d[i + 1][j + 1] |= d[i][j];
    }

  cout << (d[n][m] ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  assert(1 <= t && t <= 10);
  while (t--) {
    read();
    kill();
  }
  return 0;
}
*/
