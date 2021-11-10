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
    //open file
    ifstream infile;
    infile.open("Test.txt");
    int testCase[10];
    int z = 0;
    int num = 10;
    //reads in the file
    while(z < num){
        infile >> testCase[z];
        z++;
    }
    // To keep count of how many times it has ran
    for(int i = 0; i < num; i++){
        if(sorted.isEmpty() == true){
            sorted.insert_here(testCase[i]);
        }
        else if(testCase[i] < sorted.get_iterator()){
            sorted.insert_here(testCase[i]);
        }
        else{
            sorted.move_up();
        }
    }
    cout << sorted.print_list();
    infile.close();
}