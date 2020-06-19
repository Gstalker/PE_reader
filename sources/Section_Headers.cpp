#include "Section_Headers.h"

void Section_Headers::SH_init(const char* str) {//这个函数存在蜜汁警告，无视即可
	if (!this->NT_offset())return;
	BYTE SIZE_OF_OPTIONAL_HEADER;
	ifstream fin(str, ios::binary | ios::in);//如果父类初始化成功，则直接读取DOS头
	fin.seekg(this->NT_offset() + sizeof(DWORD)+sizeof(WORD), ios::beg);
	fin.read((char*)(&this->NUMBERS_OF_SECTIONS), sizeof(WORD));//获取节区头数量
	this->SECTION_HEADER = new IMAGE_SECTION_HEADER[NUMBERS_OF_SECTIONS];//数组分配空间
	fin.seekg(this->NT_offset() + sizeof(WORD) * 2 + sizeof(DWORD) * 4, ios::beg);//获取可选头大小
	fin.read((char*)(&SIZE_OF_OPTIONAL_HEADER), sizeof(BYTE));
	fin.seekg(this->NT_offset() + sizeof(IMAGE_FILE_HEADER) + SIZE_OF_OPTIONAL_HEADER + sizeof(DWORD), ios::beg);//定位节区头数组地址
    fin.read((char*)(this->SECTION_HEADER), sizeof(IMAGE_SECTION_HEADER) * NUMBERS_OF_SECTIONS);//直接读取整个结构，舒服！！！
	fin.close();
	return;
}

Section_Headers::~Section_Headers() {
	delete[] SECTION_HEADER;
	return;
}//唯一一个需要动态分配空间的，必须规定析构函数

WORD Section_Headers::Numbers_of_sections() {
	return NUMBERS_OF_SECTIONS;
}


const char* Section_Headers::SH_Name(int array) {
	temp_string.clear();
	for (char i = 0, t = 1; i < 8 || t != 0; ++i) {
		t = SECTION_HEADER[array].Name[i];
		temp_string += t;
	}
	return temp_string.c_str();
}

const char* Section_Headers::SH_Misc(int array) {
	return this->data2str(SECTION_HEADER[array].Misc.VirtualSize);
}//物理地址或虚拟地址的union，都是双字

const char* Section_Headers::SH_VirtualAddress(int array) {
	return this->data2str(SECTION_HEADER[array].VirtualAddress);
}

const char* Section_Headers::SH_SizeOfRawData(int array) {
	return this->data2str(SECTION_HEADER[array].SizeOfRawData);
}

const char* Section_Headers::SH_PointerToRawData(int array) {
	return this->data2str(SECTION_HEADER[array].PointerToRawData);
}

const char* Section_Headers::SH_PointerToRelocations(int array) {
	return this->data2str(SECTION_HEADER[array].PointerToRelocations);
}

const char* Section_Headers::SH_PointerToLinenumbers(int array) {
	return this->data2str(SECTION_HEADER[array].PointerToLinenumbers);
}

const char* Section_Headers::SH_NumberOfRelocations(int array) {
	return this->data2str(SECTION_HEADER[array].NumberOfRelocations);
}

const char* Section_Headers::SH_NumberOfLinenumbers(int array) {
	return this->data2str(SECTION_HEADER[array].NumberOfLinenumbers);
}

const char* Section_Headers::SH_Characteristics(int array) {
	return this->data2str(SECTION_HEADER[array].Characteristics);
}


