/*解释器模式  给定一个语言 定义它的文法的一种表示 并定义一个解释器 这个解释器用来
解释语言中的句子   有一个抽象基类解释器，然后可以派生出不同的具体类来进行不一样的
解释，容易扩展*/

#include <iostream>
#include <string>
#include <list>
using std::list;
using std::string;
using std::cout;
using std::endl;

class context
{
    public:
        string text;
};

class expression
{
    public:
        virtual void interpret(context *cont) = 0;
};
class terminalExpression : public expression
{
    public:
        virtual void interpret(context *cont)
        {
            cout<<"终端解释器:"<<cont->text<<endl;
        }
};
class NonTerminalExpression : public expression
{
    public:
        virtual void interpret(context *cont)
        {
            cout<<"非终端解释器:"<<cont->text<<endl;
        }
};

int main()
{
    context *cont = new context();
    cont->text = "adsds";
    list<expression *> li;
    li.push_back(new terminalExpression());
    li.push_back(new NonTerminalExpression());
    li.push_back(new terminalExpression());
    li.push_back(new terminalExpression());

    for(auto i:li)
        i->interpret(cont);
    for(auto i:li)
        delete i;
    delete cont;
    return 0;
}