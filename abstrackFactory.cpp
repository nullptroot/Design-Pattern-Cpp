/*下面是抽象工厂模式
抽象工厂就是提供一个创建一系列相关或者相互依赖对象的接口
具体就是下面的表示，加入数据库有两个表user和department
两个表的有相同的操作，但是操作的细节不一样，故可以用基类派生
有两种数据库分别是access和sqlserver，可以对其表进行操作
抽象工厂就直接提供了数据库和表的工厂函数，可以不考虑细节
直接利用  当工厂类只能创建一个时就是工厂，可以创建多个类
时就是抽象工厂

优点  需要改数据库的时候，直接把iFactory *factory = new accessFactory();
这一句改了就可以直接使用了  然后就是客户端是通过抽象的接口操作的，具体的类名
不会出现在客户端代码中
缺点就是新加表需要加很多类并且改抽象工厂类

由于iFactory及其派生类的作用就是创建对应数据库的表的对象，
故可以采用简单工厂模式将其替代，根据对每个表的创建函数
中用case判断来实现返回哪一个对象（若是sql则构造sql表对象
并返回）；

讲述了反射，就是可以根据字符串，在一定的程序集中，创建字符串
描述的具体类，而且不用switch和if，可配合配置文件一块使用

*/

#include <iostream>
using namespace std;


class user
{
    public:
        int id;
        string name;
};
class iUser
{
    public:
        virtual void insert(user *use) = 0;
        virtual user *getUser(int id) = 0;
};
class sqlserverUser : public iUser
{
    public:
        virtual void insert(user *use)
        {
            cout<<"在SQL server 中给user表添加一条记录\n";
        }
        virtual user * getUser(int id)
        {
            cout<<"在SQL server 中根据id在user表得到一条记录\n";
            return nullptr;
        }
};
class accessUser : public iUser
{
    public:
        virtual void insert(user *use)
        {
            cout<<"在Access 中给user表添加一条记录\n";
        }
        virtual user * getUser(int id)
        {
            cout<<"Access 中根据id给user表得到一条记录\n";
            return nullptr;
        }
};

class iDepartment
{
    public:
        virtual void insert(string department) = 0;
        virtual string getDepartment(int fd) = 0;
};
class sqlserverDepartment : public iDepartment
{
    public:
        virtual void insert(string department)
        {
            cout<<"在SQL server中给department表中添加了一条记录\n";
        }
        virtual string getDepartment(int fd)
        {
            cout<<"在SQL server中根据department得到一条department表的记录\n";
            return "";
        }
};

class accessDepartment : public iDepartment
{
    public:
        virtual void insert(string department)
        {
            cout<<"在Access中给department表中添加了一条记录\n";
        }
        virtual string getDepartment(int fd)
        {
            cout<<"在Access中根据id得到一条department表的记录\n";
            return "";
        }
};

class iFactory
{
    public:
        virtual iUser *creatUser() = 0;
        virtual iDepartment *creatDepartment() = 0;
};
class sqlserverFactory : public iFactory
{
    virtual iUser *creatUser(){return new sqlserverUser();};
    virtual iDepartment *creatDepartment(){return new sqlserverDepartment();};
};
class accessFactory : public iFactory
{
    virtual iUser *creatUser(){return new accessUser();};
    virtual iDepartment *creatDepartment(){return new accessDepartment();};
};

int main()
{
    user *use = new user();
    use->id = 1;
    use->name = "wqwq";
    string dept = "";
    iFactory *factory = new accessFactory();
    iUser *iu = factory->creatUser();
    iu->insert(use);
    iu->getUser(1);

    iDepartment *id = factory->creatDepartment();
    id->insert(dept);
    id->getDepartment(1);

    delete use;
    delete factory;
    delete iu;
    delete id;
    return 0;
}