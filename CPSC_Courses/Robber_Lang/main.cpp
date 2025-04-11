#include "FileProcessor.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
  if (argc < 3) {
    cerr << "Usage: " << argv[0] << " <inputFile> <outputFile>" << endl;
    return 1; 
  }

  string inputFile = argv[1];
  string outputFile = argv[2];

  FileProcessor fp;
  fp.processFile(inputFile, outputFile);

  return 0;
}
