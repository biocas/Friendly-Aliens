#include <iostream>
#include "menu.h"
using namespace std; 

int main() {
    //creates new dynamic menu object and the function to show the menu
    Menu* menu = new Menu(); 
    menu->welcome(); 
    //releases memory from the Heap
    delete menu; 
    
    return 0; 
}; 
