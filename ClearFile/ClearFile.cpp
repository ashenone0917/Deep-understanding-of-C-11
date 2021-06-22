// ClearFile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
#include <sstream>
#include <shlwapi.h>
template<typename... Elements> class DbgLog;
template<typename Head,typename... Tail>
class DbgLog<Head, Tail...> {
public:
	
private:
	std::wostringstream oss_{};
};

std::wstring GetCurrentProcessPath() {
	std::wstring ret{};
	ret.resize(MAX_PATH + 1);
	if (::GetModuleFileName(NULL, const_cast<WCHAR*>(ret.c_str()), MAX_PATH)) {
		ret = ret.substr(0, ret.find_last_of(L"\\"));
	}
	return std::move(ret);
}

std::wstring GetPathFromCommandLine(const std::wstring& command_line) {
	if (command_line.find(L"\"") != std::wstring::npos) {
		int argc = 0;
		auto commandlineargv = CommandLineToArgvW(command_line.c_str(), &argc);
		if (commandlineargv != NULL) return commandlineargv[0];
		return L"";
	}

	auto length = command_line.length();
	if (command_line[length - 1] == L'\\') return L"";

	int index1 = command_line.find_last_of(L"\\") + 1;
	auto substr = command_line.substr(index1, command_line.length());
	int index2 = substr.length();
	do
	{
		auto index3 = substr.find_last_of(L" ");
		if (index3 != std::wstring::npos) {
			substr = substr.substr(0, index3);
			index2 = index3;
		}
		else {
			break;
		}
	} while (true);

	return command_line.substr(0, index1 + index2);
}

int main()
{
	auto current = GetPathFromCommandLine(std::wstring(L"C:\\Windows\\system32\\svchost.exe -k -n"));
	int argc = 0;
	std::wstring line = L"C:\Windows\system32\svchost.exe -k netsvcs";
	auto commandlineargv = CommandLineToArgvW(L"C:\Windows\system32\svchost.exe -k netsvcs", &argc);
	auto path = commandlineargv[0];
	auto len = (sizeof(L"aaa") - sizeof(WCHAR)) >> 1;
	auto result = PathFindFileName(L"C:\\qqq\\aaa.txt");
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