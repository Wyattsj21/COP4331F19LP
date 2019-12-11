#include "Deflate.h"

using namespace std;


Deflate::Deflate(){}

Deflate::Deflate(const string filename)
{
	this->filename = filename;
}

// Runs complete Deflate algorithm using LZ and Huff classes
// Retruns bool depending on success or failure with true and false respectively
bool Deflate::compress()
{
	vector<Triplet> lzOut;
	LLeaf lHuff[];
	DLeaf dHuff[];
	cLeaf cHuff[];
	// Constructing LZ class and running LZ77 compression on file
	lz = LZ(this->filename);
	lz.compress();
	lzOut = lz.getOutput()
	// Construction of Huff class and running huffman compression of LZ77 output vector
	huff = Huff(lzOut);
	huff.huffmanLZ();

	//Retrieving huffman tree and lengths of literal/length, distance and code lengths
	lHuff = huff.getLengthTable();
	dHuff = huff.getDistanceTable();
	cHuff = huff.getCodeTable();

	// Only allowing for dynamic huffman trees
	// Output header of BFinal(last), BHeader(type) = 10

	// Output lengths of each tree (number of symbols in each tree)
	// 5 bits for literal/length 
	// 5 bits for distance
	// 4 bits for codes

	// Output code length table
	// Unable to produce in huffman currently

	// Output literal/length table
	// This takes the representation of printing out a code which references the code length of the symbol
	// Also could take the form of a symbol which represents a repetetion of the previous symbol
	// or it could show that the following set of 3-138 symbols have a 0 length code i.e. they arent present

	// Output distance table
	// This table takes the same form as the literal/length table

	// Output LZ77 with huffman encoded symbols
	// Output length followed by distance followed by a literal

	// At end of block output symbol for end of block
}