#include "CmderFactory.hpp"
namespace adas
{
CmderList CmderFactory::GetCmders(const std::string& commands) const noexcept
{
    CmderList cmders;
    std::string newCommands = commands;
    for (const auto cmd : ParseCommandString(newCommands)) {
        const auto it = cmderMap.find(cmd);
        if (it != cmderMap.end()) {
            cmders.push_back(it->second);
        }
    }
    return cmders;
}
std::string CmderFactory::ParseCommandString(std::string& commands) const noexcept
{
    std::string result(commands);
    ReplaceAll(result, "TR", "Z");
    return result;
}

void CmderFactory::ReplaceAll(std::string& inout, const std::string& what, const std::string& with) const noexcept
{
    for (std::string::size_type pos{}; (pos = inout.find(what, pos)) != std::string::npos; pos += with.length()) {
        inout.replace(pos, what.length(), with);
    }
}
}  // namespace adas