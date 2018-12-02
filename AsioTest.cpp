/*
 * AsioTest.cpp
 *
 *  Created on: Sep 8, 2017
 *      Author: bliu
 */

#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void AsioTest1()
{
    std::cout << __func__ << std::endl;
    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

    t.wait();
    std::cout << "Hello world!" << std::endl;
}

void print(const boost::system::error_code& /*e*/)
{
    std::cout << "Hello, world!" << std::endl;
}

void AsioTest2()
{
    std::cout << __func__ << std::endl;
    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

    t.async_wait(&print);
    io.run();
}

void AsioTest()
{
    AsioTest2();
}
