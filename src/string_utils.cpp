#include "string_utils.h"

/**
 * @brief 分隔字符串
 * @param str 
 * @param delim 
 * @return vector<string> 
 */
vector<string> StringUtils::split(const string& str, const string& delim) {
	vector<string> res;
    if ("" == str){
        return res;
    }
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1] ;
	strcpy(strs, str.c_str()); 

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);

    while (p) {
        string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, d);
    }
	return res;
}

/**
 * @brief string 转换 wstring
 * @param str 
 * @return wstring 
 */
wstring StringUtils::string2wstring(const string& str) {
    if (str.empty()) {
        return L"";
    }
    unsigned len = str.size() + 1;
    setlocale(LC_CTYPE, "en_US.UTF-8");
    unique_ptr<wchar_t[]> p(new wchar_t[len]);
    mbstowcs(p.get(), str.c_str(), len);
    wstring w_str(p.get());
    return w_str;
}
 
/**
 * @brief wstring 转换 string
 * @param w_str 
 * @return string 
 */
string StringUtils::wstring2string(const wstring& w_str) {
    if (w_str.empty()) {
        return "";
    }
    unsigned len = w_str.size() * 4 + 1;
    setlocale(LC_CTYPE, "en_US.UTF-8");
    unique_ptr<char[]> p(new char[len]);
    wcstombs(p.get(), w_str.c_str(), len);
    string str(p.get());
    return str;
}

/*******************************************************
    函数名称：UTF2Uni
    函数功能：utf-8转Unicode（跨平台）
    输入参数：
        src：utf-8编码格式的字符指针
        t：Unicode编码格式的宽字符串
    输出参数：无
    返 回 值：0表示执行成功
*******************************************************/
int UTF2Uni(const char* src, std::wstring &t)
{
    if (src == NULL) 
    {
        return -1;
    }
    int size_s = strlen(src);
    int size_d = size_s * 2;         
    wchar_t *des = new wchar_t[size_d];
    memset(des, 0, size_d * sizeof(wchar_t));

    int s = 0, d = 0;
    //设为true时，跳过错误前缀
    bool toomuchbyte = true; 

    while (s < size_s && d < size_d)
    {
        unsigned char c = src[s];
        if ((c & 0x80) == 0) 
        {
            des[d++] += src[s++];
        } 
        else if((c & 0xE0) == 0xC0)  ///< 110x-xxxx 10xx-xxxx
        {
            wchar_t &wideChar = des[d++];
            wideChar  = (src[s + 0] & 0x3F) << 6;
            wideChar |= (src[s + 1] & 0x3F);

            s += 2;
        }
        else if((c & 0xF0) == 0xE0)  ///< 1110-xxxx 10xx-xxxx 10xx-xxxx
        {
            wchar_t &wideChar = des[d++];

            wideChar  = (src[s + 0] & 0x1F) << 12;
            wideChar |= (src[s + 1] & 0x3F) << 6;
            wideChar |= (src[s + 2] & 0x3F);

            s += 3;
        } 
        else if((c & 0xF8) == 0xF0)  ///< 1111-0xxx 10xx-xxxx 10xx-xxxx 10xx-xxxx 
        {
            wchar_t &wideChar = des[d++];

            wideChar  = (src[s + 0] & 0x0F) << 18;
            wideChar  = (src[s + 1] & 0x3F) << 12;
            wideChar |= (src[s + 2] & 0x3F) << 6;
            wideChar |= (src[s + 3] & 0x3F);

            s += 4;
        } 
        else 
        {
            wchar_t &wideChar = des[d++]; ///< 1111-10xx 10xx-xxxx 10xx-xxxx 10xx-xxxx 10xx-xxxx 

            wideChar  = (src[s + 0] & 0x07) << 24;
            wideChar  = (src[s + 1] & 0x3F) << 18;
            wideChar  = (src[s + 2] & 0x3F) << 12;
            wideChar |= (src[s + 3] & 0x3F) << 6;
            wideChar |= (src[s + 4] & 0x3F);
            s += 5;
        }
    }

    t = des;
    delete[] des;
    des = NULL;

    return 0;
} 
/*******************************************************
    函数名称：Uni2UTF
    函数功能：Unicode转utf-8（跨平台）
    输入参数：
        wchar：Unicode编码格式的宽字符数组
        utf8：utf-8编码格式的字符指针
    输出参数：无
    返 回 值：utf-8编码格式的字符指针长度
*******************************************************/
int Uni2UTF(wchar_t wchar, char *utf8)
{
    if (utf8 == NULL) {
        return -1;
    }
    int len = 0;
    int size_d = 8;

    if (wchar < 0x80)
    {  //
        //length = 1;
        utf8[len++] = (char)wchar;
    }
    else if(wchar < 0x800)
    {
        //length = 2;

        if (len + 1 >= size_d)
            return -1;

        utf8[len++] = 0xc0 | ( wchar >> 6 );
        utf8[len++] = 0x80 | ( wchar & 0x3f );
    }
    else if(wchar < 0x10000 )
    {
        //length = 3;
        if (len + 2 >= size_d)
            return -1;

        utf8[len++] = 0xe0 | ( wchar >> 12 );
        utf8[len++] = 0x80 | ( (wchar >> 6) & 0x3f );
        utf8[len++] = 0x80 | ( wchar & 0x3f );
    }
    else if( wchar < 0x200000 ) 
    {
        //length = 4;
        if (len + 3 >= size_d)
            return -1;

        utf8[len++] = 0xf0 | ( (int)wchar >> 18 );
        utf8[len++] = 0x80 | ( (wchar >> 12) & 0x3f );
        utf8[len++] = 0x80 | ( (wchar >> 6) & 0x3f );
        utf8[len++] = 0x80 | ( wchar & 0x3f );
    }
    return len;
}

/*******************************************************
    函数名称：s2ws
    函数功能：string转wstring（跨平台），不涉及编码格式的转换
    输入参数：
        s：Unicode编码格式的string
    输出参数：无
    返 回 值：Unicode编码格式的wstring
*******************************************************/
std::wstring s2ws(const std::string& s)
{
    #if (defined WIN32) ||  (defined _WIN32)  
        setlocale(LC_ALL,"chs");  
    #else  
        setlocale(LC_ALL,"zh_CN.gbk");  
    #endif
    const char* _Source = s.c_str();
    size_t _Dsize = s.size() + 1;
    wchar_t *_Dest = new wchar_t[_Dsize];
    wmemset(_Dest, 0, _Dsize);
    mbstowcs(_Dest,_Source,_Dsize);
    std::wstring result = _Dest;
    delete []_Dest;
    setlocale(LC_ALL, "C");
    return result;
}
/*******************************************************
    函数名称：ws2s
    函数功能：wstring转string（跨平台），不涉及编码格式的转换
    输入参数：
        ws：Unicode编码格式的wstring
    输出参数：无
    返 回 值：Unicode编码格式的string
*******************************************************/
std::string ws2s(const std::wstring& ws)
{
    std::string curLocale = setlocale(LC_ALL, NULL); 
    #if (defined WIN32) ||  (defined _WIN32)  
        setlocale(LC_ALL,"chs");  
    #else  
        setlocale(LC_ALL,"zh_CN.gbk");  
    #endif 
    const wchar_t* _Source = ws.c_str();
    size_t _Dsize = 2 * ws.size() + 1;
    char *_Dest = new char[_Dsize];
    memset(_Dest,0,_Dsize);
    wcstombs(_Dest,_Source,_Dsize);
    std::string result = _Dest;
    delete []_Dest;
    setlocale(LC_ALL, curLocale.c_str());
    return result;
} 

