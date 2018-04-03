#include <stdio.h>
#include <stdlib.h>
#include <io.h>

int main()
{
    system("mode con cols=120 lines=38");//设置窗口大小
    if(access("e:/admininfo.txt",0) == -1 || access("e:/bookinfo.txt",0) == -1)
    storage_info();
    read_info();
    login();
    init();
    init_choice();
    return 0;
}
