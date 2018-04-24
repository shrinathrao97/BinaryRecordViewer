/*
 *Shrinath Rao
 *CS 3377.002
 *srr150130@utdallas.edu
 *
 * */

#include <iostream>
#include "cdk.h"
#include "myProj.h"
#include <stdint.h>
#include <string>
#include <sstream>

void readHeader(BinaryFileHeader* header){
	ifstream binInFile ("cs3377.bin", ios::in | ios::binary);
	binInFile.read((char *)header, sizeof(BinaryFileHeader));
	binInFile.close();
}

void readRecords(CDKMATRIX* myMatrix, BinaryRecord *record, BinaryFileHeader *header, int numRecords){
   	ifstream binInFile ("cs3377.bin", ios::in | ios::binary);
	binInFile.read((char*)header, sizeof(BinaryFileHeader));
	int j = 2;
	for (int i = 0; i < numRecords; i++){
		
		binInFile.read((char *)record, sizeof(BinaryRecord));
	  	setCDKMatrixCell(myMatrix, j, 1, convertToStr(record->strLength).c_str());
 		setCDKMatrixCell(myMatrix, j, 2, record->stringBuffer);
		j++;
	}


}

string convertToStr(int num){


	stringstream ss;
	string tem;
	ss << num;
	ss >> tem;
	return tem;


}

string convertToHex(int num){


	stringstream ss;
	string tem;
	ss << std::hex <<num;
	ss >> tem;
	return tem;


}
