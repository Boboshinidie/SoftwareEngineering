#include<bits/stdc++.h>
#include<windows.h>
#include<string.h>
using namespace std;
class Admin{
    public:
          int id_;
          int password_;

          void add();//添加账户
          void Delete();//删除账户
          void print();//输出全部账户
}admin;//一个admin对象

//快递
class Express{
	public:
		int id_;
		int is_freight_collect_; //是否到付
		int collect_fare_;
		int defer_time_;//滞留时间
		int defer_fare_;
		string phone_id_;
		int cabinet_id_; //快递柜id
		string name_;
		string adress_;

};
int ID = 1;
//判断是不是单个数字，是数字返回数字，不是返回-1
int is_figure(string str);
//判断是不是数字，全是数字返回1，不是返回-1
int allis_figure(string str);
//将string转化成int，返回转化后的int
int change_toint(string str);
//从文件里读取每行到express里
void get_e(ifstream &ifs,Express &e);
//判断是否有这个快递编号，有返回1，没有返回0
int exist_id(int id,list<Express> e_list);
//主菜单
void Main_();
//快递管理
void Express_admin();
//柜容量管理
void Cabinet_manage();

int ShowAdmins();
void GetAExpress(ifstream &inf,Express &one_line);
void PrintExpressInfo(list<Express> a_list);
void IsCollect(list<Express> a_list);
void IsDefer(list<Express> a_list);
int ShowExpress();
void GetAdmin(int &id,int &password);
int ExpressmanInfoManagement();
//快递员存快递
void Courier_deposit();
int find_post(int check_id);
int Courier_pick();
void Courier();
void Getadmin(ifstream &inf,Admin &one_line);
int pickup(list<Express> a_list,int key);
void User_pickup();
int IsAdmin(list<Admin> a_list,int n,int p);
void cabinet_manage();
//判断是不是单个数字，是数字返回数字，不是返回-1
int is_figure(string str)
{
	if(str.size()>1)
	{
		return -1;
	}
    if ((int)str[0] >= 48 && (int)str[0]<= 57)
    {
        return (int)str[0]-48;
    }
    else
    {
        return -1;
    }
}

//判断是不是数字，全是数字返回1，不是返回-1
int allis_figure(string str)
 {
    for (int i = 0; i < str.size(); i++)
    {
        int tmp = (int)str[i];
        if (tmp >= 48 && tmp <= 57)
        {
            continue;
        }
        else
        {
            return -1;
        }
    }
    return 1;
}

//将string转化成int，返回转化后的int
int change_toint(string str)
{
	int temp=0;
	int dou=1;
	for(int i=str.size()-1;i>=0;i--)
	{
		temp+=dou*((int)str[i]-48);
		dou*=10;
	}
	return temp;
}

//从文件里读取每行到express里
void get_e(ifstream &ifs,Express &e){
    ifs>>e.id_;
    ifs>>e.is_freight_collect_;
    ifs>>e.collect_fare_;
    ifs>>e.defer_time_;
    ifs>>e.defer_fare_;
    ifs>>e.phone_id_;
    ifs>>e.cabinet_id_;
    ifs>>e.name_;
    ifs>>e.adress_;
}

//判断是否有这个快递编号，有返回1，没有返回0
int exist_id(int id,list<Express> e_list)
{
	list<Express>::iterator p=e_list.begin();
    for(;p!=e_list.end();p++)
    {    		//cout<<"pid="<<(*p).id_<<endl;

    	if((*p).id_==id)
    	{
    		//cout<<"pid="<<(*p).id_<<endl;
    		//cout<<"id="<<id<<endl;
    		return 1;
		}
	}
	return 0;
}

//主菜单
void Main_()
{
	system("cls");
	int temp,jud=1;
	string input;
//	for(int i=0;i<=50;i++)
//	{
//		cout<<"<";
//	}
while(jud)
{
	cout<<endl<<"				蚁巢快递"<<endl<<endl;
	cout<<"				1.取件"<<endl;
	cout<<"				2.快递柜管理"<<endl;
	cout<<"				3.快递员信息管理"<<endl;
	cout<<"				4.退出"<<endl;
	cout<<"请输入1-4选择您想要的操作："<<endl;
	cin>>input;
	temp=is_figure(input);
	if(temp==-1||(int)input[0]-48<1||(int)input[0]-48>4)
	{
		cout<<              "输入错误请重新输入"<<endl;
		system("pause");
		system("cls");
	}
	else
	{
		switch(temp)
		{
			case 1:
				User_pickup();
				//break;
			case 2:
				cabinet_manage();
			//	break;
			case 3:
				//cout<<"dadsa";
				ExpressmanInfoManagement();
				//break;
			case 4:
				exit(0);
		}
	}
}
}



