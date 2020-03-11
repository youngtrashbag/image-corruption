/*
 * Author: youngtrashbag
 * Date: 06.03.2020
 * File: chunk.h
 * Description:
 * 	Header File for Chunk related functions.
 */

#include "../header.h"

class Chunk
{
	private:
		// lenth/size of the chunk in bytes (big endian)
		unsigned int _length;
		// chunk type, such as "IDAT"
		char _type[5];
		//the cyclic redundancy check number
		int _cylicRedundancyCheck;
		//the position of the first letter of the Chunk (for "IDAT" its "I")
		std::vector<unsigned char>::iterator _typePos;

		// function that get executed in the ctor
		bool _load(std::ifstream &pFile);

	public:
		// constructor
		Chunk(char pType[5], std::ifstream &pFile);
		
		// functions
		//char[5] GetType();
		int GetCRC();
		void ReCalculateCRC();

		//new
		std::vector<unsigned char>::iterator LoadTypePos(std::ifstream &pFile);
		unsigned int LoadLength();
		std::vector<unsigned char> &LoadData();
};

