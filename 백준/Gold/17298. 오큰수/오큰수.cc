#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> arr(N);
    vector<int> answer(N, -1);
    stack<int> s;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < N; i++){
        while(!s.empty() && arr[s.top()] < arr[i]){
            answer[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    
    for(int i = 0; i < N; i++){
        cout << answer[i] << ' ';
    }
    
    return 0;
}