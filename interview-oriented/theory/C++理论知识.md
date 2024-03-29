你现在是一个企业级C++开发人员，技术能力超强。可以为我指定一系列的问题来让我逐渐掌握：基础知识和技能，网络编程知识，多线程并发编程能力，高级主题，在基础知识和技能模块，可以分得更细一点，比如C++基础语法与概念，标准模版库(STL)，内存管理。我需要从理论和实践两个方面掌握哪些东西呢？请以常见的问题或者题目的方式对我进行能力的考察。
你每天可以给我指定涵盖这些知识点的不同的**20道题目**。
这是我的回答，如果有不正确或者不全面的地方，请以正确的理解为我做出这个知识点全方面的解释。
这些题目你之前都出过，我需要不一样的题目，涵盖不同的知识点。
你现在的回答都太简单了，请稍微介绍得详细一点，把这道问题涵盖的知识点全部给我扩展清楚。并且写出对应的代码来辅助我进行理解

## C++基础语法与概念
1. 解释C++中的基本类型有哪些？以及大小？ 
   1. 整数：short，int，long，longlong
   2. 浮点数：float，double，long double
   3. 字符：char，wchar_t，char16_t，chat32_t
   4. 布尔：bool
   5. 大小一般不同的编译器和系统都不一样哇，不会去记它，需要的时候就用sizeof关键字看一看
   
2. 描述C++中指针与引用的区别？  
   1. 我：指针就是变量的地址，可以指向任意变量；而引用就是变量的别名，只能代表一个变量的地址
   2. 指针和引用都是用于**间接访问其他变量的机制**
   3. 指针是变量，他的值是另一个变量的地址。可以指向空地址nullprt。引用操作符 * 访问指针指向变量的值，地址操作符 & :获取一个变量的地址
   4. 引用必须初始化，且不能改变，不能为空值
   5. 引用可以直接使用；引用常用于函数参数传递

3. 解释什么是面向对象编程（OOP）以及C++是如何实现OOP的（类、封装、继承、多态）？  
   1. 我：面向对象编程就是把一个对象的数据和对数据的操作封装在一起。
   2. 对象是数据(属性)和能够对数据进行操作的方法(函数)。目的是增强代码的重用性、可读行和可维护性。
   3. 封装：通过定义类来定义一组属性和方法，对于该类创建的对象来说是共有的。通过访问修饰符(public,protected,private)，定义类成员的访问级别
   4. 继承：在定义类的时候通过: 访问修饰符 基类名称来实现。派生类继承了基类的所有公有和保护属性与方法，同时还可以添加新的属性和方法或覆盖（重定义）现有的方法。
   5. 多态：允许一个接口来表示不同的数据类型或允许方法进行不同实现的能力。多态通过虚函数(virtual,override)来实现：运行时多态：子类重写基类中的虚函数，可以通过基类的指针或引用调用到子类的方法。
      1. 编译时多态：函数重载，模版
      2. 运行时多态：virtual override

4. 解释C++中的变量作用域规则？  
   1. 我：首先变量分为全局变量和局部变量。全局变量就是在程序的整个运行周期都可以被调用；而局部变量只能在创建这个变量的作用域中被调用。
   2. 生命周期和可见性范围。局部变量、全局变量、静态局部变量、静态全局变量、命名空间作用域的变量。

5. 解释什么是左值和右值？
   1. 我：左值就是对内存空间的指定，比如变量名、常量名之类的；右值就是指定放在内存中的内容。
   2. 左值：表达式结束之后仍然存在的对象或者函数的引用，在内存中有确定的存储位置。&运算符可以取到左值的内存地址
   3. 右值：表达式结束时就不再存在的临时对象的引用，不具有持久的地址，在表达式求值完毕后就被销毁。
   4. 右值引用 && 和移动语义。应该暂时用不上？

6. 什么是构造函数和析构函数？它们如何工作？  
   1. 我：构造函数就是没有类型，函数名与类名一样，用于在创造对象时分配内存空间的函数；析构函数同样如此，但是用于销毁对象时回收内存空间。
   2. 构造函数：是初始化对象的成员变量，内存分配在构造函数调用之前，构造函数负责这块内存的初始化。一个类可以有多个构造函数。
   3. 析构函数：释放对象在生命周期内申请的资源，如释放动态分配的内存、关闭文件句柄等。一个类只能有一个析构函数。

