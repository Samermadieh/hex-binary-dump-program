//Name: Samer Madieh
//File Name: dump.cpp
//Description: C++ source code for program that prints the contents of any regular file in hexadecimal/binary.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <bitset>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]){

    int argCount = argc - 1;
    int binaryFlag = 0;
    
    //Checking if the dump command is entered by itself (without file name).
    if(argCount == 0){
        printf("Error: No file name was entered with the command.\n");
        return 0;
    }

    //Store the name of the file.
    char* fileName = argv[1];

    //Checking for binary flag
    if(strcmp(argv[1], "-b") == 0){
        //Checking if file name is entered after binary flag.
        if(argCount == 1){
            printf("Error: No file name was entered with the command.\n");
            return 0;
        }
        binaryFlag = 1;
        argCount -= 1;
        fileName = argv[2];
    }

    //Checking for number of args to make sure only one file name is entered.
    if(argCount == 1){
        if(binaryFlag) {
            
            //Print binary dump of file:

            ifstream file(fileName);
            string f = "";
            char c;
            int counter = 0;
            int line = 0;

            //Read file into string "f" character by character.
            while (file.get(c))
            {
                f.push_back(c);
            }

            //Print Binary dump of the file
            for (int i = 0; i < f.length(); i++)
            {

                //Print the memory address and ASCII chars
                if (i % 8 == 0)
                {

                    //ASCII segment
                    if (i != 0)
                    {
                        cout << " ";
                        for (int j = 0; j < 8; j++)
                        {
                            int asciiVal = int(f.at(j + i - 8));
                            if (asciiVal < 32)
                            {
                                cout << ".";
                            }
                            else
                            {
                                cout << f.at(j + i - 8);
                            }
                        }
                        line++;
                        cout << endl;
                    }

                    //Memory address segment
                    cout << setfill('0') << setw(7) << hex << counter << ": ";
                    counter += 8;
                }

                //Space between every byte
                if (i % 1 == 0 && i != 0 && i % 8 != 0)
                {
                    cout << " ";
                }

                //Print Binary value of character
                cout << setfill('0') << setw(2) << bitset<8>(f.at(i));

                //If last line, still print the ASCII representation
                if (i == f.length() - 1 && i % 8 != 0)
                {
                    int lastLineIndex = line * 8;
                    int charsleft = f.length() - lastLineIndex;
                    int numSpaces = 72 - (charsleft * 8) - charsleft;
                    if (charsleft % 1 == 0)
                    {
                        numSpaces++;
                    }
                    for (int i = 0; i < numSpaces; i++)
                    {
                        cout << " ";
                    }
                    for (int z = lastLineIndex; z < f.length(); z++)
                    {
                        if (int(f.at(z)) < 32)
                        {
                            cout << ".";
                        }
                        else
                        {
                            cout << f.at(z);
                        }
                    }
                }
            }

            cout << endl;
        }
        else{
            
            //Print hex dump of file:

            ifstream file(fileName);
            string f = "";
            char c;
            int counter = 0;
            int line = 0;

            //Read file into string "f" character by character.
            while (file.get(c))
            {
                f.push_back(c);
            }

            //Print Hex dump of the file
            for (int i = 0; i < f.length(); i++)
            {

                //Print the memory address and ASCII chars
                if (i % 16 == 0)
                {

                    //ASCII segment
                    if (i != 0)
                    {
                        cout << " ";
                        for (int j = 0; j < 16; j++)
                        {
                            int asciiVal = int(f.at(j + i - 16));
                            if (asciiVal < 32)
                            {
                                cout << ".";
                            }
                            else
                            {
                                cout << f.at(j + i - 16);
                            }
                        }
                        line++;
                        cout << endl;
                    }

                    //Memory address segment
                    cout << setfill('0') << setw(7) << counter << ": ";
                    counter += 16;
                }

                //Space between every two bytes
                if (i % 2 == 0 && i != 0 && i % 16 != 0)
                {
                    cout << " ";
                }

                //Print hex value of character
                cout << setfill('0') << setw(2) << hex << (unsigned int)(unsigned char)f.at(i);

                //If last line, still print the ASCII representation
                if (i == f.length() - 1 && i % 16 != 0)
                {
                    int lastLineIndex = line * 16;
                    int charsleft = f.length() - lastLineIndex;
                    int numSpaces = 40 - (2 * (f.length() - (line * 16))) - (charsleft / 2);
                    if (charsleft % 2 == 0)
                    {
                        numSpaces++;
                    }
                    for (int i = 0; i < numSpaces; i++)
                    {
                        cout << " ";
                    }
                    for (int z = lastLineIndex; z < f.length(); z++)
                    {
                        if (int(f.at(z)) < 32)
                        {
                            cout << ".";
                        }
                        else
                        {
                            cout << f.at(z);
                        }
                    }
                }
            }

            cout << endl;
        }
    }
    //If more than one argument is entered.
    else {
        printf("Error: Multiple arguments were entered after the dump command.\n");
    }
    
    
    
    return 0;
}