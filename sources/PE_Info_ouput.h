#pragma once
//
// Created by Dreamstalker on 2019/8/23.
//

#ifndef PEREADER_PEINFO_FILE_OUPUT_H
#define PEREADER_PEINFO_FILE_OUPUT_H
#include"DOS_Head.h"
#include"NT_Head.h"
#include"Section_Headers.h"
#include<conio.h>
class PEinfo_ouput :public DOS_Head, public NT_Head ,public Section_Headers{
private:
	explicit PEinfo_ouput(const char*);//这个接口放在这里只是懒得删代码
	void NTO_info_1();
	void NTO_info_2();//共18条，页9条，附带提示信息
	void NTO_info_3();//最后的十六位数组
	void SH_pages(int);//输出第int页的数组信息
protected:
	void DOS_info();
	void NTFILE_info();
	void NTOPT_info();
	void SH_info();
	void init(const char*);
public:
	PEinfo_ouput();
	void main_menu();//主菜单，打开文件，显示主要信息，切换界面
};


#endif //PEREADER_PEINFO_FILE_OUPUT_H