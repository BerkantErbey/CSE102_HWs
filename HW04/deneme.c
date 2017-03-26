#include <stdio.h>


int main()
{
	int num,ret;
	do
	{
		scanf("%d",&num);
		if (num > 0 && num < 100000)
		{
			ret = 1;
		}
		if(num < 0)
		{
			ret = 0;
		}
	}while(num >99999);
		
	printf("%d\n",ret);

	return 0;
}