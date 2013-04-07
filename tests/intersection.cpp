#include <gtest/gtest.h>
#include "cg/primitives/segment.h"
#include "cg/operations/intersection.h"

TEST(intersection, tests)
{
    cg::point_2 p_a1(0.0, 0.0), p_b1(1.0, 0.0);
    cg::point_2 p_a_1(0.5, 1.0), p_b_1(0.5, -1.0);
    cg::segment_2t<double> a(p_a1, p_b1), b(p_a_1, p_b_1);

    cg::point_2 p_a2(0.0, 0.0), p_b2(1.0, 0.0);
    cg::point_2 p_a_2(0.5, 0.0), p_b_2(1.5, 0.0);
    cg::segment_2t<double>  a1(p_a2, p_b2), b1(p_a_2, p_b_2);

    cg::point_2 p_a3(1.0, 2.0), p_b3(2.0, 1.0);
    cg::point_2 p_a_3(1.0, 0.0), p_b_3(-1.0, 0.0);
    cg::segment_2t<double>  a2(p_a3, p_b3), b2(p_a_3, p_b_3);

    cg::point_2 p_a4(0.0, 0.0), p_b4(1.0, 1.0);
    cg::point_2 p_a_4(1.0, 1.0), p_b_4(2.0, 2.0);
    cg::segment_2t<double>  a3(p_a4, p_b4), b3(p_a_4, p_b_4);

    cg::point_2 p_a5(0.0, 0.0), p_b5(1.0, 0.0);
    cg::point_2 p_a_5(1.0, 1.0), p_b_5(1.0, -1.0);
    cg::segment_2t<double>  a4(p_a5, p_b5), b4(p_a_5, p_b_5);

    cg::point_2 p_a6(0.0, 0.0), p_b6(1.0, 0.0);
    cg::point_2 p_a_6(1.1, 1.0), p_b_6(1.1, -1.0);
    cg::segment_2t<double>  a5(p_a6, p_b6), b5(p_a_6, p_b_6);

    EXPECT_TRUE(cg::intersection(a, b));

    EXPECT_TRUE(cg::intersection(a1, b1));

    EXPECT_FALSE(cg::intersection(a2, b2));

    EXPECT_TRUE(cg::intersection(a3, b3));

    EXPECT_TRUE(cg::intersection(a4, b4));

    EXPECT_FALSE(cg::intersection(a5, b5));
}

