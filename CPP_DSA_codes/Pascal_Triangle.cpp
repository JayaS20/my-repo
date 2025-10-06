
#include <vector>
#include <iostream>

//finding nth and nth col's element

long NCR(int row, int col){ //take row-1 and col-1  [row-1 C col-1]
long res=1;
for(int i=0;i<row;i++){
    res=res*(col-i);
    res=res/(i+1);
}
return res;
}

//find any nth row's values of pascal triangle

vector<int> rowPrint(int row){
long long ans = 1;
cout<< ans <<" ";
for(int i=1;i<row;i++){
    ans=ans*(row-i);
    ans=ans/i;
    cout<<ans<<" ";
}
cout<<endl;
}

//print entire pascal triangle

vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int i=1;i<row;i++){
        ans=ans * (row-i);
        ans=ans/i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int> pascalTriangle(int N){
    vector<vector<int>> ans;
    for(int i=1;i<=N;i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}
// generateRow(int row) → generates one row of Pascal’s triangle (like 1 3 3 1).
// It returns that row as a vector<int> (because each row has multiple integers).
// pascalTriangle(int N) → generates N rows of Pascal’s triangle.
// Each row itself is a vector<int>.
// Since we need to store many rows together, we need a container that holds multiple vectors.
// That’s why we use vector<vector<int>> → a vector where each element is itself a vector (a row).

// 🔹 Why not just vector<int>?
// A single vector<int> is like a list of numbers in one line.
// But Pascal’s triangle is multiple rows of numbers.