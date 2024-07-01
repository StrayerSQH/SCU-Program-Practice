#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <conio.h>
#include "sexchoose.h"
//设计逻辑：两个贴图，点其中一个贴图后按下确定按钮，对应的gender被置1，并继续接下来的逻辑

Sex::Sex() {//initialize the position
	int genderHeight = 1;//小人图片高度
	int genderWidth = 1;//小人图片宽度，都是需要后续手动修改
	int checkWidth = 1;
	int checkHeight = 1;
	gender1_L = 1;//gender1x
	gender1_U = 1; // gender1y
	gender2_L = 1;
	gender2_U = 1;
	gender1_R = gender1_L + genderWidth;
	gender2_R = gender2_L + genderWidth;
	gender1_D = gender1_U + genderHeight;
	gender2_D = gender2_U + genderHeight;
	check_L = 1;//set by hand
	check_U = 1;//set by hand as well
	check_R = check_L + checkWidth;
	check_D = check_U + checkHeight;
}

void Sex::userclick() {
	float xx, yy;  
	while (!_kbhit()) { // 当没有按键被按下时继续循环  
		POINT cursorPos; // 声明POINT结构体用于存储鼠标坐标  
		GetCursorPos(&cursorPos); // 获取鼠标的屏幕坐标  
		xx = static_cast<float>(cursorPos.x);
		yy = static_cast<float>(cursorPos.y);
		Sleep(10);
	}
	if (xx > gender1_L && xx<gender1_R && yy >gender1_U && yy < gender1_D) {//鼠标坐标在贴图1范围内
		gender1 = 1;//选择了第一个性别
		gender2 = 0;
	}
	else if (xx > gender2_L && xx<gender2_R && yy >gender2_U && yy < gender2_D) {//贴图2
		gender2 = 1;//选择了第二个性别
		gender1 = 0;
	}
}

int Sex::checktwice() {
	float xx, yy;
	while (!_kbhit()) { // 当没有按键被按下时继续循环  
		POINT cursorPos; // 声明POINT结构体用于存储鼠标坐标  
		GetCursorPos(&cursorPos); // 获取鼠标的屏幕坐标  
		xx = static_cast<float>(cursorPos.x);
		yy = static_cast<float>(cursorPos.y);
		Sleep(10);
	}
	if (xx > check_L && xx<check_R && yy >check_U && yy < check_D) {//鼠标坐标在贴图1范围内
		return true;
	}
}

void Sex::sexChoose() {
	while (1) {//一直读取
		userclick();
		Print();
		if (Sex::checktwice()) {
			break;//跳出性别读取
		}
	}
	//继续接下来的逻辑
}

void Sex::Print() {
	if (gender1 == 1) {
		//显示一行字写着“male”，领导写一下吧我不知道你写哪的
		//也可以识别悬停啊什么的，我用的是贴图但应该也可以放大缩小什么的
	}
	else if (gender2 == 1) {
		//同上
	}
}

int main() {
	Sex s;
	s.sexChoose();
	return 0;
}