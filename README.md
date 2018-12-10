# Automotive-assembly-language
Custom assembly language with car themed syntax.

## Syntax Reference 
### Input / Output
1. Intake
  - Summary: Stores keyboard input into acc.
    - Syntax: 
      > INTAKE
2. Exhaust
  - Summary: Prints out acc. 
    - Syntax: 
      > EXHAUST

3. Brake
  - Summary: Ends the program.
    - Syntax: 
      > BRAKE
### Arithmetic
* Accelerate
  - Summary: Adds data from given register to acc.
    - Syntax:
      > ACCELLERATE R1
* Upshift
  - Summary: Adds data from given array at the index represented by a given register to acc.
    - Syntax:
      > UPSHIFT AR1 R1
* Decellerate
  - Summary: Subtracts data from given register to acc.
    - Syntax:
      > DECELLERATE R1
* Downshift 
  - Summary: Subtracts data from given array at the index represented by a given register to acc.
    - Syntax:
      > DOWNSHIFT AR1 R1
* Turbo
  - Summary: 
    - Syntax: Multiplies data from given register 
      > TURBO R1
      
      
