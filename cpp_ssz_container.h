/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_CONTAINER_H__
#define __CPP_SSZ_CONTAINER_H__

#include "Common.h"

namespace ssz {

#if 0
template<class K, class V>
class Container
{
protected:
	unsigned int m_size;
    std::vector<std::pair<K, V>> m_data;
public:
	Container() 
	{ 
	}

	~Container()
	{
		m_data.empty();
	}

	unsigned int size() const { return m_data.size(); }
    std::vector<std::pair<K, V>>& data() { return m_data; }

// encode/decode section
    void from_bytes(bytes& data, byteorder bo);
	bytes to_bytes(unsigned int size, byteorder bo);

    // operators
/*
	bool operator==(const bytesN<N>& b)
	{
	     return this->m_data == b.get_data_array();
	}
*/
};


template<class K, class V>
void Container<K, V>::from_bytes(bytes& data, byteorder bo)
{
/*
	int prefix = 0;
    prefix |= data[0] << 16;
	prefix |= data[1] << 8;
	prefix |= data[2] << 0;
    prefix -= 8388608;

    for(int i=0; i< prefix; i++)
        m_data[i] = data[3+i];
*/
}

template<class K, class V>
bytes Container<K, V>::to_bytes(unsigned int size, byteorder bo)
{

    std::vector<byte> temp1;
    for (unsigned i=0; i < m_data.size(); i++) {
        bytes t1 = m_data[i].first.to_bytes(m_data[i].first.size(), little);
        temp1.insert(temp1.end(), t1.begin(), t1.end()); 
        bytes t2 = m_data[i].second.to_bytes(m_data[i].second.size(), little);
        temp1.insert(temp1.end(), t2.begin(), t2.end()); 
    }

	unsigned int prefix = temp1.size();
    std::vector<byte> temp;
    if(bo == little) {
        temp.push_back((prefix >> 0) & 0xff);
        temp.push_back((prefix >> 8) & 0xff);
        temp.push_back((prefix >> 16)& 0xff);
        temp.push_back((prefix >> 24)& 0xff);
    }
    else {
        temp.push_back((prefix >> 24)& 0xff);
        temp.push_back((prefix >> 16)& 0xff);
        temp.push_back((prefix >> 8) & 0xff);
        temp.push_back((prefix >> 0) & 0xff);
    }
    temp.insert(temp.end(), temp1.begin(), temp1.end());
	return bytes(temp); 
}
#else
template<class K, class V>
class Container: private std::vector<std::pair<K, V>>
{
public:
    using std::vector<std::pair<K, V>>::size; 
    using std::vector<std::pair<K, V>>::begin;
    using std::vector<std::pair<K, V>>::end;
    using std::vector<std::pair<K, V>>::push_back;
    using std::vector<std::pair<K, V>>::insert;
    using std::vector<std::pair<K, V>>::operator[]; 
    using std::vector<std::pair<K, V>>::const_iterator; 
    using std::vector<std::pair<K, V>>::resize; 
	Container() 
	{ 
	}
	~Container()
	{
	}

// encode/decode section
    void from_bytes(bytes& data, byteorder bo);
	bytes to_bytes(unsigned int size, byteorder bo);
};


template<class K, class V>
void Container<K, V>::from_bytes(bytes& data, byteorder bo)
{
/*
	int prefix = 0;
    prefix |= data[0] << 16;
	prefix |= data[1] << 8;
	prefix |= data[2] << 0;
    prefix -= 8388608;

    for(int i=0; i< prefix; i++)
        m_data[i] = data[3+i];
*/
}

template<class K, class V>
bytes Container<K, V>::to_bytes(unsigned int size, byteorder bo)
{

    std::vector<byte> temp1;
    for (unsigned i=0; i < this->size(); i++) {
        bytes t1 = this->at(i).first.to_bytes(this->at(i).first.size(), little);
        temp1.insert(temp1.end(), t1.begin(), t1.end()); 
        bytes t2 = this->at(i).second.to_bytes(this->at(i).second.size(), little);
        temp1.insert(temp1.end(), t2.begin(), t2.end()); 
    }

	unsigned int prefix = temp1.size();
    bytes temp;
    if(bo == little) {
        temp.push_back((prefix >> 0) & 0xff);
        temp.push_back((prefix >> 8) & 0xff);
        temp.push_back((prefix >> 16)& 0xff);
        temp.push_back((prefix >> 24)& 0xff);
    }
    else {
        temp.push_back((prefix >> 24)& 0xff);
        temp.push_back((prefix >> 16)& 0xff);
        temp.push_back((prefix >> 8) & 0xff);
        temp.push_back((prefix >> 0) & 0xff);
    }
    temp.insert(temp.end(), temp1.begin(), temp1.end());
	return bytes(temp); 
}
#endif
}//namespace
#endif
