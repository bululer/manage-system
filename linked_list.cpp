#include"linked_list.h"

linklist* link_opt::initilize(){
    linklist *head=new linklist;
    head->next=nullptr;
    std::ifstream ifs;
    ifs.open("information.txt",std::ios::in);
    if(ifs.fail()){
        std::ofstream ofs;
        ofs.open("information.txt",std::ios::out);
        ofs.close();

    }
    std::string name,s_id;
    //每次读取一行
    while(ifs>>name>>s_id){
        std::cout<<"运行到这了";
        linklist *temp=new linklist;
        temp->name=name;
        temp->t_ID=s_id;
        //使用头插法
        if(head->next==nullptr){
            head->next=temp;
            temp->next=nullptr;
        }
        else{
            linklist *s=head->next;
            head->next=temp;
            temp->next=s;
        }
        
    }
    ifs.close();
    return head;
}

bool link_opt::add_link(){
    std::string name,Id;
    std::cout<<"请输入姓名";
    std::cin>>name;
    std::cout<<"请输入学号";
    std::cin>>Id;
    if(name_find(name)!=nullptr||ID_find(Id)!=nullptr){
        std::cout<<"此人已存在";
        return false;
    }
    std::ofstream ofs;
    ofs.open("information.txt",std::ios::app);
    if(ofs.fail()) return false;
    ofs<<name<<' '<<Id;
    
     linklist *temp=new linklist;
        temp->name=name;
        temp->t_ID=Id;
    if(head->next==nullptr){
       head->next=temp;
    }
    else{
        linklist *s=head->next;
            head->next=temp;
            temp->next=s;
    }
    ofs.close();
    return true;

}


bool link_opt::show(){
     linklist *f=head;
     if(f->next==nullptr)
     return false ;
    f=f->next;
   while(f->next!=nullptr){
    std::cout<<f->name<<' '<<f->t_ID<<std::endl;
    f=f->next;
   }
   std::cout<<f->name<<' '<<f->t_ID<<std::endl;
   return true;
}

linklist* link_opt::name_find(const std::string a){
    if(head->next==nullptr){
        
        return nullptr;
    }
    linklist *f=head;
    f=f->next;
    while(f->next!=nullptr){
    if(f->name==a)
    return f;
    f=f->next;
    }
    if(f->name==a)
    return f;
    return nullptr;
}
linklist* link_opt::ID_find(const std::string a){
       if(head->next==nullptr){
        
        return nullptr;
    }
    linklist *f=head;
    f=f->next;
    while(f->next!=nullptr){
    if(f->t_ID==a)
    return f;
    f=f->next;
    }
    if(f->t_ID==a)
    return f;
    return nullptr;
}

bool link_opt::remove_link(){
    std::string m_name;
    std::string m_id;
    std::ofstream ofs;
    
    int a=0;//选择变量
    std::cout<<"输入要修改人的姓名"<<std::endl;
    std::string name1;
    std::cin>>name1;
    linklist* pt;
    pt=name_find(name1);
    if(pt==nullptr)
    return false;
    while(1)
   {
      std::cout<<"-----------------------"<<std::endl;
      std::cout<<"姓名"<<pt->name<<"\t"<<std::endl;
      std::cout<<"学号"<<pt->t_ID<<"\t"<<std::endl;
      std::cout<<"                       "<<std::endl;
      std::cout<<"1.修改名字     2.修改学号 "<<std::endl;
      std::cout<<"      3.退出             "<<std::endl;
      std::cout<<"-----------------------"<<std::endl;
      std::cin>>a;
      switch(a){
        case 1:
        std::cout<<"请输入名字"<<std::endl;
        std::cin>>m_name;
        pt->name=m_name;
        remove_file(name1,m_name);
        break;
        case 2:
        std::cout<<"请输入学号"<<std::endl;
        std::cin>>m_id;
        pt->t_ID=m_id;
        remove_file(name1,m_name);
        break;
        default:
        return true;
        break;

    }
    system("cls");
    }
}

 bool link_opt::remove_file(const std::string name_front,const std::string name_later){
        std::ifstream ifs;
        std::ofstream ofs;
        std::string m_name;
        std::string m_id;
        ifs.open("information.txt",std::ios::in);
        ofs.open("information_temp.txt",std::ios::out);
        while(ifs>>m_name&&ifs>>m_id){
           if(m_name==name_front){
            m_name=name_later;
           }
           else if(m_id==name_front){
            m_id=name_later;
           }
            ofs<<m_name<<" "<<m_id<<std::endl;
        }
        ifs.close();
        ofs.close();
        std::ifstream iifs;
        std::ofstream oofs;
        oofs.open("information.txt",std::ios::out);
        iifs.open("information_temp.txt",std::ios::in);
        while(iifs>>m_name&&iifs>>m_id){
            
            oofs<<m_name<<" "<<m_id<<std::endl;
        }
        iifs.close();
        oofs.close();
        return true;
 }

 bool link_opt::delete_file(std::string name_or_id){
        std::ifstream ifs;
        std::ofstream ofs;
        std::string m_name;
        std::string m_id;
        ifs.open("information.txt",std::ios::in);
        ofs.open("information_temp.txt",std::ios::out);
        while(ifs>>m_name&&ifs>>m_id){
            if(m_name==name_or_id||m_id==name_or_id)
                continue;
            ofs<<m_name<<" "<<m_id<<std::endl;
        }
       
        ifs.close();
        ofs.close();
        std::ifstream iifs;
        std::ofstream oofs;
        oofs.open("information.txt",std::ios::out);
        iifs.open("information_temp.txt",std::ios::in);
        while(iifs>>m_name&&iifs>>m_id){
            
            ofs<<m_name<<" "<<m_id<<std::endl;
        }
        iifs.close();
        oofs.close();
        return true;
 }
 bool link_opt::delete_link(){
    std::cout<<"请输入要删除的人的姓名或学号";
    std::string nnm_id;
    std::cin>>nnm_id;
    linklist *a;//保存找到的信息
    linklist *b;
    if(name_find(nnm_id)!=nullptr){
        a=name_find(nnm_id);
    }
    else if(ID_find(nnm_id)!=nullptr){
        a=ID_find(nnm_id);
    }
    else{
        return false;
    }
      std::cout<<"-----------------------"<<std::endl;
      std::cout<<"姓名"<<a->name<<"\t"<<std::endl;
      std::cout<<"学号"<<a->t_ID<<"\t"<<std::endl;
      std::cout<<"-----------------------"<<std::endl;
      std::cout<<"确认要删除吗";
      std::cout<<"1.确认     2.取消 "<<std::endl;
      int select=0;//
      std::cin>>select;
      switch(select){
        case 1: if(a->next==nullptr)
                {
                    
                }
               a->name=a->next->name;   
               a->t_ID=a->next->t_ID;
               b=a->next;
               a->next=a->next->next;
                free(b);
                delete_file(nnm_id);
                return true;
        break;
        case 2:
                return false;
        break;
        default:
            return false;
        break;
    }
    return false;
 }
 link_opt::~link_opt(){
    if(head->next!=nullptr){
        head=head->next;
        linklist *temp;
        while(head->next!=nullptr){
            temp=head;
            head=head->next;
            free(temp);
        }
    }
 }