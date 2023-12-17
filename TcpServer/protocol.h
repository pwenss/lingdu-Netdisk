#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef unsigned int uint;

// message status
#define REGISTER_SUCCESS "Register success"
#define REGISTER_FAIL "Register fail"
#define LOGIN_SUCCESS "Login success"
#define LOGIN_FAIL1 "Login fail1"
#define LOGIN_FAIL2 "Login fail2"
#define LOGOUT_SUCCESS "Logout success"
#define LOGOUT_FAIL1 "Logout fail1"
#define LOGOUT_FAIL2 "Logout fail2"


// enumeration class specify the message's type
enum MSGTYPE
{

    REGISTER,
    LOGIN,
    LOGOUT,
};


// our protocal data unit through QTcpSocket
// To unify,for all transmission data, we use this data form
struct PDU
{
    uint len;         // total len
    uint type;        // message type
    char meta[64];    // meta data: file name / usename&password
    uint dataLen;     // data len
    char data[];      // transmission data
};

PDU *mkPDU(uint dataLen);

#endif
