// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> NextGreaterElement(vector<int>&arr)
{
    int n=arr.size();
    vector<int>result(n,-1);
    stack<int>st;
   for(int i=0;i<arr.size();i++)
   {
       while(!st.empty()&&arr[i]>arr[st.top()])
       {
           result[st.top()]=arr[i];
           st.pop();
       }
       st.push(i);
   }
   return result;
}

int main() {
    // Write C++ code here
   int n;
   cout<<"Enter the number of elements:";
   cin>>n;
   vector<int>arr(n);
   cout<<"Enter"<<" " <<n<<"elements";
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   cout<<"Input array:[";
for(int i=0;i<n;i++)
{
    cout<<arr[i];
    if(i<n-1)
    {
        cout<<",";
    }
}
cout<<"]"<<endl;
vector<int>result=NextGreaterElement(arr);
 cout << "Next Greater Elements: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}
