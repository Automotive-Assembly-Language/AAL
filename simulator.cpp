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
        return EXIT_SUCCESS;
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
            cin >> acc;
        }
        else if (opcode == "00001") {
            cout << acc << endl;
        }
        else if (opcode == "00010") {
            return EXIT_SUCCESS;
        }
        //opcode with format: opcode, register, then 0s
        else if (opcode == "00011") {
            string reg = instruction.substr(5,3);
            auto it = registerMap.find(reg);
            
            if(it == registerMap.end()){
                cout << reg << " is not a valid register" << endl;
                return EXIT_SUCCESS;
            }
            acc += registerMap[reg];
        }
        else if (opcode == "00101") {
            string arrReg = instruction.substr(5,2);
            string reg = instruction.substr(9,3);
            auto itArray = arrayRegisterMap.find(arrReg);
            auto itRef = registerMap.find(reg);
            if(itArray == arrayRegisterMap.end()){
                cout << arrReg << " is not a valid array register" << endl;
                return EXIT_SUCCESS;
            }        
            else if(itRef == registerMap.end()){
                cout << reg << " is not a valid register" << endl;
                return EXIT_SUCCESS;
            }
            acc += arrayRegisterMap[arrReg][registerMap[reg]];
            
        }
        else if (opcode == "00111") {

        }
        else if (opcode == "01001") {

        }
        else if (opcode == "01011") {

        }
        else if (opcode == "01100") {

        }
        else if (opcode == "01101") {

        }
        else if (opcode == "01111") {

        }
        else if (opcode == "10001") {

        }
        //opcode with format: opcode, array register, register, then 0s
        else if (opcode == "00100") {

        }
        else if (opcode == "00110") {
            
        }
        else if (opcode == "01000") {
            
        }
        else if (opcode == "01010") {
            
        }
        else if (opcode == "01110") {
            
        }
        else if (opcode == "10000") {
            
        }
        else if (opcode == "10010") {
            
        }
        else {
            cout << "Invalid Opcode: " << opcode << endl;
            return EXIT_SUCCESS;
        }
    }
    
    
    return EXIT_SUCCESS;
}
//***************************************************************************************************************
