#include <iostream>
#include <vector>

using namespace std;

//从数组末尾开始比较，将较大的数放到数组末尾，不需要额外空间来存储合并后的数组
//4ms
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i = m - 1;
    int j = n - 1;
    int k = m + n -1;
    while(i>=0 && j>=0){
        if(nums1[i] > nums2[j]){
            //如何确保nums1有k个长度？这个题目已经给定了nums1的长度为m+n
            nums1[k] = nums1[i];
            i--;
        }else{
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    } 

    while(j>=0){
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
//0ms
//先将nums1的前m个元素存到一个临时数组中，然后将nums1和nums2合并到nums1中
void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n){
    vector<int> temp(nums1.begin(), nums1.begin()+m);

    int i = 0, j = 0, k = 0;
    while(i<m && j<n){
        if(temp[i] < nums2[j]){
            nums1[k] = temp[i];
            i++;
        }else{
            nums1[k] = nums2[j];
            j++;
        }
        k++;
    }

    while(i<m){
        nums1[k] = temp[i];
        i++;
        k++;
    }

    while(j<n){
        nums1[k] = nums2[j];
        j++;
        k++;
    }

}
int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge2(nums1, 3, nums2, 3);

    cout << "Merge Array: ";
    for(int num:nums1){
        cout << num << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}