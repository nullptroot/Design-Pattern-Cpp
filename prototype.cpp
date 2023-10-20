//原型模式其实就是加一个clone的类成员。没啥其他的
//可以避免很多次构造

#include <iostream>
#include <string>
using namespace std;

class iCloneable//这个类就有一个接口，就是纯虚clone方法，强制派生类实现
{
    public:
        virtual iCloneable * clone() = 0;
};

class resume : public iCloneable
{
    private:
        string name;
        string sex;
        string age;
        string timeArea;
        string company;
    public:
        resume():name(""),sex(""),age(""),timeArea(""),company(""){};
        resume(string n):name(n){};
        resume(const resume &s)
        {
            age = s.age;
            name = s.name;
            sex = s.sex;
            timeArea = s.timeArea;
            company = s.company;
        }
        void setPersonalInfo(string s,string a){sex = s,age = a;};
        void setWorkExperience(string t,string c){timeArea = t,company = c;};
        void show()
        {
            cout<<name<<" "<<sex<<" "<<age<<endl;
            cout<<"工作经历："<<timeArea<<company<<endl;
        }
        virtual resume * clone(){return new resume(*this);};//这里有一个返回值协变
};
int main()
{
    resume *a = new resume("大鸟");
    a->setPersonalInfo("男","29");
    a->setWorkExperience("1998-2000","XX公司");

    resume *b = a->clone();
    b->setWorkExperience("1998-2006","YY公司");
    a->show();
    b->show();
    delete a;
    delete b;
    return 0;
}