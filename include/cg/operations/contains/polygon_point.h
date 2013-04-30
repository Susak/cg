#pragma once

#include "cg/operations/orientation.h"
#include "cg/primitives/polygon.h"
#include "cg/operations/has_intersection/segment_segment.h"
#include "cg/io/point.h"

namespace cg
{
    template<class Scalar>
    bool contains(polygon<Scalar> const & pol, point_2t<Scalar> const & x)
    {
        int count = 0;

        for (int i = 0; i < pol.size(); ++i)
        {
            int next = (i + 1) % pol.size();
            // point belongs to the side of the polygon
            if (orientation(pol[i], pol[next], x) == CG_COLLINEAR &&
                    (x.x >= pol[i].x && x.x <= pol[next].x || x.x >= pol[next].x && x.x <= pol[i].x))
            {
                return true;
            }
            // we will consider only the intersection with the segments to the right of the point
            if ((x.x <= pol[i].x || x.x <= pol[next].x) &&
                has_intersection(segment_2t<Scalar>(x, point_2t<Scalar>(std::max(pol[i].x, pol[next].x), x.y)),
                                      segment_2t<Scalar>(pol[i], pol[next])))
            {
                // ray intersects of segment
                if (x.y > pol[i].y && x.y < pol[next].y || x.y > pol[next].y && x.y < pol[i].y ||
                    x.y == pol[i].y && x.y < pol[next].y || x.y == pol[next].y && x.y < pol[i].y)
                {
                    count++;
                }
            }
        }
        return count % 2;
    }
}