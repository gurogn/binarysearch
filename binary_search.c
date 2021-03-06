// binary_search.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "malloc.h"
#include "stdio.h"
int binary_search(int data_list[], int to_search);
static void start_test();
int max_count = 0;
int main()
{
	start_test();
    return 0;
}

static void start_test() 
{
	int t = 0;
	int *data_list = NULL;
	while (scanf("%d %d", &max_count, &t) != EOF)
	{
		data_list = malloc(max_count * sizeof(int));
		for (int i = 0; i < max_count; i++)
		{
			data_list[i] = 10 * i;
		}
		printf("index is %d for value %d\n",binary_search(data_list, t),t);
		free(data_list);
	}
}
int binary_search(int *data_list, int to_search) 
{
	if (NULL == data_list)
		return -1;
	int upper = max_count - 1;
	int low = 0;
	int cur = 0;
	while (low <= upper) 
	{
		cur = (low + upper) / 2;
		if (data_list[cur] > to_search) 
		{
			upper = cur - 1;
		}
		else if(data_list[cur] < to_search)
		{
			low = cur + 1;
		}
		else
		{
			return cur;
		}
	}
	return -1;
}

