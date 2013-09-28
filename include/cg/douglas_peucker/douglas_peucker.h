#pragma once

#include "cg/primitives/segment.h"
#include "cg/primitives/point.h"
#include "cg/primitives/vector.h"

namespace cg {

    template<class Scalar>
    double distanse(segment_2t<Scalar> seg, point_2t<Scalar> pt)
    {
            vector_2t<Scalar> a(seg[1].x - seg[0].x, seg[1].y - seg[0].y), b(pt.x - seg[0].x, pt.y - seg[0].y);
            double t = (a * b) / (a.length() * a.length());
            if(t > 1)
                    return vector_2t<Scalar>(pt.x - seg[1].x, pt.y - seg[1].y).length();
            else if(t < 0)
                    return vector_2t<Scalar>(pt.x - seg[0].x, pt.y - seg[0].y).length();
            else
                    return fabs((a ^ b) / a.length());
    }

    template<class BidIter, class OutIter>
    OutIter douglas_peucker (BidIter begin, BidIter end, OutIter out, double eps, bool first_call = true)
    {
        double square_eps = eps * eps;
        cg::segment_2 seg(*begin, *(end - 1));
        BidIter max_it = begin;
        double m_dist = 0;

        for (BidIter it = begin + 1; it != end - 1; it++)
        {
            double cur_dist = distanse(seg, *it);
            if (m_dist < cur_dist)
            {
                m_dist = cur_dist;
                max_it = it;
            }
        }
        if (m_dist > square_eps)
        {
            out = douglas_peucker(begin, max_it + 1, out, eps, false);
            out = douglas_peucker(max_it, end, out, eps, false);
        } else {
            *out++ = *begin;
        }
        if (first_call == true) *out++ = *(end - 1);
        return out;
    }

}