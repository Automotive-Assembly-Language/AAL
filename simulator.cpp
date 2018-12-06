//***************************************************************************************************************
// File: simulator.cpp
// Team Members: Enrique Pesqueda, Sebastian Ruiz, Armando Miguel, Samuel Peters
// Date: December 4, 2018
// Description: This file interprets the binary.txt file that was created by the assembler.cpp file, and runs the program
//***************************************************************************************************************
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

//MAIN
//***************************************************************************************************************
int main() {
    
    //CREATE ACCUMULATOR REGISTER
    int acc;
    
    //CREATE REGISTER, ARRAY, AND OPCODE REGISTER MAPPINGS
    unordered_map<string, int> registerMap;
    registerMap["000"] = 0;
    registerMap["001"] = 0;
    registerMap["010"] = 0;
    registerMap["011"] = 0;
    registerMap["100"] = 0;
    registerMap["101"] = 0;
    registerMap["110"] = 0;
    registerMap["111"] = 0;
    
    unordered_map<string, vector<int> > arrayRegisterMap;
    vector<int> arrayVector;
    arrayVector.resize(100);
    for (int i = 0; i < 100; ++i) {
        arrayVector[i] = 0;
    }
    arrayRegisterMap["00"] = arrayVector;
    arrayRegisterMap["01"] = arrayVector;
    arrayRegisterMap["10"] = arrayVector;
    arrayRegisterMap["11"] = arrayVector;
    
    unordered_set<string> opcodeMap;
    //format is opcode
    opcodeMap.insert("00000");
    opcodeMap.insert("00001");
    opcodeMap.insert("00010");
    
    //format is opcode, register
    opcodeMap.insert("00011");
    opcodeMap.insert("00101");
    opcodeMap.insert("00111");
    opcodeMap.insert("01001");
    opcodeMap.insert("01011");
    opcodeMap.insert("01100");
    opcodeMap.insert("01101");
    opcodeMap.insert("01111");
    opcodeMap.insert("10001");
    
    //format is opcode, array register, register
    opcodeMap.insert("00100");
    opcodeMap.insert("00110");
    opcodeMap.insert("01000");
    opcodeMap.insert("01010");
    opcodeMap.insert("01110");
    opcodeMap.insert("10000");
    opcodeMap.insert("10010");

    
    
    return EXIT_SUCCESS;
}
//***************************************************************************************************************
