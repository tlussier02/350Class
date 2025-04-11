#include "Translator.h"
#include "Model.h"
#include <cctype>
Translator::Translator() {
}

Translator::~Translator() {
}
string Translator::translateEnglishWord(string word) 
{
    Model model;
    string result;
    for (char c : word) {
        if (isalpha(c)) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                result += model.translateSingleVowel(c);
            } else {
                result += model.translateSingleConsonant(c);
            }
        } else {
            result.push_back(c);
        }
    }
    return result;
}

string Translator::translateEnglishSentence(string sentence) 
{
    Model model;
    string result;
    for (char c : sentence) {
        if (isalpha(c)) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                result += model.translateSingleVowel(c);
            } else {
                result += model.translateSingleConsonant(c);
            }
        } else {
            result.push_back(c);
        }
    }
    return result;
}
