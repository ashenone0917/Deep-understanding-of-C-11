// SplitString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>


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
int main()
{
    unsigned int n = -1;
    int m = n;
    std::wstring s1 = L"DCubeAgent_51_1";
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

