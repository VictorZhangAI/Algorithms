#include<bits/stdc++.h>
using namespace std;
struct String
{
	char* value;
	int offset;
	int length;
	int hash;

	int len()
	{
		return length;
	}

	char charAt(int i)
	{
		return value[i + offset];
	}

	struct String build_string(int offset, int length, char* value)
	{
		struct String str;
		str.offset = offset;
		str.length = length;
		str.value = (char*)realloc(str.value, 16 + length * sizeof(char));
		str.value = value;
		return str;
	}

	struct String substring(int from, int to)
	{
		return build_string(offset + from, to - from, value);
	}

};

struct String str;

int main()
{
	str.build_string(0, 27, (char*)"An example of the string.");
	printf("%s\n", str.value);
	return 0;
}
