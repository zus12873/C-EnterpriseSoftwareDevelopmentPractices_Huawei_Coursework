#pragma once 
#include "Executor.hpp" 
namespace adas
{
    class PoseHandler final
    {
    public:
        PoseHandler(const Pose& pose) noexcept;
        PoseHandler(const PoseHandler&) = delete;
        PoseHandler& operator=(const PoseHandler&) = delete;

    public:
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;
        void Fast(void) noexcept;
        bool IsFast(void) const noexcept;
        Pose Query(void) const noexcept;

    private:
       Pose pose;
       bool fast{false};
    };
    class Point final
    {
    public:
        Point(const int x, const int y) noexcept;
        Point(const Point& rhs) noexcept;
        Point& operator=(const Point& rhs) noexcept;
        Point& operator+=(const Point& rhs) noexcept;

    public:
        int GetX(void) const noexcept;
        int GetY(void) const noexcept;

    private:
        int x;
        int y;
    };
}  // namespace adas
