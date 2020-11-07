#include <iostream>
#include "Stack.h"
#include "Queue.h"


int main()
{
	int k, n;
	cin >> k; //������ ������ �����
	TStack<int> S(k);
	cout << S.GetInd() << " - ind " << S.IsEmpty() << " and " << S.IsFull() << endl;
	cin >> n; //������ ������� ������� ���������� �������� � ����
	S.Push(n);
	cout << S.GetInd() << " - ind " <<  S.IsEmpty() << " and " << S.IsFull() << endl;
	cin >> S; //������ ���������� ��������� � ��� ����
	cout << S.GetInd() << " - ind " << S.IsEmpty() << " and " << S.IsFull() << endl;
	cout << S.Get() << endl;
	cout << S << endl << endl;

	cin >> k; //������ ������ ����������� �������
	TQueue<int> Q(5);
	cout << Q.GetInd() << " - ind " << Q.GetEnd() << " - end "<< Q.IsEmpty() << " and " << Q.IsFull() << endl;
	cin >> n; //������ ������� ������� ���������� �������� � �������
	Q.Push(n);
	cout << Q.GetInd() << " - ind " << Q.GetEnd() << " - end " << Q.IsEmpty() << " and " << Q.IsFull() << endl;
	cin >> Q; //������ ���������� ��������� � ���� ������� 
	cout << Q.GetInd() << " - ind " << Q.GetEnd() << " - end " << Q.IsEmpty() << " and " << Q.IsFull() << endl;
	cout << Q.Get() << endl;
	cout << Q << endl;
	return 0;
}