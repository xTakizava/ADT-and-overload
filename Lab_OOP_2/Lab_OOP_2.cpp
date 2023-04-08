#include "ATD.h"

int main()
{
	ATD First(10);
	ATD Second(10);
	//add
	First.Add('A');
	First.Add('B');
	First.Add('C');
	Second.Add('D');
	Second.Add('E');
	Second.Add('F');
	cout << "First object data is ";
	First.Print();
	cout << "Second object data is ";
	Second.Print();
	//copying
	ATD Three = First + Second;
	ATD Four = First + 'D';
	//check contain
	if (First.Contains('B'))
		cout << "First contains 'B'" << endl;
	else
		cout << "First not contain 'B'" << endl;
	if (Second.Contains('B'))
		cout << "Second contains 'B'" << endl;
	else
		cout << "Second not contain 'B'" << endl;
	//find index element
	int firstIndex = First.IndexOf('C');
	int secondIndex = Second.IndexOf('E');
	//check equals
	if (First == Second)
		cout << "First and Second EXAMPLE are Equal" << endl;
	else
		cout << "First and Second EXAMPLE are not Equal" << endl;
	if (First == Three)
		cout << "First and Three EXAMPLE are Equal" << endl;
	else
		cout << "First and Three EXAMPLE are not Equal" << endl;
	if (Four.Add('D'))
		cout << "Added new element to Four EXAMPLE" << endl;
	else
		cout << "Could not add new element to Four EXAMPLE" << endl;
	//removing
	First.Remove('B');
	cout << "First after removing element is ";
	//print
	First.Print();
	cin.get();
	cin.get();
}