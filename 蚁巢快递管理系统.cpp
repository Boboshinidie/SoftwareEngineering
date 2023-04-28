#include<bits/stdc++.h>
#include<windows.h>
#include<string.h>
using namespace std;
class Admin{
    public:
          int id_;
          int password_;

          void add();//����˻�
          void Delete();//ɾ���˻�
          void print();//���ȫ���˻�
}admin;//һ��admin����

//���
class Express{
	public:
		int id_;
		int is_freight_collect_; //�Ƿ񵽸�
		int collect_fare_;
		int defer_time_;//����ʱ��
		int defer_fare_;
		string phone_id_;
		int cabinet_id_; //��ݹ�id
		string name_;
		string adress_;

};
int ID = 1;
//�ж��ǲ��ǵ������֣������ַ������֣����Ƿ���-1
int is_figure(string str);
//�ж��ǲ������֣�ȫ�����ַ���1�����Ƿ���-1
int allis_figure(string str);
//��stringת����int������ת�����int
int change_toint(string str);
//���ļ����ȡÿ�е�express��
void get_e(ifstream &ifs,Express &e);
//�ж��Ƿ��������ݱ�ţ��з���1��û�з���0
int exist_id(int id,list<Express> e_list);
//���˵�
void Main_();
//��ݹ���
void Express_admin();
//����������
void Cabinet_manage();

int ShowAdmins();
void GetAExpress(ifstream &inf,Express &one_line);
void PrintExpressInfo(list<Express> a_list);
void IsCollect(list<Express> a_list);
void IsDefer(list<Express> a_list);
int ShowExpress();
void GetAdmin(int &id,int &password);
int ExpressmanInfoManagement();
//���Ա����
void Courier_deposit();
int find_post(int check_id);
int Courier_pick();
void Courier();
void Getadmin(ifstream &inf,Admin &one_line);
int pickup(list<Express> a_list,int key);
void User_pickup();
int IsAdmin(list<Admin> a_list,int n,int p);
void cabinet_manage();
//�ж��ǲ��ǵ������֣������ַ������֣����Ƿ���-1
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

//�ж��ǲ������֣�ȫ�����ַ���1�����Ƿ���-1
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

//��stringת����int������ת�����int
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

//���ļ����ȡÿ�е�express��
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

//�ж��Ƿ��������ݱ�ţ��з���1��û�з���0
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