//快递管理
void Express_admin()
{
	system("cls");
	list<Express> e_list;
    ifstream if_e;
    if_e.open("Express.txt",ios::in);
    if(!if_e)
	{
        cout<<"文件不存在"<<endl;
    }
    else
	{
        if(if_e.peek() == EOF)
		{
            cout<<"文件为空"<<endl;
            system("pause");
        }
        else
		{
            while(!if_e.eof())
			{
                Express new_e;
                get_e(if_e,new_e);
                e_list.push_back(new_e);
            }
        }
    }
    if_e.close();


    list<Express>::iterator show=e_list.begin();
    for(int i=0;i<e_list.size()-1;show++,i++)
    {
    	cout<<(*show).id_<<" "<<(*show).is_freight_collect_<<" "<<(*show).collect_fare_<<" "<<(*show).defer_time_<<" "<<(*show).defer_fare_<<" "<<(*show).phone_id_<<" "<<(*show).cabinet_id_<<" "<<(*show).name_<<" "<<(*show).adress_<<endl;
	}



	string input,sid;
	int jud=1,temp,jud1=1,id;
	while(jud1)
	{
		cout<<"				请输入快递编号（输入0返回上一界面）"<<endl;
		cin>>sid;
		temp=allis_figure(sid);
		if(temp==-1)
		{
			cout<<              "输入错误请重新输入"<<endl;
			system("pause");
		}
		else
		{


			id=change_toint(sid);
			if(id==0)
			{
				cabinet_manage();
			}
			//cout<<"id="<<id<<endl;
			if(exist_id(id,e_list))
			{
				jud1=0;
			//	cout<<"   enene";
				break;
			}
			else
			{
				cout<<              "没有该编号请重新输入"<<endl;
				system("pause");
			}

		}
	}
	list<Express>::iterator now=e_list.begin();
    for(;now!=e_list.end();now++)
    {
    	if((*now).id_==id)
		break;
	}


while(jud)
{
	cout<<"				1.滞留时间管理"<<endl;
	cout<<"				2.滞留费用管理"<<endl;
	cout<<"				3.返回"<<endl;
	cout<<"请输入1-3选择您想要的操作："<<endl;
	cin>>input;
	temp=is_figure(input);
	if(temp==-1||(int)input[0]-48<1||(int)input[0]-48>3)
	{
		cout<<              "输入错误请重新输入"<<endl;
		system("pause");
	}
	else
	{
		switch(temp)
		{
			case 1:{
				int jud2=1;
				while(jud2)
				{
					cout<<"此快递滞留时间为"<<(*now).defer_time_<<endl;;
					cout<<"请输入修改后的时间"<<endl;
					string stime;
					int jud3=1;
					while(jud3)
					{
						cin>>stime;
						temp=allis_figure(stime);
						if(temp==-1)
						{
							cout<<              "输入错误请重新输入"<<endl;
							system("pause");
						}
						else
						{
							//cout<<(*now).defer_time_<<endl;
							(*now).defer_time_=change_toint(stime);
							//cout<<(*now).defer_time_<<endl;
							list<Express>::iterator show=e_list.begin();
							ofstream of_c("Express.txt");
							for(int i=0;i<e_list.size()-1;i++,show++)
							{
								of_c<<(*show).id_<<" "<<(*show).is_freight_collect_<<" "<<(*show).collect_fare_<<" "<<(*show).defer_time_<<" "<<(*show).defer_fare_<<" "<<(*show).phone_id_<<" "<<(*show).cabinet_id_<<" "<<(*show).name_<<" "<<(*show).adress_<<endl;
							}
							//of_c<<(*show).id_<<" "<<(*show).is_freight_collect_<<" "<<(*show).collect_fare_<<" "<<(*show).defer_time_<<" "<<(*show).defer_fare_<<" "<<(*show).phone_id_<<" "<<(*show).cabinet_id_<<" "<<(*show).name_<<" "<<(*show).adress_<<endl;
							of_c.close();
							break;
						}
					}
					cout<<"更改成功"<<endl;
					system("pause");
					break;
				}
				break;
			}
			case 2:{
				int jud4=1;
				while(jud4)
				{
					cout<<"此快递滞留费用为"<<(*now).defer_fare_<<endl;;
					cout<<"请输入修改后的费用"<<endl;
					string sfare;
					int jud5=1;
					while(jud5)
					{
						cin>>sfare;
						temp=allis_figure(sfare);
						if(temp==-1)
						{
							cout<<              "输入错误请重新输入"<<endl;
							system("pause");
						}
						else
						{
							//cout<<(*now).defer_time_<<endl;
							(*now).defer_fare_=change_toint(sfare);
							//cout<<(*now).defer_time_<<endl;
							list<Express>::iterator show=e_list.begin();
							ofstream of_c("Express.txt");
							for(int i=0;i<e_list.size()-1;i++,show++)
							{
								of_c<<(*show).id_<<" "<<(*show).is_freight_collect_<<" "<<(*show).collect_fare_<<" "<<(*show).defer_time_<<" "<<(*show).defer_fare_<<" "<<(*show).phone_id_<<" "<<(*show).cabinet_id_<<" "<<(*show).name_<<" "<<(*show).adress_<<endl;
							}
							//of_c<<(*show).id_<<" "<<(*show).is_freight_collect_<<" "<<(*show).collect_fare_<<" "<<(*show).defer_time_<<" "<<(*show).defer_fare_<<" "<<(*show).phone_id_<<" "<<(*show).cabinet_id_<<" "<<(*show).name_<<" "<<(*show).adress_<<endl;
							of_c.close();
							break;
						}
					}
					cout<<"更改成功"<<endl;
					system("pause");
					break;
				}
				break;
			}
			case 3:
				cabinet_manage();
				break;
		}
	}
}

}


