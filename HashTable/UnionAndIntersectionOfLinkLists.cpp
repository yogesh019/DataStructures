/**
Intersection (list1, list2)
Initialize result list as NULL. Traverse list1 and look for its each element in list2, if the element is present in list2, 
then add the element to result.

Union (list1, list2):
Initialize result list as NULL. Traverse list1 and add all of its elements to the result.
Traverse list2. If an element of list2 is already present in result then do not insert it to result, otherwise insert.

This method assumes that there are no duplicates in the given lists.

Time Complexity: O(mn) for both union and intersection operations. Here m is the number of elements in first list and n is the number of elements in second list.
**/

/**
Second Method

Union (list1, list2)

Initialize the result list as NULL and create an empty hash table. Traverse both lists one by one, for each element being visited, 
look the element in hash table. If
the element is not present, then insert the element to result list. If the element is present, then ignore it.

Intersection (list1, list2)

Initialize the result list as NULL and create an empty hash table. Traverse list1. For each element being visited in list1, 
insert the element in hash table.
Traverse list2, for each element being visited in list2, look the element in hash table. If the element is present, then 
insert the element to result list.
If the element is not present, then ignore it.
**/

#include<iostream>
#include<unordered_set>
#include<list>

using namespace std;

template<typename T>
list<T>Union( list<T>&l1, list<T>&l2){
    unordered_set<T>check;
    list<T>l;
    for(typename list<T>::iterator it=l1.begin();it!=l1.end();it++){
        check.insert(*it);
        l.push_back(*it);
    }
    for(typename list<T>::iterator it=l2.begin();it!=l2.end();it++){
        if(check.find(*it)==check.end()){
            l.push_back(*it);
        }
    }
    return l;
}
template<typename T>
list<T>Intersection( list<T>&l1, list<T>&l2){
    unordered_set<T>check;
    list<T>l;
    for(typename list<T>::iterator it=l1.begin();it!=l1.end();it++){
       
        check.insert(*it);
    }
    for(typename list<T>::iterator it=l2.begin();it!=l2.end();it++){
        if(check.find(*it)!=check.end()){
            l.push_back(*it);
        }
    }
    return l;
}
int main(){
    list<int>l1,l2;
    int value;
    cout<<"Enter the first list(-1 to terminate): ";
    cin>>value;
    while(value!=-1){
        l1.push_back(value);
        cin>>value;
    }
    cout<<"Enter the second list(-1 to terminate): ";
    cin>>value;
    while(value!=-1){
        l2.push_back(value);
        cin>>value;
    }
    cout<<"Union of the lists are: "<<endl;
    list<int>temp=Union(l1,l2);
    for(list<int>::iterator it=temp.begin();it!=temp.end();it++){
        cout<<(*it)<<" ";
    }
    temp.clear();
    cout<<endl<<"Intersection of the lists :"<<endl;
    temp=Intersection(l1,l2);
    for(list<int>::iterator it=temp.begin();it!=temp.end();it++){
        cout<<(*it)<<" ";
    }


    return 0;
}




