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
/// progressive download information
class pdin : public box
{

public:

    static const std::string TYPE;

public:
    pdin(std::weak_ptr<box> parent) :
        box(pdin::TYPE, parent)
    { }

    void read(uint64_t size, byte_stream& bs)
    {
        box::read(size, bs);
        bs.skip(m_remaining_bytes);
    }
};
}
}
