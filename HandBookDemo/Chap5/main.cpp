/**************************************************
 * Essential C++ -- Stanley Lippman
 * Addison-Wesley 
 * ISBN 0-201-48518-4
 * homepage: www.objectwrite.com
 * email: slippman@objectwrite.com
 *************************************************/

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

// various test programs
extern void prog1();
extern void prog2();
extern void prog3();

int main()
{
	// prog1();
	// prog2();
	prog3();
    system("pause");
	return 0; // quiets vc++
}

class num_sequence;
ostream& operator<<( ostream &os, const num_sequence &ns );

class num_sequence {
public:
	typedef vector<unsigned int>::iterator iterator;

    virtual ~num_sequence(){};
	virtual num_sequence *clone() const = 0;
			 
	virtual unsigned int elem( int pos ) const = 0;
	virtual bool         is_elem(  unsigned int ) const=0;
	virtual int          pos_elem( unsigned int ) const=0;

    virtual const char*  what_am_i() const = 0;
	static  int          max_elems(){ return _max_elems; }
	virtual ostream&     print( ostream &os = cout ) const = 0;
	
	virtual bool operator ==( const num_sequence& ) const=0;
    virtual bool operator !=( const num_sequence& ) const=0;
	
	// to work, need to remove all pure virtual functions
    // virtual num_sequence operator+( const num_sequence& ) const=0;

	virtual iterator begin() const = 0;
	virtual iterator end() const = 0;

	virtual int length()  const = 0;
    virtual int beg_pos() const = 0; 

	virtual void set_position( int pos ) = 0;
	virtual void set_length( int pos ) = 0;

	virtual	const vector<unsigned int>* sequence() const=0;
  
protected:
	// static const int    _max_elems = 1024;	
	// for compilers not supporting const static
	enum { _max_elems = 1024 };

    virtual void gen_elems( int pos ) const = 0;
	bool check_integrity( int pos, int size ) const; 
};

ostream& operator<<( ostream &os, const num_sequence &ns )
{  
    return ns.print( os );
}

class Fibonacci : public num_sequence {
public:
   Fibonacci( int beg_pos = 1, int len = 1 )
   {  set_position( beg_pos ); set_length( len ); }

   virtual num_sequence *clone() const 
		 { return new Fibonacci( *this ); }
		
   virtual unsigned int elem( int pos ) const;
   virtual bool        is_elem(  unsigned int elem ) const;
   virtual int         pos_elem( unsigned int elem ) const;

   virtual const char* what_am_i() const { return "Fibonacci"; }
   virtual ostream&    print( ostream &os = cout ) const; 

   virtual bool operator==( const num_sequence &rhs ) const;
   virtual bool operator!=( const num_sequence &rhs ) const; 

   virtual int length()  const { return _length;  }
   virtual int beg_pos() const { return _beg_pos; }

   virtual void set_position( int pos );
   virtual void set_length( int pos );

   virtual iterator begin() const 
		 { return _elems.begin()+_beg_pos-1; }

   virtual iterator end() const 
		 { return _elems.begin() + _beg_pos + _length; }	 

   virtual const vector<unsigned int>* 
	     sequence() const { return & _elems; }

protected:
   virtual void gen_elems( int pos ) const;
   static vector< unsigned int > _elems;
   
   int _length; 	
   int _beg_pos; 

private:
	int _calc_pos( unsigned int elem ) const;
};

class Pell : public num_sequence {
public:
   Pell( int beg_pos = 1, int len = 1 )
   {  set_position( beg_pos ); set_length( len ); }

   virtual num_sequence *clone() const 
		 { return new Pell( *this ); }
		
   virtual unsigned int elem( int pos ) const;
   virtual bool is_elem(  unsigned int elem ) const;
   virtual int pos_elem( unsigned int elem ) const;

   virtual const char* what_am_i() const { return "Pell"; }
   virtual ostream&    print( ostream &os = cout ) const; 

   virtual int length()  const { return _length;  }
   virtual int beg_pos() const { return _beg_pos; }

   virtual void set_position( int pos );
   virtual void set_length( int pos );

   virtual bool operator==( const num_sequence &rhs ) const;
   virtual bool operator!=( const num_sequence &rhs ) const; 

   virtual iterator begin() const 
		 { return _elems.begin()+_beg_pos-1; }

   virtual iterator end() const 
		 { return _elems.begin() + _beg_pos + _length; }

