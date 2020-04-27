#include "String.h"

String::String()//default constructor
{
	str = new char{ '\0' };
	size = 0;
}

String::String(const String& gelen)
{
	if (gelen.size != size)
	{
		delete str;
		str = new char[size+1];
	}
	size = gelen.size;
	for (size_t i = 0; i < size; ++i) {
		str[i] = gelen.str[i];
		//gelen dizinin t�m elemanlar�n� yeni olu�an diziye atad�k
	}
	str[size] = '\0';
}


String::String(const size_t s, const char gelen)
{
	size = s;
	str = new char[size + 1];
	str[size] = '\0';
	for (size_t i = 0; i < size; ++i) {
		str[i] = gelen;
	}
}

String::String(const char* gelen)
{
	helpfonk(gelen);
}

String::String(const char gelen)
{
	size = 1;
	str = new char[size + 1];
	str[size-1] = gelen;
	str[size] = '\0';
}

const String& String::operator=(const char* gelen)
{
	del();
	helpfonk(gelen);
	return *this;
}

const String& String::operator=(const char gelen)
{
	del();
	size = 1;
	str = new char[size + 1];
	str[size] = gelen;
	str[size] = '\0';
	return *this;
}

const String& String::operator=(const String& gelen)
{
	if (&gelen != this) {
		//e�er gelenin adresi nesnemizle ayn� de�ilse yani kendini kendine atam�yorsak
		if (size != gelen.size) { //gelenin boyutu �uanki diziden farkl�ysa
			del();
			size = gelen.size; //yeni boyutu belirledik
			str = new char[size]; // yeni boyut kadar yer ald�k
		}
		//bu kontrol�n amac�, e�er boyutlar ayn� ise silip yeni yer almakla u�ra�mamakt�r
		else if (size == 0)
		{
			str = new char{ '\0' };
			return *this;
		}
		for (size_t i = 0; i <= size; ++i) { //kopyalanacak dizinin t�m elemanlar�n� yeni diziye atad�k
			str[i] = gelen.str[i];
		}
		
	}
	return *this; // a=b=c tarz� bir e�itlik yapmak i�in kendini d�nd�rd�k
}

const String& String::operator+=(const String& gelen)
{
	size_t newsize = size + gelen.size;
	char* temp = new char[size+1];
	for (size_t i = 0; i < size; i++)
		temp[i] = str[i];
	del();
	str = new char[newsize+1];
	size_t i;
	for (i = 0; i < size; i++)
		str[i] = temp[i];
	if (gelen.size == 0)
		str[size] = '\0';
	else
		for (size_t a=0;a<=gelen.size; ++a) {
			
			str[a+size] = gelen.str[a];
		
		}
	size = newsize;
	return *this;
}

const String& String::operator+=(const char* a)
{
	String gelen = a;
	*this += gelen;
	return *this;
}

const String& String::operator+=(const char a)
{
	String gelen = a;
	*this += gelen;
	return *this;
}

const String String::operator+(const String& gelen)
{
	String temp = *this;
	temp+= gelen;
	return temp;
}

const String String::operator+(const char* a)
{
	String temp = *this;
	return temp + a;
}

const String String::operator+(const char a)
{
	String temp = *this;
	temp += a;

	return temp;
}

char String::operator[](int i) const
{
	return str[i];
}

char& String::operator[](int i)
{
	return str[i];
}
inline void String::helpfonk(const char* gelen) {

	size_t i = 0;

	if (gelen[0] == '\0')
		size = 0;
	else {
		while (gelen[i] != '\0')
		{
			size = i + 1;
			++i;
		}
	}

	str = new char[size + 1];

	if (size != 0)
	{
		for (size_t i = 0; i < size; ++i)
			str[i] = gelen[i];
	}
	str[size] = '\0';
}

int String::getSize() const
{
	return size;
}

void String::del()
{
	if (str) 
	{
		if (size == 0)
		{
			delete str;
		}

		else if (size > 0)
		{
			delete[] str;
		}
	}
}

ostream& operator<<(std::ostream& yaz, const String& nesne)
{
	yaz << nesne.str;

	return yaz;
}

