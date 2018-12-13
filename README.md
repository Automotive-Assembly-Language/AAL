# Automotive-assembly-language
Custom assembly language with car themed syntax.

## Instruction Word Size: 16 bits

## Syntax Reference 
### Input / Output
______________________________________________________________________________________________________________________________
* **Intake**
  - Summary: Stores keyboard input into acc.
    - Syntax: 
      > INTAKE
    - Instruction Word breakdown: 5 digits of opcode, followed by 11 0s.
* **Exhaust**
  - Summary: Prints out acc. 
    - Syntax: 
      > EXHAUST
    - Instruction Word breakdown: 5 digits of opcode, followed by 11 0s.
* **Brake**
  - Summary: Ends the program.
    - Syntax: 
      > BRAKE
    - Instruction Word breakdown: 5 digits of opcode, followed by 11 0s.
### Arithmetic
_____________________________________________________________________________________________________________________________
* **Accelerate**
  - Summary: Adds data from given register to acc.
    - Syntax:
      > ACCELLERATE R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 3 digits to identify the register, followed by 8 0s.
* **Upshift**
  - Summary: Adds data from given array at the index represented by a given register to acc.
    - Syntax:
      > UPSHIFT AR1 R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 2 digits to identify the array register, followed by 3 digits to identify the register, followed by 6 0s.
* **Decellerate**
  - Summary: Subtracts data from given register to acc.
    - Syntax:
      > DECELLERATE R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 3 digits to identify the register, followed by 8 0s.
* **Downshift**
  - Summary: Subtracts data from given array at the index represented by a given register to acc.
    - Syntax:
      > DOWNSHIFT AR1 R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 2 digits to identify the array register, followed by 3 digits to identify the register, followed by 6 0s.
* **Turbo**
  - Summary: Multiplies data from given register to acc.
    - Syntax: 
      > TURBO R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 3 digits to identify the register, followed by 8 0s.
* **Twin Turbo**
  - Summary: Multiplies data from given array at the index represented by a given register to acc.
    - Syntax: 
      > TWINTURBO AR1 R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 2 digits to identify the array register, followed by 3 digits to identify the register, followed by 6 0s.
* **Miss Fire**
  - Summary: Divides data from given register to acc.
    - Syntax:
      > MISFIRE R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 3 digits to identify the register, followed by 8 0s.
* **Knock**
  - Summary: Divides data from given array at the index represented by a given register to acc.
    - Syntax:
      > KNOCK AR1 R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 2 digits to identify the array register, followed by 3 digits to identify the register, followed by 6 0s.
### Branch
_____________________________________________________________________________________________________________________________ 
* **Coil Over**
  - Summary: Takes it back to a given line of code to run sequentially.
    - Syntax: Will 
      > COILOVER R1    
    - Instruction Word breakdown: 5 digits of opcode, followed by 3 digits to identify the register, followed by 8 0s.
* **Skip Gear** 
  - Summary: Skips next line of code based on condition: 
    - Syntax: 
      > SKIPGEAR (C)
    - 100: Skips if AC < 0
    - 200: Skips if AC = 0
    - 300: Skips if AC > 0
    - Instruction Word breakdown: 5 digits of opcode, followed by 3 digits to identify the condition, followed by 8 0s.
       
### Data Transfering
_____________________________________________________________________________________________________________________________
* **Fuel**
  - Summary: Loads register value into acc.
    - Syntax:
      > Fuel R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 3 digits to identify the register, followed by 8 0s.
* **Refuel**
  - Summary: Loads value from index of array register into acc.
    - Syntax:
      > REFUEL AR1 R2
    - Instruction Word breakdown: 5 digits of opcode, followed by 2 digits to identify the array register, followed by 3 digits to identify the register, followed by 6 0s.
* **Console**
  - Summary: Loads value from acc into register.
    - Syntax:
      > CONSOLE R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 3 digits to identify the register, followed by 8 0s.
* **Trunk**
  - Summary: Loads value from acc into index of array register.
    - Syntax:
      > TRUNK AR1 R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 2 digits to identify the array register, followed by 3 digits to identify the register, followed by 6 0s.
### Data Managing
_____________________________________________________________________________________________________________________________
* **Flush**
  - Summary: Sets value in register to 0.
    - Syntax:
      > FLUSH R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 3 digits to identify the register, followed by 8 0s.
* **Burn Out**
  - Summary: Sets value in index of array to 0.
    - Syntax: 
      > BURNOUT AR1 R1
    - Instruction Word breakdown: 5 digits of opcode, followed by 2 digits to identify the array register, followed by 3 digits to identify the register, followed by 6 0s.
* **Inject**
  - Summary: Sets register to value.
    - Syntax:
      >INJECT R1 13
    - Instruction Word breakdown: 5 digits of opcode, followed by 3 digits to identify the register, followed by 8 digits to represent an integer.
      
  
  
