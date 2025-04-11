#include "Model.h"
#include <cctype> 

Model::Model() {

}

Model::~Model() {

}


string Model::translateSingleConsonant(char c)
{
    bool isUpper = isupper(c);
    char lower = tolower(c);

    string result;
    result.push_back(c);
    result.push_back('o');
    result.push_back(lower);
 return result;
}
string Model::translateSingleVowel(char c) 
{

  string result(1, c); // 1 is size denoted by n and c is char
  return result;
}