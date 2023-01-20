#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include <windows.h>
#include <sstream>
#include "cursorlib.h"
#include "quandale.h"

int main(){
	cursorController.cursor_init();
	cursorController.textcolor(10,0);

    std::string temp;
    std::fstream titleImg;

    SetConsoleTitle("Quandale Dingle");

    titleImg.open("title.txt", std::ios::in);
    while(std::getline(titleImg, temp)){
        std::cout << temp << '\n';
    }
    titleImg.close();

    start_dingle();

	while(cursorController.inputRecord.Event.KeyEvent.uChar.AsciiChar != 0x1b && running){
        switch(cursorController.cursor_loop()){
        case 1:
            full_dingle();
            break;
        }
	}
	return 0;
}
