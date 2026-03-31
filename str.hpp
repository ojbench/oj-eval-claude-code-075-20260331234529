#include <algorithm>
#include <cstring>
#include <vector>

class str
{
private:
	char *data;
	size_t length;

	void copy_from(const char *s)
	{
		if (s == nullptr)
		{
			data = new char[1];
			data[0] = '\0';
			length = 0;
		}
		else
		{
			length = strlen(s);
			data = new char[length + 1];
			strcpy(data, s);
		}
	}

public:
	str()
	{
		data = new char[1];
		data[0] = '\0';
		length = 0;
	}

	str(const char &c)
	{
		length = 1;
		data = new char[2];
		data[0] = c;
		data[1] = '\0';
	}

	str(const char *&& s_)
	{
		copy_from(s_);
	}

	str &operator=(const char *&& s_)
	{
		if (data != s_)
		{
			delete[] data;
			copy_from(s_);
		}
		return *this;
	}

	str(const str &other)
	{
		length = other.length;
		data = new char[length + 1];
		strcpy(data, other.data);
	}

	str &operator=(const str &other)
	{
		if (this != &other)
		{
			delete[] data;
			length = other.length;
			data = new char[length + 1];
			strcpy(data, other.data);
		}
		return *this;
	}

	char &operator[](size_t pos)
	{
		return data[pos];
	}

	size_t len() const
	{
		return length;
	}

	str join(const std::vector<str> &strs) const
	{
		if (strs.empty())
		{
			return str();
		}

		// Calculate total length needed
		size_t total_len = 0;
		for (size_t i = 0; i < strs.size(); i++)
		{
			total_len += strs[i].length;
			if (i < strs.size() - 1)
			{
				total_len += length;
			}
		}

		// Create result
		str result;
		delete[] result.data;
		result.length = total_len;
		result.data = new char[total_len + 1];

		// Build result string
		size_t pos = 0;
		for (size_t i = 0; i < strs.size(); i++)
		{
			strcpy(result.data + pos, strs[i].data);
			pos += strs[i].length;
			if (i < strs.size() - 1)
			{
				strcpy(result.data + pos, data);
				pos += length;
			}
		}
		result.data[total_len] = '\0';

		return result;
	}

	str slice(size_t l, size_t r) const
	{
		if (l >= length || r > length || l >= r)
		{
			return str();
		}

		str result;
		delete[] result.data;
		result.length = r - l;
		result.data = new char[result.length + 1];

		for (size_t i = 0; i < result.length; i++)
		{
			result.data[i] = data[l + i];
		}
		result.data[result.length] = '\0';

		return result;
	}

	~str()
	{
		delete[] data;
	}
};
