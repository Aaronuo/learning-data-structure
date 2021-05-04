#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
#define LISTINCREMENT 10


typedef int ElemType;
typedef struct 
{
	ElemType *elem;
	int length;
	int listsize;

}sqList;
Status InitList(sqList &L) 
{
	L.elem = (ElemType* )malloc(sizeof(ElemType)* LIST_INIT_SIZE);
	if (!L.elem)
		exit(-2);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 1;

}
int ListLength(sqList L)
{

	return 0;
}
void ClearList(int& L)
{

}
void ListEmpty(int L)
{

}
void GetElem(sqList L, int i, ElemType e)
{

}
int LocateElem(sqList L, ElemType e, Status (*compare)(ElemType,ElemType))
{
	int i = 1;
	int *p;
	p = L.elem;
	while (i <= L.length && !(*compare)(*p++, e))
		++i;
	if (i <= L.length)
		return i;
	else
		return 0;


}
Status ListInsert(sqList &L, int i, ElemType e)
{

	ElemType *newbase;
	int *p,*q;
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length >= L.listsize)
	{
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i - 1]);
	for (p = &(L.elem[L.length - 1]); p >= q; --p)
	*(p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}
Status ListDelete(sqList &L, int i,ElemType e)
{
	int * p, * q;
	if (i<1 || i>L.length + 1)
		return ERROR;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;
	for (++p; p <= q; ++p)
		*(p-1)=*p;
	--L.length;
	return OK;

}
void UnionList(sqList &La,sqList Lb) 
{
	int i;
	ElemType e;
	int Lb_len,La_len;
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, e);
		if (!LocateElem(La, e, 0))
			ListInsert(La, ++La_len, e);
	}
}

void MergeList(sqList La, sqList Lb, sqList& Lc)
{
	int *pa, *pb,*pc;
	int *pa_last, *pb_last;
	pa = La.elem;
	pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)
		exit(OVERFLOW);
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)
		*pc++ = *pa++;
	while (pb <= pb_last)
	*pc++ = *pb++;

}
int main() 
{
	return 0;
}