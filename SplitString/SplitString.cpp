// SplitString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
template <typename TString>
std::vector<TString> SplitString(TString& tstring,TString& delim) {
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
    std::wstring s1 = L"111:1222:421412:53215:11111:8786";
    std::wstring s2 = L":";
    auto reuslt = SplitString(s1, s2);
    s2 = L",";
    reuslt = SplitString(s1, s2);
}

