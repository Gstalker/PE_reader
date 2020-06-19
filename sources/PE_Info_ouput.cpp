//
// Created by Dreamstalker on 2019/8/23.
//

#include "PE_Info_ouput.h"
PEinfo_ouput::PEinfo_ouput() {
	return;
}
PEinfo_ouput::PEinfo_ouput(const char* str) {
	this->init(str);
	return;
}
void PEinfo_ouput::init(const char* str) {
	this->PE_Headers_open(str);
	this->DOS_Head_open(str);
	this->NT_Head_open(str);
	this->SH_init(str);
	return;
}

void PEinfo_ouput::DOS_info() {
	system("cls");
	if (!this->NT_offset()) {
		cout << "can not open the file!";
		exit(-1);
	}
	cout << "name\t\tmeaning\t\t\t\t\tvalue\n\n";
	cout << "e_magic\t\tMagic number“MZ”\t\t\t" <<e_magic()<< '\n';
	cout << "e_cblp\t\tBytes on last page of file\t\t" << e_cblp() << '\n';
	cout << "e_cp\t\tPages in file\t\t\t\t" << e_cp() << '\n';
	cout << "e_crlc\t\tRelocations\t\t\t\t" << e_crlc() << '\n';
	cout << "e_cparhdr\tSize of header in paragraphs\t\t" << e_cparhdr() << '\n';
	cout << "e_minalloc\tMinimum extra paragraphs needed\t\t" << e_minalloc() << '\n';
	cout << "e_maxalloc\tMaximum extra paragraphs needed\t\t" << e_maxalloc() << '\n';
	cout << "e_ss\t\tInitial(relative)SS value\t\t" << e_ss() << '\n';
	cout << "e_sp\t\tInitial SP value\t\t\t" << e_sp() << '\n';
	cout << "e_csum\t\tChecksum\t\t\t\t" << e_csum() << '\n';
	cout << "e_ip\t\tInitial IP value\t\t\t" << e_ip() << '\n';
	cout << "e_cs\t\tInitial(relative)CS value\t\t" << e_cs() << '\n';
	cout << "e_lfarlc\tFile address of relocation table\t" << e_lfarlc() << '\n';
	cout << "e_ovno\t\tOverlay number\t\t\t\t" << e_ovno() << '\n';
	cout << "e_res[4]\tReserved words\t\t\t\t" << e_res() << '\n';
	cout << "e_oemid\t\tOEM identifier (for e_oeminfo)\t\t" << e_oemid() << '\n';
	cout << "e_oeminfo\tOEM information; e_oemid specific\t" << e_oeminfo() << '\n';
	cout << "e_res2[10]\tReserved words\t\t\t\t" << e_res2() << '\n';
	cout << "e_lfanew\tFile address of new exe header\t\t" << e_lfanew() << '\n';
	cout << "\n按ESC返回上一级菜单";
	cout << "\nWaitng ketboard input...";
	for (int a = 0; a != 27;)a = getch();
	return;
}

void PEinfo_ouput::NTFILE_info() {
	system("cls");
	if (!this->NT_offset()) {
		cout << "can not open the file!";
		exit(-1);
	}
	cout << "name\t\t\tmeaning\t\t\t\tvalue\n\n";
	cout << "Signature\t\tNT头签名\t\t\t" << NT_Signature() << '\n';
	cout << "Machine\t\t\t文件运行平台\t\t\t" << NTF_Machine() << '\n';
	cout << "NumberOfSections\t区段数量\t\t\t" << NTF_NumberOfSections() << '\n';
	cout << "TimeDateStamp\t\t文件创建时间\t\t\t" << NTF_TimeDateStamp() << '\n';
	cout << "PointerToSymbolTable\t符号表偏移\t\t\t" << NTF_PointerToSymbolTable() << '\n';
	cout << "NumberOfSymbols\t\t符号个数\t\t\t" << NTF_NumberOfSymbols() << '\n';
	cout << "SizeOfOptionalHeader\t扩展头大小\t\t\t" << NTF_SizeOfOptionalHeader() << '\n';
	cout << "Characteristics\t\tPE文件属性\t\t\t" << NTF_Characteristics() << '\n';
	cout << "\n按ESC返回上一级菜单";
	cout << "\nWaitng ketboard input...";
	for (int a = 0; a != 27;)a = getch();
	return;
}

