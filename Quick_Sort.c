#include<stdio.h>
#include<conio.h>

void quick_sort(int a[] , int L , int H)
{
	int temp , pivot = a[L] , low = L+1 , high = H;

	while(low <= high)
	{
		while(a[low] < pivot)
		{
			low++;
		}
		while(a[high] > pivot)
		{
			high--;
		}
		if(low <= high)
		{
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
		}
	}
	temp = a[L];
	a[L] = a[high];
	a[high] = temp;

	if(L < high)
	{
		quick_sort(a,L,high-1);
	}
	if(low < H)
	{
		quick_sort(a,low,H);
	}
}

void main()
{
	int a[50], i , n;
	

	printf("How many elemnts do you want ot enter in an array\n");
	scanf("%d",&n);

	printf("Enter elements\n");
	for(i=0 ; i<n ;i++)
	{
		scanf("%d",&a[i]);
	}

	printf("\nUnsorted Array\n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d\t",a[i]);
	}

	quick_sort(a,0,n-1);//function call

	printf("\nSorted Array Using Quick Sort\n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
}