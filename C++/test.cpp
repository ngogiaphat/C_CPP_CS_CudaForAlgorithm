#include<stdio.h>
#include<string.h>
#define max 100
typedef struct tn
{
	char Holot[30],Ten[30],Ngaysinh[8],Noisinh[40],X_LOAI[20];
	int D_Word,D_Excel,D_Win,TongDiem;
}
TINHOC;
TINHOC p,a[max];
void input_one(TINHOC &p);
void input_list(TINHOC a[],int &n);
void output_list(TINHOC a[],int n);
void input_score_list(TINHOC a[],int n);
void input_score_one(TINHOC a[],int n);
int seach(TINHOC a[],int n,char s[]);
void input_more(TINHOC a[],int &n);
void seach_sv(TINHOC a[],int n);
void output_score(TINHOC a[],int n);
void selection(TINHOC a[],int n);
void sum_one(TINHOC a[],int i);
void sum_list(TINHOC a[],int n);
void ratting_list(TINHOC a[],int n);
void ratting_one(TINHOC a[],int i);
void sort_score(TINHOC a[],int n);
void sort_name(TINHOC a[],int n);
void output_ratting(TINHOC a[],int n);
void detele(TINHOC a[],int &n);
int main()
{
	int n;
	input_list(a,n);
	output_list(a,n);
	selection(a,n);
}
void selection(TINHOC a[],int n)
{
	int i;
	char s;
	do
	{
		printf("\n1.Nhap diem ca lop\n");
		printf("2.Nhap diem tung hoc vien\n");
		printf("3.Tim hoc vien theo ten\n");
		printf("4.Them hoc vien\n");
		printf("5.Xoa hoc vien\n");
		printf("6.Sap xep danh sach theo diem tong\n");
		printf("7.Sap xep danh sach theo ten\n");
		printf("8.Hien thi danh sach thong tin hoc vien\n");
		printf("9.Hien thi danh sach diem cua hoc vien\n");
		printf("10.Hien thi danh sach hoc vien theo xep loai nhap vao\n");
		printf("11.Thoat\n");
		printf("Nhap lua chon: ");
		scanf("%d",&i);
		switch (i)
		{
			case 1:
				input_score_list(a,n);
				output_score(a,n);
				break;
			case 2:
				input_score_one(a,n);
				output_score(a,n);
				break;
			case 3:
				seach_sv(a,n);
				break;
			case 4:
				input_more(a,n);
				output_list(a,n);
				break;
			case 5:
				detele(a,n);
				output_list(a,n);
				break;
			case 6:
				sort_score(a,n);
				output_score(a,n);
				break;
			case 7:
				sort_name(a,n);
				output_list(a,n);
				break;
			case 8:
				output_list(a,n);
				break;
			case 9:
				output_score(a,n);
				break;
			case 10:
				output_ratting(a,n);
				break;
			case 11:
				return;
			default:
				printf("\nNhap sai!Nhap lai\n");
				continue;
		}
		printf("\nBan muon thuc hien cac lenh khac(y/n): ");
		fflush(stdin);
		scanf("%c",&s);
	}
	while(s=='y');
}

