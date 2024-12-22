#pragma once
#include <string>
namespace adas
{
struct Pose {
    int x;
    int y;
    char heading;
    Pose(int x, int y, char heading) : x(x), y(y), heading(heading)
    {
    }
};

enum Vehicle {
    normal,
    sport_car,
    bus,
};
class Executor
{
    // Caller should delete *executor when it is no longer needed.
public:
    static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'}, const Vehicle vehicle = normal) noexcept;

public:
    Executor(void) = default;
    virtual ~Executor(void) = default;
    Executor(const Executor&) = delete;
    Executor& operator=(const Executor&) = delete;

public:
    virtual void Execute(const std::string& command) noexcept = 0;
    virtual Pose QueryHead(void) const noexcept = 0;
    virtual Pose QueryTail(void) const noexcept = 0;
};
}  // namespace adas