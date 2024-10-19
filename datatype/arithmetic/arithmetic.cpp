#include<bits/stdc++.h>
#include"Stack.h"

using namespace std;

char buffer[2048];

int main()
{	
	scanf("%s", buffer);

	for(int i = 0; buffer[i] != '\0'; i++)
	{
		if(buffer[i] == '(');
		else if(buffer[i] == '+')
			op_push(buffer[i]);
		else if(buffer[i] ==  '*')
			op_push(buffer[i]);
		else if(buffer[i] == ')')
		{
			char op = op_pop();
			if(op == '+')
			{
				int temp1 = num_pop();
				int temp2 = num_pop();
				int temp = temp1 + temp2;
				num_push(temp);
			}
			else if(op == '*')
			{
				int temp1 = num_pop();
				int temp2 = num_pop();
				int temp = temp1 * temp2;
				num_push(temp);
			}
		}
		else
			num_push((buffer[i] - '0'));
		printf("%d \n", num_pop());
	}	
	
	return 0;
}
