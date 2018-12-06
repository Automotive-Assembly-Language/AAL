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
    
    //open binary.txt file to read instructions from
    string binaryFileName = "binary.txt";
    ifstream binaryFile(binaryFileName);
    if (binaryFile.fail()) {
        cout << "binary file open failed\n";
        return;
    }
    
    //go through binary.txt file and simulate code
    while (!binaryFile.eof()) {
        
        //take in instruction
        string instruction;
        binaryFile >> instruction;
        
        //get opcode from instruction
        string opcode;
        opcode = instruction.substr(0, 5);
        
        //opcode with format: opcode then 0s
        if (opcode == "00000") {
            <#statements#>
        }
        else if (opcode == "00001") {
            <#statements#>
        }
        else if (opcode == "00010") {
            <#statements#>
        }
        //opcode with format: opcode, register, then 0s
        else if (opcode == "00011") {
            <#statements#>
        }
        else if (opcode == "00101") {
            <#statements#>
        }
        else if (opcode == "00111") {
            <#statements#>
        }
        else if (opcode == "01001") {
            <#statements#>
        }
        else if (opcode == "01011") {
            <#statements#>
        }
        else if (opcode == "01100") {
            <#statements#>
        }
        else if (opcode == "01101") {
            <#statements#>
        }
        else if (opcode == "01111") {
            <#statements#>
        }
        else if (opcode == "10001") {
            <#statements#>
        }
        //opcode with format: opcode, array register, register, then 0s
        else if (opcode == "00100") {
            <#statements#>
        }
        else if (opcode == "00110") {
            <#statements#>
        }
        else if (opcode == "01000") {
            <#statements#>
        }
        else if (opcode == "01010") {
            <#statements#>
        }
        else if (opcode == "01110") {
            <#statements#>
        }
        else if (opcode == "10000") {
            <#statements#>
        }
        else if (opcode == "10010") {
            <#statements#>
        }
        else {
            cout << "Invalid Opcode: " << opcode << endl;
            return;
        }
    }
    
    //close binary file
    binaryFile.close();
    
    return EXIT_SUCCESS;
}
//***************************************************************************************************************
