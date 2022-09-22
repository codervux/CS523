#include<iostream>
#include<string>
using namespace std;

int* creat_temporary_array(string);
int KMP_search(string, string);

int main() {
	string txt = "abcxabcdabcdabcy";// return 8
	string pat = "abcdabcy";
	cout << KMP_search(txt, pat);
	return 0;
}

int KMP_search(string txt, string pat) {
	int* a = creat_temporary_array(pat);
	for (int i = 0, j = 0; i < txt.length() && j < pat.length(); i++, j++) {
		if (txt[i] != pat[j]) {
			if (j != 0)
				j = a[j - 1];
			else
				i++;
		}
		if (j == pat.length() - 1)
			return i - j;
	}
	return -1;
}

int* creat_temporary_array(string pat) {
	int* a = new int[pat.length()];
	a[0] = 0;
	for (int i = 0, j = 1; j < pat.length();) {
		if (pat[i] == pat[j]) {
			a[j] = i + 1;
			i++;
			j++;
		}
		else {
			if (i == 0) {
				a[j] = 0;
				j++;
			} else 
				i = a[i - 1];
		}
	} return a;
}