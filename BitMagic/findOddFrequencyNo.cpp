/*We have to find the number occuring odd no. of time in a given collection
 * We can traverse the array and store the a pair<element, count> in an 
 * unordered_map , the time complexity is O(n) but exra space is also required.
 * So use another technique that will solve in O(n) time with no extra space
 * We take xor of all elements in the array. xor of a number with 0 is number itslef and xor of a no. with itself is 0
 *
 *
x (+) 0 = x
XORing with 0 gives you back the same number. Thus, 0 is the identity for XOR.

x (+) 1 = \x
XORing with 1 gives you back the negation of the bit. Again, this comes from the truth table. For bitwise XOR, the property 
is slightly different: x ^ ~0 = ~x . That is, if you XOR with all 1's, the result will be the bitwise negation of x.

x (+) x = 0
XORing x with itself gives you 0. That's because x is either 0 or 1, and 0 (+) 0 = 0 and 1 (+) 1 = 0.

XOR is associative.
That is: (x (+) y) (+) z = x (+) (y (+) z).

You can verify this by using truth tables.

XOR is commutative.
That is: x (+) y = y (+) x.

You can verify this by using truth tables.
*/
#include<iostream>
using namespace std;

int getOddFrequenyNo(int*arr,int n){
    int res=0;
    for(int i=0;i<n;i++){
        res=res^arr[i];
    }
    return res;
}
int main(){
    int arr[100],n;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Number occuring Odd no.of times: "<<getOddFrequenyNo(arr,n);
    cout<<endl;
    return 0;
}

