/*
Full name: Trevor Lussier
Student ID: 2445730
Chapman email: tlussier@chapman.edu
Course number and section: CPSC 350-04
Assignment or exercise number: PA3 (Do You See What I See?)
*/

#include "SpeakerView.h"
#include "MonoStack.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

SpeakerView::SpeakerView() {
    seats = nullptr;
    numRows = 0;
    numCols = 0;
}

SpeakerView::~SpeakerView() {
    freeSeats();
}

void SpeakerView::allocateSeats(int r, int c) {
    numRows = r;
    numCols = c;
    seats = new double*[r];
    for (int i = 0; i < r; ++i) {
        seats[i] = new double[c];
    }
}

void SpeakerView::freeSeats() {
    if (seats) {
        for (int i = 0; i < numRows; ++i) {
            delete[] seats[i];
        }
        delete[] seats;
        seats = nullptr;
        numRows = 0;
        numCols = 0;
    }
}

void SpeakerView::loadFile(const std::string &filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw std::runtime_error("SpeakerView::loadFile - cannot open file: " + filename);
    }
    bool readingData = false;
    std::string lines[500]; 
    int rowCount = 0;

    std::string line;
    while (std::getline(inFile, line)) {
        if (line == "BEGIN") {
            readingData = true;
            continue;
        }
        if (line == "END") {
            readingData = false;
            break;
        }
        if (readingData) {
            lines[rowCount++] = line;
        }
    }
    inFile.close();

    if (rowCount == 0) {
        throw std::runtime_error("No seat data found between BEGIN and END");
    }

    // parse first line => numCols
    {
        std::stringstream ss(lines[0]);
        double tmp;
        int colCount = 0;
        while (ss >> tmp) {
            colCount++;
        }
        allocateSeats(rowCount, colCount);
    }

    // fill seats in row=0..rowCount-1 order
    for (int r = 0; r < rowCount; ++r) {
        std::stringstream ss(lines[r]);
        for (int c = 0; c < numCols; ++c) {
            double val;
            ss >> val;
            seats[r][c] = val; // row r
        }
    }
}

void SpeakerView::processAndPrint() {
    // We do a "monotonically decreasing" stack => pop all smaller
    // But we read from row=(numRows-1)..0. 
    // => occupant in row 0 is pushed last, 
    // => if occupant in row 0 is bigger, it pops smaller occupant behind it,
    // => final occupant sets match the sample exactly 
    // (81.4 remains if occupant behind is smaller, etc.)

    for (int col = 0; col < numCols; ++col) {
        MonoStack<double> stack(numRows, 'd'); 
         // 'd' => "pop all smaller"

        // read from the *back* row = (numRows-1) down to row=0
        for (int row = numRows - 1; row >= 0; --row) {
            double h = seats[row][col];
            stack.push(h); 
        }

        // Now occupant in row=0 was pushed last => if occupant in row=0 is bigger,
        // it popped any smaller occupant behind them => matches the sample occupant sets.

        // pop them out
        double* reversed = new double[numRows];
        int count = 0;
        while (!stack.isEmpty()) {
            reversed[count++] = stack.pop();
        }
        // reversed[0] = occupant from row=0, reversed[count-1] = occupant from row=(numRows-1)
        // So occupant from row=0 is reversed[0], occupant from row=1 is reversed[1], etc.

        std::cout << "In column " << col 
                  << " there are " << count
                  << " that can see. Their heights are: ";
        for (int i = 0; i < count; ++i) {
            std::cout << reversed[i];
            if (i < count - 1) {
                std::cout << ", ";
            }
        }
        std::cout << " inches.\n";

        delete[] reversed;
    }
}
