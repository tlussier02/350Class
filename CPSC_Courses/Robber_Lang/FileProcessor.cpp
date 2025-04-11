#include "FileProcessor.h"
#include "Translator.h"
#include <fstream>  
#include <iostream>   
FileProcessor::FileProcessor() {
}

FileProcessor::~FileProcessor() {
}

void FileProcessor::processFile(string inputFile, string outputFile) 
{

  ifstream inFile(inputFile);
  if (!inFile.is_open()) {
    cerr << "Could not open input file: " << inputFile << endl;
    return;
  }

  ofstream outFile(outputFile);
  if (!outFile.is_open()) {
    cerr << "Could not open output file: " << outputFile << endl;
    return;
  }


  outFile << "<html>\n<body>\n";
  Translator translator;
  string line;

  
  while (getline(inFile, line)) {

    outFile << "<b>" << line << "</b><br>\n";
    string translation = translator.translateEnglishSentence(line);
    outFile << "<i>" << translation << "</i><br><br>\n";
  }

  outFile << "</body>\n</html>\n";
  inFile.close();
  outFile.close();
}
