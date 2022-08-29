#include"teacher.h"
void teacher::menu_t(){
    std::cout<<"-------------------------------"<<std::endl;
    std::cout<<"--------1.查看班级学生-----------"<<std::endl;
    std::cout<<"--------2.搜索------------------"<<std::endl;
    std::cout<<"--------3.增加新学生信息----------"<<std::endl;
    std::cout<<"--------4.删除学生---------------"<<std::endl;
    std::cout<<"--------5.修改学生信息------------"<<std::endl;
    std::cout<<"--------6.输出全班学生成绩---------"<<std::endl;
    std::cout<<"--------0.退出-------------------"<<std::endl;
    std::cout<<"--------------------------------"<<std::endl;
}
void teacher::emmm(){
    while(1){
        menu_t();
        int select=999;
        std::cout<<"请输入 ";
        std::cin>>select;
        switch(select){
            case 1:
                show_t();
            break;
            case 2:
                search_t();
            break;
            case 3:
                add_t();
            break;
            case 4:
                delete_t();
            break;
            case 5:
                revamp_t();
            break;
            case 6:
            
            case 0:
            return;
            break;
            default:
            break;
        }
        std::cout<<"按任意键继续"<<std::endl;
        std::cin.get();
      
    }
}
void teacher::show_t(){
    link_opt::show();
}

bool teacher::search_t(){
    linklist *p;
    std::cout<<"输入要查找的名字或学号";
    std::string name_id;
    std::cin>>name_id;
    if(name_find(name_id)==nullptr&&ID_find(name_id)==nullptr)
    {
        std::cout<<"没有查询到学生信息"<<std::endl;
        return false;
    }
    if(name_find(name_id)==nullptr){
        p=ID_find(name_id);
    }
    else{
        p=name_find(name_id);
    }
    std::cout<<p->name<<std::endl;
    std::cout<<p->t_ID<<std::endl;
    return true;
}
 void teacher::add_t(){
    add_link();
 }

 void teacher::delete_t(){
    delete_link();
 }
 void teacher::revamp_t(){
    remove_link();
 }
 