void PEinfo_ouput::NTOPT_info() {
	system("cls");
	if (!this->NT_offset()) {
		cout << "can not open the file!";
		exit(-1);
	}
	int a = '1';
	while (1) {
	switch_loop:
		switch (a) {
		case '1':this->NTO_info_1(); a = 0; break;
		case '2':this->NTO_info_2(); a = 0; break;
		case '3':this->NTO_info_3(); a = 0; break;
		case 27:return;
		default:a = getch(); goto switch_loop;//我不知道咋整的，switch语句的default居然会退出switch
		}
		cout << "\n\n按键查看详细信息:\n1:第一页\n2:第二页\n3:第三页\nESC:返回上一级菜单\n\nWaitng ketboard input...";
	}
}

void PEinfo_ouput::NTO_info_1() {
	system("cls");
	cout << "name\t\t\t\tmeaning\t\t\t\t\tvalue\n\n";

	cout << "Magic\t\t\t\t文件属性标志字\t\t\t\t" << NTOPT_Magic() << '\n';
	cout << "MajorLinkerVersion\t\t链接程序的主版本号\t\t\t" << NTOPT_MajorLinkerVersion() << '\n';
	cout << "MinorLinkerVersion\t\t链接程序的次版本号\t\t\t" << NTOPT_MinorLinkerVersion() << '\n';
	cout << "SizeOfCode\t\t\t所有含代码的节的总大小\t\t\t" << NTOPT_SizeOfCode() << '\n';
	cout << "SizeOfInitializedData\t\t所有含已初始化数据的节的总大小\t\t" << NTOPT_SizeOfInitializedData() << '\n';
	cout << "SizeOfUninitializedData\t\t所有含未初始化数据的节的大小\t\t" << NTOPT_SizeOfUninitializedData() << '\n';
	cout << "AddressOfEntryPoint\t\t程序执行入口RVA\t\t\t\t" << NTOPT_AddressOfEntryPoint() << '\n';
	cout << "BaseOfCode\t\t\t代码区块的起始RVA\t\t\t" << NTOPT_BaseOfCode() << '\n';

	if (if32())cout << "BaseOfData\t\t\t数据区块的起始RVA\t\t\t" << NTOPT_BaseOfData() << '\n';
	else cout << "BaseOfData\t\t\t数据区块的起始RVA\t\t\t" << NTOPT_BaseOfData() << '\n';

	cout << "ImageBase\t\t\t程序的首选装载地址\t\t\t" << NTOPT_ImageBase() << '\n';
	cout << "SectionAlignment\t\t内存中的区块的对齐大小\t\t\t" << NTOPT_SectionAlignment() << '\n';
	cout << "FileAlignment\t\t\t文件中的区块的对齐大小\t\t\t" << NTOPT_FileAlignment() << '\n';
	cout << "MajorOperatingSystemVersion\t要求操作系统最低版本号的主版本号\t" << NTOPT_MajorOperatingSystemVersion() << '\n';
	cout << "MinorOperatingSystemVersion\t要求操作系统最低版本号的副版本号\t" << NTOPT_MinorOperatingSystemVersion() << '\n';
	return;
}

