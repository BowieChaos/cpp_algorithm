#pragma once
#include <iostream>

class String {
public:
	String(const char* str = NULL) // 普通构造函数
	{
		if (str == NULL) {
			m_data = NULL;
			m_len = 0;
			return;
		}
		m_len = Strlen(str);
		m_data = new char[m_len + 1];
		Strcpy(m_data, str);
	}
	String(const String& other) // 拷贝构造函数
	{
		if (other.m_data == NULL)
			return;
		m_len = other.m_len;
		m_data = new char[m_len + 1];
		Strcpy(m_data, other.m_data);
	}
	~String(void) // 析构函数
	{
		m_len = 0;
		delete[] m_data;
		m_data = NULL;
	}
	String& operator=(const String& other) // 赋值函数
	{
		if (this != &other) {
			if (m_len != other.m_len) {
				delete[] m_data;
				m_len = other.m_len;
				m_data = new char[m_len + 1];
			}
			Strcpy(m_data, other.m_data);
		}
		return *this;
	}

	int Strlen(const char* StrDest) {
		int i;
		i = 0;
		while ((*StrDest++) != '\0') {
			i++;
		}
		return i;
	}

	char* Strcpy(char* strDest, const char* strSrc) {
		if ((NULL == strDest) || (NULL == strSrc))
			throw "Invalid argument(s)";
		char* strDestCopy = strDest;
		while ((*strDestCopy++ = *strSrc++) != '\0')
			;
		return strDest;
	}

private:
	char* m_data;
	size_t m_len;
};
