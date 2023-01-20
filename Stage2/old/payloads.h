#ifndef PAYLOADS_H
#define PAYLOADS_H

    class payloadClass{
    public:
        static void payload0();
        static __declspec(dllexport) void payload1();
        static __declspec(dllexport) void payload2();
        static __declspec(dllexport) void payload3();

        static __declspec(dllexport) void payload4();
        static __declspec(dllexport) void payload5();
        static void payload6();
        static void payload7();

        static int generatePayload();
    };

#endif // PAYLOADS_H
