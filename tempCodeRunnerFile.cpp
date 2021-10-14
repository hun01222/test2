#include<iostream>
#include<math.h>
#define max 4000000
using namespace std;

int arr[max+1], prime[max+1]; // 큰 크기의 배열은 전역변수로!!

int main(){
    arr[1]=1; // 소수면 0
    int k=0;
    for(int i=2; i<=sqrt(max); i++){
        if(arr[i]==0){
            prime[k++]=i;
            for(int j=i*2; j<=max; j+=i)
                arr[j]=1;
        }
    }

    int n, start=0, end=0, temp=0, cnt=0;
    cin >> n;
    while(end<=k){
        if(temp<n){
            temp+=prime[end++];
        }
        else if(temp>=n){
            temp-=prime[start++];
        }
        if(temp==n){
            cnt++;
        }
    }
    cout << cnt;
}