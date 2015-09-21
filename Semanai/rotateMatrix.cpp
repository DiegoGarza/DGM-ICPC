#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

//With O(n) memory
vvi rotateHelper(vvi mat){
    vvi ans(mat.size(), vi(mat.size()));
    for(int i=0, k = mat.size() - 1; i<mat.size(); i++, k--){
        for(int j=0; j<mat.size(); j++){
            ans[j][k] = mat[i][j];
        }
    }
    return ans;
}

void rotateMatrix(vvi &mat, int k){
    k = k % 4;
    if(k < 0) k += 4;
    for(int i = 0; i < k; i++){
        mat = rotateHelper(mat);
    }
}

//Without O(n) memory
void rotateHelper2(vector<vector<int> > &mat){
    for(int i = 0, k = mat.size() - 1; i<k; i++, k--){
        for(int ul = i, ur = i, ll = k, lr = k; ul < k; ul++, ur++, ll--, lr--){
            int temp = mat[ur][k];
            mat[ur][k] = mat[i][ul];
            mat[i][ul] = mat[ll][i];
            mat[ll][i] = mat[k][lr];
            mat[k][lr] = temp;
        }
    }
}

void rotateMatrix2(vector<vector<int> > &mat, int k){
    k = k % 4;
    if(k < 0) k += 4;
    for(int i = 0; i < k; i++){
        rotateHelper2(mat);
    }
}

int main() {
    int size;
    cout<<"Size:"<<endl;
    cin>>size;
    cout<<"Matrix: "<<endl;
    vector<vector<int> > mat(size, vector<int>(size));
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cin>>mat[i][j];
        }
    }

    int rot, extra;
    cout<<"Rotations: "<<endl;
    cin>>rot;
    cout<<"Extra memory: (1 for yes, 0 for no)"<<endl;
    cin>>extra;

    if(extra) rotateMatrix(mat, rot);
    else rotateMatrix2(mat, rot);

    cout<<"ANSWER: "<<endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
