/*
 * FusionTest.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: bliu
 */

#include <boost/fusion/sequence.hpp>
#include <boost/fusion/include/sequence.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/container/vector/vector_fwd.hpp>
#include <boost/fusion/include/vector_fwd.hpp>
#include <boost/fusion/algorithm/iteration/fold.hpp>
#include <boost/fusion/include/fold.hpp>
#include <boost/lexical_cast.hpp>
#include <cassert>

struct make_string
{
    typedef std::string result_type;
    template<typename T>
    std::string operator()(const std::string & str, const T& t)
    {
        return str + boost::lexical_cast<std::string>(t);
    }
};


void FusionTest1()
{
    const boost::fusion::vector<int ,int> vec(1, 2);
    assert(boost::fusion::fold(vec, std::string(""), make_string()) == "12");
}

void FusionTest()
{
    FusionTest1();
}