//柜容量管理
void Cabinet_manage()
{
	system("cls");
	int jud=1;
	list<int> c_list;
    ifstream if_c;
    if_c.open("Cabinet.txt",ios::in);
    if(!if_c) cout<<"文件不存在"<<endl;
    else
	{
        if(if_c.peek() == EOF)
		{
            cout<<"文件为空"<<endl;
            system("pause");
            return ;
    	}
        else
		{
            while(!if_c.eof())
			{
                int new_c;
				if_c>>new_c;
                c_list.push_back(new_c);
            }
        }
    }
	if_c.close();
while(jud)
{
    list<int>::iterator p=c_list.begin();
    for(int i=1;p!=c_list.end();i++,p++)
    {
   		cout<<"当前第"<<i<<"个柜容量："<<*p<<endl;
	}
	cout<<"请输入你要修改哪个柜的柜容量（1-5）（输入0返回）"<<endl;
	string input;
	cin>>input;
	int temp=is_figure(input),num=(int)input[0]-48;
	if(num==0)
	{
		cabinet_manage();
	}
	if(temp==-1||num<1||num>5)
	{
		cout<<"输入错误请重新输入"<<endl;
		system("pause");
		system("cls");
		jud=1;
	}
	else
	{
		cout<<"请输入修改后的柜容量"<<endl;
		cin>>input;
		int temp=allis_figure(input);
		if(temp==-1)
		{
			cout<<"输入错误请重新输入"<<endl;
			system("pause");
			system("cls");
			jud=1;
		}
		else
		{
			list<int>::iterator ir=c_list.begin();
  			for(int i=0;i<num-1;i++)
  			{
  				ir++;
			}
			ir=c_list.erase(ir);
			c_list.insert(ir,change_toint(input));
			list<int>::iterator li=c_list.begin();
			ofstream of_c("Cabinet.txt");
			for(int i=0;i<c_list.size()-1;i++,li++)
			{
				of_c<<*li<<" ";
			}
			of_c<<*li;
			of_c.close();
			int tt=1;
			while(tt)
			{
				cout<<"输入1(继续修改)2(返回)"<<endl;
				string strr;
				cin>>strr;
				//cout<<"strr="<<strr<<endl;
				int temp=is_figure(strr),nn=(int)strr[0]-48;
				//cout<<"temp="<<temp<<endl;
				//cout<<"nn="<<nn<<endl;
				if(temp==-1||nn<1||nn>2)
				{
					cout<<"输入错误请重新输入"<<endl;
					system("pause");
					system("cls");
					tt=1;
				}
				else if(nn==1)
				{
					tt=0;
				}
				else
				{
					tt=0;
					jud=0;
					cout<<"即将返回"<<endl;
					system("pause");
					system("cls");
					cabinet_manage();

				}

			}

		}

	}

}


}

