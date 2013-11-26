//  Copyright Neil Groves 2009.
//  Copyright Eric Niebler 2013
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef RANGES_V3_ALGORITHM_REMOVE_COPY_IF_HPP
#define RANGES_V3_ALGORITHM_REMOVE_COPY_IF_HPP

#include <utility>
#include <algorithm>
#include <range/v3/begin_end.hpp>
#include <range/v3/concepts.hpp>
#include <range/v3/range_traits.hpp>
#include <range/v3/utility/bindable.hpp>

namespace ranges
{
    inline namespace v3
    {
        struct remover_copier_if : bindable<remover_copier_if>
        {
            /// \brief template function remove_copy_if
            ///
            /// range-based version of the remove_copy_if std algorithm
            ///
            /// \pre InputRange is a model of the InputRange concept
            /// \pre OutputIterator is a model of the OutputIterator concept
            /// \pre Predicate is a model of the Predicate concept
            /// \pre InputIterator's value type is convertible to Predicate's argument type
            /// \pre out_it is not an iterator in the range rng
            template<typename InputRange, typename OutputIterator, typename Predicate>
            static OutputIterator
            invoke(remover_copier_if, InputRange && rng, OutputIterator out_it, Predicate pred)
            {
                CONCEPT_ASSERT(ranges::InputRange<InputRange>());
                return std::remove_copy_if(ranges::begin(rng), ranges::end(rng),
                    detail::move(out_it), detail::move(pred));
            }
        };

        constexpr remover_copier_if remove_copy_if {};
    }
}

#endif // include guard
