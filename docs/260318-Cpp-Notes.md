# C++ 关键字学习总结

> 学习日期：2026年3月18日  
> 文件来源：const.cpp、static.cpp

---

## 一、const 关键字

### 1. const 修饰基本变量

```cpp
const int max_speed = 120;
// max_speed = 150; // 报错：不可修改的左值
```

**要点**：声明时必须初始化，修饰后变量不可修改。

---

### 2. const 修饰指针

| 形式 | 作用 | 可修改指针 | 可修改对象内容 |
|------|------|-----------|---------------|
| `const T* p` | 保护对象 | ✅ | ❌ |
| `T* const p` | 保护指针 | ❌ | ✅ |
| `const T* const p` | 两者都保护 | ❌ | ❌ |

```cpp
const person* p1 = new person();  // 指向常对象的指针
// p1->age = 100; // 报错：不可修改

person* const p2 = new person();  // 常指针
// p2 = p3; // 报错：不可修改指针指向
```

**记忆口诀**：const 在 `*` 前面保护"它指向的东西"，const 在 `*` 后面保护"它自己"。

---

### 3. const 成员函数

```cpp
void display() const {
    // age = 10; // 报错：不可修改成员变量
}
```

**特点**：
- 承诺不修改对象状态，作为只读接口
- 不能修改普通成员变量

---

### 4. mutable 关键字

在 const 成员函数中，某些特殊情况需要修改变量，使用 `mutable`：

```cpp
mutable std::string date = "aabnbcc";

void display() const {
    date = "eeffgg"; // 可以修改
}
```

---

### 5. const 引用参数

```cpp
void printPersonInfo(const person& p) {
    // p.name = "aaa"; // 报错：防止意外修改
}
```

**优点**：保护传入对象，提高接口安全性。

---

## 二、static 关键字

### 1. 全局范围：内部链接

```cpp
static int static_global_num = 20;        // 仅当前文件可见
static void static_global_func() { }      // 仅当前文件可见
```

**作用**：将全局符号限制在当前翻译单元，避免命名冲突。

---

### 2. 局部范围：延长生命周期

```cpp
void test_static() {
    int normal_num = 0;           // 每次调用重新初始化
    static int static_num = 0;    // 只初始化一次，程序结束才销毁
    
    normal_num++;
    static_num++;
}
```

**调用结果**：
- 第1次调用：normal_num=1, static_num=1
- 第2次调用：normal_num=1, static_num=2
- 第3次调用：normal_num=1, static_num=3

---

### 3. 类成员

#### 3.1 static 成员变量

```cpp
class Person {
    static int count;  // 所有对象共享
};

int Person::count = 0;  // 类外必须初始化（C++17前）
```

**访问方式**：`Person::count` 或 `对象.count`

**应用场景**：计数器、单例模式、配置参数共享。

#### 3.2 static 成员函数

```cpp
static void show_count() {
    cout << count << endl;  // 只能访问 static 成员
}
```

**特点**：
- 属于类而非对象，可通过 `类名::` 直接调用
- 没有 this 指针，不能访问非 static 成员

#### 3.3 static const / constexpr 成员变量

```cpp
class Person {
    static const int MAX_AGE = 120;        // 整型可在类内初始化
    static constexpr int time = 500;       // C++11+ 推荐
    static const std::string DEFAULT_GROUP; // 需类外初始化
};
```

**注意**：static 成员函数不能加 const（没有 this 指针）。

---

## 三、对比总结

| 场景 | const | static |
|------|-------|--------|
| 变量 | 不可修改 | 生命周期/作用域控制 |
| 指针 | 保护指针或对象 | - |
| 成员函数 | 只读接口 | 无 this 指针 |
| 成员变量 | - | 类共享 |

---

## 四、待深入学习

- [ ] static const 静态常成员变量
- [ ] const 成员函数与非 const 成员函数的逻辑复用
