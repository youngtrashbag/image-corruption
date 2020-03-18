/*
 * Author: youngtrashbag
 * Date: 18.03.2020
 * File: crc.cpp
 * Description:
 * 	Functions and Code related to the Calculation
 * 	of the CRC a.k.a. CRC32 code in the Images
 */

#include "chunk.h"

using namespace std;

// this function loads the crc
int Chunk::LoadCRC()
{
	// add the remaining 3 chars of the type and the length of the chunk, to see the crc
	vector<unsigned char>::iterator crcFinder = _typePos + 4 + _length;

	// get size of chunk
	unsigned char charCRCArray[5] = {
		*(crcFinder),
		*(crcFinder + 1),
		*(crcFinder + 2),
		*(crcFinder + 3)
	};

	int cyclicRedundancyCheck = 0;

	for(int i = 0; i <= 4; i++)
	{
		cyclicRedundancyCheck += charCRCArray[i] << 1;
	}

	cyclicRedundancyCheck = cyclicRedundancyCheck >> 1;
	return cyclicRedundancyCheck;
}

void Chunk::ReCalculateCRC()
{
}
