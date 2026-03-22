#include <iostream>
#include <string>

// 1. 传值、传指针、传引用的对比函数

//(1)传值：函数内创建副本，不影响原变量
void passByValue(int num) {
    num = 100;
    std::cout << "传值函数内部的值：" << num << "\n";
}

//(2)传指针：通过地址修改原变量
void passByPointer(int* numPtr) {
    if(numPtr != nullptr) { // 空指针检查，避免崩溃
        *numPtr = 200;  // 解引用指针，修改原变量值
        std::cout << "传指针函数内部的值：" << *numPtr << "\n";
    }
}

//(3)传引用： 直接操作原变量（更安全的指针）
void passByReference(int& numRef) {
    numRef = 300;
    std::cout << "传引用函数内部的值：" << numRef << "\n";
}

// 2.const指针与引用的演示函数
void constPointerAndReference() {
    int a = 10, b = 20;

    //const指针的几种形式
    //情况1：指向const的指针（指针指向的值不可修改，但指针本身可以指向其他地址）
    const int* ptr1 = &a;
    std::cout << "\n指向const的指针ptr1指向的值为" << *ptr1 << "\n";
    // *ptr1 = 15;   //报错 ： 表达式必须是可修改的左值
    //但是下面这个
    // a = 15;    //不报错，下面输出15 因为const 修饰的是 *ptr（指针指向的值），而不是变量 a 本身
    // 禁止的是 *ptr = xxx 这种通过指针修改值的行为，不禁止 a = xxx 这种直接修改原变量的行为
    // std::cout << a << std::endl;  
    ptr1 = &b;
    std::cout << "ptr1 指向b后的值: " << *ptr1 << std::endl;

    // 情况2: const指针（指针本身不可修改，但指向的值可修改）
    int* const ptr2 = &a;
    std::cout << "\nconst指针 ptr2 指向的值: " << *ptr2 << std::endl;
    *ptr2 = 15; // 合法：可以修改指向的值
    std::cout << "修改ptr2指向的值后: " << *ptr2 << std::endl;
    // ptr2 = &b; // 错误：const指针本身不能指向其他地址

    // 情况3: 指向const的const指针（指针和指向的值都不可修改）
    const int* const ptr3 = &a;
    std::cout << "\n指向const的const指针 ptr3 指向的值: " << *ptr3 << std::endl;
    // *ptr3 = 25; // 错误：不能修改指向的值
    // ptr3 = &b;  // 错误：不能修改指针本身

    // const 引用（常用，避免拷贝且防止修改）
    const int& ref1 = a;
    std::cout << "\nconst引用 ref1 的值: " << ref1 << std::endl;
    // ref1 = 30; // 错误：不能修改const引用的值

    //这里的 const int 和这个 const int&有什么区别？？
    const int c = a;      // ===>>  只读变量（独立内存）	占用独立内存，值不可改
    const int& ref = a;   // ===>>  普通变量的只读别名	不占独立内存，指向 a 的内存

}

int main() {
    // ========== 1. 指针基本语法演示 ==========
    std::cout << "===== 指针基本语法 =====" << std::endl;
    int x = 42;
    int* ptr = &x; // & 取地址符：ptr存储x的内存地址

    std::cout << "变量x的值: " << x << std::endl;
    std::cout << "x的地址: " << &x << std::endl;
    std::cout << "指针ptr存储的地址: " << ptr << std::endl;
    std::cout << "解引用ptr获取值: " << *ptr << std::endl; // * 解引用符：通过地址访问值

    // 修改指针指向的值
    *ptr = 99;
    std::cout << "修改后x的值: " << x << std::endl;

    // ========== 2. 指针 vs 引用 对比 ==========
    std::cout << "\n===== 指针 vs 引用 =====" << std::endl;
    int y = 10;
    int* p = &y;    // 指针：可以为空、可以重定向
    int& r = y;     // 引用：必须初始化、不能重定向（是变量的别名）

    std::cout << "原y值: " << y << std::endl;
    *p = 20; // 指针修改值
    std::cout << "指针修改后y值: " << y << std::endl;
    r = 30;  // 引用修改值（直接操作原变量）
    std::cout << "引用修改后y值: " << y << std::endl;

    // 指针可以重定向
    int z = 50;
    p = &z;
    std::cout << "指针重定向到z后的值: " << *p << std::endl;
    r = z; // 这不是重定向，只是给y赋值z的值
    std::cout << "引用赋值z后y的值: " << y << std::endl;

    // ========== 3. 传值 vs 传指针 vs 传引用 ==========
    std::cout << "\n===== 传值 vs 传指针 vs 传引用 =====" << std::endl;
    int num = 10;
    std::cout << "调用函数前num的值: " << num << std::endl;

    passByValue(num);
    std::cout << "传值调用后num的值: " << num << std::endl; // 无变化

    passByPointer(&num);
    std::cout << "传指针调用后num的值: " << num << std::endl; // 被修改

    passByReference(num);
    std::cout << "传引用调用后num的值: " << num << std::endl; // 被修改

    // ========== 4. const 指针与引用 ==========
    std::cout << "\n===== const 指针与引用 =====" << std::endl;
    constPointerAndReference();

    return 0;
}