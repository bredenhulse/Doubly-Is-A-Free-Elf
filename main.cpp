/*
Name: Breden Hulse
Class: Computer Science 2
Description: It is a linked list.
*/
#include <iostream>
#include "list.h"
#include <fstream>

using namespace std;

int main(){
    List beiju;
    //open files
    ifstream infile;
    infile.open("Test.txt");
    ofstream fout;
    fout.open("outfile");
    string testCase;
    //reads in the file
    while(infile >> testCase){
        beiju.begin();
        for(int i = 0; i < testCase.size(); i++){
            if(testCase[i] == '['){
               beiju.begin(); 
            }
            else if(testCase[i] == ']'){
                beiju.end();
            }
            else{
                beiju.insert_after(testCase[i]);
            }
        }
        //Sends to the outfile
        beiju.begin();
        while(beiju.get_iterator() != ']'){
            if(beiju.get_iterator() != '['){
                fout << beiju.get_iterator();
            }
            beiju.move_up();
        }
        beiju.clear();
        fout << endl;
    }
    infile.close();
    fout.close();
}