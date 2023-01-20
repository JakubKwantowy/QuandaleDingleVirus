#include "cursorlib.h"
#include <windows.h>
#include <string>

CursorController::CursorController(){
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    hin = GetStdHandle(STD_INPUT_HANDLE);
    cci.dwSize = 25;
    cci.bVisible = TRUE;
}

void CursorController::cursor_init(){
    SetConsoleCursorInfo(hout, &cci);
    SetConsoleMode(hout, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
    textcolor(2, 0);
}

void CursorController::gotoxy(int x, int y){
    SetConsoleCursorPosition(hout, {x, y});
}

int CursorController::cursor_loop(){
    ReadConsoleInput(hin, &inputRecord, 1, &events);
    if(inputRecord.EventType == MOUSE_EVENT){
        coord.X = inputRecord.Event.MouseEvent.dwMousePosition.X;
        coord.Y = inputRecord.Event.MouseEvent.dwMousePosition.Y;
        SetConsoleCursorPosition(hout, coord);

        return inputRecord.Event.MouseEvent.dwButtonState;
    }
    return 0;
}


void CursorController::textcolor(int text, int bg){
    SetConsoleTextAttribute(hout, bg*16 + text);
}
