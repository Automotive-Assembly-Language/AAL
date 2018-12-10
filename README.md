# Automotive-assembly-language
Custom assembly language with car themed syntax.

## Syntax Reference 
### Input / Output
______________________________________________________________________________________________________________________________
* **Intake**
  - Summary: Stores keyboard input into acc.
    - Syntax: 
      > INTAKE
* **Exhaust**
  - Summary: Prints out acc. 
    - Syntax: 
      > EXHAUST

* **Brake**
  - Summary: Ends the program.
    - Syntax: 
      > BRAKE
### Arithmetic
_____________________________________________________________________________________________________________________________
* **Accelerate**
  - Summary: Adds data from given register to acc.
    - Syntax:
      > ACCELLERATE R1
* **Upshift**
  - Summary: Adds data from given array at the index represented by a given register to acc.
    - Syntax:
      > UPSHIFT AR1 R1
* **Decellerate**
  - Summary: Subtracts data from given register to acc.
    - Syntax:
      > DECELLERATE R1
* **Downshift**
  - Summary: Subtracts data from given array at the index represented by a given register to acc.
    - Syntax:
      > DOWNSHIFT AR1 R1
* **Turbo**
  - Summary: Multiplies data from given register to acc.
    - Syntax: 
      > TURBO R1
* **Twin Turbo**
  - Summary: Multiplies data from given array at the index represented by a given register to acc.
    - Syntax: 
      > TWINTURBO AR1 R1
* **Miss Fire**
  - Summary: Divides data from given register to acc.
    - Syntax:
      > MISSFIRE R1
* **Knock**
  - Summary: Divides data from given array at the index represented by a given register to acc.
    - Syntax:
      > KNOCK AR1 R1
### Branch
_____________________________________________________________________________________________________________________________ * **Coil Over**
  - Summary: Takes it back to a given line of code to run sequentially.
    - Syntax: Will 
      > COILOVER 1    
* **Skip Gear** 
  - Summary: Skips next line of code based on condition: 
    - Syntax: 
      > SKIPGEAR (C)
    - 100: Skips if AC < 0
    - 200: Skips if AC = 0
    - 300: Skips if AC > 0
       
### Data Transfering
_____________________________________________________________________________________________________________________________
* **Fuel**
  - Summary: Loads register value into acc.
    - Syntax:
      > Fuel R1
* **Refuel**
  - Summary: Loads value from index of array register into acc.
    - Syntax:
      > REFUEL AR1 R2
* **Console**
  - Summary: Loads value from acc into register.
    - Syntax:
      > CONSOLE R1
* **Trunk**
  - Summary: Loads value from acc into index of array register.
    - Syntax:
      > TRUNK AR1 R1
### Data Managing
_____________________________________________________________________________________________________________________________
* **Flush**
  - Summary: Sets value in register to 0.
    - Syntax:
      > FLUSH R1
* **Burn Out**
  - Summary: Sets value in index of array to 0.
    - Syntax: 
      > BURNOUT AR1 R1
  
  
