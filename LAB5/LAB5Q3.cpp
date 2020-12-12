// LAB5Q3
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char aux_rod, char to_rod)
    {
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod <<" to rod " << to_rod<<endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, to_rod, aux_rod);
    cout << "Move disk " << n << " from rod " << from_rod <<" to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, from_rod, to_rod);
    }
int main()
{
    int n ;
    cout<<"Enter number of disks:";
    cin>>n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
