// Wyatt Jones

#include "huffman.h"

using namespace std;

// No parameter Constructor
Huff::Huff(){}

// Constructor for passing uncompressed file
Huff::Huff(const string filename)
{
	this->filename = filename;
}

// Constructor for passing LZ77 in vector format
Huff::Huff(const vector<Triplet> v)
{
	this->LZ = v;
}


// Uses LZ77 vector stored in class to create and store
// lLeafs (length/literal huffman tree), dLeafs (distance huffman tree), cLeafs
// (code length huffman tree, currently not implemented). 
void Huff::huffmanLZ()
{
	bool character = true, dist = true, leng = true;		// Used for finding counts of symbols
	BT *lFirst = &BT(INT8_MAX), *lSecond = &BT(INT8_MAX);	// TODO error with temporary variable address
	BT *combine;											// Intermediate storage for combining trees
	BT *ptr;												// Temporary tree
	int *bitL;												// Bit length counts for length/literals
	int *bitD;												// Bit Length counts for distance 
	int *next_code;											// Stores next avaliable code for each bit length
	int total = 0, first, second, p, code, len;

	// Iterating through LZ vector representation to count each symbol
	for (auto itr = this->LZ.begin(); itr != this->LZ.end(); itr++)
	{
		for (int i = 0; i < 286; i++)
		{
			if(i < 256 && (int)itr->follow == i)
			{
				lLeafs[i].count++;
				character = true;
			}
			else if (i > 256 && (itr->length >= lens[i - 257]) && (itr->length < lens[i - 256]))
			{
				lLeafs[i].count++;
				leng = true;
			}

			// If both symbols have been counted move on to distance
			if (character && leng)
			{
				break;
			}
		}

		character = leng = false;

		for (int i = 0; i < 30; i++)
		{
			if ((itr->distance >= dist[i]) && (itr->distance < dist[i + 1]))
			{
				dLeafs[i].count++;
				break;
			}
		}
	}

	// Only one End of Block code in any block so setting count to one
	lLeafs[256].count = 1;

	// Puts every literal/length that appears at least once in the LZ representation into a BT node
	for (int i = 0; i < 286; i++)
	{
		if (lLeafs[i].count > 0)
		{
			this->huffmantreeL.push_back(BT(total = lLeafs[i].count, l = lLeafs[i]));
		}
	}

	// Loop to reduce the number of trees until there is aonly a single tree left
	// Finds threes with the lowest total count and merges them.
	// Replaces the location of the earliest tree with the merged tree and shifts
	// shifts all trees after latest tree down by 1 to fill in gaps.
	while (this->huffmantreeL.size() > 1)
	{

		for (int i = 0; i < this->huffmantreeL.size(); i++)
		{
			if (this->huffmantreeL[i].totalCount < lFirst->totalCount)
			{
				lSecond = lFirst;
				lFirst = this->huffmantreeL[i];
				second = first;
				first = i;
			}

			else if (this->huffmantreeL[i].totalCount < lSecond->totalCount)
			{
				lSecond = this->huffmantreeL[i];
				second = i;
			}
		}

		combine = BT(this->huffmantreeL[first].totalCount + this->huffmantreeL[second].totalCount, z = this->huffmantreeL[first],
			o = this->huffmantreeL[second]);

		if (first < second)
		{
			this->huffmantreeL[first] = combine;
			for (int i = second; i < this->huffmantreeL.size() - 1; i++)
			{
				this->huffmantreeL[i] = this->huffmantreeL[i+1];
			}
		}

		else
		{
			this->huffmantreeL[second] = combine;

			for (int i = first; i < this->huffmantreeL.size() - 1; i++)
			{
				this->huffmantreeL[i] = this->huffmantreeL[i+1];
			}
		}

		this->huffmantreeL.shrink_to_fit();
		lFirst = BT(INT8_MAX);
		lSecond = BT(INT8_MAX);
	}


	// Exact process form line 75 but with distances instead
	for (int i = 0; i < 30; i++)
	{
		if (dLeafs[i].count > 0);
		{
			this->huffmantreeL.push_back(BT(total = dLeafs[i].count, d = dLeafs[i]));

		}
	}

	// Exact process as line 88 but with distances instead
	while (this->huffmantreeD.size() > 1)
	{
		for (int i = 0; i < this->huffmantreeD.size(); i++)
		{
			if (this->huffmantreeD[i].totalCount < lFirst->totalCount)
			{
				lSecond = lFirst;
				lFirst = this->huffmantreeD[i];
				second = first;
				first = i;
			}
			else if (this->huffmantreeD[i].totalCount < lSecond->totalCount)
			{
				lSecond = this->huffmantreeD[i];
				second = i;
			}
		}
		combine = BT(this->huffmantreeD[first].totalCount + this->huffmantreeD[second].totalCount, lz = this->huffmantreeD[first],
			lo = this->huffmantreeD[second])
		if (first < second)
		{
			this->huffmantreeD[first] = combine;
			for (int i = second; i < this->huffmantreeD.size() - 1; i++)
			{
				this->huffmantreeD[i] = this->huffmantreeD[i+1];
			}
		}
		else
		{
			this->huffmantreeD[second] = combine;
			for (int i = first; i < this->huffmantreeD.size() - 1; i++)
			{
				this->huffmantreeD[i] = this->huffmantreeD[i+1];
			}
		}
		this->huffmantreeD.shrink_to_fit();
		lFirst = BT(INT8_MAX);
		lSecond = BT(INT8_MAX);
	}


	ptr = &huffmantreeL[0];

	// Passing in huffmantree and starting depth of the tree
	codeCountL(ptr, 0);

	// Allocating int array to the size of the maximum bit length
	bitL = malloc(sizeof(int) * max_bitsl);

	for (int i = 0; i < max_bitsl; i++)
	{
		bitL[i] = 0;
	}

	// Counts code lengths of every huffman code
	for (int i = 0; i < 286; i++)
	{
		bitL[lLeafs[i].bitL]++;
	}

	code = 0;
	bitL[0] = 0;
	next_code = malloc(sizeof(int) * max_bitsl);

	// Finds starting code for each code length
	for (int bits = 1; bits < max_bitsl; bits++)
	{
		code = (code + bitL[bits-1]) << 1;
		next_code[bits] = code;
	}

	// Gives eac symbol its code using next_code
	for (int n = 0; n < 286; n++)
	{
		len = lLeafs[n].bitL;
		if (len != 0)
		{
			lLeafs[n].code = next_code[len];
			next_code[len]++;
		}
	}

	// The following portion of code line 230-260 is identical in purpose to
	// lines 188-227
	ptr = &huffmantreeD[0];
	codeCountD(ptr, 0);

	bitD = malloc(sizeof(int) * max_bitsd);
	for (int i = 0; i < max_bitsd; i++)
	{
		bitD[i] = 0;
	}

	for (int i = 0; i < 30; i++)
	{
		bitD[dLeafs[i].bitL]++;
	}

	code = 0
	bitD[0] = 0;
	next_code = malloc(sizeof(int) * max_bitsd);
	for (int bits = 1; bits < max_bitsl; bits++)
	{
		code = (code + bitD[bits-1]) << 1;
		next_code[bits] = code;
	}
	for (int n = 0; i < 30; i++)
	{
		len = dLeafs[n].bitL;
		if (len != 0)
		{
			dLeafs[n].code = next_code[len];
			next_code[len]++;
		}
	}

	// After this point the next step is to set up the huffman symbol table
	// for the sybols 0-18 for the code lengths huffman table.
	// Currently this is escaping me as understanding how each code will be between 0-7
	// is not completly clear
}


