
#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct MinHeapNode {
	char data;
	unsigned freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, unsigned freq) {
    	left = right = NULL;
    	this->data = data;
    	this->freq = freq;
	}
};

// For comparison of two heap nodes (needed in min heap)
struct compare {
	bool operator()(MinHeapNode* l, MinHeapNode* r) {
    	return (l->freq > r->freq);
	}
};

// Prints frequency table of characters
void printFrequency(const unordered_map<char, unsigned>& freqMap) {
	cout << "Character\tFrequency" << endl;
	for (auto& pair : freqMap) {
    	cout << pair.first << "\t\t" << pair.second << endl;
	}
	cout << endl;
}

// Prints huffman codes from the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str) {
	if (!root)
    	return;
	if (root->data != '$')
    	cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and print codes by traversing the built Huffman Tree
void HuffmanCodes(const string& sentence) {
	unordered_map<char, unsigned> freqMap;

	// Count frequencies of characters in the sentence
	for (char ch : sentence) {
    	freqMap[ch]++;
	}

	// Print frequency table
	cout << "Frequency Table:" << endl;
	printFrequency(freqMap);

	// Create a min heap & inserts all characters with their frequencies
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (auto& pair : freqMap) {
    	minHeap.push(new MinHeapNode(pair.first, pair.second));
	}

	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1) {
    	MinHeapNode *left = minHeap.top();
    	minHeap.pop();

    	MinHeapNode *right = minHeap.top();
    	minHeap.pop();

    	MinHeapNode *top = new MinHeapNode('$', left->freq + right->freq);
    	top->left = left;
    	top->right = right;
    	minHeap.push(top);
	}

	// Print Huffman codes using the Huffman tree built above
	cout << "\nHuffman Codes:" << endl;
	printCodes(minHeap.top(), "");
}

// Driver Code
int main() {
	string sentence = "Huffman coding";
	HuffmanCodes(sentence);

	return 0;
}


