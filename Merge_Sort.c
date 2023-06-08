#include<stdio.h>
#include<conio.h>


void merge(int a[] , int lb , int mid , int ub)
{
	int i , j , k;
	int b[50];
	i= lb;
	j= mid+1;
	k = 0;

	while( i<= mid && j<= ub)
	{
		if(a[i]<a[j])
		{
			b[k] = a[i];
			i++;
			k++;
		}
		else
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}

	
		while(j<=ub)
		{
			b[k] = a[j];
			j++;
			k++;
		}

		while(i<=mid)
		{
			b[k] = a[i];
			i++;
			k++;
		}
	

	k=0;
	for(i=lb;i<ub;i++)
	{
		a[i]=b[k];
		k++;
	}


}

void merge_sort(int a[] , int lb , int ub)
{
	int mid;
	if(lb<ub)
	{
		mid = (lb+ub)/2;
		//for first half
		merge_sort(a,lb,mid);
		//for second half
		merge_sort(a,mid+1,ub);
		//for merging sub-arrays
		merge(a,lb,mid, ub);
	}
}

void main()
{
	int a[50], i , n,lb,ub;
	

	printf("How many elemnts do you want ot enter in an array\n");
	scanf("%d",&n);

	lb = 0;
	ub = n-1;

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


	merge_sort(a,lb,ub);

	printf("\nSorted Array Using Merge Sort\n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
}