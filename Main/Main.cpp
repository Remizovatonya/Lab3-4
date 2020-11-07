#include <iostream>
#include "Stack.h"
#include "Queue.h"


int main()
{
	int k, n;
	cin >> k; //ввести размер стека
	TStack<int> S(k);
	cout << S.GetInd() << " - ind " << S.IsEmpty() << " and " << S.IsFull() << endl;
	cin >> n; //ввести элемент который необходимо положить в стек
	S.Push(n);
	cout << S.GetInd() << " - ind " <<  S.IsEmpty() << " and " << S.IsFull() << endl;
	cin >> S; //ввести количество элементов и сам стек
	cout << S.GetInd() << " - ind " << S.IsEmpty() << " and " << S.IsFull() << endl;
	cout << S.Get() << endl;
	cout << S << endl << endl;

	cin >> k; //ввести размер зацикленной очереди
	TQueue<int> Q(5);
	cout << Q.GetInd() << " - ind " << Q.GetEnd() << " - end "<< Q.IsEmpty() << " and " << Q.IsFull() << endl;
	cin >> n; //ввести элемент который необходимо положить в очередь
	Q.Push(n);
	cout << Q.GetInd() << " - ind " << Q.GetEnd() << " - end " << Q.IsEmpty() << " and " << Q.IsFull() << endl;
	cin >> Q; //ввести количество элементов и саму очередь 
	cout << Q.GetInd() << " - ind " << Q.GetEnd() << " - end " << Q.IsEmpty() << " and " << Q.IsFull() << endl;
	cout << Q.Get() << endl;
	cout << Q << endl;
	return 0;
}