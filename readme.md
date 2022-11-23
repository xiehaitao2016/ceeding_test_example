# Creating a New Ceedling Project
ceedling new <prjname>

## example1---如何使用ceedling进行TDD测试驱动开发
### create a module
ceedling module:create[lights]

可以通过
ceedling module:create[electrical/leds]
创建更深层次的目录结构

此时，可以通过
ceedling
命令，进行测试并查看测试情况

### 实现一个特性
lights.h 头文件，增加API接口定义
lights.c 增加API的接口实现

在test_lights.c里，增加对新增的API接口的测试用例

test_WhenTheHeadlightSwitchIsOff_ThenTheHeadLightsAreOff

### Mocking 硬件接口
如何测试嵌入式软件？如何解决对硬件的依赖呢？

这时候需要用到mocking技术，即仿冒或模拟

通过仿冒硬件接口，可以不需要实际的硬件来进行单元测试

image.png

通过Mocking技术，可以将依赖硬件的层序解耦成下面的形式：

image.png


## example2---如何使用mock技术解耦硬件依赖
本例子的硬件结构如下：

image.png

1.创建温度传感器模块
ceedling module:create[tempSensor]

假设温度传感器寄存器值和实际温度的对应关系如下：

image.png

则写出test_whenTempRegisterReadsMaxValue_thenTheTempIsTheMaxValue测试用例代码：


2.mock I2C API接口
在test_tempSensor.c里，添加
#include "mock_i2c.h"
告诉ceedling，你需要ceeding 对i2c.h进行mock，ceedling会生成
mock_i2c.c和mock_i2c.h并编译到target，在我们的test_tempSensor.c里，就可以调用这些mock的接口了

3.执行测试
ceedling

## example3---如何对已有的项目使用Ceedling进行单元测试

通常情况下，你发布bin并测试的方法如下：
image.png


TDD测试开发时，使用ceedling增加单元测试代码并单独发布，不影响现有的发布代码
image.png

### 以已有的一个项目为例
git clone https://github.com/ElectronVector/add-ceedling-to-existing-project.git

mv add-ceedling* blinky
ceedling new blinky

通过以下命令，查看ceedling管理了哪些源文件
ceedling files:source

1.创建一个新的测试文件

ceedling module:create[led]


2.添加更多的源文件目录路径
某些源文件是由第三方提供的，可以通过配置project.yml文件，设置搜索路径：

image.png


3.添加需要mock的头文件到test_led.c里

#include "mock_gpio.h"

通过这种方式告诉ceedling，你直到有一个gpio.h文件，需要ceedling去mock并生成
mock_gpio.c和mock_gpio.h


4. 添加其它的头文件到ceedling搜索路径

image.png

默认对于extern的API接口，是不是mocking的，如果需要对extern的API也生成mock，需要在project.yml里添加配置：

:cmock:

  :treat_externs: :include

5.测试

ceedling test:all