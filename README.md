# Project-in-C-language
writing assembler software for assembled language specifically set for this project

The role of the assembler is to produce raw machine code for a program program written in assembly language.
This is the first step in the path that the program goes through, until you get a code ready to run on the computer hardware.

Defining the assembly language and the imaginary computer model, for this project:
The computer in the project consists of a central processing unit, registers and RAM, when part
From memory also serves as a stack.
The size of a computer memory word is 14 bits.
Arithmetic is done using the complementary method for 2
This computer only works with positive and negative integers, no real numbers are supported.
 
Registers:
The processor has 8 general registers (r0, r1, r2, r3, r4, r5, r6, r7)
The size of each hamster is 14 bits. The least significant bit will be specified as bit number 0, and the most significant bit as number 13.
 
The processor also has a register called PSW (word status program), which contains a number of flags that characterize the activity state in the processor at any given moment.
 
The memory size is 256 cells, in addresses (255-0) at a decimal base, and each cell is 14 bits in size.
A cell in memory is also called a "word."
 
Character encoding is done in ascii code.
 
Machine teaching structure:
Each machine instruction encodes several memory words, from one word to a maximum of four words,
All depending on the addressing methods used. In all types of instructions, the structure of
The first word is the same. The structure of the first word in the instruction is as follows:


![image](https://user-images.githubusercontent.com/61827476/137619239-ec94a410-6c19-4f3b-bdbb-cedb6ecdec11.png)
