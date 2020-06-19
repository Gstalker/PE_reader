// Created by Dreamstalker on 2019/8/21.
//
#include "PE_Headers.h"

PE_Headers::PE_Headers() : NT_OFFSET(0) {}
//初始化，NT_OFFSET为0时代表没有打开任何文件或者文件打开失败

PE_Headers::PE_Headers(const char* str) {
	this->PE_Headers_open(str);
	return;
}
void PE_Headers::PE_Headers_open(const char* str) {
	//构造函数：打开str所指的文件，读取NT_OFFSET
	ifstream fin(str, ios::binary | ios::in);
	if (!fin) {
		NT_OFFSET = 0;
		return;//如果文件打开失败，设置NT_OFFSET为0
	}
	this->FILE_LOC = str;
	fin.seekg(sizeof(IMAGE_DOS_HEADER) - sizeof(LONG), ios::beg);
	fin.read((char*)(&this->NT_OFFSET), sizeof(LONG));
	fin.close();
	return;
}
LONG PE_Headers::NT_offset() const {
	return NT_OFFSET;
}

const char* PE_Headers::File_loc() const {
	return FILE_LOC.c_str();
}

const char* PE_Headers::data2str(BYTE tar)const {
	stringstream trans;
	static string output;
	output.clear();
	trans << std::hex << tar;
	trans >> output;
	string temp_output(sizeof(BYTE) * 2 - output.size(), '0'); //补0
	temp_output += output;
	output.clear();
	output = temp_output;
	return output.c_str();
}
const char* PE_Headers::data2str(WORD tar)const {
	stringstream trans;
	static string output;
	output.clear();
	trans << std::hex << tar;
	trans >> output;
	string temp_output(sizeof(WORD) * 2 - output.size(), '0'); //补0
	temp_output += output;
	output.clear();
	output = temp_output;
	return output.c_str();
}
const char* PE_Headers::data2str(DWORD tar)const {
	stringstream trans;
	static string output;
	output.clear();
	trans << std::hex << tar;
	trans >> output;
	string temp_output(sizeof(DWORD) * 2 - output.size(), '0'); //补0
	temp_output += output;
	output.clear();
	output = temp_output;
	return output.c_str();
}
const char* PE_Headers::data2str(LONG tar)const {
	stringstream trans;
	static string output;
	output.clear();
	trans << std::hex << tar;
	trans >> output;
	string temp_output(sizeof(LONG) * 2 - output.size(), '0'); //补0
	temp_output += output;
	output.clear();
	output = temp_output;
	return output.c_str();
}
const char* PE_Headers::data2str(ULONGLONG tar) const {
	stringstream trans;
	static string output;
	output.clear();
	trans << std::hex << tar;
	trans >> output;
	string temp_output(sizeof(ULONGLONG) * 2 - output.size(), '0'); //补0
	temp_output += output;
	output.clear();
	output = temp_output;
	return output.c_str();
}
const char* PE_Headers::data2str(_IMAGE_DATA_DIRECTORY tar) const {
	//这个是什么东西，为什么我一点印象都没有?
	static string output;
	output.clear();
	output = data2str(tar.VirtualAddress);
	output += ',';
	output += data2str(tar.Size);
	return output.c_str();
}
const wchar_t* PE_Headers::GetWC(const char* str)const {
	const size_t cSize = strlen(str) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, str, cSize);
	return wc;
}