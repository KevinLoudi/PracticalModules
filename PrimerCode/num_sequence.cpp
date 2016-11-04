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
