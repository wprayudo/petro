// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include "../parser.hpp"
#include "../box/all.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <memory>

namespace petro
{
    class h264_extractor
    {
    public:
        h264_extractor(std::ifstream& file);
        ~h264_extractor();

        const std::shared_ptr<sequence_parameter_set> sps();
        const std::shared_ptr<picture_parameter_set> pps();
        uint32_t found_samples();
        std::vector<char> next_nalu();
        bool has_next_nalu();

    private:
        uint32_t read_nalu_size(std::istream& file, uint8_t length_size);

    private:
        std::ifstream& m_file;
        uint32_t m_found_samples = 0;
        uint32_t sample = 0;
        uint32_t m_sample_size;
        uint32_t m_chunk = 0;
        std::vector<uint64_t> m_chunk_offsets;
        std::shared_ptr<petro::box::avcc> m_avcc;
        std::shared_ptr<petro::box::stsz> m_stsc;
        std::shared_ptr<petro::box::stsz> m_stsz;
    };
}
