/*
Full name: Trevor Lussier
Student ID: 2445730
Chapman email: tlussier@chapman.edu
Course number and section: CPSC 350-04
Assignment or exercise number: PA3 (Do You See What I See?)
*/

#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include <string>

/*
  SpeakerView:
   - processAndPrint() uses a 'd' stack => pop all smaller, 
     iterating from row=(numRows-1) down to row=0, 
     yielding occupant sets exactly matching the sample output
*/

class SpeakerView {
public:
    SpeakerView();
    ~SpeakerView();

    void loadFile(const std::string &filename);
    void processAndPrint();

private:
    double** seats;
    int numRows;
    int numCols;

    void allocateSeats(int r, int c);
    void freeSeats();
};

#endif
