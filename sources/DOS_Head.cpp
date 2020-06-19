#include "DOS_Head.h"//
// Created by Dreamstalker on 2019/8/23.
//

#include "DOS_Head.h"
DOS_Head::DOS_Head() {
	memset(&DOS_HEAD, 0, sizeof(IMAGE_DOS_HEADER));
	return;
}

DOS_Head::DOS_Head(const char* str) {
	this->DOS_Head_open(str);
	return;
}

void DOS_Head::DOS_Head_open(const char* str) {
	if (!this->NT_offset())return;//父类初始化失败则跳过初始化
	ifstream fin(str, ios::binary | ios::in);//如果父类初始化成功，则直接读取DOS头
	fin.read((char*)(&this->DOS_HEAD), sizeof(IMAGE_DOS_HEADER));
	fin.close();
	return;
}
const char* DOS_Head::e_magic()const {
	return data2str(DOS_HEAD.e_magic);
}
const char* DOS_Head::e_cblp()const {
	return data2str(DOS_HEAD.e_cblp);
}
const char* DOS_Head::e_cp()const {
	return data2str(DOS_HEAD.e_cp);
}
const char* DOS_Head::e_crlc()const {
	return data2str(DOS_HEAD.e_crlc);
}
const char* DOS_Head::e_cparhdr()const {
	return data2str(DOS_HEAD.e_cparhdr);
}
const char* DOS_Head::e_minalloc()const {
	return data2str(DOS_HEAD.e_minalloc);
}
const char* DOS_Head::e_maxalloc()const {
	return data2str(DOS_HEAD.e_maxalloc);
}
const char* DOS_Head::e_ss()const {
	return data2str(DOS_HEAD.e_ss);
}
const char* DOS_Head::e_sp()const {
	return data2str(DOS_HEAD.e_sp);
}
const char* DOS_Head::e_csum()const {
	return data2str(DOS_HEAD.e_csum);
}
const char* DOS_Head::e_ip()const {
	return data2str(DOS_HEAD.e_ip);
}
const char* DOS_Head::e_cs()const {
	return data2str(DOS_HEAD.e_cs);
}
const char* DOS_Head::e_lfarlc()const {
	return data2str(DOS_HEAD.e_lfarlc);
}
const char* DOS_Head::e_ovno()const {
	return data2str(DOS_HEAD.e_ovno);
}
const char* DOS_Head::e_res()const {
	stringstream trans;
	string output;
	string temp;
	for (int i = 0; i < 3; ++i, output += ",") {
		temp.clear();
		trans << std::hex << DOS_HEAD.e_res[i];
		trans >> temp;
		string temp1(sizeof(LONG) - temp.size(), '0'); //补0
		output += temp1;
	}
	output[output.size()] = 0;
	static string reg;
	reg.clear();
	reg = output;
	return reg.c_str();
}//数组，长度为4
const char* DOS_Head::e_oemid()const {
	return data2str(DOS_HEAD.e_oemid);
}
const char* DOS_Head::e_oeminfo()const {
	return data2str(DOS_HEAD.e_oeminfo);
}
const char* DOS_Head::e_res2()const {
	stringstream trans;
	string output;
	string temp;
	for (int i = 0; i < 10; ++i, output += ",") {
		temp.clear();
		trans << std::hex << DOS_HEAD.e_res2[i];
		trans >> temp;
		string temp1(sizeof(LONG) - temp.size(), '0'); //补0
		output += temp1;
	}
	output[output.size()] = 0;
	static string reg;
	reg.clear();
	reg = output;
	return reg.c_str();
}//数组，长度为10；

const char* DOS_Head::e_lfanew()const {
	return data2str(DOS_HEAD.e_lfanew);
}