//***************************************************************************************************************
// File: assembler.cpp
// Team Members: Enrique Pesqueda, Sebastian Ruiz, Armando Miguel, Samuel Peters
// Date: December 4, 2018
// Description: This files takes in a txt file with "automotive assembly" code and creates a binary txt file to be used by our simulator.
//***************************************************************************************************************
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <string>
using namespace std;

//FILE WITH CODE TO ASSEMBLE
//***************************************************************************************************************
static const string FILETOBECONVERTED = "benchmark2.txt";
//***************************************************************************************************************

//CONVERSION FUNCTION
//***************************************************************************************************************
// Preconditions: Takes in valid file name, and three maps pertaining to registers, array registers, and opcodes.
// Postconditions: The valid filename is used to create a binary file that the simulator will use.
void codeToBinary(string codeFileName, unordered_map<string, string> registerMap, unordered_map<string, string> arrayRegisterMap, unordered_map<string, string> opcodeMap);
//***************************************************************************************************************
//Summary: takes in a string of an integer and returns that integer in binary form
string decToBin(string num);
//***************************************************************************************************************

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
    //format is opcode, register, integer
    opcodeMap["INJECT"] = "10011";
    
    //format is opcode
    opcodeMap["INTAKE"] = "00000";
    opcodeMap["EXHAUST"] = "00001";
    opcodeMap["BRAKE"] = "00010";
    
    //format is opcode, register
    opcodeMap["ACCELLERATE"] = "00011";
    opcodeMap["DECELLERATE"] = "00101";
    opcodeMap["TURBO"] = "00111";
    opcodeMap["MISFIRE"] = "01001";
    opcodeMap["COILOVER"] = "01011";
    opcodeMap["SKIPGEAR"] = "01100";
    opcodeMap["FUEL"] = "01101";
    opcodeMap["CONSOLE"] = "01111";
    opcodeMap["FLUSH"] = "10001";
    
    //format is opcode, array register, register
    opcodeMap["UPSHIFT"] = "00100";
    opcodeMap["DOWNSHIFT"] = "00110";
    opcodeMap["TWINTURBO"] = "01000";
    opcodeMap["KNOCK"] = "01010";
    opcodeMap["REFUEL"] = "01110";
    opcodeMap["TRUNK"] = "10000";
    opcodeMap["BURNOUT"] = "10010";
    
    //convert code to binary
    codeToBinary(FILETOBECONVERTED, registerMap, arrayRegisterMap, opcodeMap);
    
    return EXIT_SUCCESS;
}
//***************************************************************************************************************

//CONVERSION FUNCTION
//***************************************************************************************************************
void codeToBinary(string codeFileName, unordered_map<string, string> registerMap, unordered_map<string, string> arrayRegisterMap, unordered_map<string, string> opcodeMap) {
    
    //file being opened to read automotive assembly code from
    ifstream codeFile(codeFileName);
    if (codeFile.fail()) {
        cout << "File open failed\n";
        return;
    }
    //file being opened to hold binary representation of the code file
    ofstream binaryFile("binary.txt");
    
    //go through code file and convert it to 1s and 0s to be saved to the binary file
    while (!codeFile.eof()) {
        
        //take in opcode
        string opcode;
        codeFile >> opcode;
        //check if opcode is invalid
        if (opcodeMap.find(opcode) == opcodeMap.end()) {
            cout << "Invalid Opcode: " << opcode << endl;
            return;
        }
        //add binary to binary.txt based on formats
        else if (opcode == "INJECT") {
            string reg;
            codeFile >> reg;
            //check if register is invalid
            if (registerMap.find(reg) == registerMap.end()) {
                cout << "Invalid Register: " << reg << endl;
                return;
            }
            //take in number to store in register
            int num;
            codeFile >> num;
            if (num > 255) {
                cout << "Number is to large to store in register: " << num << endl;
                return;
            }
            
            //all is valid so write into binary file
            binaryFile << opcodeMap[opcode] << registerMap[reg] << decToBin(to_string(num)) << endl;
        }
        else if (opcode == "SKIPGEAR") {
            string condition = "";
            codeFile >> condition;
            if (condition != "100" && condition != "200" && condition != "300") {
                cout << "Invalid Condition: " << condition << endl;
                return;
            }
            if (condition == "100") {
                binaryFile << opcodeMap[opcode] << "100" << "00000000\n";
            }
            else if (condition == "200") {
                binaryFile << opcodeMap[opcode] << "110" << "00000000\n";
            }
            else if (condition == "300") {
                binaryFile << opcodeMap[opcode] << "111" << "00000000\n";
            }
        }
        else if (opcode == "INTAKE" || opcode == "EXHAUST" || opcode == "BRAKE") {
            //this format is opcode followed by 0s
            binaryFile << opcodeMap[opcode] << "00000000000\n";
        }
        else if (opcode == "ACCELLERATE" || opcode == "DECELLERATE" || opcode == "TURBO" || opcode == "MISFIRE" || opcode == "COILOVER" || opcode == "FUEL" || opcode == "CONSOLE" || opcode == "FLUSH") {
            string reg;
            codeFile >> reg;
            //check if register is invalid
            if (registerMap.find(reg) == registerMap.end()) {
                cout << "Invalid Register: " << reg << endl;
                return;
            }
            else {
                //this format is opcode followed by register followed by 0s
                binaryFile << opcodeMap[opcode] << registerMap[reg] << "00000000\n";
            }
        }
        else {
            //get array register being accessed
            string arrayReg;
            codeFile >> arrayReg;
            //check if array register is invalid
            if (arrayRegisterMap.find(arrayReg) == arrayRegisterMap.end()) {
                cout << "Invalid Array Register: " << arrayReg << endl;
                return;
            }
            //get register being used as index
            string reg;
            codeFile >> reg;
            //check if register is invalid
            if (registerMap.find(reg) == registerMap.end()) {
                cout << "Invalid Register: " << reg << endl;
                return;
            }
            
            //add items to binary file with format: opcode followed by arrayRegister followed by register
            binaryFile << opcodeMap[opcode] << arrayRegisterMap[arrayReg] << registerMap[reg] << "000000\n";
        }
    }
    //close files
    codeFile.close();
    binaryFile.close();
    //inform that assembly was successful
    cout << "Code Successfully Assembled\n";
}
//***************************************************************************************************************

//***************************************************************************************************************
//Summary: takes in a string of an integer and returns that integer in binary form
string decToBin(string num) {
    
    int decNum = stoi(num);
    if (decNum == 0) {
        return "00000000";
    }
    string toReturn = "";
    while (decNum != 0) {
        if ( (decNum % 2) == 0 ) {
            toReturn.append("0");
        }
        else {
            toReturn.append("1");
        }
        decNum /= 2;
    }
    reverse(toReturn.begin(), toReturn.end());
    while (toReturn.length() < 8) {
        toReturn = "0" + toReturn;
    }
    return toReturn;
}
//***************************************************************************************************************
