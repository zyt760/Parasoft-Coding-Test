#include <stdio.h>
#include <stdlib.h>
int reverse(int x);
int main()
{
	int x,a=0;
	while(1)
	{
		printf("a=");
		scanf("%d",&x);
		int r=reverse (x);
		printf("%d\n",r);	
	}
}
int reverse(int x)
{
	int a=0;
	while(x != 0)
    {	
		if(a > 214748364 || a < -214748364)
		return 0;
		if(a == 214748364 && x > 7)
        return 0;
        if(a == -214748364 && x < -8)
        return 0;
        a = a * 10 + x % 10;
        x /= 10;   
    }
    return a;
}
