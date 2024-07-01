#pragma once
#ifndef SEXCHOOSE_H
#define SEXCHOOSE_H

class Sex {
private:
	int gender1 = 0, gender2 = 0;
public:
	Sex();
	int gender1_L, gender1_R, gender1_U, gender1_D;//性别一的贴图坐标范围
	int gender2_L, gender2_R, gender2_U, gender2_D;//性别二的贴图坐标范围
	int check_L, check_R, check_U, check_D;//确定按钮的贴图坐标范围
	void sexChoose();//选贴图
	void userclick();//识别点击，避免用户把两个性别都选了过后全置1
	int checktwice();//点确定
	void Print();
};
#endif