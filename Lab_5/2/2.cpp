#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<fstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	string text;
	string tmp;
	map<string, int> word;

	//Read sonnents
	ifstream in("sonnets.txt");

	while (!in.eof())
	{
		getline(in, tmp);
		text += tmp;
	}

	in.close();

	//Find word
	transform(text.begin(), text.end(), text.begin(), ::tolower);
	char* substr = strtok(&text[0], ".,:!;? ");
	while (substr != NULL)
	{
		tmp = substr;
		if (tmp.length() > 3) word[tmp]++;
		substr = strtok(NULL, ".,:!;? ");
	}

	//Sort word
	map<int, string> reverseWord;
	for (pair<string, int> pair : word) {
		reverseWord[pair.second] = pair.first;
	}

	//Print word
	map<int, string>::reverse_iterator it = reverseWord.rbegin();
	while (it != reverseWord.rend()) {
		if (it->first >= 7)
			cout << it->first << " " << it->second << '\n';
		it++;
	}
}
