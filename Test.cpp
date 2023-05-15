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
        CHECK_EQ(23.071, dis12);
        CHECK_EQ(dis13, 10.012);
        CHECK_EQ(10.012, dis13);
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
            Point result1 = p1.moveTowards(p1);
            Point result2 = p2.moveTowards(p2);
            Point result3 = p3.moveTowards(p3);
            Point result4 = p4.moveTowards(p4);

            CHECK(result1.distance(p2) <= distance);
            CHECK(result2.distance(p3) <= distance);
            CHECK(result3.distance(p4) <= distance);
            CHECK(result4.distance(p1) <= distance);
        }

        SUBCASE("distance between points is less than or equal to given distance")
        {
            double distance = 15.0;
            Point result1 = p1.moveTowards(p1);
            Point result2 = p2.moveTowards(p2);
            Point result3 = p3.moveTowards(p3);
            Point result4 = p4.moveTowards(p4);

            CHECK(result1.distance(p2) <= distance);
            CHECK(result2.distance(p3) <= distance);
            CHECK(result3.distance(p4) <= distance);
            CHECK(result4.distance(p1) <= distance);
        }
    }
}

TEST_SUITE("Cowboy")
{
    Cowboy c1("Mi", Point(2, 5));
    Cowboy *c2 = new Cowboy("Gh", Point(3, 5)); // opponet

    TEST_CASE("Constructor")
    {
        CHECK_EQ(c1.getAmoutOfBullets(), 6);
        CHECK_EQ(c1.getHitPoints(), 110);
    }
    TEST_CASE("Cowboys operations")
    {
        YoungNinja *yn = new YoungNinja("yn", Point(1, 5));
        TrainedNinja *tn = new TrainedNinja("tn", Point(4, 5));
        OldNinja *on = new OldNinja("on", Point(1, 6));

        CHECK(c1.hasboolets()); // true
        c1.shoot(c2);
        CHECK_EQ(c1.getAmoutOfBullets(), 5); // this also checks in background that setAmountOfBullets work
        c1.shoot(c2);
        CHECK_EQ(c1.getAmoutOfBullets(), 4);
        c1.shoot(c2);
        CHECK_EQ(c1.getAmoutOfBullets(), 3);
        c1.shoot(c2);
        CHECK_EQ(c1.getAmoutOfBullets(), 2);
        c1.shoot(c2);
        CHECK_EQ(c1.getAmoutOfBullets(), 1);
        c1.shoot(c2);
        // c1 should has no bullets now
        CHECK_FALSE(c2->hasboolets()); // false
        CHECK_EQ(c1.getAmoutOfBullets(), 0);
        CHECK_EQ(c2->getHitPoints(), 50); // each shoot reduce 10 hit points
        CHECK_THROWS_AS(c1.shoot(c2), std::runtime_error);
        c1.reload();
        CHECK(c1.hasboolets());
        CHECK_EQ(c1.getAmoutOfBullets(), 6); // now should have 6 bullets

        SUBCASE("Cowboy can hit Ninja")
        {

            CHECK_NOTHROW(c1.shoot(yn));
            CHECK_NOTHROW(c1.shoot(tn));
            CHECK_NOTHROW(c1.shoot(on));
        }
        SUBCASE("dead")
        {
            for (size_t i = 0; i < 5; i++)
            {
                c1.shoot(c2);
            } // now c2 should be dead

            // hit dead
            CHECK_THROWS_AS(c1.shoot(c2), std::runtime_error);
            CHECK_THROWS_AS(yn->slash(c2), std::runtime_error);
            CHECK_THROWS_AS(yn->slash(nullptr), std::invalid_argument);
            // by dead
            CHECK_THROWS_AS(c2->shoot(yn), std::runtime_error);

            stringstream ss;
            string c2Str = c2->print();
            ss << "C (" << c2->getName() << ") died" << endl;
            CHECK(ss.str() == c2Str);
        }
    }
    TEST_CASE("print alive")
    {
        stringstream ss;
        string c2Str = c2->print();
        ss << "C (" << c2->getName() << ") Hit Points" << c2->getHitPoints() << endl;
        CHECK(ss.str() == c2Str);
    }
}

