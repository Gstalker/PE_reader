#pragma once
//
// Created by Dreamstalker on 2019/8/23.
//
#ifndef PEREADER_DOS_HEAD_H
#define PEREADER_DOS_HEAD_H
#include"PE_Headers.h"

class DOS_Head : virtual public PE_Headers {
private:
	IMAGE_DOS_HEADER DOS_HEAD;
protected:
	const char* e_magic()const;
	const char* e_cblp()const;
	const char* e_cp()const;
	const char* e_crlc()const;
	const char* e_cparhdr()const;
	const char* e_minalloc()const;
	const char* e_maxalloc()const;
	const char* e_ss()const;
	const char* e_sp()const;
	const char* e_csum()const;
	const char* e_ip()const;
	const char* e_cs()const;
	const char* e_lfarlc()const;
	const char* e_ovno()const;
	const char* e_res()const;//数组，长度为4
	const char* e_oemid()const;
	const char* e_oeminfo()const;
	const char* e_res2()const;//数组，长度为10；
	const char* e_lfanew()const;
public:
	DOS_Head();
	explicit DOS_Head(const char*);//初始化函数
	void DOS_Head_open(const char*);//初始化函数
};

#endif //PEREADER_DOS_HEAD_H