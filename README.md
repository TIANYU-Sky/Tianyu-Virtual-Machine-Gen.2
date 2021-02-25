# Tianyu-Virtual-Machine-Gen.2
项目开发于2020年3月，开发耗时2个月零10天
&emsp;   
&emsp;     
# 目录
> **[虚拟机的基本构成](#First)**
>> [虚拟内存](#First-1)  
>> [虚拟处理器](#First-2)  
>> [虚拟系统](#First-3)  
>> [虚拟输入输出控制器](#First-4)  
>> [虚拟设备](#First-5)
> &emsp;  

> **[设计与环境](#Second)**  
>> [设计理念](#Second-1)  
>> [设备](#Second-2)
> &emsp;  

> **[整体设计](#Third)**
>> [系统框架](#Third-1)  
>> [基本设计](#Third-2)
> &emsp;  

> **[详细设计与实现](#Forth)**
>> [虚拟内存](#Forth-1)  
>> [虚拟处理器](#Forth-2)  
>> [虚拟系统](#Forth-3)  
>> [虚拟输入输出控制器](#Forth-4)  
>> [虚拟设备](#Forth-5)   
>> [虚拟设备](#Forth-6)  
>>> [C语言字符串结构](#Forth-6-1)  
>>> [天宇文件组件](#Forth-6-2) 
> &emsp;  

> **[参考文献](#Fifth)**
> &emsp;  

> **[指令集编码](#Sixth)**
>> [指令格式](#Sixth-1)  
>> [详细说明](#Sixth-2)  

&emsp;  
&emsp;  
#### **注意**  
+ 当前说明文档部分改自论文<font size=3>《天宇虚拟机的设计与实现》</font>，部分说明可能与Github文件存在不匹配的问题，给您造成不便，尽情谅解。  
+ 由于网络问题，在国内浏览时，文档内的图片可能无法正常显示。如果出现该问题，您可以clone本项目，将图片括号内的链接修改为说明文字部分的括号中的链接，即可正常显示图片。  
+ 如果对该项目有疑问或建议，欢迎联系邮件：<u>ysydty@outlook.com</u>或<u>1564891277@qq.com</u>。  
+ 该项目已经作为毕业设计提交。


&emsp;  
&emsp;  
## <span id="First">虚拟机的基本构成</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机的设计目标是需要更好的与现在的物理机进行融合，因此，天宇虚拟机的系统结构将模仿计算机的物理结构。**天宇虚拟机**包含五个主要组件：<kbd>虚拟内存</kbd>、<kbd>虚拟处理器</kbd>、<kbd>虚拟系统</kbd>、<kbd>虚拟输入输出控制器</kbd>以及<kbd>虚拟设备</kbd>。
### <span id="First-1">**虚拟内存**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟内存类似于物理机的内存控制器，由它直接进行内存的操作，所有的内存申请与释放都将依赖这个模块实现。
### <span id="First-2">**虚拟处理器**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟处理器是天宇虚拟机中的执行模块，它模仿实际的处理器，包含<kbd>ALU（算数逻辑单元）</kbd>、<kbd>FPU（浮点运算单元）</kbd>、<kbd>寄存器组（16个通用寄存器与4个专用寄存器）</kbd>以及<kbd>执行控制器</kbd>。  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟处理器所采用的二进制指令模仿x86指令集，并结合RISC，*只提供64位的运行环境*。
### <span id="First-3">**虚拟系统**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟系统是天宇虚拟机的**总控中心**，负责整个虚拟机的运行。它需要协调内存、处理器与I/O，并控制之间的通讯。同时还需要针对多线程实现内存锁以及线程的申请。
### <span id="First-4">**虚拟输入输出控制器**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟I/O控制器是天宇虚拟机对扩展设备的连接通道，它可以连接、管理多种虚拟设备，并实现模拟的I/O通讯。
### <span id="First-5">**虚拟设备**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟设备是天宇虚拟机的最外层组件，它是I/O控制器的外部连接组件。虚拟设备通过实现指定的接口与I/O控制器相连接，并完成注册、通讯与销毁操作。

&emsp;  
&emsp;  

## <span id="Second">设计与环境</span>
### <span id="Second-1">**设计理念**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机的设计结合了物理机与现有的JVM、CLR，既可以通过指令的翻译进而实现跨平台的特性，也提供了一组虚拟内存与虚拟I/O控制器，可以方便开发人员更好的访问内存与外部设备，实现更多的功能。虚拟I/O控制器与虚拟设备的设计借鉴微内核架构，采用扩展组件的形式实现，可以更方便的实现设备的扩展、更新和维护。
### <span id="Second-2">**设备**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;由于本系统设计时，默认采用了**64位**的汇编代码，因此在处理器的选择上必须支持x86-64的指令集。同时，由于启动后的系统占用约为1.3-1.5GB（以Windows 10 1909为例），因此为了保证程序的运行，设定不小于2GB的内存空间。  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**硬件需求配置**表如下：  
|||
|:-:|:-:|
|设备|最低要求|
|处理器|支持x86-64指令集的处理器|
|内存|2GB及以上|

&emsp;   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;您可以根据您的需要，使用指定平台的汇编代码，依照调用规则替换基于x86-64指令的汇编代码，以实现跨平台。  

&emsp;  
&emsp;  

## <span id="Third">整体设计</span>
### <span id="Third-1">**系统框架**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机整体分为五个组成部分，如下图所示，分别为：虚拟系统、虚拟处理器，虚拟内存、虚拟I/O控制器与虚拟设备。虚拟系统是整个虚拟机系统的控制中心，其中包含虚拟处理器、虚拟内存与虚拟I/O控制器。通过虚拟系统的调度，完成虚拟处理器与内存、输入输出设备之间的通讯。虚拟I/O控制器连接虚拟设备，提供外部扩展设备的功能。  
![天宇虚拟机逻辑结构-(READMEIMG/TYVMGen.2-LogicStruct.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-LogicStruct.png)
### <span id="Third-2">**基本设计**</span>
> 虚拟处理器  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;如下图所示，虚拟机的处理器模拟现在的通用处理器设计，包含基本的<kbd>算术逻辑单元</kbd>、<kbd>浮点运算单元</kbd>、<kbd>寄存器</kbd>和<kbd>控制器</kbd>。其中段寄存器用于相对寻址的实现，专用寄存器则作为堆栈、源/目的地址等的寻址，通用寄存器用于临时保存数据；算术逻辑单元用于执行逻辑指令与算数指令，浮点运算单元用于执行独立的浮点指令；指令指针始终指向下一条需要执行的指令位置；<kbd>标志寄存器</kbd>用于保存指令执行完成后符号、奇偶性等附加数据的值。  
![天宇虚拟机虚拟处理器基本设计-(READMEIMG/TYVMGen.2-BaseDesign-CPU.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-BaseDesign-CPU.png)  
&emsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟处理器的<kbd>执行控制器</kbd>是处理器的控制单元，主要用于指令的译码和执行，在执行中出现的指令错误也将通过系统通道进行报告。天宇虚拟机指令集借用x86指令集，提供与其类似的指令系统，如下表展示了所有天宇虚拟机现有**指令集**的所有指令；由于篇幅原因，具体的指令编码见[指令集编码](#Sixth)。  
> 
> |指令助记符|翻译代码|说明|
> |:-:|:-:|:--|
> |NOP|0x00|空指令（占用等待时间5ms）|
> |STC|0x01|设置标志寄存器进位标志为1|
> |CLC|0x02|设置标志寄存器进位标志为0|
> |CMC|0x03|设置标志寄存器进位标志取反|
> |RET|0x04|过程返回|
> |PUSHF|0x06|将64位标志寄存器压入栈中|
> |POPF|0x07|从栈中弹出64位数据到标志寄存器|
> |PUSHA|0x08|RAX/RBX/RDX/RCX/RSP/RBP/RSI/RDI入栈|
> |POPA|0x09|RDI/RSI/RBP/RSP/RCX/RDX/RBX/RAX出栈|
> |LAIP|0x0A|将RIP寄存器传送至RAX寄存器|
> |SAIP|0x0B|从RAX寄存器更新RIP寄存器|
> |PUSH|0x20|将元素压入堆栈|
> |POP|0x21|从栈顶弹出元素|
> |IN|0x22|I/O输入指令|
> |LDS|0x23|将指针装入DS段|
> |LES|0x24|将指针装入ES段|
> |LCS|0x25|将指针装入CS段|
> |LSS|0x27|将指针装入SS段|
> |LAF|0x28|将标志寄存器内容传送至RAX|
> |SAF|0x29|将RAX内容传送至标志寄存器|
> |INC|0x2A|自增1|
> |DEC|0x2B|自减1|
> |NEG|0x2C|求补|
> |JMP|0x2D|无条件跳转指令|
> |CALL|0x2E|无条件调用指令|
> |JE|0x2F|相等时转移|
> |JZ|0x30|等于0时转移|
> |JNE|0x31|不等时转移|
> |JNZ|0x32|不等于0时转移|
> |JC|0x33|有进位时转移|
> |JNC|0x34|无进位时转移|
> |JO|0x35|溢出时转移|
> |JNO|0x36|未溢出时转移|
> |JS|0x37|符号位为1时转移（负时转移）|
> |JNS|0x38|符号位为0时转移（正时转移）|
> |JP|0x39|偶时转移|
> |JNP|0x3A|奇时转移|
> |JPO|0x3B|奇时转移|
> |JPE|0x3C|偶时转移|
> |LOOP|0x3D|RCX不为0时循环|
> |JCXZ|0x3E|RCX为零时转移|
> |INT|0x3F|中断指令|
> |NOT|0xE0|逻辑非|
> |MOV|0xA0|数据传送指令|
> |CMPXCHG|0xA4|比较并交换指令（包含内存锁）|
> |OUT|0xA5|I/O输出指令|
> |LEA|0xA6|装入有效地址|
> |ADD|0xA7|算术加法|
> |SUB|0xA8|算术减法|
> |CMP|0xA9|比较指令|
> |MUL|0xAA|无符号乘法|
> |IMUL|0xAB|有符号乘法|
> |DIV|0xAC|无符号除法|
> |IDIV|0xAD|有符号除法|
> |AND|0xAE|逻辑与|
> |OR|0xAF|逻辑或|
> |XOR|0xB1|逻辑异或|
> |SHR|0xB2|逻辑右移|
> |SAR|0xB3|算术右移|
> |SHL|0xB4|逻辑左移|
> |SAL|0xB5|算数左移|
> |FINIT|0x10|初始化浮点部件|
> |FCLEX|0x11|清除异常|
> |FNOP|0x12|浮点空指令|
> |FLDZ|0x13|将0.0装入ST0|
> |FLD1|0x14|将1.0装入ST0|
> |FLDPI|0x15|将Π装入ST0|
> |FLDL2T|0x16|将log2(10)装入ST0|
> |FLDL2E|0x17|将log2(e)装入ST0|
> |FLDLG2|0x18|将log10(2)装入ST0|
> |FLDLN2|0x19|将ln2装入ST0|
> |FDECSTP|0x1A|减少浮点寄存器栈指针|
> |FINCSTP|0x1B|增加浮点寄存器栈指针|
> |FCHS|0xD1|改变ST0的符号|
> |FABS|0xD2|将ST0取绝对值后保存|
> |FSQRT|0xD3|将ST0取根号后保存|
> |FSIN|0xD4|将ST0取正弦值后保存|
> |FCOS|0xD5|将ST0取余弦值后保存|
> |FXCH|0xD6|交换ST0与ST1|
> ||0x40|交换ST0与STi|
> |FCMP|0xD7|比较ST0与ST1|
> ||0x45|比较ST1与ST0|
> |FADD|0xD8|浮点加法ST0+ST1|
> ||0x46|浮点加法ST0+STi|
> |FSUB|0xD9|浮点减法ST0-ST1|
> ||0x48|浮点减法ST0-STi|
> |FSUBR|0xDA|浮点减法ST1-ST0|
> ||0x49|浮点减法STi-ST0|
> |FMUL|0xDB|浮点乘法ST0*ST1|
> ||0x4C|浮点乘法ST0*STi|
> |FDIV|0xDC|浮点除法ST0/ST1|
> ||0x4E|浮点除法ST0/STi|
> |FDIVR|0xDD|浮点除法ST1/ST0|
> ||0x4F|浮点除法STi/ST0|
> |FLD|0x41|将浮点数装入ST0|
> |FILD|0x42|将整数装入ST0|
> |FST|0x43|保存浮点数ST0|
> |FIST|0x44|保存整数ST0|
> |FIADD|0x47|浮点加法ST0+整数|
> |FISUB|0x4A|浮点减法ST0-整数|
> |FISUBR|0x4B|浮点减法 整数-ST0|
> |FIDIV|0x50|浮点除法ST0/整数|
> |FIDIVR|0x51|浮点除法 整数/ST0|

&emsp;  

> **虚拟内存**  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟内存包含内存申请与释放两个模块，对应虚拟机对物理内存的申请与释放。在今后的更新升级中，可以增加其他模块以实现更多的功能。
&emsp;  

> **虚拟系统**  
> ![天宇虚拟机虚拟系统基本设计-(READMEIMG/TYVMGen.2-BaseDesign-SYS.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-BaseDesign-SYS.png)  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;如上图所示为虚拟机虚拟系统的*逻辑结构*。虚拟系统作为整个虚拟机的控制中心，其包含所有的其他外部组件接口，同时提供针对多线程的内存锁与内存申请表。处理器管理器用于管理所有虚拟机包含的子线程，并为每一个线程分配自己的线程号，方便后期内存释放与管理。内存申请表则对应每一个线程，由某一个线程所申请的空间在线程结束之后将会自动结束，由此保证多线程内部内存的释放。多线程锁则针对带锁的指令进行内存访问控制，保证原子性操作。对于所有的外部系统调用都将通过系统调用接口进行统一的封装，以此可以为后期跨平台提供更方便的操作，**虚拟系统的通用接口**如下表。
> 
> |天宇虚拟机虚拟系统接口函数表|
> |:-:|
> |void Lock()|
> |void UnLock()|
> |uint64 DeviceIn(uint64)|
> |void DeviceOut(uint64, uint64)|
> |void SysInterrupt(uint64, uint64, uint64*)|
> |void SysException(uint64, uint64)|  
> 
> &emsp;  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;拟系统中的系统调用主要分为内存系统调用、线程系统调用与控制台系统调用，具体的**系统调用设计**见下表。  
> 
> |中断号|传递参数|返回参数|系统调用类型|
> |:-:|:-:|:-:|:-:|
> |0x10|uint64|uint64|系统内存申请|
> |0x11|uint64|-|系统内存销毁|
> |0x12|uint64|uint64|系统内存大小请求|
> |0x20|uint64|-|创建新线程|
> |0x30|uint64|-|打印一个字符到控制台|
> |0x31|uint64|-|打印字符串到控制台|
> |0x32|-|uint64|从控制台读取一个字符|
> |0x33|uint64|uint64|从控制台读取字符串，返回实际长度|

&emsp;  

> **虚拟输入输出控制器**  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟输入输出控制器中包含连接表，用于记录连接设备信息以及为其分配的设备号，由虚拟系统的所有系统调用都将通过查表找到对应的设备再进行具体操作。  

&emsp;  

> **虚拟设备**  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟设备在虚拟机设计中只规定一组通用的控制接口，用于连接虚拟输入输出控制器。下表为虚拟机所定义的**虚拟设备基本接口**。
> 
> |接口方法|说明|
> |:-:|:--|
> |CStructString iodevice_describe()|该方法用户获取虚拟设备的描述信息|
> |void iodevice_out(uint64 data)|用于将64bit数据输出到设备中|
> |uint64 iodevice_in()|用于从设备中读取64bit数据|
> |byte iodevice_state()|用于获取当前设备的状态（具体状态值见下表：**虚拟设备状态宏定义**）|
> |void iodevice_pause()|通知设备暂停|
> |void iodevice_resume()|通知设备从暂停中恢复|
> |void iodevice_stop()|通知设备停止工作|
> |void iodevice_start()|通知设备开始工作|
> |void iodevice_clerror()|通知设备清空所有的异常|
> |void iodevice_reset()|通知设备重置工作状态并开始运行|
> 
> &emsp;  
> *虚拟设备状态宏定义*
> |宏定义|值|描述|
> |:-:|:-:|:--|
> |\_\_TYVM_IO_DEVICE_STATE_RUNNING\_\_|0x00|设备正在运行（正在数据处理）|
> |\_\_TYVM_IO_DEVICE_STATE_FREE\_\_|0x01|设备空闲（设备运行无数据处理）|
> |\_\_TYVM_IO_DEVICE_STATE_STOPED\_\_|0x02|设备已经停止运行|
> |\_\_TYVM_IO_DEVICE_STATE_PAUSED\_\_|0x03|设备暂停（未停止运行）|
> |\_\_TYVM_IO_DEVICE_STATE_ERROR\_\_|0xFF|设备存在错误|
> 
> *注：天宇虚拟机虚拟设备状态宏定义在头文件（tvmio.h）中定义。*  

&emsp;  
&emsp;  

## <span id="Forth">详细设计与实现</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在本项目的实现中，通过**C语言**的**结构体**与**函数指针**实现部分<u>面向对象的封装、继承</u>。通过在头文件中定义公共的方法、变量将它们包含在结构体中，并在实现的文件中根据需要包含这个结构体（结构体放在实现结构体的第一个变量位置），内部可以增加新的变量和方法，通过这种方式实现数据的封装。同时对于不同的派生结构，可以为其函数指针指派不同的函数实现，以此实现函数的多态特性。在对象的创建与销毁中，采用公共的函数以模拟OOP中的构造与析构函数。  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;通过这样的设计方式，在软件的开发过程中，既可以避免C++语言的复杂特性，也可以提供更好的数据抽象能力。在外部扩展结构上，也可以通过这样的设计保证接口的统一。在之后的类图中，**特殊标出C语言**的部分即为**采用该技术实现**，其中的构造与虚构函数则对用外部函数，并**隐藏**了内部方法**的操作对象传递参数**；**没有特殊标注**的则是使用的**C++面向对象编程**。
&emsp;  
&emsp;  
### <span id="Forth-1">**虚拟内存**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;当前天宇虚拟机的内存组件，主要为程序运行时内存的分配与释放提供操作接口。如下图所示为虚拟机内存组件的<b>类设计图（C语言）</b>。  
![天宇虚拟机内存组件类图（C语言）-(READMEIMG/TYVMGen.2-Realize-Memory.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-Memory.png)   

&emsp;  
### <span id="Forth-2">**虚拟处理器**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机处理器主要用于指令的执行，其<b>类结构（C语言）</b>如下图所示。每一个CPU在虚拟机中模拟一个独立的线程，因此每一个CPU中都包含一个线程号用于标识线程，同时内部包含完整的处理器结构。在CPU中还包含一个系统组件接口，CPU运行过程中出现的错误、请求的中断、I/O的访问都可以通过此接口与虚拟系统进行通讯和数据的传输。  
![天宇虚拟机处理器组件类图（C语言）-(READMEIMG/TYVMGen.2-Realize-CPU.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-CPU.png)  
&emsp;   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在虚拟CPU中虽然提供了段寄存器的设计，但由于在实际的x64运行时，为了保证寻址空间，默认并**不采用基于段寄存器的寻址**。因此在虚拟机运行过程中也保留了这个设定，段寄存器的值默认为0。对于**数据的寻址**，则依旧**可以使用段寄存器**进行基于段的寻址。需要注意的是，虽然段寄存器默认不适用，但当指令对**CS段进行修改后**，依旧**会影响下一条指令的位置**，因此在指令设计中，应**避免对CS段寄存器进行赋值操作**，以免影响指令执行时的安全性，也避免出现不可控的跳转。  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟CPU中的<kbd>栈顶</kbd>与<kbd>栈底</kbd>字段用于进行**栈地址的安全性检查**，可以为栈指针的验证提供根据。在执行时如遇到需要对堆栈指针进行操作的指令，**处理器**将会先**对栈指针进行安全性验证**，如果验证**失败**，则将**自动向虚拟系统抛出异常**并**结束掉该线程**，**保证**内存的**安全性**。  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CPU中还包含了一个用于计算内存位置的函数，通过该函数，CPU可以实时的根据指令，计算相对寻址的目标地址。  
&emsp;   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;每一个虚拟CPU在执行时都需要绑定一个实际的系统线程，因此在运行时，将会通过系统线程调用处理器执行方法实现运行。在处理器执行方法中，将会获取下一跳指令，并完成译码工作。译码完成后的指令将被组装成一个指令包，<b>指令包类结构（C语言）</b>如下图所示，并**通过指令包中的Run方法**实现指令的**执行**。对于**不同的指令**，指令包中的**Run方法将绑定到不同的实例**。  
![天宇虚拟机执行指令包类图（C语言）-(READMEIMG/TYVMGen.2-Realize-InstructionPackage.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-InstructionPackage.png)   
&emsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在指令包中都包含**指令锁状态**、**操作数方向状态**、**段寄存器描述**、**操作数大小描述**以及**操作数对象**。天宇虚拟机的<b>指令操作数类图（C语言）</b>如下图所示。指令译码过程中会**根据需要**填充第一操作数与第二操作数以及其他的状态与描述符，在执行中根据状态与描述符完成对操作数的调整。  
![天宇虚拟机执行指令操作数包类图（C语言）-(READMEIMG/TYVMGen.2-Realize-InstructionPackageOP.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-InstructionPackageOP.png)   
&emsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机处理器的**指令译码逻辑**如下图所示。译码器依次从内存中<kbd>读取字节</kbd>，<kbd>判断指令前缀</kbd>、<kbd>判断指令</kbd>，并<kbd>根据指令分类对操作数部分进行读取</kbd>。在译码过程中如果存在指令异常，将通过系统接口抛出异常。  
![ 天宇虚拟机处理器指令译码器逻辑流程图-(READMEIMG/TYVMGen.2-Realize-InstructionDecode.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-InstructionDecode.png)   

&emsp;  
### <span id="Forth-3">**虚拟系统**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机的虚拟系统为整个虚拟机提供统一的管理，并提供统一的管理接口。天宇虚拟机的<b>系统组件结构类图（C语言）</b>如下所示。  
![天宇虚拟机系统组件结构类图（C语言）-(READMEIMG/TYVMGen.2-Realize-System.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-System.png)   
&emsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在虚拟系统中，提供一组用于原子性操作的**内存锁**，保证在多线程时的操作不会出现异常。内存锁通过使用`pthread_mutex_t`实现（包含于`pthreads.h`中）。虚拟系统的实现采用C语言模拟OOP，因此除接口外，内部的对象都在.c文件中声明实现封装。  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;虚拟系统的系统中断是系统调用的实现方式，程序CPU通过**调用系统中断完成系统功能调用**。虚拟系统中的系统异常方法是CPU进行异常抛出的通道，当指令执行过程出现异常时，将通过该通道报告异常以及出现异常的位置，当前已经定义的**系统组件异常**见下表。  
|宏定义|值|说明|
|:-:|:-:|:-:|
|\_\_TYVM_RUNNING_EXCEPTION_UNKNOWN_ERROR\_\_|0x00|未知异常|
|\_\_TYVM_RUNNING_EXCEPTION_CPU_DECODER_ERROR\_\_|0x01|指令译码异常|
|\_\_TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR\_\_|0x02|指令执行异常|
|\_\_TYVM_RUNNING_EXCEPTION_OVERFLOW_STACK\_\_|0x10|堆栈越界|
|\_\_TYVM_RUNNING_EXCEPTION_NULL_POINTER\_\_|0x11|空指针异常|  

*注：天宇虚拟机系统组件的异常定义在（tvmsystem.h）中。*  

&emsp;  
### <span id="Forth-4">**虚拟输入输出控制器**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机输入输出控制器为所有拓展的虚拟设备提供通用的接口。I/O控制其中包含一个设备列表，所有的扩展设备都将通过设备列表与虚拟机相连接，并由一个唯一的设备号标识。如下图所示为<b>虚拟I/O控制器类图（C语言）</b>。   
![天宇虚拟机IO控制器组件类图（C语言）-(READMEIMG/TYVMGen.2-Realize-IOController.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-IOController.png)   
&emsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<kbd>设备列表</kbd>采用**哈希字典**的方式实现，对设备号取64位模之后按照大小顺序排列设备形成链表。哈希字典的**哈希散列值位32**，通过逻辑运算实现求模，以提高系统性能。  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;设备列表中，默认的0-255号设备都是保留的，**特别是0号设备。当虚拟机运行模式为嵌入式程序时，通过0号设备接口，程序可以很方便的与上层程序进行通讯，实现数据、控制的传输**。 

&emsp;  
### <span id="Forth-5">**虚拟设备**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机中的<kbd>虚拟设备</kbd>，是一种可以由**外部实现并动态加载的虚拟组件**，要求开发者必须实现**I/O设备构造与销毁方法**（见下表），并要求开发者所创建的结构**必须包含**<kbd>IODevice</kbd>结构体。通过统一的二进制接口，虚拟机可以动态的加载设备并实现设备的多种操作。  

|||
|:-:|:-:|
|IODevice* CreateIODevice()|创建一个指定的I/O设备对象|
|void DestroyIODevice(IODevice*)|销毁一个指定的I/O设备对象|

&emsp;  
### <span id="Forth-6">**相关组件**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机项目中，需要设计部分组件，以实现扩展性的功能，主要包括天宇文件组件以及用于C语言的字符串组件。
&emsp;  
#### <span id="Forth-6-1">***C语言字符串结构***</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;由于在C语言中并没有类似于C++的字符串类型，因此在项目中使用结构体与函数指针的方式实现模拟的字符串操作。**C语言字符串结构**如下图所示，在此结构中，只包含公开的对字符串的操作方法。   
![C语言字符串结构接口类图（C语言）-(READMEIMG/TYVMGen.2-Realize-CStringStruct.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-CStringStruct.png)   
&emsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;如下图所示为**实现的C语言字符串结构**，并实现对字段的封装，只向用户提供通用的操作方法。   
![C语言字符串结构实现类图（C语言）-(READMEIMG/TYVMGen.2-Realize-CStringStructR.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-CStringStructR.png)   

&emsp;  
#### <span id="Forth-6-2">***天宇文件组件***</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;对于实际的应用程序以及其相关的扩展文件，它们都属于可执行与可链接文件，在Windows平台上是PE（Portable Executable）文件，而在Unix上则是ELF（Executable and Linkable Format）。因此为了在虚拟机上应用二进制的文件，设计了类似于ELF与PE文件的TY文件格式，它也包含独立的文件头、定位表，**TY文件格式文件头结构体**如下图所示。以下将展示天宇文件组件的组成结构以及实现逻辑。   
![TY文件头结构体-(READMEIMG/TYVMGen.2-Realize-TYFileHead.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-TYFileHead.png)  
&emsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;除了TY文件头，天宇文件还包含一个**应用程序头部**（如下图），用于标识文件具体的运行环境、堆栈、段寄存器信息等数据。   
![天宇文件应用程序头部结构体-(READMEIMG/TYVMGen.2-Realize-TYExecuteHead.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-TYExecuteHead.png)   
&emsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;每一个天宇文件都由多个节组成，每一个节都对应**符号表**（如下图）中的一条记录。   
![天宇文件符号表结构体-(READMEIMG/TYVMGen.2-Realize-TYSymTable.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-TYSymTable.png)     
&emsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;节拥有自己的数据区、重定位段，每一个重定位段由<b>附加头（TianyuAdditionHead）</b>和<b>重定位节点（TYRelocationItem）</b>（如下图）构成。   
![天宇文件节附加头结构体-(READMEIMG/TYVMGen.2-Realize-TianyuAdditionHead.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-TianyuAdditionHead.png)      
![天宇文件节重定位节点结构体-(READMEIMG/TYVMGen.2-Realize-TYRelocationItem.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-TianyuAdditionHead.png)     
&emsp;     
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;由于在文件设计上使用了全新的文件结构，因此也需要创建一个新的文件读取器对文件信息进行处理，所以设计了一个专用于**读取天宇文件的操作器**，如下图所示。读取器可以完成文件头的分析，并通过文件读取接口实现对每一个节的获取工作。     
![天宇文件读取器-(READMEIMG/TYVMGen.2-Realize-TYYFilePackage.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Realize-TYYFilePackage.png)  

&emsp;  
## <span id="Fifth">参考文献</span>
\[1\] 唐朔飞. 计算机组成原理（第二版）\[M\]. 北京：高等教育出版社, 2008  
\[2\]	Randal E. Bryant. Computer Systems: A Programmer\`s Perspective, Third Edition \[M\]. 北京：机械工业出版社, 2016   
\[3\]	张秀宏. 自己动手写Java虚拟机 \[M\]. 北京：机械工业出版社, 2016  
\[4\]	Josuttis,N.M. The C++ Standard Library: A Tutorial and Reference \[M\]. 北京：电子工业出版社, 2015  
\[5\]	郑莉，董渊，何江舟. C++语言程序设计 \[M\]. 北京：清华大学出版社, 2010  
\[6\]	赵雁南，温冬婵，杨泽红. 微型计算机系统与接口 \[M\]. 北京：清华大学出版社, 2011  
\[7\]	周志明. 深入理解Java虚拟机：JVM高级特性与最佳实践 \[M\]. 北京：机械工业出版社, 2013  
\[8\]	蒋本珊. 计算机组成原理 \[M\]. 北京：清华大学出版社, 2004  
\[9\]	王生原. 编译原理 \[M\]. 北京：清华大学出版社, 2015  
\[10\]	Intel. Intel® 64 and IA-32 Architectures Software Developer`s Manual \[S\]  
\[11\]	Alfred,V.A, Monica S. Lam, Ravi Sethi, Jeffrey D. Ullman. Compilers: Principles, Techniques and Tools, Second Edition \[M\]. Pearson Education Inc, 1986  
\[12\]	David A. Patterson, John L. Hennessy. Computer Organization and Design, The Hardware/Software Interface, Fourth Edition\[M\]. 北京：机械工业出版社, 2013  
\[13\]	陈火旺. 程序设计语言编译原理（第三版）\[M\]. 北京：国防工业出版社, 2014  
\[14\]	吕国英,李茹,王文剑,任瑞征,钱宇华. 算法设计与分析\[M\]. 北京：清华大学出版社, 2015  
\[15\]	张尧学,宋虹,张高. 计算机操作系统教程（第四版）\[M\]. 北京：清华大学出版社, 2013  
\[16\]	汤小丹,梁红兵,哲凤屏,汤子瀛. 计算机操作系统（第四版）\[M\]. 西安：西安电子科技大学出版社, 2014  


&emsp;  
## <span id="Sixth">指令集编码</span>
### <span id="Sixth-1">**指令格式**</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机指令系统为了能够在后期提供直接二进制映射的代码执行方式，因此在采用x86指令集的同时仿造x86-64的编码结构，分为**5个部分**，分别是：<kbd>指令前缀</kbd>、<kbd>指令编码</kbd>、<kbd>附加段</kbd>、<kbd>相对偏移</kbd>与<kbd>立即数</kbd>，具体的**指令集结构说明**见下表。  

|项目|长度（字节）|说明|
|:-:|:-:|:--|
|指令前缀|1-2|用于描述指令的操作位数、段寄存器和扩展功能|
|指令编码|1-3|用于编码指令|
|附加段|1-3|用于描述操作数类型、寻址方式|
|相对便宜|8|用于描述寻址的固定偏移量|
|立即数|1/2/4/8|用于提供立即数，长度根据附加段、指令编码确定|

&emsp;  
### <span id="Sixth-2">**详细说明**</span>

+ 指令前缀  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机指令集中的指令前缀分为两种，一个为**功能前缀**，一个为**寄存器前缀**。
&emsp;    
> **功能前缀**  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;功能前缀采用特定的指令标识符（0x6X）来标识前缀。功能前缀段用于提供指令数据的长度、操作数方向以及内存锁的标识。**功能前缀段结构**见下图所示。  
![天宇虚拟机指令集功能前缀结构-(READMEIMG/TYVMGen.2-Instruction-FuncPre.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Instruction-FuncPre.png) 
&emsp;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;本段的高4位位固定值，第0位为内存锁标志位，第1位位操作数的方向位（0时为OPNum2→OPNum1；1时为OPNum1→OPNum2），第2-3位为操作数大小位，其定义见下表：**指令集功能前缀2-3位值描述**，用于描述针对在使用内存寻址时，确定从内存中读取数据的长度。  
>   
> |第3位|第2位|描述|
> |:-:|:-:|:-:|
> |0|0|指定操作数为64位|
> |0|1|指定操作数为32位|
> |1|0|指定操作数为16位|
> |1|1|指定操作数为8位|
&emsp;
> **寄存器前缀**  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;寄存器前缀使用特定的指令标识符（0x9X）来标识前缀,用于提供段寄存器的选择.**寄存器前缀段结构**见下图所示，**段寄存器选择对应值描述**见下表。  
![天宇虚拟机指令集寄存器前缀结构-(READMEIMG/TYVMGen.2-Instruction-RegPre.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Instruction-RegPre.png) 
>   
> |段|编码|描述|
> |:-:|:-:|:-:|
> |Null|0b000|空段（不使用段寄存器）|
> |CS|0b001|代码段|
> |DS|0b010|数据段|
> |ES|0b100|扩展段|
> |SS|0b011|堆栈段|
> |Default|0b111|缺省的段（由寄存器确定）|

&emsp;
+ 指令编码  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;指令编码部分根据指令操作数的数目，对高四位进行分组，具体的**指令分组信息**见下表。  
> 
> |分组|组大小|描述|
> |:-:|:-:|:-:|
> |0x0|15|0操作数指令|
> |0x1|16|0操作数指令|
> |0x2|16|1操作数指令|
> |0x3|16|1操作数指令|
> |0x4|16|1操作数指令|
> |0x5|16|1操作数指令|
> |0x6|0|前缀段标识|
> |0x7|16|保留|
> |0x8|16|保留|
> |0x9|0|前缀段标识|
> |0xA|16|2操作数指令|
> |0xB|16|2操作数指令|
> |0xC|16|2操作数指令|
> |0xD|16|1操作数指令|
> |0xE|16|1操作数指令（2字节长度）|
> |0xF|15|1操作数指令（2字节长度）|
> 
> &emsp;  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;其中0操作数指令总计31条，1操作数指令总计95条（64条1字节指令和31条2字节指令），2操作数指令总计48条。

&emsp;
+ 附加段  
> **段1**  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;附加段1为主要附加段，**附加段1的结构**如下图所示，用于提供第一操作数类型、寻址方式等操作；分为<kbd>寻址方式字段</kbd>、<kbd>寄存器/扩展码字段</kbd>与<kbd>副操作数字段</kbd>。  
![天宇虚拟机指令集附加段1结构-(READMEIMG/TYVMGen.2-Instruction-Addition1.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Instruction-Addition1.png) 
> &emsp;  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;高两位为寻址方式标识，用于描述当前指令的第一操作数的寻址方式，详细的**附加段1寻址方式编码**见下表所示。
> &emsp; 
> |编码|寻址方式|
> |:-:|:-:|
> |0b00|其他寻址（将会增加附加段2）|
> |0b01|寄存器操作数|
> |0b10|立即数寻址|
> |0b11|立即数（不存在第二操作数，忽略附加段1的低2位）| 
>   
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;中间的四位为寄存器/扩展码标识，用于描述对应的寄存器或立即数的长度，详细的**附加段1寄存器扩展码**见下表。
> &emsp; 
> |寻址方式|寄存器/拓展码|说明|
> |:-:|:-:|:--|
> |00|0000~1111|指定16个对应位数的寄存器|
> |01|0000~1111|指定16个对应位数的寄存器，标识变址寻址寄存器|
> |10|XXXX|指定8字节的偏移量用于寻址|
> |11|0001|指定的立即数长度为字节|
> ||0010|指定的立即数长度为字|
> ||0100|指定的立即数长度为双字|
> ||1000|指定的立即数长度为四字|
>   
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;低2位为副操作数（第2操作数）的类型标识符，具体的**附加段1副操作数编码**见下表。
> &emsp; 
> |编码|说明|
> |:-:|:-:|
> |00|无第二操作数|
> |01|副操作数为寄存器（扩展附加段3）|
> |10|副操作数为立即数（扩展附加段3）|
> |11|副操作数为扩展（扩展附加段4，当前不采用）|
> 
> *注：当寻址方式为立即数时，无论副操作数的值为何，其都将被忽略。*
> &emsp;

&emsp;
> **段2**  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;如下图所示为**指令集附加段2的结构**，为主操作数的附加寻址段，主要用于在寻址方式为其他寻址时，标识<kbd>基址寄存器</kbd>、<kbd>扩展倍率</kbd>以及<kbd>相对寻址偏移量</kbd>。  
![天宇虚拟机指令集附加段2结构-(READMEIMG/TYVMGen.2-Instruction-Addition2.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Instruction-Addition2.png) 
> &emsp;  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;附加段2中当“基址寄存器有效”**标识符**为**1**时，将会读取基址寄存器的值，基址寄存器可以是所有通用寄存器；扩展倍率用于机制寄存器的辅助运算（基址寄存器×扩展倍率，实现时采用算术左移的方式），其**倍率定义**见下表；**偏移量标识**用于确定寻址过程是否需要偏移量，当其**为1**时，自动向后读取8字节的整数作为偏移量。
> 
> |倍率编码|实际倍率|
> |:-:|:-:|
> |0b00|1|
> |0b01|2|
> |0b10|4|
> |0b11|8|


&emsp;
> **段3**  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;附加段3为副操作数寻址段。在指令中，副操作数只允许使用可直接寻址的值，包括立即数和寄存器立即数。具体的**附加段3编码**见下表。
> 
> |副操作数类型|编码|说明|
> |:-:|:-:|:-:|
> |01|XXXX|64位寄存器组|
> |10|0001|8位立即数|
> |10|0010|16位立即数|
> |10|0100|32位立即数|
> |10|1000|64位立即数|

&emsp;
+ 相对偏移  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;相对偏移量用于描述立即数寻址或其他寻址方式的辅助量，**长度固定为四字**（64bit）。

&emsp;
+ 立即数  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;立即数用于在指令中包含无需寻址的值，长度可选为字节、字、双字和四字，由长度描述符进行说明。

&emsp;
+ 寄存器编码  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;天宇虚拟机处理器中包含**整数寄存器**、**浮点寄存器**以及**标志寄存器**。
> **整数寄存器**  
> 天宇虚拟机指令集整数寄存器编码
> 
> |寄存器|编码|
> |:-:|:-:|
> |RAX|0b0000|
> |RBX|0b0001|
> |RCX|0b0010|
> |RDX|0b0011|
> |RSP|0b0100|
> |RBP|0b0101|
> |RSI|0b0110|
> |RDI|0b0111|
> |R8|0b1000|
> |R9|0b1001|
> |R10|0b1010|
> |R11|0b1011|
> |R12|0b1100|
> |R13|0b1101|
> |R14|0b1110|
> |R15|0b1111|

&emsp;
> **浮点寄存器**  
> 天宇虚拟机指令集浮点寄存器编码
> 
> |寄存器|编码|
> |:-:|:-:|
> |ST0|0b0000|
> |ST1|0b0001|
> |ST2|0b0010|
> |ST3|0b0011|
> |ST4|0b0100|
> |ST5|0b0101|
> |ST6|0b0110|
> |ST7|0b0111|

&emsp;
> **标志寄存器**    
![天宇虚拟机标志寄存器-(READMEIMG/TYVMGen.2-Instruction-FlagReg.png)](https://github.com/TIANYU-Sky/Tianyu-Virtual-Machine-Gen.2/blob/main/READMEIMG/TYVMGen.2-Instruction-FlagReg.png) 