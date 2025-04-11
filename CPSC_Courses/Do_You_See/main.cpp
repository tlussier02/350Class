/*
Full name: Trevor Lussier
Student ID: 2445730
Chapman email: tlussier@chapman.edu
Course number and section: CPSC 350-04
Assignment or exercise number: PA3 (Do You See What I See?)
*/

#include "SpeakerView.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <inputFile>\n";
        return 1;
    }
    try {
        SpeakerView sv;
        sv.loadFile(argv[1]);
        sv.processAndPrint();
    }
    catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
