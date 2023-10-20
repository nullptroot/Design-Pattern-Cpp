/*问题代码  cpp中没有委托
委托就是把一些函数或者类方法，放入委托中，一块执行
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;


class subject
{
       
    public:
        string subjectState;
};
class boss : public subject
{
    private:
        string action;
    public:
        list<void *()> Update;
    public:
        void notify()
        {
            for(auto i:Update)
            {
                i();
            }
        };
        
};
class stockObserver
{
    private:
        string name1;
        subject *subj;
    public:
        stockObserver(string name,subject *sub):name1(name),subj(sub){};
        void update()
        {
            cout<<subj->subjectState<<" "<<name1<<"关闭股票行情，继续工作\n";
        }
};
class NBAObserver
{
    private:
        string name1;
        subject *subj;
    public:
        NBAObserver(string name,subject *sub):name1(name),subj(sub){};
        void update()
        {
            cout<<subj->subjectState<<" "<<name1<<"关闭NBA直播，继续工作\n";
        }
};

int main()
{
    boss *huhansan = new boss();
    stockObserver *tongshi1 = new stockObserver("小李",huhansan);
    NBAObserver *tongshi2 = new NBAObserver("小王",huhansan);
    huhansan->Update.push_back(tongshi1->update);
    huhansan->subjectState = "我胡汉三回来了";
    huhansan->notify();
    delete huhansan;
    return 0;
}