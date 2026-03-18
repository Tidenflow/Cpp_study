/*
   todos: 本demo是  const  关键字的一些基本知识
          但是距离完整的工业级  const  使用还差两个：
          （1）static const  静态常成员变量
          （2）const 成员函数与非 const 成员函数的逻辑复用
          后面有时间可以再看看
*/

#include <iostream>
#include <string>

class person {
public:
  std::string name = "jmh" ;
  int age = 20;
  const std::string email = "@123";
  mutable std::string  date = "aabnbcc";

    //3. const成员函数   ---->>       返回类型 函数名() const { ... }      const函数一般作为只读接口
    void display() const {
      // (1)不能修改成员变量
      // age = 10;      //报错  ： 不可修改的左值
      std::cout << "const 成员函数" << std::endl;

      // (2)尝试修改mutable变量
      std::cout << "即将修改" << this->date << std::endl;
      date = "eeffgg";
      std::cout << "修改完成" <<this->date << std::endl;
    }

    //4.内部成员函数尝试修改一下内部成员变量
    void changeInfo() {
      age = 1;
      // email = "@test";    //报错
    }

};

void printPersonInfo(const person& p) {
  std::cout << "打印对象信息" << p.name << p.age << std::endl;
  // p.name = "aaa";   报错 去掉const就可以了
}

//使用指针  这个和const没啥关系纯粹是用一下指针
void printPersonInfoPoi(const person* p) {
  std::cout << "打印对象信息" << p->name << p->age << std::endl;
}

//使用指针  这个和const没啥关系纯粹是用一下指针
// void printPersonInfoPoi(const person* p) {
//   std::cout << "打印对象信息" << p->name << p->age << std::endl;
// }

int main() 
{
    //1.表达式必须是可修改的左值
   const int max_speed = 120;
    //max_speed = 150;         会报错

    //2.修饰指针
    // (1)  const在 * 前面         保护对象中的内容
    // 禁忌：不能修改p1的成员变量
    // 灵活：可与修改p1指针的指向
    const person* p1 = new person();

    // (2)  const在 * 后面         保护指针变量存储的地址
    // 禁忌：p2不能再指向别处，只能存这一个地址
    // 灵活：可以修改p2指向的对象的内容
    person* const p2 = new person();
    
    std::cout << "p1  " << p1->name << "and" << p1->age << std::endl;
    std::cout << "p2  " << p2->name << "and" << p2->age << std::endl;

    // 尝试修改对象内容   
    // p1->age = 100;   报错：左值应该是可修改的
    p2->age = 100;
    std::cout << "修改对象内容" << std::endl;
    std::cout << "p1  " << p1->name << "and" << p1->age << std::endl;
    std::cout << "p2  " << p2->name << "and" << p2->age << std::endl;
    

    //尝试切换指针
    person* p3 = new person();
    p3->age = 10;

    p1 = p3;
    // p2 = p3;   报错：左值应该是可修改的    
    std::cout << "尝试切换指针" << std::endl;
    std::cout << "p1  " << p1->name << "and" << p1->age << std::endl;
    std::cout << "p2  " << p2->name << "and" << p2->age << std::endl;

    // 调用一下函数
    std::cout << "调用打印函数" << std::endl;
    person p4;
    printPersonInfo(*p1);
    printPersonInfo(p4);
    printPersonInfoPoi(p2);
    p1->display();
    p2->display();

    return 0;
}