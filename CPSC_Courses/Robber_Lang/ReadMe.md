

# README

**Full Name:** Trevor Lussier 
**Student ID:** 2445730
**Chapman Email:** tlussier@chapman.edu
**Course Number and Section:** CPSC 350-01  
**Assignment Number:** 1 (Robber Language Translation)

---

## 1. List of Source Files

1. `main.cpp`
2. `Model.cpp`
3. `Translator.cpp`
4. `FileProcessor.cpp`
5. `Model.h`
6. `Translator.h`
7. `FileProcessor.h`



## 2. Description of Known Compile/Runtime Errors or Deviations

- **Compile Errors:** None known at this time.
- **Runtime Errors:** None observed during testing with various input files.

---

## 3. Code Limitations

- The code does not handle extended alphabetical characters. Only standard English alphabets are tested.
- No advanced punctuation handling beyond leaving non-alphabetic characters unchanged.
- Vowels are  `A, E, I, O, U`. Y is treated as a consonant.

---

## 4. References and Help

- **C++ reference** for string and IO: https://en.cppreference.com
- **ChatGPT** for clarifications on specific syntax (cited in comments where relevant)
- https://www.youtube.com/watch?v=s0g4ty29Xgg&list=PLBlnK6fEyqRh6isJ01MBnbNpV3ZsktSyS basic sytax when starting i followed his introduction video 

---

## 5. Instructions for Running the Assignment

1. **Compilation:**  
   g++ -std=c++11 main.cpp FileProcessor.cpp Translator.cpp Model.cpp -o A1.exe

2. **Execution:**  
   ./A1.exe input.txt output.html

   - `input.txt` is a plain text file containing English sentences.
   - `output.html` is the generated HTML file containing both the original text (in **bold**) and the Rövarspråket translation (in *italics*).  
   - Open `output.html` in a web browser to see the formatted output.

---

**End of README**