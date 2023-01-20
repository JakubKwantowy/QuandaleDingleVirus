#include <iostream>
#include <Windows.h>
#include <wingdi.h>
#include "payloads.h"

int main(){
    //FreeConsole();

    /*MessageBox(
        NULL,
        (LPCSTR)"Text",
        (LPCSTR)"Caption",
        MB_OK | MB_ICONINFORMATION
    );*/

    //HWND hWnd = GetDesktopWindow();
    //HDC hdc = GetWindowDC(hWnd);

    /*while(1){
        DrawIcon(hdc, 0, 0, LoadIcon(NULL, IDI_ERROR));
    }*/

    /*HBRUSH brush = CreateSolidBrush(RGB(0,0,0));
    RECT res;
    GetWindowRect(hWnd, &res);

    RECT rct;
    rct.left = 0;
    rct.top = 0;
    rct.right = res.right;
    rct.bottom = res.bottom;

    while(1) {
        FillRect(hdc,&rct,brush);
        Sleep(1000/60);
    }*/

    std::cout << payloadLib::payloadClass::generatePayload();

    return 0;
}
