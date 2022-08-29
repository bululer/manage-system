#ifndef LINK_H_
#define LINK_H_
#include<iostream>
#include<fstream>
typedef struct linklists{
    std::string name;
    std::string t_ID; 
    linklists *next;
}linklist;
class link_opt{
public:
    //构造函数
    link_opt(){
        head=initilize();
    }
    //析构函数
    ~link_opt();
    linklist* get(){
        return head;
    }
//插入学生信息
    bool add_link();
//修改
    bool remove_link();
    bool remove_file(const std::string name_front,const std::string name_later);
//删除 
    bool delete_link();
    bool delete_file(std::string name_or_id);
//显示
    bool show();
//查找
    linklist* name_find(const std::string a);
    linklist* ID_find(const std::string a);

private:
linklist *head;//头节点，不存储信息
linklist* initilize();//初始化链表

};

#endif