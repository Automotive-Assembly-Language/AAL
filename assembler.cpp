//***************************************************************************************************************
// File: assembler.cpp
// Team Members: Enrique Pesqueda, Sebastian Ruiz, Armando Miguel, Samuel Peters
// Last Modified: December 4, 2018
// Description: This files takes in a txt file with "automotive assembly" code and creates a binary txt file to be used by our simulator.
//***************************************************************************************************************
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <string>
using namespace std;

//MAIN
//***************************************************************************************************************
int main() {
    
    //CREATE REGISTER, ARRAY, AND OPCODE REGISTER MAPPINGS
    unordered_map<string, string> registerMap;
    registerMap["R1"] = "000";
    registerMap["R2"] = "001";
    registerMap["R3"] = "010";
    registerMap["R4"] = "011";
    registerMap["R5"] = "100";
    registerMap["R6"] = "101";
    registerMap["R7"] = "110";
    registerMap["R8"] = "111";
    
    unordered_map<string, string> arrayRegisterMap;
    arrayRegisterMap["AR1"] = "00";
    arrayRegisterMap["AR2"] = "01";
    arrayRegisterMap["AR3"] = "10";
    arrayRegisterMap["AR4"] = "11";
    
    unordered_map<string, string> opcodeMap;
    opcodeMap["INTAKE"] = "00000";
    opcodeMap["EXHAUST"] = "00001";
    opcodeMap["BRAKE"] = "00010";
    opcodeMap["ACCELLERATE"] = "00011";
    opcodeMap["UPSHIFT"] = "00100";
    opcodeMap["DECELLERATE"] = "00101";
    opcodeMap["DOWNSHIFT"] = "00110";
    opcodeMap["TURBO"] = "00111";
    opcodeMap["TWINTURBO"] = "01000";
    opcodeMap["MISFIRE"] = "01001";
    opcodeMap["KNOCK"] = "01010";
    opcodeMap["COILOVER"] = "01011";
    opcodeMap["SKIPGEAR"] = "01100";
    opcodeMap["FUEL"] = "01101";
    opcodeMap["REFUEL"] = "01110";
    opcodeMap["CONSOLE"] = "01111";
    opcodeMap["TRUNK"] = "10000";
    opcodeMap["FLUSH"] = "10001";
    opcodeMap["BURNOUT"] = "10010";
    
    
    
    
    return EXIT_SUCCESS;
}
//***************************************************************************************************************




