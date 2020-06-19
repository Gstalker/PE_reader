#pragma once
#include"PE_Headers.h"
class Section_Headers : virtual public PE_Headers {
private:
	IMAGE_SECTION_HEADER* SECTION_HEADER;
	WORD NUMBERS_OF_SECTIONS;
protected:
	WORD Numbers_of_sections();

	const char* SH_Name(int);//int:指明访问数组中的第i个成员
	const char* SH_Misc(int);//物理地址或内存中节区所占大小的union，都是双字
	const char* SH_VirtualAddress(int);
	const char* SH_SizeOfRawData(int);
	const char* SH_PointerToRawData(int);
	const char* SH_PointerToRelocations(int);
	const char* SH_PointerToLinenumbers(int);
	const char* SH_NumberOfRelocations(int);
	const char* SH_NumberOfLinenumbers(int);
	const char* SH_Characteristics(int);
public:
	void SH_init(const char*);
	~Section_Headers();//唯一一个需要动态分配空间的，必须规定析构函数
};

