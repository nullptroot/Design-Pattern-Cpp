#include <iostream>
#include <string>

using std::cout;
using std::string;
/*懒汉模式*/
// class singleton
// {
//     private:
//         static singleton *instance;
//         singleton(){};
//     public:
//         static singleton *getInstance()
//         {
//             if(instance == nullptr)
//                 instance = new singleton();
//             return instance;
//         }
// };
//懒汉的优化，这个只有在初始化的时候会阻塞，完成初始化就不会阻塞了
// class singleton
// {
//     private:
//         static singleton *instance;
//         singleton(){};
//     public:
//         static singleton *getInstance()
//         {
//             if(instance == nullptr)
//             {
//                 lock();
//                 if(instance == nullptr)
//                     instance = new singleton();
//                 unlock();
//             }
//             return instance;
//         }
// };
// singleton *singleton::instance;
/*饿汉模式*/
class singleton
{
    private:
        static singleton *instance;
        singleton(){};
    public:
        static singleton *getInstance()
        {
            if(instance == nullptr)
                instance = new singleton();
            return instance;
        }
};
singleton *singleton::instance = new singleton();
int main()
{
    singleton *s1 = singleton::getInstance();
    singleton *s2 = singleton::getInstance();
    if(s1 == s2)
        cout<<"两个对象是相同的实例\n";
    delete s1;
    return 0;
}