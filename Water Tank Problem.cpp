#include<bits/stdc++.h>
using namespace std;
int main()
{
        int m; //size of array
        cin>>m;
        vector<int> height(m);
        for(int i=0;i<m;i++)
        cin>>height[i];

        vector<int> leftmax; //contains max height on the left of current element
        vector<int> rightmax; //contains max height on the right of current element
        int n=height.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
                leftmax.push_back(height[i]);
            else
            {
                leftmax.push_back(max(height[i],leftmax[i-1]));
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                rightmax.push_back(height[i]);
            else
            {
                rightmax.push_back(max(height[i],rightmax[n-i-2]));
            }
        }

        reverse(rightmax.begin(),rightmax.end());

        for(int i=0;i<n;i++)
        {
            ans+= min(leftmax[i],rightmax[i])-height[i];
        }

        cout<< ans;
}
