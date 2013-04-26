#pragma once

#include <boost/range/algorithm/sort.hpp>

#include <cg/operations/orientation.h>

#include "graham.h"

namespace cg {

template<class BadIter>
    BadIter andrew_hull(BadIter p, BadIter q)
    {
          if (p == q)
             return p;

          std::iter_swap(p, std::min_element(p, q));
          BadIter l = p++;
          if (p == q)
              return p;
          std::iter_swap(p, std::max_element(p, q));

          BadIter r = p++;

          if (p == q)
              return p;

          BadIter m = std::partition(p, q, [l, r] (point_2 const &a)
                        {
                            return  orientation(*l, *r, a) != CG_LEFT;
                        }
                );
         if (l != m) { std::iter_swap(r, m - 1); }
         if (l != m) { std::sort(l, m - 1); }
         std::sort(m, q, std::greater<point_2>());
         return contour_graham_hull(l, q);
    }
}