7. 如何在C++中实现接口（抽象类）？  
   1. 我：在继承类的时候加上virtual关键字
   2. 接口：包含纯虚函数的抽象类。纯虚函数通过在函数声明的末尾添加=0来指定。抽象类不能被实例化，只能通过继承来实现接口。

8. 什么是命名空间，它如何解决名称冲突？
   1. 我：就是namespace，相当于声明静态全局变量？
   2. 命名空间是一种容器(应该是编译器来实现的)，的是解决复杂项目中可能出现的名称冲突问题。知道怎么去定义一个命名空间，已经怎么去使用命名空间就好。为什么一般写的时候还是不要using namespace，因为这样就还是会在一个代码文件中产生冲突。

9. 描述C++中的异常处理和它的用法？
   1. 我：不知道
   2. 一种错误处理机制，遇到错误时执行错误处理代码。
   3. 异常处理的基本概念：抛出异常，捕获异常，try catch块

10. 解释运算符重载及其使用场景?
   1. 允许开发者为用户定义的类型（类或结构体）重新定义运算符。
   2. 通过定义一个特殊的成员函数或全局函数来实现。由关键字operator后面要重载的运算符符号组成。比如，operator+
    
11. 什么是模板编程？举例说明函数模板和类模板。
   1. 让函数或类在定义时不指定具体的类型，而是在使用的时候指定。这样，同一段代码就可以用于不同的数据类型。
   2. 改怎么定义函数和类就怎么定义，只是在数据类型那里全部用T替换。要引入头文件：template <typename T>

12. 何为作用域解析运算符(::)，并给出其使用场景？
   1. 指定调用那个类或命名空间的成员
   2. 使用场景：全局变量被局部变量遮盖、类中的静态成员、定义类外的成员函数、枚举、命名空间、继承与覆盖


13. 在C++中，何为友元函数和友元类，它们的使用场景是什么？
   1. 友元函数：友元函数不是类的成员函数，因此不受类的访问控制规则约束。但是还是在这个类里面定义的？
   2. 友元类：当一个类被声明为另一个类的“友元”时，它的所有成员函数都可以访问第二个类的私有和保护成员。友元关系是单向的。
   3. 使用场景：有三个。

14. 解释重载函数的解析是如何工作的？
   1. 是编译时过程。
   2. 编译器遵循以下步骤：候选函数集合的创建、可行函数的确定、最佳匹配的选择（形参与实参类型）、调用、不能确认就报错'调用歧义'

15. 什么是C++中的条件运算符？给出一个例子。
   1. 三元运算符：条件 ? 表达式1 : 表达式2

16. 解释C++中的隐式类型转换和显式类型转换？
   1. 隐式类型转换：编译器自动进行的类型转换。常见于赋值操作、函数调用时的参数传递等场景，目的是使类型匹配
   2. 显式类型转换：也是强制类型转换，需要程序员使用特定的语法（如static_cast<type>(expression)）明确指定转换的类型

17. 描述C++中虚函数的作用及其对多态的影响？
   1. 一种允许在派生类中被重写的成员函数
   2. 通过基类指针或引用调用虚函数时，将根据对象的实际类型调用相应的函数版本，这使得程序能够在运行时根据对象的实际类型决定调用哪个函数，从而实现多态性。
   3. 那为什么不直接使用派生类的指针调用成员函数呢？允许同一个接口处理不同类型的对象

18. 解释什么是纯虚函数和抽象类？
   1. 基类中声明但不提供实现的虚函数，它通过在函数声明的末尾加上= 0来指定
   2. 包含纯虚函数的类称为抽象类。抽象类不能直接实例化，只能作为基类来派生新的类。
   3. 在运行时根据对象的实际类型来调用相应的成员函数。意思是我用派生类去实例化对象时，编译器还不知道这个对象的具体类型？

19. 如何在C++中使用构造函数初始化列表？
   1.  在构造函数体执行之前初始化对象成员变量的方式。避免了先默认初始化然后再赋值的步骤

20. 如何在C++中使用条件语句和循环结构？
   1.  条件语句：if else if else switch
   2.  循环结构：for while do-while

21. 描述C++中的运算符优先级和结合性？
    1. 只需要记住那个表就行

22. 编写一个C++程序，展示类的构造函数和析构函数的使用。

23. 解释C++中的虚函数表（Virtual Function Table）是什么，以及它如何支持多态性。
    1. 虚函数表是一个指针数组，其中存储了该类的所有虚函数的地址。当调用虚函数时，实际上是通过对象的虚指针来查找并调用正确的虚函数。

