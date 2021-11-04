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
    List sorted;
    //open files
    ifstream infile;
    infile.open("Test.txt");
    string testCase;
    //reads in the file
    int num = 1;
    // To keep count of how many times it has ran
    while(infile >> testCase){
        for(int i = 0; i < num; i++){
            if(sorted.isEmpty() == false){
                sorted.insert_here(testCase[i]);
            }
            else if(testCase[i] < sorted.get_iterator()){
                sorted.move_up();
            }
            else{
                sorted.insert_here(testCase[i]);
            }
        }
        num++;
    }
    sorted.print_list();
    infile.close();
}