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
#include <stack>
using namespace std;

//***************************************************************************************************************
//summary: This function takes in a string of a binary number and returns a string of that number in decimal.
string binToDec(string bin);
//***************************************************************************************************************

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
//        
//        //print registers
//        cout << "R1: " << registerMap["000"] << endl;
//        cout << "R2: " << registerMap["001"] << endl;
//        cout << "R3: " << registerMap["010"] << endl;
//        cout << "R4: " << registerMap["011"] << endl;
//        cout << "R5: " << registerMap["100"] << endl;
//        cout << "R6: " << registerMap["101"] << endl;
//        cout << "R7: " << registerMap["110"] << endl;
//        cout << "R8: " << registerMap["111"] << endl;

        //take in instruction
        string instruction;
        binaryFile >> instruction;

        //get opcode from instruction
        string opcode;
        opcode = instruction.substr(0, 5);

        //opcode with format: opcode then 0s
        if (opcode == "00000") {
            cout << "Input: ";
            cin >> acc;
        }
        else if (opcode == "00001") {
            cout << "Output: " << acc << endl;
        }
        else if (opcode == "00010") {
            cout << "Program Terminated\n";
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
        //***************************************************************************************************************
        //JUMP FUNCTION
        //***************************************************************************************************************
        // Preconditions: Checks if the Register Map is valid.
        // Postconditions: If valid jumps to the line of code based on integer value in register.
        else if (opcode == "01011") {
          string reg = instruction.substr(5,3);
          auto it = registerMap.find(reg);
          if(it == registerMap.end()){
            cout << reg << " is not a valid register" << endl;
            return EXIT_SUCCESS;
          }
            binaryFile.close();
            binaryFile.open(binaryFileName);
          for(int i = 0; i < registerMap[reg] - 1; ++i){
              binaryFile >> instruction;
          }
        }

        else if (opcode == "01100") {
          string cond = instruction.substr(5,3);
          if(cond == "100" && acc < 0)
            binaryFile >> instruction;
          else if(cond == "110" && acc == 0)
            binaryFile >> instruction;
          else if(cond == "111" && acc > 0)
            binaryFile >> instruction;
        }

        else if (opcode == "01101") {
          string reg = instruction.substr(5,3);
          auto it = registerMap.find(reg);
          if(it == registerMap.end()){
              cout << reg << " is not a valid register" << endl;
              return EXIT_SUCCESS;
              }
          acc = registerMap[reg];
        }

        else if (opcode == "01111") {
            string reg = instruction.substr(5,3);
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
            string reg = instruction.substr(5,3);
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
            acc /= arrayRegisterMap[arrReg][registerMap[reg]];
        }

        else if (opcode == "01110") {
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
          acc = arrayRegisterMap[arrReg][registerMap[reg]];
        }
        //***************************************************************************************************************
        //TRUNK FUNCTION
        //***************************************************************************************************************
        // Preconditions: Checks if the Array Register Map and the Register Map is valid.
        // Postconditions: If both are valid then, set the Register Map to the Acc.
        else if (opcode == "10000") {
            string arrReg = instruction.substr(5,2);
            if(arrayRegisterMap.find(arrReg) == arrayRegisterMap.end()){
                cout<<"Invalid Array Register Map: "<<arrReg<<endl;
                return EXIT_SUCCESS;
            }
            else{
                string reg = instruction.substr(7,3);
                if(registerMap.find(reg)== registerMap.end()){
                    cout<<"Invalid Register Map: "<< reg <<endl;
                    return EXIT_SUCCESS;
                }
                else{
                    (arrayRegisterMap[arrReg])[registerMap[reg]] = acc;
                }
            }
        }
        //***************************************************************************************************************
        //BURNOUT FUNCTION
        //***************************************************************************************************************
        // Preconditions:Checks if the Array Register Map and the Register Map is valid.
        // Postconditions: If both are valid then, set the Register Map to 0.
        else if (opcode == "10010") {
            string arrReg = instruction.substr(5,2);
            if(arrayRegisterMap.find(arrReg) == arrayRegisterMap.end()){
                cout<<"Invalid Array Register Map: "<<arrReg<<endl;
                return EXIT_SUCCESS;
            }
            else{
                string reg = instruction.substr(7,3);
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
        else if (opcode == "10011") {
            //get register and check if it is valid
            string reg = instruction.substr(5, 3);
            if (registerMap.find(reg) == registerMap.end()) {
                cout << "Invalid Register: " << reg << endl;
                return EXIT_SUCCESS;
            }
            //get integer to store
            string num = instruction.substr(8, 8);
            
            //insert value into register
            registerMap[reg] = stoi(binToDec(num));
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

//**********************************************************************
//summary: This function takes in a string of a binary number and returns a string of that number in decimal.
string binToDec(string bin) {
    if (bin == "0") {
        return bin;
    }
    stack<char> binStack;
    for (int i = 0; i < bin.length(); i++) {
        binStack.push(bin[i]);
    }
    int multiplier = 1;
    int sum = 0;
    while (!binStack.empty()) {
        if (binStack.top() == '1') {
            sum += multiplier;
        }
        binStack.pop();
        multiplier *= 2;
    }
    return to_string(sum);
}
//**********************************************************************
