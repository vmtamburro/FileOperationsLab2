/*
Write a program that asks the sue for two file names.
The first will be opened for input and the second will be opened
for output. (It will be assumed that the first file contains
sentences that end with a period) The program will read the contents
of the first file and change all the letters to lowercase
except the first letter of each sentence, which should be made
uppercase. The revised contents should be stored in the second
file.

*/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{

    char chFirst;
    fstream firstFile("firstFile.txt", ios::out);
    if(!firstFile)
    {
        cout<<"Error Opening File!"<<endl;
        return 0;
    }


    cout << "Type a sentence with a period at the end: \n";

    cin.get(chFirst);


    while(chFirst != '.')
    {
        firstFile.put(chFirst);
        cin.get(chFirst);
    }

    firstFile.put(chFirst); //Write the Period
    firstFile<<endl;
    firstFile.close();


    firstFile.open("firstFile.txt", ios::in);

    fstream secondFile("secondFile.txt", ios::out | ios::app);

    if(!firstFile | !secondFile)
    {
        cout << "Error Opening File!"<<endl;
        return 0;
    }

    firstFile.get(chFirst);
    secondFile.put(toupper(chFirst));
    while(chFirst != '.')
    {
        firstFile.get(chFirst);
        secondFile.put(tolower(chFirst));
    }

   // secondFile.put(chFirst); //Write the Period
    secondFile<<endl;

    firstFile.close();
    secondFile.close();














    return 0;
}
