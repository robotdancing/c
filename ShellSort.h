#ifndef SHELLSORT_H
#define SHELLSORT_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ShellSort(int a[],int length);
void BubbleSort(int a[],int length);
void SelectSort(int a[],int n);
void QuickSort(int a[],int left,int right);
void InsertSort(int a[],int n);
void Merge2Array(int a[],int first,int mid,int last,int tmp[]);
#endif
