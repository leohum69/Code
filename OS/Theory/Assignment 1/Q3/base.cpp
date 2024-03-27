#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include "BKTree.h"

#define SHM_SIZE 1024

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

using namespace std;


string boogie;

vector<pair<int, string>> ln;

struct trieNode
{
	bool isEnd;
	trieNode *children[26];
};

static struct trieNode *node()
{
	struct trieNode *temp = new trieNode();
	temp->isEnd = false;

	for (int i = 0; i < 26; i++)
	{
		temp->children[i] = NULL;
	}
	return temp;
}

int findDistance(string word1, string word2)
{
	int distance = 0, i = 0;
	for (; i < word1.length() && i < word2.length(); i++)
	{
		if (word1[i] != word2[i])
		{
			distance++;
		}
	}
	return word1.length() + word2.length() - 2 * i + distance;
}

int findUnCommon(string word1, string word2)
{
	int frequency[26];
	for (int i = 0; i < 26; i++)
	{
		frequency[i] = 0;
	}

	for (char c : word1)
	{
		frequency[CHAR_TO_INDEX(c)]++;
	}
	for (char c : word2)
	{
		frequency[CHAR_TO_INDEX(c)]--;
	}
	int uncommon = 0;
	for (int i = 0; i < 26; i++)
	{
		uncommon += abs(frequency[i]);
	}
	return uncommon;
}

int longestPrefix(string word1, string word2)
{

	int len = word1.length() > word2.length() ? word2.length() : word1.length();
	for (int i = 0; i < len; i++)
	{
		if (word1[i] != word2[i])
		{
			return i;
		}
	}
	return len;
}

int cost(string word1, string word2)
{
	return (findDistance(word1, word2) + findUnCommon(word1, word2) - longestPrefix(word1, word2));
}

class Trie
{
private:
public:
	struct trieNode *root;
	int size;
	Trie()
	{
		size = 0;
		root = node();
	}

	void insertWord(string word)
	{
		trieNode *temp = root;
		for (char c : word)
		{
			if (temp->children[CHAR_TO_INDEX(c)] == NULL)
			{
				temp->children[CHAR_TO_INDEX(c)] = node();
			}
			temp = temp->children[CHAR_TO_INDEX(c)];
		}
		temp->isEnd = true;
		size++;
	}

