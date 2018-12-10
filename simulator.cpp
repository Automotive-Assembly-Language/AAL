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
    int acc = 0;

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
            //DECELLERATE(subtract opcode)

            //take in next 3 values from instruction, which are the register to use
            string reg = instruction.substr(5, 3);
            //check if register is valid
            if (registerMap.find(reg) == registerMap.end()) {
                cout << "Invalid Register: " << reg << endl;
                return EXIT_SUCCESS;
            }
            //since register is valid subtract value in reg from acc
            acc -= registerMap[reg];
        }
        else if (opcode == "00111") {
            //TURBO(multiply opcode)

            //take in next 3 values from instruction, which are the register to use
            string reg = instruction.substr(5, 3);
            //check if register is valid
            if (registerMap.find(reg) == registerMap.end()) {
                cout << "Invalid Register: " << reg << endl;
                return EXIT_SUCCESS;
            }
            //since register is valid, multiply value in reg from acc
            acc *= registerMap[reg];
        }
        else if (opcode == "01001") {
            //MISFIRE(divide opcode)

            //take in next 3 values from instruction, which are the register to use
            string reg = instruction.substr(5, 3);
            //check if register is valid
            if (registerMap.find(reg) == registerMap.end()) {
                cout << "Invalid Register: " << reg << endl;
                return EXIT_SUCCESS;
            }
            //since register is valid, divide value in reg from acc
            acc /= registerMap[reg];
        }
        else if (opcode == "01011") {

        }
        else if (opcode == "01100") {

        }
        else if (opcode == "01101") {

        }
        //***************************************************************************************************************
        //CONSOLE FUNCTION
        //***************************************************************************************************************
        // Preconditions: Checks if the Register Map is valid.
        // Postconditions: If valid set the found Register Map equal to the Acc.
        else if (opcode == "01111") {
            string reg = instruction.substr(5,3)
            if(registerMap.find(reg)== registerMap.end()){
                cout<< "Invalid Register Map: " << reg <<endl;
                return EXIT_SUCCESS;
            }
            else{
                registerMap[reg] = acc;
            }
        }
        //***************************************************************************************************************
        //FLUSH FUNCTION
        //***************************************************************************************************************
        // Preconditions: Checks if the Register Map is valid.
        // Postconditions: If valid set the found Register Map equal to 0.
        else if (opcode == "10001") {
            string reg = instruction.substr(5,3)
            if(registerMap .find(reg) == registerMap.end()){
                cout<< "Invalid Register Map: " << reg <<endl;
                return EXIT_SUCCESS;
            }
            else{
                registerMap[reg] = 0;
            }

        }
        //***************************************************************************************************************
        //opcode with format: opcode, array register, register, then 0s
        else if (opcode == "00100") {
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
        else if (opcode == "00110") {
            //DOWNSHIFT(subtract array value opcode)

            //check next 2 bits in instruction to get array register, then see if it is valid
            string arrayReg = instruction.substr(5, 2);
            if (arrayRegisterMap.find(arrayReg) == arrayRegisterMap.end()) {
                cout << "Invalid Array Register: " << arrayReg << endl;
                return EXIT_SUCCESS;
            }
            //since array register is valid, get register and check if it is valid
            string reg = instruction.substr(7, 3);
            if (registerMap.find(reg) == registerMap.end()) {
                cout << "Invalid Register: " << reg << endl;
                return EXIT_SUCCESS;
            }
            //since array register and register are valid, check reg to make sure it contains a valid index (0-99)
            if (registerMap[reg] > 99 || registerMap[reg] < 0) {
                cout << "Invalid Index: " << registerMap[reg] << endl;
                return EXIT_SUCCESS;
            }
            //since everything is valid, subtract from acc
            acc -= (arrayRegisterMap[arrayReg])[(registerMap[reg])];
        }
        else if (opcode == "01000") {
            //TWINTURBO(multiply array value opcode)

            //check next 2 bits in instruction to get array register, then see if it is valid
            string arrayReg = instruction.substr(5, 2);
            if (arrayRegisterMap.find(arrayReg) == arrayRegisterMap.end()) {
                cout << "Invalid Array Register: " << arrayReg << endl;
                return EXIT_SUCCESS;
            }
            //since array register is valid, get register and check if it is valid
            string reg = instruction.substr(7, 3);
            if (registerMap.find(reg) == registerMap.end()) {
                cout << "Invalid Register: " << reg << endl;
                return EXIT_SUCCESS;
            }
            //since array register and register are valid, check reg to make sure it contains a valid index (0-99)
            if (registerMap[reg] > 99 || registerMap[reg] < 0) {
                cout << "Invalid Index: " << registerMap[reg] << endl;
                return EXIT_SUCCESS;
            }
            //since everything is valid, multiply from acc
            acc *= (arrayRegisterMap[arrayReg])[(registerMap[reg])];
        }
        else if (opcode == "01010") {

        }
        else if (opcode == "01110") {

        }
        //***************************************************************************************************************
        //TRUNK FUNCTION
        //***************************************************************************************************************
        // Preconditions: Checks if the Array Register Map and the Register Map is valid.
        // Postconditions: If both are valid then, set the Register Map to the Acc.
        else if (opcode == "10000") {
            string arrReg = instructions.substr(5,2);
            if(arrayRegisterMap.find(arrReg) == arrayRegisterMap.end()){
                cout<<"Invalid Array Register Map: "<<arrReg<<endl;
                return EXIT_SUCCESS;
            }
            else{
                string reg = instructions.substr(7,3);
                if(registerMap.find(reg)== registerMap.end()){
                    cout<<"Invalid Register Map: "<< reg <<endl;
                    return EXIT_SUCCESS;
                }
                else{
                    registerMap[reg] = acc;
                }
            }
        }
        //***************************************************************************************************************
        //BURNOUT FUNCTION
        //***************************************************************************************************************
        // Preconditions:Checks if the Array Register Map and the Register Map is valid.
        // Postconditions: If both are valid then, set the Register Map to 0.
        else if (opcode == "10010") {
            string arrReg = instructions.substr(5,2);
            if(arrayRegisterMap.find(arrReg) == arrayRegisterMap.end()){
                cout<<"Invalid Array Register Map: "<<arrReg<<endl;
                return EXIT_SUCCESS;
            }
            else{
                string reg = instructions.substr(7,3);
                if(registerMap.find(reg)== registerMap.end()){
                    cout<<"Invalid Register Map: "<< reg <<endl;
                    return EXIT_SUCCESS;
                }
                else{
                    registerMap[reg] = 0;
                }
            }
        }
        //***************************************************************************************************************
        else {
            cout << "Invalid Opcode: " << opcode << endl;
            return EXIT_SUCCESS;
        }
    }

    //close binary file
    binaryFile.close();

    return EXIT_SUCCESS;
}
//***************************************************************************************************************
