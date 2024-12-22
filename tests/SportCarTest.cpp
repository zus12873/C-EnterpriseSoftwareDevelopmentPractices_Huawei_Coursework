#include <gtest/gtest.h>

#include <memory>

#include "Executor.hpp"
#include "PoseEq.hpp"
namespace adas
{
TEST(sport_carTest, should_return_x_plus_2_given_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("M");
    const Pose target({2, 0, 'E'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_x_plus_4_given_command_is_FM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("FM");
    const Pose target({4, 0, 'E'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_x_minus_4_given_command_is_FM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("BFM");
    const Pose target({-4, 0, 'E'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_x_minus_2_given_command_is_BM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("BM");
    const Pose target({-2, 0, 'E'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_x_minus_4_given_command_is_BFM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("BFM");
    const Pose target({-4, 0, 'E'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_y_plus_1_given_command_is_L_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("L");
    const Pose target({0, 1, 'N'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_y_minus_1_given_command_is_R_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("R");
    const Pose target({0, -1, 'S'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_y_plus_1_given_command_is_BL_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("BL");
    const Pose target({0, 1, 'S'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_y_minus_1_given_command_is_BR_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("BR");
    const Pose target({0, -1, 'N'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_x_plus_1_and_y_plus_1_given_command_is_BR_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("FL");
    const Pose target({1, 1, 'N'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_x_plus_1_and_y_minus_1_given_command_is_BR_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("FR");
    const Pose target({1, -1, 'S'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_x_minus_1_and_y_plus_1_given_command_is_BFL_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("BFL");
    const Pose target({-1, 1, 'S'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(sport_carTest, should_return_x_minus_1_and_y_minus_1_given_command_is_BFR_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::sport_car));

    executor->Execute("BFR");
    const Pose target({-1, -1, 'N'});
    ASSERT_EQ(target, executor->QueryHead());
}
}  // namespace adas