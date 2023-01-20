#include <iostream>
#include <time.h>
#include "payloads.h"

namespace payloadLib{
    int payloadClass::generatePayload(){
        int payloadId = 0;
        time_t currtimet = 0;
        struct tm *currtm;

        currtimet = time(0);
        currtm = localtime(&currtimet);

        if(currtm->tm_sec / 30) payloadId += 4;

        return payloadId;
    }
}