   virtual const vector<unsigned int>* 
	     sequence() const { return & _elems; }

protected:
   virtual void gen_elems( int pos ) const;
   static vector< unsigned int > _elems;
   
   int _length; 	
   int _beg_pos; 

private:
	int _calc_pos( unsigned int elem ) const;
};

class Lucas : public num_sequence {
public:
   Lucas( int beg_pos = 1, int len = 1 )
   {  set_position( beg_pos ); set_length( len ); }

   virtual num_sequence *clone() const 
		 { return new Lucas( *this ); }
		
   virtual unsigned int elem( int pos ) const;
   virtual bool        is_elem(  unsigned int elem ) const;
   virtual int         pos_elem( unsigned int elem ) const;

   virtual const char* what_am_i() const { return "Lucas"; }
   virtual ostream&    print( ostream &os = cout ) const; 

   virtual int length()  const { return _length;  }
   virtual int beg_pos() const { return _beg_pos; }

   virtual void set_position( int pos );
   virtual void set_length( int pos );

   virtual bool operator==( const num_sequence &rhs ) const;
   virtual bool operator!=( const num_sequence &rhs ) const; 

   virtual iterator begin() const 
		 { return _elems.begin()+_beg_pos-1; }

   virtual iterator end() const 
		 { return _elems.begin() + _beg_pos + _length; }

   virtual const vector<unsigned int>* 
	     sequence() const { return & _elems; }

protected:
   virtual void gen_elems( int pos ) const;
   static vector< unsigned int > _elems;
   	 
   int _length; 	
   int _beg_pos; 

private:
	int _calc_pos( unsigned int elem ) const;
};

class Triangular : public num_sequence {
public:
   Triangular( int beg_pos = 1, int len = 1 )
   {  set_position( beg_pos ); set_length( len ); }

   virtual num_sequence *clone() const 
		 { return new Triangular( *this ); }
		
   virtual unsigned int elem( int pos ) const;
   virtual bool is_elem(  unsigned int elem ) const;
   virtual int  pos_elem( unsigned int elem ) const;

   virtual const char* what_am_i() const { return "Triangular"; }
   virtual ostream&    print( ostream &os = cout ) const; 

   virtual int length()  const { return _length;  }
   virtual int beg_pos() const { return _beg_pos; }

   virtual void set_position( int pos );
   virtual void set_length( int pos );

   virtual bool operator==( const num_sequence &rhs ) const;
   virtual bool operator!=( const num_sequence &rhs ) const; 

   virtual iterator begin() const 
		 { return _elems.begin()+_beg_pos-1; }

   virtual iterator end() const 
		 { return _elems.begin() + _beg_pos + _length; }

   virtual const vector<unsigned int>* 
	     sequence() const { return & _elems; }

protected:
   virtual void gen_elems( int pos ) const;
   static vector< unsigned int > _elems;
   	
   int _length; 	
   int _beg_pos;
   
private:
	int _calc_pos( unsigned int elem ) const;
};

class Square : public num_sequence {
public:
   Square( int beg_pos = 1, int len = 1 )
   {  set_position( beg_pos ); set_length( len ); }

   virtual num_sequence *clone() const 
		 { return new Square( *this ); }
		
   virtual unsigned int elem( int pos ) const;
   virtual bool        is_elem(  unsigned int elem ) const;
   virtual int         pos_elem( unsigned int elem ) const;

   virtual const char* what_am_i() const { return "Square"; }
   virtual ostream&    print( ostream &os = cout ) const; 

   virtual int length()  const { return _length;  }
   virtual int beg_pos() const { return _beg_pos; }

   virtual void set_position( int pos );
   virtual void set_length( int pos );

   virtual bool operator==( const num_sequence &rhs ) const;
   virtual bool operator!=( const num_sequence &rhs ) const; 

   virtual iterator begin() const 
		 { return _elems.begin()+_beg_pos-1; }

   virtual iterator end() const 
		 { return _elems.begin() + _beg_pos + _length; }

   virtual const vector<unsigned int>* 
	     sequence() const { return & _elems; }

protected:
   virtual void gen_elems( int pos ) const;
   static vector< unsigned int > _elems;
   	
   int _length; 	
   int _beg_pos; 

private:
	int _calc_pos( unsigned int elem ) const;
};

class Pentagonal : public num_sequence {
public:
   Pentagonal( int beg_pos = 1, int len = 1 )
   {  set_position( beg_pos ); set_length( len ); }

   virtual num_sequence *clone() const 
		 { return new Pentagonal( *this ); }
		
