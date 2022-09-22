#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int prime = 101;
bool checkEqual(string str1, int start1, int end1, string str2, int start2, int end2);
long createHash(string str, int end);
long recalculateHash(string str, int oldIndex, int newIndex, long oldHash, int patternLen);
    int patternSearch(string text, string pattern);

int main() {
    string text = "abcdeabcadbeswghs";
    string pat = "esw";
    cout << patternSearch(text, pat);
    return 0;
}
 int patternSearch(string text, string pattern) {
    int m = pattern.length();
    int n = text.length();
    long patternHash = createHash(pattern, m - 1);
    long textHash = createHash(text, m - 1);
    for (int i = 1; i <= n - m + 1; i++) {
        if (patternHash == textHash && checkEqual(text, i - 1, i + m - 2, pattern, 0, m - 1)) {
            return i - 1;
        }
        if (i < n - m + 1) {
            textHash = recalculateHash(text, i - 1, i + m - 1, textHash, m);
        }
    }
    return -1;
}

 long recalculateHash(string str, int oldIndex, int newIndex, long oldHash, int patternLen) {
    long newHash = oldHash - str[oldIndex];
    newHash = newHash / prime;
    newHash += str[newIndex] * pow(prime, patternLen - 1);
    return newHash;
}

 long createHash(string str, int end) {
    long hash = 0;
    for (int i = 0; i <= end; i++) {
        hash += str[i] * pow(prime, i);
    }
    return hash;
}

 bool checkEqual(string str1, int start1, int end1, string str2, int start2, int end2) {
    if (end1 - start1 != end2 - start2) {
        return false;
    }
    while (start1 <= end1 && start2 <= end2) {
        if (str1[start1] != str2[start2]) {
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}