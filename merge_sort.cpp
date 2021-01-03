// 2021.01.01
// 归并排序
#include<iostream>
#define MAX_VALUE 1000
using namespace std;
// 输出数组
void printArray(int A[],int size){
        // 输出数组
    for (int i=0;i<size;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    
}
// 合并A数组中的两个有序序列
void merge (int A[],int p,int q,int r){

    // 分别计算两个有序数组的长度
    int n1 = q-p+1;
    int n2 = r-q;

    // 新建两个数组，分别存储两个有序序列
    int L[n1+1];
    int R[n2+1];

    for (int i=0;i<n1;i++){
        L[i] = A[p+i];
    }
    for (int i=0;i<n2;i++){
        R[i] = A[i+q+1];
    }
    
    // 数组上界标志位
    L[n1] = MAX_VALUE;
    R[n2] = MAX_VALUE;


    // 开始归并两个有序数组
    int i = 0;
    int j = 0;

    for (int k=p;k<=r;k++){
        if (L[i]<R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
    
    // printArray(A,r-p+1);
}
// 拆分递归排序
void merge_sort(int A[],int p,int r){

    if (p<r)
    {
        int q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);

        /* code */
    }
    // printArray(A,r-p+1);
    
}


int main (){
    int A[10] = {1,0,2,4,3,5,7,9,8};
    
    merge_sort(A,0,8);
    printArray(A,9);
    return 0;
}