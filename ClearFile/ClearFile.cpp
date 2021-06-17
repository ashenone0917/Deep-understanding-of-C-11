// ClearFile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
#include <sstream>

template<typename... Elements> class DbgLog;
template<typename Head,typename... Tail>
class DbgLog<Head, Tail...> {
public:
	
private:
	std::wostringstream oss_{};
};

int main()
{
	//auto ret = MoveFileEx(L"D:/xmltest_copy", L"D:/xmltest", 
	//	MOVEFILE_REPLACE_EXISTING | MOVEFILE_COPY_ALLOWED/*MOVEFILE_WRITE_THROUGH*/);
	//std::wstring temp1 = L"D:\\xmltest\\testfile.txt";
	//std::wstring temp = L"D:\\xmltest";
	//std::wstring temp2 = temp1.substr(temp.length());
	SHFILEOPSTRUCTW fo;
	fo.hwnd = NULL;
	fo.wFunc = FO_COPY;
	fo.pFrom = L"D:\\xmltest";
	fo.pTo = L"D:\\xmltest_1";
	fo.fFlags = (FOF_NO_UI);
	fo.fAnyOperationsAborted = FALSE;
	fo.hNameMappings = NULL;
	fo.lpszProgressTitle = NULL;

	DWORD dwError = (DWORD)::SHFileOperationW(&fo);
    HANDLE handle = CreateFile(L"D:\\testdir\\testfile.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    DWORD Bytes = 0;
    WriteFile(handle, "1234\n5678", 9, &Bytes, NULL);
    ::CloseHandle(handle);
    std::cout << "Hello World!\n";
}