void Admin::add(){
            ofstream write;//写入文件
            ifstream read;//读取文件
            int user,code;//从文件读出来的内容
            int option;
            cout<<" 输入要添加的账号:";
            cin>>id_;
            cout<<"输入密码:";
            cin>>password_;

            read.open("Admin.txt",ios::in);//读取方式打开文件
            if(!read.is_open()){          //判断文件是否存在
                cout<<"文件不存在!"<<endl;
                system("pause");
                system("cls");
                //menu();
            }
            for(;!read.eof();){     //判断是否存在该管理员
                read>>user;
                read>>code;
                if(user==id_){
                    cout<<"该账户已存在,新建失败"<<endl;
                    system("pause");
                    read.close();
                    return;
                }
            }
            read.close();

            write.open("Admin.txt",ios::app);//写入方式打开
            write<<id_<<" "<<password_<<endl;
            cout<<"添加成功!"<<endl;
            write.close();

            cout<<"1.继续创建/2.返回？";
            cin>>option;
            cin.clear();
            cin.sync();
            if(option==1)
                admin.add();
            else if(option==2)
                cout<<"返回上一页"<<endl;
            else
            {
            	cout<<"输入的是非法字符"<<endl;
                system("pause");
			}
                
          }

void Admin::Delete(){
        int i,j,option;//文件行数、遍历指针、输入选择
        ofstream write;//写入文件
        ifstream read;//读取文件
        int user[100],code[100];//从文件读出来的内容

        read.open("Admin.txt",ios::in);
        if(!read.is_open()){          //判断文件是否存在
                cout<<"文件不存在!"<<endl;
                system("pause");
                return;
            }

            system("cls");
            cout<<"******************当前所有账户******************"<<endl;
        for(i=0;!read.eof();i++){
            read>>user[i];
            read>>code[i];
        }
        i--;//减去文件最后一行的回车
        cout<<"*****\033[31;1m账号:"<<std::right<<setw(10)<<user[0]<<"    密码:"<<std::right<<setw(10)<<code[0]<<"   \033[0m******"<<endl;
        for(j=1;j<i;j++)//遍历输出文本所有信息
            cout<<"*****账号:"<<std::right<<setw(10)<<user[j]<<"    密码:"<<std::right<<setw(10)<<code[j]<<"   ******"<<endl;
        read.close();

        cout<<"请输入要删除的账号:";
        cin>>id_;
        for(j=0;j<i;j++){//查询是否有想要删除的账号
            if(id_==user[j])
                break;
        }
        if(j=i)
            cout<<"未找到该账号,删除失败"<<endl;
        else{
            for(;j<i-1;j++){
                user[j]=user[j+1];
                code[j]=code[j+1];
                }
            cout<<"删除成功！"<<endl;
            i--;
            write.open("Admin.txt",ios::trunc);
            for(j=0;j<i;j++)
            write<<user[j]<<" "<<code[j]<<endl;
            write.close();

            cout<<"1.继续删除/2.返回？";
            cin>>option;
            cin.clear();
            cin.sync();
            if(option==1)
                admin.Delete();
            else if(option==2)
                cout<<"返回上一页"<<endl;
            else
            {
            	cout<<"输入的是非法字符"<<endl;
                system("pause");
			}
                
        }
}

void Admin::print(){//输出全部账户
    int i,j,option;
    ifstream read;//读取文件
    int user[100],code[100];//从文件读出来的内容
    read.open("Admin.txt",ios::in);
        if(!read.is_open()){          //判断文件是否存在
                cout<<"文件不存在!"<<endl;
                return;
            }
            system("cls");
            cout<<"******************当前所有账户******************"<<endl;
        for(i=0;!read.eof();i++){
            read>>user[i];
            read>>code[i];
        }
        i--;//减去文件最后一行的回车
        cout<<"*****\033[31;1m账号:"<<std::right<<setw(10)<<user[0]<<"    密码:"<<std::right<<setw(10)<<code[0]<<"   \033[0m******"<<endl;
        for(j=1;j<i;j++)//遍历输出文本所有信息
            cout<<"*****账号:"<<std::right<<setw(10)<<user[j]<<"    密码:"<<std::right<<setw(10)<<code[j]<<"   ******"<<endl;
        read.close();
        cout<<"是否进行数据操作?(1.添加/2.删除/3.返回)";
            cin>>option;
            if(option==1)
                admin.add();
            else if(option==2)
                admin.Delete();
            else if(option==3)
                  cout<<"返回上一页"<<endl;
            else{
                cout<<"输入的是非法字符"<<endl;
            }
}
int ShowAdmins(){
    //list<Admin> admin_list;
    ifstream inf_admin;
    string temp_id,temp_password;

    inf_admin.open("Admin.txt",ios::in);
    if(!inf_admin){
        cout<<"file isn't exists"<<endl;
    }
    else{
        if(inf_admin.peek() == EOF){
            cout<<"file is empty"<<endl;
        }
        cout<<"管理员ID:"<<endl;
        while(!inf_admin.eof())
        {
            inf_admin>>temp_id;
            inf_admin>>temp_password;
            cout<<temp_id<<endl;
        }
        system("pause");
    }

    inf_admin.close();
    return 0;
}

