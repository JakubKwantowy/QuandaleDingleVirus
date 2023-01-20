#ifndef CURSORLIB_INCLUDED
#define CURSORLIB_INCLUDED 1

#include <windows.h>

// I don't know why, but it works.
class CursorController{
    public:
    HANDLE hout;
    HANDLE hin;
    INPUT_RECORD inputRecord;
    DWORD events;
    COORD coord;
    CONSOLE_CURSOR_INFO cci;

    void cursor_init();
    int cursor_loop();
    void gotoxy(int x, int y);
    void textcolor(int text, int bg);
    CursorController();
};
#endif // CURSORLIB_INCLUDED
