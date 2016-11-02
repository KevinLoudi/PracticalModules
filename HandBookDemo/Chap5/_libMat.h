#ifndef _LIBMAT_H
#define _LIBMAT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class _libMat
{
	public:
		_libMat(){cout << "LibMat::LibMat() default constructor!\n";}
		virtual ~_libMat(){cout << "LibMat::~LibMat() destructor!\n";}
		virtual void print() const
		{cout << "LibMat::print() -- I am a LibMat object!\n";}
	protected:
};

class _book: public _libMat
{
	public:
		_book(const string &title,const string &author):_title(title),_author(author)
	    {
			cout << "Book::Book( " << _title
			 << ", " << _author << " )  constructor\n";
		}
		
		~_book()
		{cout << "Book::~Book() destructor!\n";}
		
		//override the print in base class 
		virtual void print() const
		{cout << "Book::print() -- I am a Book object!\n"
			 << "My title is: " << _title << '\n'
			 << "My author is: " << _author << endl;}
	    
	    const string& title() const{return _title;}
	    const string& author() const{return _author;}
		
	protected:
		string _title;
		string _author;
		
};

class _audioBook: public _book
{
	public:
		_audioBook(const string &title,const string &author,
		const string &narrator):_book(title,author),_narrator(narrator)
		{	cout << "AudioBook::AudioBook( " << _title
			 << ", " << _author 
			 << ", " << _narrator
			 << " )  constructor\n";}
		
		~_audioBook(){
			cout << "AudioBook::~AudioBook() destructor!\n";
		}
		
		virtual void print() const
		{	cout << "AudioBook::print() -- I am a AudioBook object!\n"
			 << "My title is: " << _title << '\n'
			 << "My author is: " << _author << '\n'
			 << "My narrator is: " << _narrator << endl;
		}
		
		const string& narrator() const{return _narrator;}
	protected:
		string _narrator;
};


class _magazine: public _book
{
	public:
		_magazine(const string &title,const string &author,
		const string &journelname):_book(title,author),_journelname(journelname)
		{
			cout << "_magazine::_magazine( " << _title
			 << ", " << _author 
			 << ", " << _journelname
			 << " )  constructor\n";}
		
		~_magazine(){
			cout << "_magazine::~_magazine() destructor!\n";}
			
		virtual void print() const
		{
			cout << "_magazine::print() -- I am a magazine object!\n"
			 << "My title is: " << _title << '\n'
			 << "My author is: " << _author << '\n'
			 << "My journelname is: " << _journelname << endl;
		}
		
		const string &journelname(){return _journelname;}
	protected:	
	    string _journelname;
};
#endif
