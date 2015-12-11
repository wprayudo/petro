// Copyright Steinwurf ApS 2015.
// All Rights Reserved

#pragma once

#include <cstdint>
#include <string>

#include "box.hpp"
#include "../byte_stream.hpp"

namespace petro
{
namespace box
{
    /// binary XML container
    class bxml : public box
    {

    public:

        static const std::string TYPE;

    public:
        bxml(std::weak_ptr<box> parent);

        void read(uint64_t size, byte_stream& bs);
    };
}
}
