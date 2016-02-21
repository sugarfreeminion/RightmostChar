#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            char del;
            string lineSubstr;
            size_t location = 0;
            
            //cout << "Input: " << line << endl;

            del = *(line.end()-1);
         
            //cout << "Char to match: " << del << endl;

            lineSubstr = line.substr(0, line.size()-2);

            //cout << "Input without matching char: " << lineSubstr << endl;

            location = lineSubstr.find_last_of(del);

            if(location == string::npos)
            {
                //cout << del << " was not found in the line" << endl;
                cout << "-1" << endl;
            }
            else
            {
                //cout << "Last location of " << del << " is at: " << location << endl;
                cout << location << endl;
            }
        }
    }
    else
    {
        cout << "Error with input file" << endl;
    }

    return 0;
}
