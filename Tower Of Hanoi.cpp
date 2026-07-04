#include<iostream>
#include<Windows.h>
#include<iomanip>
using namespace std;
class Stack
{
public:
	Stack(const int&);
	void push(const int&);
	int pop();
	int top();
	void display()const;
	int getSize()const { return current; }
	bool isEmpty()const { return current == -1; }
	bool isFull()const { return current == maxSize - 1; }
	friend void displayTower(const Stack& st, const int& ignoreSpaceLen);
	~Stack();
protected:
	int* arr;
	int maxSize;
	int current;
};
Stack::Stack(const int& size) :maxSize(size < 0 ? 0 : size),
	arr(size == 0 ? nullptr : new int[size] {})
{
	this->current = -1;
}
Stack::~Stack()
{
	delete[]this->arr; this->arr = nullptr;
}
void Stack::push(const int& value) {
	if (isFull()) throw("Error: Stack Overflow!\n");
	arr[++current] = value;
}
int Stack::pop() {
	if (isEmpty()) throw("Error: Stack Underflow!");
	return arr[current--];
}
int Stack::top() {
	if (isEmpty()) throw("Error: Stack Underflow!");
	return arr[current];
}
void Stack::display()const {
	for (int i = maxSize - 1; i >= 0; --i) {
		if (i <= current) cout << arr[i] << " ";
	}
}
void displayTower(const Stack& st, const int& spaces) {
	for (int i = st.maxSize - 1; i >= 0; --i) {
		for (int i = 1; i <= spaces; ++i) cout << "\t";
		cout << "|  ";
		if (i <= st.current) {
			cout << st.arr[i];
		}
		else cout << "-";
		cout << "  |\n";
	}
	for (int i = 1; i <= spaces; ++i) cout << "\t";
	cout << "-------";
}
void rendering(const int& val, const int& size, const int& position1, const int& position2, const int& current1, const int& current2) {
	cout << "\033[?25l";
	for (int i = 1; i < size - current1; ++i)cout << "\n";
	if (position1 == 0) for (int i = 1; i <= 4; ++i) cout << "\t";
	else if (position1 == 1) for (int i = 1; i <= 5; ++i) cout << "\t";
	else if (position1 == 2) for (int i = 1; i <= 6; ++i) cout << "\t";
	cout << "|   \b \b";
	for (int i = current1; i <= size + 1; ++i)
	{
		if (i < size)cout << "-";
		cout << "\033[F";
		if (position1 == 0) for (int i = 1; i <= 4; ++i) cout << "\t";
		else if (position1 == 1) for (int i = 1; i <= 5; ++i) cout << "\t";
		else if (position1 == 2) for (int i = 1; i <= 6; ++i) cout << "\t";
		if (i < size - 1)cout << "|  ";
		else cout << "   ";
		cout << val;
		Sleep(50);
		cout << "\b \b";
	}
	cout << " ";
	int spaces{ 7 };
	position1 < position2 ? spaces *= position2 - position1 : spaces *= position1 - position2;
	if (abs(position1 - position2) == 2) ++spaces;
	if (position1 < position2) {
		for (int i = 0; i <= spaces; ++i)
		{
			cout << "\b ";
			cout << val;
			Sleep(30);
		}
	}
	else {
		for (int i = 0; i <= spaces; ++i)
		{
			cout << "\b \b\b";
			cout << val;
			Sleep(30);
		}
	}
	for (int i = size+2; i > current2+1; --i)
	{
		if (i < size && i>current2+1) cout << "\b-\n";
		else cout << "\b \n";
		//if(i+1>current2)cout << "\b \n";
		if (position2 == 0) for (int i = 1; i <= 4; ++i) cout << "\t";
		else if (position2 == 1) for (int i = 1; i <= 5; ++i) cout << "\t";
		else if (position2 == 2) for (int i = 1; i <= 6; ++i) cout << "\t";
		if(i<=size)cout << "|  ";
		else cout << "   ";
		cout << val;
		Sleep(50);
	}
	for (int i = 1; i < size - current2-1; ++i)cout << "\033[F";
 }
void welcome() {
	cout << "\t\t\t\t  ------------------\n";
	cout << "\t\t\t\t  | Tower of Hanoi |\n";
	cout << "\t\t\t\t  ------------------\n";

}
int main() {
	welcome();
	int noOfRings{};
	cout << "\nEnter Number of Rings: ";
	cin >> noOfRings;
	// check for -ve value
	if (noOfRings <= 0) {
		cout << "Error: Invalid No of Rings";
		return 0;
	}
	Stack bars[3]{ noOfRings , noOfRings, noOfRings };
	for (int i = noOfRings; i >= 1; --i) { bars[0].push(i); }
	bool isShifted = false;
	short lastMovedDiskNo = 0;
	int barNo = 0;
	int countMoves{};
	cout << "\n\n\n\n\n";
	displayTower(bars[0], 4);
	for (int i = 0; i < noOfRings; ++i) cout << "\033[F";
	displayTower(bars[1], 5);
	for (int i = 0; i < noOfRings; ++i) cout << "\033[F";
	displayTower(bars[2], 6);
	cout << "\n\t\t\t  -----------------------------------\n";
	cout << "\t\t\t\t\tMoves: " << countMoves << endl;
	Sleep(300);
	for (int i = 0; i < noOfRings + 3; ++i) cout << "\033[F";
	while (!isShifted)
	{
		for (int i = 0; i < 3; ++i) {
			if (!bars[i].isEmpty() && bars[i].top() != lastMovedDiskNo) {
				int disk = bars[i].top();

				disk % 2 == 0 ? i == 2 ? barNo = 0 : barNo = i + 1 : i == 0 ? barNo = 2 : barNo = i - 1;

				if (bars[barNo].isEmpty() || bars[barNo].top() > disk) {

					rendering(
						bars[i].top(),
						noOfRings,
						i,
						barNo,
						bars[i].getSize(),
						bars[barNo].getSize()
					);

					bars[i].pop();
					bars[barNo].push(disk);

					lastMovedDiskNo = disk;

					++countMoves;

					system("cls");

					welcome();

					cout << "\n\n\n\n\n";

					displayTower(bars[0], 4);

					for (int j = 0; j < noOfRings; ++j)
						cout << "\033[F";

					displayTower(bars[1], 5);

					for (int j = 0; j < noOfRings; ++j)
						cout << "\033[F";

					displayTower(bars[2], 6);

					cout << "\n\t\t\t  -----------------------------------\n";
					cout << "\t\t\t\t\tMoves: " << countMoves << endl;

					Sleep(300);

					for (int j = 0; j < noOfRings + 3; ++j)
						cout << "\033[F";

					break;
				}
			}
		}

		if (bars[barNo].isFull())
			isShifted = true;
	}
	cout << "\n\n\n\n\n\n\n\n\n\n";
	return 0;
}