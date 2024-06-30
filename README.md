# 四川大学新生入学模拟器
## 四川大学计算机学院2023级编程实战课程项目作业

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;欢迎使用四川大学新生入学模拟器！！！😄这是一个由四川大学计算机学院2023级计算机科学与技术专业学生编程实战课程开发的项目作业。<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;该模拟器旨在帮助新生更好地了解四川大学的校园环境和入学流程。通过模拟器，新生可以体验入学前的各种场景和任务，以便更好地适应四川大学大学生活。除此之外，本项目给即将进入大学学习计算机相关领域学科且需要进行编程实战的朋友们提供了一些思路。<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;当前游戏正在搭建中，欢迎大家提出宝贵的意见！！！该模拟器将持续进行更新，加入更多模块带来更多游戏玩法。<br>

### 1.项目依托的库
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在本项目中，我们选择了使用SFML库（Simple and Fast Multimedia Library）作为主要的技术框架。SFML是一个跨平台的多媒体库，专注于图形渲染和用户交互，非常适合游戏开发和图形应用程序。通过引入SFML库，我们成功实现了以下功能：<br>
#### 1.1 创建窗口
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;通过使用SFML库的sf::RenderWindow类，我们创建了一个窗口对象。这个窗口对象用于显示我们应用程序的图形界面。我们可以设置窗口的大小、标题和其他属性，以满足项目需求。<br>
#### 1.2 处理事件
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SFML库提供了强大的事件处理机制，我们可以监听和处理窗口中发生的各种事件。这些事件包括窗口关闭、按键按下、鼠标点击等用户交互行为。通过在主循环中使用SFML的事件循环，我们能够根据不同的事件类型执行相应的逻辑，例如关闭窗口、处理按键输入或响应鼠标点击。<br>
#### 1.3 绘制图形
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SFML库提供了丰富的绘图功能，使我们能够在窗口中绘制各种图形元素。通过使用SFML的绘图接口，我们成功绘制了背景图像、按钮和其他用户界面元素，从而创建出具有视觉吸引力的应用程序界面。<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;通过以上功能的实现，我们的项目能够提供了一个交互性强、视觉效果出色且较为简单的图形界面。给即将进入大学学习计算机相关领域学科且需要进行编程实战的朋友们提供了一些思路！！！😄<br>

