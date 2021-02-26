#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std ;

template<class ForwardIterator, class T>
ForwardIterator Search(ForwardIterator start, ForwardIterator end, T key){
		while(start != end){
				if(*start == key)
					return start ;
			}
		return end ;
	}

class Book{
		public : 
			string author ;
			int price ;
		
		Book(string authorName, int bookPrice){
				this->author = authorName ;
				this->price = bookPrice ;
			}
			
		bool operator == (const Book &b1, const Book &b2){
				return b1.price == b2.price ;
			}
	};
	
/*class BookCompare{
		// compare by price
		bool operator ==(Book b1, Book b2){
				return b1.price == b2.price ;
			}
	};
	 */
		
int main(){

	int price ;
	string authorName ;
	Book b1("CLRS", 200) ;
	Book b2("Galvin", 300) ;
	Book b3("Hamsher", 350) ;
	vector<Book> books ;
	books.push_back(b1) ;
	books.push_back(b2) ;
	books.push_back(b3) ;
	
	cout<<"Books available : " ;
	for(auto book : books){
			cout<<"\n(name : "<<book.author<<", Price : "<<book.price<<" )" ;
		}
		
	cout<<"Enter Price : " ;
	cin>>price ;
	cout<<"\nEnter Author Name : " ;
	cin>>authorName ;
	Book b(authorName, price) ;
	
	vector<int>::iterator index = Search(books.begin(), books.end(), b) ;
	
	if(index != books.end())
		cout<<"Book Present" ;
	else
		cout<<"Book Not Present" ;
		
	return 0 ;
}
