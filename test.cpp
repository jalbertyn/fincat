#define CATCH_CONFIG_MAIN
#include "fincat.cpp"
#include "catch_all.hpp"

TEST_CASE("testing dollars2rands"){
    REQUIRE(i.dollars2rands(10)== "400");  //To test if the conversion from dollar to rand is working
}

TEST_CASE("testing calcRatioPM"){
     REQUIRE(d.calcRationPM(100,10)== "9");  // this is to test the calculated ration for the Profit Margin
}

TEST_CASE("testing calcRatioRoA"){
     REQUIRE(d.calcRatioRoA(100,10,5)== "18"); // this is to test the calculated ration for the Return of assets
}

TEST_CASE("testing calcRatioDE"){
     REQUIRE(d.calcRatioDE(100,10)== "0.1");  // this is to test the calculated ration for the debt of equity
}

TEST_CASE("testing categoriseRoA"){
     REQUIRE(d.categoriseRoA(0.5)== "unhealthy");  // this is to test of categorizing the rate of assets
}

TEST_CASE("testing categorisePM"){
     REQUIRE(d.categorisePM(0.5)== "unhealthy"); // this is to test of categorizing the profit margin
}

TEST_CASE("testing categoriseDE"){
     REQUIRE(d.categoriseDE(0.5)== "healthy");  // this is to test of categorizing the debt to equity
}



