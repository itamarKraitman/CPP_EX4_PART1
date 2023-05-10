#include <iostream>
#include <string>
#include <stdexcept>
#include <random>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include "doctest.h"
#include "all_headers.hpp"

using namespace ariel;

TEST_SUITE("Point class")
{
    // constructor
    Point p1(1, 2);
    Point p2(12.5, 22);
    Point p3(11, 2.5);
    Point p4(1.5, 2.5);

    vector<Point> points = {
        p1, p2, p3, p4};

    TEST_CASE("Constructor, getters")
    {
        CHECK_EQ(p1.getX(), 1);
        CHECK_EQ(p1.getY(), 2);
        CHECK_EQ(p2.getX(), 12.5);
        CHECK_EQ(p2.getY(), 22);
        CHECK_EQ(p3.getX(), 11);
        CHECK_EQ(p3.getY(), 2.5);
        CHECK_EQ(p4.getX(), 1.5);
        CHECK_EQ(p4.getY(), 2.5);
    }

    TEST_CASE("Distance")
    {
        // distance
        double dis12 = p1.distance(p2);
        double dis13 = p1.distance(p3);
        double dis14 = p1.distance(p4);
        double dis23 = p2.distance(p3);
        double dis24 = p2.distance(p4);
        double dis34 = p3.distance(p4);

        CHECK_EQ(dis12, 23.071);
        CHECK_EQ(dis13, 10.012);
        CHECK_EQ(dis14, 0.707);
        CHECK_EQ(dis23, 19.558);
        CHECK_EQ(dis24, 22.389);
        CHECK_EQ(dis34, 9.5);
    }

    TEST_CASE("Print")
    {
        for (Point &p : points)
        {
            stringstream ss;
            ostringstream actuallStr;
            streambuf *printed = cout.rdbuf();
            cout.rdbuf(ss.rdbuf());
            p.print();
            cout.rdbuf(printed);
            actuallStr << "(" << p.getX() << "," << p2.getY() << ")" << endl;
            CHECK(ss.str() == actuallStr.str());
        }
    }

    TEST_CASE("moveTowards returns closest point to destination within given distance")
    {
        Point p1(1, 2);
        Point p2(12.5, 22);
        Point p3(11, 2.5);
        Point p4(1.5, 2.5);

        SUBCASE("distance between points is greater than given distance")
        {
            double distance = 5.0;
            Point result1 = p1.moveTowards(p1, p2, distance);
            Point result2 = p2.moveTowards(p2, p3, distance);
            Point result3 = p3.moveTowards(p3, p4, distance);
            Point result4 = p4.moveTowards(p4, p1, distance);

            CHECK(result1.distance(p2) <= distance);
            CHECK(result2.distance(p3) <= distance);
            CHECK(result3.distance(p4) <= distance);
            CHECK(result4.distance(p1) <= distance);
        }

        SUBCASE("distance between points is less than or equal to given distance")
        {
            double distance = 15.0;
            Point result1 = p1.moveTowards(p1, p2, distance);
            Point result2 = p2.moveTowards(p2, p3, distance);
            Point result3 = p3.moveTowards(p3, p4, distance);
            Point result4 = p4.moveTowards(p4, p1, distance);

            CHECK(result1.distance(p2) <= distance);
            CHECK(result2.distance(p3) <= distance);
            CHECK(result3.distance(p4) <= distance);
            CHECK(result4.distance(p1) <= distance);
        }
    }
}

TEST_SUITE("Cowboy")
{
    Cowboy c1 = Cowboy("Mi", Point(2, 5));

    TEST_CASE("Constructor")
    {
        Cowboy c1 = Cowboy("Mi", Point(2, 5));
        CHECK_EQ(c1.getAmoutOfBullets(), 6);
        CHECK_EQ(c1.getHitPoints(), 110);
    }
    TEST_CASE("Cowboys operations")
    {
        CHECK(c1.hasBoolets());                     // true
        Cowboy *c2 = new Cowboy("Gh", Point(3, 5)); // opponet
        c1.shoot(c2);
        c1.shoot(c2);
        c1.shoot(c2);
        c1.shoot(c2);
        c1.shoot(c2);
        c1.shoot(c2);
        // c1 should has no bullets now
        CHECK_EQ(c1.getAmoutOfBullets(), 0);
        CHECK_EQ(c2->getHitPoints(), 50); // each shoot reduce 10 hit points
        CHECK_THROWS_AS(c1.shoot(c2), std::runtime_error);
        c1.reload();
        CHECK_EQ(c1.getAmoutOfBullets(), 6);
        
        SUBCASE("Cowboy can hit Ninja")
        {
            YoungNinja* yn = new YoungNinja("yn",Point(1,5));
            TrainedNinja* tn = new TrainedNinja("tn",Point(4,5));
            OldNinja* on = new OldNinja("on", Point(1,6));
            CHECK_NOTHROW(c1.shoot(yn));
            CHECK_NOTHROW(c1.shoot(tn));
            CHECK_NOTHROW(c1.shoot(on));
        }
    }
}
