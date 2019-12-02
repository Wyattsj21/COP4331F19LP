// Wyatt Jones 

#include "LZ77.h"

using namespace std;

// Base constructor
LZ::LZ(){}

// Constructor to set filename
// Currently only method to set filename
LZ::LZ(const string filename)
{
	this->filename = filename;
}

// Deconstructor
LZ::~LZ()
{
	
}

// LZ77 comrpession algorithm
// Returns true on successful compression
// Retruns false on unsuccessful compression - Currently no method for determining reason of failure

bool LZ::compress()
{
	// checking for file existance and opening
	ifstream myFile;
	myFile.open(this->filename);
	if (!(myFile.is_open()))
	{
		return false;
	}
	// Declaring varibales locally
	vector<Trip> pos;				// Keeps track of index of identical strings for every character
	bool found;						// Used in determining if string is a repetition
	char search[32768] = {'\0'};	// Search Buffer 32KB in length - initalized to NULL character
	char look[258] = {'\0'};		// Look Ahead Buffer 258B in lenght - initalized to NULL character
	int j;							// Used for for loops and evaluating how long for loop ran
	int exchange = 0;				// Stores number of characters to move into Look Ahead Buffer
	
	// Putting first character in Search buffer and producing its guarenteed output 
	myFile.get(search[32767]);
	output.push_back(Triplet(0, 0, search[32767]));

	// Filling Look Ahead Buffer
	for (int i = 0; i < 96; i++)
	{
		if (myFile.eof())
		{
			break;
		}
		else
		{
			myFile.get(look[i]);
		}
	}

	// Continue until all text has passed through the Look ahead Buffer
	while(look[0] != '\0')
	{
		// Checks if the single start character in LAB is in SB
		// If the character exists in both buffers every instance inside of SB is stored in pos
		for(int i = 32767; i > -1; i--)
		{
			if (look[0] == search[i])
			{
				pos.push_back(Trip(i, 1, 1));
				found = true;
			}	
		}

		// Finds maximum length substring in SB
		// Uses indicies found and stored in pos to skip looping through every character in SB
		// TODO remove indicies of vector which do not find a match after nested for loop
		for(j = 1; j < 257; j++)
		{
			if(found)
			{
				found = false;
				for (auto itr = pos.begin(); itr != pos.end(); itr++)
				{
					if (look[j] == search[itr->distance + itr->length])
					{
						itr->follow = j + 1;
						itr->length++;
						found = true;
					}
				}
			}
			else break;
		}

		// Stores a Triplet showing 0 compression if no matching string is found
		if (pos.size() == 0)
			this->output.push_back(Triplet(0, 0, look[0]));

		// If there is a matching string then produce Triplet and store in output
		// Store length of match for when the buffers slide
		else
		{
			for (auto itr = pos.begin(); itr != pos.end(); itr++)
			{
				if (itr->follow == j  - 1)
				{
					exchange = itr->length;
					this->output.push_back(Triplet(32768 - itr->distance, itr->length, look[j-1]));
					break;
				}
			}
		}
		found = false;

		// Slides buffer by matched string plus 1
		// puts follow character at end of SB
		for (j = 0; j < exchange + 1; j++)
		{
			for (int i = 0; i < 32767; i++)
			{
				search[i] = search[i+1];
			}
			search[32767] = look[0];
			for (int i = 0; i < 257; i++)
			{
				look[i] = look[i+1];
			}
			if (myFile.eof())
			{
				look[257] = '\0';
			}
			else
			{
				myFile.get(look[257]);
			}
			pos.clear();
		}
		pos.clear();
		exchange = 0;
	}
	return true;
}

// Used for recieving output vector
vector<Triplet> getOutput()
{
	return this->output;
}