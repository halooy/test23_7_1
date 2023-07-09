#define _CRT_SECURE_NO_WARNINGS
#include<stdbool.h>
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>

#define ROW 5
#define COL 4
#define SIZE 5

int maxv(num1, num2) 
{
	if (num1 > num2)
		return num1;
	return num2;
}
bool isLeap(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int Add(op1, op2)
{
	return op1 + op2;
}
int Sub(op1, op2)
{
	return op1 - op2;
}
int Mul(op1, op2)
{
	return op1 * op2;
}
int Div(op1, op2)
{
	return op1 / op2;
}
int Mod(op1, op2)
{
	return op1 % op2;
}
int Find(int ar[], int n, int key)
{
	int index;
	for (int i = 0; i < n; ++i)
	{
		if (key == ar[i])
			return i;
	}
	return -1;
}
int FindMax(int ar[], int n)
{
	int max = ar[0];
	int i;
	for(i = 1; i < n; ++i)
	{
		if (ar[i] > max)
			max = ar[i];
	}
	return max;
}
void Sort(int ar[], int n)
{
	for (int i = 0; i < n-1; ++i)	//���ڿ��ƱȽϵ�����
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (ar[j] > ar[j + 1])
			{
				int tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
			}
		}
	}
}
void PrintArray(int ar[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", ar[i]);
	}
}
//�ж��Ƿ�Ϊ����
bool IsPrime(int value)
{
	for (int i = 2; i < value - 1; ++i)
	{
		if (value % i == 0)
			return false;
	}
	return true;
}
void Reverse(int ar[], int n)
{
	int low = 0;
	int high = n - 1;
	while (low < high)
	{
		int tmp = ar[low];
		ar[low] = ar[high];
		ar[high] = tmp;
		low++;
		high--;
	}
}
int Fac(int n)			//�ݹ���׳�
{
	if (1 == n)
		return 1;
	else
		return n * Fac(n - 1);
}
int Fib(int n)
{
	if (n <= 2)
		return 1;
	int fib1 = 1;
	int fib2 = 2;
	//�������ž�ջ�����
	int fib;
	for (int i = 3; i <= n; ++i)	//1 1 2 3 5
	{
		fib = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib;
	}
	return fib;

}
void bubble_sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int GetCount(unsigned char ch)
{
	int count = 0;

	while (ch)
	{
		count++;
		ch &= (ch - 1);
	}

	//while (ch != 0)
	//{
	//	if (ch  & 0x01 != 0)
	//		count++;
	//	ch >>= 2;
	//}

	//while (ch != 0)
	//{
	//	if (ch % 2 == 1)
	//		count++;
	//	ch /= 2;
	//}
	return count;
}
//�ݹ� ��һ������ÿһλ��ӡ����
void print(int num)
{
	if (num < 10)
	{
		printf("%d", num);
		return;
	}
	print(num / 10);	//��ÿ�εݹ�����-- 6789-��678-��67-��6
	printf("%d", num % 10);
}
//�ݹ�ʵ��strlen--���ַ����ĳ��ȣ���ʼλ�õ�\0��
int mystrlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}
//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ��	5^4  5*5^3  
int mypow(int n, int k)
{
	if (0 == k)
		return 1;
	if (1 == k)
		return n;
	return n * mypow(n, k - 1);
}

typedef struct Student
{
	int ID;
	char name[10];
	char sex[3];
	int age;
}Student, *PStu;

void Print_Stu_1(struct Student s1)
{
	printf("ID = %d, name = %s, sex = %s, age = %d\n",
		s1.ID, s1.name, s1.sex, s1.age);
}
void Print_Stu_2(struct Student* ps)
{
	printf("ID = %d, name = %s, sex = %s, age = %d\n",
		ps->ID, ps->name, ps->sex, ps->age);
}