	bool searchWord(string word)
	{
		trieNode *temp = root;
		for (char c : word)
		{
			if (temp->children[CHAR_TO_INDEX(c)] == NULL)
			{
				return 0;
			}
			temp = temp->children[CHAR_TO_INDEX(c)];
		}
		if (temp->isEnd)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	bool isLast(string word)
	{
		if (!searchWord(word))
		{
			return false;
		}
		trieNode *temp = root;
		for (char c : word)
		{
			temp = temp->children[CHAR_TO_INDEX(c)];
		}
		for (int i = 0; i < 26; i++)
		{
			if (temp->children[i])
			{
				return false;
			}
		}
		return true;
	}

	bool isLastNode(struct trieNode *root)
	{
		for (int i = 0; i < 26; i++)
		{
			if (root->children[i])
				return false;
			return true;
		}
		return false;
	}

	void printAll(trieNode *temp, string word = "", int flag = 0, string inp = "")
	{
		if (temp->isEnd == true && flag)
		{
			if (cost(word, inp) < 5)
			{
				ln.push_back(make_pair(cost(word, inp), word));
			}
		}
		if (temp->isEnd == false || isLast(word) == false)
		{
			for (int i = 0; i < 26; i++)
			{
				if (temp->children[i] != NULL)
				{
					if (flag == 0)
						word = "";
					printAll(temp->children[i], word + (char)(i + 96 + 1), flag + 1, inp);
				}
			}
		}
	}

	void recommend(string word)
	{
		if (searchWord(word))
		{	boogie.append(word);
			boogie.append(" is the correct spelling!");
			// cout << word << " is the correct spelling!" << endl;
			return;
		}
		trieNode *temp = root;
		// cout << "TRIE Tree predictions:";
		boogie.append("Predictions : \n");
		printAll(temp, "", 0, word);
		sort(ln.begin(), ln.end());
		int i = 1;
		for (vector<pair<int, string>>::iterator itr = ln.begin(); itr != ln.end(); itr++)
		{
			// cout << itr->second << endl;
			boogie.append(itr->second);
			boogie.append("\n");
			if (i % 10 == 0)
			{
				// cout << "View more? [1/0]: ";
				// cin >> i;
				// if (!i)
				// {
					return;
				// }
			}
			else
			{
				i++;
			}
		}
	}
};

// BK tree implementation
struct Node
{
	string word;
	size_t distance;
	Node *leftChild;
	Node *rightSibling;
};

class BKTree
{
private:
	Node *root;
	Node *createNode(string w, size_t d);
	int min(int a, int b, int c);
	size_t levenshteinDistance(string w1, string w2);
	void recursiveSearch(Node *node, vector<string> &suggestions, string w, size_t t, bool &wordFound);
	bool inRange(size_t curDist, size_t minDist, size_t maxDist);
	void printSuggestions(vector<string> &suggestions, bool wordFound);

public:
	BKTree();
	~BKTree();
	void add(string w);
	void cleanString(basic_string<char> &s);
	void search(string w, int t);
};

BKTree::BKTree() { root = NULL; }
BKTree::~BKTree() { delete root; }

Node *BKTree::createNode(string w, size_t d)
{
	Node *node = new Node();

	node->word = w;
	node->distance = d;
	node->leftChild = NULL;
	node->rightSibling = NULL;

	return node;
}

void BKTree::add(string w)
{
	if (root == NULL)
	{
		root = createNode(w, -1);
		return;
	}

	Node *curNode = root;
	Node *child;
	Node *newChild;
	size_t dist;

	while (1)
	{
		dist = levenshteinDistance(curNode->word, w);
		if (!dist)
			return;
		child = curNode->leftChild;
		while (child)
		{
			if (child->distance == dist)
			{
				curNode = child;
				break;
			}
			child = child->rightSibling;
		}
		if (!child)
		{
			newChild = createNode(w, dist);
			newChild->rightSibling = curNode->leftChild;
			curNode->leftChild = newChild;
			break;
		}
	}
}

void BKTree::search(string w, int t)
{
	vector<string> suggestions;
	bool wordFound = false;

	recursiveSearch(root, suggestions, w, t, wordFound);

	printSuggestions(suggestions, wordFound);
}

void BKTree::recursiveSearch(Node *curNode, vector<string> &suggestions, string w,
							 size_t t, bool &wordFound)
{
	size_t curDist = levenshteinDistance(curNode->word, w);
	size_t minDist = curDist - t;
	size_t maxDist = curDist + t;

	if (!curDist)
	{
		wordFound = true;
		return;
	}
	if (curDist <= t)
		suggestions.push_back(curNode->word);

	Node *child = curNode->leftChild;
	if (!child)
		return;

	while (child)
	{
		if (inRange(child->distance, minDist, maxDist))
			recursiveSearch(child, suggestions, w, t, wordFound);

		child = child->rightSibling;
	}
}

bool BKTree::inRange(size_t curDist, size_t minDist, size_t maxDist)
{
	return (minDist <= curDist && curDist <= maxDist);
}

void BKTree::printSuggestions(vector<string> &suggestions, bool wordFound)
{
	if (wordFound)
	{
		cout << "Word is spelled correctly." << endl;
	}
	else if (suggestions.empty())
	{
		cout << "No suggestions found." << endl;
	}
	else
	{
		cout << "BK Tree Predictions: ";
		for (int i = 0; i < suggestions.size() - 1; i++)
		{
			cout << suggestions[i] << ", ";
		}
		cout << suggestions[suggestions.size() - 1] << "?" << endl;
	}
}

// https://en.wikipedia.org/wiki/Levenshtein_distance
size_t BKTree::levenshteinDistance(string w1, string w2)
{
	if (w1.length() == 0)
		return w2.length();
	if (w2.length() == 0)
		return w1.length();

	size_t n_w1 = w1.length();
	size_t n_w2 = w2.length();
	int cost;

	int d[n_w1 + 1][n_w2 + 1];

	for (int i = 0; i <= n_w1; i++)
		d[i][0] = i;
	for (int i = 0; i <= n_w2; i++)
		d[0][i] = i;

	for (int i = 1; i <= n_w1; i++)
	{
		for (int j = 1; j <= n_w2; j++)
		{

			cost = (w1[i - 1] == w2[j - 1]) ? 0 : 1;

			d[i][j] = min(d[i - 1][j] + 1,
						  d[i][j - 1] + 1,
						  d[i - 1][j - 1] + cost);
		}
	}

	return d[n_w1][n_w2];
}

int BKTree::min(int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;

	return min;
}

void BKTree::cleanString(basic_string<char> &s)
{
	for (basic_string<char>::iterator p = s.begin();
		 p != s.end(); ++p)
	{
		*p = tolower(*p);
	}
}
BKTree *tree = new BKTree();

BKTree *BKTreeInit()
{
	// BKTree* tree = new BKTree();

	string line;
	ifstream file("words.txt");
	clock_t start;
	clock_t end;

	double elapsedTime;

	if (file.is_open())
	{
		// cout << "Building BKTree..." << endl;

		while (getline(file, line))
			tree->add(line);

		file.close();
	}
	// cout << "Done building BKTree." << endl
		//  << endl;

	// string word = l;

	// tree->cleanString(word);

	// // start = clock();
	// tree->search(word, 1);

	return tree;
}

void BKTreeSearch(string line)
{
	string word = line;

	tree->cleanString(word);

	// // start = clock();
	// cout<<"Searching";
	tree->search(word, 1);
	// end = clock();

	// elapsedTime = double(end - start) /CLOCKS_PER_SEC;
	// cout<<"Results found by implementing BKTree in "<<elapsedTime<<"s."<<endl<<endl;
}

int main()
{

	Trie obj1;
	string line;
	ifstream words("words.txt");
	if (words)
	{
		while (getline(words, line))
		{
			obj1.insertWord(line);
		}
		words.close();
	}

	BKTreeInit();

	int shmid;

	key_t key = 1234; // Same key as the sender

	char *shm_ptr;
	// cout<<"which ho naw"<<endl;
	// Locate the existing shared memory segment

	if ((shmid = shmget(key, SHM_SIZE, S_IRUSR | S_IWUSR)) == -1)
	{

		perror("shmget");

		exit(EXIT_FAILURE);
	}

	// Attach the shared memory segment to the receiver's address space

	shm_ptr = (char *)shmat(shmid, NULL, 0);

	if (shm_ptr == (char *)(-1))
	{

		perror("shmat");

		exit(EXIT_FAILURE);
	}

	// Read data from the shared memory

	// cout << shm_ptr;
	line = shm_ptr;
	// cout<<line<<endl;
	if ((int)obj1.searchWord(line))
	{
		// cout << "The spelling of this word is correct." << endl;
		// BKTreeSearch(line);
		obj1.recommend(line);
	}
	else
	{
		// cout << "The word is spelled wrong." << endl;
		obj1.recommend(line);
		// BKTreeSearch(line);
	}

	// Detach the shared memory segment

	// cout<<boogie;

	shmctl(shmid, IPC_RMID, NULL);

	for (int i = 0; i < boogie.length(); i++)
	{
		shm_ptr[i] = boogie[i];
	}
	shm_ptr[boogie.length()] = '\0';
	

	shmdt(shm_ptr);

	// while(1){
	// 	cout<<"Enter word: ";
	// 	cin>>line;

	// }

	// BKTreeSearch(line);
}
