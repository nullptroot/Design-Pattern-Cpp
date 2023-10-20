/*合成 聚合关系，尽量使用合成聚合而不用类继承
此模式核心  当实现系统可能多角度分类，每一种分类都有可能变化，那就把这种多角度分离出来
让她们独立变化，减少他们之间的耦合 下面是手机软件和手机品牌的抽象  桥接模式  stl上说
pimpl是桥接模式 把类的成员和虚函数封装成其他类 原类保存一个指针 卧槽 确实是 其实就是
聚合关系  不太理解*/

#include<iostream>
#include <string> 
using std::string;
using std::cout;
using std::endl;
//手机软件
class handsetSoft
{
    public:
        virtual void run() = 0;
};
//手机游戏
class handsetGame : public handsetSoft
{
    public:
        virtual void run(){cout<<"运行手机游戏"<<endl;}
};
//手机通信录
class handsetAddressList : public handsetSoft
{
    public:
        virtual void run(){cout<<"运行手机通信录"<<endl;}
};
//手机品牌
class handsetBrand
{
    protected:
        handsetSoft *soft;
    public:
        handsetBrand():soft(nullptr){};
        virtual ~handsetBrand(){delete soft;};
        void setHandsetSoft(handsetSoft *s)
        {
            delete soft;
            soft = s;
        };
        virtual void run() = 0;
};
//手机品牌N
class handsetBrandN : public handsetBrand
{
    public:
        virtual void run(){cout<<"品牌N：";soft->run();};
};
//手机品牌M
class handsetBrandM : public handsetBrand
{
    public:
        virtual void run(){cout<<"品牌M：";soft->run();};
};

int main()
{
    handsetBrand *ab;
    ab = new handsetBrandN();
    ab->setHandsetSoft(new handsetGame());
    ab->run();
    ab->setHandsetSoft(new handsetAddressList());
    ab->run();

    delete ab;
    ab = new handsetBrandM();
    ab->setHandsetSoft(new handsetGame());
    ab->run();
    ab->setHandsetSoft(new handsetAddressList());
    ab->run();
    delete ab;
    return 0;
}