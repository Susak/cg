#include "gtest/gtest.h"

#include "cg/douglas_peucker/douglas_peucker.h"
#include "cg/io/point.h"
#include "cg/primitives/point.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace cg;

TEST (douglas, simple1)
{
    vector<point_2> pts( {point_2(0, 0), point_2(1, 0), point_2(2, 0)} );

    vector<point_2> pt;
    douglas_peucker(pts.begin(), pts.end(), back_inserter(pt), 2.0);
    for (int i = 0; i < pt.size(); i++) {
        std::cout << pt[i] << " ";
    }
}
TEST (douglas, simple2)
{
    vector<point_2> pts( {point_2(0, 0), point_2(1, -1), point_2(2, -1), point_2(3, 0)} );

    vector<point_2> pt;
    douglas_peucker(pts.begin(), pts.end(), back_inserter(pt), 0.2);
    for (int i = 0; i < pt.size(); i++) {
        std::cout << pt[i] << " ";
    }
}