24. 描述C++中的类型推断（Type Inference）是什么，以及它在C++11及更高版本中的作用。
    1. 编译器根据上下文推断出变量或表达式的类型，而无需显式指定类型。简化代码，编写模板代码简洁明了
    2. 关键字：auto，decltype ，decltype(auto)，函数返回值类型推断

25. 什么是C++中的静态断言（Static Assertion）？它在代码中的作用是什么？
    1. static_assert关键字。在编译时检查一些常量表达式的真假，并在条件为假时触发编译器错误。就是不用if判断或者抛出异常？
    2. 跟异常处理的方式不同：时机不同、用途不同、处理方式不同
26. 如何防止一个类被继承？
27. 构造函数可以是虚函数吗？解释你的答案。
28. 何时会调用拷贝构造函数？
29. 如何重载赋值运算符，并解释为什么需要注意深拷贝和浅拷贝？
30. 解释显式类型转换运算符和类型转换构造函数。


## 标准模版库(STL)
1. 解释STL中vector和list的区别及用途？
   1. 一个就是动态数组，一个是双向链表
   2. std是标准库的命名空间，还有Boost库，还可以自定义命名空间
2. 使用std::vector和std::list解释序列容器的概念。

3. 解释STL中map和unordered_map的区别及各自的使用场景？
   1. 关联容器，用于存储键值对。
   2. map为平衡二叉树(如红黑树)。保持元素有序
   3. unordered_map为哈希表。不需要保存元素有序

4. 如何使用std::sort对自定义对象进行排序？
   1. 对容器中的元素进行排序。需要提供比较器：比较函数或者函数对象。

5. 解释迭代器的概念及其与容器的关系?
   1. 迭代器抽象了指针的概念，允许以统一的方式操作各种数据结构。
   2. 允许算法通过迭代器访问容器中的元素,使用相同的迭代器接口，你可以对不同类型的容器执行相同的操作。
   3. 迭代器通常作为容器类的内部类或与容器类紧密关联的独立类实现。类模板和多态

6. 使用std::find在容器中查找元素的示例?
   1. 通过两个迭代器来制定范围

7. 描述std::unique_ptr和std::shared_ptr的区别及用法?
   1. 都是用来管理使用new操作符分配的内存，就不用再手动的使用delete了。使用智能指针，C++开发者可以更加专注于业务逻辑的实现，而不是被繁琐的内存管理任务所困扰。
   2. std::unique_ptr：不可复制，但可以移动
   3. std::shared_ptr：可复制和可移动，复制时引用计数增加。

8. std::forward_list与std::list的区别是什么？
   1. forward_list：单向链表
   2. list：双向链表

9. 在STL中，如何自定义比较函数来对std::set进行排序？
   1. set默认使用'<'运算符来对元素进行排序，确保它们是唯一的并按顺序存储。
   2. 自定义排序准则：使用函数对象、使用Lambda表达式

10. 描述std::pair和std::tuple的用途和基本操作？
   1.  用于存储固定数量和顺序的异构(不同类型)元素
   2.  pair：键值对，可以用构造函数或者make_pair来初始化
   3.  tuple：存储任意数量和类型的元素

11. std::deque提供了哪些独特的功能？
   1.  双端队列：提供了在序列的前端和后端高效插入和删除元素

12. 如何使用STL迭代器遍历一个容器？
   1.  以使用容器的begin()和end()方法获取迭代器的范围，并用循环结构（如for或while）来遍历
   2.  用迭代器时，可以访问和操作容器中的元素，而不需要直接使用容器的索引

13. STL中sort函数的工作原理是什么？
   1. 头文件<algorithm>
   2. std::sort函数是一种高效的排序算法，通常实现为快速排序、插入排序和堆排序的混合版本。平均时间复杂度为O(nlogn)

14. 编写一个程序，使用std::sort对自定义对象进行排序。
    1.  需要定义自定义对象的类，并且提供一个比较函数或重载 < 运算符来指定排序规则

15. 使用std::function和std::bind实现回调函数的例子。
    1.  回调函数：把函数作为参数传递给另一个函数或存储起来以备后续调用，而不是立即执行。当满足特定条件或事件发生时，这个“回调”被触发执行。
    

16. 解释迭代器的工作原理，并给出使用它们遍历std::vector的示例。
    1.  迭代器通过提供指向容器中元素的指针（或类似指针的对象），并定义了一组操作（如递增、递减、解引用等），来遍历容器。
    2.  迭代器的种类不同，支持的操作集合不同，容器的类型决定了适用的迭代器种类。不需要显式指定迭代器的种类。
