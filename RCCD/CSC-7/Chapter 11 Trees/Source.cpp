#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct node
{
	node()
	{
		freq = 0;
	}

	char letter;
	unsigned int freq;
	vector<node> children;
};

void LoadFile(node &root, string filename)
{
	int i;
	string word;
	unsigned int freq;

	ifstream in;
	in.open(filename);
	if (in.fail())
		exit(404);

	while (in >> i >> word >> freq)
	{
		node* n = &root;

		for (int l = 0; l < word.length(); l++)
		{
			if (n->children.size() == 0)
				n->children.resize(28);

			int index = tolower(word[l]) - 'a';
			if (word[l] == '\'')
				index = 27;



			n->children[index].freq += freq;
			n->children[index].letter = char(index + 'a');
			
			n = &n->children[index];
		}

		if (n->children.size() == 0)
			n->children.resize(28);

		n->children[26].freq += freq;
		n->children[26].letter = '\0';

		cout << "Word: " << word << endl;
	}

	in.close();
}

string SearchWord(node &root, string word)
{
	node* n = &root;
	string suggestion;
	char letter;

	//partial traversal
	for (int l = 0; l < word.length(); l++)
	{
		letter = tolower(word[l]);
		suggestion += letter;

		int index = letter - 'a';
		if (letter == '\'')
			index = 27;

		n = &n->children[index];
	}

	if (n->children.size() == 0)
		return "No Suggestions...";
	if (n->children[26].freq > 0)
		return suggestion;


	//complete traversal
	while (n->letter != '\0' && n->children.size() > 0)
	{


		int i_maxfreq = 0;

		for (int i = 0; i < n->children.size(); i++)
		{
			if (n->children[i].freq > n->children[i_maxfreq].freq)
				i_maxfreq = i;
		}

		n = &n->children[i_maxfreq];
		suggestion += n->letter;
	}

	return suggestion;
}


int main()
{
	node root;
	string word, suggestion;

	LoadFile(root, "words.txt");

	cout << "Type word (/quit to quit): ";
	do
	{
		cin >> word;
		suggestion = SearchWord(root, word);

		if (suggestion != word)
			cout << "Did you mean '" << suggestion << "'?" << endl;

	} while (word != "/quit");


	return 0;
}