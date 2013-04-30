#include <gtest/gtest.h>

#include <cg/operations/contains/segment_point.h>
#include <cg/operations/contains/triangle_point.h>
#include "cg/operations/contains/convex_polygon_point.h"
#include "cg/operations/contains/polygon_point.h"



TEST(contains, segment_point)
{
   using cg::point_2;

   cg::segment_2 s(point_2(0, 0), point_2(2, 2));
   for (size_t l = 0; l != 2; ++l)
      EXPECT_TRUE(cg::contains(s, s[l]));

   EXPECT_TRUE(cg::contains(s, point_2(1, 1)));

   EXPECT_FALSE(cg::contains(s, point_2(-1, -1)));
   EXPECT_FALSE(cg::contains(s, point_2(4, 4)));

   EXPECT_FALSE(cg::contains(s, point_2(1, 0)));
   EXPECT_FALSE(cg::contains(s, point_2(0, 1)));
}

TEST(contains, convex_polygon_point)
{
    cg::point_2 a(0, 0), b(1, 0), c(2, 1), d(2, 2), e(1, 3), f(0, 3), g(-1, 2), h(-1, 1);
    EXPECT_EQ(cg::contains(cg::convex_polygon<double>({a, b ,c, d, e, f, g, h}), cg::point_2(1, 1)), true);
    EXPECT_EQ(cg::contains(cg::convex_polygon<double>({a, b ,c, d, e, f, g, h}), cg::point_2(-1, 1)), true);
    EXPECT_EQ(cg::contains(cg::convex_polygon<double>({a, b ,c, d, e, f, g, h}), cg::point_2(-0.0001, 0.0001)), true);
    EXPECT_EQ(cg::contains(cg::convex_polygon<double>({a, b ,c, d, e, f, g, h}), cg::point_2(-0.0001, 0)), false);
    EXPECT_EQ(cg::contains(cg::convex_polygon<double>({a, b ,c, d, e, f, g, h}), cg::point_2(0.0001, 0)), true);
}

TEST(contains, small_test)
{
    cg::point_2 a(0, 0), b(1, 0), c(2, 1), d(2, 2), e(1, 3), f(0, 3), g(-1, 2), h(-1, -1), x(1, 1);
    EXPECT_EQ(cg::contains(cg::polygon<double>({a, b, c, d, e, f, g, h}), x), true);
}

TEST(contains, close_enough)
{
    cg::point_2 a(0, 0), b(5, 0), c(7, 3), d(0, .1), e(7, 5), f(0, 10), g(0, .11), h(-3, 5), i(-3, 2), x(-0.001, 1);
    EXPECT_EQ(cg::contains(cg::polygon<double>({a, b, c, d, e, f, g, h, i}), x), false);
}

TEST(contains, begin_from_vertex1)
{
    cg::point_2 a(0, 0), b(5, 0), c(7, 3), d(0, .1), e(7, 5), f(0, 10), g(0, .11), h(-3, 5), i(-3, 2), x(0, 10);
    EXPECT_EQ(cg::contains(cg::polygon<double>({a, b, c, d, e, f, g, h, i}), x), true);
}

TEST(contains, begin_from_vertex2)
{
    cg::point_2 a(0, 0), b(1, 0), c(1, 1), d(0, 1), x(0, 0);
    EXPECT_EQ(cg::contains(cg::polygon<double>({a, b, c, d}), x), true);
}

TEST(contains, point_match_with_side1)
{
    cg::point_2 a(0, 0), b(1, 0), c(1, 1), d(0, 1), x(0.5, 0);
    EXPECT_EQ(cg::contains(cg::polygon<double>({a, b, c, d}), x), true);
}

TEST(contains, point_match_with_side2)
{
    cg::point_2 a(0, 0), b(0.5, 0), c(1, 0), d(1, 1), e(1, 0), x(0.4, 0);
    EXPECT_EQ(cg::contains(cg::polygon<double>({a, b, c, d, e}), x), true);
}

TEST(contains, out_of_polygon1)
{
    cg::point_2 a(0, 0), b(0.5, 0), c(1, 0), d(1, 1), e(1, 0), x(-1, 0);
    EXPECT_EQ(cg::contains(cg::polygon<double>({a, b, c, d, e}), x), false);
}

TEST(contains, out_of_polygon2)
{
    cg::point_2 a(0, 0), b(2, 0), c(2, 2), d(0, 2), x(-1, 0);
    EXPECT_EQ(cg::contains(cg::polygon<double>({a, b, c, d}), x), false);
}

TEST(contains, point_in_triangle)
{
    cg::point_2 a(0, 0), b(5, 0), c(2.5, .0000000001), x(1, .0000000000000001);
    EXPECT_EQ(cg::contains(cg::polygon<double>({a, b, c}), x), true);
}

TEST(contains, triangle_point)
{
   using cg::point_2;

   cg::triangle_2 t(point_2(0, 0), point_2(1, 1), point_2(2, 0));

   for (size_t l = 0; l != 3; ++l)
      EXPECT_TRUE(cg::contains(t, t[l]));

   EXPECT_TRUE(cg::contains(t, point_2(1, 0.5)));

   EXPECT_TRUE(cg::contains(t, point_2(1, 0)));
   EXPECT_TRUE(cg::contains(t, point_2(0.5, 0.5)));
   EXPECT_TRUE(cg::contains(t, point_2(1.5, 0.5)));

   EXPECT_FALSE(cg::contains(t, point_2(0, 1)));
   EXPECT_FALSE(cg::contains(t, point_2(2, 1)));
   EXPECT_FALSE(cg::contains(t, point_2(1, -1)));
}