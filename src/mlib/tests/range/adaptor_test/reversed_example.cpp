// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <mlib/tests/_pc_.h>

#include <mlib/range/adaptor/reversed.hpp>
#include <mlib/range/algorithm/copy.hpp>
#include <mlib/range/algorithm_ext/push_back.hpp>

#include <boost/assign.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

namespace 
{
    void reversed_example_test()
    {
        using namespace boost::adaptors;
        using namespace boost::assign;

        std::vector<int> input;
        input += 1,2,3,4,5,6,7,8,9;
        
        //boost::copy(
        //    input | reversed,
        //    std::ostream_iterator<int>(std::cout, ","));


        std::vector<int> test;
        boost::push_back(test, input | reversed);

        BOOST_CHECK_EQUAL_COLLECTIONS( input.rbegin(), input.rend(),
            test.begin(), test.end() );
    }
}

BOOST_AUTO_TEST_CASE( test_range_reversed_example_test )
{
    reversed_example_test();
}