TEST_SUITE("Ninja")
{

    YoungNinja *yn = new YoungNinja("yn", Point(1, 5));
    TrainedNinja *tn = new TrainedNinja("tn", Point(4.55, 5));
    OldNinja *on = new OldNinja("on", Point(1, 6.85));

    Cowboy *c1 = new Cowboy("CA", Point{1, 2});
    Cowboy *c2 = new Cowboy("CB", Point{55.548, 28.879});
    YoungNinja *yn1 = new YoungNinja("YN1", Point{17.765, 29});
    OldNinja *on1 = new OldNinja("ON1", Point{26.31, 5.4});
    TrainedNinja *tn1 = new TrainedNinja("TN1", Point{16.52, 60.546});

    vector<Character *> team = {yn, tn, on, yn1, on1, tn1};

    TEST_CASE("Ninja Character")
    {
        SUBCASE("Speed")
        {
            CHECK_EQ(yn->getSpeed(), 14);
            CHECK_EQ(tn->getSpeed(), 12);
            CHECK_EQ(on->getSpeed(), 8);
        }
        SUBCASE("hitPoints")
        {
            CHECK_EQ(yn->getHitPoints(), 100);
            CHECK_EQ(tn->getHitPoints(), 120);
            CHECK_EQ(on->getHitPoints(), 180);
        }
        SUBCASE("location")
        {
            CHECK_EQ(yn->getLocation().getX(), Point{1, 5}.getX());
            CHECK_EQ(yn->getLocation().getY(), Point{1, 5}.getY());
            CHECK_EQ(tn->getLocation().getX(), Point{4.55, 5}.getX());
            CHECK_EQ(tn->getLocation().getY(), Point{4.55, 5}.getY());
            CHECK_EQ(on->getLocation().getX(), Point(1, 6.85).getX());
            CHECK_EQ(on->getLocation().getY(), Point(1, 6.85).getY());
        }
        SUBCASE("Name")
        {
            CHECK_EQ(yn->getName(), "yn");
            CHECK_EQ(on->getName(), "tn");
            CHECK_EQ(on->getName(), "on");
        }
    }

    TEST_CASE("Operations")
    {
        SUBCASE("Move")
        {
            double dis1 = yn1->getLocation().distance(c1->getLocation());
            double dis2 = yn1->getLocation().distance(c2->getLocation());
            double dis3 = yn1->getLocation().distance(on1->getLocation());
            double dis4 = yn1->getLocation().distance(tn1->getLocation());
            double dis5 = on1->getLocation().distance(tn1->getLocation());
            double dis6 = on1->getLocation().distance(c1->getLocation());
            double dis7 = on1->getLocation().distance(c2->getLocation());

            yn1->move(c1);
            yn1->move(c2);
            yn1->move(on1);
            yn1->move(tn1);
            on1->move(tn1);
            on1->move(c1);
            on1->move(c2);

            CHECK_EQ(yn1->getLocation().distance(c1->getLocation()), 17.782);
            CHECK_EQ(yn1->getLocation().distance(c2->getLocation()), 23.783);
            CHECK_EQ(yn1->getLocation().distance(on1->getLocation()), 11.099);
            CHECK_EQ(yn1->getLocation().distance(tn1->getLocation()), 17.571);
            CHECK_EQ(on1->getLocation().distance(tn1->getLocation()), 42.008);
            CHECK_EQ(on1->getLocation().distance(c1->getLocation()), 17.537);
            CHECK_EQ(on1->getLocation().distance(c2->getLocation()), 29.498);

            SUBCASE("distance < than speed")
            {
                yn1->move(on1); // speed 14, distance 11.909
                CHECK_EQ(yn1->getLocation().distance(on1->getLocation()), 2.901);
            }
        }

        SUBCASE("Slash")
        {
            YoungNinja *enemy = new YoungNinja("enemy", Point{18, 28.5}); // distance < 1M
            CHECK_NOTHROW(yn1->slash(enemy));
            CHECK_EQ(enemy->getHitPoints(), 60); // slash reduce 40 hit points
            yn1->slash(c1);                      // should not make any damage
            CHECK_EQ(c1->getHitPoints(), 110);
        }
    }

    TEST_CASE("Print Ninja")
    {
        stringstream ss;
        ostringstream actuallStr;
        streambuf *printed = cout.rdbuf();
        cout.rdbuf(ss.rdbuf());
        yn->print();
        cout.rdbuf(printed);
        actuallStr << "N (" << yn->getName() << "), Hit Points: " << yn->getHitPoints() << endl;
        CHECK(ss.str() == actuallStr.str());
    }
}

