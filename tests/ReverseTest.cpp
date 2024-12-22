#include <gtest/gtest.h>

#include <memory>

#include "Executor.hpp"
#include "PoseEq.hpp"
namespace adas
{
TEST(ExecutorReverseTest, should_return_x_minus_1_given_status_is_reverse_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BM");
    const Pose target({-1, 0, 'E'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(ExecutorReverseTest, should_return_x_minus_2_given_status_is_reverse_and_fast_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BFM");
    const Pose target({-2, 0, 'E'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(ExecutorReverseTest, should_return_x_plus_1_given_command_is_BBM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BBM");
    const Pose target({1, 0, 'E'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(ExecutorReverseTest, facing_should_change_to_S_given_status_is_fast_command_is_BM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BL");
    const Pose target({0, 0, 'S'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(
    ExecutorReverseTest,
    should_return_x_minus_1_and_facing_should_change_to_S_given_status_is_fast_and_reverse_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BFL");
    const Pose target({-1, 0, 'S'});
    ASSERT_EQ(target, executor->QueryHead());
}
TEST(ExecutorReverseTest, facing_should_change_to_N_given_status_is_reverse_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BR");
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->QueryHead());
}

TEST(ExecutorReverseTest,
     facing_should_change_to_N_and_return_x_puls_1_given_status_is_reverse_and_fast_command_is_R_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BFR");
    const Pose target({-1, 0, 'N'});
    ASSERT_EQ(target, executor->QueryHead());
}
}  // namespace adas