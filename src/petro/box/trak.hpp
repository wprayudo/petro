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
    /// container for an individual track or stream
    template<class Parser>
    class trak : public box
    {

    public:

        static const std::string TYPE;

    public:
        trak(uint32_t size, byte_stream& bs, box* parent=nullptr):
            box(trak::TYPE, size, bs, parent)
        {
            Parser p;
            p.read(m_children, bs.data(), m_remaining_bytes, this);
            bs.skip(m_remaining_bytes);
        }
    };

    template<class Parser>
    const std::string trak<Parser>::TYPE = "trak";
}
}