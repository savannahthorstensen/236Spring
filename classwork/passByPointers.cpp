/* notes
- NEVER return adresress on stack memory
- can return pointers
- aPtr created on stack 
*/

#include <iostream>
using namespace std;

/*void swap(int* xPtr, int* yPtr){
    int t = *xPtr;
    *xPtr = *yPtr;
    *yPtr = t;


}

int main(){
    int a = 5;
    int b = 7;
    swap(&a, &b);
}

*/


//returnring pointer
int * getValue(){
    int* xPtr = new int;
    return xPtr;
}
void main(){
    int* aPtr = getValue();
    cout << *aPtr;
    delete aPtr;
}