   virtual unsigned int elem( int pos ) const;
   virtual bool        is_elem(  unsigned int elem ) const;
   virtual int         pos_elem( unsigned int elem ) const;

   virtual const char* what_am_i() const { return "Pentagonal"; }
   virtual ostream&    print( ostream &os = cout ) const; 

   virtual int length()  const { return _length;  }
   virtual int beg_pos() const { return _beg_pos; }

   virtual void set_position( int pos );
   virtual void set_length( int pos );

   virtual bool operator==( const num_sequence &rhs ) const;
   virtual bool operator!=( const num_sequence &rhs ) const; 

   virtual iterator begin() const 
		 { return _elems.begin()+_beg_pos-1; }

   virtual iterator end() const 
		 { return _elems.begin() + _beg_pos + _length; }

   virtual const vector<unsigned int>* 
	     sequence() const { return & _elems; }

protected:
   virtual void gen_elems( int pos ) const;
   static vector< unsigned int > _elems;
   	
   int _length; 	
   int _beg_pos; 

private:
	int _calc_pos( unsigned int elem ) const;
};

inline void 
display( ostream &os, const num_sequence &ns, 
		 int pos, int elem_val )
{
	os << "The element at position " << pos 
	   << " for the "
	   << ns.what_am_i() 
	   << " sequence is " << elem_val << endl;
}

inline void 
display( ostream &os, const num_sequence &ns, int pos )
{
	os << "The element at position " 
	   << pos            << " for the "
	   << ns.what_am_i() << " sequence is " 
	   << ns.elem( pos ) << endl;
}

// actual programs exercising the hierarchy
// normally would go in a program text file: .cpp

void prog1()
{
	const int pos = 8;

	Fibonacci fib;	
	display( cout, fib, pos );

	Pell pell;
	display( cout, pell, pos );

	Lucas lucas;
	display( cout, lucas, pos );

	Triangular trian;
	display( cout, trian, pos );
	
	Square square;
	display( cout, square, pos );

	Pentagonal penta;
    display( cout, penta, pos );

}

void prog2()
{
	Fibonacci  fib( 1, 8 );
	Pell       pell( 4, 6 );
	Lucas      lucas( 7, 10 );
	Triangular trian( 1, 12 );
	Square     square( 6, 6 );
	Pentagonal penta( 1, 8 );

	cout << "fib: " << fib << '\n'
	     << "pell: " << pell << '\n'
		 << "lucas: " << lucas << '\n'
		 << "trian: " << trian << '\n'
		 << "square: " << square << '\n'
		 << "penta: " << penta << endl;
};

void prog3()
{
	num_sequence *pns = 0;
	int elem_val = 0;
	const int pos = 8;
	const int find_pos = 14;

	int elem_values[] = { 377, 80782, 843, 105, 196, 287 }; 
	// for ( int ix = 0; ix < 6; ++ix ) // test all
	for ( int ix = 0; ix < 1; ++ix ) // test 1 at time
	{
		// for testing, just insure that we try
		// out each derived class instance ...

		switch( ix ) {
		case 0:
			pns = new Fibonacci( 1, 8 );
			break;
		case 1:
			delete pns;
			pns = new Pell( 1, 8 );
			break;
		case 2:
			delete pns;
			pns = new Lucas( 1, 8 );
			break;
		case 3:
			delete pns;
			pns = new Triangular( 1, 8 );
			break;
		case 4:
			delete pns;
			pns = new Square( 1, 8 );
			break;
		case 5:
			delete pns;
			pns = new Pentagonal( 1, 8 );
			break;
		default:
			delete pns;
			return;
		}

          elem_val = pns->elem( pos );
          display( cout, *pns, pos, elem_val );
		  cout << pns->what_am_i() << " : ( " 
			   << pns->beg_pos()   << ", "
			   << pns->length()    << " ) : "
			   << *pns;
		  cout << endl;

		  pns->set_length( 12 );
		  cout << *pns << endl;

		  cout << "num_sequence::is_elem() ";
		  if ( ! pns->is_elem( elem_val ) ||
			     pns->is_elem( 2*elem_val ))
				 cout << "failed\n";
		  else cout << "ok!\n";

		  cout << "copy constructor and equality ";
		  num_sequence *pns2 = pns->clone();
		  if ( *pns != *pns2 )
			   cout << "failed!\n";
		  else cout << "ok!\n";

		  pns2->set_position( 5 );
 
		  int posit = pns->pos_elem( elem_val );
		  if ( pns->pos_elem( elem_val ) != pos )
	           cout << "pos_elem() failed : " << posit << "\n";
		  else cout << "pos_elem() -- ok: " << posit << "\n";

		  posit = pns->pos_elem( elem_values[ix] );
          if ( posit != find_pos ) 
			   cout << "pos_elem(): not found but grown: failed: " 
			        << posit << " correct: " << find_pos << "\n";
		  else cout << "pos_elem(): not found but grown: ok\n";

		  cout << "about to print final ns vector: \n";
		  pns->print();
		  cout << endl;
		  
		  cout << "ns2: should begin at position 5:\n" << *pns2 << endl;
	}
}

