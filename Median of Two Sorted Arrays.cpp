class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        int *num1=new int[len1];
        for(int i=0;i<len1;i++)
        {
            num1[i]=nums1[i];
        }
        int *num2=new int[len2];
        for(int i=0;i<len2;i++)
        {
            num2[i]=nums2[i];
        }
        if((len1+len2)%2==1)
            return findKth(num1,num2,len1,len2,(len1+len2+1)/2);
        else
            return (findKth(num1,num2,len1,len2,(len1+len2)/2)+findKth(num1,num2,len1,len2,(len1+len2)/2+1))/2;
        delete [] num1;
        delete [] num2;
    }
    double findKth(int a[], int b[], int m, int n, int k)//始终保持a短于b
    {
        if(m>n)
            return findKth(b,a,n,m,k);  
        if(m==0)
            return b[k-1]; 
        if(k==1)  
            return min(a[0],b[0]);  
        int pa=min(k/2,m), pb=k-pa;  
        if (a[pa-1]<b[pb-1])
        {
            return findKth(a+pa,b,m-pa,n,k-pa);
        }
        else if (a[pa-1]>b[pb-1])  
            return findKth(a,b+pb,m,n-pb,k-pb);  
        else  
            return a[pa-1];  
    }
};