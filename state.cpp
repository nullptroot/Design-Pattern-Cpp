/*完全按照书上的方法和类的顺序是不能通过编译的，下述是正常运行的代码
当有一些类，根据自己的状态数据成员不同会做不同的事情，并且状态会被改变
如果只用一个方法来对其进行编写，那么必定会有很多的if判断句，并且如果
要添加一个状态或者删除一个状态，就要修改整个方法，这是不好的编码习惯

所以把不同状态的判断放到单独的类中，先判断当前类的状态和要比较的一样
不一样，如果一样直接执行当前状态要执行的代码就行，如果不一样，那么就
更改当前的状态，并执行改完后状态的代码，这样如果添加一些状态和删除一
些状态只需要添加一些类，修改相关联的状态类即可。
*/
#include <iostream>
#include <string>
using namespace std;
class work;
class state
{
    public:
        virtual void writeProgram(work *wok) = 0;
};
class work
{
    public:
        state *current;
        double hour;
        bool taskFinished;
    public:
        work():current(nullptr){};
        void setState(state *sta)
        {
            delete current;
            current = sta;
        }
        void writeProgram()
        {
            current->writeProgram(this);
        }
};
class sleepingState : public state
{
    public:
        virtual void writeProgram(work *wok)
        {
            cout<<"当前时间："<<wok->hour<<"点,不行了，睡着了\n";
        }
};
class restState : public state
{
    public:
        virtual void writeProgram(work *wok)
        {
            cout<<"当前时间："<<wok->hour<<"点,下班回家了\n";
        }
};
class eveningState : public state
{
    public:
        virtual void writeProgram(work *wok)
        {
            if(wok->taskFinished)
            {
                wok->setState(new restState());
                wok->writeProgram();
            }
            else
            {
                if(wok->hour < 21)
                    cout<<"当前时间："<<wok->hour<<"点，加班嗷，疲劳至极\n";
                else
                {
                    wok->setState(new sleepingState());
                    wok->writeProgram();
                }
            }
        }
};
class afternoonState : public state
{
    public:
        virtual void writeProgram(work *wok)
        {
            if(wok->hour < 17)
                cout<<"当前时间："<<wok->hour<<"点，下午状态还不错，继续努力\n";
            else
            {
                wok->setState(new eveningState());
                wok->writeProgram();
            }
        }
};
class noonState : public state
{
    public:
        virtual void writeProgram(work *wok)
        {
            if(wok->hour < 13)
                cout<<"当前时间："<<wok->hour<<"点，饿了，午饭，犯困，午休\n";
            else
            {
                wok->setState(new afternoonState());
                wok->writeProgram();
            }
        }
};
class forenoonState : public state
{
    public:
        virtual void writeProgram(work *wok)
        {
            if(wok->hour < 12)
                cout<<"当前时间："<<wok->hour<<"点，上午工作 精神百倍\n";
            else
            {
                wok->setState(new noonState());
                wok->writeProgram();
            }
        }
};


int main()
{
    work *emergencyProjects = new work();
    emergencyProjects->current = new forenoonState();
    emergencyProjects->hour = 9;
    emergencyProjects->writeProgram();
    emergencyProjects->hour = 10;
    emergencyProjects->writeProgram();
    emergencyProjects->hour = 12;
    emergencyProjects->writeProgram();
    emergencyProjects->hour = 13;
    emergencyProjects->writeProgram();
    emergencyProjects->hour = 14;
    emergencyProjects->writeProgram();
    emergencyProjects->hour = 17;
    emergencyProjects->writeProgram();

    emergencyProjects->taskFinished = 0;
    emergencyProjects->writeProgram();
    emergencyProjects->hour = 19;
    emergencyProjects->writeProgram();
    emergencyProjects->hour = 22;
    emergencyProjects->writeProgram();
    return 0;
}