// derived class implementations
// normally would go in a program text file: .cpp

vector<unsigned int> Fibonacci::_elems;
vector<unsigned int> Pell::_elems;
vector<unsigned int> Lucas::_elems;
vector<unsigned int> Triangular::_elems;
vector<unsigned int> Square::_elems;
vector<unsigned int> Pentagonal::_elems;

bool num_sequence::
check_integrity( int pos, int size ) const
{
	if ( pos <= 0 || pos > _max_elems )
	{
		 cerr << "!! invalid position: " << pos
			  << " Cannot honor request\n";
		 return false;
	}

	if ( pos > size )
		 gen_elems( pos );

	return true;
}
			 
unsigned int Fibonacci::
elem( int pos ) const 
{
	    if ( ! check_integrity( pos, _elems.size() ))
			 return 0;

		return _elems[ pos-1 ];
}

unsigned int Pell::
elem( int pos ) const 
{
	    if ( ! check_integrity( pos, _elems.size() ))
			 return 0;

		return _elems[ pos-1 ];
}

unsigned int Lucas::
elem( int pos ) const 
{
	    if ( ! check_integrity( pos, _elems.size() ))
			 return 0;

		return _elems[ pos-1 ];
}

unsigned int Triangular::
elem( int pos ) const 
{
	    if ( ! check_integrity( pos, _elems.size() ))
			 return 0;

		return _elems[ pos-1 ];
}

unsigned int Square::
elem( int pos ) const 
{
	    if ( ! check_integrity( pos, _elems.size() ))
			 return 0;

		return _elems[ pos-1 ];
}

unsigned int Pentagonal::
elem( int pos ) const 
{
	    if ( ! check_integrity( pos, _elems.size() ))
			 return 0;

		return _elems[ pos-1 ];
}

ostream& Fibonacci:: 
print( ostream &os ) const
{
	int elem_pos = _beg_pos-1;
	int end_pos = elem_pos + _length;

    if ( end_pos > _elems.size() )
		 Fibonacci::gen_elems( end_pos );

	 os << "( "
	    << _beg_pos << " , "
	    << _length << " ) ";

	while ( elem_pos < end_pos )
		     os << _elems[ elem_pos++ ] << ' ';

	return os;
}

ostream& Pell::print( ostream &os ) const
{
	int elem_pos = _beg_pos-1;
	int end_pos = elem_pos + _length;

    if ( end_pos > _elems.size() )
		  Pell::gen_elems( end_pos );

	 os << "( "
	    << _beg_pos << " , "
	    << _length << " ) ";

	while ( elem_pos < end_pos )
		     os << _elems[ elem_pos++ ] << ' ';

	return os;
}

ostream& Lucas::print( ostream &os ) const 
{
	int elem_pos = _beg_pos-1;
	int end_pos = elem_pos + _length;

    if ( end_pos > _elems.size() )
		 Lucas::gen_elems( end_pos );

	 os << "( "
	    << _beg_pos << " , "
	    << _length << " ) ";

	while ( elem_pos < end_pos )
		     os << _elems[ elem_pos++ ] << ' ';

	return os;
}

ostream& Triangular::print( ostream &os ) const 
{
	int elem_pos = _beg_pos-1;
	int end_pos = elem_pos + _length;

    if ( end_pos > _elems.size() )
		 Triangular::gen_elems( end_pos );

	 os << "( "
	    << _beg_pos << " , "
	    << _length << " ) ";

	while ( elem_pos < end_pos )
		     os << _elems[ elem_pos++ ] << ' ';

	return os;
}

