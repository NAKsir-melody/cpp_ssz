/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 
#include <ethash/ethash.hpp>
#include <ethash/keccak.hpp>

#include "include/Common.h"
#include "include/cpp_ssz_bool.h"
#include "include/cpp_ssz_uint.h"
#include "include/cpp_ssz_bytes.h"
#include "include/cpp_ssz_bytesN.h"
#include "include/cpp_ssz_list.h"
#include "include/cpp_ssz_tuple.h"
#include "include/cpp_ssz_container.h"
#include "include/cpp_ssz_util.h"

using namespace std;
using namespace ssz;

#include "include/test.h"

int main()
{
    uint8_t data[4] = {0x1,0x2,0x3,0x4};
    ethash::hash256 h = ethash::keccak256(data, 4);
    bytes a(h.bytes,32);
    print_hex(a);
    return 0;
}