// Used to find the code length of each symbol.
// Updates max_bitsl to the maximum length of a single code
// Updates Leafl to store the code length of its respective symbol
void codeCountL(BT *huffmantree, int depth)
{
	// Checking for non-null BT nodes
	if (huffmantree)
	{
		if (huffmantree->LeafL)
		{
			huffmantree->LeafL.bitL = depth;
			if (depth > max_bitsl)
				max_bitsl = depth;
			return;
		}
		// Recursively parsing tree for leaf nodes
		else
		{
			codeCountL(huffmantree->zero, depth+1);
			codeCountL(huffmantree->one, depth+1);
		}
	}
	else
	{
		return;
	}
}

// Identifcal functionality to method codeCountL with the exception of 
// working with the huffman tree containing Distance symbols
void codeCountD(BT *huffmantree, int depth)
{
	if (depth == 0)
	{
		codeCountD(huffmantree->zero, 1);
		codeCountD(huffmantree->one, 1);
	}
	if (huffmantree)
	{
		if (huffmantree->LeafD)
		{
			huffmantree->LeafD.bitL = depth;
			if (depth > max_bitsd)
				max_bitsd = depth;
			return;
		}
		else
		{
			codeCountL(huffmantree->zero, depth+1);
			codeCountL(huffmantree->one, depth+1);
		}
	}
	else
	{
		return;
	}
}

// The following three methods would be used to retrieve the respective huffman tables
Huff::getLengthTable()
{

}

Huff::getDistTable()
{

}

Huff::getCodeTable()
{

}

// Deconstructor
Huff::~Huff()
{
	
}







