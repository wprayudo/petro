// Copyright Steinwurf ApS 2015.
// All Rights Reserved

#include <petro/box/udta.hpp>
#include <petro/box/box.hpp>
#include <petro/parser.hpp>

#include <gtest/gtest.h>

#include <memory>

TEST(box_test_udta, construct)
{
    std::weak_ptr<petro::box::box> parent;
    petro::box::udta<petro::parser<>> b(parent);
    EXPECT_EQ("udta", b.type());
}