### 2.项目开发记录
#### 2.1 环境配置（2024年6月29日）
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;本项目使用了SFML库（Simple and Fast Multimedia Library）。SFML是一个跨平台的开源多媒体库，旨在简化游戏和图形应用程序的开发过程。它提供了丰富的功能和易于使用的接口，使开发者能够快速创建交互性强、图形效果出色的应用程序。SFML支持多种编程语言，包括C++、Python、Java和.NET等，使开发者能够根据自己的喜好和需求选择合适的编程语言进行开发。它提供了一系列模块，涵盖了图形、窗口、音频、网络和系统等方面的功能，为开发者提供了全面的工具集。通过SFML，开发者可以轻松创建窗口，并在窗口中绘制图形、文字和粒子等元素。SFML还提供了丰富的输入处理功能，包括键盘、鼠标和触摸屏等，使开发者能够方便地响应用户的交互操作。SFML的音频模块支持多种音频格式的播放和录制，开发者可以轻松处理音效和音乐。网络模块提供了简单易用的网络编程接口，使开发者能够创建基于TCP或UDP的网络应用程序。SFML的设计理念注重简洁和高效，它在底层使用了硬件加速和多线程技术，以提供出色的性能和响应速度。同时，SFML的文档和社区支持非常丰富，开发者可以从官方文档、示例代码和社区论坛中获取帮助和资源。<br>
#### 2.2 界面初步搭建及部分功能测试（2024年6月30日）
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;项目初步实现了在调试运行程序中循环播放背景音乐、显示字体、显示按钮并根据按钮功能进行相应的事件相应。<br>
![界面初步搭建及部分功能测试（2024年6月30日）效果图](https://github.com/StrayerSQH/SCU-Program-Practice/blob/main/Introduction/%E7%95%8C%E9%9D%A2%E5%88%9D%E6%AD%A5%E6%90%AD%E5%BB%BA%E5%8F%8A%E9%83%A8%E5%88%86%E5%8A%9F%E8%83%BD%E6%B5%8B%E8%AF%95%EF%BC%882024%E5%B9%B46%E6%9C%8830%E6%97%A5%EF%BC%89.png)<br>

# Sichuan University Freshman Enrollment Simulator
## Project Assignment for Programming Practice Course, Class of 2023, School of Computer Science, Sichuan University

Welcome to the Sichuan University Freshman Enrollment Simulator! 😄 This is a project assignment developed by students majoring in Computer Science and Technology at Sichuan University, Class of 2023, as part of the Programming Practice course.

The simulator aims to help incoming freshmen better understand the campus environment and enrollment process at Sichuan University. Through the simulator, freshmen can experience various scenarios and tasks before enrollment, in order to better adapt to university life. In addition, this project provides some ideas for friends who are about to study computer-related subjects and need to engage in programming practice.

The game is currently under construction, and we welcome valuable suggestions! The simulator will continue to be updated, incorporating more modules to bring more gameplay.

### 1. Library Dependencies
In this project, we have chosen to use the SFML (Simple and Fast Multimedia Library) as the primary technical framework. SFML is a cross-platform multimedia library that focuses on graphics rendering and user interaction, making it ideal for game development and graphics applications. By incorporating the SFML library, we have successfully implemented the following features:

#### 1.1 Window Creation
By using the sf::RenderWindow class provided by the SFML library, we created a window object. This window object is used to display the graphical interface of our application. We can set the size, title, and other properties of the window to meet the project requirements.

#### 1.2 Event Handling
SFML provides a powerful event handling mechanism, allowing us to listen for and handle various events that occur within the window. These events include window closure, key presses, mouse clicks, and other user interactions. By using SFML's event loop in the main loop, we can execute the corresponding logic based on different event types, such as closing the window, handling key input, or responding to mouse clicks.

#### 1.3 Graphics Rendering
SFML provides rich drawing capabilities, allowing us to draw various graphic elements within the window. By using SFML's drawing interface, we successfully rendered background images, buttons, and other user interface elements, creating a visually appealing application interface.

Through the implementation of these features, our project is able to provide an interactive, visually appealing, and relatively simple graphical interface. It provides some ideas for friends who are about to study computer-related subjects and need to engage in programming practice! 😄

### 2. Project Development Log
#### 2.1 Environment Setup (June 29, 2024)
For this project, we used the SFML (Simple and Fast Multimedia Library). SFML is a cross-platform open-source multimedia library designed to simplify the development process of games and graphics applications. It provides rich functionality and an easy-to-use interface, enabling developers to quickly create interactive and visually impressive applications. SFML supports multiple programming languages, including C++, Python, Java, and .NET, allowing developers to choose the appropriate programming language based on their preferences and needs. It provides a set of modules covering graphics, windowing, audio, networking, and system functionalities, offering developers a comprehensive toolkit. With SFML, developers can easily create windows and draw graphics, text, and particles within the windows. SFML also provides rich input handling capabilities, including keyboard, mouse, and touch screen, making it easy for developers to respond to user interactions. The audio module of SFML supports playback and recording of multiple audio formats, allowing developers to handle sound effects and music effortlessly. The network module provides a simple and user-friendly network programming interface, enabling developers to create network applications based on TCP or UDP. SFML is designed with a focus on simplicity and efficiency, utilizing hardware acceleration and multithreading techniques at the lower level to provide excellent performance and responsiveness. Additionally, SFML has extensive documentation and community support, where developers can find help and resources from official documentation, sample code, and community forums.

#### 2.2 Initial Interface Construction and Partial Function Testing (June 30, 2024)
The project has initially implemented the looping playback of background music, display of fonts, display of buttons, and event handling based on button functionality in the debugging and running program.
![界面初步搭建及部分功能测试（2024年6月30日）效果图](https://github.com/StrayerSQH/SCU-Program-Practice/blob/main/Introduction/%E7%95%8C%E9%9D%A2%E5%88%9D%E6%AD%A5%E6%90%AD%E5%BB%BA%E5%8F%8A%E9%83%A8%E5%88%86%E5%8A%9F%E8%83%BD%E6%B5%8B%E8%AF%95%EF%BC%882024%E5%B9%B46%E6%9C%8830%E6%97%A5%EF%BC%89.png)<br>
