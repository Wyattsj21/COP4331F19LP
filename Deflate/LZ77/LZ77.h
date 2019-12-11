// Wyatt Jones


#ifndef DL_LZ_H
#define DL_LZ_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

// LZ77 class for compressing files using repeated strings
class LZ
{
	private:
		// nested Triplet struct used for storing the three-tuple used in LZ compression
		struct Triplet
		{
			int distance;
			int length;
			int follow;		
			


			//Constructor
			Triplet(int d = 0, int l = 0, int c = 0)
			{
				this->distance = d;
				this->length = l;
				this->follow = c;
			}
			
		};

		// nested Trip struct used for processing buffers
		struct Trip
		{
			int distance;
			int length;
			int follow;		
			


			//Constructor
			Trip(int d = 0, int l = 0, int c = 0)
			{
				this->distance = d;
				this->length = l;
				this->follow = c;
			}
			
		};

	// method declarations
	// Find functions in LZ77.hpp
	public:
		LZ();
		LZ(const string filename);
		bool compress();			
		~LZ(); 
		vector<Triplet> getOutput();

	private:
		string filename;			// location of file to be compressed
		vector<Triplet> output;		// stores all tuples after compression
};

#include "LZ77.hpp"

#endif