void PEinfo_ouput::NTO_info_2() {
	system("cls");
	cout << "name\t\t\t\tmeaning\t\t\t\t\tvalue\n\n";

	cout << "MajorImageVersion\t\t可运行于操作系统的主版本号\t\t" << NTOPT_MajorImageVersion() << '\n';
	cout << "MinorImageVersion\t\t可运行于操作系统的次版本号\t\t" << NTOPT_MinorImageVersion() << '\n';
	cout << "MajorSubsystemVersion\t\t要求最低子系统版本的主版本号\t\t" << NTOPT_MajorSubsystemVersion() << '\n';
	cout << "MinorSubsystemVersion\t\t要求最低子系统版本的次版本号\t\t" << NTOPT_MinorSubsystemVersion() << '\n';
	cout << "Win32VersionValue\t\t莫须有字段，不被病毒利用的话一般为0\t" << NTOPT_Win32VersionValue() << '\n';
	cout << "SizeOfImage\t\t\t映像装入内存后的总尺寸\t\t\t" << NTOPT_SizeOfImage() << '\n';
	cout << "SizeOfHeaders\t\t\t所有头+区块表的尺寸大小\t\t\t" << NTOPT_SizeOfHeaders() << '\n';
	cout << "CheckSum\t\t\t映像的校检和\t\t\t\t" << NTOPT_CheckSum() << '\n';
	cout << "Subsystem\t\t\t可执行文件期望的子系统\t\t\t" << NTOPT_Subsystem() << '\n';
	cout << "DllCharacteristics\t\tDllMain()函数何时被调用,默认为0\t\t" << NTOPT_DllCharacteristics() << '\n';
	cout << "SizeOfStackReserve\t\t初始化时的栈大小\t\t\t" << NTOPT_SizeOfStackReserve() << '\n';
	cout << "SizeOfStackCommit\t\t初始化时实际提交的栈大小\t\t" << NTOPT_SizeOfStackCommit() << '\n';
	cout << "SizeOfHeapReserve\t\t初始化时保留的堆大小\t\t\t" << NTOPT_SizeOfHeapReserve() << '\n';
	cout << "SizeOfHeapCommit\t\t初始化时实际提交的堆大小\t\t" << NTOPT_SizeOfHeapCommit() << '\n';
	cout << "LoaderFlags\t\t\t与调试有关,默认为0\t\t\t" << NTOPT_LoaderFlags() << '\n';
	return;
}
//共29+1条，每页14条，附带提示信息

void PEinfo_ouput::NTO_info_3() {
	system("cls");
	cout << "name\t\t\tmeaning\t\t\t\tRVA\t,Size\n\n";

	cout << "DataDirectory[0]\t导入表\t\t\t\t" << this->NTOPT_DataDirectory(0) << '\n';
	cout << "DataDirectory[1]\t导出表\t\t\t\t" << this->NTOPT_DataDirectory(1) << '\n';
	cout << "DataDirectory[2]\t资源\t\t\t\t" << this->NTOPT_DataDirectory(2) << '\n';
	cout << "DataDirectory[3]\t异常(具体资料不详)\t\t" << this->NTOPT_DataDirectory(3) << '\n';
	cout << "DataDirectory[4]\t安全(具体资料不详)\t\t" << this->NTOPT_DataDirectory(4) << '\n';
	cout << "DataDirectory[5]\t重定位表\t\t\t" << this->NTOPT_DataDirectory(5) << '\n';
	cout << "DataDirectory[6]\t调试信息\t\t\t" << this->NTOPT_DataDirectory(6) << '\n';
	cout << "DataDirectory[7]\t版权信息\t\t\t" << this->NTOPT_DataDirectory(7) << '\n';
	cout << "DataDirectory[8]\tGLOBALPTR(具体资料不详)\t\t" << this->NTOPT_DataDirectory(8) << '\n';
	cout << "DataDirectory[9]\tTLS(Thread Local Storage)\t" << this->NTOPT_DataDirectory(9) << '\n';
	cout << "DataDirectory[A]\tLOAD_CONFIG(具体资料不详)\t" << this->NTOPT_DataDirectory(10) << '\n';
	cout << "DataDirectory[B]\tBOUND_IMPORT(具体资料不详)\t" << this->NTOPT_DataDirectory(11) << '\n';
	cout << "DataDirectory[C]\tIAT(导入函数地址表)\t\t" << this->NTOPT_DataDirectory(12) << '\n';
	cout << "DataDirectory[D]\tDELAY_IMPORT(具体资料不详)\t" << this->NTOPT_DataDirectory(13) << '\n';
	cout << "DataDirectory[E]\tCOM_DESRRIPTOR(具体资料不详)\t" << this->NTOPT_DataDirectory(14) << '\n';
	cout << "DataDirectory[F]\t未使用\t\t\t\t" << this->NTOPT_DataDirectory(15) << '\n';
	return;
}
//最后的十六位数组