17. 解释STL中的迭代器失效问题。


## 内存管理
1. 描述自动存储、静态存储、动态存储的区别？  
   1. 是根据变量的生命周期和作用域，存储空间的分配和回收方式
   2. 自动存储：函数内部的局部变量。存储在栈上。生命周期短，作用域就在单个函数。 栈内存
   3. 静态存储：需要保持持久性，或在程序多个部分间共享的变量。全局变量、静态变量和常量。生命周期长，在程序的多处访问。静态内存
   4. 动态存储：new和delete,运行时决定数据大小。存储在堆上。在运行时控制的复杂数据结构。 堆内存

2. 解释智能指针（如std::unique_ptr和std::shared_ptr）是如何帮助管理动态分配的内存的？  
   1. 用于自动管理动态分配(在堆上分配)，以避免内存泄漏和指针悬挂的问题。
   2. 在memory这个头文件里面。
   3. "作用域"是指一个变量或对象在程序中存在并可被访问的区域。作用域通常由大括号{}定义

3. 描述动态内存分配在C++中是如何工作的？
   1. 在程序运行时而非编译时，请求和释放内存的过程。
   2. new和delete；new[]和delete[]；智能指针
   3. C++中动态内存管理是如何工作的？比较new/delete和malloc/free。

4. 什么是内存泄露？如何在C++中避免内存泄露？
   1. 分配了堆内存（使用new、malloc等）但未能释放它
   2. 如何避免：使用智能指针、使用标准容器、RALL原则、避免裸指针、使用工具检测内存泄漏、及时释放不再需要的内存

5. 解释RAII（资源获取即初始化）原则？
   1. 将资源的生命周期与对象的生命周期绑定。在对象被创建的时刻，通过其构造函数获取所有必要的资源，在对象的生命周期结束时，通过其析构函数自动释放所占用的资源。

6. 如何使用智能指针管理资源？
   1. std::unique_ptr、std::shared_ptr和std::weak_ptr

7. 描述new和delete操作符的用法及其与malloc和free的区别。？
   1. 一个是C语言的一个是C++的，也意味着多了对对象的操作。
   2. 构造函数和析构函数的自动调用、类型安全、错误处理、分配和释放数组、

8.  描述placement new的使用场景和如何使用它？
   1. 允许在已分配的内存中构造对象。在预分配的内存上构造对象。

9.  何为内存碎片化，以及如何避免？
   1.  指内存分配过程中产生许多小的、分散的未使用区域的现象。
   2.  外部碎片化：两个已分配内存块之间，形成了无法被利用的小空闲内存块。不连续无法使用。
   3.  内部碎片化：配的内存块比实际需要的内存大时
   4.  如何避免：使用固定大小的内存分配、使用内存池、合理释放内存、使用自定义的内存分配器、利用现代编程语言提供的高级功能

10. C++中的弱指针(std::weak_ptr)是什么，以及使用它的原因？
    1.  用来解决std::shared_ptr智能指针可能引发的循环引用问题。

11. 解释栈内存和堆内存的区别及其用途？
   1.  栈内存：编译器自动分配和释放。用于存储函数参数、局部变量等。但大小有限
   2.  堆内存：通过代码中的动态分配函数手动管理。用于存储生命周期长或大小大、变化的对象。

12. 描述静态内存、栈内存和堆内存之间的区别。
    1.  静态内存：用于存储全局和静态数据，生命周期贯穿程序执行期。
    2.  栈内存：用于存储函数的局部变量，自动管理，快速但容量有限。
    3.  堆内存：用于动态内存分配，由程序员显式管理，灵活但管理成本高。

13. 编写一个示例程序，演示智能指针（std::unique_ptr，std::shared_ptr）的使用。

14. 解释C++11中新增的移动语义和右值引用
    1.  右值引用:使用双引号（&&）来声明,右值引用主要用于绑定临时对象和表达式的值。右值是指“临时”对象,通过 std::move() 来将左值转换为右值引用。
    2.  移动语义:允许将资源（如堆上分配的内存、文件句柄等）从一个对象“移动”到另一个对象，而不是进行复制。定义移动构造函数和移动赋值运算符
15. 描述C++中动态内存管理机制，包括new/delete与malloc/free的区别。
16. 解释内存泄漏、野指针和内存碎片化的概念及预防方法。



