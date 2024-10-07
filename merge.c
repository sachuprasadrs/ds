#include<stdio.h>
int main()
{
int a[20],b[20],c[40],i,j,n,m,temp,k;
printf("Enter 1st array limit\n");
scanf("%d",&n);
printf("Enter 1st array elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter 2nd array limit\n");
scanf("%d",&m);
printf("Enter 2nd array elements\n");
for(j=0;j<m;j++)
{
scanf("%d",&b[j]);
}
printf("Elements of 1st array are:\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\nElements of 2nd array are:\n");
for(j=0;j<m;j++)
{
printf("%d\t",b[j]);
}

for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
for(i=0;i<m-1;i++)
{
for(j=i+1;j<m;j++)
{
if(b[i]>b[j])
{
temp=b[i];
b[i]=b[j];
b[j]=temp;
}
}
}
printf("\nElements after sort:\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\nElements after sort:\n");
for(j=0;j<m;j++)
{
printf("%d\t",b[j]);
}

printf("\nElements after merging:");
i=j=k=0;
while(i<n&&j<m)
{
if(a[i]<=b[j])
{
c[k++]=a[i++];
}
else
{
c[k++]=b[j++];
}
}
while(i<n)
{
c[k++]=a[i++];
}
while(j<m)
{
c[k++]=b[j++];
}
for(k=0;k<n+m;k++)
{
printf("%d\t",c[k]);
}
return 0;
}

