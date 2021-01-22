#pragma once
//#define N 100
////��̬˳���
//struct seqlist2
//{
//	SLDataType data[N];//��������
//	int size;          //��Ч���ݸ���
//};                     //sizeof(seqlist2)=404



typedef int SLDataType;
//��̬˳���
typedef struct seqList
{
	SLDataType* data; //����ָ��
	int size;            //��ЧԪ�ظ���
	int capacity;//����Ŀռ�
}seqList;       //sizeof(seqlist)=12


//��ʼ��˳���
void initseqList(seqList* sl);

//β��
void seqListPushBack(seqList* sl, SLDataType val);

//βɾ
void seqListpopBack(seqList* sl);

//�������
void seqListCheckCapacity(seqList* sl);

//��ӡ
void seqListPrint(seqList* sl);

//��������λ�õ�Ԫ��
SLDataType seqListAt(seqList* sl, int pos);

//�п�
int seqListEmpty(seqList* sl);

//��ЧԪ�ظ���
int seqListSize(seqList* sl);

//ͷ��
void seqListPushFront(seqList* sl, SLDataType val);

//ͷɾ
void seqListPopFront(seqList* sl);

//����λ�ò���
void seqListInsert(seqList* sl, int pos, SLDataType val);

//����λ��ɾ��
void seqListErase(seqList* sl, int pos);

//����
void seqListDestroy(seqList* sl);

//����
int seqListFind(seqList* sl, SLDataType val);

//��ȡβ��Ԫ��
int seqListBack(seqList* sl);