TEST_SUITE("Team")
{
    YoungNinja *yn = new YoungNinja("yn", Point(1, 5));
    TrainedNinja *tn = new TrainedNinja("tn", Point(4.55, 5));
    OldNinja *on = new OldNinja("on", Point(1, 6.85));
    Cowboy *c1 = new Cowboy("CA", Point{1, 2});
    Cowboy *c2 = new Cowboy("CB", Point{55.548, 28.879});
    YoungNinja *yn1 = new YoungNinja("YN1", Point{17.765, 29});
    OldNinja *on1 = new OldNinja("ON1", Point{26.31, 5.4});
    TrainedNinja *tn1 = new TrainedNinja("TN1", Point{16.52, 60.546});

    TEST_CASE("Constructor")
    {
        CHECK_NOTHROW(Team team(c1));
    }
    TEST_CASE("add member")
    {
        Team team(c1);
        CHECK_NOTHROW(team.add(yn));
        CHECK_NOTHROW(team.add(c2));
        CHECK_NOTHROW(team.add(on));
        CHECK_EQ(team.getSize(), 4);

        CHECK(team.getSquad().at(0)->getName() == c1->getName());
        CHECK(team.getSquad().at(1)->getName() == c2->getName());
        CHECK(team.getSquad().at(2)->getName() == yn->getName());
        CHECK(team.getSquad().at(3)->getName() == on->getName());

        SUBCASE("Team can have 10 members at last")
        {
            team.add(new Cowboy("ont", Point(11, 6.85)));
            team.add(new Cowboy("onty", Point(11, 6.86)));
            team.add(new Cowboy("ontj", Point(11, 6.857)));
            team.add(new Cowboy("ontp", Point(11, 6.858)));
            team.add(new Cowboy("ontw", Point(11, 6.856)));
            CHECK_THROWS_AS(team.add(new Cowboy("onte", Point(11, 6.852))), std::runtime_error);
        }
    }

    TEST_CASE("add duplicated member")
    {
        Team team(c1);
        CHECK_NOTHROW(team.add(yn));
        CHECK_THROWS(team.add(yn));
    }
    TEST_CASE("attack")
    {
        Team team1(c1); // leader c1
        team1.add(yn);
        team1.add(c2);
        team1.add(yn1);

        Team team2(tn1); // leader c1
        team2.add(on1);

        CHECK_NOTHROW(team1.attack(&team2));
        CHECK(tn1->getHitPoints() < 120);

        yn->hit(100); // should be dead now
        CHECK(team1.stillAlive() == 3);
    }
    TEST_CASE("Print")
    {
        Team team1(c1); // leader c1
        team1.add(yn);
        team1.add(c2);
        team1.add(yn1);
        CHECK(team1.getSize() == 4);

        string teamString;
        CHECK_NOTHROW(team1.print());
        std::stringstream ss;
        std::streambuf *prev_cout_buf = std::cout.rdbuf(ss.rdbuf()); // redirect cout to ss
        team1.print();
        std::cout.rdbuf(prev_cout_buf); // restore cout's original buffer
        std::string expected_output = "Team team1: Leader: Cowboy" + c1->getName() + "\n2. cowbouy " + c2->getName() + "\n3. ninja " + yn->getName() + "\n4. ninja: " + yn1->getName();
        CHECK(ss.str() == expected_output);
    }
    TEST_CASE("Team2")
    {
        SUBCASE("constructor")
        {
            CHECK_NOTHROW(Team2 team1(c1)); // leader c1
        }

        Team2 team(yn1);
        team.add(yn);
        team.add(c1);
        team.add(tn);

        CHECK(team.getSize() == 4);
        CHECK(team.stillAlive() == 4);
        yn1->hit(100); // should be dead now
        CHECK(team.stillAlive() == 3);

        CHECK(team.getSquad().at(0)->getName() == yn1->getName());
        CHECK(team.getSquad().at(1)->getName() == yn->getName());
        CHECK(team.getSquad().at(2)->getName() == c1->getName());
        CHECK(team.getSquad().at(3)->getName() == tn->getName());

        string teamString;
        CHECK_NOTHROW(team.print());
        std::stringstream ss;
        std::streambuf *prev_cout_buf = std::cout.rdbuf(ss.rdbuf()); // redirect cout to ss
        team.print();
        std::cout.rdbuf(prev_cout_buf); // restore cout's original buffer
        std::string expected_output = "Team team: Leader: ninja" + yn1->getName() + "\n2. ninja " + yn->getName() + "\n3. cowboy " + c1->getName() + "\n4. ninja: " + tn->getName();
        CHECK(ss.str() == expected_output);
    }
}