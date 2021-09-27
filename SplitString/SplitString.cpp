// SplitString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <Windows.h>
#include <sstream>
template <typename TString>
std::vector<TString> SplitString(TString& tstring,typename TString::const_pointer delim) {
    if (tstring.empty()) return std::vector<TString>();

    typename TString::size_type start = 0;
    typename TString::size_type end = 0;
    typename TString::size_type size = tstring.size();
    std::vector<TString> retVal{};
    do
    {
       end = tstring.find(delim, start);
       if (end == TString::npos) end = size;
       if(start != end) retVal.emplace_back(tstring.substr(start, end - start));
       start = end + 1;
    } while (start < size);

    return std::move(retVal);
}
TCHAR g_strCmdPath[] = L"C:\\Program Files\\DataCloak_DCube\\Bin\\DcubeBrowser\\DacsBrowser.exe --create_browser --url=www.baidu.com";

std::vector<std::wstring> FindFlagsDirSaas() {
    std::vector<std::wstring> arrayConfig;
    arrayConfig.reserve(3);
    WIN32_FIND_DATAW        FindData = { 0 };

    HANDLE hFindHandle = INVALID_HANDLE_VALUE;

    const std::wstring&& wstrRule = L"D:\\Git Workspace\\Deep-understanding-of-C-11\\SplitString\\*.ddcube_2_3";
    hFindHandle = ::FindFirstFileW(wstrRule.c_str(), &FindData);

    if (hFindHandle == INVALID_HANDLE_VALUE) {
        return arrayConfig;
    }

    do {
        // 过滤文件夹
        if ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            continue;
        arrayConfig.emplace_back(FindData.cFileName);
        memset(&FindData, 0, sizeof(FindData));
    } while (FindNextFileW(hFindHandle, &FindData));
    FindClose(hFindHandle);

    return arrayConfig;
}
int main()
{
    std::wstring temp1 = L"client.ovpn.ddcube_2_3";
    auto index = temp1.find(L".ddcube_2_3");
    auto temp2 = temp1.substr(0, index);
    auto filearray = FindFlagsDirSaas();
    
    unsigned int n = -1;
    int m = n;
    std::wstring s1 = L"DCubeAgent_51_1_";
    std::wstring s3;
    for (int i = 0; i < s1.length(); i++) {
        wchar_t leh;
        ((char*)(&leh))[0] = ((char*)(&s1[i]))[1];
        ((char*)(&leh))[1] = ((char*)(&s1[i]))[0];
        s3 += leh;
    }
    auto reuslt = SplitString(s1, L"_");
    reuslt = SplitString(s1, L",");
}

