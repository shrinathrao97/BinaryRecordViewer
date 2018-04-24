#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>
#include <sstream>
#include "cdk.h"


using namespace std;
const int maxRecordStringLength = 25;

class BinaryFileHeader{


	public:
	 	uint32_t magicNumber;
		uint32_t versionNumber;
		uint64_t numRecords;

};


class BinaryRecord{

	public:
		 uint8_t strLength;
                 char stringBuffer[maxRecordStringLength];
};





void readHeader(BinaryFileHeader *header);
void readRecords(CDKMATRIX *myMarix, BinaryRecord *record, BinaryFileHeader *header, int numRecords);
string convertToStr(int num);
string convertToHex(int num);
