#include <iostream>

struct String
{
private:

	size_t m_size = 0;
	char* m_str = nullptr;

public:

	friend std::ostream& operator << (std::ostream& out, const String& str);
	friend std::istream& operator >> (std::istream& in, String& str);

	String(size_t c, size_t size) = delete;


	explicit String(const char* str) : m_size(strlen(str)), m_str(new char[m_size + 1])
	{
		std::copy(str, str + m_size + 1, m_str);
	}


	explicit String(char c, size_t size) : m_size(size), m_str(new char[size + 1])
	{
		std::fill(m_str, m_str + m_size, c);
		m_str[size] = '\0';
	}


	
	~String()
	{
		if (m_str != nullptr)
			delete[] m_str;
	}



	String(const String& other) : String(other.m_str) {}


	String& operator = (const String& other)
	{
		String tmp = other;
		std::swap(this->m_size, tmp.m_size);
		std::swap(this->m_str, tmp.m_str);

		return *this;
	}

	String& operator += (const String other)
	{
		size_t size = this->m_size + other.m_size;
		String tmp('q', size);

		for (int i = 0; i < this->m_size; i++)
		{
			tmp.m_str[i] = this->m_str[i];
		}
		for (int i = 0; i < other.m_size; i++)
		{
			tmp.m_str[i + this->m_size] = other.m_str[i];
		}

		std::swap(this->m_size, tmp.m_size);
		std::swap(this->m_str, tmp.m_str);

		return *this;
	}

	String operator + (const String& other) const
	{
		String tmp = *this;
		tmp += other;
		return tmp;

	}

	String operator + (const char* other) const
	{
		String tmp1 = *this;
		String tmp2(other);
		tmp1 += tmp2;
		return tmp1;
	}

	char& operator [] (size_t el)
	{
		return this->m_str[el];
	}

	bool operator > (const String& other)
	{
		if (this->m_size > other.m_size) { return true; }
		else if (this->m_size < other.m_size) { return false; }
		else if (this->m_size == other.m_size)
		{
			for (int i = 0; i < this->m_size; i++)
			{
				if (int(this->m_str[i]) > int(other.m_str[i])) { return true; }
				if (int(this->m_str[i]) < int(other.m_str[i])) { return false; }
				if (int(this->m_str[i]) == int(other.m_str[i])) { continue; }
			}

			return false;
		}
	}

	bool operator < (const String& other)
	{
		if (this->m_size < other.m_size) { return true; }
		else if (this->m_size > other.m_size) { return false; }
		else if (this->m_size == other.m_size)
		{
			for (int i = 0; i < this->m_size; i++)
			{
				if (int(this->m_str[i]) < int(other.m_str[i])) { return true; }
				if (int(this->m_str[i]) > int(other.m_str[i])) { return false; }
				if (int(this->m_str[i]) == int(other.m_str[i])) { continue; }
			}

			return false;
		}
	}

	bool operator == (const String& other)
	{
		if (this->m_size != this->m_size) { return false; }
		for (int i = 0; i < this->m_size; i++)
		{
			if (this->m_str[i] != other.m_str[i]) { return false; }
		}
		return true;
	}

	size_t length()
	{
		return m_size;
	}

	char* c_str()
	{
		return m_str;
	}

	size_t find(char tmp)
	{
		for (int i = 0; i < this->m_size; i++)
		{
			if (this->m_str[i] == tmp) { return i; }
		}
		return -1;
	}

	void Print() const
	{
		for (int i = 0; i < this->m_size; i++)
			std::cout<< m_str[i];
		std::cout << std::endl;
	}

};


std::ostream& operator << (std::ostream& out, const String& str)
{

	for (int i = 0; i < str.m_size; i++)
	{
		out<<str.m_str[i];
	}

	return out;
}

std::istream& operator >> (std::istream& in, String& str)
{
	char* tmp = new char[10000];

	in >>* (tmp);
	size_t ind = -1;

	for (int i = 0; i < 10000; i++)
	{
		if (tmp[i] == '\0')
		{
			ind = i;
			break;
		}
	}

	str.m_size = ind + 1;
	delete[] str.m_str;

	str.m_str = new char[str.m_size + 1];
	std::copy(tmp, tmp + ind + 1, str.m_str);
	delete[] tmp;

	return in;
}

int main()
{
	String s1("Hello, world!");
	std::cout << s1 << std::endl;
	String s2('a', 3);
	std::cout << s2 << std::endl;
	String s3("Hello, world!");
	s3 = s2 + s1 + "hhh";
	std::cout << s3 << std::endl;

	std::cout << s1[2] << std::endl;
	std::cout << (s1 > s2) << std::endl;
	std::cout << s1.find('o') << std::endl;

	std::cin >> s2;
	std::cout << s2 << std::endl;
}