#include<iostream>
#include<string>
using namespace std;

int brute_force_search(string pat, string txt)
{
	int M = pat.length(), N = txt.length();
	for (int i = 0; i <= N - M; i++) {
		int j;
		for (j = 0; j < M; j++) {
			if (txt[i + j] != pat[j]) break;
		}
		if (j == M) return i; // tìm xong
	}
	return N; // không tìm được
};

int main() {
	string txt = "ABACADABRAC";
	string pat = "ABR";
	int a = brute_force_search(pat, txt);
	return 0;
}
