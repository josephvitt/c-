#include "client.h"
//静态数据成员的引用，注意加上”类名::“来修饰
void Client::ChangeServerName(char name){
    Client::ServerName = name;
    Client::ClientNum++;
}

int Client::getClientNum(){
    return Client::ClientNum;
}