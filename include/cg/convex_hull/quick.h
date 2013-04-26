#include "cg/operations/orientation.h"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/linestring.hpp>
#include <boost/geometry/geometries/point_xy.hpp>


namespace cg {


    template<class BidIter>
    BidIter contour_quick_hull(BidIter p, BidIter q, BidIter l, BidIter r)
    {
        if (p == q) {
            std::iter_swap(p, r);
            return p;
        }

        
    }

    template<class BidIter>
    BidIter quick_hull(BidIter p, BidIter q)
    {
        if (p == q)
            return p;

        std::iter_swap(p, std::min_element(p, q));
        BidIter l = p++;

        if (p == q)
            return p;

        std::iter_swap(p + 1, std::max_element(p, q));
        BidIter r = p + 1;

        BidIter m = std::stable_partition(p + 1, q, [l, r] (point_2 const &a)
                                    {
                                        switch (orientation(*l, *r, a))
                                        {
                                            case CG_LEFT : return true;
                                            case CG_RIGHT : return false;
                                            case CG_COLLINEAR : return false;
                                        }
                                    }
                                );
        contour_quick_hull(p + 1, m, l, r);
        contour_quick_hull(m + 1, q, r, l);

    }

}