ostream& Square::print( ostream &os ) const 
{
	int elem_pos = _beg_pos-1;
	int end_pos = elem_pos + _length;

    if ( end_pos > _elems.size() )
		 Square::gen_elems( end_pos );

	 os << "( "
	    << _beg_pos << " , "
	    << _length << " ) ";

	while ( elem_pos < end_pos )
		     os << _elems[ elem_pos++ ] << ' ';

	return os;
}

ostream& Pentagonal::print( ostream &os ) const 
{
	int elem_pos = _beg_pos-1;
	int end_pos = elem_pos + _length;

    if ( end_pos > _elems.size() )
		 Pentagonal::gen_elems( end_pos );

	 os << "( "
	    << _beg_pos << " , "
	    << _length << " ) ";

	while ( elem_pos < end_pos )
		     os << _elems[ elem_pos++ ] << ' ';

	return os;
}

void Fibonacci::
gen_elems( int pos ) const
{   
	if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( _elems.empty() )
       { _elems.push_back( 1 ); _elems.push_back( 1 ); }

    if ( _elems.size() <= pos )
	{
		    int ix = _elems.size();
			int n_2 = _elems[ ix-2 ], 
				n_1 = _elems[ ix-1 ];

			int elem;
			for ( ; ix <= pos; ++ix ){
				    elem = n_2 + n_1; 
					// cout << "gen_elems: " << elem << endl;
					_elems.push_back( elem );
					n_2 = n_1; n_1 = elem;
			}
	 }
}
   
void Pell::
gen_elems( int pos ) const    
{    
	if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( _elems.empty() )
       {  _elems.push_back( 1 ); _elems.push_back( 2 ); }

    if ( _elems.size() <= pos )
	{
		    int ix = _elems.size();
			int n_2 = _elems[ ix-2 ], 
				n_1 = _elems[ ix-1 ];

			int elem;
			for ( ; ix <= pos; ++ix ){
				    elem = n_2 + 2 * n_1; 
					_elems.push_back( elem );
					n_2 = n_1; n_1 = elem;
			}
	 }
}
   
void Lucas::
gen_elems( int pos ) const
{     
	if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( _elems.empty() )
       {  _elems.push_back( 1 ); _elems.push_back( 3 ); }

    if ( _elems.size() <= pos )
	{
		    int ix = _elems.size();
			int n_2 = _elems[ ix-2 ], 
				n_1 = _elems[ ix-1 ];

			int elem;
			for ( ; ix <= pos; ++ix ){
				    elem = n_2 +  n_1; 
					_elems.push_back( elem );
					n_2 = n_1; n_1 = elem;
			}
	 }
}    

void Triangular::
gen_elems( int pos ) const
{
	if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( _elems.size() <= pos )
	{
		int end_pos = pos+1;
		int ix = _elems.size()+1;
		cout << "tri: ix: " << ix << " pos: " << pos << endl;
		for ( ; ix <= end_pos; ++ix )
			  _elems.push_back( ix*(ix+1)/2 );
	}
}

void Square::
gen_elems( int pos ) const
{
 	if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( _elems.size() <= pos )
	{
		int end_pos = pos + 1;
		int ix = _elems.size()+1;
		for ( ; ix <= end_pos; ++ix )
			  _elems.push_back( ix*ix );
	}
}   
    
void Pentagonal::
gen_elems( int pos ) const
{
 	if ( pos <= 0 || pos > max_elems() )
		 return;

    if ( _elems.size() <= pos )
	{
		int end_pos = pos + 1;
		int ix = _elems.size()+1;
		for ( ; ix <= end_pos; ++ix )
			  _elems.push_back( ix*(3*ix-1)/2 );
	}
}

bool Fibonacci::
operator==( const num_sequence &rhs ) const 
{
	return ( _beg_pos == rhs.beg_pos() ) &&
		   ( _length  == rhs.length() );
}

bool Fibonacci::
operator !=( const num_sequence &rhs ) const 
{ return ! ( *this == rhs ); }

void Fibonacci::
set_position( int pos )
{
	if ( pos <= 0 || pos > _max_elems ){
		 cerr << "!! invalid position: " << pos 
			  << " setting pos to default value of 1\n"
			  << "If inadequate, invoke set_position(pos)\n";
		 pos = 1;
	}
	_beg_pos = pos;
}

void Fibonacci::
set_length( int len )
{
	if ( len <= 0 || len + _beg_pos - 1 > _max_elems ){
		 cerr << "!! invalid length for this object: " << len 
			  << " setting length to default value of 1\n"
			  << "If inadequate, invoke set_length(len)\n";
	     len = 1;
	}
	_length = len;
}

