#ifndef DL_HUFF_H
#define DL_HUFF_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

// Huffman Compression class
// Currently only able to compress a vector representation of LZ77
class Huff
{
	private:
		// Used to store Length/Literal huffman table
		struct LLeaf
		{
			int bitL;	// Bit length of symbol
			int count;	// Number of symbols in uncompressed file
			int code;	// Huffman code for symbol
			//Constructor
			LLeaf(int c = 0, int n = 0, int co = 0)
			{
				this->count = c;
				this->bitL = n;
				this->code = co;
			}
		};

		// Used to store Distance huffman table
		struct DLeaf
		{
			int count;	// Bit length of symbol
			int bitL;	// Number of symbols in uncompressed file
			int code;	// Huffman code for symbol

			//Constructor
			DLeaf(int c = 0, int n = 0, int co = 0)
			{
				this->count = c;
				this->bitL = n;
				this->code = co;
			}
		};

		// Used for local storage of vector representation of LZ77
		struct Triplet
		{
			int distance;	// Offset from cursor
			int length;		// Number of characters to copy from distance
			char follow;	// Trailing literal
			
			//Constructor
			Triplet(int d = 0, int l = 0, char c = '\0')
			{
				this->distance = d;
				this->length = l;
				this->follow = c;
			}
			
		};

		// Used for a binary tree
		struct BT
		{
			int totalCount;		// Keeps track of total amount of characters in tree
			BT *one;			// Left branch
			BT *zero;			// Right branch
			LLeaf *leafL;		// For leaf nodes stores reference to specific index in lLeaf
			DLeaf *leafD;		// For leaf nodes stores reference to specific index of dLeaf

			BT(int total = 0, BT *o = NULL, BT *z = NULL, LLeaf *l = NULL, DLeaf *d = NULL)
			{
				this->totalCount = total;
				this->one = o;
				this->zero = z;
				this->leafL = l;
				this->leafD = d;
			}
		};

	// Method prototypes
	// Find Method definitons in huffman.hpp
	public:
		Huff();
		Huff(const string filename);
		Huff(const vector<Triplet> v);
		void huffmanLZ();
		void compress();
		LLeaf getLengthTable();
		DLeaf getDistanceTable();
		Cleaf getCodeTable();
		~Huff(); 

	private:
		// Fixed symbol starting points for literal/length symbols 257-286
		const int lens[29] = {
			3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
			35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258};
		// Extra bits used with respective lieral/length symbol index
		const int lext[29] = {
        	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
        	3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0};
        // Fixed symbol starting points for distance symbols 0-29
		const int dists[30] = {
			1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
        	257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
        	8193, 12289, 16385, 24577};
        // Extra bits used with respective distance symbol index
        const int dext[30] = {
        	0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
			7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13};

		// Location of file to compress
		string filename;
		// Vector representation of LZ77 compression
		vector<Triplet> LZ;
		// Huffman table for literal/length symbols
		LLeaf lLeafs[286] = {0, 0, true, 0};
		// Huffman table for distance symbols
		DLeaf dLeafs[30] = {0, 0, true, 0};
		// Huffman trees for detemrining code length for each symbol
		vector<BT> huffmantreeL;
		vector<BT> huffmantreeD;;
		// max bit lengths for each alphabet
		// adjusted when inside of their respective codeCount method
		int max_bitsl = 0;
		int max_bitsd = 0;
};

#include "huffman.hpp"

#endif