void PEinfo_ouput::main_menu() {
	string file_name;
	while (1) {
		cout << "请将本程序与需要打开的文件置于同一目录下\n"
			 << "请输入文件名称:";
		cin >> file_name;
		this->init(file_name.c_str());
		if (!this->NT_offset()) {
			system("cls");
			cout << "无法打开指定文件!\n请确定文件名或文件路径正确\n\n";
			continue;
		}
		break;
	}
	int a = 0;
	while (1) {
		system("cls");
		cout << "文件名:" << file_name << "\n主要信息:\n";
		cout << "文件位数:  ";
		if (this->if32())cout << "32bit\t\t";
		else             cout << "64bit\t\t";
		cout << "区段数量:  " << NTF_NumberOfSections() << '\n';
		cout << "NT头偏移:  " << e_lfanew() << "\t\t";
		cout << "首选装载地址:  " << NTOPT_ImageBase() << "\n\n\n";
		cout << "按键查看详细信息:\nd:Dos头\nf:NT签名与NT文件头\no:NT可选头\nh:节区头数组\nESC:退出程序\n\nWaitng ketboard input...";

		switch_loop:
		switch (a) {
		    case 'D':case 'd':this->DOS_info(); a = 0; break;
		    case 'F':case 'f':this->NTFILE_info(); a = 0; break;
		    case 'O':case 'o':this->NTOPT_info(); a = 0; break;
			case 'H':case 'h':this->SH_info(); a = 0; break;
			case 27:return;
			default:a = getch(); goto switch_loop;//我不知道咋整的，switch语句的default居然会退出switch
		}
	}
}//主菜单，打开文件，显示主要信息，切换界面

void PEinfo_ouput::SH_info() {
	system("cls");
	int page_arr = 0;
	int con = 0;
	this->SH_pages(page_arr);
	while (1) {
		this->SH_pages(page_arr);
	switch_loop:
		switch (getch()) {
		    case 27:return;
			case 224:switch (getch()) {
			    case 75:if (page_arr)--page_arr; break;
				case 77:if ((page_arr + 1) < this->Numbers_of_sections())++page_arr; break;
			}break;
			default:goto switch_loop;
		}
	}
}

void  PEinfo_ouput::SH_pages(int array) {
	system("cls");
	cout << "SECTION_HEADER[" << array << "]\tmeaning\t\t\t\tvalue\n\n";
	cout << "name\t\t\t节区名\t\t\t\t" << SH_Name(array) << '\n';//int:指明访问数组中的第i个成员
	cout << "VirtualSize\t\t内存中节区大小\t\t\t" << SH_Misc(array) << '\n';//物理地址或内存中节区所占大小的union，都是双字
	cout << "VirtualAddress\t\t内存中节区起始位置(RVA)\t\t" << SH_VirtualAddress(array) << '\n';
	cout << "SizeOfRawData\t\t磁盘文件中节区大小\t\t" << SH_SizeOfRawData(array) << '\n';
	cout << "PointerToRawdata\t磁盘文件中节区起始位置\t\t" << SH_PointerToRawData(array) << '\n';
	cout << "PointerToRelocations\t在OBJ文件中使用m\,重定位的偏移\t" << SH_PointerToRelocations(array) << '\n';
	cout << "PointerToLinenumbers\t行号表的偏移(供调试使用)\t" << SH_PointerToLinenumbers(array) << '\n';
	cout << "NumberOfRelocations\t在OBJ文件中使用，重定位项数目\t" << SH_NumberOfRelocations(array) << '\n';
	cout << "NumberOfLinenumbers\t行号表中行号的数目\t\t" << SH_NumberOfLinenumbers(array) << '\n';
	cout << "Characteristics\t\t节属性如可读,可写,可执行等\t" << SH_Characteristics(array) << '\n';
	cout << "\n当前第" << array+1 << "页,共" << this->Numbers_of_sections() << "页\n";
	cout << "按键查看详细信息:\n←:上一页\n→:下一页\nESC:返回上一级\n\nWaitng ketboard input...";
	return;
}