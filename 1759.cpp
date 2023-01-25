#include <iostream>
#define MAX 26

using namespace std;

int alpha[MAX]={0,};
int L, C;

//collection idx: 0,4,8,14,20
bool check_alpha(){
    int col=0;
    int vow=0;

    for(int i=0; i<MAX; i++){
        if(alpha[i]==-1){
            if(i==0 || i==4 || i==8 || i==14 || i==20) col++;
            else vow++;
        }
    }

    if(col>=1 && vow>=2) return true;
    return false;
}

void print_ans(){
    for(int i=0; i<MAX; i++){
        if(alpha[i]==-1){
            char c=(char)(97+i);
            cout<<c;
        }
    }
    cout<<'\n';
}

void DFS(int idx, int cnt){
    if(cnt==L){
        if(check_alpha()) print_ans();
        return;
    }

    for(int i=idx; i<MAX; i++){
        if(alpha[i]==0 || alpha[i]==-1) continue;
        alpha[i]=-1;
        DFS(i,cnt+1);
        if(alpha[i]==-1) alpha[i]=1;
    }
}

int main(){
    cin>>L>>C;

    for(int i=0; i<C; i++){
        char ch;
        cin>>ch;
        alpha[(int)ch-97]=1;
    }

    DFS(0,0);
}