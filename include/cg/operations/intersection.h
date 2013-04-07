#pragma once

#include "cg/primitives/segment.h"
#include "cg/operations/orientation.h"

namespace cg {

    template<class Scalar>
    inline bool intersection(segment_2t<Scalar> const &a, segment_2t<Scalar> const &b)
    {
        auto or1 = orientation(a[0], a[1], b[0]);
        auto or2 = orientation(a[0], a[1], b[1]);

        if (or1 == CG_COLLINEAR && or2 == CG_COLLINEAR) {
            return (min(a) <= b[0] && max(a) >= b[0])
            || (min(a) <= b[1] && max(a) >= b[1])
            || (min(b) <= a[0] && max(b) >= a[0])
            || (min(b) <= a[1] && max(b) >= a[1]);
        }

        auto or3 = orientation(b[0], b[1], a[0]);
        auto or4 = orientation(b[0], b[1], a[1]);

        return (or1 != or2) && (or3 != or4);
    }
}
