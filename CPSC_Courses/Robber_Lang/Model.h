#ifndef MODEL_H // chatgpt helped me with this first header class, "How to link classes in headers".
#define MODEL_H
#include <string>
using namespace std;

class Model 
{
    public:
    Model();
    ~Model();
    string translateSingleConsonant(char c);


    string translateSingleVowel(char c);
};
#endif