void input_one(TINHOC &p)
{
	fflush(stdin);
	printf("Nhap Ho lot: ");
	gets(p.Holot);
	printf("Nhap Ten: ");
	gets(p.Ten);
	printf("Nhap Ngay sinh: ");
	gets(p.Ngaysinh);
	printf("Nhap Noi sinh: ");
	gets(p.Noisinh);
}
void input_list(TINHOC a[],int &n)
{
	printf("Nhap so luong hoc vien: ");
    do
	{
	    scanf("%d",&n);
    }
	while(n<1);
	TINHOC s;
	for(int i=0;i<n;i++)
	{
		printf("Thong tin hoc vien thu %d\n",i+1);
		input_one(s);
		a[i]=s;
	}
}
void input_more(TINHOC a[],int &n)
{
	TINHOC s;
	input_one(s);
	a[n] = s;
	n++;
}
void input_score_one(TINHOC a[],int n)
{
	char s[30],c;
	printf("Nhap Ho Ten hoc vien can nhap diem: ");
	gets(s);
	int i,temp;
	do
	{
		i = seach(a,n,s);
		if(i == -1) 
		{
			printf("Khong tim thay hoc vien! Nhap lai ten hoc vien: ");
			gets(s);
			i = seach(a,n,s);
		}
	}
	while(i == -1);
	do
	{
		printf("\n1.Nhap diem WORD");
		printf("\n2.Nhap diem EXCEL");
		printf("\n3.Nhap diem WIN");
		printf("\nChon mon can nhap diem: ");
		scanf("%d",&temp);
		if(temp>3)
		{
			printf("Nhap sai!Vui long nhap lai");
			continue;
		}
		if(temp==1)
		{
			printf("Nhap diem WORD: ");
			do
			{
				scanf("%d",&a[i].D_Word);
				if (a[i].D_Word<0 || a[i].D_Word>10)
				{
						printf("\nNhap sai!Vui long nhap lai\n");
				}
			}while(a[i].D_Word<0 || a[i].D_Word>10);
		}
		else if(temp==2){
			printf("Nhap diem EXCEL: ");
			do
			{
				scanf("%d",&a[i].D_Excel);
				if (a[i].D_Excel<0 || a[i].D_Excel>10)
				{
						printf("\nNhap sai!Vui long nhap lai\n");
				}
			}while(a[i].D_Excel<0 || a[i].D_Excel>10);
		}
		else if(temp==3)
		{
			printf("Nhap diem WIN: ");
			do
			{
				scanf("%d",&a[i].D_Win);
				if (a[i].D_Win<0 || a[i].D_Win>10)
				{
					printf("\nNhap sai!Vui long nhap lai\n");
				}
			}
			while(a[i].D_Win<0 || a[i].D_Win>10);
		}
		printf("Ban co muon nhap tiep tuc (y/n): ");
		fflush(stdin);
		scanf("%c",&c);
	}
	while(temp>3||c =='y');
    sum_one(a,i);
	ratting_one(a,i);
}
void input_score_list(TINHOC a[],int n)
{
	char s;
	int temp;
	for(int i=0;i<n;i++)
	{
		printf("\nNhap diem cho %s %s",a[i].Holot,a[i].Ten);
		do{
			printf("\n1.Nhap diem WORD");
			printf("\n2.Nhap diem EXCEL");
			printf("\n3.Nhap diem WIN");
			printf("\nChon mon can nhap diem: ");
			scanf("%d",&temp);
			if(temp>3)
			{
				printf("\nNhap sai!Vui long nhap lai\n");
				continue;
			}
			if(temp==1)
			{
				printf("Nhap diem WORD: ");
				do
				{
					scanf("%d",&a[i].D_Word);
					if (a[i].D_Word<0 || a[i].D_Word>10)
					{
						printf("\nNhap sai!Vui long nhap lai\n");
					}
				}
				while(a[i].D_Word<0 || a[i].D_Word>10);
			}
			else if(temp==2)
			{
				printf("Nhap diem EXCEL: ");
				do
				{
					scanf("%d",&a[i].D_Excel);
					if (a[i].D_Excel<0 || a[i].D_Excel>10)
					{
						printf("\nNhap sai!Vui long nhap lai\n");
					}
				}
				while(a[i].D_Excel<0 || a[i].D_Excel>10);
			}
			else if(temp==3)
			{
				printf("Nhap diem WIN: ");
				do
				{
					scanf("%d",&a[i].D_Win);
					if (a[i].D_Win<0 || a[i].D_Win>10)
					{
						printf("\nNhap sai!Vui long nhap lai\n");
					}
				}
				while(a[i].D_Win<0 || a[i].D_Win>10);
			}
			printf("Ban co muon nhap tiep tuc (y/n): ");
			fflush(stdin);
			scanf("%c",&s);
		}
		while(temp>3||s=='y');
	}
    sum_list(a,n);
	ratting_list(a,n);
}
void output_list(TINHOC a[],int n)
{
	printf("_________________________________________________________________________________________\n");
	printf("|%-3s|%-30s|%-15s|%-20s|%-15s|","STT","Ho va Ten","Ngay sinh","Noi sinh","Ghi chu");
	printf("\n-----------------------------------------------------------------------------------------\n");
	for(int i=0;i<n;i++)
	{
		printf("|%-3d|%-20s%-10s|%-15s|%-20s|%-15s|",i+1,a[i].Holot,a[i].Ten,a[i].Ngaysinh,a[i].Noisinh,"_______________");
		printf("\n-----------------------------------------------------------------------------------------\n");
	}
}
void output_score(TINHOC a[],int n){
	printf("____________________________________________________________________________________________________________________\n");
	printf("|%-3s|%-30s|%-15s|%-15s|%-15s|%-15s|%-15s|","STT","Ho va Ten","Diem Word","Diem Excel","Diem Win","Tong Diem","Xep Loai");
	printf("\n--------------------------------------------------------------------------------------------------------------------\n");
	for(int i=0;i<n;i++)
	{
		printf("|%-3d|%-20s%-10s|%-15d|%-15d|%-15d|%-15d|%-15s|",i+1,a[i].Holot,a[i].Ten,a[i].D_Word,a[i].D_Excel,a[i].D_Win,a[i].TongDiem,a[i].X_LOAI);
		printf("\n--------------------------------------------------------------------------------------------------------------------\n");
	}
}
void seach_sv(TINHOC a[],int n)
{
	char s[30],q;
	int i;
	do
	{
		printf("Nhap ten hoc vien can tim: ");
		fflush(stdin);
		gets(s);
		i = seach(a,n,s);
		if(i == -1) 
		{
			printf("Khong tim thay hoc vien! Tiep tuc tim hoc vien(y/n): ");
			scanf("%c",&q);
		}
		else
		{
			printf("_____________________________________________________________________\n");
			printf("|%-30s|%-15s|%-20s|","Ho va Ten","Ngay sinh","Noi sinh");
			printf("\n---------------------------------------------------------------------\n");
			printf("|%-15s%-15s|%-15s|%-20s|",a[i].Holot,a[i].Ten,a[i].Ngaysinh,a[i].Noisinh);
		}
	}
	while(q =='y');
}
int seach(TINHOC a[],int n,char s[]){
	char p[30];
	for(int i=0;i<n;i++){
		strcpy(p,a[i].Holot);
		strcat(p," ");
		strcat(p,a[i].Ten);
		if(strcmp(p,s)==0)
		{
			return i;
		}
	}
	return -1;
}
void sum_one(TINHOC a[],int i)
{
    a[i].TongDiem=a[i].D_Excel+a[i].D_Win+a[i].D_Word;
}
void sum_list(TINHOC a[],int n)
{
    for(int i=0;i<n;i++)
	{
        a[i].TongDiem=a[i].D_Excel+a[i].D_Win+a[i].D_Word;
    }
}
void ratting_list(TINHOC a[],int n)
{
    for(int i=0;i<n;i++)
	{
        if(a[i].TongDiem>=24)
		{
            char s[30] = "Gioi";
            strcpy(a[i].X_LOAI,s);
        }
		else if(a[i].TongDiem>=18)
		{
            char s[30] = "Kha";
            strcpy(a[i].X_LOAI,s);
        }
		else if(a[i].TongDiem>=15)
		{
            char s[30] = "Trung binh";
            strcpy(a[i].X_LOAI,s);
        }
		else 
		{
            char s[30] = "Kem";
            strcpy(a[i].X_LOAI,s);
        }
    }
}
void ratting_one(TINHOC a[],int i)
{
	if(a[i].TongDiem>=24)
	{
		char s[30] = "Gioi";
		strcpy(a[i].X_LOAI,s);
	}
	else if(a[i].TongDiem>=18)
	{
		char s[30] = "Kha";
		strcpy(a[i].X_LOAI,s);
	}
	else if(a[i].TongDiem>=15)
	{
		char s[30] = "Trung binh";
		strcpy(a[i].X_LOAI,s);
	}
	else 
	{
		char s[30] = "Kem";
		strcpy(a[i].X_LOAI,s);
    }
}
void sort_score(TINHOC a[],int n)
{
	TINHOC temp;
	for(int i=0;i<n-1;i++)
	{
		if(a[i].TongDiem < a[i+1].TongDiem)
		{
			temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
		}
	}
}
void sort_name(TINHOC a[],int n)
{
	TINHOC temp;
	char ten1[30],ten2[30];
	for(int i=0;i<n;i++)
	{
		strcpy(ten1,a[i].Holot);
		strcat(ten1," ");
		strcat(ten1,a[i].Ten);
		for(int j=i+1;j<n;j++)
		{
			strcpy(ten2,a[j].Holot);
			strcat(ten2," ");
			strcat(ten2,a[j].Ten);
			if(strcmp(strupr(ten1),strupr(ten2))>0)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void output_ratting(TINHOC a[],int n)
{
	char s[15];
	printf("Nhap Xep loai can hien thi: ");
	fflush(stdin);
	gets(s);
	printf("____________________________________________________________________________________________________________________\n");
	printf("|%-3s|%-30s|%-15s|%-15s|%-15s|%-15s|%-15s|","STT","Ho va Ten","Diem Word","Diem Excel","Diem Win","Tong Diem","Xep Loai");
	printf("\n--------------------------------------------------------------------------------------------------------------------\n");
	for(int i=0;i<n;i++)
	{
		if(strcmp(s,a[i].X_LOAI)==0)
		{
			printf("|%-3d|%-20s%-10s|%-15d|%-15d|%-15d|%-15d|%-15s|",i+1,a[i].Holot,a[i].Ten,a[i].D_Word,a[i].D_Excel,a[i].D_Win,a[i].TongDiem,a[i].X_LOAI);
			printf("\n--------------------------------------------------------------------------------------------------------------------\n");
		}
	}
}

void detele(TINHOC a[],int &n)
{
	char s[30],tmp;
	do
	{
		printf("\nNhap ten hoc vien can xoa: ");
		fflush(stdin);
		gets(s);
		int temp = seach(a,n,s);
		if(temp == 0){
			for(int i=temp;i<n-1;i++)
			{
				a[i]=a[i+1];
			}
			n--;
			printf("\nThuc hien lai chuc nang(y/n): ");
			scanf("%c",&tmp);
		}
		else
		{
			printf("\nKhong tim thay hoc vien can xoa");
			printf("\nThuc hien lai chuc nang(y/n): ");
			scanf("%c",&tmp);
		}
	}
	while(tmp == 'y');
}