#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

fstream logicalFile;
string physicalFile;

void LoadAnExistingFile(){
    fstream fileName;
    string file;
    cout<<"Enter file name: ";
    getline(cin, file);
    fileName.open(file.c_str(), ios::out | ios::in);
    if(fileName.is_open()){
        cout<<fileName.rdbuf()<<endl;
    }
    else {cout<<"Doesn't Exist"<<endl;}
    //fileName.is_open() ? cout<<fileName.rdbuf(): "File isn't open\n";
}

void CreatNewFile(string physicalFile){
    cout<<"Enter file name: ";
    getline(cin, physicalFile);
    fstream logicalFile(physicalFile);
    logicalFile.open(physicalFile.c_str(), ios::out | ios::in);
}

void DisplayContent(string physicalFile){
    if(logicalFile.is_open()){
        cout<<logicalFile.rdbuf()<<endl;
    }
}

int main()
{
    char choice;
    cout<<"What do you want to do? ";
    cout<<"1- Load an existing file\n2- Create a new file\n3- Display file content\nE- End\n";
    cin>>choice;

    while(1){
        switch(choice){
            case '1':
                LoadAnExistingFile();
                break;
            case '2':
                CreatNewFile(physicalFile);
            case '3':
                DisplayContent(physicalFile)    ;
                break;
            case 'E' || case 'e':
                return 0;
        }
    }

}