void GetAExpress(ifstream &inf,Express &one_line){
    inf>>one_line.id_;
    inf>>one_line.is_freight_collect_;
    inf>>one_line.collect_fare_;
    inf>>one_line.defer_time_;
    inf>>one_line.defer_fare_;
    inf>>one_line.phone_id_;
    inf>>one_line.cabinet_id_;
    inf>>one_line.name_;
    inf>>one_line.adress_;
}

void PrintExpressInfo(list<Express> a_list){
    list<Express>::iterator p;
    system("cls");
    cout<<left<<setw(4)<<"编号"<<" "<<left<<setw(8)<<"是否到付"<<" "<<left<<setw(8)<<"到付费用"<<" "<<left<<setw(8)<<"滞留时间"<<" "
    <<left<<setw(8)<<"滞留费用"<<" "<<left<<setw(11)<<"电话号码"<<" "<<left<<setw(4)<<"柜号"<<" "<<left<<setw(6)<<"姓名"<<" "<<left<<setw(10)<<"地址"<<" "<<endl;   //标题
    for(p=a_list.begin();(p==a_list.begin()||p!=a_list.end());p++){
        cout<<left<<setw(4)<<(*p).id_<<" "<<left<<setw(8)<<(*p).is_freight_collect_<<" "<<left<<setw(8)<<(*p).collect_fare_<<" "<<left<<setw(8)<<(*p).defer_time_<<" "
        <<left<<setw(8)<<(*p).defer_fare_<<" "<<left<<setw(11)<<(*p).phone_id_<<" "<<left<<setw(4)<<(*p).cabinet_id_<<" "<<left<<setw(6)<<(*p).name_<<" "<<left<<setw(10)<<(*p).adress_<<" "<<endl;
    }
    cout<<"输入'1'以退出"<<endl<<"输入'2'按到付分类"<<endl<<"输入'3'按滞留分类"<<endl;
}

void IsCollect(list<Express> a_list){//是否到付
    list<Express>::iterator p;
    system("cls");
    cout<<left<<setw(4)<<"编号"<<" "<<left<<setw(8)<<"是否到付"<<" "<<left<<setw(8)<<"到付费用"<<" "<<left<<setw(8)<<"滞留时间"<<" "
    <<left<<setw(8)<<"滞留费用"<<" "<<left<<setw(11)<<"电话号码"<<" "<<left<<setw(4)<<"柜号"<<" "<<left<<setw(6)<<"姓名"<<" "<<left<<setw(10)<<"地址"<<" "<<endl;
    for(p=a_list.begin();(p==a_list.begin()||p!=a_list.end());p++){
        if((*p).is_freight_collect_==1)
            cout<<left<<setw(4)<<(*p).id_<<" "<<left<<setw(8)<<(*p).is_freight_collect_<<" "<<left<<setw(8)<<(*p).collect_fare_<<" "<<left<<setw(8)<<(*p).defer_time_<<" "
            <<left<<setw(8)<<(*p).defer_fare_<<" "<<left<<setw(11)<<(*p).phone_id_<<" "<<left<<setw(4)<<(*p).cabinet_id_<<" "<<left<<setw(6)<<(*p).name_<<" "<<left<<setw(10)<<(*p).adress_<<" "<<endl;
    }
    for(p=a_list.begin();(p==a_list.begin()||p!=a_list.end());p++){
        if((*p).is_freight_collect_==0)
            cout<<left<<setw(4)<<(*p).id_<<" "<<left<<setw(8)<<(*p).is_freight_collect_<<" "<<left<<setw(8)<<(*p).collect_fare_<<" "<<left<<setw(8)<<(*p).defer_time_<<" "
            <<left<<setw(8)<<(*p).defer_fare_<<" "<<left<<setw(11)<<(*p).phone_id_<<" "<<left<<setw(4)<<(*p).cabinet_id_<<" "<<left<<setw(6)<<(*p).name_<<" "<<left<<setw(10)<<(*p).adress_<<" "<<endl;
    }
    cout<<"输入'1'以退出"<<endl<<"输入'2'按到付分类"<<endl<<"输入'3'按滞留分类"<<endl;
}


