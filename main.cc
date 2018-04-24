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



#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20 
#define MATRIX_NAME_STRING "Binary Record Viewer"

using namespace std;


int main() {

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[] = {"a", "a", "b", "c", "d", "e"};
  const char 		*columnTitles[] = {"a", "a", "b", "c", "d", "e"};
  int		boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED,  vMIXED,  vMIXED};

  window = initscr();
  cdkscreen = initCDKScreen(window);

  initCDKColor();

  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL) {
  
      printf("Error creating Matrix\n");
      _exit(1);
  
  }

  drawCDKMatrix(myMatrix, true);

  BinaryFileHeader *header = new BinaryFileHeader();
  BinaryRecord *record = new BinaryRecord();
  readHeader(header);
  readRecords(myMatrix, record, header, header->numRecords);
  
  setCDKMatrixCell(myMatrix, 1, 1, convertToHex(header->magicNumber).c_str());
  setCDKMatrixCell(myMatrix, 1, 2, convertToStr(header->versionNumber).c_str());
  setCDKMatrixCell(myMatrix, 1, 3, convertToStr(header->numRecords).c_str());

  drawCDKMatrix(myMatrix, true);    /* required  */
  unsigned char x;
  cin >> x;
  endCDK();
}



