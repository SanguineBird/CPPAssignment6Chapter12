/*
Meghan Moore
March 21, 2015
CIT 245 - Data Structures and Programming C++
Assignment 6 - Chapter 12
Purpose: Make a program that can write advice to a file.
*/

#include <iostream> //cin, cout, cerr
#include <cstdlib> //system
#include <fstream> //ifstream, ofstream, fstream
using namespace std;

void readFromFile(string fileName);
/*Attempts to open file for reading. If successful, reads exisiting data to screen. If unsuccessful, creates new file with specified file name.
Precondition: a file name (including extension) has been obtained from the user, and stored as a string variable.*/

void writeToFile(string fileName);
/*Prompts user for advice phrase, and writes phrase to file
Precondition: a file name (including extension) has been obtained from the user, and stored as a string variable.*/

int main(){
  string fileName;
  cout << "Please enter advice file name (include extension):\n";
  getline(cin, fileName);
  cout << endl << endl;
  
  readFromFile(fileName);
  
  writeToFile(fileName);
  
  system("pause");
  return 0;
}//end main

void readFromFile(string fileName){
  ifstream inStream;
  inStream.open(fileName.c_str());
  
  if (! inStream.fail()){ //file found
    cout << "Found Advice File.\nOld Advice:\n";
    //declare 'next'? !!!!!!!!!!!!!!!
    inStream.get(next);
    while (! inStream.eof()){
      cout << next;
      inStream.get(next);
    }
    inStream.close();
  }
  else{ //file NOT found
    cout << "Could not open advice file.\nAssumption: first run - creating new file...\n";
    inStream.close();
    fstream inOutStream;
    inOutStream.open(fileName.cstr(), ios::in | ios::out | ios::trunc); //creates new file
    inOutStream.close();
  }
}// end readFromFile

void writeToFile(string fileName){
  ofstream outStream;
  outStream.open(fileName.cstr(), ios::app);
  
  if (! outStream.fail()){
    string advice;
    cout "Enter your phrase for the next user:\n"
    cin >> advice;
    outStream << advice << endl;
    outStream.close();
  }
  else{
    cerr << "Error: Cannot open file to write.";
    exit(1);
  }
} //end writeToFile