int main()
{


	Student s1 = { 1000, "ysy", "��", 25 };
	Print_Stu_1(s1);
	Print_Stu_2(&s1);
	//��ֵ
	//s1.ID = 1000;
	//strcpy(s1.name, "ysy");
	//strcpy(s1.sex, "��");
	//s1.age = 25;
	//printf("ID = %d, name = %s, sex = %s, age = %d\n",
	//	s1.ID, s1.name, s1.sex, s1.age);


//�ݹ�ʵ��strlen--���ַ����ĳ��ȣ���ʼλ�õ�\0��
	//printf("%d\n", mystrlen("halooy"));

///ָ����Ǳ�����������ŵ�ַ�ı��� 
/// ָ��Ĵ�С��32λƽ̨����4���ֽڣ���64λƽ̨����8���ֽ� 
/// 32λ��ָ���С4���ֽڣ�64λ��ָ���С8���ֽڣ���ΪҪȷ��ָ��Ĵ�С�ܹ��洢���µ�ַ��32λ�ĵ�ַ��С2^32��4G�������ַ�ĸ��ֽھ��ܹ��洢�������32λ�µ�ָ���С����λ4���ֽڣ�64λͬ��
///Ұָ����������
/// 	1��ָ��δ����ʼ��
/// 	2��ָ��Խ�����
/// 	3��ָ��ָ��Ŀռ��ͷ�
	//int values[SIZE];
	//int* vp = &values[SIZE - 1];
	//while (vp >= &values[0])
	//{
	//	*vp-- = 0;
	//}
	//int a = 1;
	//int b = 2;
	//int c = 3;
	//int ar[3] = { a,b,c };
	////���ָ�������
	//int *br[3] = { &a,&b,&c };	//ָ������     int * br[]
	//int(*cr)[3];				//����ָ��     ָ��ָ������

///ȡһ������������1�ĸ���
/// 100=>0110 0100
/// 255=>1111 1111
	//unsigned char ch = 100;
	//int count = GetCount(ch);
	//pritnf("count = %d\n", count);

///���ú���ʱ���������鲢���ǰ��������鴫�����������ǰ��������Ԫ�ص�ַ����ȥ��ͨ��ָ�������
	//int arr[] = { 3,1,7,5,8,9,0,2,4,6 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < n; ++i)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");
	//bubble_sort(arr, n);
	//for (int i = 0; i < n; ++i)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");

///��ӡ��ά����
	//int ar[ROW][COL] = { 0 };
	//for (int i = 0; i < ROW; ++i)
	//{
	//	for (int j = 0; j < COL; ++j)
	//	{
	//		printf("%d ", ar[i][j]);
	//	}
	//	printf("\n");
	//}

/// 쳲������� 1 1 2 3 5 8 13 21 ...
	//int n = 5;
	//size_t result = Fib(n);
	//printf("result = %u\n", result);

	/*int n = 5;
	int result = Fac(n);
	printf("result = %d\n", result);*/

///�ж�����
	//int n;
	//printf("input n:");
	//scanf("%d", n);
	//if (IsPrime(n))
	//	printf("is Prime\n");
	//else
	//	printf("is not Prime\n");

///�������ã�����������Լ�����
	//int ar[] = { 4,7,9,2,0,1,5,12,43,21,67,54,100 };
	//int n = sizeof(ar) / sizeof(ar[0]);
	////int key;
	////printf("input key:");
	////scanf("%d", &key);
	////int index = Find(ar, n, key);
	////if (index == -1)
	////	printf("none\n");
	////else
	////	printf("index: %d\n", index);
	//int max_value = FindMax(ar, n);
	//printf("max_value = %d\n", max_value);
	//PrintArray(ar, n);
	//Sort(ar, n);
	//PrintArray(ar, n);
	//Reverse(ar, n);
	//PrintArray(ar, n);

///ģ���û���¼����ֻ�ܵ�¼���Ρ�����ֻ���������������룬������ȷ��ʾ��¼�ɹ���������ξ�����������˳�����

///��ʾ����ַ��������ƶ������м���
	//char arr1[] = "welcome to 519...";
	//char arr2[] = "#################";
	//int i = 0;
	//int j = strlen(arr1) - 1;
	//while (i <= j)
	//{
	//	printf("%s\n", arr2);
	//	arr2[i] = arr1[i];
	//	arr2[j] = arr1[j];
	//	i++;
	//	j--;
	//	Sleep(1000);
	//	system("cls");
	//}
	//printf("%s\n", arr1);

///���ֲ���(ǰ��������������)
//	int arr[] = {12,23,34,45,56,78,89,123,134,156,178,245,256};
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int key;
//	printf("������Ҫ���ҵ�����");
//	scanf("%d", &key);
//	int low = 0;
//	int high = n - 1;
//	int mid, index = -1;
//	while (low <= high)
//	{
//		mid = (high + low) / 2;
//		if (key == arr[mid])
//		{
//			index = mid;
//			break;
//		}
//		else if (key < arr[mid])
//		{
//			high = mid - 1;
//		}
//		else
//			low = mid + 1;
//	}
//	if (index == -1)
//		printf("Ҫ���ҵ� % d������\n", key);
//	else
//		printf("Ҫ���ҵ�%d�ڣ�%d\n", key, index);

///����1-10�Ľ׳˺�
	//size_t result = 0;
	//for (int i = 1; i <= 10; ++i)
	//{
	//	int temp = 1;
	//	for (int j = 1; j <= i; ++j)	//i�Ľ׳�
	//	{
	//		temp *= j;
	//	}
	//	result += temp;
	//}
	//printf("%1!~10��= %u", result);

///����n�Ľ׳�
	//int i;
	//size_t result = 1;
	//int n;
	//printf("input:");
	//scanf("%d", &n);
	//for (i=1; i <= n; ++i)
	//{
	//	result *= i;
	//}
	//printf("%d! = %u\n",n, result);

///������
	//int select = 1;
	//int op1, op2, result;
	//////////////////////////////////////
	////�������
	//system("title ���׼�����");
	//system("mode con cols=30 lines=15");
	//////////////////////////////////////
	////InstallShield 2010
	//while (select)
	//{
	//	printf("************************\n");
	//	printf("*     ���׼�����       *\n");
	//	printf("************************\n");
	//	printf("*[1]Add         [2]Sub *\n");
	//	printf("*[3]Mul         [4]Div *\n");
	//	printf("*[5]Mod         [0]Quit*\n");
	//	printf("************************\n");
	//	printf("��ѡ��");
	//	scanf("%d", &select);
	//	if (0 == select)
	//		break;
	//	printf("������op1��op2��");
	//	scanf("%d %d", &op1, &op2);
	//	switch (select)
	//	{
	//	case 1:
	//		result = Add(op1, op2);
	//		break;
	//	case 2:
	//		result = Sub(op1, op2);
	//		break;
	//	case 3:
	//		result = Mul(op1, op2);
	//		break;
	//	case 4:
	//		result = Div(op1, op2);
	//		break;
	//	case 5:
	//		result = Mod(op1, op2);
	//		break;
	//	default:
	//		printf("��������\n");
	//		break;
	//	}
	//	printf("result = %d\n", result);
	//	system("pause");
	//	system("cls");			//clear screen
	//}
	//printf("ϵͳ�˳�\n");

///����n�Ľ׳�
	//int n = 10;
	//int num = 1;
	//for (n; n>1; --n)
	//{
	//	num *= n;
	//}
	//printf("%d", num);

//����
	/*int ar[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	int n = sizeof(ar) / sizeof(ar[0]);
	for (int i = 0; i < n; ++i)
	{
		printf("%d", ar[i]);
	}
	printf("\n");*/

// switch��䡢������������
	/*int year;
	int month;
	int days;
	while (1)
	{
		printf("input month");
		scanf("%d %d", &year, &month);
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days = 31;
			break;
		case 2:
			if (isLeap(year))
				days = 29;
			else
				days = 28;
			break;
		case 4:
			days = 30;
			break;
		case 6:
			days = 30;
			break;
		case 9:
			days = 30;
			break;
		case 11:
			days = 30;
			break;
		default:
			printf("input error"\n);
			break;
		}
		printf("%d��%d����%d��\n", year, month, days);
	}*/

// ���ú���
	/*int num1, num2;
	printf("������������,�ո���:");
	scanf("%d %d", &num1, &num2);
	printf("%d", maxv(num1, num2));*/

/// 
	//int a = 0;
	//printf("%d %d %d %d\n", a++, ++a, a++, ++a);
	////  2  2  1  1   �ֺŽ������������   ѹջ����  
	////  3  4  1  4	 
	//printf("a = %d\n", a);
	////  4

/// ѭ�����
	//int sum = 0;
	//int i;
	//for (i = 1; i <= 10; ++i)
	//{
	//	sum += i;
	//}
	//printf("sum = %d\n", sum);

/// ѡ�����
	//int a, b, max_value;
	//printf("����������");
	//scanf_s("%d %d", &a, &b);
	//if (a > b)
	//	max_value = a;
	//else
	//	max_value = b;
	//printf("max_value = %d", max_value);
	
	//char* str = "hello";
	//printf("str = %s\n", str);

/// �����ַ������Դ�һ���ֽ�
/// �����ַ��������Դ������ֽڣ���һ��\0
/// 	���鶨�����Ϊ��������Ϊ����, arr1[?]
	/*char arr1[] = "bit";
	char arr2[] = { 'b','i','t'};
	char arr3[] = { 'b','i','t','\0'};
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%s\n", arr3);*/

	return 0;
}