#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <QByteArray>

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

#define ADD_FOLDER_SUCCESS "AddFolder success"
#define ADD_FOLDER_FAIL "AddFolder fail"

#define DELETE_FOLDER_SUCCESS "DeleteFolder success"
#define DELETE_FOLDER_FAIL "DeleteFolder fail"

#define UP_FOLDER_SUCCESS "UPFolder success"
#define UP_FOLDER_FAIL "UPFolder fail"

#define UPLOAD_REQUEST_ACCEPTED "ADDFile request accepted"
#define UPLOAD_SUCCESS "AddFile success"
#define UPLOAD_FAIL1 "AddFile fail1"
#define UPLOAD_FAIL2 "AddFile fail2"

#define DOWNLOAD_REQUEST_ACCEPTED "Download request accepted"
#define DOWNLOAD_SUCCESS "Download success"
#define DOWNLOAD_FAIL "Download fail"

#define SEARCH_SUCCESS "Search success"

// enumeration class specify the message's type
enum MSGTYPE
{
    REGISTER,
    LOGIN,
    LOGOUT,
    ROOTID,
    REFRESH_FOLDER,
    ADD_FOLDER,
    DELETE,
    UP_FOLDER,
    UPLOAD,
    DOWNLOAD,
    SEARCH,
};
// our protocal data unit through QTcpSocket
// To unify,for all transmission data, we use this data form
struct PDU
{
    uint len;         // total len // this is the first unit, because we need to read it first
    uint type;        // message type
    char meta[96];    // meta data: file name / usename&password
    uint dataLen;     // data len
    char data[];      // transmission data
};

PDU *mkPDU(uint dataLen);

#endif