## 网络编程知识
1. 解释TCP和UDP协议的主要区别?
   1. 传输控制协议和用户数据报协议。在连接性、可靠性、效率、用途上面有区别。
   2. TCP适合对可靠性要求高的应用，如网页浏览、文件传输、电子邮件等。UDP适合对实时性要求高的应用，如视频流、在线游戏和VoIP（语音通信）


2. 如何使用socket API在C++中创建TCP客户端？
   1. 创建socket  socket()
   2. 指定服务器地址 sockaddr_in结构体
   3. 连接服务器 connect()
   4. 发送和接收数据 send()和recv()
   5. 关闭socket close()

3. 什么是非阻塞IO？它在网络编程中的作用是什么？
   1. 当线程执行一个非阻塞IO操作时，该操作会立即返回一个状态，而不是等待数据真正被读取或写入，不会让线程有被挂起的时候。这样的话就要通过轮询或事件通知来确定IO的状态。
   2. 在网络编程中可以做到：提高效率、增强响应性、资源利用优化

4. 描述如何在C++中处理网络数据的接收和发送?
   1. 使用套接字(Sockets) API

5. 什么是SSL/TLS？如何在C++网络应用中实现加密通信？
   1. SSL(安全套接字层)和TLS(传输层安全)
   2. 有专门的库：OpenSSL，GnuTLS，LibreSSL

6. 描述C++中可以用来处理网络地址的数据结构?
   1. 依赖于底层操作系统提供的API和数据结构。

7. 什么是套接字选项（Socket Option），如何在C++中设置它们？
   1. 用于配置套接字行为的特定于实现的参数。通过设置这些选项，可以改变套接字的底层行为
   2. <Winsock2.h>和<sys/socket.h>中，setsockopt函数和getsockopt函数

8. 解释阻塞与非阻塞套接字的差异？
   1. 阻塞与非阻塞套接字的差异主要体现在套接字操作（如数据的发送、接收）对应用程序控制流的影响上。

9.  描述TCP的三次握手过程？
   1.  第一次握手：SYN
   2.  第二次握手：SYN-ACK
   3.  第三次握手：ACK
   4.  目的和重要性：确保双方准备就绪、同步序列号、防止旧连接初始化段的干扰。

10. 什么是套接字（Socket）编程？
   1.  使用套接字，程序可以指定网络层的地址和传输层的协议端口，从而实现网络服务的客户端和服务器端的开发

11. 如何处理网络中的数据传输？
   1.  建立网络连接、数据的发送与接收、以及连接的关闭。在C++中通过使用Socket API来实现

12. 编写一个C++程序，实现简单的HTTP客户端。

13. 解释如何在C++程序中实现DNS查找。
    1.  使用Boost库中的asio模块来执行DNS查找

14. 描述非阻塞套接字的优点及其在C++中的使用。
    1.  优点：异步操作、灵活性
    2.  使用：
        1. 设置非阻塞模式
        2. 使用异步IO操作


## 多线程并发编程能力
1. 解释线程在C++11中是如何被引入和使用的?
   1. 引入了对多线程编程的原生支持，包括线程管理、同步机制以及条件变量等。都包含在<thread>、<mutex>、<future>、<atomic>等头文件。
   2. 通过std::thread类提供了一种在C++程序中创建和管理线程的方式。std::thread允许你指定一个函数或可调用对象，作为新线程的入口点。如果不加thread那整个源代码就只有一个主线程。
   3. 线程的使用注意事项：等待线程完成、传递参数、线程局部存储、移动语义

2. 描述互斥锁（std::mutex）的用途和如何使用它来同步数据访问?(**为什么我的VScode不能有多线程编程？**)
   1. 防止多个线程同时访问同一种资源(如全局变量、数据结构等)，防止数据竞争，保持数据一致性

3. 什么是死锁？如何避免?
   1. 死锁的四个必要条件：互斥条件、持有和等待条件、非剥夺条件、循环等待条件
   2. 如何避免死锁：

4. 解释条件变量（std::condition_variable）及其在线程同步中的应用?
   1. 条件变量通常与互斥锁（std::mutex）结合使用，用于线程间的协调和状态通知。
   2. 使用条件变量：等待（wait）；通知（notify）

5. 描述C++中的原子操作和std::atomic类型的使用?
   1. 原子操作是指在多线程环境中，无法被其他线程中断的操作。
   2. 声明原子变量，执行原子操作

6. 何为线程局部存储（Thread Local Storage）并如何在C++中使用它？
   1. 每个线程都有自己独立实例的数据存储方式。可以通过thread_local关键字来声明线程局部存储变量