bool Lucas::
operator==( const num_sequence &rhs ) const 
{
	return ( _beg_pos == rhs.beg_pos() ) &&
		   ( _length  == rhs.length() );
}

bool Lucas::
operator !=( const num_sequence &rhs ) const 
{ return ! ( *this == rhs ); }

void Lucas::
set_position( int pos )
{
	if ( pos <= 0 || pos > _max_elems ){
		 cerr << "!! invalid position: " << pos 
			  << " setting pos to default value of 1\n"
			  << "If inadequate, invoke set_position(pos)\n";
		 pos = 1;
	}
	_beg_pos = pos;
}

void Lucas::
set_length( int len )
{
	if ( len <= 0 || len + _beg_pos - 1 > _max_elems ){
		 cerr << "!! invalid length for this object: " << len 
			  << " setting length to default value of 1\n"
			  << "If inadequate, invoke set_length(len)\n";
	     len = 1;
	}
	_length = len;
}

bool Pell::
operator==( const num_sequence &rhs ) const 
{
	return ( _beg_pos == rhs.beg_pos() ) &&
		   ( _length  == rhs.length() );
}

bool Pell::
operator !=( const num_sequence &rhs ) const 
{ return ! ( *this == rhs ); }

void Pell::
set_position( int pos )
{
	if ( pos <= 0 || pos > _max_elems ){
		 cerr << "!! invalid position: " << pos 
			  << " setting pos to default value of 1\n"
			  << "If inadequate, invoke set_position(pos)\n";
		 pos = 1;
	}
	_beg_pos = pos;
}

void Pell::
set_length( int len )
{
	if ( len <= 0 || len + _beg_pos - 1 > _max_elems ){
		 cerr << "!! invalid length for this object: " << len 
			  << " setting length to default value of 1\n"
			  << "If inadequate, invoke set_length(len)\n";
	     len = 1;
	}
	_length = len;
}

bool Triangular::
operator==( const num_sequence &rhs ) const 
{
	return ( _beg_pos == rhs.beg_pos() ) &&
		   ( _length  == rhs.length() );
}

bool Triangular::
operator !=( const num_sequence &rhs ) const 
{ return ! ( *this == rhs ); }

void Triangular::
set_position( int pos )
{
	if ( pos <= 0 || pos > _max_elems ){
		 cerr << "!! invalid position: " << pos 
			  << " setting pos to default value of 1\n"
			  << "If inadequate, invoke set_position(pos)\n";
		 pos = 1;
	}
	_beg_pos = pos;
}

void Triangular::
set_length( int len )
{
	if ( len <= 0 || len + _beg_pos - 1 > _max_elems ){
		 cerr << "!! invalid length for this object: " << len 
			  << " setting length to default value of 1\n"
			  << "If inadequate, invoke set_length(len)\n";
	     len = 1;
	}
	_length = len;
}

bool Square::
operator==( const num_sequence &rhs ) const 
{
	return ( _beg_pos == rhs.beg_pos() ) &&
		   ( _length  == rhs.length() );
}

bool Square::
operator !=( const num_sequence &rhs ) const 
{ return ! ( *this == rhs ); }

void Square::
set_position( int pos )
{
	if ( pos <= 0 || pos > _max_elems ){
		 cerr << "!! invalid position: " << pos 
			  << " setting pos to default value of 1\n"
			  << "If inadequate, invoke set_position(pos)\n";
		 pos = 1;
	}
	_beg_pos = pos;
}

void Square::
set_length( int len )
{
	if ( len <= 0 || len + _beg_pos - 1 > _max_elems ){
		 cerr << "!! invalid length for this object: " << len 
			  << " setting length to default value of 1\n"
			  << "If inadequate, invoke set_length(len)\n";
	     len = 1;
	}
	_length = len;
}

bool Pentagonal::
operator==( const num_sequence &rhs ) const 
{
	return ( _beg_pos == rhs.beg_pos() ) &&
		   ( _length  == rhs.length() );
}

bool Pentagonal::
operator !=( const num_sequence &rhs ) const 
{ return ! ( *this == rhs ); }

void Pentagonal::
set_position( int pos )
{
	if ( pos <= 0 || pos > _max_elems ){
		 cerr << "!! invalid position: " << pos 
			  << " setting pos to default value of 1\n"
			  << "If inadequate, invoke set_position(pos)\n";
		 pos = 1;
	}
	_beg_pos = pos;
}

