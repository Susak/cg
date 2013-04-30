#pragma once

#include "cg/operations/orientation.h"
#include "cg/primitives/triangle.h"
#include "cg/primitives/polygon.h"

namespace cg
{
    template<class Scalar>
    bool contains(convex_polygon<Scalar> const & pol, point_2t<Scalar> const & x)
    {
        std::vector<point_2t<Scalar> > vec = pol.get_vector();
        auto pos = std::lower_bound(
                    vec.begin(),
                    vec.end(),
                    x,
                    [vec](point_2t<Scalar> const & x, point_2t<Scalar> const & y)
                    {
                        return orientation(vec[0], x, y) == CG_LEFT;
                    });
        return contains(triangle_2t<Scalar>(vec[0], vec[pos - vec.begin()], vec[(pos - vec.begin() + 1) % vec.size()]), x);
    }
}
