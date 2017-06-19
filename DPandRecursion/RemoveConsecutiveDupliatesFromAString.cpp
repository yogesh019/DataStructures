#include<iostream>
#include<set>
using namespace std;

/* Note
 * If we want to removed duplicates from an array then one aproach is to sort the elements of array(~Time(O(nlogn))) , by doing this
 * all the duplicates are consecutiveand thenwe can remove them easily in O(n) go , so total time complexity is 0(nlogn)
 * But the order of non-duplicate elemnts does-not remain same in this approach
 *
 * second approach is to use hashing , to keep the order of non duplicatessame
 * Time Complexity is O(n)
 * Space Complexity is O(n)
 */

void removeConsecutiveDuplicates(char*str){
    if(!str[0]){
        return;
    }
    if(str[0]==str[1]){
        int i=1;
        while(str[i]){
            str[i-1]=str[i];
            i++;
        }
        str[i-1]=0;
        
    }
    removeConsecutiveDuplicates(str+1);
    return;
}

void removeDuplicates(char*str){
    set<char>s;
    int i=0,j=0;
    while(str[i]){
        if(s.find(str[i])==s.end()){
            s.insert(str[i]);
            str[j]=str[i];
            j++;
        }
        i++;
    }
    str[j]=0;
    return;
}
int main(){
    char str[100];
    cout<<"Enter the string: ";
    cin.getline(str,100);
    removeDuplicates(str);
    cout<<str<<endl;
    return 0;
}


