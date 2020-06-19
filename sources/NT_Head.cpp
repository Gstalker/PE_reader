//
// Created by Dreamstalker on 2019/8/23.
//

#include "NT_Head.h"

NT_Head::NT_Head() :SIGNATURE(0),if32_true(0){
	memset(&FILE_HEADER, 0, sizeof(IMAGE_FILE_HEADER));
	memset(&OPTIONAL_HEADER, 0, sizeof(IMAGE_OPTIONAL_HEADER64));
	return;
}

NT_Head::NT_Head(const char* str) {//初始化函数
	this->NT_Head_open(str);
	return;
}
void NT_Head::NT_Head_open(const char* str) {//初始化函数
	if (!this->NT_offset())return;
	ifstream fin(str, ios::binary | ios::in);//如果父类初始化成功，则直接读取DOS头
	fin.seekg(this->NT_offset(), ios::beg);
	fin.read((char*)(&this->SIGNATURE), sizeof(LONG));
	fin.read((char*)(&this->FILE_HEADER), sizeof(IMAGE_FILE_HEADER));
	if (this->FILE_HEADER.SizeOfOptionalHeader == sizeof(IMAGE_OPTIONAL_HEADER32)) {//判断，PE头文件32or64位
		this->set_if32(true);
		fin.read((char*)(&this->OPTIONAL_HEADER.OPTIONAL_32), sizeof(IMAGE_OPTIONAL_HEADER32));
	}
	else {
		this->set_if32(false);
		fin.read((char*)(&this->OPTIONAL_HEADER.OPTIONAL_64), sizeof(IMAGE_OPTIONAL_HEADER64));
	}
	fin.close();
	return;
}
void NT_Head::set_if32(bool flag) {//接口：读取文件时设置bool标记
	this->if32_true = flag;//旗子先给你插好，这玩意绝对跑不起来
	return;
}

bool NT_Head::if32() {
	return if32_true;
}

const char* NT_Head::NT_Signature() const {
	return data2str(SIGNATURE);
}

const char* NT_Head::NTF_Machine()const {
	return data2str(FILE_HEADER.Machine);
}

const char* NT_Head::NTF_NumberOfSections()const {
	return data2str(FILE_HEADER.NumberOfSections);
}

const char* NT_Head::NTF_TimeDateStamp()const {
	return data2str(FILE_HEADER.TimeDateStamp);
}

const char* NT_Head::NTF_PointerToSymbolTable()const {
	return data2str(FILE_HEADER.PointerToSymbolTable);
}

const char* NT_Head::NTF_NumberOfSymbols()const {
	return data2str(FILE_HEADER.NumberOfSections);
}

const char* NT_Head::NTF_SizeOfOptionalHeader()const {
	return data2str(FILE_HEADER.SizeOfOptionalHeader);
}

const char* NT_Head::NTF_Characteristics()const {
	return data2str(FILE_HEADER.Characteristics);
}



const char* NT_Head::NTOPT_Magic()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.Magic);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.Magic);
}

const char* NT_Head::NTOPT_MajorLinkerVersion()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.MajorLinkerVersion);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.MajorLinkerVersion);
}

const char* NT_Head::NTOPT_MinorLinkerVersion()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.MinorLinkerVersion);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.MinorLinkerVersion);
}

const char* NT_Head::NTOPT_SizeOfCode()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.SizeOfCode);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.SizeOfCode);
}

const char* NT_Head::NTOPT_SizeOfInitializedData()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.SizeOfInitializedData);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.SizeOfInitializedData);
}

const char* NT_Head::NTOPT_SizeOfUninitializedData()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.SizeOfUninitializedData);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.SizeOfUninitializedData);
}

const char* NT_Head::NTOPT_AddressOfEntryPoint()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.AddressOfEntryPoint);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.AddressOfEntryPoint);
}

const char* NT_Head::NTOPT_BaseOfCode()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.BaseOfCode);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.BaseOfCode);
}

const char* NT_Head::NTOPT_BaseOfData()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.BaseOfData);
	//else return data2str(OPTIONAL_HEADER.OPTIONAL_64.BaseOfData);//64位没有这个东西
	else return "64位程序没有这个成员";
}



const char* NT_Head::NTOPT_ImageBase()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.ImageBase);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.ImageBase);
}

const char* NT_Head::NTOPT_SectionAlignment()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.SectionAlignment);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.SectionAlignment);
}

const char* NT_Head::NTOPT_FileAlignment()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.FileAlignment);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.FileAlignment);
}

const char* NT_Head::NTOPT_MajorOperatingSystemVersion()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.MajorOperatingSystemVersion);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.MajorOperatingSystemVersion);
}

const char* NT_Head::NTOPT_MinorOperatingSystemVersion()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.MinorOperatingSystemVersion);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.MinorOperatingSystemVersion);
}

const char* NT_Head::NTOPT_MajorImageVersion()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.MajorImageVersion);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.MajorImageVersion);
}

const char* NT_Head::NTOPT_MinorImageVersion()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.MinorImageVersion);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.MinorImageVersion);
}

const char* NT_Head::NTOPT_MajorSubsystemVersion()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.MajorSubsystemVersion);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.MajorSubsystemVersion);
}

const char* NT_Head::NTOPT_MinorSubsystemVersion()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.MinorSubsystemVersion);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.MinorSubsystemVersion);
}

const char* NT_Head::NTOPT_Win32VersionValue()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.Win32VersionValue);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.Win32VersionValue);
}

const char* NT_Head::NTOPT_SizeOfImage()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.SizeOfImage);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.SizeOfImage);
}

const char* NT_Head::NTOPT_SizeOfHeaders()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.SizeOfHeaders);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.SizeOfHeaders);
}

const char* NT_Head::NTOPT_CheckSum()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.CheckSum);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.CheckSum);
}

const char* NT_Head::NTOPT_Subsystem()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.Subsystem);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.Subsystem);
}

const char* NT_Head::NTOPT_DllCharacteristics()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.DllCharacteristics);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.DllCharacteristics);
}

const char* NT_Head::NTOPT_SizeOfStackReserve()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.SizeOfStackReserve);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.SizeOfStackReserve);
}

const char* NT_Head::NTOPT_SizeOfStackCommit()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.SizeOfStackCommit);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.SizeOfStackCommit);
}

const char* NT_Head::NTOPT_SizeOfHeapReserve()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.SizeOfHeapReserve);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.SizeOfHeapReserve);
}

const char* NT_Head::NTOPT_SizeOfHeapCommit()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.SizeOfHeapCommit);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.SizeOfHeapCommit);
}

const char* NT_Head::NTOPT_LoaderFlags()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.LoaderFlags);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.LoaderFlags);
}

const char* NT_Head::NTOPT_NumberOfRvaAndSizes()const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.NumberOfRvaAndSizes);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.NumberOfRvaAndSizes);
}

const char* NT_Head::NTOPT_DataDirectory(int array)const {
	if (if32_true)return data2str(OPTIONAL_HEADER.OPTIONAL_32.DataDirectory[array]);
	else return data2str(OPTIONAL_HEADER.OPTIONAL_64.DataDirectory[array]);
}//数组，长度16