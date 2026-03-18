#include <iostream>
#include <string>
// static 是 C++ 中非常常用且容易混淆的关键字，
// 核心作用是改变变量/函数的 “作用域” 和 “生命周期”

/*
=======================================================================================
========================================1.作用域========================================
1. 全局作用域下：static 修饰全局变量/函数 —— 限制作用域
(1)默认情况：全局变量 / 函数的作用域是「整个程序」（多个源文件都能访问）；
(2)加 static 后：
作用域被限制在「当前源文件」（其他源文件看不到），避免命名冲突。

// file1.cpp
#include <iostream>
// 全局变量：默认整个程序可见
int global_num = 10;
// static全局变量：仅file1.cpp可见
static int static_global_num = 20;

// 全局函数：默认整个程序可见
void global_func() {
    std::cout << "全局函数" << std::endl;
}

// static全局函数：仅file1.cpp可见
static void static_global_func() {
    std::cout << "static全局函数" << std::endl;
}

// file2.cpp
#include <iostream>
// 能访问全局变量global_num（跨文件可见）
extern int global_num;
// 无法访问static_global_num（被static限制，编译报错）
// extern int static_global_num; 

// 能访问全局函数global_func
extern void global_func();
// 无法访问static_global_func（编译报错）
// extern void static_global_func();

int main() {
    std::cout << global_num << std::endl; // ? 正常输出10
    global_func(); // ? 正常执行
    return 0;
}


核心用途：工业级开发中，多文件项目里用static修饰全局变量 / 函数，
避免不同文件的同名变量 / 函数冲突（比如多个文件都有init()函数，加 static 就不会冲突）。
*/


/*
=========================================================================================
========================================2.生命周期========================================
2. 局部作用域下：static 修饰局部变量 —— 延长生命周期
(1)默认情况：局部变量（函数内 / 代码块内）的生命周期是「函数执行期间」，
每次调用函数都会重新创建、初始化，执行完销毁；
(2)加 static 后：
生命周期：程序启动时创建，程序结束时销毁（只初始化 1 次）；
作用域：仍限制在当前函数 / 代码块内（只能在函数内访问）。

*/

void test_static() {
    // 普通局部变量：每次调用都重新初始化（栈上）
    int normal_num = 0;
     // static局部变量：仅初始化1次（全局/静态存储区）
    static int static_num = 0;

    normal_num++;
    static_num++;

    std::cout << "普通变量：" << normal_num << " | static变量：" << static_num << std::endl;
}




/*

工业级用途：
统计函数被调用的次数；
实现 “单例模式”（一个类只能创建一个对象）；
缓存临时数据（避免每次调用函数都重新计算）。

*/


/*
================================================================================
====================3.static 修饰成员变量 / 成员函数 —— 类级共享==================

(3.1)static 成员变量 —— 所有对象共享的变量   可修改！！
默认情况：类的普通成员变量，每个对象都有一份独立的拷贝（比如每个person对象都有自己的age）；
加 static 后：
属于「类」，而非「对象」：所有对象共享这一个变量，修改一个对象的 static 成员，所有对象都能看到；
必须类内声明，类外初始化（C++17 前）；
访问方式：类名::变量名（推荐） 或 对象.变量名。
*/
class Person {
public:
    std::string name; // 普通成员：每个对象独有  在这里即使  name 初始化为 "hah" 外部也可以改
    static int count; // static成员：所有对象共享（统计Person对象的数量）

    // 构造函数：创建对象时count+1
    Person(std::string n) : name(n) {
        count++;
    }

    // static成员函数：只能访问static成员
    static void show_count() {
        std::cout << "当前Person对象总数：" << count << std::endl;
        // cout << name << endl; // 报错：不能访问普通成员变量（无this指针）
    }

    //static const 成员变量
    // C++17前：类内声明，类外初始化
    static const int MAX_AGE = 120; // 内置类型可类内声明时赋初值（但仍需类外初始化）
    static const std::string DEFAULT_GROUP;
    //C++ 11+ 推荐使用constexpr
    static constexpr int time = 500;
    static void change_time() /*const*/ {  //此处要是加上个const则报错 静态成员函数上不允许使用类型限定符
            // time++;    //报错  ：表达式必须是可修改的左值
            std::cout << "Time" << time << std::endl;
    }

    // C++17后：加inline，直接类内初始化（无需类外）
    // inline static const double PI = 3.1415926;

};

// static成员变量：类外初始化（必须！C++17前）
int Person::count = 0;

/*
(3.2) static 成员函数 —— 类级函数，无 this 指针
属于「类」，而非「对象」：可以直接通过类名::函数名调用，无需创建对象；
无this指针：因此不能访问类的普通成员变量 / 函数（因为普通成员依赖对象），只能访问 static 成员变量 / 函数；
不能被const修饰（const修饰的是 this 指针，static 函数没有 this）
*/

/*
(3.3) 类中 static const （静态常成员变量）—— 类级常量   不可修改！！
      没有static const 函数
*/







int main() {
    //对应第二部分
    std::cout << "第1次调用：\n";
    test_static(); // 输出：普通变量：1 | static变量：1
    std::cout << "第2次调用：\n";
    test_static(); // 输出：普通变量：1 | static变量：2
    std::cout << "第3次调用：\n";
    test_static(); // 输出：普通变量：1 | static变量：3



    //对应第三部分
    // 访问static成员：类名直接访问（还没创建对象）
    std::cout << "创建对象前，count：" << Person::count << std::endl; // 输出0

    Person p1("张三");
    std::cout << "p1.name：" << p1.name << " | count：" << Person::count << std::endl; // 输出1
    Person p2("李四");
    std::cout << "p2.name：" << p2.name << " | count：" << Person::count << std::endl; // 输出2

    // 也可以通过对象访问static成员（不推荐）
    std::cout << "p1.count：" << p1.count << std::endl; // 输出2

    // 3.2示例
    Person::show_count();
    p1.show_count();

    //3.3示例
    std::cout << "time: " << Person::time << std::endl;

    return 0;
}