7. 何为std::future和std::promise，它们如何协同工作？
   1. 位于<future>头文件中。这两个类用于在不同线程之间传递值或状态信息
   

8. 何为活锁（Livelock），它如何发生，以及如何避免？
   1. 处于活锁的进程/线程是处于忙等（busy-waiting）状态，持续地改变状态以尝试解决冲突，但这些尝试总是以失败告终
   2. 如何发生：活锁通常发生在两个或多个线程尝试响应对方的行为以避免冲突时。每个线程都在尝试让步给其他线程，但由于它们的让步是同时进行的，这实际上导致了无限循环，没有任何线程能够继续执行
   3. 如何避免：随机退避、优先级系统、请求-确认机制、监控和干预、状态变化策略

9.  描述C++中的std::async的作用？
   1. 位于<future>头文件中。用于异步执行一个任务
   2. 作用：异步执行、简化多线程编程、获取异步结果

10. 解释C++11中std::thread的基本使用方法。
   1.  C++11提供的<thread>头文件
   2.  使用步骤：
      1.  定义线程任务
      2.  创建std::thread对象
      3.  等待线程完成（可选）
      4.  分离线程（可选）

11. 描述C++11中的std::mutex和std::lock_guard，并给出同步访问共享资源的示例
    1.  std::mutex 是C++11引入的互斥量，用于保护共享资源的访问，确保同一时间只有一个线程可以访问共享资源。两个主要操作函数：lock() 和 unlock()
    2.  std::lock_guard 是一个C++11模板类，用于在作用域结束时自动释放锁。通过RAII（资源获取即初始化）机制，在构造时自动锁定互斥量，在析构时自动释放互斥量
12. 如何在C++中创建线程？
    

    


## 高级主题
1. 在C++中如何实现函数模板的特化？
   1. 存在这些类型的特化模版版本，编译器将优先使用特化版本而不是通用模板
   2. 实现：定义通用模板、特化模板

2. 解释Lambda表达式捕获列表中的[=]、[&]和[this]的含义？
   1. Lambda表达式：提供了一种方便的方式来定义匿名函数对象
   2. Lambda表达式的捕获列表定义了外部作用域中的变量如何被Lambda表达式捕获
      1. [=]：值捕获所有外部变量
      2. [&]：引用捕获所有外部变量
      3. [this]：捕获当前对象的this指针

3. 解释C++中的Lambda表达式及其捕获模式。
   1. 创建匿名函数：
   2. 基本语法：[capture-list](parameters) -> return-type { body }

4. 描述C++中异常安全（Exception Safety）的概念及其级别？
   1. 异常安全主要关注代码在抛出异常时的行为，尤其是资源泄露、数据一致性和程序状态等方面。
   2. 异常安全的级别:
      1. 无异常保证（No-throw Guarantee）/不抛出异常保证
      2. 强异常保证（Strong Exception Guarantee）/提交或回滚保证
      3. 基本异常保证（Basic Exception Guarantee）/无泄露保证
      4. 无异常安全保证（No Exception Safety Guarantee）
   3. 实现异常安全的策略：
      1. RAII、Copy-and-swap、智能指针

5. 解释C++中异常处理的工作原理和最佳实践。
   1. 异常处理的基本流程：
      1. 异常抛出（Throw）
      2. 异常捕获（Catch）
      3. 异常处理（Handle）
      4. 异常传播（Propagation）
   2. C++中的异常处理最佳实践
      1. 仅在适当的情况下使用异常
      2. 使用标准异常类
      3. 捕获精确的异常类型
      4. 注意异常安全性

6. 描述C++17中引入的结构化绑定（Structured Binding）及其用法？
   1. 结构化绑定允许你一次性声明多个变量，并直接将它们绑定到聚合类型的各个元素或成员上。这样，你可以避免显式地访问元素或写额外的代码来提取值。
   2. 使用场景:
      1. 从函数返回多个值时
      2. 在范围基于的for循环（range-based for loop）中遍历容器，特别是容器元素是聚合类型时
      3. 需要处理数组或结构体成员时，直接提取成员到独立变量中

7. 描述模板元编程（TMP）的概念及其在C++中的应用。

8. 编写一个示例程序，演示如何使用C++20的概念来实现类型约束
   1. 在模板中定义对类型的约束，以确保模板参数满足特定的要求
9. 描述模板类与模板函数的区别。
10. 解释内联函数的优缺点。
11. 如何诊断和优化C++程序的性能问题？
   
   

