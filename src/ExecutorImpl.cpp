#include "CmderFactory.hpp"
#include "ExecutorImpl.hpp"
#include "Singleton.hpp"
#include "algorithm"
#include "memory"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose, const Vehicle vehicle) noexcept
{
    return new (std::nothrow) Executorlmpl(pose, vehicle);
}
Executorlmpl::Executorlmpl(const Pose& pose, const Vehicle vehicle) noexcept : poseHandler(pose, vehicle)
{
}
void Executorlmpl::Execute(const std::string& command) noexcept
{
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(command);
    std::for_each(cmders.begin(), cmders.end(),
                  [this](const Cmder& cmder) noexcept { cmder(poseHandler).DoOperate(poseHandler); });
}
Pose Executorlmpl::QueryHead(void) const noexcept
{
    return poseHandler.QueryHead();
}
Pose Executorlmpl::QueryTail(void) const noexcept
{
    return poseHandler.QueryTail();
}
}  // namespace adas