void IsDefer(list<Express> a_list){//是否滞留
    list<Express>::iterator p;
    system("cls");
    cout<<left<<setw(4)<<"编号"<<" "<<left<<setw(8)<<"是否到付"<<" "<<left<<setw(8)<<"到付费用"<<" "<<left<<setw(8)<<"滞留时间"<<" "
    <<left<<setw(8)<<"滞留费用"<<" "<<left<<setw(11)<<"电话号码"<<" "<<left<<setw(4)<<"柜号"<<" "<<left<<setw(6)<<"姓名"<<" "<<left<<setw(10)<<"地址"<<" "<<endl;
    for(p=a_list.begin();(p==a_list.begin()||p!=a_list.end());p++){
        if((*p).defer_fare_>0)
            cout<<left<<setw(4)<<(*p).id_<<" "<<left<<setw(8)<<(*p).is_freight_collect_<<" "<<left<<setw(8)<<(*p).collect_fare_<<" "<<left<<setw(8)<<(*p).defer_time_<<" "
            <<left<<setw(8)<<(*p).defer_fare_<<" "<<left<<setw(11)<<(*p).phone_id_<<" "<<left<<setw(4)<<(*p).cabinet_id_<<" "<<left<<setw(6)<<(*p).name_<<" "<<left<<setw(10)<<(*p).adress_<<" "<<endl;
    }
    for(p=a_list.begin();(p==a_list.begin()||p!=a_list.end());p++){
        if((*p).defer_fare_==0)
            cout<<left<<setw(4)<<(*p).id_<<" "<<left<<setw(8)<<(*p).is_freight_collect_<<" "<<left<<setw(8)<<(*p).collect_fare_<<" "<<left<<setw(8)<<(*p).defer_time_<<" "
            <<left<<setw(8)<<(*p).defer_fare_<<" "<<left<<setw(11)<<(*p).phone_id_<<" "<<left<<setw(4)<<(*p).cabinet_id_<<" "<<left<<setw(6)<<(*p).name_<<" "<<left<<setw(10)<<(*p).adress_<<" "<<endl;
    }
    cout<<"输入'1'以退出"<<endl<<"输入'2'按到付分类"<<endl<<"输入'3'按滞留分类"<<endl;
}

int ShowExpress(){
    list<Express> express_list;
    ifstream inf_express;
    inf_express.open("Express.txt",ios::in);//读取
    if(!inf_express){//文件是否存在
        cout<<"file isn't exists"<<endl;
    }
    else{
        if(inf_express.peek() == EOF){ //文件是否空
            cout<<"file is empty"<<endl;
            system("pause");
            return 0;
        }
        else{
            while(!inf_express.eof()){
                Express new_express;
                GetAExpress(inf_express,new_express);
                express_list.push_back(new_express);
            }
        }
    }
    inf_express.close();

    PrintExpressInfo(express_list);//打印信息
    string choice;    //查找筛选显示
    while(1){
        cin>>choice;
        if(choice=="1")cabinet_manage();
        else if(choice == "2") IsCollect(express_list);
        else if(choice == "3") IsDefer(express_list);
    }
    cout<<"即将返回"<<endl;
    system("pause");
	cabinet_manage();
}

void GetAdmin(int &id,int &password){//得到总管理员,将Admin文件中第一个作为总管理员
    ifstream inf_admin;
    inf_admin.open("Admin.txt",ios::in);
    if(!inf_admin){
        cout<<"file isn't exists"<<endl;
        exit(0);
    }else{
        if(inf_admin.peek() == EOF){
            cout<<"file is empty"<<endl;
            exit(0);
        }
        inf_admin>>id;
        inf_admin>>password;
    }
    inf_admin.close();
}


int ExpressmanInfoManagement(){ //快递员信息管理
	
	system("cls");
    int admin_id=(0);//总管理员账号
    int admin_password=(0); //总管理员密码
    GetAdmin(admin_id,admin_password);
    int temp_admin;
    int temp_password;
    while(1){
    system("cls");
    cin.sync();
    printf("请输入总管理员账号:\n");
    scanf("%d",&temp_admin);
    printf("请输入总管理员密码:\n");
    scanf("%d",&temp_password);
    if(admin_id==temp_admin&&admin_password==temp_password){
        break;
    }else{
        printf("id or password error!\n");
        system("pause");
    }
    }
    while(1){
    system("cls");
    printf("1.添加账户  2.删除账户  3.显示所有  4.返回\n");
    printf("输入对应数字\n");
    int choice=(0);
    scanf("%d",&choice);
    switch(choice){
        case 1:{
            admin.add();
            break;
        }
        case 2:{
            admin.Delete();
            break;
        }
        case 3:{
            admin.print();
            break;
        }
        case 4:{
            Main_();
            break;
        }
        default:{
            cin.sync();
            break;
        }
    }
    }
    return 0;
}



