#pragma once

#include "cg/operations/orientation.h"
#include "cg/primitives/point.h"
#include <boost/lexical_cast.hpp>
#include <algorithm>

namespace cg
{
    template <class Scalar>
    class triangle_2t
    {
        typedef triangle_2t<double> triangle_2;
        typedef triangle_2t<float> triangle_2f;
        typedef triangle_2t<int> triangle_2i;
        point_2t<Scalar> a, b, c;

        public:
            triangle_2t (point_2t<Scalar> const &_a, point_2t<Scalar> const &_b, point_2t<Scalar> const &_c)
                    : a(_a)
                    , b(_b)
                    , c(_c)
            {
                auto min_point = std::min(std::min(a, b), c);
                std::swap(a, *min_point);

                if (orientation(a, b, c) == CG_LEFT)
                    std::swap(b, c);
            }

            template<class Scalar>
            point_2t<Scalar> &operator[](int index)
            {
                switch(i)
                {
                    case(0) : return a;
                    case(1) : return b;
                    case(2) : return c;
                    default :
                        throw std::logic_error("invalid index: " + boost::lexical_cast<std::string>(i));
                }
            }

            template<class Scalar>
            point_2t<Scalar> const &operator[](int index)
            {
                switch(i)
                {
                    case(0) : return a;
                    case(1) : return b;
                    case(2) : return c;
                    default :
                        throw std::logic_error("invalid index: " + boost::lexical_cast<std::string>(i));
                }
            }

    };


}