void Pentagonal::
set_length( int len )
{
	if ( len <= 0 || len + _beg_pos - 1 > _max_elems ){
		 cerr << "!! invalid length for this object: " << len 
			  << " setting length to default value of 1\n"
			  << "If inadequate, invoke set_length(len)\n";
	     len = 1;
	}
	_length = len;
}

// is_elem() returns true if the element passed in a valid element 
// in the object's sequence. For example, if the object represents 
// a fibonacci sequence { 1,1, 2, 3, 5, 8, 13, 21, 34, 45}, beginning 
// as position 3 for a length of 2, then
//    Obj.is_elem( 1 ); // false
//    Obj.is_elem( 3 ); // true
//    Obj.is_elem( 5 ); // false
//    Obj.is_elem( 4 ); // false

bool Fibonacci::
is_elem( unsigned int elem ) const
{
	if ( ! check_integrity( _beg_pos, _length ))
		 return false;

	return binary_search( begin(), end(), elem );
}

bool Pell::
is_elem( unsigned int elem ) const
{
	if ( ! check_integrity( _beg_pos, _length ))
		 return false;

	return binary_search( begin(), end(), elem );
}

bool Lucas::
is_elem( unsigned int elem ) const
{
	if ( ! check_integrity( _beg_pos, _length ))
		 return false;

	return binary_search( begin(), end(), elem );
}

bool Triangular::
is_elem( unsigned int elem ) const
{
	if ( ! check_integrity( _beg_pos, _length ))
		 return false;

	return binary_search( begin(), end(), elem );
}

bool Square::
is_elem( unsigned int elem ) const
{
	if ( ! check_integrity( _beg_pos, _length ))
		 return false;

	return binary_search( begin(), end(), elem );
}

bool Pentagonal::
is_elem( unsigned int elem ) const
{
	if ( ! check_integrity( _beg_pos, _length ))
		 return false;

	return binary_search( begin(), end(), elem );
}

// pos_elem() returns the position of an element within the sequence 
// independent of what the object's position and length. The object 
// simply is used to identify the sequence for which to return a position. 
// If the element value is invalid, return 0. For example, if the object 
// represents a fibonacci sequence, then
//     Obj.pos_elem( 1 ); // returns 1 - ignore duplicate
//     Obj.pos_elem( 32 ); // returns 9
//     Obj.pos_elem( very-large-instance ); // your choice
//     Obj.pos_elem( 4 ); // return 0

int Fibonacci::
pos_elem( unsigned int elem ) const
{
	cout << "pos_elem( " << elem << " )\n";

	iterator iter;

	if ( _elems[ _elems.size()-1 ] < elem )
		 return _calc_pos( elem );

	if (( iter = find( _elems.begin(), _elems.end(), elem ))
		       == _elems.end() )
		 return 0;
    else return distance( _elems.begin(), iter )+1;
}

int Pell::
pos_elem( unsigned int elem ) const
{
	cout << "pos_elem( " << elem << " )\n";

	iterator iter;

	if ( _elems[ _elems.size()-1 ] < elem )
		 return _calc_pos( elem );

	if (( iter = find( _elems.begin(), _elems.end(), elem ))
		       == _elems.end() )
		 return 0;
    else return distance( _elems.begin(), iter )+1;
}

int Lucas::
pos_elem( unsigned int elem ) const
{
	cout << "pos_elem( " << elem << " )\n";

	iterator iter;

	if ( _elems[ _elems.size()-1 ] < elem )
		 return _calc_pos( elem );

	if (( iter = find( _elems.begin(), _elems.end(), elem ))
		       == _elems.end() )
		 return 0;
    else return distance( _elems.begin(), iter )+1;
}

int Triangular::
pos_elem( unsigned int elem ) const
{
	cout << "pos_elem( " << elem << " )\n";

	iterator iter;

	if ( _elems[ _elems.size()-1 ] < elem )
		 return _calc_pos( elem );

	if (( iter = find( _elems.begin(), _elems.end(), elem ))
		       == _elems.end() )
		 return 0;
    else return distance( _elems.begin(), iter )+1;
}

int Square::
pos_elem( unsigned int elem ) const
{
	cout << "pos_elem( " << elem << " )\n";

	iterator iter;

	if ( _elems[ _elems.size()-1 ] < elem )
		 return _calc_pos( elem );

	if (( iter = find( _elems.begin(), _elems.end(), elem ))
		       == _elems.end() )
		 return 0;
    else return distance( _elems.begin(), iter )+1;
}

