/*职责链模式，使多个对象又机会处理请求，将这个对象连接成一条链，沿着
链处理该请求，知道有对象可以处理为止，和状态模式有点像，状态模式是根据
不太的状态选择不同的处理类，状态模式好像不要求成请求链状

这使得接收者和发送者都没有对方明确的信心。且链中的对象并不知道链的结构
简化了对象的相互连接，仅需要保存一个向后传请求的对象，而不用保存所有
候选的对象。*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class request
{
    public:
        string requestType;
        string requestContent;
        int number;
};

class manager
{
    protected:
        string name;
        manager *superior;
    public:
        manager(string n):name(n),superior(nullptr){};
        void setSuperior(manager *sup){superior = sup;};
        virtual void requestApplications(request req) = 0;
};

class commonManager : public manager
{
    public:
        virtual ~commonManager(){};
        commonManager(string n):manager(n){};
        virtual void requestApplications(request req)
        {
            if(req.requestType == "请假" && req.number <= 2)
            {
                cout<<name<<": "<<req.requestContent<<"数量"<<req.number<<"被批准"<<endl;
            }
            else
            {
                if(superior)
                    superior->requestApplications(req);
            }
        }
};
class majordomo : public manager
{
    public:
        virtual ~majordomo(){};
        majordomo(string n):manager(n){};
        virtual void requestApplications(request req)
        {
            if(req.requestType == "请假" && req.number <= 5)
            {
                cout<<name<<": "<<req.requestContent<<"数量"<<req.number<<"被批准"<<endl;
            }
            else
            {
                if(superior)
                    superior->requestApplications(req);
            }
        }
};
class generalManager : public manager
{
    public:
        virtual ~generalManager(){};
        generalManager(string n):manager(n){};
        virtual void requestApplications(request req)
        {
            if(req.requestType == "请假")
            {
                cout<<name<<": "<<req.requestContent<<"数量"<<req.number<<"被批准"<<endl;
            }
            else if(req.requestType == "加薪" && req.number <= 500)
            {
                cout<<name<<": "<<req.requestContent<<"数量"<<req.number<<"被批准"<<endl;
            }
            else if(req.requestType == "加薪" && req.number > 500)
            {
                cout<<name<<": "<<req.requestContent<<"数量"<<req.number<<"再说吧"<<endl;
            }
        }
};

int main()
{
    commonManager *jinli = new commonManager("金立");
    majordomo *zongjian = new majordomo("总监");
    generalManager *zhongjingli = new generalManager("总经理");
    jinli->setSuperior(zongjian);
    zongjian->setSuperior(zhongjingli);

    request req;
    req.requestType = "请假";
    req.requestContent = "小菜请假";
    req.number = 1;
    jinli->requestApplications(req);

    req.requestType = "请假";
    req.requestContent = "小菜请假";
    req.number = 4;
    jinli->requestApplications(req);

    req.requestType = "加薪";
    req.requestContent = "小菜加薪";
    req.number = 500;
    jinli->requestApplications(req);

    req.requestType = "加薪";
    req.requestContent = "小菜加薪";
    req.number = 1000;
    jinli->requestApplications(req);

    delete zongjian;
    delete zhongjingli;
    delete jinli;
    return 0;
}