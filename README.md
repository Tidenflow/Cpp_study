# Cpp_study ⚙️

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=600&size=28&pause=2000&color=00599C&center=true&vCenter=true&width=600&lines=Hardcore+Engineering+with+C%2B%2B;Memory+is+the+canvas+of+code;Life+is+experience" alt="Typing SVG" />
</p>

> "Life is experience, and C++ is the ultimate control over that experience."

---

## 📅 深度学习路径 (Syllabus)

### 1️⃣ 现代 C++ 进阶 (Modern C++)
- [ ] **内存管理**：智能指针源码分析 (`shared_ptr`, `unique_ptr`)、RAII 机制
- [ ] **右值引用与性能**：移动语义 (`std::move`)、完美转发 (`std::forward`)
- [ ] **模板元编程**：SFINAE、`std::enable_if`、模版特化

### 2️⃣ STL 深度剖析 (STL Internals)
- [ ] **容器源码**：`vector` 的扩容机制、`list` 的内存分布、`unordered_map` 哈希冲突处理
- [ ] **迭代器与适配器**：理解迭代器失效的本质与底层实现

### 3️⃣ 并发与系统编程 (System & Concurrency)
- [ ] **多线程核心**：`std::thread`, `mutex`, `condition_variable`
- [ ] **高性能线程池**：基于任务队列与工作线程的 **Thread Pool** 实现
- [ ] **无锁编程基础**：原子操作 `std::atomic` 与内存屏障 (Memory Barrier)

### 4️⃣ 工程化实践 (Industrial Engineering)
- [ ] **构建系统**：CMake 复杂项目多级目录管理与第三方库链接
- [ ] **设计模式**：单例、工厂、观察者模式在 C++ 中的落地
- [ ] **性能分析**：使用 Valgrind 检测内存泄漏，GDB 调试实战

---

## 📂 详细目录结构 (Project Architecture)

```text
Cpp_study/
├── 00-Basics/                     # 阶段零：工程基石 (补齐底层认知)
│   ├── ConstSystem/               # Const 正确性专题
│   │   ├── ConstPtr.cpp           # 常量指针与指针常量深度对比
│   │   └── ConstMember.cpp        # const 成员函数与 mutable 语义实验
│   ├── ReferenceSemantic/         # 引用与传递专题
│   │   ├── PassByValue_Ref.cpp    # 传值、传引用、传指针性能压测对比
│   │   └── ExplicitConvert.cpp    # explicit 构造函数防止隐式转换陷阱
│   ├── ObjectModel/               # 对象模型与生命周期
│   │   ├── DeepCopy.cpp           # 手写 String 类演示深拷贝与 Double Free
│   │   ├── CopyVsAssignment.cpp   # 拷贝构造与赋值运算符执行时机拆解
│   │   └── DtorChain.cpp          # 多重继承下的析构顺序探究
│   └── MemoryFoundations/         # 内存布局基础
│       ├── EmptyClassSize.cpp     # 空类、虚函数类、对齐规则 sizeof 实验
│       └── StaticLayout.cpp       # 静态变量在 Data/BSS 段的分布验证
├── 01-Modern-CPP/                 # 阶段一：语言现代性
│   ├── SmartPointers/             # 智能指针专题
│   │   ├── RefCount.hpp           # 原子计数器封装
│   │   ├── SharedPtr.hpp          # 模拟实现 shared_ptr
│   │   └── UniquePtr.hpp          # 模拟实现 unique_ptr (禁用拷贝构造)
│   ├── MoveSemantics/             # 移动语义与性能
│   │   ├── StringMove_Bench.cpp   # 移动构造 vs 拷贝构造性能对比测试
│   │   └── PerfectForwarding.cpp  # std::forward 解决参数透传问题
│   └── TemplateMagic/             # 模板元编程
│       ├── SFINAE_Test.cpp        # 探究 std::enable_if 与类型推导
│       └── TypeTraits.hpp         # 手写 is_pointer 等类型萃取工具
├── 02-STL-Analysis/               # 阶段二：STL 源码级拆解
│   ├── MyVector/                  # 动态数组
│   │   ├── VectorImpl.hpp         # 模拟实现 (迭代器、扩容机制、push_back)
│   │   └── Iterator_Traits.hpp    # 迭代器特征萃取实现
│   ├── MyHashMap/                 # 哈希表
│   │   ├── HashFunctions.hpp      # 各类常用字符串哈希算法实现
│   │   └── ChainingHashMap.hpp    # 链地址法解决冲突
│   └── MyList/                    # 双向链表
│       └── ListImpl.hpp           # 内存布局与双向迭代器实现
├── 03-Memory-Management/          # 阶段三：内存管理精髓
│   ├── Allocators/                # 配置器
│   │   └── SimpleAlloc.hpp        # 基于 operator new 的简单配置器
│   ├── MemoryPool/                # 【核心】内存池
│   │   ├── FixedSizePool.hpp      # 固定大小对象池 (FreeList 机制)
│   │   └── SlabAllocator.hpp      # 探究 Slab 分配算法 (选做)
│   └── RAII-Protocols/            # 资源管理协议
│       ├── FileDescriptor.hpp     # 文件描述符的 RAII 封装
│       └── LockGuard.hpp          # 互斥锁的 RAII 封装思路
├── 04-Concurrency/                # 阶段四：并发编程 (硬核区)
│   ├── ThreadPool/                # 通用线程池
│   │   ├── SafeQueue.hpp          # 线程安全任务队列 (condition_variable)
│   │   └── ThreadPool.hpp         # 工作线程调度与 std::future 任务提交
│   ├── SyncPrimitives/            # 同步原语练习
│   │   ├── ProducerConsumer.cpp   # 经典生产者消费者模型
│   │   └── DeadlockDemo.cpp       # 死锁复现与 std::lock 规避方案
│   └── Atomic-LockFree/           # 无锁编程
│       ├── AtomicCounter.cpp      # std::atomic 性能压测
│       └── LockFreeStack.hpp      # 基于 CAS 操作的无锁栈
├── 05-Networking-IO/              # 阶段五：网络与系统 IO
│   ├── SocketWrapper/             # 原生 Socket API 封装
│   ├── Select-Poll-Epoll/         # 三种多路复用模型对比实验
│   └── Reactor-Pattern/           # 高性能 Reactor 架构
│       ├── EventLoop.cpp          # 事件循环逻辑
│       └── EpollDemultiplexer.cpp # 基于 epoll 的分发器
├── 06-Design-Patterns/            # 阶段六：软件设计模式 (C++实现)
│   ├── Singleton/                 # 线程安全的单例 (Meyers Singleton)
│   ├── Observer/                  # 观察者模式与 std::function 回调
│   └── Decorator/                 # 装饰器模式练习
├── scripts/                       # 自动化脚本
│   ├── build.sh                   # 一键 CMake 编译
│   └── memcheck.sh                # 调用 Valgrind 进行内存泄漏扫描
├── CMakeLists.txt                 # 顶层 CMake 配置
└── README.md                      # 导航与心得
