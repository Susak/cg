#pragma once
#include "cg/primitives/range.h"
#include "cg/operations/orientation.h"
#include "cg/primitives/point.h"

template<class Scalar>
inline bool intersection(cg::range_t<Scalar> const &a, cg::range_t<Scalar> const &b)
{
    if (cg::orientation(a.inf, a.sup, b.inf) == 0 && cg::orientation(a.inf, a.sup, b.sup) == 0)
        return a.contains(b.inf) || a.contains(b.sup);

    if (cg::orientation(a.inf, a.sup, b.inf) != cg::orientation(a.inf, a.sup, b.sup) &&
            cg::orientation(b.inf, b.sup, a.inf) != cg::orientation(b.inf, b.sup, a.sup))
        return true;

    return false;
}

