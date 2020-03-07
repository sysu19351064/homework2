#include <stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class Identity{
public:
    Identity(long long int new_number,char new_name[32]):number_(new_number){//构造函数
        strcpy(name_, new_name);
        cout<<"constructor1"<<endl;
    }
    Identity(const Identity&ide){//复制构造函数
        number_=ide.number_;
        strcpy(name_,ide.name_);
        cout<<"copy constructor1"<<endl;
    }
    ~Identity(){//析构函数
        cout<<"distructor1"<<endl;
    }
    long long int getNUM(){//number成员的存取函数
        return number_;
    }
    string getNAME(){//name成员的存取函数
        return name_;
    }
private:
    long long int number_;
    char name_[32];
};
class Student{
public:
    Student();//默认构造函数
    Student(Identity new_id):id_(new_id){//只初始化id成员的构造函数
        cout<<"constructor2"<<endl;
    }
    Student(Identity new_id,string new_school):id_(new_id),school_(new_school){//id成员和school成员的构造函数
        cout<<"constructor2"<<endl;
    }
    Student(const Student&stu):id_(stu.id_){//复制构造函数
        school_=stu.school_;
        cout<<"copy constructor2"<<endl;
    }
    ~Student(){
        cout<<"distructor2"<<endl;
    }
    void getID(){//id成员的存取函数
        cout<<id_.getNUM()<<endl;
        cout<<id_.getNAME()<<endl;
    }
    string getSCH(){//school的存取函数
        return school_;
    }
private:
    Identity id_;
    string school_;
};
int main(){
    cout<<"Identity类函数使用例子"<<'\n';
    Identity stu1(362424200205281153,"lihongli");//构造函数
    Identity stu2(stu1);//复制构造函数
    cout<<stu1.getNUM()<<stu1.getNAME()<<endl;
    cout<<"Student类函数使用例子"<<'\n';
    Student stu3(stu1);//只初始化id成员的构造函数，调用了复制构造函数
    Student stu4(stu1,"SYSU");//id成员和school成员的构造函数，调用了复制构造函数
    Student stu5(stu4);//复制构造函数
    stu4.getID();
    cout<<stu4.getSCH()<<endl;
    cout<<"Makestudent函数使用例子"<<'\n';
    Student Makestudent(Identity id,string school);
    Makestudent(stu1, "SYSU").getID();
    cout<<Makestudent(stu1, "SYSU").getSCH()<<endl;
}
Student Makestudent(Identity id,string school){
    Student stu(id,school);
    return stu;
}
