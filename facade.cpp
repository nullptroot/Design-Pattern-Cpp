//外观模式对一系列的类方法 提供一个总的方法 使这些方法更容易被使用
/*
三个阶段使用
1 在创建初期就应该把两个不同的层分离  层与层之间建立外观
2 开发期间子系统会不断的变复杂 增加外观可以减少子系统与子系统的依赖
3 对遗留的老系统可以建立外观 来设计比老系统更加清晰地接口 供新系统使用
*/

#include <iostream>
#include <string>
using namespace std;
//其实这种可以用模板方法  也就是上一个设计模式
class stock1
{
    public:
        void sell(){cout<<"股票1卖出\n";};
        void buy(){cout<<"股票1买入\n";};
};
class stock2
{
    public:
        void sell(){cout<<"股票2卖出\n";};
        void buy(){cout<<"股票2买入\n";};
};
class stock3
{
    public:
        void sell(){cout<<"股票3卖出\n";};
        void buy(){cout<<"股票3买入\n";};
};

class nationalDebt1
{
    public:
        void sell(){cout<<"国债1卖出\n";};
        void buy(){cout<<"国债1买入\n";};
};
class realty1
{
    public:
        void sell(){cout<<"房地产1卖出\n";};
        void buy(){cout<<"房地产1买入\n";};
};
class fund
{
    private:
        stock1 *gu1;
        stock2 *gu2;
        stock3 *gu3;
        nationalDebt1 *nd1;
        realty1 *rt1;
    public:
        fund():gu1(new stock1()),gu2(new stock2()),gu3(new stock3()),nd1(new nationalDebt1()),rt1(new realty1()){};
        ~fund()
        {
            delete gu1;
            delete gu2;
            delete gu3;
            delete nd1;
            delete rt1;
        }
        void buyFund()
        {
            gu1->buy();
            gu2->buy();
            gu3->buy();
            nd1->buy();
            rt1->buy();
        }
        void sellFund()
        {
            gu1->sell();
            gu2->sell();
            gu3->sell();
            nd1->sell();
            rt1->sell();
        }

};
int main()
{
    fund *jijin = new fund();
    jijin->buyFund();
    jijin->sellFund();
    return 0;
}