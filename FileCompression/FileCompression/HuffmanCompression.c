#include "HuffmanCompression.h"

//Function to start compression
void startCompression()
{
	char file_path[MAX_PATH];

	printf("Enter file path: ");
	gets(file_path);

	FILE* input = fopen(file_path, "r");

	// Read the contents of the file into memory
	fseek(input, 0, SEEK_END);
	int fileSize = ftell(input);
	fseek(input, 0, SEEK_SET);
	char* data = (char*)malloc(fileSize + 1);
	fread(data, fileSize, 1, input);
	data[fileSize] = '\0';

	// Create a frequency table for each character in the file
	int frequency[256] = { 0 };
	for (int i = 0; i < fileSize; i++)
	{
		frequency[(int)data[i]]++;
	}

	// Build the Huffman tree
	char characters[256];
	int numChars = 0;
	for (int i = 0; i < 256; i++)
	{
		if (frequency[i] > 0) {
			characters[numChars] = (char)i;
			numChars++;
		}
	}
	node* root = buildTree(frequency, characters, numChars);

	// Traverse the Huffman tree to create the mapping
	char mapping[256];
	char code[256] = "";
	createMapping(root, mapping, code);

	// Use the mapping to replace each character in the original file with its corresponding Huffman code
	char* compressedData = (char*)malloc(fileSize * sizeof(char));
	int compressedSize = 0;
	for (int i = 0; i < fileSize; i++)
	{
		strcpy(compressedData + compressedSize, mapping[(int)data[i]]);
		compressedSize += strlen(mapping[(int)data[i]]);
	}

	// Write the compressed data to a new file
	FILE* output = fopen("output.txt", "w");
	fwrite(compressedData, compressedSize, 1, output);

	// Close the files and free memory
	fclose(input);
	fclose(output);
	free(data);
	free(compressedData);

	return 0;

}

node* buildTree(int* frequency, char* characters, int numChars)
{
	return NULL;
}

void createMapping(node* root, char* mapping, char* code)
{
}
