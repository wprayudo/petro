// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <cstdint>
#include <string>

#include "box.hpp"
#include "../byte_stream.hpp"

namespace petro
{
namespace box
{
/// container for an individual track or stream
template<class Parser>
class trak : public box
{

public:

    static const std::string TYPE;

public:
    trak(std::weak_ptr<box> parent) :
        box(trak::TYPE, parent)
    { }

    void read(uint64_t size, byte_stream& bs)
    {
        box::read(size, bs);
        Parser p;
        auto branched_bs = byte_stream(bs, m_remaining_bytes);
        p.read(branched_bs, shared_from_this());
    }
};

template<class Parser>
const std::string trak<Parser>::TYPE = "trak";
}
}
