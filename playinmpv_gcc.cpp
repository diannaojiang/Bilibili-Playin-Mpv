// playinmpv.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//#include <Windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <assert.h>
using namespace std;

unsigned char ToHex(unsigned char x)
{
    return  x > 9 ? x + 55 : x + 48;
}

unsigned char FromHex(unsigned char x)
{
    unsigned char y;
    if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
    else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
    else if (x >= '0' && x <= '9') y = x - '0';
    else assert(0);
    return y;
}

std::string UrlEncode(const std::string& str)
{
    std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        if (isalnum((unsigned char)str[i]) ||
            (str[i] == '-') ||
            (str[i] == '_') ||
            (str[i] == '.') ||
            (str[i] == '~'))
            strTemp += str[i];
        else if (str[i] == ' ')
            strTemp += "+";
        else
        {
            strTemp += '%';
            strTemp += ToHex((unsigned char)str[i] >> 4);
            strTemp += ToHex((unsigned char)str[i] % 16);
        }
    }
    return strTemp;
}

std::string UrlDecode(const std::string& str)
{
    std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == '+') strTemp += ' ';
        else if (str[i] == '%')
        {
            assert(i + 2 < length);
            unsigned char high = FromHex((unsigned char)str[++i]);
            unsigned char low = FromHex((unsigned char)str[++i]);
            strTemp += high * 16 + low;
        }
        else strTemp += str[i];
    }
    return strTemp;
}

int main(int argc, char* argv[])
{
    string cmd;
    if (argc < 2)
    {
        std::cout << "can't get value" << endl;
        sleep(1000 * 10);
    }
    else {
        cmd = argv[1];
        std::cout << "输入url:" << endl;
        std::cout << cmd <<endl;
    }
    cmd = cmd.substr(6);
    cmd = UrlDecode(cmd);
    // string url_1 = "upos-hz-mirrorakam.akamaized.net", url_2 = "upos-sz-mirrorks3c.bilivideo.com";
    // if (cmd.find(url_1)!=string::npos) {
    //     cmd = cmd.replace(cmd.find(url_1), url_1.length(), url_2);
    //     std::cout << "港澳台视频cdn替换为：upos-sz-mirrorks3c.bilivideo.com" << endl;
    // }
    // if (cmd.find(url_1) != string::npos) {
    //     cmd = cmd.replace(cmd.find(url_1), url_1.length(), url_2);
    //     std::cout << "港澳台音频cdn替换为：upos-sz-mirrorks3c.bilivideo.com" << endl;
    // }
    cmd = "mpv " + cmd;
    const char* cstr = cmd.c_str();
    std::cout << "执行命令：" << endl;
    std::cout << cstr << endl;
    system(cstr);
    sleep(1000 * 1);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
