#include <iostream>
using namespace std;

int N;

void tab(int n){
    for(int i = 0 ; i < n; i++) cout << "____";
}

void print(int n){
    tab(n);
    cout << "\"����Լ��� ������?\"\n";
    tab(n);
    if(n != N){
        cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        tab(n);
        cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        tab(n);
        cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
        print(n + 1);
    }
    else{
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    }
    tab(n);
    cout << "��� �亯�Ͽ���.\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    print(0);
    return 0;
}