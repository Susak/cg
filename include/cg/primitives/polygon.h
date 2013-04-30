#pragma once

#include "cg/primitives/point.h"
#include <vector>

namespace cg
{
    template<class Scalar>
    struct polygon
    {
    protected:
        std::vector<point_2t<Scalar> > points;

    public:
        polygon(std::vector<point_2t<Scalar> > _points)
        {
            if (_points.size() < 3)
            {
                throw std::logic_error("it is not a polygon");
            }
            points = _points;
        }

        point_2t<Scalar> const & operator[](size_t i) const
        {
            return points[i];
        }

        point_2t<Scalar> & operator[](size_t i)
        {
            return points[i];
        }

        int size() const
        {
            return points.size();
        }

        std::vector<point_2t<Scalar> > const & get_vector() const
        {
            return points;
        }
    };

    template<class Scalar>
    struct convex_polygon : polygon<Scalar>
    {
        convex_polygon(std::vector<point_2t<Scalar> > _points) : polygon<Scalar>(_points)
        {}
    };
}
