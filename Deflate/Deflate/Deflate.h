#ifndef DL_DEFLATE_H
#define DL_DEFLATE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>
#include "../Huffman/huffman.h"
#include "../LZ77/LZ77.h"

using namespace std;

// Deflate compression class
// Uses LZ and Huff classes to gather neccessary data to produce output
// Currently does not support having multiple blocks of compression or any uncompressed or
// fixed blocks
// No attempt to write yet due to huffman being unable to produce useful output
class Deflate
{
	// TODO: Will contain Triplet struct and Leaf structs from huff and LZ classes
	private:
		

	// Method protoypes find definitons in Deflate.hpp
	public:
		Deflate(); // default zero parameter constructor
		Deflate(const string filename);
		bool compress(string location);
		~Huff();
	private:
		// stores location of file to compress
		string filename;
		// Compression classes
		LZ lz;
		Huff huff;
		// Represents type of compression used
		int type = 2;
		// Represents if this is the last block of the file
		bool last = true;

}

#include "Deflate.hpp"

#endif