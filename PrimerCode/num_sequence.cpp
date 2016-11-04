#include "num_sequence.h"

inline num_sequence::num_sequence(int beg_pos,int len,vector<UINT>& re):_relems(re)
{
	set_position(beg_pos);
	set_length(len);
}

inline bool num_sequence::operator ==(const num_sequence& rhs) const
{
	return (_beg_pos==rhs._beg_pos)&&(_length==rhs._length);
}

inline bool num_sequence::operator !=(const num_sequence& rhs) const
{
	return !(*this==rhs);
}

inline void num_sequence::set_position(int pos)
{
	if ( pos <= 0 || pos > _max_elems ){
		 cerr << "!! invalid position: " << pos 
			  << " setting pos to default value of 1\n"
			  << "If inadequate, invoke set_position(pos)\n";
		 pos = 1;
	}
	_beg_pos = pos;
}

inline void num_sequence::set_length( int len )
{
	if ( len <= 0 || len + _beg_pos - 1 > _max_elems ){
		 cerr << "!! invalid length for this object: " << len 
			  << " setting length to default value of 1\n"
			  << "If inadequate, invoke set_length(len)\n";
	     len = 1;
	}
	_length = len;
}

inline UINT num_sequence::elem(int pos) const
{
	return(!check_integrity(pos,_relems.size()))?0:_relems[pos-1];
}

#include<typeinfo>

inline const char* num_sequence::what_am_i() const
{
	//RTTI Run-Time Type Identification
	return typeid(*this).name();
}

inline bool num_sequence::check_integrity(int pos,int size) const
{
	bool status = true;

	if ( pos <= 0 || pos > _max_elems ){
		 cerr << "!! invalid position: " << pos
			  << " Cannot honor request\n";
		 status = false;
	}
    else if ( pos > size )
		      gen_elems( pos );

	return status;
}

bool num_sequence::is_elem(UINT elem) const
{
	return ( ! check_integrity( _beg_pos, _length ))
	 ? false : binary_search( begin(), end(), elem );
}

ostream & num_sequence::print(ostream &os) const
{
	int elem_pos=_beg_pos-1;
	int end_pos=elem_pos+_length;
	
	if(!check_integrity(end_pos,_relems.size()))
		return os;
	
	os<<"("<<_beg_pos<<" "<<_length<<")";
	
	while(elem_pos<end_pos)
		os<<_relems[elem_pos++]<<" ";
		
	return os;
}

int num_sequence::pos_elem(UINT elem) const
{
	cout<<"pos_elem("<<elem<<"\n";
	
	if(_relems[_relems.size()-1]<elem)
		return _calc_pos(elem);
		
	iterator iter=find(_relems.begin(),_relems.end(),elem);
	//if not found, return 0, otherwise return postion in the series
	return (iter==_relems.end())?0:distance(_relems.begin(),iter)+1;
}

int num_sequence::_calc_pos( unsigned int elem ) const
{
	// presumption is that check_integrity() has passed
	int pos = _relems.size()-1;
	
	cout<<"calc_pos invoked()!: elems:"<<elem<<" pos:"<<pos
	    <<" at:"<<_relems[pos]<<"\n";
	    
	while((pos<_max_elems)&&(_relems[pos]<elem))
	{
		gen_elems(++pos);//a virtual call
		cout<<"pos: "<<pos<<"at: "<<_relems[pos]<<endl;
	}
	
	return ((pos<_max_elems)&&(_relems[pos]==elem))?(pos+1):0;
}


