#include <gtest/gtest.h>

#include <memory>

#include "Executor.hpp"
#include "PoseEq.hpp"
namespace adas
{
TEST(busTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("M");
    const Pose head({1, 0, 'E'});
    const Pose tail({0, 0, 'E'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
TEST(busTest, should_return_x_minus_1_given_command_is_BM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("BM");
    const Pose head({-1, 0, 'E'});
    const Pose tail({-2, 0, 'E'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
TEST(busTest, should_return_x_plus_2_given_command_is_FM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("FM");
    const Pose head({2, 0, 'E'});
    const Pose tail({1, 0, 'E'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
TEST(busTest, should_return_x_minus_2_given_command_is_BFM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("BFM");
    const Pose head({-2, 0, 'E'});
    const Pose tail({-3, 0, 'E'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
TEST(busTest, should_return_x_plus_1_given_command_is_L_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("L");
    const Pose head({1, 0, 'N'});
    const Pose tail({1, -1, 'N'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
TEST(busTest, should_return_x_minus_1_given_command_is_BL_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("BL");
    const Pose head({-1, 0, 'S'});
    const Pose tail({-1, 1, 'S'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
TEST(busTest, should_return_x_plus_2_given_command_is_FL_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("FL");
    const Pose head({2, 0, 'N'});
    const Pose tail({2, -1, 'N'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
TEST(busTest, should_return_x_minus_2_given_command_is_BFL_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("BFL");
    const Pose head({-2, 0, 'S'});
    const Pose tail({-2, 1, 'S'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
TEST(busTest, should_return_x_plus_1_given_command_is_R_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("R");
    const Pose head({1, 0, 'S'});
    const Pose tail({1, 1, 'S'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
TEST(busTest, should_return_x_minus_1_given_command_is_BR_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("BR");
    const Pose head({-1, 0, 'N'});
    const Pose tail({-1, -1, 'N'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
TEST(busTest, should_return_x_plus_2_given_command_is_FR_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("FR");
    const Pose head({2, 0, 'S'});
    const Pose tail({2, 1, 'S'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
TEST(busTest, should_return_x_minus_2_given_command_is_BFR_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, Vehicle::bus));

    executor->Execute("BFR");
    const Pose head({-2, 0, 'N'});
    const Pose tail({-2, -1, 'N'});
    ASSERT_EQ(head, executor->QueryHead());
    ASSERT_EQ(tail, executor->QueryTail());
}
}  // namespace adas