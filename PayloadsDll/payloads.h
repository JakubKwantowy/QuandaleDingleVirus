#ifndef PAYLOADS_H
#define PAYLOADS_H

namespace payloadLib{
    class payloadClass{
    public:
        static __declspec(dllexport) void payload0();
        static __declspec(dllexport) void payload1();
        static __declspec(dllexport) void payload2();
        static __declspec(dllexport) void payload3();

        static __declspec(dllexport) void payload4();
        static __declspec(dllexport) void payload5();
        static __declspec(dllexport) void payload6();
        static __declspec(dllexport) void payload7();

        static __declspec(dllexport) int generatePayload();
        static __declspec(dllexport) void execPayload(int payloadId);
    };
}

#endif // PAYLOADS_H
