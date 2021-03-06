#include <stdio.h>
#include <stdlib.h>
#include <initializer_list>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <memory>
#include <limits>
#include <list>
#include <map>
#include <iostream>
#include <array>
#include <set>

using namespace std;

vector<string> get_permutations(string str) {
	vector<string> permutations;

	if (str.empty()) {
		permutations.push_back(str);
		return permutations;
	}

	char last_char = str.back();
	str.pop_back();

	for (const string& permutation : get_permutations(str)) {
		for (int i = 0; i <= permutation.length(); i++) {
			string permutation_copy = permutation;
			permutation_copy.insert(i, 1, last_char);
			permutations.push_back(permutation_copy);
		}
	}

	return permutations;
}

int main(int argc, char** argv) {
	string a_str = "abcd";
	for (const string& str : get_permutations(a_str)) {
		cout << str << endl;
	}
}
