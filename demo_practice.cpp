#include <iostream>
using namespace std;
void modify(int *a, int *b) {
    *a = *a + 10;
    *b = *b + 20;
}
int main() {
    int x = 10;
    int y = 20;
    cout << "Before: " << x << " " << y << endl;
    modify(&x, &y);
    cout << "After: " << x << " " << y << endl;
    return 0;
}
