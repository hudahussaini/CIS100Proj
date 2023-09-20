
// File: CopyFile.cpp
// Copies file InData.txt to file OutData.txt

#include <cstdlib>     // for the definition of EXIT_FAILURE
#include <fstream>     // required for external file streams
#include <iostream>
using namespace std;

#define inFile "Patrick.txt"
#define outFile "Hussaini.txt"

int copyLine(ifstream&, ofstream&);

int main()
{
    int lineCount;  
    ifstream ins;    
    ofstream outs;    

    ins.open(inFile);      
    if (ins.fail())
    {
    cerr << "*** ERROR: Cannot open " << inFile
         << " for input." << endl;
    return EXIT_FAILURE;    
    }  

    outs.open(outFile);     // connect outs to file outFile
    if (outs.fail())
    {
        cerr << "*** ERROR: Cannot open " << outFile
            << " for output." << endl;
        return EXIT_FAILURE;    // failure return
    }  

    lineCount = 0;

    do
    {
        if (copyLine(ins, outs) != 0)
            lineCount++;
    } while (!ins.eof());


    cout << "Input file copied to output file." << endl;
    cout << lineCount << " lines copied." << endl;

    ins.close();          
    outs.close();        

    return 0;       // successful return
}

int copyLine
(ifstream& ins,          
    ofstream& outs)         
{
    const char NWLN = '\n';          
    char nextCh;                   
    int charCount = 0;            

    ins.get(nextCh);
    while ((nextCh != NWLN) && !ins.eof())
    {
        outs.put(nextCh);
        charCount++;
        ins.get(nextCh);
    } 
 
    if (!ins.eof())
    {
        outs.put(NWLN);
        charCount++;
    }
    return charCount;
}  