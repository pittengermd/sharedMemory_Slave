#include <iostream>
#include "sharedmemory.hh"
#define UNMANAGED 1

struct TestStruct
{
    double d1 {0.0} , d2 {1.1};
    float f {2.2f};
    char msg[6] = "Hello";
};

int main()
{
    std::string quit;
    SharedMemory MySharedMemory {"TestSharedMemory", sizeof(TestStruct), sharedMemMode::ReadWrite, sharedMemRole::Slave };
    TestStruct MyTestStruct {0.11, 0.22, 0.33f, "vwxyz"};
    MySharedMemory.Open();
    MyTestStruct = MySharedMemory.Read<TestStruct>();
        std::cout << "MyTestStruct d1: " << MyTestStruct.d1 << std::endl;
        std::cout << "MyTestStruct d2: " << MyTestStruct.d2 << std::endl;
        std::cout << "MyTestStruct f: " << MyTestStruct.f << std::endl;
        std::cout << "MyTestStruct msg: " << std::string(MyTestStruct.msg) << std::endl;
    std::cout << "Read Again? [y/n]: ";
    while(1)
    {
        std::cin >> quit;
        if (quit == "n")
        {
            break;
        }
        else
        {
            MyTestStruct = MySharedMemory.Read<TestStruct>();
                std::cout << "MyTestStruct d1: " << MyTestStruct.d1 << std::endl;
                std::cout << "MyTestStruct d2: " << MyTestStruct.d2 << std::endl;
                std::cout << "MyTestStruct f: " << MyTestStruct.f << std::endl;
                std::cout << "MyTestStruct msg: " << std::string(MyTestStruct.msg) << std::endl;
            std::cout << "Read Again? [y/n]: ";
        }
    }
    return 0;
}
