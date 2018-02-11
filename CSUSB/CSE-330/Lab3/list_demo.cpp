//list_demo.cpp
/*
Because of the use of template when defining the List and node classes,
unfortunately, we do need to include the .cpp files here for the
current compilers.
*/
#include <iostream>
#include "list.cpp"
#include "node.cpp"

using namespace std;

template <typename T>
void print_list( List<T> &aList )
{
  typename List<T>::iterator start, stop;
  start = aList.begin();	stop = aList.end();
  while ( start != stop ){
    cout << *start << ",\t";
    ++start;
  }
  cout << endl;
}
template <class T>
void demo( List<T> &aList )
{
  typedef double T1;

  typename List<T>::iterator it = aList.begin();
  cout << "\nDisplaying demo function and implementing its member functions:\n";
  cout << "1) empty() = " << aList.empty() 
       << "\n0 = false, therefore the list is NOT empty" << endl;
  cout << "\n2) size() = " << aList.size() << endl;

  T1 n = 44;
  aList.insert(it, n);
  cout << "\n3) insert(44) to the list:" << endl;
  print_list(aList);
  it = aList.begin();
  it++;
  n = 50;
  aList.insert(it, n);
  cout << "\n3) insert(55) to the list using it++" << endl;
  print_list(aList);

  aList.pop_front();
  cout << "\n4) pop_front()" << endl;
  print_list( aList );

  aList.pop_back();
  cout << "\n5) pop_back()" << endl;
  print_list( aList );

  //find() 
  n = 9;
  auto tmp_itr = aList.find(n);
  if ( tmp_itr == aList.end() );
  cout << "\n6) find(55) = " << *aList.find(n) << endl;

  typename List<T>::iterator start = aList.begin(), end = aList.end();
  aList.erase(start, end);
  cout << "\n7) erase()" << endl;
  cout << "The list has been erased" << endl;
  cout << "\nempty() = " << aList.empty() 
       << "\n1 = true, therefore the list is empty" << endl;
  print_list( aList );
}

int main()
{
  typedef double T;

  List<T> aList;	//a list
  T n;
  cout<<"Adnar Lozano\nCSE 330\nLab3\nCreated on 04/19/17"<<endl;
  while ( true ) {
    cout << "Enter a number, -99 to terminate: ";
    cin >> n;
    if ( n == -99 )
	break;
    aList.push_front( n );	//insert into list at front
  }  //while
  cout << "\nYou have entered the list: " << endl;
  print_list( aList ); 
  demo( aList );
  return 0;
}
