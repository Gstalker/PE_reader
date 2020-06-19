#pragma once
//
// Created by Dreamstalker on 2019/8/23.
//

#ifndef PEREADER_NT_HEAD_H
#define PEREADER_NT_HEAD_H
#include"PE_Headers.h"

class NT_Head : virtual public PE_Headers {
private:
	DWORD SIGNATURE;//NT头签名
	IMAGE_FILE_HEADER FILE_HEADER;//文件头
	union OptionalHeader {
		IMAGE_OPTIONAL_HEADER32 OPTIONAL_32;//可选头32
		IMAGE_OPTIONAL_HEADER64 OPTIONAL_64;//可选头64
	}OPTIONAL_HEADER;//可选头联合体
	bool if32_true;
	//bool标记，如果为true,调用32位可选头
	//bool标记，如果为false，调用64位可选头
protected:
	void set_if32(bool);//接口：读取文件时设置bool标记
	bool if32();//接口：返回程序的运行环境(32bit or 64bit)
	const char* NT_Signature()const;


	const char* NTF_Machine()const;
	const char* NTF_NumberOfSections()const;
	const char* NTF_TimeDateStamp()const;
	const char* NTF_PointerToSymbolTable()const;
	const char* NTF_NumberOfSymbols()const;
	const char* NTF_SizeOfOptionalHeader()const;
	const char* NTF_Characteristics()const;


	const char* NTOPT_Magic()const;
	const char* NTOPT_MajorLinkerVersion()const;
	const char* NTOPT_MinorLinkerVersion()const;
	const char* NTOPT_SizeOfCode()const;
	const char* NTOPT_SizeOfInitializedData()const;
	const char* NTOPT_SizeOfUninitializedData()const;
	const char* NTOPT_AddressOfEntryPoint()const;
	const char* NTOPT_BaseOfCode()const;
	const char* NTOPT_BaseOfData()const;//64位没有这个东西
	const char* NTOPT_ImageBase()const;
	const char* NTOPT_SectionAlignment()const;
	const char* NTOPT_FileAlignment()const;
	const char* NTOPT_MajorOperatingSystemVersion()const;
	const char* NTOPT_MinorOperatingSystemVersion()const;
	const char* NTOPT_MajorImageVersion()const;
	const char* NTOPT_MinorImageVersion()const;
	const char* NTOPT_MajorSubsystemVersion()const;
	const char* NTOPT_MinorSubsystemVersion()const;
	const char* NTOPT_Win32VersionValue()const;
	const char* NTOPT_SizeOfImage()const;
	const char* NTOPT_SizeOfHeaders()const;
	const char* NTOPT_CheckSum()const;
	const char* NTOPT_Subsystem()const;
	const char* NTOPT_DllCharacteristics()const;
	const char* NTOPT_SizeOfStackReserve()const;
	const char* NTOPT_SizeOfStackCommit()const;
	const char* NTOPT_SizeOfHeapReserve()const;
	const char* NTOPT_SizeOfHeapCommit()const;
	const char* NTOPT_LoaderFlags()const;
	const char* NTOPT_NumberOfRvaAndSizes()const;
	const char* NTOPT_DataDirectory(int)const;//数组，长度16,这个单独整个页面出来


public:
	NT_Head();
	explicit NT_Head(const char*);//初始化函数
	void NT_Head_open(const char*);//初始化函数
};


#endif //PEREADER_NT_HEAD_H