//���˵�
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
	cout<<endl<<"				�ϳ����"<<endl<<endl;
	cout<<"				1.ȡ��"<<endl;
	cout<<"				2.��ݹ����"<<endl;
	cout<<"				3.���Ա��Ϣ����"<<endl;
	cout<<"				4.�˳�"<<endl;
	cout<<"������1-4ѡ������Ҫ�Ĳ�����"<<endl;
	cin>>input;
	temp=is_figure(input);
	if(temp==-1||(int)input[0]-48<1||(int)input[0]-48>4)
	{
		cout<<              "�����������������"<<endl;
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



//��ݹ���
void Express_admin()
{
	system("cls");
	list<Express> e_list;
    ifstream if_e;
    if_e.open("Express.txt",ios::in);
    if(!if_e)
	{
        cout<<"�ļ�������"<<endl;
    }
    else
	{
        if(if_e.peek() == EOF)
		{
            cout<<"�ļ�Ϊ��"<<endl;
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
		cout<<"				�������ݱ�ţ�����0������һ���棩"<<endl;
		cin>>sid;
		temp=allis_figure(sid);
		if(temp==-1)
		{
			cout<<              "�����������������"<<endl;
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
				cout<<              "û�иñ������������"<<endl;
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
	cout<<"				1.����ʱ�����"<<endl;
	cout<<"				2.�������ù���"<<endl;
	cout<<"				3.����"<<endl;
	cout<<"������1-3ѡ������Ҫ�Ĳ�����"<<endl;
	cin>>input;
	temp=is_figure(input);
	if(temp==-1||(int)input[0]-48<1||(int)input[0]-48>3)
	{
		cout<<              "�����������������"<<endl;
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
					cout<<"�˿������ʱ��Ϊ"<<(*now).defer_time_<<endl;;
					cout<<"�������޸ĺ��ʱ��"<<endl;
					string stime;
					int jud3=1;
					while(jud3)
					{
						cin>>stime;
						temp=allis_figure(stime);
						if(temp==-1)
						{
							cout<<              "�����������������"<<endl;
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
					cout<<"���ĳɹ�"<<endl;
					system("pause");
					break;
				}
				break;
			}
			case 2:{
				int jud4=1;
				while(jud4)
				{
					cout<<"�˿����������Ϊ"<<(*now).defer_fare_<<endl;;
					cout<<"�������޸ĺ�ķ���"<<endl;
					string sfare;
					int jud5=1;
					while(jud5)
					{
						cin>>sfare;
						temp=allis_figure(sfare);
						if(temp==-1)
						{
							cout<<              "�����������������"<<endl;
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
					cout<<"���ĳɹ�"<<endl;
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


//����������
void Cabinet_manage()
{
	system("cls");
	int jud=1;
	list<int> c_list;
    ifstream if_c;
    if_c.open("Cabinet.txt",ios::in);
    if(!if_c) cout<<"�ļ�������"<<endl;
    else
	{
        if(if_c.peek() == EOF)
		{
            cout<<"�ļ�Ϊ��"<<endl;
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
   		cout<<"��ǰ��"<<i<<"����������"<<*p<<endl;
	}
	cout<<"��������Ҫ�޸��ĸ���Ĺ�������1-5��������0���أ�"<<endl;
	string input;
	cin>>input;
	int temp=is_figure(input),num=(int)input[0]-48;
	if(num==0)
	{
		cabinet_manage();
	}
	if(temp==-1||num<1||num>5)
	{
		cout<<"�����������������"<<endl;
		system("pause");
		system("cls");
		jud=1;
	}
	else
	{
		cout<<"�������޸ĺ�Ĺ�����"<<endl;
		cin>>input;
		int temp=allis_figure(input);
		if(temp==-1)
		{
			cout<<"�����������������"<<endl;
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
				cout<<"����1(�����޸�)2(����)"<<endl;
				string strr;
				cin>>strr;
				//cout<<"strr="<<strr<<endl;
				int temp=is_figure(strr),nn=(int)strr[0]-48;
				//cout<<"temp="<<temp<<endl;
				//cout<<"nn="<<nn<<endl;
				if(temp==-1||nn<1||nn>2)
				{
					cout<<"�����������������"<<endl;
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
					cout<<"��������"<<endl;
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
            ofstream write;//д���ļ�
            ifstream read;//��ȡ�ļ�
            int user,code;//���ļ�������������
            int option;
            cout<<" ����Ҫ��ӵ��˺�:";
            cin>>id_;
            cout<<"��������:";
            cin>>password_;

            read.open("Admin.txt",ios::in);//��ȡ��ʽ���ļ�
            if(!read.is_open()){          //�ж��ļ��Ƿ����
                cout<<"�ļ�������!"<<endl;
                system("pause");
                system("cls");
                //menu();
            }
            for(;!read.eof();){     //�ж��Ƿ���ڸù���Ա
                read>>user;
                read>>code;
                if(user==id_){
                    cout<<"���˻��Ѵ���,�½�ʧ��"<<endl;
                    system("pause");
                    read.close();
                    return;
                }
            }
            read.close();

            write.open("Admin.txt",ios::app);//д�뷽ʽ��
            write<<id_<<" "<<password_<<endl;
            cout<<"��ӳɹ�!"<<endl;
            write.close();

            cout<<"1.��������/2.���أ�";
            cin>>option;
            cin.clear();
            cin.sync();
            if(option==1)
                admin.add();
            else if(option==2)
                cout<<"������һҳ"<<endl;
            else
            {
            	cout<<"������ǷǷ��ַ�"<<endl;
                system("pause");
			}
                
          }

void Admin::Delete(){
        int i,j,option;//�ļ�����������ָ�롢����ѡ��
        ofstream write;//д���ļ�
        ifstream read;//��ȡ�ļ�
        int user[100],code[100];//���ļ�������������

        read.open("Admin.txt",ios::in);
        if(!read.is_open()){          //�ж��ļ��Ƿ����
                cout<<"�ļ�������!"<<endl;
                system("pause");
                return;
            }

            system("cls");
            cout<<"******************��ǰ�����˻�******************"<<endl;
        for(i=0;!read.eof();i++){
            read>>user[i];
            read>>code[i];
        }
        i--;//��ȥ�ļ����һ�еĻس�
        cout<<"*****\033[31;1m�˺�:"<<std::right<<setw(10)<<user[0]<<"    ����:"<<std::right<<setw(10)<<code[0]<<"   \033[0m******"<<endl;
        for(j=1;j<i;j++)//��������ı�������Ϣ
            cout<<"*****�˺�:"<<std::right<<setw(10)<<user[j]<<"    ����:"<<std::right<<setw(10)<<code[j]<<"   ******"<<endl;
        read.close();

        cout<<"������Ҫɾ�����˺�:";
        cin>>id_;
        for(j=0;j<i;j++){//��ѯ�Ƿ�����Ҫɾ�����˺�
            if(id_==user[j])
                break;
        }
        if(j=i)
            cout<<"δ�ҵ����˺�,ɾ��ʧ��"<<endl;
        else{
            for(;j<i-1;j++){
                user[j]=user[j+1];
                code[j]=code[j+1];
                }
            cout<<"ɾ���ɹ���"<<endl;
            i--;
            write.open("Admin.txt",ios::trunc);
            for(j=0;j<i;j++)
            write<<user[j]<<" "<<code[j]<<endl;
            write.close();

            cout<<"1.����ɾ��/2.���أ�";
            cin>>option;
            cin.clear();
            cin.sync();
            if(option==1)
                admin.Delete();
            else if(option==2)
                cout<<"������һҳ"<<endl;
            else
            {
            	cout<<"������ǷǷ��ַ�"<<endl;
                system("pause");
			}
                
        }
}

void Admin::print(){//���ȫ���˻�
    int i,j,option;
    ifstream read;//��ȡ�ļ�
    int user[100],code[100];//���ļ�������������
    read.open("Admin.txt",ios::in);
        if(!read.is_open()){          //�ж��ļ��Ƿ����
                cout<<"�ļ�������!"<<endl;
                return;
            }
            system("cls");
            cout<<"******************��ǰ�����˻�******************"<<endl;
        for(i=0;!read.eof();i++){
            read>>user[i];
            read>>code[i];
        }
        i--;//��ȥ�ļ����һ�еĻس�
        cout<<"*****\033[31;1m�˺�:"<<std::right<<setw(10)<<user[0]<<"    ����:"<<std::right<<setw(10)<<code[0]<<"   \033[0m******"<<endl;
        for(j=1;j<i;j++)//��������ı�������Ϣ
            cout<<"*****�˺�:"<<std::right<<setw(10)<<user[j]<<"    ����:"<<std::right<<setw(10)<<code[j]<<"   ******"<<endl;
        read.close();
        cout<<"�Ƿ�������ݲ���?(1.���/2.ɾ��/3.����)";
            cin>>option;
            if(option==1)
                admin.add();
            else if(option==2)
                admin.Delete();
            else if(option==3)
                  cout<<"������һҳ"<<endl;
            else{
                cout<<"������ǷǷ��ַ�"<<endl;
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
        cout<<"����ԱID:"<<endl;
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
    cout<<left<<setw(4)<<"���"<<" "<<left<<setw(8)<<"�Ƿ񵽸�"<<" "<<left<<setw(8)<<"��������"<<" "<<left<<setw(8)<<"����ʱ��"<<" "
    <<left<<setw(8)<<"��������"<<" "<<left<<setw(11)<<"�绰����"<<" "<<left<<setw(4)<<"���"<<" "<<left<<setw(6)<<"����"<<" "<<left<<setw(10)<<"��ַ"<<" "<<endl;   //����
    for(p=a_list.begin();(p==a_list.begin()||p!=a_list.end());p++){
        cout<<left<<setw(4)<<(*p).id_<<" "<<left<<setw(8)<<(*p).is_freight_collect_<<" "<<left<<setw(8)<<(*p).collect_fare_<<" "<<left<<setw(8)<<(*p).defer_time_<<" "
        <<left<<setw(8)<<(*p).defer_fare_<<" "<<left<<setw(11)<<(*p).phone_id_<<" "<<left<<setw(4)<<(*p).cabinet_id_<<" "<<left<<setw(6)<<(*p).name_<<" "<<left<<setw(10)<<(*p).adress_<<" "<<endl;
    }
    cout<<"����'1'���˳�"<<endl<<"����'2'����������"<<endl<<"����'3'����������"<<endl;
}

void IsCollect(list<Express> a_list){//�Ƿ񵽸�
    list<Express>::iterator p;
    system("cls");
    cout<<left<<setw(4)<<"���"<<" "<<left<<setw(8)<<"�Ƿ񵽸�"<<" "<<left<<setw(8)<<"��������"<<" "<<left<<setw(8)<<"����ʱ��"<<" "
    <<left<<setw(8)<<"��������"<<" "<<left<<setw(11)<<"�绰����"<<" "<<left<<setw(4)<<"���"<<" "<<left<<setw(6)<<"����"<<" "<<left<<setw(10)<<"��ַ"<<" "<<endl;
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
    cout<<"����'1'���˳�"<<endl<<"����'2'����������"<<endl<<"����'3'����������"<<endl;
}


void IsDefer(list<Express> a_list){//�Ƿ�����
    list<Express>::iterator p;
    system("cls");
    cout<<left<<setw(4)<<"���"<<" "<<left<<setw(8)<<"�Ƿ񵽸�"<<" "<<left<<setw(8)<<"��������"<<" "<<left<<setw(8)<<"����ʱ��"<<" "
    <<left<<setw(8)<<"��������"<<" "<<left<<setw(11)<<"�绰����"<<" "<<left<<setw(4)<<"���"<<" "<<left<<setw(6)<<"����"<<" "<<left<<setw(10)<<"��ַ"<<" "<<endl;
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
    cout<<"����'1'���˳�"<<endl<<"����'2'����������"<<endl<<"����'3'����������"<<endl;
}

int ShowExpress(){
    list<Express> express_list;
    ifstream inf_express;
    inf_express.open("Express.txt",ios::in);//��ȡ
    if(!inf_express){//�ļ��Ƿ����
        cout<<"file isn't exists"<<endl;
    }
    else{
        if(inf_express.peek() == EOF){ //�ļ��Ƿ��
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

    PrintExpressInfo(express_list);//��ӡ��Ϣ
    string choice;    //����ɸѡ��ʾ
    while(1){
        cin>>choice;
        if(choice=="1")cabinet_manage();
        else if(choice == "2") IsCollect(express_list);
        else if(choice == "3") IsDefer(express_list);
    }
    cout<<"��������"<<endl;
    system("pause");
	cabinet_manage();
}

void GetAdmin(int &id,int &password){//�õ��ܹ���Ա,��Admin�ļ��е�һ����Ϊ�ܹ���Ա
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


int ExpressmanInfoManagement(){ //���Ա��Ϣ����
	
	system("cls");
    int admin_id=(0);//�ܹ���Ա�˺�
    int admin_password=(0); //�ܹ���Ա����
    GetAdmin(admin_id,admin_password);
    int temp_admin;
    int temp_password;
    while(1){
    system("cls");
    cin.sync();
    printf("�������ܹ���Ա�˺�:\n");
    scanf("%d",&temp_admin);
    printf("�������ܹ���Ա����:\n");
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
    printf("1.����˻�  2.ɾ���˻�  3.��ʾ����  4.����\n");
    printf("�����Ӧ����\n");
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



void Courier_deposit(){//���Ա����
    Express x;
    cout << "������������", cin >> x.name_;
    cout << "�������ַ��", cin >> x.adress_;
    cout << "������绰�ţ�", cin >> x.phone_id_;
    x.defer_fare_ = 0;
    x.defer_time_ = 0;
    cout << "�������ݹ���(1-5):", cin >> x.cabinet_id_;
    Courier();
    x.id_ = ID;
    cout << "0.�� 1.��" << endl;
    cout << "�������Ƿ񵽸���", cin >> x.is_freight_collect_;
    if(x.is_freight_collect_ == 1){
        cout << "�������ݷѣ�";
        cin >> x.collect_fare_;
    }
    else
        x.collect_fare_ = 0;
    system("cls");
    cout << "�����Ѵ򿪣���������";
    system("pause");
    ofstream fout("Express.txt", ios::out | ios::app);//�ǵø�·��
    if(fout.is_open()){
        fout<<x.id_<<" "<<x.is_freight_collect_<<" "<<x.collect_fare_
            <<" "<<x.defer_time_<<" "<<x.defer_fare_<<" "
            <<x.phone_id_<<" "<<x.cabinet_id_<<" "<<x.name_<<" "<<x.adress_<<endl;
        fout.close();
    }
    cout << "�ɹ�����������"<<endl;
	system("pause");
	cabinet_manage();
}
int find_post(int check_id){
    ifstream fin("Express.txt", ios::in);//�ǵø�·��
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
    cout << "�����������ţ�";
    int id;
    cin >> id;
    cout << "��ѯ�У����Ժ�";
    Sleep(1000);
    while(!find_post(id)){
        system("cls");
        cout << "-1.�˳�" << endl;
        cout << "1.��������������:" << endl;
        cout << "δ��ѯ����������ѡ��";
        int x;
        cin >> x;
        if(x == 1){
            cout << "�����������ţ�";
            cin >> id;
        }
        else if(x == -1)
            return 0;
        else{
            cout << "��������!";
            system("pause");
        }
    }
    cout << endl << "�����Ѵ򿪣���ȡ������" << endl;
    system("pause");

    string S[1000];
    int index = find_post(id);

    ifstream fin("Express.txt", ios::in);//�ǵø�·��
    int j = 1;
    while(getline(fin, S[j]))
        j++;
    fin.close();

    ofstream fout("Express.txt");//�ǵø�·��
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
    cout << "�ɹ�������������"<<endl;
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
    LLLL:	cout<<"�ô�ȡ����Ϊ����������Ϊ"<<(*p).collect_fare_<<",��֧��('yes'֧���ɹ�)"<<endl;
    		cin>>pay;
    		if(pay=="yes")
    		{
    			if((*p).defer_fare_>0)
    			{
    	LLL:		cout<<"\n�ô�ȡ����������"<<(*p).defer_time_<<"��,��֧����������('yes'֧���ɹ�)"<<(*p).defer_fare_<<endl;
    				cin>>pay;
    				if(pay=="yes")
    				{
    					cout<<"��ǰ��"<<(*p).cabinet_id_<<"�ſ�ݹ�ȡ��"<<endl;
					}
					else
					{
						cout<<"֧��ʧ�ܣ�������֧��"<<endl;
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
    	LLLLL:		cout<<"\n�ô�ȡ����������"<<(*p).defer_time_<<"��,��֧����������('yes'֧���ɹ�)"<<(*p).defer_fare_<<endl;
    				cin>>pay;
    				if(pay=="yes")
    				{
    					 cout<<"��ǰ��"<<(*p).cabinet_id_<<"�ſ�ݹ�ȡ��"<<endl;
					}
					else
					{
						cout<<"֧��ʧ�ܣ�������֧��"<<endl;
						Sleep(2);
						goto LLLLL;
					}
				}
			else
			{
				cout<<"��ǰ��"<<(*p).cabinet_id_<<"�ſ�ݹ�ȡ��"<<endl;
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
    inf_express.open("Express.txt",ios::in);//��ȡ
    if(!inf_express)
	{//�ļ��Ƿ����
        cout<<"file isn't exists"<<endl;
    }
    else
	{
        if(inf_express.peek() == EOF)
		{ //�ļ��Ƿ��
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
    	cout<<"������ȡ����:";
    	cin>>key;
    	if(pickup(express_list,key)==1)
    	{
    		cout<<"1.����  2.����ȡ��";
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
			cout<<"δ��ѯ����ݱ�š�1.�������� 2.����";
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
    inf_admin.open("Admin.txt",ios::in);//��ȡ
    if(!inf_admin)
	{//�ļ��Ƿ����
        cout<<"file isn't exists"<<endl;
    }
    else
	{
        if(inf_admin.peek() == EOF)
		{ //�ļ��Ƿ��
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
    cout<<"���������Ա�˺ţ�";
	cin>>n;
	cout<<"���������룺";
	cin>>p;
	if(IsAdmin(admin_list,n,p)==1)
	{
		cout<<"1.��ݹ��� 2.��� 3.�鿴���п�� 4.ȡ�� 5.���������� 6.�˳�";
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
		cout<<"�˺�������� 1.�������� 2.���� ";
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