void Courier_deposit(){//快递员存快递
    Express x;
    cout << "请输入姓名：", cin >> x.name_;
    cout << "请输入地址：", cin >> x.adress_;
    cout << "请输入电话号：", cin >> x.phone_id_;
    x.defer_fare_ = 0;
    x.defer_time_ = 0;
    cout << "请输入快递柜编号(1-5):", cin >> x.cabinet_id_;
    Courier();
    x.id_ = ID;
    cout << "0.否 1.是" << endl;
    cout << "请输入是否到付：", cin >> x.is_freight_collect_;
    if(x.is_freight_collect_ == 1){
        cout << "请输入快递费：";
        cin >> x.collect_fare_;
    }
    else
        x.collect_fare_ = 0;
    system("cls");
    cout << "柜门已打开，请放入包裹";
    system("pause");
    ofstream fout("Express.txt", ios::out | ios::app);//记得改路径
    if(fout.is_open()){
        fout<<x.id_<<" "<<x.is_freight_collect_<<" "<<x.collect_fare_
            <<" "<<x.defer_time_<<" "<<x.defer_fare_<<" "
            <<x.phone_id_<<" "<<x.cabinet_id_<<" "<<x.name_<<" "<<x.adress_<<endl;
        fout.close();
    }
    cout << "成功！即将返回"<<endl;
	system("pause");
	cabinet_manage();
}
int find_post(int check_id){
    ifstream fin("Express.txt", ios::in);//记得改路径
    string input;
    int index = 1;
    while(getline(fin, input)){
        stringstream str(input);
        string true_id;
        int num;
        getline(str, true_id, ' ');
        istringstream ss(true_id);
        ss >> num;
        if(check_id == num){
            fin.close();
            return index;
        }
        index++;
    }
    fin.close();
    return 0;
}
int Courier_pick(){
    cout << "请输入包裹编号：";
    int id;
    cin >> id;
    cout << "查询中，请稍后";
    Sleep(1000);
    while(!find_post(id)){
        system("cls");
        cout << "-1.退出" << endl;
        cout << "1.重新输入包裹编号:" << endl;
        cout << "未查询到包裹，请选择：";
        int x;
        cin >> x;
        if(x == 1){
            cout << "请输入包裹编号：";
            cin >> id;
        }
        else if(x == -1)
            return 0;
        else{
            cout << "错误输入!";
            system("pause");
        }
    }
    cout << endl << "柜门已打开，请取出包裹" << endl;
    system("pause");

    string S[1000];
    int index = find_post(id);

    ifstream fin("Express.txt", ios::in);//记得改路径
    int j = 1;
    while(getline(fin, S[j]))
        j++;
    fin.close();

    ofstream fout("Express.txt");//记得改路径
    int i = 1;
    while(!S[i].empty()){
        if(i == index){
            i++;
            continue;
        }
        else{
            fout << S[i] << endl;
            i++;
        }
    }
    fout.close();
    system("cls");
    cout << "成功！，即将返回"<<endl;
    system("pause");
    cabinet_manage();
    return 0;
}

void Courier() {
    ifstream fin("Express.txt", ios::in);
    string line, last_line;
    while (getline(fin, line))
    {
        last_line = line;
    }
    stringstream str(last_line);
    string id;
    int last_id;
    getline(str, id, ' ');
    istringstream ss(id);
    ss >> last_id;
    ID = last_id + 1;
    fin.close();
}



void Getadmin(ifstream &inf,Admin &one_line)
{
	inf>>one_line.id_;
	inf>>one_line.password_;
}