int Pentagonal::
pos_elem( unsigned int elem ) const
{
	cout << "pos_elem( " << elem << " )\n";

	iterator iter;

	if ( _elems[ _elems.size()-1 ] < elem )
		 return _calc_pos( elem );

	if (( iter = find( _elems.begin(), _elems.end(), elem ))
		       == _elems.end() )
		 return 0;
    else return distance( _elems.begin(), iter )+1;
}

int Fibonacci::
_calc_pos( unsigned int elem ) const
{
    // presumption is that check_integrity() has passed
	int pos = _elems.size()-1;

    cout << "calc_pos invoked()!: elem: " << elem 
		 << " pos: " << pos 
		 << " at: "  << _elems[ pos ] 
		 << "\n";

	while (( pos < _max_elems ) && 
		   ( _elems[ pos ] < elem ))
	{
		   gen_elems( ++pos );
		   cout << " pos: " << pos 
		        << " at: "  << _elems[ pos ] << endl;
	}

	return (( pos < _max_elems ) && 
		   ( _elems[pos] == elem )) ? pos+1 : 0;
}

int Pell::
_calc_pos( unsigned int elem ) const
{
    // presumption is that check_integrity() has passed
	int pos = _elems.size()-1;

    cout << "calc_pos invoked()!: elem: " << elem 
		 << " pos: " << pos 
		 << " at: "  << _elems[ pos ] 
		 << "\n";

	while (( pos < _max_elems ) && 
		   ( _elems[ pos ] < elem ))
	{
		   gen_elems( ++pos );
		   cout << " pos: " << pos 
		        << " at: "  << _elems[ pos ] << endl;
	}

	return (( pos < _max_elems ) && 
		   ( _elems[pos] == elem )) ? pos+1 : 0;
}

int Lucas::
_calc_pos( unsigned int elem ) const
{
    // presumption is that check_integrity() has passed
	int pos = _elems.size()-1;

    cout << "calc_pos invoked()!: elem: " << elem 
		 << " pos: " << pos 
		 << " at: "  << _elems[ pos ] 
		 << "\n";

	while (( pos < _max_elems ) && 
		   ( _elems[ pos ] < elem ))
	{
		   gen_elems( ++pos );
		   cout << " pos: " << pos 
		        << " at: "  << _elems[ pos ] << endl;
	}

	return (( pos < _max_elems ) && 
		   ( _elems[pos] == elem )) ? pos+1 : 0;
}

int Triangular::
_calc_pos( unsigned int elem ) const
{
    // presumption is that check_integrity() has passed
	int pos = _elems.size()-1;

    cout << "calc_pos invoked()!: elem: " << elem 
		 << " pos: " << pos 
		 << " at: "  << _elems[ pos ] 
		 << "\n";

	while (( pos < _max_elems ) && 
		   ( _elems[ pos ] < elem ))
	{
		   gen_elems( ++pos );
		   cout << " pos: " << pos 
		        << " at: "  << _elems[ pos ] << endl;
	}

	return (( pos < _max_elems ) && 
		   ( _elems[pos] == elem )) ? pos+1 : 0;
}

int Square::
_calc_pos( unsigned int elem ) const
{
    // presumption is that check_integrity() has passed
	int pos = _elems.size()-1;

    cout << "calc_pos invoked()!: elem: " << elem 
		 << " pos: " << pos 
		 << " at: "  << _elems[ pos ] 
		 << "\n";

	while (( pos < _max_elems ) && 
		   ( _elems[ pos ] < elem ))
	{
		   gen_elems( ++pos );
		   cout << " pos: " << pos 
		        << " at: "  << _elems[ pos ] << endl;
	}

	return (( pos < _max_elems ) && 
		   ( _elems[pos] == elem )) ? pos+1 : 0;
}

int Pentagonal::
_calc_pos( unsigned int elem ) const
{
    // presumption is that check_integrity() has passed
	int pos = _elems.size()-1;

    cout << "calc_pos invoked()!: elem: " << elem 
		 << " pos: " << pos 
		 << " at: "  << _elems[ pos ] 
		 << "\n";

	while (( pos < _max_elems ) && 
		   ( _elems[ pos ] < elem ))
	{
		   gen_elems( ++pos );
		   cout << " pos: " << pos 
		        << " at: "  << _elems[ pos ] << endl;
	}

	return (( pos < _max_elems ) && 
		   ( _elems[pos] == elem )) ? pos+1 : 0;
}
