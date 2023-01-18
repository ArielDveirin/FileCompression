#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 100

// Define a struct for the Huffman tree node
typedef struct _node {
	int frequency;
	char character;
	struct _node* left;
	struct _node* right;
} node;

//Function to start compression
void startCompression();

// Function to build the Huffman tree
node* buildTree(int* frequency, char* characters, int numChars);

// Function to traverse the Huffman tree and create the mapping
void createMapping(node* root, char* mapping, char* code);