int pickup(list<Express> a_list,int key)
{
    string pay;
	list<Express>::iterator p;
    system("cls");
    for(p=a_list.begin();(p==a_list.begin()||p!=a_list.end());p++)
	{
		if((*p).id_==key)
    	{
    	if((*p).is_freight_collect_==1)
    	{
    LLLL:	cout<<"该待取包裹为到付，费用为"<<(*p).collect_fare_<<",请支付('yes'支付成功)"<<endl;
    		cin>>pay;
    		if(pay=="yes")
    		{
    			if((*p).defer_fare_>0)
    			{
    	LLL:		cout<<"\n该待取包裹已滞留"<<(*p).defer_time_<<"天,请支付滞留费用('yes'支付成功)"<<(*p).defer_fare_<<endl;
    				cin>>pay;
    				if(pay=="yes")
    				{
    					cout<<"请前往"<<(*p).cabinet_id_<<"号快递柜取件"<<endl;
					}
					else
					{
						cout<<"支付失败，请重新支付"<<endl;
						Sleep(2);
						goto LLL;
					}
				}

				a_list.erase(p);
				list<Express>::iterator show=a_list.begin();
							ofstream of_c("Express.txt");
							for(int i=0;i<a_list.size()-1;i++,show++)
							{
								of_c<<(*show).id_<<" "<<(*show).is_freight_collect_<<" "<<(*show).collect_fare_<<" "<<(*show).defer_time_<<" "<<(*show).defer_fare_<<" "<<(*show).phone_id_<<" "<<(*show).cabinet_id_<<" "<<(*show).name_<<" "<<(*show).adress_<<endl;
							}
							//of_c<<(*show).id_<<" "<<(*show).is_freight_collect_<<" "<<(*show).collect_fare_<<" "<<(*show).defer_time_<<" "<<(*show).defer_fare_<<" "<<(*show).phone_id_<<" "<<(*show).cabinet_id_<<" "<<(*show).name_<<" "<<(*show).adress_<<endl;
							of_c.close();
			}
			else
			{
				goto LLLL;
			}
		}
		else
		{
			if((*p).defer_fare_>0)
    			{
    	LLLLL:		cout<<"\n该待取包裹已滞留"<<(*p).defer_time_<<"天,请支付滞留费用('yes'支付成功)"<<(*p).defer_fare_<<endl;
    				cin>>pay;
    				if(pay=="yes")
    				{
    					 cout<<"请前往"<<(*p).cabinet_id_<<"号快递柜取件"<<endl;
					}
					else
					{
						cout<<"支付失败，请重新支付"<<endl;
						Sleep(2);
						goto LLLLL;
					}
				}
			else
			{
				cout<<"请前往"<<(*p).cabinet_id_<<"号快递柜取件"<<endl;
			 }
		}

		return 1;
		}
	}
	return 0;
}

void User_pickup()
{
	system("cls");
	int key;
	int x;
    list<Express> express_list;
    ifstream inf_express;
    inf_express.open("Express.txt",ios::in);//读取
    if(!inf_express)
	{//文件是否存在
        cout<<"file isn't exists"<<endl;
    }
    else
	{
        if(inf_express.peek() == EOF)
		{ //文件是否空
            cout<<"file is empty"<<endl;
            system("pause");
            return;
        }
        else
		{
            while(!inf_express.eof())
			{
				Express new_express;
				GetAExpress(inf_express,new_express);
                express_list.push_back(new_express);
            }
        }
    }
    inf_express.close();
    while(1)
    {
    	cout<<"请输入取件码:";
    	cin>>key;
    	if(pickup(express_list,key)==1)
    	{
    		cout<<"1.返回  2.继续取件";
            cin>>x;
            if(x==1)
            {
				Main_();
			}
			else if(x==2)
			{
				continue;
			}
		}
		else
		{
			cout<<"未查询到快递编号。1.重新输入 2.返回";
			cin>>x;
            if(x==1)
            {
               	continue;
			}
			else if(x==2)
			{
				Main_();
			}
		}
	}
}

int IsAdmin(list<Admin> a_list,int n,int p)
{
	list<Admin>::iterator p1;
    system("cls");
    for(p1=a_list.begin();(p1==a_list.begin()||p1!=a_list.end());p1++)
	{
        if(((*p1).id_==n)&&((*p1).password_==p))
        {
        	return 1;
		}
    }
    return 0;
}

void cabinet_manage()
{
	int x;
	list<Admin> admin_list;
    ifstream inf_admin;
    inf_admin.open("Admin.txt",ios::in);//读取
    if(!inf_admin)
	{//文件是否存在
        cout<<"file isn't exists"<<endl;
    }
    else
	{
        if(inf_admin.peek() == EOF)
		{ //文件是否空
            cout<<"file is empty"<<endl;
            system("pause");
            return;
        }
        else
		{
            while(!inf_admin.eof())
			{
				Admin new_admin;
				Getadmin(inf_admin,new_admin);
                admin_list.push_back(new_admin);
            }
        }
    }
    inf_admin.close();
    int n,p;
PP:    system("cls");
    cout<<"请输入管理员账号：";
	cin>>n;
	cout<<"请输入密码：";
	cin>>p;
	if(IsAdmin(admin_list,n,p)==1)
	{
		cout<<"1.快递管理 2.存件 3.查看所有快递 4.取件 5.柜容量管理 6.退出";
		cin>>x;
		switch(x){
			case 1:
				Express_admin();
				break;
			case 2:
				Courier_deposit();
				break;
			case 3:
				ShowExpress();
				break;
			case 4:
				Courier_pick();
				break;
			case 5:
				Cabinet_manage();
				break;
			case 6:
				Main_();
		}
	}
	else
	{
		cout<<"账号密码错误 1.重新输入 2.返回 ";
		cin>>x;
		if(x==1)
		{
			goto PP;
		 }
		 else
		 {
			Main_();
		 }
	}
}

int main()
{
	Main_();
}
