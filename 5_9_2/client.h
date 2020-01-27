#ifndef CLIENT_H_
#define CLIENT_H_
//为了避免重复包含头文件通常要使用编译与处理指令
class Client {
    static char ServerName;
    static int ClientNum;
    public:
        static void ChangeServerName(char name);
        static int getClientNum();
};

#endif