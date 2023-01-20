#include <iostream>
#include <windows.h>
#include <sstream>

std::stringstream printstream;

CursorController cursorController;

bool running = true;

void printWithDelay(int delay){
    std::string toPrint = printstream.str();
    printstream.str("");

    for(int i=0;i<toPrint.length();i++){
        std::cout << toPrint[i];
        Sleep(delay);
    }
}

void printWithDelay(){
    printWithDelay(50);
}

void start_dingle(){
    Sleep(5000);
    std::cout << '\n' << '\n';
    printstream << "What's up guys, ";
    printWithDelay();
    Sleep(500);
    printstream << "Quandale Dingle Here!";
    printWithDelay();
    cursorController.textcolor(2,0);
    printstream << "  ruhuhehehehe\n";
    printWithDelay();
    Sleep(500);
    cursorController.textcolor(10,0);
    printstream << "I have been arrested for Multiple Crimes, Including:";
    printWithDelay();
    cursorController.textcolor(2,0);
    printstream << "  aughhh!\n";
    printWithDelay();
    cursorController.textcolor(10,0);
    Sleep(500);
    printstream << " - Battery on a Police Officer";
    printWithDelay();
    cursorController.textcolor(2,0);
    printstream << "  WHAT?!\n";
    printWithDelay();
    cursorController.textcolor(10,0);
    Sleep(250);
    printstream << " - Grand Theft\n";
    printWithDelay();
    Sleep(250);
    printstream << " - Declaring War on Italy\n";
    printWithDelay();
    Sleep(250);
    printstream << " - and Public Indecency";
    printWithDelay();
    cursorController.textcolor(2,0);
    printstream << "  ruhuhehehehe\n";
    printWithDelay(20);
    cursorController.textcolor(10,0);
    Sleep(500);
    printstream << "I will be Escaping Prison on";
    printWithDelay();
    Sleep(250);
    printstream << " March 28th\n";
    printWithDelay();
    Sleep(500);
    printstream << "After that, i will take over the World!\n\n";
    printWithDelay();
    Sleep(750);
    printstream << "[Call Ended]";
    printWithDelay(15);
    printstream << " . . .";
    printWithDelay(500);
    printstream << "\n\nPress {Left Mouse Button} to Continue";
    printWithDelay(25);
}

void full_dingle(){
    running = false;
    cursorController.gotoxy(0,0);
    for(int i=0;i<2000;i++) std::cout << ' ';
    cursorController.gotoxy(0,0);
    printstream << "Temp Directory: " << getenv("temp");
    printWithDelay(50);
    Sleep(5000);
    system("%cd%\\copy.vbs");
}
